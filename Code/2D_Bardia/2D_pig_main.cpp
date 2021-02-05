#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <ctime>
#include <vector>

#include "pig_ecc_biophysJ2021.hpp"
#include "CVOde_Tissue.hpp"


//0D Single Pig Cell Simulation
int main(){
	
	int NEQ = 73;

	int NX = 10; //X direction  
	int NY = 10; //Y direction

	int NN = NX*NY; //total number of cells
	//Macros for cell type: CONTROL=1, REMOTE_HF=2, BORDER_HF=3

	// CVOde_Cell **ptissue = new CVOde_Cell* [NN];
	CVOde_TISSUE ptissue(NX, NY, NEQ, 0.2, fnew_pig_vm_as_para, true, CONTROL);

	// ptissue.create_stim_map("LEFT");
	

	// std::ofstream outfile;
	// std::string ofilename = "./results/2D_CONTROL_results.txt";
	// outfile.open(ofilename);

	
	double dt = 0.1; 
	int out_dt = 10; 
	double t_total = 1000;
	int tn = 0; //integer t, counts all iterationss

	clock_t begin = clock();

	
	//Main Loop
	for (double t = 0; t <= t_total; t += dt/2) {

		if(tn%2==0){
			for(int id=0; id<NN; id++){
				ptissue.tissue[id]->solve_single_time_step_vm_para(t + dt, dt);	
			}
		}

		
		// ptissue.ekdiffusion();

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

	clock_t end = clock();

	double elapsed = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << std::setprecision(5) << "Computation Time: " << elapsed << " seconds" << std::endl;

}

















