/*
 * conduction.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Modified by Haibo Ni <haibo.ni02@gmail.com>
 *
 */
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "conduction.h"
#include "util.h"
#ifndef CONDUCTION_C
#define CONDUCTION_C

double **generate_laplacian(unsigned char *** atrium,
                            int nz, int ny, int nx, int count,
                            const char *theta_name, const char *phi_name,
                            double dx, double dd, double d2) {
	// generates the laplacian operator as a linear array.
	double **laplacian;
	double * * **lap;
	int i, j, k, n, c;

	// first, generate your laplacian.
	lap = generate_3d_laplacian(atrium, nz, ny, nx, theta_name, phi_name, dx, dd, d2);

	// allocate the 2d array.
	laplacian = allocate_2d_laplacian(count);

	c = 0;
	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (lap[k][j][i] != NULL) {
					for (n = 0; n < 19; ++n) {
						laplacian[c][n] = lap[k][j][i][n];
					}
					c++;
				}
			}
		}
	}

	deallocate_and_zero_3d_double_pointer(lap, nz + 2, ny + 2, nx + 2);

	return laplacian;
}


/*  function to take spatial heterogeneity of diffusion coefficient (ie d1 d2, and dd = d1-dd2 at each node (cell)
    By Haibo Ni
    Last update, 2014 Oct 27. Monday.
    a 3-D matrix of dd and d2 is required, a major difference from the old version.
*/


double **generate_laplacian_test_heterogeneity ( unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *theta_name, const char *phi_name,
        double dx, double dd, double d2) {

	double ***M_dd; // = (double ** *)allocate_and_zero_3d_double( nz + 2,  ny + 2,  nx + 2);
	double ***M_d2; // = (double ** *)allocate_and_zero_3d_double( nz + 2,  ny + 2,  nx + 2);

	allocate_and_zero_3d_maxtrix(M_dd, nz + 2,  ny + 2,  nx + 2);
	allocate_and_zero_3d_maxtrix(M_d2, nz + 2,  ny + 2,  nx + 2);

	int i, j, k;

	for (k = 1; k < nz + 1; ++k)
	{
		for (j = 1; j < ny + 1; ++j)
		{

			for (i = 1; i < nx + 1; ++i)
			{
				M_dd[k][j][i] = dd;
				M_d2[k][j][i] = d2;

				/* 10 percent decrease in diffusion coefficient from ENDO to EPI*/
				if (atrium[k][j][i] <= 10 && atrium[k][j][i] >= 1)
				{
					M_dd[k][j][i] = dd * ( 1.0 - 0.1 * ((double)atrium[k][j][i] - 1.0) / 9.0);
					M_d2[k][j][i] = d2 * ( 1.0 - 0.1 * ((double)atrium[k][j][i] - 1.0) / 9.0);
				}
				if (atrium[k][j][i] <= 20 && atrium[k][j][i] >= 11)
				{
					M_dd[k][j][i] = dd * ( 1.0 - 0.1 * ((double)atrium[k][j][i] - 11.0) / 9.0);
					M_d2[k][j][i] = d2 * ( 1.0 - 0.1 * ((double)atrium[k][j][i] - 11.0) / 9.0);
				}
			}
		}
	}


	double **lap;

	lap = generate_laplacian_with_diffusion_heterogeneity(atrium,
	        nz, ny, nx, count,
	        theta_name, phi_name,
	        dx, dx, dx,
	        M_dd, M_d2);

	deallocate_and_zero_3d_matrix(M_dd,  nz + 2,  ny + 2,  nx + 2);
	deallocate_and_zero_3d_matrix(M_d2,  nz + 2,  ny + 2,  nx + 2);
	return lap;
}


double **generate_laplacian_with_diffusion_heterogeneity(unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *theta_name, const char *phi_name,
        double dx, double dy, double dz,
        double ***dd, double ***d2) {
	// generates the laplacian operator as a linear array.
	double **laplacian;
	double * * **lap;
	int i, j, k, n, c;

	if (!dd) {
		perror("dd should a matrix");
		exit(EXIT_FAILURE);
	}


	if (!d2) {
		perror("d2 should a matrix");
		exit(EXIT_FAILURE);
	}

	// first, generate your laplacian.
	// this is the old version, diffusion was universally the same
	// lap = generate_3d_laplacian(atrium, nz, ny, nx, theta_name, phi_name, dx, dd, d2);

	// and the new version:
	lap = generate_3d_laplacian_with_diffusion_heterogeneity(atrium,
	        nz, ny, nx,
	        theta_name, phi_name,
	        dx, dy, dz,
	        dd, d2);

	// allocate the 2d array.
	laplacian = allocate_2d_laplacian(count);

	c = 0;
	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (lap[k][j][i] != NULL) {
					for (n = 0; n < 19; ++n) {
						laplacian[c][n] = lap[k][j][i][n];
					}
					c++;
				}
			}
		}
	}

	deallocate_and_zero_3d_double_pointer(lap, nz + 2, ny + 2, nx + 2);

	return laplacian;
}

double **generate_laplacian_using_fibre_components(unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *fibre_x_file, const char *fibre_y_file, const char *fibre_z_file,
        double dx, double dd, double d2)
{
	// generates the laplacian operator as a linear array.
	double **laplacian;
	double * * **lap;
	int i, j, k, n, c;

	// first, generate your laplacian.
	lap = generate_3d_laplacian_using_fibre_components(atrium, nz, ny, nx,
	        fibre_x_file, fibre_y_file, fibre_z_file,
	        dx, dd, d2);

	// allocate the 2d array.
	laplacian = allocate_2d_laplacian(count);

	c = 0;
	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (lap[k][j][i] != NULL) {
					for (n = 0; n < 19; ++n) {
						laplacian[c][n] = lap[k][j][i][n];
					}
					c++;
				}
			}
		}
	}

	deallocate_and_zero_3d_double_pointer(lap, nz + 2, ny + 2, nx + 2);

	return laplacian;
}

