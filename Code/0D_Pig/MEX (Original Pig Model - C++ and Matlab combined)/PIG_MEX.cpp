#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <ctime>
#include <vector>
#include <mex.h>

#include "soltis_biophysJ2010_eccODEfile.cpp"

#include "APInfo.hpp"
#include "cell.cpp"
#include "matrix.h"

using namespace std;

//Initial conditions for state variables in array "y"
void Initialize_y_vec(N_Vector y, int sy0, char* stateFileName){
	FILE *fp = fopen( stateFileName, "r");
	double tmp;
	for ( int idy = 0; idy < sy0; idy++ ) { //Scan in variables from text file

		fscanf ( fp, "%lf", &tmp );
		Ith(y, idy+1) = tmp;

	}
	fclose( fp );
}

//Steady state values for state variables in y_ss (y steady state) file
void Set_y_vec_ss(N_Vector y, int sy0, char* stateFileName){
	FILE *fp = fopen( stateFileName, "w");
	double tmp;
	for ( int idy = 0; idy < sy0; idy++ ) { //Scan in variables from text file
		tmp = Ith(y, idy+1);
		fprintf ( fp, "%lf\t", tmp );
	}
	fclose( fp );
}

//Timer class for accurate simulation computation times
class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const { 
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

	int NEQ = 73; //Number of ODEs

	double* p = mxGetPr(prhs[0]);

	double pcl =                 (double) p[0]; //Pacing Cycle Length
	bool   AP_Clamp_Simulation = (bool)   p[1]; //AP Clamp Switch (0 = No AP clamp, 1 = AP clamp)
	int    nbeats =              (double) p[2]; //Number of total beats to simulate
	double dt =                  (double) p[3]; //Time step
	double output_dt =           (double) p[4]; //Output time step for reduced file sizes (output_dt > dt)
	bool   output_last_two =     (bool)   p[5]; //Output only last two beats to reduce file size (0 = output all, 1 = output last two)
	bool   hegyi_ion_data =      (bool)   p[6]; //True = Hegyi Data, False = Original Shannon 2004 concentrations
	int    cell_type =           (int)    p[7]; //0 = Control, 1 = Remote-HF, 2 = Border-HF
	int    s2_pcl =              (int)    p[8]; //S1S2 pacing parameter, dictates S2 pacing cycle length (0 = no S1S2 pacing)

	int n_const = 9; //Number of total constant parameters above

	std::string cell_name;

	//Used to output different files during parallel Matlab processing
	int thread_ID = (int)*mxGetPr(prhs[1]);
	if(thread_ID >= 0){
		std::cout << "Process ID Name: " << thread_ID << std::endl;
	}

	//EAD tests
	double* EAD_VALUES = (double* )mxGetData(prhs[2]);
	double EAD_ICA, EAD_IKR, EAD_IKS;
	
	
	


	

	//Cell used for data storage and the actual simulation
	Cell cell(dt, NEQ, p);

	
	switch(cell_type){
		case 1:
			// std::cout << "CONTROL: " << cell_type << std::endl;
			cell_name = "control";
			break;
		case 2:
			// std::cout << "REMOTE: " << cell_type << std::endl;
			cell_name = "remote";
			break;
		case 3:
			// std::cout << "BORDER: " << cell_type << std::endl;
			cell_name = "border";
			break;

	}
	std::cout << "CELL TYPE: " << cell_name << std::endl;
	// char stateFileName[] = "./inputs/y.txt";
	char stateFileName[] = "./inputs/y_ss.txt";
	
	
	// CVODE Solver
		N_Vector y0n;
		cvode_solver cvode(NEQ,1);
		realtype tout;
		tout = dt;
		
		y0n = N_VNew_Serial(NEQ); // for solver		
		Initialize_y_vec(y0n, NEQ, stateFileName);
		cvode.set_IC(y0n);
		cvode.initialise_mem(soltis_biophysJ2010_eccODEfile);	
		cvode.set_user_data(&cell);	
		
	//

	//Simulation Variables

	//APD Measuring
	bool append_mode = false;
	bool file_out = true;
	char buffer_apd [50];
	char buffer_results [50];
	ofstream outfile;
	

