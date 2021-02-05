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

	// CVOde_Cell **ptissue = new CVOde_Cell* [NN];
	CVOde_TISSUE ptissue(NX, NY, NEQ, 0.2, fnew_pig_vm_as_para, true, CONTROL);

	ptissue.create_stim_map("LEFT", 3);	//(STIM_TYPE, NUM_CELLS_TO_STIM)
	

	// std::ofstream outfile;
	// std::string ofilename = "./results/2D_CONTROL_results.txt";
	// outfile.open(ofilename);

	
	double dt = 0.1; 
	int out_dt = 100; 
	double t_total = 2000;
	int tn = 0; //integer t, counts all iterationss

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	omp_set_num_threads(8);
	//Main Loop
	for (double t = 0; t <= t_total; t += dt) {

		#pragma omp parallel for
		for(int id=0; id<NN; id++){
			ptissue.tissue[id]->solve_single_time_step_vm_para(t + dt, dt);	

		}

		if(tn%out_dt == 0){
			std::cout << "t = " << tn*dt << " ms" <<  std::endl;	
		}
		

		
		ptissue.ekmodel_diffusion(t);

		if(tn%out_dt == 0){
			ptissue.print_tissue(tn);	
		}
		
		// v_new = ptissue.cell.V;

		// if (v_new != v_new) {
		// 	std::cerr << " NaNs Encountered, Exiting Programe... ... \n\n\n";
		// 	std::exit(0);
		// }

		tn++;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	// double elapsed = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Computation Time = " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0 << " seconds	" <<std::endl;

}

















