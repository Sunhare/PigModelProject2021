#ifndef _CELL_H_
#define _CELL_H_

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include "cvode_solver.hpp"
#include <ctime>

class Cell{
private: 
	const double* p; //parameter array
	const int NEQ; //number of state variables

	std::vector<double> ydot;
public:
	
	std::string cell_name; 
	
	double t, dt;  //Time (in miliseconds)
	double Vm, Vm_prev;
	double dVdt; //Membrane voltage

	double stopwatch; 


	double cai, nai, ki; //variable internal ion concentrations
	double nao, ko, clo, cli, cao, mgi; //constant concnetrations
	double cmem;
	double m,h,j;

	double caJ; //Junctional Calcium
	double caSL; //Sarcollemal Calcium
	
	double caSR; //SR Calcium concentration
	double J_SRrel; //Release flux of the SR
	double J_serca; //Uptake flux of the SR


	//Sodium channels
	double I_Na;
	double I_NaL;

	//Potassium channels
	double I_K1;
	double I_Kr;
	double I_tof;
	double I_tos;

	double I_Ks; //Small conductance potassium channel

	double I_sk; //Calcium dependent potassium channel

	double I_kp; //Plateau K channel



	//Calcium currents
	double I_Ca; //I_Catot

	//Exchanger currents
	double I_NaK;
	double I_NCX;
	

	//Chloride channels
	double I_ClCa; //Calcium dependent chloride channel
	
	//Stim current
	double I_stim;
	bool is_stim;

	//Diffusive current
	double I_diff;

	//Background currents
	double I_SLCaP; //Sarcolemmal Ca pump
	double I_CaBK; //Background Ca leak through sarcolemma
	double J_SRLeak; //SR calcium leak;
	double I_NaBK; //Sodium leak
	double I_ClBK; //Chloride leak

	char* cell_type; //Control, Remote, Border, etc;


	//(Scaling Parameters)
	double SCALE_ICa; //L-type Calcium Channel
	double SCALE_INa; //Fast sodium channel
	double SCALE_INaL; //Late sodium channel
	double SCALE_IK1; //Time Independent Rectifier Potassium Channel
	double SCALE_IKr; //Rapid rectifier Potassium Channel
	double SCALE_IKs; //Slow rectifier potassium channel
	double SCALE_Isk; //Calcium dependent potassium cannel
	double SCALE_IClCa; //Calcium dependent Chloride channel

	double SCALE_INCX; //Sodium calcium exchanger
	double SCALE_INaK; //Sodium Potassium ATPase

	double SCALE_JSRrel; //SR release flux
	double SCALE_JSERCA; //SR uptake flux
 
 	double SCALE_Ito; //Transient outward potassium channel (Ito=0 in  pigs)

 	double SCALE_koCa; //RyR Sensitivity to SR Calcium (forward rate constant for opening)

 	double RYR_RI;
	double RYR_R;
	double RyR_O;
	double RyR_I;

	





	
	void print(std::ofstream &outfile); //Output 
	void set_ap_clamp_data(std::string apc_file, double exp_dt);
	double* ap_clamp_data;


	Cell(double dt_in, int NEquations, double* params); //Constructor
	~Cell();
	Cell& operator=(const Cell& rhscell); //Assignment operator
	
	const double* get_p(void){return p;} //return whole parameter array
    double get_param(int index){return p[index];} //return index value of parameter array

    int get_NEQ(void){return NEQ;} //return number of state variables/ODEs

    std::vector<double> get_ydot(void){return ydot;}
    void set_ydot(std::vector<double> ydot){this->ydot=ydot;};
    void print_ydot(void);


	
};

#endif