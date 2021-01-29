#include <iostream>

#include "cell.h"

Cell::Cell(double dt_in, int NEquations, double* params): p{params}, NEQ{NEquations}, dt{dt_in}{
	
	//Check if using Hegyi ion data
	// mgi = 3.0;

	if(params[6]){ //If true, use Hegyi data

			//Constants (from Hegyi 2018)
			nao = 149;
			// ko = 4;
			ko = 5.4;
			clo = 132.4;
			cli = 30;
			// cao = 1.2; //Experimental
			cao = 1.8;
			mgi = 0.567; //Free Mg (total = 3 mM)
	}
	else{	
			//Original model values
			nao = 140;						  //  Extracellular Na  [mM]
			ko = 5.4; 						  //  Extracellular K   [mM]
			clo = 150;						  //  Extracellular Cl  [mM]
			cli = 15; 						  //  Intracellular Cl  [mM]
			cao = 1.8;						  //  Extracellular Ca  [mM] 
			mgi = 1.0;						  //  Intracellular Mg  [mM]
	}

	switch((int)p[7]){
		case 1:
			cell_name = "control";
			cmem = 1.3810e-10;
			break;
		case 2:
			cell_name = "remote";
			cmem = 1.722413793e-10;
			break;
		case 3:
			cell_name = "border";
			cmem = 1.709428571e-10;
			break;

	}

	//Scaling Factors
	SCALE_ICa = 	1;
	SCALE_INa = 	1;
	SCALE_INaL = 	1;
	SCALE_IK1 = 	1;
	SCALE_IKr = 	1;
	SCALE_IKs = 	1;
	SCALE_Isk = 	1;
	SCALE_IClCa = 	1;
	SCALE_INCX = 	1;
	SCALE_INaK = 	1;
	SCALE_JSRrel = 	1;
	SCALE_JSERCA = 	1;
	SCALE_Ito = 	1;
	SCALE_koCa = 	1;

	

	//State Variables
	t = 0;
	Vm = 0;
	dVdt = 0;

	cai = caSR = nai = ki = 0;
	J_SRrel = 0;
	J_serca = 0;

	m = 0;
	h = 0;
	j = 0;

	I_Na = 0;
	I_NaL = 0;

	I_K1 = 0;
	I_Kr = 0;
	I_tof = 0;
	I_tos = 0;
	I_Ks = 0;

	I_sk = 0; //I_K(Ca)

	I_Ca = 0;

	I_NaK = 0;
	I_NCX = 0;

	I_ClCa = 0;

	I_stim = 0;

	I_SLCaP = 0;
	I_CaBK = 0;
	J_SRLeak = 0;
	I_NaBK = 0;
	I_ClBK = 0;
	
	I_diff = 0;

	

	// ydot = new double [NEQ];

	stopwatch = 0; //Used to time simulations dynamically

	ap_clamp_data = new double[(int)(p[0]/dt_in)];

}

Cell& Cell::operator=(const Cell& rhscell){
	t = rhscell.t;
	Vm = rhscell.Vm;
	dVdt = rhscell.dVdt;

	cai = rhscell.cai;
	nai = rhscell.nai;
	ki = rhscell.ki;

	m = rhscell.m;
	h = rhscell.h;
	j = rhscell.j;

	caSR = rhscell.caSR;
	J_SRrel = rhscell.J_SRrel;
	J_serca = rhscell.J_serca;

	
	I_Na = rhscell.I_Na;
	I_NaL = rhscell.I_NaL;

	
	I_K1 = rhscell.I_K1;
	I_Kr = rhscell.I_Kr;
	I_tof = rhscell.I_tof;
	I_tos = rhscell.I_tos;
	I_Ks = rhscell.I_Ks;
	I_sk = rhscell.I_sk;
	
	I_Ca = rhscell.I_Ca;

	
	I_NaK = rhscell.I_NaK;
	I_NCX = rhscell.I_NCX;
	

	I_ClCa = rhscell.I_ClCa;
	
	I_stim = rhscell.I_stim;

	I_SLCaP = rhscell.I_SLCaP;
	I_CaBK = rhscell.I_CaBK;
	J_SRLeak = rhscell.J_SRLeak;
	I_NaBK = rhscell.I_NaBK;
	I_ClBK = rhscell.I_ClBK;


	SCALE_IClCa = rhscell.SCALE_IClCa;

	SCALE_IK1 = rhscell.SCALE_IK1;
	SCALE_IKr = rhscell.SCALE_IKr;
	SCALE_IKs = rhscell.SCALE_IKs;
	SCALE_Isk = rhscell.SCALE_Isk;
	
	SCALE_ICa = rhscell.SCALE_ICa;

	SCALE_INa = rhscell.SCALE_INa;
	SCALE_INaL = rhscell.SCALE_INaL;
	
	SCALE_INCX = rhscell.SCALE_INCX;
	SCALE_INaK = rhscell.SCALE_INaK;

	SCALE_Ito = rhscell.SCALE_Ito;
	
	SCALE_JSRrel = rhscell.SCALE_JSRrel;
	SCALE_JSERCA = rhscell.SCALE_JSERCA;


	return(*this);
}

