/*
 * conduction.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 *
 * Functions associated with conduction through the system.
 */

#ifndef CONDUCTION_H
#define CONDUCTION_H


double **generate_laplacian(unsigned char *** atrium,
                            int nz, int ny, int nx, int count,
                            const char *theta_name, const char *phi_name,
                            double dx, double dd, double d2);
double **generate_laplacian_using_fibre_components(unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *fibre_x_file, const char *fibre_y_file, const char *fibre_z_file,
        double dx, double dd, double d2);
// generates the laplacian operator as a sparsely allocated z-y-x-components
// array.
double **generate_laplacian_test_heterogeneity ( unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *theta_name, const char *phi_name,
        double dx, double dd, double d2);
double **generate_laplacian_with_diffusion_heterogeneity(unsigned char *** atrium,
        int nz, int ny, int nx, int count,
        const char *theta_name, const char *phi_name,
        double dx, double dy, double dz,
        double ***dd, double ***d2);

double **allocate_2d_laplacian(int count);
// allocates a 2d laplacian array.

double ** **generate_3d_laplacian(unsigned char *** atrium,
                                  int nz, int ny, int nx,
                                  const char *theta_name, const char *phi_name,
                                  double dx, double dd, double d2);
// generates the laplacian operator as a sparsely allocated z-y-x-components
// array.
double ** **generate_3d_laplacian_with_diffusion_heterogeneity(unsigned char *** atrium,
        int nz, int ny, int nx,
        const char *theta_name, const char *phi_name,
        double dx, double dy, double dz,
        double ***dd, double ***d2);

double ** **generate_3d_laplacian_using_fibre_components(unsigned char *** atrium,
        int nz, int ny, int nx,
        const char *fibre_x_file, const char *fibre_y_file, const char *fibre_z_file,
        double dx, double dd, double d2);

void calculate_fibre_unit_vectors(unsigned char *** theta, unsigned char *** phi,
                                  int nz, int ny, int nx, float ***z, float ***y, float ***x);
// calculates the unit vectors of fibre orientation from the theta and phi
// files.
void convert_fibre_components_to_angles(unsigned char *** theta, unsigned char *** phi,
                                        int nz, int ny, int nx,
                                        char *fibre_x_file, char *fibre_y_file, char *fibre_z_file
                                       );  



void calculate_diffusion_tensor_components(unsigned char *** atrium,
        int nz, int ny, int nx,
        float ***z, float ***y, float ***x,
        double dx, double dd, double d2,
        double ** **dc, double ** **df);
// calculates the diffusion tensor components, and their differentials, from the
// fibre orientation unit vectors.
void calculate_diffusion_tensor_components_with_diffusion_heterogeneity(unsigned char *** atrium, \
        int nz, int ny, int nx,  \
        float ***z, float ***y, float ***x,  \
        double dx, double dy, double dz,  \
        double ***dd, double ***d2,  \
        double ** **dc, double ** **df, \
        double ** **d_dd, double ** **d_d2);



void calculate_laplacian_components(unsigned char *** atrium,
                                    int nz, int ny, int nx,
                                    float ***z, float ***y, float ***x,
                                    double dx, double dd,
                                    double ** **dc, double ** **df,
                                    double ** **lap);
// calculates the components of the laplacians from diffusion tension and the
// fibre orientation unit vectors.

void calculate_laplacian_components_with_diffusion_heterogeneity ( unsigned char *** atrium,
        int nz, int ny, int nx,
        float ***z, float ***y, float ***x,
        double dx, double dy, double dz,
        double ***dd, double ***d2,
        double ** **dc, double ** **df,
        double ** **d_dd, double ** **d_d2,
        double ** **lap);

#endif /* CONDUCTION_H */

