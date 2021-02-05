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
#include "CVOde_Cell.hpp"


//0D Single Pig Cell Simulation
int main(){
	
	int NEQ = 73;

	//Macros for cell type: CONTROL=1, REMOTE_HF=2, BORDER_HF=3
	// CVOde_Cell single_cell(NEQ, 0.2, fnew_pig, false, CONTROL);
	CVOde_Cell single_cell(NEQ, 0.2, fnew_pig_vm_as_para, false, CONTROL);

	std::ofstream outfile;
	std::string ofilename = "./results/"+single_cell.cell.cell_name + "_results.txt";
	outfile.open(ofilename);

	
	double dt = 0.1; 
	int out_dt = 10; 
	double t_total = 10000;
	int tn = 0; //integer t, counts all iterations

	double v_new;

	clock_t begin = clock();
	for (double t = 0; t <= t_total; t += dt) {

		// single_cell.solve_single_time_step_vm_para(t + dt, dt);
		single_cell.solve_single_time_step(t+dt);

		// if(tn%out_dt == 0){
		// 	single_cell.cell.print_to_file_Vm_only(t, outfile);	
		// }
	

		if (v_new != v_new) {
			std::cerr << " NaNs Encountered, Exiting Programe... ... \n\n\n";
			std::exit(0);
		}

		tn++;
	}

	outfile.close();
	clock_t end = clock();

	double elapsed = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << std::setprecision(5) << "Computation Time: " << elapsed << " seconds" << std::endl;

}

