Cell::~Cell() {
  // delete p;
  // delete ap_clamp_data;
}

void Cell::set_ap_clamp_data(std::string apc_file, double exp_dt){
	std::ifstream infile;
	double pcl = this->get_param(0);

	infile.open (apc_file);
	if(infile.good()){
		double t, v;
		t=v=0.0;

		int iter = 0;
		if(infile.is_open()){
			while(!infile.eof()){
				infile >> t >> v; 
				ap_clamp_data[iter] = v;
				iter++;
			}
		}
		//If data file runs out before diastolic interval is over, fill in with last data read in.
		while(iter < pcl/exp_dt){ 
			ap_clamp_data[iter] = v;
			iter++;
		}
	}
	else{
		std::cerr << "Error opening the AP Clamp file" << std::endl;
	}
	

	infile.close();

}
//Used for debugging/verifcation
void Cell::print_ydot(void){
	// std::ofstream ofile;
	// ofile.open(ofname);
	for(int i = 0; i < NEQ; i++){
		std::cout << ydot[i] << "\t";
	}
	std::cout << std::endl;
	// ofile.close();
}

void Cell::print(std::ofstream &outfile) { //
	

	outfile <<	std::setprecision(16) <<	//Matlab Plotting Number reference
		t 		<< "\t" << 	//t 	1
		Vm 		<< "\t" << //Vm 	2

		cai 	<< "\t" << //cai 	3
		nai 	<< "\t" << //nai 	4
		ki 		<< "\t" << //ki 	5

		caSR 	<< "\t" << //caSR: 	6
		J_SRrel	<< "\t" << //JSR_R	7
		J_serca	<< "\t" << //JSR_U	8

		I_Na	<< "\t" << //I_Na 	9
		I_NaL	<< "\t" << //I_NaL 	10
		I_Ca	<< "\t" << //I_Ca 	11

		I_K1 	<< "\t" << //I_K1	12
		I_Kr 	<< "\t" << //I_Kr	13
		I_tof	<< "\t" << //I_tof 	14
		I_tos	<< "\t" << //I_tos	15
		I_Ks	<< "\t" << //I_Ks	16
		I_sk 	<< "\t" << //I_sk 	17

		I_NaK	<< "\t" << //I_NaK	18
		I_NCX 	<< "\t" << //I_NCX 	19

		I_ClCa 	<< "\t" << //IClCa	20

		I_stim << "\t" << //I_stim 	21

		m 		<<"\t" << //m 		22
		h 		<<"\t" << //h		23
		j 		<<"\t" << //j 		24

		dVdt 	<<"\t" << //dvdt 	25

		stopwatch << "\t" << //time 26

		caJ 	<< "\t" << //CaJunc 27
		caSL 	<< "\t" << //CaSL   28

		I_SLCaP	<< "\t" << //SLCaP  29
		I_CaBK	<< "\t" << //SLCaBk 30 
		J_SRLeak<< "\t" << //SRLeak 31
		I_NaBK	<< "\t" << //I_NaBK 32
		I_ClBK	<< "\t" << //I_ClBK 33

		RYR_RI	<< "\t" << //RYR_RI 34
		RYR_R 	<< "\t" << //RYR_R  35
		RyR_O 	<< "\t" << //RyR_O  36
		RyR_I 	<< "\t" << //RyR_I  37








		std::endl;

}