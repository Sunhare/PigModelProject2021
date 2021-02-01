#include <stdio.h>
#include <zlib.h>
#include <stdlib.h>
#include <math.h>

#define NX 107
#define NY 101
#define NZ 1

int geometry_int[NZ][NY][NX];

int outgeometry_int[NZ][NY][NX];
unsigned char geometry[NZ][NY][NX];
unsigned char theta[NZ][NY][NX];
unsigned char phi[NZ][NY][NX];

int main(){

	int i, j, k;
	FILE *in, *out;
	gzFile gz;

	double FCell;

	//in = fopen("123Geometry.txt", "r");
	in = fopen("stimulationmap_small.dat", "r");
	//in = fopen("../Desktop/FullGeometryWithPFandAVN_17032012/MikeGeo.txt", "r");

	for (k=0;k<NZ;k++){
		for (j=0;j<NY;j++){
		        for (i=0;i<NX;i++){
			        fscanf(in, "%d\n", &geometry_int[k][j][i]);
						if (geometry_int[k][j][i] < 0) geometry_int[k][j][i] = 0;
						geometry[k][j][i] = geometry_int[k][j][i];
						theta[k][j][i] = 0;
						phi[k][j][i] = 43;
					}
			}
	}
	fclose(in);

/*	in = fopen("Fcell.txt", "r");
	out = fopen("1DFcell.txt", "wt");
	for (k=0;k<NZ;k++){
		for (j=0;j<NY;j++){
		        for (i=0;i<NX;i++){
			        fscanf(in, "%d ", FCell);
				if(geometry_int[k][j][i] != 0){
					fprintf(out, "%d\n", FCell);
				}
			}
		}
	}
	fclose(in);
	fclose(out);
*/
	gz = gzopen("atria.stim.small.gz", "wb9");
	gzwrite(gz, geometry, NX*NY*NZ);
	gzclose(gz);

	// gz = gzopen("atria.theta.gz", "wb9");
	// gzwrite(gz, theta, NX*NY*NZ);
	// gzclose(gz);

	// gz = gzopen("atria.phi.gz", "wb9");
	// gzwrite(gz, phi, NX*NY*NZ);
	// gzclose(gz);

}

