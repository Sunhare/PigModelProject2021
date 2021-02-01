#include <stdio.h>
#include <zlib.h>
#include <stdlib.h>
#include <math.h>

#define NX 125
#define NY 120
#define NZ 1

int geometry_int[NZ][NY][NX];

int outgeometry_int[NZ][NY][NX];
unsigned char geometry[NZ][NY][NX];
unsigned char theta[NZ][NY][NX];
unsigned char phi[NZ][NY][NX];

int main() {

	int i, j, k;
	FILE *in, *out;
	gzFile gz;

	double FCell;

	//in = fopen("123Geometry.txt", "r");
	// in = fopen("geo.dat", "r");
	//in = fopen("../Desktop/FullGeometryWithPFandAVN_17032012/MikeGeo.txt", "r");

	for (k = 0; k < NZ; k++) {
		for (j = 0; j < NY; j++) {
			for (i = 0; i < NX; i++) {
				// fscanf(in, "%d\n", &geometry_int[k][j][i]);

				geometry_int[k][j][i] = 1;

				int block_id = (i / 5) + 25 * (j / 5);

				// if (geometry_int[k][j][i] < 0) geometry_int[k][j][i] = 0;
				geometry[k][j][i] = 1;// block_id; // geometry_int[k][j][i];
				geometry_int[k][j][i] = block_id;
				theta[k][j][i] = 0;
				phi[k][j][i] = 155;
			}
		}
	}
	// fclose(in);

	// in = fopen("Fcell.txt", "r");
	// out = fopen("1DFcell.txt", "wt");
	out = fopen ("tissue.vtk", "wt");

	fprintf(out, "# vtk DataFile Version 3.0\n");
	fprintf(out, "vtk output\n");
	fprintf(out, "ASCII\n");
	fprintf(out, "DATASET STRUCTURED_POINTS\n");
	fprintf(out, "DIMENSIONS %d %d %d\n", NX, NY, NZ);
	fprintf(out, "SPACING 1 1 1\n");
	fprintf(out, "ORIGIN 0 0 0\n");
	fprintf(out, "POINT_DATA %d\n", NX * NY * NZ);
	fprintf(out, "SCALARS HumanAtrium int 1\n");
	fprintf(out, "LOOKUP_TABLE default\n");
	for (k = 0; k < NZ; k++) {
		for (j = 0; j < NY; j++) {
			for (i = 0; i < NX; i++) {
				// fscanf(in, "%d ", FCell);
				// if (geometry_int[k][j][i] != 0) {
					fprintf(out, "%d ", geometry_int[k][j][i]);
				// }
			}
		}
	}
	// fclose(in);
	fclose(out);

	gz = gzopen("TWO_D_Plat_125X120.geo.gz", "wb9");
	gzwrite(gz, geometry, NX * NY * NZ);
	gzclose(gz);

	gz = gzopen("TWO_D_Plat_125X120.theta.gz", "wb9");
	gzwrite(gz, theta, NX * NY * NZ);
	gzclose(gz);

	gz = gzopen("TWO_D_Plat_125X120.phi.gz", "wb9");
	gzwrite(gz, phi, NX * NY * NZ);
	gzclose(gz);

}

