/*  Post Processing Script *
 *  Compute Activation Pattern (simu_time sequence)
*  Input: Geometry, Dimension, One-D array of AP
 *  Options: bin - binary, xz - bin.xz
 *  Compile: icc/gcc source.c -lz -o APD
 *  Execute: ./APD 500 600 bin folder 


 *  Haibo Ni

 *  Haibo.Ni0822@gmail.com

 *	update: Sun 05 Apr 2015 14:27:15 BST 	
 *  update: 13th, Nov. 2014
 */


#include <stdio.h>
#include <zlib.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>



/* Downsampled IS ventricle dimension */
#define NX (125)
#define NY (120)
#define NZ (1)

#ifndef AP_INFOR_H
#define AP_INFOR_H
typedef struct {
	float Vmax, Vmin, timeAPDstart, timeAPDend, dVdtmax, dVdt, dVdt_pre, APD_out_end[2];
	int APD_switch, APD_count, Vmax_switch, APD_out_swhich;
	float APD90, APD50, APD20, APD75;
	float Vm_prev;
	float v90, v75, v50, v20;
	float ICaL_in, RyR_in;
	float Istim_prev;
	float AMP, AMP_last;
	float APD90_prev;
	float t_since_up_stroke;
	char first_cmp;
	FILE *out;
} AP_infor;

#endif
void AP_information_initialise(AP_infor *AP);
void APD90_measure_using_dvdt_max(double t, double dt, double Vm, AP_infor *AP);

#define MIN (-80.0)
#define MAX (20.0)

unsigned char c[NZ][NY][NX];
int ccc[NZ][NY][NX];
float *s;
float *si;
int *apdswitch;
float *simu_time;
float *APD;
float *RT;
float *APD_new;
char *Cell_type;
AP_infor * AP_struct;