	if(thread_ID >= 0){ //Used for sensitivity analysis 
		int n1 = sprintf (buffer_apd,     "./outputs/APDs   /%s_APD_    %.0f_%d.txt", cell_name.c_str(), pcl, thread_ID); //n is a placeholder. Write the string to buffer
		int n2 = sprintf (buffer_results, "./outputs/results/%s_results_%.0f_%d.txt", cell_name.c_str(), pcl, thread_ID); //n is a placeholder. Write the string to buffer
	}
	else if(s2_pcl > 0){
		int n1 = sprintf (buffer_apd,     "./outputs/APDs   /%s_APD_    %.0f_s2_%d.txt", cell_name.c_str(), pcl, s2_pcl); //n is a placeholder. Write the string to buffer
		int n2 = sprintf (buffer_results, "./outputs/S1S2/%s_results_%.0f_s2_%d.txt", cell_name.c_str(), pcl, s2_pcl); //n is a placeholder. Write the string to buffer
	}
	else if(EAD_VALUES[0] != -1){ //EAD test
		std::cout << "----EAD SIMULATION----" << std::endl;
		if(EAD_VALUES[0] != -1 ){
			EAD_ICA = EAD_VALUES[0];
			EAD_IKR = EAD_VALUES[1];
			EAD_IKS = EAD_VALUES[2];
			std::cout << "EAD_ICA: " << EAD_ICA << " EAD_IKR: " << EAD_IKR << " EAD_IKS: " << EAD_IKS << std::endl;
		}
		int n1 = sprintf (buffer_apd, "./outputs/APDs/%s_APD_%.0f.txt", cell_name.c_str(), pcl); //n is a placeholder. Write the string to buffer
		int n2 = sprintf(buffer_results,  "./outputs/EAD/%s_results_%.0f_%04.2f_%04.2f_%04.2f_.txt", cell_name.c_str(), pcl, EAD_ICA, EAD_IKR, EAD_IKS);
		
		//NOTE: In order to get the relative scale, the conductance of each current involved in EADs is divided by the "original" optimized conductance at 1 Hz
		//If an optimization protocol is repeated, these values must be changed
		// switch(cell_type){
		// case 1:
		// 	n2 = sprintf(buffer_results,  "./outputs/EAD/%s_results_%.0f_%04.2f_%04.2f_%04.2f_.txt", cell_name.c_str(), pcl, p[n_const-1+1]/1.17182814104286, p[n_const-1+5]/1.34601288054242, p[n_const-1+6]/1.36651622380483);
		// 	break;
		// case 2:
		// 	n2 = sprintf(buffer_results,  "./outputs/EAD/%s_results_%.0f_%04.2f_%04.2f_%04.2f_.txt", cell_name.c_str(), pcl, p[n_const-1+1]/0.80, p[n_const-1+5]/1.19, p[n_const-1+6]/2.20);
		// 	break;
		// case 3:
		// 	n2 = sprintf(buffer_results,  "./outputs/EAD/%s_results_%.0f_%04.2f_%04.2f_%04.2f_.txt", cell_name.c_str(), pcl, p[n_const-1+1]/0.87, p[n_const-1+5]/1.20, p[n_const-1+6]/2.00);
		// 	break;
		// }

	}
	else {
		int n1=sprintf (buffer_apd, "./outputs/APDs/%s_APD_%.0f.txt", cell_name.c_str(), pcl); //n is a placeholder. Write the string to buffer
		int n2 =sprintf (buffer_results, "./outputs/results/%s_results_%.0f.txt", cell_name.c_str(), pcl); //n is a placeholder. Write the string to buffer
	}
		 // "./outputs/results/control_results_5000_1.00_0.25_0.25_.txt"

    
	// APInfor AP("outputs/APD.txt", append_mode, file_out);
	APInfor AP(buffer_apd, append_mode, file_out);
	outfile.open(buffer_results);

	
	int iter_count = 0;
	int NOUT = (int)(nbeats*pcl);
	

	if(AP_Clamp_Simulation){
		cell.set_ap_clamp_data("./inputs/PIG_REPRESENTATIVE_AP_SMOOTHED.txt", 0.1);
	}

	printf("Starting pig simulation...\n");
	printf("PCL: %.1f NBEATS: %d DT: %.2f DT_OUT: %.2f LAST_TWO: %d HEGYI_DATA: %d\n", pcl, nbeats,dt, output_dt, output_last_two, hegyi_ion_data);
	
	if(AP_Clamp_Simulation){
		printf("--AP CLAMP SIMULATION--\n");
	}
	else if(s2_pcl > 0 ){
		printf("--S1:%.0f S2:%d --\n", pcl, s2_pcl);
	}
	else{
		printf("--CURRENT CLAMP SIMULATION--\n");
	}
	

	clock_t begin = clock();
	Timer tmr; 

	int beat_counter = 0;

	while(tout < NOUT) {


		AP.MeasurePigModel(tout, cell.I_stim, pcl, dt, cell.Vm,  cell.I_Na, cell.cai, cell.dVdt, cell.caSR); //Haibo's APD measurements

		cvode.solve_single_step(tout);
		
		
		if(iter_count % (int)(output_dt/dt) == 0){
			cell.stopwatch = tmr.elapsed();
			if(output_last_two && tout >= NOUT-(pcl*2)){ //Only output last two beats
				cell.print(outfile) ;
			}
			else if (output_last_two == false) {
				cell.print(outfile); //Output time and other state variables
			}
		}
		iter_count++;
		tout += dt;
	}
	outfile.close();

	clock_t end = clock();

	double elapsed = double(end - begin) / CLOCKS_PER_SEC;

	AP.ReportLastTwoPig();


	//Output state variable states at steady state
	// char stateFileName_ss[] = "./inputs/y_ss.txt";
	// Set_y_vec_ss(cvode.y, NEQ, stateFileName_ss);
	
	//Return file name created back to Matlab
	plhs[0] = mxCreateString(buffer_results);

	// std::cout << "\nCreated: \n" << buffer_apd << "\n" << buffer_results << "\n" << std::endl;
	// cout << setprecision(5) << "Computation Time: " << elapsed << " seconds" << endl;
	// printf("Done.\n");
}