double * * **generate_3d_laplacian_using_fibre_components(unsigned char *** atrium,
        int nz, int ny, int nx,
        const char *fibre_x_file, const char *fibre_y_file, const char *fibre_z_file,
        double dx, double dd, double d2) {

	// unsigned char *** theta  = read_and_embed_geometry(theta_name, nz, ny, nx);
	// unsigned char *** phi    = read_and_embed_geometry(phi_name,   nz, ny, nx);

	// float ***x = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	// float ***y = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	// float ***z = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);


	// calculate the unit vectors from  the angles.
	// calculate_fibre_unit_vectors(theta, phi, nz, ny, nx, z, y, x);
	float ***x = read_and_embed_float_data(fibre_x_file, nz, ny, nx);
	float ***y = read_and_embed_float_data(fibre_y_file, nz, ny, nx);
	float ***z = read_and_embed_float_data(fibre_z_file, nz, ny, nx);
#define OUT_FIBRE
#ifdef OUT_FIBRE
	{
		FILE *out;
		out = fopen ("MIKE_atrium_fibre.vtk", "wt");

		fprintf (out, "# vtk DataFile Version 3.0\n");
		fprintf (out, "vtk output\n");
		fprintf (out, "ASCII\n");
		fprintf (out, "DATASET STRUCTURED_POINTS\n");
		fprintf (out, "DIMENSIONS %d %d %d\n", nx, ny, nz);
		fprintf (out, "SPACING 1 1 1\n");
		fprintf (out, "ORIGIN 0 0 0\n");
		fprintf (out, "POINT_DATA %d\n", (nz ) * (ny ) * (nx));
		fprintf (out, "SCALARS HumanAtrium float 3\n");
		fprintf (out, "LOOKUP_TABLE default\n");

		int i, j, k;
		float t, p;

		for (k = 1; k < nz + 1; ++k) {
			for (j = 1; j < ny + 1; ++j) {
				for (i = 1; i < nx + 1; ++i) {

					fprintf(out, "%f %f %f ", x[k][j][i], y[k][j][i], z[k][j][i]);

				}
				fprintf(out, "\n");
			}
		}
		fclose(out);
	}
#endif

	double * * **dc = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	double * * **df = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);

	calculate_diffusion_tensor_components(atrium,
	                                      nz, ny, nx,
	                                      z, y, x,
	                                      dx, dd, d2,
	                                      dc, df);



	double * * **lap = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	calculate_laplacian_components(atrium,
	                               nz, ny, nx,
	                               z, y, x,
	                               dx, dd,
	                               dc, df, lap);


	// deallocate x, y, z
	deallocate_and_zero_3d_float(x, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(y, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(z, nz + 2, ny + 2, nx + 2);


	deallocate_and_zero_3d_double_pointer(dc, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_double_pointer(df, nz + 2, ny + 2, nx + 2);

	return lap;
}



double **allocate_2d_laplacian(int count) {
	// allocates a 2d laplacian array.

	double **lap;
	int i, j;

	// allocate a long enough spine.
	// lap = (double **) malloc(count * sizeof(double *));
	lap = new double * [count];
	if (!lap) {
		perror("Laplacian array malloc");
		exit(EXIT_FAILURE);
	}

	// allocate the neighbours.
	for (i = 0; i < count; ++i) {
		// lap[i] =  (double *)malloc(19 * sizeof(double));
		lap[i] =  new double [19]; //
		if (!lap[i]) {
			perror("Laplacian array malloc");
			exit(EXIT_FAILURE);
		}

		for (j = 0; j < 19; ++j) {   // cells including itself.
			lap[i][j] = 0.0;
		}
	}

	return lap;
}

double * * **generate_3d_laplacian(unsigned char *** atrium,
                                   int nz, int ny, int nx,
                                   const char *theta_name, const char *phi_name,
                                   double dx, double dd, double d2) {

	unsigned char *** theta  = read_and_embed_geometry(theta_name, nz, ny, nx);
	unsigned char *** phi    = read_and_embed_geometry(phi_name,   nz, ny, nx);

	float ***x = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	float ***y = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	float ***z = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);


	// calculate the unit vectors from  the angles.
	calculate_fibre_unit_vectors(theta, phi, nz, ny, nx, z, y, x);
#define OUT_FIBRE
#ifdef OUT_FIBRE
	{
		FILE *out;
		out = fopen ("atrium_fibre3.vtk", "wt");

		fprintf (out, "# vtk DataFile Version 3.0\n");
		fprintf (out, "vtk output\n");
		fprintf (out, "ASCII\n");
		fprintf (out, "DATASET STRUCTURED_POINTS\n");
		fprintf (out, "DIMENSIONS %d %d %d\n", nx, ny, nz);
		fprintf (out, "SPACING %f %f %f \n", dx, dx, dx);
		fprintf (out, "ORIGIN 0 0 0\n");
		fprintf (out, "POINT_DATA %d\n", (nz ) * (ny ) * (nx));
		fprintf (out, "SCALARS HumanAtrium float 3\n");
		fprintf (out, "LOOKUP_TABLE default\n");

		int i, j, k;
		float t, p;

		for (k = 1; k < nz + 1; ++k) {
			for (j = 1; j < ny + 1; ++j) {
				for (i = 1; i < nx + 1; ++i) {

					fprintf(out, "%f %f %f ", x[k][j][i], y[k][j][i], z[k][j][i]);

				}
				fprintf(out, "\n");
			}
		}
		fclose(out);
	}
#endif

	deallocate_and_zero_3d_unsigned_char(theta,  nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_unsigned_char(phi,    nz + 2, ny + 2, nx + 2);

	double * * **dc = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	double * * **df = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);

	calculate_diffusion_tensor_components(atrium,
	                                      nz, ny, nx,
	                                      z, y, x,
	                                      dx, dd, d2,
	                                      dc, df);



	double * * **lap = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	calculate_laplacian_components(atrium,
	                               nz, ny, nx,
	                               z, y, x,
	                               dx, dd,
	                               dc, df, lap);


	// deallocate x, y, z
	deallocate_and_zero_3d_float(x, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(y, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(z, nz + 2, ny + 2, nx + 2);


	deallocate_and_zero_3d_double_pointer(dc, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_double_pointer(df, nz + 2, ny + 2, nx + 2);

	return lap;
}


double * * **generate_3d_laplacian_with_diffusion_heterogeneity(unsigned char *** atrium,
        int nz, int ny, int nx,
        const char *theta_name, const char *phi_name,
        double dx, double dy, double dz,
        double ***dd, double ***d2) {

	unsigned char *** theta  = read_and_embed_geometry(theta_name, nz, ny, nx);
	unsigned char *** phi    = read_and_embed_geometry(phi_name,   nz, ny, nx);

	float ***x = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	float ***y = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);
	float ***z = allocate_and_zero_3d_float(nz + 2, ny + 2, nx + 2);


	// calculate the unit vectors from  the angles.
	calculate_fibre_unit_vectors(theta, phi, nz, ny, nx, z, y, x);
#define OUT_FIBRE
#ifdef OUT_FIBRE
	{
		FILE *out;
		out = fopen ("atrium_fibre.vtk", "wt");

		fprintf (out, "# vtk DataFile Version 3.0\n");
		fprintf (out, "vtk output\n");
		fprintf (out, "ASCII\n");
		fprintf (out, "DATASET STRUCTURED_POINTS\n");
		fprintf (out, "DIMENSIONS %d %d %d\n", nx, ny, nz);
		fprintf (out, "SPACING %f %f %f \n", dx, dx, dx);
		fprintf (out, "ORIGIN 0 0 0\n");
		fprintf (out, "POINT_DATA %d\n", (nz ) * (ny ) * (nx));
		fprintf (out, "SCALARS HumanAtrium float 3\n");
		fprintf (out, "LOOKUP_TABLE default\n");

		int i, j, k;
		float t, p;

		for (k = 1; k < nz + 1; ++k) {
			for (j = 1; j < ny + 1; ++j) {
				for (i = 1; i < nx + 1; ++i) {

					fprintf(out, "%f %f %f ", x[k][j][i], y[k][j][i], z[k][j][i]);

				}
				fprintf(out, "\n");
			}
		}
		fclose(out);
	}
#endif

	deallocate_and_zero_3d_unsigned_char(theta,  nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_unsigned_char(phi,    nz + 2, ny + 2, nx + 2);

	double * * **dc = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	double * * **df = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	double * * **d_dd = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	double * * **d_d2 = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);

	calculate_diffusion_tensor_components_with_diffusion_heterogeneity(atrium,
	        nz, ny, nx,
	        z, y, x,
	        dx, dy, dz,
	        dd, d2,
	        dc, df,
	        d_dd, d_d2);

	double * * **lap = allocate_and_zero_3d_double_pointer(nz + 2, ny + 2, nx + 2);
	/*calculate_laplacian_components(atrium,
	                               nz, ny, nx,
	                               z, y, x,
	                               dx, dd,
	                               dc, df, lap);*/

	calculate_laplacian_components_with_diffusion_heterogeneity (atrium,
	        nz, ny, nx, \
	        z, y, x, \
	        dx, dy, dz, \
	        dd, d2, \
	        dc, df, \
	        d_dd, d_d2, \
	        lap);

	// deallocate x, y, z
	deallocate_and_zero_3d_float(x, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(y, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(z, nz + 2, ny + 2, nx + 2);

	/* deallocate the tempoery memery */
	deallocate_and_zero_3d_double_pointer(dc, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_double_pointer(df, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_double_pointer(d_dd, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_double_pointer(d_d2, nz + 2, ny + 2, nx + 2);

	return lap;
}


void calculate_fibre_unit_vectors(unsigned char *** theta, unsigned char *** phi,
                                  int nz, int ny, int nx, float ***z, float ***y, float ***x) {
	int i, j, k;
	float t, p;

	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				/*if (phi[k][j][i] != 255) {
					t = (float) ((theta[k][j][i] / 254.0) * M_PI);
					p = (float) ((phi[k][j][i] / 254.0) * M_PI);

					x[k][j][i] = (float) (cos(p) * sin(t));
					y[k][j][i] = (float) (sin(p) * sin(t));
					z[k][j][i] = (float) cos(t);
				} else {
					x[k][j][i] = 1.0;
					y[k][j][i] = 0.0;
					z[k][j][i] = 0.0;
				}*/

					theta[k][j][i] = 0;
					phi[k][j][i] = 255;
					t = (float) ((theta[k][j][i] / 255.0) * M_PI);
					p = (float) ((phi[k][j][i] / 255.0) * M_PI);

					x[k][j][i] = (float) (cos(p) * sin(t));
					y[k][j][i] = (float) (sin(p) * sin(t));
					z[k][j][i] = (float) cos(t);


										x[k][j][i] = 1.0;
					y[k][j][i] = 0.0;
					z[k][j][i] = 0.0;
				/*} else {
					x[k][j][i] = 1.0;
					y[k][j][i] = 0.0;
					z[k][j][i] = 0.0;
				}*/

			}
		}
	}
}

void convert_fibre_components_to_angles(unsigned char *** theta, unsigned char *** phi,
                                        int nz, int ny, int nx,
                                        char *fibre_x_file, char *fibre_y_file, char *fibre_z_file
                                       ) {
	float ***x = read_and_embed_float_data(fibre_x_file, nz, ny, nx);
	float ***y = read_and_embed_float_data(fibre_y_file, nz, ny, nx);
	float ***z = read_and_embed_float_data(fibre_z_file, nz, ny, nx);
	int i, j, k;
	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				/*make sure the vectors are unit vectors */
				if (fabs(x[k][j][i]*x[k][j][i] + y[k][j][i]*y[k][j][i] + z[k][j][i]*z[k][j][i] - 1) < 0.5) {
					theta[k][j][i] = phi[k][j][i] = 255;
				} else {
					theta[k][j][i] = (unsigned char)(acos(z[k][j][i]) * 254.0 / M_PI + 0.5);
					if (x[k][j][i] == 0.0)
					{
						phi[k][j][i] = 254;
					} else {
						phi[k][j][i] = (unsigned char) (atan(y[k][j][i] / x[k][j][i]) * 254.0 / M_PI + 0.5);
					}
				}

			}
		}
	}
	// deallocate x, y, z
	deallocate_and_zero_3d_float(x, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(y, nz + 2, ny + 2, nx + 2);
	deallocate_and_zero_3d_float(z, nz + 2, ny + 2, nx + 2);
}

void calculate_diffusion_tensor_components(unsigned char *** atrium,
        int nz, int ny, int nx,
        float ***z, float ***y, float ***x,
        double dx, double dd, double d2,
        double * * **dc, double * * **df) {
	int i, j, k;

	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (atrium[k][j][i] > 0) {
					// allocate diffision tensor at this point
					dc[k][j][i] = new double [9]; // (double *) malloc(9 * sizeof(double));
					if (!dc[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}
					df[k][j][i] = new double [9]; // (double *) malloc(9 * sizeof(double));
					if (!df[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}

					// calculate dc
					dc[k][j][i][0] = d2 + (dd * x[k][j][i] * x[k][j][i]);
					dc[k][j][i][1] = dd * x[k][j][i] * y[k][j][i];
					dc[k][j][i][2] = dd * x[k][j][i] * z[k][j][i];
					dc[k][j][i][3] = dd * y[k][j][i] * x[k][j][i];
					dc[k][j][i][4] = d2 + (dd * y[k][j][i] * y[k][j][i]);
					dc[k][j][i][5] = dd * y[k][j][i] * z[k][j][i];
					dc[k][j][i][6] = dd * z[k][j][i] * x[k][j][i];
					dc[k][j][i][7] = dd * z[k][j][i] * y[k][j][i];
					dc[k][j][i][8] = d2 + (dd * z[k][j][i] * z[k][j][i]);

					// calculate df
					// dfx/dx
					df[k][j][i][0] = (x[k][j][i + 1] - x[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][0] = (x[k][j][i] - x[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][0] = (x[k][j][i + 1] - x[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						df[k][j][i][0] = 0.0;

					//dfx/dy
					df[k][j][i][1] = (x[k][j + 1][i] - x[k][j - 1][i]) / (2 * dx);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][1] = (x[k][j][i] - x[k][j - 1][i]) / (dx);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][1] = (x[k][j + 1][i] - x[k][j][i]) / (dx);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][1] = 0.0;

					// dfx/dz
					df[k][j][i][2] = (x[k + 1][j][i] - x[k - 1][j][i]) / (2 * dx);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][2] = (x[k][j][i] - x[k - 1][j][i]) / (dx);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][2] = (x[k + 1][j][i] - x[k][j][i]) / (dx);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][2] = 0.0;


					// dfy/dx
					df[k][j][i][3] = (y[k][j][i + 1] - y[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][3] = (y[k][j][i] - y[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][3] = (y[k][j][i + 1] - y[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						df[k][j][i][3] = 0.0;

					//dfy/dy
					df[k][j][i][4] = (y[k][j + 1][i] - y[k][j - 1][i]) / (2 * dx);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][4] = (y[k][j][i] - y[k][j - 1][i]) / (dx);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][4] = (y[k][j + 1][i] - y[k][j][i]) / (dx);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][4] = 0.0;

					// dfy/dz
					df[k][j][i][5] = (y[k + 1][j][i] - y[k - 1][j][i]) / (2 * dx);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][5] = (y[k][j][i] - y[k - 1][j][i]) / (dx);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][5] = (y[k + 1][j][i] - y[k][j][i]) / (dx);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][5] = 0.0;

					// dfz/dx
					df[k][j][i][6] = (z[k][j][i + 1] - z[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][6] = (z[k][j][i] - z[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][6] = (z[k][j][i + 1] - z[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i - 1] == 0) // + - changed
						df[k][j][i][6] = 0.0;

					//dfy/dy
					df[k][j][i][7] = (z[k][j + 1][i] - z[k][j - 1][i]) / (2 * dx);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][7] = (z[k][j][i] - z[k][j - 1][i]) / (dx);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][7] = (z[k][j + 1][i] - z[k][j][i]) / (dx);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][7] = 0.0;

					// dfz/dz
					df[k][j][i][8] = (z[k + 1][j][i] - z[k - 1][j][i]) / (2 * dx);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][8] = (z[k][j][i] - z[k - 1][j][i]) / (dx);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][8] = (z[k + 1][j][i] - z[k][j][i]) / (dx);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][8] = 0.0;
				}
			}
		}
	}
}


