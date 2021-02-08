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
#include "CVOde_Tissue.hpp"


//0D Single Pig Cell Simulation
int main(){
	
	int NEQ = 73;

	int NX = 100; //X direction  
	int NY = 100; //Y direction

	int NN = NX*NY; //total number of cells
	//Macros for cell type: CONTROL=1, REMOTE_HF=2, BORDER_HF=3

	//Pig tissue class
	CVOde_TISSUE ptissue(NX, NY, NEQ, 0.2, fnew_pig_vm_as_para, true, CONTROL);

	ptissue.create_stim_map("LEFT", 3);	//(STIM_TYPE, NUM_CELLS_TO_STIM)
	
<<<<<<< HEAD
	
	double dt = 0.1;  // Max time step and diffusion time step
	int out_dt = 100; // How often to write out results 
	int nbeats = 2; // How many beats to simulate
	double t_total = 1000 * nbeats; //Total simulation time (PCL = 1000);
	int tn = 0; //integer t, counts all iterationss

	double tectopic;
	//Control
	tectopic = 440;
	//Remote_HF
=======
	double dt = 0.1; 
	int out_dt = 10; 
	double t_total = 10000;
	int tn = 0; //integer t, counts all iterations
>>>>>>> parent of 9dd1908... Quick stash

	//Border_HF
	// tectopic = 740;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	omp_set_num_threads(8); // OMP threads to use
	//Main Loop
	for (double t = 0; t <= t_total; t += dt) {
		if(tn%out_dt == 0){
			std::cout << "t = " << tn*dt << " ms" <<  std::endl;	
		}

		#pragma omp parallel for
		for(int id=0; id<NN; id++){
			ptissue.tissue[id]->solve_single_time_step_vm_para(t + dt, dt);	 //Solve single time step for all cells
		}
		
		
		ptissue.ekmodel_diffusion(t); // Solve diffusion for tissue class

		if(t >= tectopic - 2*dt && t <= tectopic + 2*dt ){
			ptissue.ectopic_beat("TOP");
		}

		if(tn%out_dt == 0){
			ptissue.print_tissue(tn);	// Print every out_dt iterations
		}

		tn++;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Computation Time = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0 << " seconds	" <<std::endl;

}