int main (int argc, char **argv) {
	int g, h, i, counter, offset, n;
	char command[256];
	gzFile gz;
	FILE *p, *out;// *outtext *in;
	// char *str;

	int CVzup;
	int CVzdown;
	float first;
	int CVyplus;
	int CVYmins;
	int firstx, firsty, firstz;
	int peak, RP;
	unsigned int count;
	int early_san, early_RA, early_LA, late_san, late_RA, late_LA, earlyPV, latePV, earlyBB, lateBB, earlyAS, lateAS;

	int start_time, end_time;
	std::string mode;
	start_time = atoi(argv[1]);
	end_time   = atoi(argv[2]);
	mode = argv[3];
	std::string::size_type posBeginIdx, posEndIdx;
	posBeginIdx = 0;
        posEndIdx = 0;
	std::string folder(argv[4]);

	std::string output_folder;    /* get rid of all '..' and '/' */

        for (int i = 0; i<argc; i++) std::cout << argv[i] << std::endl;

	if (folder.substr(0, 3) == "../") {
		output_folder = folder.substr(3);
	} else {
		output_folder = folder;
	}
        std::cout << "read in folder " << folder << std::endl;
	std::cout << "output folder " << output_folder << std::endl;
        std::size_t found = output_folder.find_first_of("./");
	while (found != std::string::npos) {
		std::cout << found << std::endl;
		output_folder.replace(found, 1, "_");
		found = output_folder.find_first_of("./");
	}
	std::cout << "output folder " << output_folder << std::endl;
	early_san = early_RA = early_LA = earlyPV = earlyBB = earlyAS = 3000;
	late_san = late_RA = late_LA  = latePV = lateBB = lateAS = 0;

	gz = gzopen("../Geometry/TWO_D_Plat_125X120.geo.gz", "r");


	if (!gz) {
		fprintf(stderr, "geo.gz file does not exist!!! \n");
		exit(EXIT_FAILURE);
	}
	gzread(gz, c, NZ * NY * NX);
	gzclose(gz);
	// printf("1111asdfe\n");

	count = 0;
	for (g = 0; g < NZ; g++) {
		for (h = 0; h < NY; h++) {
			for (i = 0; i < NX; i++) {
				if (c[g][h][i] != 0) {
					ccc[g][h][i] = 1;
					count++;
				} else ccc[g][h][i] = 0;
			}
		}
	}

	const unsigned long int CELL_NUM = count;
	printf("CELL_NUM = %d\n", count);
	Cell_type = (char *) malloc(CELL_NUM * sizeof(char));
	count = 0;

	int nn = 0;
	for (g = 0; g < NZ; g++) {
		for (h = 0; h < NY; h++) {
			for (i = 0; i < NX; i++) {
				if (c[g][h][i] != 0) {
					Cell_type[nn] = c[g][h][i];
					nn++;
				}

			}
		}
	}

	s = (float*)malloc(CELL_NUM * sizeof(float));
	si = (float*)malloc(CELL_NUM * sizeof(float));

	simu_time = (float*)malloc(CELL_NUM * sizeof(float));
	apdswitch = (int*)malloc(CELL_NUM * sizeof(int));
	APD = (float*)malloc(CELL_NUM * sizeof(float));
	RT = (float*)malloc(CELL_NUM * sizeof(float));
	APD_new = (float*)malloc(CELL_NUM * sizeof(float));
	AP_struct = (AP_infor*)malloc(CELL_NUM * sizeof(AP_infor));


	for (n = 0; n < CELL_NUM; n++) {
		simu_time[n] = 115000;
		apdswitch[n] = 1;
		APD[n] = 115000;
		APD_new[n] = 115000;
		AP_information_initialise(&AP_struct[n]);
	}

	printf("CELL_NUM = %ld\n", CELL_NUM);
	for (counter = start_time; counter <= end_time; counter++) {
		std::string str;
		if (mode == "xz") {
			str += folder;
			char tmp_char[100];

			sprintf(tmp_char, "/v_%04d.bin.xz", counter);
			str += tmp_char;

			sprintf(command, "xzcat %s", str.c_str());
			p = popen(command, "r");
			int num = fread(s, sizeof(float), CELL_NUM, p);
			pclose(p);
			if (num != CELL_NUM) {
				fprintf(stderr, "input data num and cell num does not match in file %s !\n", str.c_str());
				continue;
			}
		} else if ( mode == "bin") {
			str += folder;
			char tmp_char[100];

			sprintf(tmp_char, "/v_%04d.bin", counter);
			str += tmp_char;

			FILE *in;
			in = fopen(str.c_str(), "rb");
			if (!in) {
				fprintf(stderr, "file %s does not exist !\n", str.c_str());
				continue;
			}
			int num = fread(s, sizeof(float), CELL_NUM, in);
			if (num != CELL_NUM) {
				fprintf(stderr, "input data num and cell num does not match in file %s !\n", str.c_str());
				continue;
			}
			fclose(in);
		} else {
			fprintf(stderr, "Invalid data file format mode!!! \n");
			exit(EXIT_FAILURE);
		}

		std::cout << "Processing Data File " << str << std::endl;

		n = 0;
		// printf("counter = %d \n", counter);
		for (n = 0; n < CELL_NUM; ++n) {
			FILE * out;
			APD90_measure_using_dvdt_max(counter, 2, s[n], &AP_struct[n]);
			if (simu_time[n] >= 4999) {
				if (s[n] > -20) {
					simu_time[n] = counter;
					// printf("counter = %d\n", counter);
				}
			} else {
				if (apdswitch[n] == 1) {
					if (Cell_type[n] == 101) RP = -60;
					else RP = -80;
					if (s[n] < -65/*RP + 5*/) {
						apdswitch[n] = 0;
						APD[n] = counter - simu_time[n];
					}
				}
			}
		}
	} // end for


	first = 1112500;
	n = 0;
	firstx = 0;
	firsty = 0;
	firstz = 0;
	int cell_activate = 0;
	//find earliest activation
	for (g = 0; g < NZ; ++g) {
		for (h = 0; h < NY; ++h) {
			for (i = 0; i < NX; ++i) {

				if ((c[g][h][i] != 0)) {
					// fprintf(stderr, "[n] = %d\n", n);
					if (simu_time[n] < 5000) {
						cell_activate++;
						if (simu_time[n] < first) {
							first = simu_time[n];
							firstx = i;
							firsty = h;
							firstz = g;
							// fprintf(stderr, "simu_time[n] = %d\n", simu_time[n]);
						}
					}
					n++;
				}
			}
		}
	}

	for (n = 0; n < CELL_NUM; ++n) {
		APD_new[n] = AP_struct[n].APD90;

		std::cout << APD_new[n] << std::endl;
	}



	for (n = 0; n < CELL_NUM; ++n) {
		if (fabs(APD_new[n] - APD[n]) > 10)
			printf("at n = %d , APD not consistent, value difference = %f \n", n, fabs(APD_new[n] - APD[n]) );
	}


	for (i = 0; i < CELL_NUM; i++) {
		RT[i] = simu_time[i] + APD[i];
	}


	printf("\n\n");
	printf("******************************************************\n");
	printf("\t Total_Number_of_Cells: %ld \n", CELL_NUM);
	printf("\t Cells Activated: %d \n", cell_activate);
	printf("\t First Activation Time = %f\n", first);
	printf("\t Firstx = %d\n", firstx);
	printf("\t Firsty = %d\n", firsty);
	printf("\t Firstz = %d\n", firstz);
	printf("******************************************************\n");
	printf("\n\n");
	printf("first activation: %g\n First SAN: %d\n  Last SAN: %d\n  First RA: %d\n Last RA %d\n First LA %d\n Last LA %d\n", first, early_san, late_san, early_RA, late_RA, early_LA, late_LA);
	printf("First PV: %d\n  Last PV: %d\n  First BB: %d\n Last BB %d\n First AS %d\n Last AS %d\n", earlyPV, latePV, earlyBB, lateBB, earlyAS, lateAS);


	std::string filename;
	filename = "Results/" + output_folder + "_APD_distribution.bin";

	out = fopen(filename.c_str(), "wb+");
	if (!out) {
		perror(filename.c_str());
	}
	fwrite(APD, CELL_NUM, sizeof(float), out);
	fclose(out);

	filename = "Results/" + output_folder + "_AT_distribution.bin";

	out = fopen(filename.c_str(), "wb+");
	if (!out)
		perror(filename.c_str());
	fwrite(simu_time, CELL_NUM, sizeof(float), out);
	fclose(out);

	filename = "Results/" + output_folder + "_NewAPD_distribution.bin";

	out = fopen(filename.c_str(), "wb+");
	if (!out)
		perror(filename.c_str());
	fwrite(APD_new, CELL_NUM, sizeof(float), out);
	fclose(out);

	filename = "Results/" + output_folder + "_RT_distribution.bin";

	out = fopen(filename.c_str(), "wb+");
	if (!out)
		perror(filename.c_str());
	fwrite(RT, CELL_NUM, sizeof(float), out);
	fclose(out);

	//  str = malloc (8*sizeof(char));
	//   sprintf(str, "A%s.vtk", i);

	char write_vtk = 0;
	if (argc >= 6) {
		write_vtk = atoi(argv[5]);
	}
	if (write_vtk) {

		out = fopen ("APD_distribution.vtk", "wt");

		fprintf(out, "# vtk DataFile Version 3.0\n");
		fprintf(out, "vtk output\n");
		fprintf(out, "ASCII\n");
		fprintf(out, "DATASET STRUCTURED_POINTS\n");
		fprintf(out, "DIMENSIONS %d %d %d\n", NX, NY, NZ);
		fprintf(out, "SPACING 0.1 0.1 0.1\n");
		fprintf(out, "ORIGIN 0 0 0\n");
		fprintf(out, "POINT_DATA %d\n", NX * NY * NZ);
		fprintf(out, "SCALARS ImageFile float 1\n");
		fprintf(out, "LOOKUP_TABLE default\n");

		n = 0;
		for (g = 0; g < NZ; ++g) {
			for (h = 0; h < NY; ++h) {
				for (i = 0; i < NX; ++i) {
					offset = (g * NX * NY) + (h * NX) + i;
					if (c[g][h][i] == 0) {
						fprintf (out, "%f ", -100.0);
					} else {
						fprintf (out, "%f ", APD[n]);
						n++;
					}
				}
				fprintf(out, "\n");
			}
			fprintf(out, "\n");
		}

		out = fopen("Activation.vtk", "wt");

		fprintf(out, "# vtk DataFile Version 3.0\n");
		fprintf(out, "vtk output\n");
		fprintf(out, "ASCII\n");
		fprintf(out, "DATASET STRUCTURED_POINTS\n");
		fprintf(out, "DIMENSIONS %d %d %d\n", NX, NY, NZ);
		fprintf(out, "SPACING 0.1 0.1 0.1\n");
		fprintf(out, "ORIGIN 0 0 0\n");
		fprintf(out, "POINT_DATA %d\n", NX * NY * NZ);
		fprintf(out, "SCALARS ImageFile float 1\n");
		fprintf(out, "LOOKUP_TABLE default\n");

		n = 0;
		for (g = 0; g < NZ; ++g) {
			for (h = 0; h < NY; ++h) {
				for (i = 0; i < NX; ++i) {
					offset = (g * NX * NY) + (h * NX) + i;
					if (c[g][h][i] == 0) {
						fprintf (out, "%f ", -100.0);
					} else {
						fprintf (out, "%f ", simu_time[n]);
						n++;
					}
				}
				fprintf(out, "\n");
			}
			fprintf(out, "\n");
		}
		//free(str);
		fclose(out);

		out = fopen ("Repolarisaton.vtk", "wt");

		fprintf(out, "# vtk DataFile Version 3.0\n");
		fprintf(out, "vtk output\n");
		fprintf(out, "ASCII\n");
		fprintf(out, "DATASET STRUCTURED_POINTS\n");
		fprintf(out, "DIMENSIONS %d %d %d\n", NX, NY, NZ);
		fprintf(out, "SPACING 0.1 0.1 0.1\n");
		fprintf(out, "ORIGIN 0 0 0\n");
		fprintf(out, "POINT_DATA %d\n", NX * NY * NZ);
		fprintf(out, "SCALARS ImageFile float 1\n");
		fprintf(out, "LOOKUP_TABLE default\n");

		n = 0;
		for (g = 0; g < NZ; ++g) {
			for (h = 0; h < NY; ++h) {
				for (i = 0; i < NX; ++i) {
					offset = (g * NX * NY) + (h * NX) + i;
					if (c[g][h][i] == 0) {
						fprintf (out, "%f ", -100.0);
					} else {
						fprintf (out, "%f ", simu_time[n] + APD[n]);
						n++;
					}
				}
				fprintf(out, "\n");
			}
			fprintf(out, "\n");
		}
	}
	free(s);
	free(si);
	free(simu_time);
	return 0;

} /* end of main() */

