#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <chrono>
#include <vector>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "pig_ecc_biophysJ2021.hpp"
#include "PIG_TISSUE.hpp"

int main(){

	double dt = 0.01;  // Max time step and diffusion time step
	int out_dt = 1000; // How often to write out results 
	int nbeats = 2; // How many beats to simulate
	double pcl = 1000;
	// double t_total = pcl * nbeats; //Total simulation time (PCL = 1000);
	double t_total = 10;
	// double t_total = 1;
	int tn = 0; //integer t, counts all iterations

	PIG_ECC cell(pcl, dt, true, CONTROL) ;
	// Macros for cell type: CONTROL=1, REMOTE_HF=2, BORDER_HF=3

	//Main Loop
	std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();

	double st; //Stimulus

	for (double t = 0; t <= t_total; t += dt) {

		st = S1( 0, 22, pcl, t, 3);
		cell.pace(st);
			// t, dt);

		// if(tn%out_dt == 0){
			std::cout << "t: " << t << std::endl;
			// cell.print_to_file_Vm_only(t);
			cell.print_everything(t);
			cell.print_YDOT(t);
			std::cout << std::endl;
		// }
		tn++;
	}
	std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
	std::cout << "Computation Time = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count()) /1000000.0 << " seconds	" <<std::endl;

}










