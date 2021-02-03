#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <ctime>
#include <vector>

#include "soltis_biophysJ2010_eccODEfile.h"


#include "APInfo.hpp"
#include "cell.h"

using namespace std;

void Initialize_y_vec(N_Vector y, int sy0, char* stateFileName){
	FILE *fp = fopen( stateFileName, "r");
	double tmp;
	for ( int idy = 0; idy < sy0; idy++ ) { //Scan in variables from text file

		fscanf ( fp, "%lf", &tmp );
		Ith(y, idy+1) = tmp;

	}
	fclose( fp );
}

void Set_y_vec_ss(N_Vector y, int sy0, char* stateFileName){ 
	FILE *fp = fopen( stateFileName, "w");
	double tmp;
	for ( int idy = 0; idy < sy0; idy++ ) { //Scan in variables from text file
		tmp = Ith(y, idy+1);
		fprintf ( fp, "%lf\t", tmp );
	}
	fclose( fp );
}

//Timer class to measure speed
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


int main(){

	const int NEQ = 73; //Number of ODEs

	//Constant Simulation Parameters
	double pcl = 1000.0; //double, pacing frequency of heart cell (milliseconds)
	double AP_Clamp_Simulation = 0; //bool, 0 = No AP Clamp, 1 = AP Clamp
	double nbeats = 200; //int, total number of heart beats to simulate
	double dt = 0.1; //double, true time step
	double output_dt = 1.0; //double, reduces file size by outputting less time steps
	double output_last_two = 1; //bool, only output last two beats to reduce file size, 0 = false, 1 = true
	double hegyi_ion_data = 1; //bool, 0 = Original SS data, 1 = Hegyi Data
	double cell_type = 1; //int, 1 = Control, 2 = Remote-HF, 3 = Border
	double s2_pcl = 0; //double, control pacing of S2 beat (0 = no S1S2 pacing, > 0 = S1S2 pacing, milliseconds)

	//Ionic Current Scales
	double SCALE_ICa =  	1.0;
    double SCALE_INa =  	1.0;
    double SCALE_INaL =  	1.0;
    double SCALE_IK1 =  	1.0;
    double SCALE_IKr =  	1.0;
    double SCALE_IKs =  	1.0;
    double SCALE_Isk =  	1.0;
    double SCALE_IClCa =  	1.0;
    double SCALE_INCX =  	1.0;
    double SCALE_INaK =  	1.0;
    double SCALE_JSRrel =  	1.0;
    double SCALE_JSERCA =  	1.0;
    double SCALE_Ito =  	1.0;
    double SCALE_koCa =  	1.0;


	std::string cell_name;
	std::cout << "CELL TYPE: ";
    switch(int(cell_type)){
    	case 1: //Control
	    	std::cout << "CONTROL" << std::endl;
			cell_name = "control";
			SCALE_ICa = 	1.17;
			SCALE_INa = 	0.90;
			SCALE_INaL = 	2.39;
			SCALE_IK1 = 	0.50;
			SCALE_IKr = 	1.35;
			SCALE_IKs = 	1.37;
			SCALE_Isk = 	5.92;
			SCALE_IClCa = 	1.15;
			SCALE_INCX = 	0.78;
			SCALE_INaK = 	1.20;
			SCALE_JSRrel = 	1.00;
			SCALE_JSERCA = 	1.00;
			SCALE_Ito = 	0.00; //Always set to 0
			SCALE_koCa = 	5.00;
    		break;
    	case 2: //Remote-HF
	    	std::cout << "REMOTE" <<  std::endl;
			cell_name = "remote";
			SCALE_ICa = 	0.80;
			SCALE_INa = 	0.92;
			SCALE_INaL = 	4.00;
			SCALE_IK1 = 	0.55;
			SCALE_IKr = 	1.19;
			SCALE_IKs = 	2.20;
			SCALE_Isk = 	8.00;
			SCALE_IClCa = 	1.00;
			SCALE_INCX = 	1.55;
			SCALE_INaK = 	1.00;
			SCALE_JSRrel = 	1.00;
			SCALE_JSERCA = 	1.00;
			SCALE_Ito = 	0.00;  //Always set to 0
			SCALE_koCa = 	5.00;
    		break;
    	case 3: //Border-HF
    		std::cout << "BORDER" <<  std::endl;
			cell_name = "border";
    		SCALE_ICa = 	0.87;
			SCALE_INa = 	0.80;
			SCALE_INaL = 	2.00;
			SCALE_IK1 = 	0.50;
			SCALE_IKr = 	1.20;
			SCALE_IKs = 	2.00;
			SCALE_Isk = 	7.92;
			SCALE_IClCa = 	0.70;
			SCALE_INCX = 	0.58;
			SCALE_INaK = 	1.00;
			SCALE_JSRrel = 	1.00;
			SCALE_JSERCA = 	1.00;
			SCALE_Ito = 	0.00;  //Always set to 0
			SCALE_koCa = 	5.00;
    		break;
		default:
			std::cout << "Error: cell_type has unexpected value" << std::endl;
			return 0;
			break;

    }


	double p [9+14] = { //number of constants (above) + number of variables 
		//Constant terms
		pcl, 
		AP_Clamp_Simulation, 
		nbeats, dt, 
		output_dt, 
		output_last_two, 
		hegyi_ion_data, 
		cell_type, 
		s2_pcl,

		//Model Parameters (Ionic Current Conductances + RyR Sensitivity)
		SCALE_ICa,
		SCALE_INa,
		SCALE_INaL,
		SCALE_IK1,
		SCALE_IKr,
		SCALE_IKs,
		SCALE_Isk,
		SCALE_IClCa,
		SCALE_INCX,
		SCALE_INaK,
		SCALE_JSRrel,
		SCALE_JSERCA,
		SCALE_Ito,
		SCALE_koCa
	};
	

	//Cell used for data storage and the actual simulation
	Cell cell(dt, NEQ, p);

	

	//Read input ODE states from file
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

	//Simulation Variables

	//APD Measuring
	bool append_mode = false;
	bool file_out = true;
	char buffer_apd [50];
	char buffer_results [50];
	ofstream outfile;
	
	if(s2_pcl > 0){
		int n1=sprintf (buffer_apd, "outputs/APDs/%s_APD_%.0f_s2_%.0f.txt", cell_name.c_str(), pcl, s2_pcl); //n is a placeholder. Write the string to buffer
		int n2 =sprintf (buffer_results, "outputs/results/%s_results_%.0f_s2_%.0f.txt", cell_name.c_str(), pcl, s2_pcl); //n is a placeholder. Write the string to buffer
	}
	else {
		int n1=sprintf (buffer_apd, "outputs/APDs/%s_APD_%.0f.txt", cell_name.c_str(), pcl); //n is a placeholder. Write the string to buffer
		int n2 =sprintf (buffer_results, "outputs/results/%s_results_%.0f.txt", cell_name.c_str(), pcl); //n is a placeholder. Write the string to buffer
	}

    
	APInfor AP(buffer_apd, append_mode, file_out);
	outfile.open(buffer_results);

	
	int iter_count = 0;
	int NOUT = (int)(nbeats*pcl);
	

	if(AP_Clamp_Simulation){
		cell.set_ap_clamp_data("./inputs/APC_repr_v_in_smooth.txt", 0.1);
	}

	printf("Starting simulation of pig ventricular myocyte...\n");
	printf("PCL: %.1f NBEATS: %d DT: %.2f DT_OUT: %.2f LAST_TWO: %d HEGYI_DATA: %d\n", pcl, int(nbeats),dt, output_dt, int(output_last_two), int(hegyi_ion_data));
	
	if(AP_Clamp_Simulation){
		printf("--AP CLAMP SIMULATION--\n");
	}
	else{
		printf("--CURRENT CLAMP SIMULATION--\n");
	}
	if(s2_pcl > 0 ){
		printf("--S1:%.0f S2:%.0f --\n", pcl, s2_pcl);
	}

	clock_t begin = clock();
	Timer tmr; 

	int beat_counter = 0;


	bool test_bool = false;
	while(tout < NOUT) {

		AP.MeasurePigModel(tout, cell.I_stim, pcl, dt, cell.Vm,  cell.I_Na, cell.cai, cell.dVdt, cell.caSR); //Haibo's APD measurements
		cvode.solve_single_step(tout);
		
		
		if(iter_count % (int)(output_dt/dt) == 0){
			cell.stopwatch = tmr.elapsed();
			if(output_last_two && tout >= NOUT-(pcl*2)){ //Only output last beat
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

	std::cout << "\nCreated: \n" << buffer_apd << "\nand\n" << buffer_results << "\n" << std::endl;
	cout << setprecision(5) << "Computation Time: " << elapsed << " seconds" << endl;
	printf("Done.\n");
}