void AP_information_initialise(AP_infor *AP) {
	AP->Vmax = -60.0;
	AP->Vmin = 0.0;
	AP->timeAPDstart = 0.0;
	AP->timeAPDend = 0.0;
	AP->dVdtmax = 0.0;
	AP->APD_out_end[0] = 0.0;
	AP->APD_out_end[1] = 0.0;

	AP->APD_switch = 0;
	AP->APD_count = 0;
	AP->Vmax_switch = 0;
	AP->APD_out_swhich = 0;
	AP->APD90 = AP->APD75 = AP->APD50 = AP->APD20 = 0.0;
	AP->Vm_prev = 0.0;
	AP->v90 = -1.0;
	AP->v75 = -1.0;
	AP->v50 = -1.0;
	AP->v20 = -1.0;
	AP->ICaL_in = 0.0;
	AP->RyR_in = 0.0;
	AP->Istim_prev = 0.0;
	AP->first_cmp = 1;
	AP->AMP = 0.0;
	AP->AMP_last = 0.0;
	AP->APD90_prev = 0.0;
	AP->t_since_up_stroke = 0.0;
	AP->out = NULL;
	AP->dVdt = 0.0;
	AP->dVdt_pre = 0.0;
}

void APD90_measure_using_dvdt_max(double t, double dt, double Vm, AP_infor *AP)  {

	if (AP->first_cmp == 1) {
		AP->Vm_prev = Vm;
		AP->first_cmp = 0;
		// printf("aasdfeb\n");
	}
	AP->dVdt_pre = AP->dVdt;
	AP->dVdt = (Vm - AP->Vm_prev) / dt;
	// printf("%f\n", AP->dVdtmax);
	if (AP->APD_switch == 0) {
		if (AP->Vmin > Vm) {
			AP->Vmin = Vm;
		}

		if (AP->dVdt >= AP->dVdtmax)
			AP->dVdtmax = AP->dVdt;
		else {

			if ((AP->dVdt_pre > AP->dVdt) && (AP->dVdtmax >= 10) && (Vm > -60.0) ) {
				AP->timeAPDstart = t - dt;
				AP->t_since_up_stroke = dt;
				AP->APD_switch = 1;
				// printf("APPAPAPPA\n");
			}
		}
	}


	if (AP->APD_switch == 1) {
		// printf("APPAPAPPAaaaa\n");

		AP->t_since_up_stroke += dt;
		if (Vm > -60.0) {
			if ((Vm > AP->Vmax) && (AP->t_since_up_stroke <= 20.0)) {
				AP->Vmax = Vm;
				//-60.000-60.000-60.-60.000-60.000000
				// printf("APPAPAPPA\n");

			} else AP->Vmax_switch = 1;
			if (AP->Vmax_switch == 1) {
				AP->APD_switch = 2;
				AP->AMP_last = AP->AMP;
				AP->AMP = AP->Vmax - AP->Vmin;
				AP->v90 = AP->Vmax - 0.9 * (AP->Vmax - AP->Vmin);
				AP->v75 = AP->Vmax - 0.75 * (AP->Vmax - AP->Vmin);
				AP->v50 = AP->Vmax - 0.50 * (AP->Vmax - AP->Vmin);
				AP->v20 = AP->Vmax - 0.20 * (AP->Vmax - AP->Vmin);
				// printf("asfde\n");
			}
		}
	} else if (AP->APD_switch == 2) {

		if ((AP->Vm_prev >= AP->v20) && (Vm <= AP->v20) ) {
			AP->APD20 = t - AP->timeAPDstart ;
			// printf("aaaa\n");

		} else if ((AP->Vm_prev >= AP->v50) && (Vm <= AP->v50 )) {
			AP->APD50 = t - AP->timeAPDstart ;
			// printf("bbbbbbbbb\n");

		} else if (AP->Vm_prev >= AP->v75 && Vm <= AP->v75 ) {
			AP->APD75 = t - AP->timeAPDstart ;
			// printf("ccccccccccc\n");

		} else if (AP->Vm_prev >= AP->v90 && Vm <= AP->v90) {
			AP->APD_switch = 0;
			AP->APD_count ++;
			AP->Vmax_switch = 0;
			AP->APD90_prev = AP->APD90;
			AP->APD90 = t - AP->timeAPDstart;

			// printf("dddddddddddd\n");
			// fprintf (out, "%.2f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n", AP->APD_count * BCL, AP->APD90, AP->APD75, AP->APD50, AP->APD20, AP->Vmax, AP->Vmin, AP->dVdtmax);
			// printf ("%.2f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n", AP->APD_count * BCL, AP->APD90, AP->APD75, AP->APD50, AP->APD20, AP->Vmax, AP->Vmin, AP->dVdtmax);
			if (AP->APD_out_swhich == 0) {
				AP->APD_out_end[0] = t - AP->timeAPDstart;
				AP->APD_out_swhich = 1;
			} else if (AP->APD_out_swhich == 1) {
				AP->APD_out_end[1] = t - AP->timeAPDstart;
				AP->APD_out_swhich = 0;
			}
			AP->dVdtmax = 0.0;
			AP->Vmin = 0.0;
			AP->Vmax = -60.0;

		}
	}

	/*double dVdt = (Vm - AP->Vm_prev) / dt;
	if (dVdt > AP->dVdtmax) AP->dVdtmax = dVdt;*/
	AP->Vm_prev = Vm;
}