/* compute the diffusion tensor */
void calculate_diffusion_tensor_components_with_diffusion_heterogeneity(unsigned char *** atrium, \
        int nz, int ny, int nx,  \
        float ***z, float ***y, float ***x,  \
        double dx, double dy, double dz,  \
        double ***dd, double ***d2,  \
        double * * **dc, double * * **df, \
        double * * **d_dd, double * * **d_d2) {
	int i, j, k;

	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (atrium[k][j][i] > 0) {
					// allocate diffusion tensor at this point
					dc[k][j][i] = new double [9] ;// (double *)  malloc(9 * sizeof(double));
					if (!dc[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}
					df[k][j][i] = new double [9] ; //  (double *) malloc(9 * sizeof(double));
					if (!df[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}

					d_dd[k][j][i] = new double [3] ;// (double *) malloc(3 * sizeof(double));
					if (!d_dd[k][j][i]) {
						fprintf(stderr, "d_dd %d, %d, %d failed to allocate!\n", k, j, i);
					}

					d_d2[k][j][i] = new double [3] ;// (double *) malloc(3 * sizeof(double));
					if (!d_d2[k][j][i]) {
						fprintf(stderr, "d_d2 %d, %d, %d failed to allocate!\n", k, j, i);
					}


					// calculate dc diffusion tensor projected with Fibre Orientation, the material is axially anisotropic
					dc[k][j][i][0] = d2[k][j][i] + (dd[k][j][i] * x[k][j][i] * x[k][j][i]);
					dc[k][j][i][1] = dd[k][j][i] * x[k][j][i] * y[k][j][i];
					dc[k][j][i][2] = dd[k][j][i] * x[k][j][i] * z[k][j][i];
					dc[k][j][i][3] = dd[k][j][i] * y[k][j][i] * x[k][j][i];
					dc[k][j][i][4] = d2[k][j][i] + (dd[k][j][i] * y[k][j][i] * y[k][j][i]);
					dc[k][j][i][5] = dd[k][j][i] * y[k][j][i] * z[k][j][i];
					dc[k][j][i][6] = dd[k][j][i] * z[k][j][i] * x[k][j][i];
					dc[k][j][i][7] = dd[k][j][i] * z[k][j][i] * y[k][j][i];
					dc[k][j][i][8] = d2[k][j][i] + (dd[k][j][i] * z[k][j][i] * z[k][j][i]);

					// calculate df
					// dfx/dx
					df[k][j][i][0] = (x[k][j][i + 1] - x[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][0] = (x[k][j][i] - x[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][0] = (x[k][j][i + 1] - x[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						df[k][j][i][0] = 0.0;

					//dfx/dy
					df[k][j][i][1] = (x[k][j + 1][i] - x[k][j - 1][i]) / (2 * dy);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][1] = (x[k][j][i] - x[k][j - 1][i]) / (dy);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][1] = (x[k][j + 1][i] - x[k][j][i]) / (dy);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][1] = 0.0;

					// dfx/dz
					df[k][j][i][2] = (x[k + 1][j][i] - x[k - 1][j][i]) / (2 * dz);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][2] = (x[k][j][i] - x[k - 1][j][i]) / (dz);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][2] = (x[k + 1][j][i] - x[k][j][i]) / (dz);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][2] = 0.0;


					// dfy/dx
					df[k][j][i][3] = (y[k][j][i + 1] - y[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][3] = (y[k][j][i] - y[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][3] = (y[k][j][i + 1] - y[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						df[k][j][i][3] = 0.0;

					//dfy/dy
					df[k][j][i][4] = (y[k][j + 1][i] - y[k][j - 1][i]) / (2 * dy);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][4] = (y[k][j][i] - y[k][j - 1][i]) / (dy);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][4] = (y[k][j + 1][i] - y[k][j][i]) / (dy);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][4] = 0.0;

					// dfy/dz
					df[k][j][i][5] = (y[k + 1][j][i] - y[k - 1][j][i]) / (2 * dz);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][5] = (y[k][j][i] - y[k - 1][j][i]) / (dz);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][5] = (y[k + 1][j][i] - y[k][j][i]) / (dz);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][5] = 0.0;

					// dfz/dx
					df[k][j][i][6] = (z[k][j][i + 1] - z[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						df[k][j][i][6] = (z[k][j][i] - z[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						df[k][j][i][6] = (z[k][j][i + 1] - z[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i - 1] == 0) // + - changed
						df[k][j][i][6] = 0.0;

					//dfy/dy
					df[k][j][i][7] = (z[k][j + 1][i] - z[k][j - 1][i]) / (2 * dy);
					if (atrium[k][j + 1][i] == 0)
						df[k][j][i][7] = (z[k][j][i] - z[k][j - 1][i]) / (dy);
					if (atrium[k][j - 1][i] == 0)
						df[k][j][i][7] = (z[k][j + 1][i] - z[k][j][i]) / (dy);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						df[k][j][i][7] = 0.0;

					// dfz/dz
					df[k][j][i][8] = (z[k + 1][j][i] - z[k - 1][j][i]) / (2 * dz);
					if (atrium[k + 1][j][i] == 0)
						df[k][j][i][8] = (z[k][j][i] - z[k - 1][j][i]) / (dz);
					if (atrium[k - 1][j][i] == 0)
						df[k][j][i][8] = (z[k + 1][j][i] - z[k][j][i]) / (dz);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						df[k][j][i][8] = 0.0;

					// calculate d_dd
					// d_dd/dx
					d_dd[k][j][i][0] = (dd[k][j][i + 1] - dd[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						d_dd[k][j][i][0] = (dd[k][j][i] - dd[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						d_dd[k][j][i][0] = (dd[k][j][i + 1] - dd[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						d_dd[k][j][i][0] = 0.0;

					// d_dd/dy
					d_dd[k][j][i][1] = (dd[k][j + 1][i] - dd[k][j - 1][i]) / (2 * dy);
					if (atrium[k][j + 1][i] == 0)
						d_dd[k][j][i][1] = (dd[k][j][i] - dd[k][j - 1][i]) / (dy);
					if (atrium[k][j - 1][i] == 0)
						d_dd[k][j][i][1] = (dd[k][j + 1][i] - dd[k][j][i]) / (dy);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						d_dd[k][j][i][1] = 0.0;

					// d_dd/dz
					d_dd[k][j][i][2] = (dd[k + 1][j][i] - dd[k - 1][j][i]) / (2 * dz);
					if (atrium[k + 1][j][i] == 0)
						d_dd[k][j][i][2] = (dd[k][j][i] - dd[k - 1][j][i]) / (dz);
					if (atrium[k - 1][j][i] == 0)
						d_dd[k][j][i][2] = (dd[k + 1][j][i] - dd[k][j][i]) / (dz);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						d_dd[k][j][i][2] = 0.0;

					// calculate d_d2
					// d_d2/dx
					d_d2[k][j][i][0] = (d2[k][j][i + 1] - d2[k][j][i - 1]) / (2 * dx);
					if (atrium[k][j][i + 1] == 0)
						d_d2[k][j][i][0] = (d2[k][j][i] - d2[k][j][i - 1]) / (dx);
					if (atrium[k][j][i - 1] == 0)
						d_d2[k][j][i][0] = (d2[k][j][i + 1] - d2[k][j][i]) / (dx);
					if (atrium[k][j][i + 1] == 0 && atrium[k][j][i + 1] == 0)
						d_d2[k][j][i][0] = 0.0;

					// d_d2/dy
					d_d2[k][j][i][1] = (d2[k][j + 1][i] - d2[k][j - 1][i]) / (2 * dy);
					if (atrium[k][j + 1][i] == 0)
						d_d2[k][j][i][1] = (d2[k][j][i] - d2[k][j - 1][i]) / (dy);
					if (atrium[k][j - 1][i] == 0)
						d_d2[k][j][i][1] = (d2[k][j + 1][i] - d2[k][j][i]) / (dy);
					if (atrium[k][j + 1][i] == 0 && atrium[k][j - 1][i] == 0)
						d_d2[k][j][i][1] = 0.0;

					// d_d2/dz
					d_d2[k][j][i][2] = (d2[k + 1][j][i] - d2[k - 1][j][i]) / (2 * dz);
					if (atrium[k + 1][j][i] == 0)
						d_d2[k][j][i][2] = (d2[k][j][i] - d2[k - 1][j][i]) / (dz);
					if (atrium[k - 1][j][i] == 0)
						d_d2[k][j][i][2] = (d2[k + 1][j][i] - d2[k][j][i]) / (dz);
					if (atrium[k + 1][j][i] == 0 && atrium[k - 1][j][i] == 0)
						d_d2[k][j][i][2] = 0.0;


					/*if (d_d2[k][j][i][2] != 0.0 || d_d2[k][j][i][1] != 0.0 || d_d2[k][j][i][0] != 0.0)
					    printf("k = %d, j = %d, i = %d\n", k, j, i);
					if (d_dd[k][j][i][2] != 0.0 || d_dd[k][j][i][1] != 0.0 || d_dd[k][j][i][0] != 0.0)
					    printf("k = %d, j = %d, i = %d\n", k, j, i);*/
				}
			}
		}
	}
}






void calculate_laplacian_components(unsigned char *** atrium,
                                    int nz, int ny, int nx,
                                    float ***z, float ***y, float ***x,
                                    double dx, double dd,
                                    double * * **dc, double * * **df,
                                    double * * **lap) {
	int i, j, k, n;
	double factor;

	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (atrium[k][j][i] > 0) {
					lap[k][j][i] = new double [19]; //(double *) malloc(19 * sizeof(double));
					if (!lap[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}
					for (n = 0; n < 19; ++n) {
						lap[k][j][i][n] = 0;
					}

					// indexes
					// self         = 0
					// xplus        = 1
					// xminus       = 2
					// yplus        = 3
					// yminus       = 4
					// zplus        = 5
					// zminus       = 6
					// xplusyplus   = 7
					// xminusyminus = 8
					// xplusyminus  = 9
					// xminusyplus  = 10
					// xpluszplus   = 11
					// xminuszminus = 12
					// xpluszminus  = 13
					// xminuszplus  = 14
					// ypluszplus   = 15
					// yminuszminus = 16
					// ypluszminus  = 17
					// yminuszplus  = 18

					// dvdx2
					factor = (1 / dx) * (1 / dx) * dc[k][j][i][0];
					if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  1.0 * factor;
						lap[k][j][i][2] +=  1.0 * factor;
					} else if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  2.0 * factor;
						lap[k][j][i][2] +=  0.0 * factor;
					} else if ((atrium[k][j][i + 1] == 0) && (atrium[k][j][i - 1] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  0.0 * factor;
						lap[k][j][i][2] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += 0;
					}

					// dvdy2
					factor = (1 / dx) * (1 / dx) * dc[k][j][i][4];
					if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  1.0 * factor;
						lap[k][j][i][4] +=  1.0 * factor;
					} else if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  2.0 * factor;
						lap[k][j][i][4] +=  0.0 * factor;
					} else if ((atrium[k][j + 1][i] == 0) && (atrium[k][j - 1][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  0.0 * factor;
						lap[k][j][i][4] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][3] += 0;
						lap[k][j][i][4] += 0;
					}

					// dvdz2
					factor = (1 / dx) * (1 / dx) * dc[k][j][i][8];
					if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  1.0 * factor;
						lap[k][j][i][6] +=  1.0 * factor;
					} else if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  2.0 * factor;
						lap[k][j][i][6] +=  0.0 * factor;
					} else if ((atrium[k + 1][j][i] == 0) && (atrium[k - 1][j][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  0.0 * factor;
						lap[k][j][i][6] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][5] += 0;
						lap[k][j][i][6] += 0;
					}

					// right, that's the easy bit done.  Now for the more
					// complex bits!
					// dvdx
					factor = (1.0 / 2.0) * (1 / dx) * dd * ((x[k][j][i] * df[k][j][i][0] + x[k][j][i] * df[k][j][i][0]) +
					                                        (y[k][j][i] * df[k][j][i][1] + x[k][j][i] * df[k][j][i][4]) +
					                                        (z[k][j][i] * df[k][j][i][2] + x[k][j][i] * df[k][j][i][8]));

					/* for debug purpose */
					/*if (abs(0.01 / 0.33 * factor) > 1)
					{
					    fprintf(stderr, "i = %d,j = %d, k =%d\n", i, j, k );
					}*/
					// implement upwind scheme here! haibo 2014.11.06
					if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][1] +=  factor;
						lap[k][j][i][2] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][1] += 2 * factor;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += -2 * factor;
						}


					} else if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] == 0)) {
						/*lap[k][j][i][0] += -2 * factor;
						lap[k][j][i][1] +=  2 * factor;
						lap[k][j][i][2] += 0;*/


						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][1] += 2 * factor;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += 0.0;
						}
					} else if ((atrium[k][j][i + 1] == 0) && (atrium[k][j][i - 1] > 0)) {
						/*lap[k][j][i][0] += 2 * factor;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += -2 * factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += -2 * factor;
						}

					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += 0;
					}

					// dvdy
					factor = (1.0 / 2.0) * (1 / dx) * dd * ((x[k][j][i] * df[k][j][i][3] + y[k][j][i] * df[k][j][i][0]) +
					                                        (y[k][j][i] * df[k][j][i][4] + y[k][j][i] * df[k][j][i][4]) +
					                                        (z[k][j][i] * df[k][j][i][5] + y[k][j][i] * df[k][j][i][8]));
					if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][3] +=  factor;
						lap[k][j][i][4] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][3] += 2 * factor;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += -2 * factor;
						}

					} else if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] == 0)) {


						/*lap[k][j][i][0] += -2 * factor;
						lap[k][j][i][3] +=  2 * factor;
						lap[k][j][i][4] += 0;*/
						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][3] += 2 * factor;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += 0.0;
						}


					} else if ((atrium[k][j + 1][i] == 0) && (atrium[k][j - 1][i] > 0)) {
						/*lap[k][j][i][0] += 2 * factor;
						lap[k][j][i][3] += 0;
						lap[k][j][i][4] += -2 * factor;*/
						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += -2 * factor;
						}

					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][3] += 0;
						lap[k][j][i][4] += 0;
					}

					// dvdz
					factor = (1.0 / 2.0) * (1 / dx) * dd * ((x[k][j][i] * df[k][j][i][6] + z[k][j][i] * df[k][j][i][0]) +
					                                        (y[k][j][i] * df[k][j][i][7] + z[k][j][i] * df[k][j][i][4]) +
					                                        (z[k][j][i] * df[k][j][i][8] + z[k][j][i] * df[k][j][i][8]));
					if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][5] +=  factor;
						lap[k][j][i][6] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][5] += 2 * factor;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += -2 * factor;
						}

					} else if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] == 0)) {
						/* lap[k][j][i][0] += -2 * factor;
						 lap[k][j][i][5] +=  2 * factor;
						 lap[k][j][i][6] += 0;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][5] += 2 * factor;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += 0.0;
						}
					} else if ((atrium[k + 1][j][i] == 0) && (atrium[k - 1][j][i] > 0)) {
						/* lap[k][j][i][0] +=  2 * factor;
						 lap[k][j][i][5] += 0;
						 lap[k][j][i][6] += -2 * factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += -2 * factor;
						}
					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][5] += 0;
						lap[k][j][i][6] += 0;
					}


					// dudxdy
					if ( (atrium[k][j + 1][i + 1] > 0) &&
					        (atrium[k][j - 1][i - 1] > 0) &&
					        (atrium[k][j - 1][i + 1] > 0) &&
					        (atrium[k][j + 1][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dx) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  +=  factor;
						lap[k][j][i][8]  +=  factor;
						lap[k][j][i][9]  += -factor;
						lap[k][j][i][10] += -factor;
					}

					// dudxdz
					if ( (atrium[k + 1][j][i + 1] > 0) &&
					        (atrium[k - 1][j][i - 1] > 0) &&
					        (atrium[k - 1][j][i + 1] > 0) &&
					        (atrium[k + 1][j][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dx) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  factor;
						lap[k][j][i][12] +=  factor;
						lap[k][j][i][13] += -factor;
						lap[k][j][i][14] += -factor;
					}

					// dudydz
					if ( (atrium[k + 1][j + 1][i] > 0) &&
					        (atrium[k - 1][j - 1][i] > 0) &&
					        (atrium[k + 1][j - 1][i] > 0) &&
					        (atrium[k - 1][j + 1][i] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dx) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] +=  factor;
						lap[k][j][i][16] +=  factor;
						lap[k][j][i][17] += -factor;
						lap[k][j][i][18] += -factor;
					}
				}
			}
		}
	}
}


void calculate_laplacian_components_with_diffusion_heterogeneity ( unsigned char *** atrium,
        int nz, int ny, int nx,
        float ***z, float ***y, float ***x,
        double dx, double dy, double dz,
        double ***dd, double ***d2,
        double * * **dc, double * * **df,
        double * * **d_dd, double * * **d_d2,
        double * * **lap) {
	int i, j, k, n;
	double factor;

	for (k = 1; k < nz + 1; ++k) {
		for (j = 1; j < ny + 1; ++j) {
			for (i = 1; i < nx + 1; ++i) {
				if (atrium[k][j][i] > 0) {
					lap[k][j][i] = new double [19];//(double *) malloc(19 * sizeof(double));
					if (!lap[k][j][i]) {
						fprintf(stderr, "%d, %d, %d failed to allocate!\n", k, j, i);
					}
					for (n = 0; n < 19; ++n) {
						lap[k][j][i][n] = 0;
					}

					// indexes
					// self         = 0
					// xplus        = 1
					// xminus       = 2
					// yplus        = 3
					// yminus       = 4
					// zplus        = 5
					// zminus       = 6
					// xplusyplus   = 7
					// xminusyminus = 8
					// xplusyminus  = 9
					// xminusyplus  = 10
					// xpluszplus   = 11
					// xminuszminus = 12
					// xpluszminus  = 13
					// xminuszplus  = 14
					// ypluszplus   = 15
					// yminuszminus = 16
					// ypluszminus  = 17
					// yminuszplus  = 18

					// dvdx2
					factor = (1 / dx) * (1 / dx) * dc[k][j][i][0];
					if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  1.0 * factor;
						lap[k][j][i][2] +=  1.0 * factor;
					} else if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  2.0 * factor;
						lap[k][j][i][2] +=  0.0 * factor;
					} else if ((atrium[k][j][i + 1] == 0) && (atrium[k][j][i - 1] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][1] +=  0.0 * factor;
						lap[k][j][i][2] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += 0;
					}

					// dvdy2
					factor = (1 / dy) * (1 / dy) * dc[k][j][i][4];
					if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  1.0 * factor;
						lap[k][j][i][4] +=  1.0 * factor;
					} else if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  2.0 * factor;
						lap[k][j][i][4] +=  0.0 * factor;
					} else if ((atrium[k][j + 1][i] == 0) && (atrium[k][j - 1][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][3] +=  0.0 * factor;
						lap[k][j][i][4] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0.0;
						lap[k][j][i][3] += 0.0;
						lap[k][j][i][4] += 0.0;
					}

					// dvdz2
					factor = (1 / dz) * (1 / dz) * dc[k][j][i][8];
					if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  1.0 * factor;
						lap[k][j][i][6] +=  1.0 * factor;
					} else if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] == 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  2.0 * factor;
						lap[k][j][i][6] +=  0.0 * factor;
					} else if ((atrium[k + 1][j][i] == 0) && (atrium[k - 1][j][i] > 0)) {
						lap[k][j][i][0] += -2.0 * factor;
						lap[k][j][i][5] +=  0.0 * factor;
						lap[k][j][i][6] +=  2.0 * factor;
					} else {
						lap[k][j][i][0] += 0.0;
						lap[k][j][i][5] += 0.0;
						lap[k][j][i][6] += 0.0;
					}


					/* comment for second order derivatives */
					// dudxdy
					if ( (atrium[k][j + 1][i + 1] > 0) &&
					        (atrium[k][j - 1][i - 1] > 0) &&
					        (atrium[k][j - 1][i + 1] > 0) &&
					        (atrium[k][j + 1][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1.0 / dx) * (1.0 / dy) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  +=  factor;
						lap[k][j][i][8]  +=  factor;
						lap[k][j][i][9]  += -factor;
						lap[k][j][i][10] += -factor;
					}
					// dudxdy
					else if ( (atrium[k][j + 1][i + 1] == 0) &&
					          (atrium[k][j - 1][i - 1] > 0) &&
					          (atrium[k][j - 1][i + 1] > 0) &&
					          (atrium[k][j + 1][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1.0 / dx) * (1.0 / dy) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  +=  0.0;
						lap[k][j][i][8]  +=  factor;
						lap[k][j][i][9]  += -0.5 * factor;
						lap[k][j][i][10] += -0.5 * factor;
					}
					// dudxdy
					else if ( (atrium[k][j + 1][i + 1] > 0) &&
					          (atrium[k][j - 1][i - 1] == 0) &&
					          (atrium[k][j - 1][i + 1] > 0) &&
					          (atrium[k][j + 1][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1.0 / dx) * (1.0 / dy) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  +=  factor;
						lap[k][j][i][8]  +=  0.0;
						lap[k][j][i][9]  += -0.5 * factor;
						lap[k][j][i][10] += -0.5 * factor;
					}
					// dudxdy
					else if ( (atrium[k][j + 1][i + 1] > 0) &&
					          (atrium[k][j - 1][i - 1] > 0) &&
					          (atrium[k][j - 1][i + 1] == 0) &&
					          (atrium[k][j + 1][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1.0 / dx) * (1.0 / dy) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  +=  0.5 * factor;
						lap[k][j][i][8]  +=  0.5 * factor;
						lap[k][j][i][9]  +=  0.0;
						lap[k][j][i][10] += -factor;
					}
					// dudxdy
					else if ( (atrium[k][j + 1][i + 1] > 0) &&
					          (atrium[k][j - 1][i - 1] > 0) &&
					          (atrium[k][j - 1][i + 1] > 0) &&
					          (atrium[k][j + 1][i - 1] == 0)) {
						factor = (1.0 / 4.0) * (1.0 / dx) * (1.0 / dy) * (dc[k][j][i][1] + dc[k][j][i][3]);
						lap[k][j][i][7]  += 0.5 * factor;
						lap[k][j][i][8]  += 0.5 * factor;
						lap[k][j][i][9]  += -factor;
						lap[k][j][i][10] += 0.0;
					}

					// dudxdz
					if ( (atrium[k + 1][j][i + 1] > 0) &&
					        (atrium[k - 1][j][i - 1] > 0) &&
					        (atrium[k - 1][j][i + 1] > 0) &&
					        (atrium[k + 1][j][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dz) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  factor;
						lap[k][j][i][12] +=  factor;
						lap[k][j][i][13] += -factor;
						lap[k][j][i][14] += -factor;
					}
					else if ( (atrium[k + 1][j][i + 1] == 0) &&
					          (atrium[k - 1][j][i - 1] > 0) &&
					          (atrium[k - 1][j][i + 1] > 0) &&
					          (atrium[k + 1][j][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dz) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  0.0;
						lap[k][j][i][12] +=  factor;
						lap[k][j][i][13] += -0.5 * factor;
						lap[k][j][i][14] += -0.5 * factor;
					}
					else if ( (atrium[k + 1][j][i + 1] > 0) &&
					          (atrium[k - 1][j][i - 1] == 0) &&
					          (atrium[k - 1][j][i + 1] > 0) &&
					          (atrium[k + 1][j][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dz) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  factor;
						lap[k][j][i][12] +=  0.0;
						lap[k][j][i][13] += -0.5 * factor;
						lap[k][j][i][14] += -0.5 * factor;
					}
					else if ( (atrium[k + 1][j][i + 1] > 0) &&
					          (atrium[k - 1][j][i - 1] > 0) &&
					          (atrium[k - 1][j][i + 1] == 0) &&
					          (atrium[k + 1][j][i - 1] > 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dz) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  0.5 * factor;
						lap[k][j][i][12] +=  0.5 * factor;
						lap[k][j][i][13] += 0.0;
						lap[k][j][i][14] += -factor;
					}
					else if ( (atrium[k + 1][j][i + 1] > 0) &&
					          (atrium[k - 1][j][i - 1] > 0) &&
					          (atrium[k - 1][j][i + 1] > 0) &&
					          (atrium[k + 1][j][i - 1] == 0)) {
						factor = (1.0 / 4.0) * (1 / dx) * (1 / dz) * (dc[k][j][i][2] + dc[k][j][i][6]);
						lap[k][j][i][11] +=  0.5 * factor;
						lap[k][j][i][12] +=  0.5 * factor;
						lap[k][j][i][13] += -factor;
						lap[k][j][i][14] += 0.0;
					}

					// dudydz
					if ( (atrium[k + 1][j + 1][i] > 0) &&
					        (atrium[k - 1][j - 1][i] > 0) &&
					        (atrium[k + 1][j - 1][i] > 0) &&
					        (atrium[k - 1][j + 1][i] > 0)) {
						factor = (1.0 / 4.0) * (1 / dy) * (1 / dz) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] +=  factor;
						lap[k][j][i][16] +=  factor;
						lap[k][j][i][17] += -factor;
						lap[k][j][i][18] += -factor;
					}
					// dudydz
					else if ( (atrium[k + 1][j + 1][i] == 0) &&
					          (atrium[k - 1][j - 1][i] > 0) &&
					          (atrium[k + 1][j - 1][i] > 0) &&
					          (atrium[k - 1][j + 1][i] > 0)) {
						factor = (1.0 / 4.0) * (1 / dy) * (1 / dz) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] +=  0.0;
						lap[k][j][i][16] +=  factor;
						lap[k][j][i][17] += -0.5 * factor;
						lap[k][j][i][18] += -0.5 * factor;
					}
					// dudydz
					else if ( (atrium[k + 1][j + 1][i] > 0) &&
					          (atrium[k - 1][j - 1][i] == 0) &&
					          (atrium[k + 1][j - 1][i] > 0) &&
					          (atrium[k - 1][j + 1][i] > 0)) {
						factor = (1.0 / 4.0) * (1 / dy) * (1 / dz) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] +=  factor;
						lap[k][j][i][16] +=  0.0;
						lap[k][j][i][17] += -0.5 * factor;
						lap[k][j][i][18] += -0.5 * factor;
					}
					// dudydz
					else if ( (atrium[k + 1][j + 1][i] > 0) &&
					          (atrium[k - 1][j - 1][i] > 0) &&
					          (atrium[k + 1][j - 1][i] == 0) &&
					          (atrium[k - 1][j + 1][i] > 0)) {
						factor = (1.0 / 4.0) * (1 / dy) * (1 / dz) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] +=  0.5 * factor;
						lap[k][j][i][16] +=  0.5 * factor;
						lap[k][j][i][17] += 0.0;
						lap[k][j][i][18] += -factor;
					}
					// dudydz
					else if ( (atrium[k + 1][j + 1][i] > 0) &&
					          (atrium[k - 1][j - 1][i] > 0) &&
					          (atrium[k + 1][j - 1][i] > 0) &&
					          (atrium[k - 1][j + 1][i] == 0)) {
						factor = (1.0 / 4.0) * (1 / dy) * (1 / dz) * (dc[k][j][i][5] + dc[k][j][i][7]);
						lap[k][j][i][15] += 0.5 * factor;
						lap[k][j][i][16] += 0.5 * factor;
						lap[k][j][i][17] += -factor;
						lap[k][j][i][18] += 0.0;
					}

					// right, that's the easy bit done.  Now for the more
					// complex bits!
					// dvdx
					factor = (1.0 / 2.0) * (1 / dx) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][0] + x[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * x[k][j][i] * d_dd[k][j][i][0] + d_d2[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][1] + x[k][j][i] * df[k][j][i][4]) +
					                                   x[k][j][i] * y[k][j][i] * d_dd[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][2] + x[k][j][i] * df[k][j][i][8]) +
					                                   x[k][j][i] * z[k][j][i] * d_dd[k][j][i][2]
					                                  );

					// should be this??? // 16:50:03, Tue, 31-December-2019, By Haibo
					/*factor = (1.0 / 2.0) * (1 / dx) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][0] + x[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * x[k][j][i] * d_dd[k][j][i][0] + d_d2[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][3] + x[k][j][i] * df[k][j][i][4]) +
					                                   x[k][j][i] * y[k][j][i] * d_dd[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][6] + x[k][j][i] * df[k][j][i][8]) +
					                                   x[k][j][i] * z[k][j][i] * d_dd[k][j][i][2]
					                                  );*/
					/*factor = (1 / 2) * (1 / dx) * dd[k][j][i] * ((x[k][j][i] * df[k][j][i][0] + x[k][j][i] * df[k][j][i][0]) +
					         (y[k][j][i] * df[k][j][i][1] + x[k][j][i] * df[k][j][i][4]) +
					         (z[k][j][i] * df[k][j][i][2] + x[k][j][i] * df[k][j][i][8]));*/

					// implement upwind scheme here! haibo 2014.11.06
					if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][1] +=  factor;
						lap[k][j][i][2] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][1] += 2 * factor;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += -2 * factor;
						}


					} else if ((atrium[k][j][i + 1] > 0) && (atrium[k][j][i - 1] == 0)) {
						/*lap[k][j][i][0] += -2 * factor;
						lap[k][j][i][1] +=  2 * factor;
						lap[k][j][i][2] += 0;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][1] += 2 * factor;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += 0.0;
						}
					} else if ((atrium[k][j][i + 1] == 0) && (atrium[k][j][i - 1] > 0)) {
						/*lap[k][j][i][0] += 2 * factor;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += -2 * factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][1] += 0.0;
							lap[k][j][i][2] += -2 * factor;
						}

					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][1] += 0;
						lap[k][j][i][2] += 0;
					}



					// dvdy
					factor = (1.0 / 2.0) * (1 / dy) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][3] + y[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * y[k][j][i] * d_dd[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][4] + y[k][j][i] * df[k][j][i][4]) +
					                                   y[k][j][i] * y[k][j][i] * d_dd[k][j][i][1] + d_d2[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][5] + y[k][j][i] * df[k][j][i][8]) +
					                                   z[k][j][i] * y[k][j][i] * d_dd[k][j][i][2]
					                                  );


					// this is wrong???? // 16:50:59, Tue, 31-December-2019, By Haibo
					/*factor = (1.0 / 2.0) * (1 / dy) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][1] + y[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * y[k][j][i] * d_dd[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][4] + y[k][j][i] * df[k][j][i][4]) +
					                                   y[k][j][i] * y[k][j][i] * d_dd[k][j][i][1] + d_d2[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][7] + y[k][j][i] * df[k][j][i][8]) +
					                                   z[k][j][i] * y[k][j][i] * d_dd[k][j][i][2]
					                                  );*/
					/*factor = (1 / 2) * (1 / dx) * dd[k][j][i] * ((x[k][j][i] * df[k][j][i][3] + y[k][j][i] * df[k][j][i][0]) +
					         (y[k][j][i] * df[k][j][i][4] + y[k][j][i] * df[k][j][i][4]) +
					         (z[k][j][i] * df[k][j][i][5] + y[k][j][i] * df[k][j][i][8]));*/

					if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][3] +=  factor;
						lap[k][j][i][4] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][3] += 2 * factor;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += -2 * factor;
						}

					} else if ((atrium[k][j + 1][i] > 0) && (atrium[k][j - 1][i] == 0)) {


						/*lap[k][j][i][0] += -2 * factor;
						lap[k][j][i][3] +=  2 * factor;
						lap[k][j][i][4] += 0;*/
						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][3] += 2 * factor;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += 0.0;
						}


					} else if ((atrium[k][j + 1][i] == 0) && (atrium[k][j - 1][i] > 0)) {
						/*lap[k][j][i][0] += 2 * factor;
						lap[k][j][i][3] += 0;
						lap[k][j][i][4] += -2 * factor;*/
						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][3] += 0.0;
							lap[k][j][i][4] += -2 * factor;
						}

					} else {
						lap[k][j][i][0] += 0;
						lap[k][j][i][3] += 0;
						lap[k][j][i][4] += 0;
					}

					// dvdz
					/*factor = (1.0 / 2.0) * (1.0 / dz) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][6] + z[k][j][i] * df[k][j][i][0]) + \
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][7] + z[k][j][i] * df[k][j][i][4]) +  \
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][8] + z[k][j][i] * df[k][j][i][8]) \
					                                  );*/
					/*+
					// x[k][j][i] * z[k][j][i] * d_dd[k][j][i][0] +
					// y[k][j][i] * z[k][j][i] * d_dd[k][j][i][1] +
					z[k][j][i] * z[k][j][i] * d_dd[k][j][i][2] + d_d2[k][j][i][2]*/

					// printf("%.10f\n", (1/2));
					factor = (1.0 / 2.0) * (1 / dz) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][6] + z[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * z[k][j][i] * d_dd[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][7] + z[k][j][i] * df[k][j][i][4]) +
					                                   y[k][j][i] * z[k][j][i] * d_dd[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][8] + z[k][j][i] * df[k][j][i][8]) +
					                                   z[k][j][i] * z[k][j][i] * d_dd[k][j][i][2] + d_d2[k][j][i][2]);



					//this was wrong? // 16:51:29, Tue, 31-December-2019, By Haibo
					/*factor = (1.0 / 2.0) * (1 / dz) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][2] + z[k][j][i] * df[k][j][i][0]) +
					                                   x[k][j][i] * z[k][j][i] * d_dd[k][j][i][0] +
					                                   dd[k][j][i] * (y[k][j][i] * df[k][j][i][5] + z[k][j][i] * df[k][j][i][4]) +
					                                   y[k][j][i] * z[k][j][i] * d_dd[k][j][i][1] +
					                                   dd[k][j][i] * (z[k][j][i] * df[k][j][i][8] + z[k][j][i] * df[k][j][i][8]) +
					                                   z[k][j][i] * z[k][j][i] * d_dd[k][j][i][2] + d_d2[k][j][i][2]);*/

					/*factor = (1.0 / 2.0) * (1.0 / dz) * (dd[k][j][i] * (x[k][j][i] * df[k][j][i][6] + z[k][j][i] * df[k][j][i][0]) +
					                                     dd[k][j][i] * (y[k][j][i] * df[k][j][i][7] + z[k][j][i] * df[k][j][i][4]) +
					                                     dd[k][j][i] * (z[k][j][i] * df[k][j][i][8] + z[k][j][i] * df[k][j][i][8])
					                                    );*/
					if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] > 0)) {

						/*centred difference*/
						/*lap[k][j][i][0] += 0;
						lap[k][j][i][5] +=  factor;
						lap[k][j][i][6] += -factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][5] += 2 * factor;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += -2 * factor;
						}

					} else if ((atrium[k + 1][j][i] > 0) && (atrium[k - 1][j][i] == 0)) {
						/* lap[k][j][i][0] += -2 * factor;
						 lap[k][j][i][5] +=  2 * factor;
						 lap[k][j][i][6] += 0;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += -2 * factor;
							lap[k][j][i][5] += 2 * factor;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 0.0;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += 0.0;
						}
					} else if ((atrium[k + 1][j][i] == 0) && (atrium[k - 1][j][i] > 0)) {
						/* lap[k][j][i][0] +=  2 * factor;
						 lap[k][j][i][5] += 0;
						 lap[k][j][i][6] += -2 * factor;*/

						/* upwind scheme */
						if (factor >= 0.0)
						{

							lap[k][j][i][0] += 0.0;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += 0.0;
						} else {
							lap[k][j][i][0] += 2 * factor;
							lap[k][j][i][5] += 0.0;
							lap[k][j][i][6] += -2 * factor;
						}
					} else {
						lap[k][j][i][0] += 0.0;
						lap[k][j][i][5] += 0.0;
						lap[k][j][i][6] += 0.0;
					}

				}
			}
		}
	}
}

#endif