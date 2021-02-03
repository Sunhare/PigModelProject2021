#ifndef _PIG_ECC_BIOPHYS_
#define _PIG_ECC_BIOPHYS_

#include <cmath>
#include "pcell.h"
#include "stimulus.h"
#include "pig_ecc_biophysJ2021.h"

#include "cvode_solver.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stimulus.h>

#include <iomanip>

#define CONTROL   1
#define REMOTE_HF 2
#define BORDER_HF 3


class PIG_ECC
{
public:
	PIG_ECC(int cell_type) {

		for (int i = 0; i < ODE_NUM; ++i)
		{
			ydot[0] = 0.0;
		}
		for (int i = 0; i < 14; ++i) {
			para[i] = 1.0;
		}

		switch(cell_type){
			case CONTROL:
				SCALE_ICa 	  = 0.90;
				SCALE_INa 	  = 2.39;
				SCALE_INaL 	  = 0.99;
				SCALE_IK1 	  = 0.50;
				SCALE_IKr 	  = 1.37;
				SCALE_IKs 	  = 5.92;
				SCALE_Isk 	  = 1.15;
				SCALE_IClCa   = 0.78;
				SCALE_INCX 	  = 1.00;
				SCALE_INaK 	  = 1.20;
				SCALE_JSRrel  = 1.00;
				SCALE_JSERCA  = 0.00;
				SCALE_Ito 	  = 0.52;
				SCALE_koCa 	  = 5.00;
				break;
			case REMOTE_HF:
				SCALE_ICa 	  = 0.90;
				SCALE_INa 	  = 2.39;
				SCALE_INaL 	  = 0.99;
				SCALE_IK1 	  = 0.50;
				SCALE_IKr 	  = 1.37;
				SCALE_IKs 	  = 5.92;
				SCALE_Isk 	  = 1.15;
				SCALE_IClCa   = 0.78;
				SCALE_INCX 	  = 1.00;
				SCALE_INaK 	  = 1.20;
				SCALE_JSRrel  = 1.00;
				SCALE_JSERCA  = 0.00;
				SCALE_Ito 	  = 0.52;
				SCALE_koCa 	  = 5.00;
				break;
			case BORDER_HF:
				SCALE_ICa 	  = 0.90;
				SCALE_INa 	  = 2.39;
				SCALE_INaL 	  = 0.99;
				SCALE_IK1 	  = 0.50;
				SCALE_IKr 	  = 1.37;
				SCALE_IKs 	  = 5.92;
				SCALE_Isk 	  = 1.15;
				SCALE_IClCa   = 0.78;
				SCALE_INCX 	  = 1.00;
				SCALE_INaK 	  = 1.20;
				SCALE_JSRrel  = 1.00;
				SCALE_JSERCA  = 0.00;
				SCALE_Ito 	  = 0.52;
				SCALE_koCa 	  = 5.00;
				break;

		}

		// initialize_state_vars();
		read_initial_condition(filename);
	};
	~PIG_ECC() {

	};

	double V, dV;
	 
	double SCALE_ICa;
	double SCALE_INa;
	double SCALE_INaL;
	double SCALE_IK1;
	double SCALE_IKr;
	double SCALE_IKs;
	double SCALE_Isk;
	double SCALE_IClC;
	double SCALE_INCX;
	double SCALE_INaK;
	double SCALE_JSRr;
	double SCALE_JSER;
	double SCALE_Ito;
	double SCALE_koCa;

	// double I_Na_junc, I_Na_sl, I_Na;

	// double I_NaL_junc, I_NaL_sl, I_NaL;
	// double I_nabk_junc, I_nabk_sl, I_nabk;
	// double I_nak_junc, I_nak_sl, I_nak;
	// double I_to, I_tof;
	// double I_kr, I_kur;
	// double I_k2p;
	// double I_ks_sl, I_ks_junc, I_ks;
	// double I_ki_sl, I_ki_j, I_ki;
	// double I_kp;
	// double I_kach_j, I_kach_sl, I_kach;

	// double I_sk_junc, I_sk_sl, I_sk, /*I_ClCa_jun, I_ClCa_s,*/I_ClCa, I_Clbk, I_ClCFTR;
	// double I_Ca_junc, I_Ca_sl, I_Ca, I_CaK, I_CaNa_junc, I_CaNa_sl, I_CaNa, I_Catot;
	// double I_cabk_junc, I_cabk_sl, I_cabk;
	// double I_pca_junc, I_pca_sl, I_pca;
	// double I_ncx_junc, I_ncx_sl, I_ncx, J_SRCarel, J_serca, J_SRleak,  I_Na_tot_junc, J_CaB_junction, J_CaB_sl;
	// double J_CaB_cytosol,  I_Na_tot_sl;
	// double I_ClCa_junc, I_ClCa_sl, I_Cl_tot;
	// double I_app, I_Ca_tot, I_Ca_tot_junc, I_Ca_tot_sl, I_tot, I_Na_tot, I_K_tot;
	// double CaSR, Caj, Casl, Cai;
	// double Nai, Naj, Nasl;

	// double kmf_scale = 1.0;

	double PCL = 1000.0;

	bool allow_stimulation_flag = true;

	const int ODE_NUM = 73; //UPDATE To Soltis Saucerman ODE numbers

	double para[14];
	double y[73];
	double ydot[73];

	void print_to_file(double t, std::ofstream & output_file) ;
	void print_to_file_Vm_only(double t, std::ofstream & output_file) ;

	void pig_ecc_biophysJ2021(double t); //ODE function

	void output_inital_condition(const char* filename);

	void read_initial_condition(const char * filename);


};

void PIG_ECC::initialize_state_vars(const char * filename){
	read_initial_condition(filename);
	// const double mo = 1.405627e-3;
	// const double ho = 9.867005e-1;
	// const double jo = 9.915620e-1;
	// const double do1 = 7.175662e-6;
	// const double fo = 1.000681;
	// const double fcaBjo = 2.421991e-2;
	// const double fcaBslo = 1.452605e-2;
	// const double xtoso = 4.051574e-3;
	// const double ytoso = 9.945511e-1;
	// const double xtofo = 4.051574e-3;
	// const double ytofo = 9.945511e-1;
	// const double xkro = 8.641386e-3;
	// const double xkso = 5.412034e-3;
	// const double RyRro = 8.884332e-1;
	// const double RyRoo = 8.156628e-7;
	// const double RyRio = 1.024274e-7;
	// const double NaBjo = 3.539892;
	// const double NaBslo = 7.720854e-1;
	// const double TnCLo = 8.773191e-3;
	// const double TnCHco = 1.078283e-1;
	// const double TnCHmo = 1.524002e-2;
	// const double CaMo = 2.911916e-4;
	// const double Myoco = 1.298754e-3;
	// const double Myomo = 1.381982e-1;
	// const double SRBo = 2.143165e-3;
	// const double SLLjo = 9.566355e-3;
	// const double SLLslo = 1.110363e-1;
	// const double SLHjo = 7.347888e-3;
	// const double SLHslo = 7.297378e-2;
	// const double Csqnbo = 1.242988;
	// const double Ca_sro = 0.1e-1; // 5.545201e-1;
	// const double Najo = 9.136; // 8.80329;
	// const double Naslo = 9.136; // 8.80733;
	// const double Naio = 9.136; // 8.80853;
	// const double Kio = 120;
	// const double Cajo = 1.737475e-4;
	// const double Caslo = 1.031812e-4;
	// const double Caio = 8.597401e-5;
	// const double Vmo = -8.09763e+1;
	// const double rtoso = 0.9946;
	// const double ICajuncinto = 0;
	// const double ICaslinto = 1;
	// const double C1o = 0.0015;     //  []
	// const double C2o = 0.0244;     //  []
	// const double C3o = 0.1494;     //  []
	// const double C4o = 0.4071;     //  []
	// const double C5o = 0.4161;     //  []
	// const double C7o = 0.0001;     //  []
	// const double C8o = 0.0006;     //  []
	// const double C9o = 0.0008;     //  []
	// const double C10o = 0;         //  []
	// const double C11o = 0;         //  []
	// const double C12o = 0;         //  []
	// const double C13o = 0;         //  []
	// const double C14o = 0;         //  []
	// const double C15o = 0;         //  []
	// const double O1o = 0;          //  []
	// const double O2o = 0;          //  []
	// const double C6o = 1 - (C1o + C2o + C3o + C4o + C5o + C7o + C8o + C9o + C10o + C11o + C12o + C13o + C14o + C15o + O1o + O2o); //  []


	// initial conditions for IKur
	// const double rkuro = 0;
	// const double skuro = 1.0;

	// int sy0 = 62; // 57;
	//	double y0[] = { mo, ho, jo, do1, fo, fcaBjo, fcaBslo, xtoso, ytoso, xtofo, ytofo, xkro, xkso,
	//		RyRro, RyRoo, RyRio, NaBjo, NaBslo, TnCLo, TnCHco, TnCHmo, CaMo, Myoco, Myomo,
	//		SRBo, SLLjo, SLLslo, SLHjo, SLHslo, Csqnbo,
	//		Ca_sro, Najo, Naslo, Naio, Kio, Cajo, Caslo, Caio, Vmo, rtoso, 1,
	//		C1o, C2o, C3o, C4o, C5o, C6o, C7o, C8o, C9o, C10o, C11o, C12o, C13o, C14o, C15o, O1o };

	// double* y0 = new double[ODE_NUM];
	
	// double y0[] = { mo, ho, jo, do1, fo, fcaBjo, fcaBslo, xtoso, ytoso, xtofo,
	//                 ytofo, xkro, xkso, RyRro, RyRoo, RyRio, NaBjo, NaBslo, TnCLo, TnCHco,
	//                 TnCHmo, CaMo, Myoco, Myomo, SRBo, SLLjo, SLLslo, SLHjo, SLHslo, Csqnbo,
	//                 Ca_sro, Najo, Naslo, Naio, Kio, Cajo, Caslo, Caio, Vmo, rtoso,
	//                 1, C1o, C2o, C3o, C4o, C5o, C6o, C7o, C8o, C9o,
	//                 C10o, C11o, C12o, C13o, C14o, C15o, O1o, rkuro, skuro, 1,
	//                 0, 0
	//               };



	for (int i = 0; i < ODE_NUM; ++i)
	{
		y[i] = y0[i];
	}

	// y[40] = 0;
	// y[41] = 1;
}


void GB_ECC::read_initial_condition(const char* filename) {

	FILE *fp = fopen( stateFileName, "r");

	if (!fp) {
		std::cerr << filename << " not opened!!! " << std::endl;
		std::exit(0);
	}

	long int rw = fread(y, sizeof(double), ODE_NUM, fp);
	if (rw != ODE_NUM) {
		std::cerr << rw << " / " << ODE_NUM << " doubles read from " << filename << ", exiting..." << std::endl;
		// exit(EXIT_FAILURE);
		std::exit(0);
	}

	double tmp;
	for ( int idy = 0; idy < ODE_NUM; idy++ ) { //Scan in variables from text file

		fscanf ( fp, "%lf", &tmp );
		y[idy] = tmp;
		// Ith(y, idy+1) = tmp;

	}
	fclose( fp );

	// FILE *file;
	// // open the file
	// file = fopen(filename, "r");
	// if (!file) {
	// 	// perror(filename);

	// 	std::cerr << filename << " not opened!!! " << std::endl;
	// 	// print_error_info_file_open_failure(filename);
	// 	std::exit(0);
	// }
	// // fread(array, sizeof(double), num, in)
	// // output
	// long int rw = fread(y, sizeof(double), ODE_NUM, file);
	// if (rw != ODE_NUM) {
	// 	std::cerr << rw << " / " << ODE_NUM << " doubles read from " << filename << ", exiting..." << std::endl;
	// 	// exit(EXIT_FAILURE);
	// 	std::exit(0);
	// }
	// if (file)
	// 	fclose(file);
}


int fnew(realtype t, N_Vector y, N_Vector ydot, void *user_data) {

	PIG_ECC *Data = (PIG_ECC*) user_data;
	int NEQ_m = Data->ODE_NUM;

	for (int i = 0; i < NEQ_m; i++){
		Data->y[i] = Ith(y, i + 1);
	}

	Data->V  = Data->y[38];
	Data->pig_ecc_biophysJ2021(t);


	for (int i = 0; i < NEQ_m; i++){
		Ith(ydot, i + 1) = Data->ydot[i];
	}

	return 0;

}



int fnew_vm_as_para(realtype t, N_Vector y, N_Vector ydot, void *user_data) {

	PIG_ECC *Data = (PIG_ECC*) user_data;
	int NEQ_m = Data->ODE_NUM;

	for (int i = 0; i < NEQ_m; i++){
		Data->y[i] = Ith(y, i + 1);
	}

	Data->y[38] = Data->V;// Vm updated outside solver;
	Data->pig_ecc_biophysJ2021(t);
	Data->ydot[38] = 0;  // Vm updated outside solver;

	for (int i = 0; i < NEQ_m; i++){
		Ith(ydot, i + 1) = Data->ydot[i];
	}

	return 0;

}



// int pig_ecc_biophysJ2021(realtype t, N_Vector Y, N_Vector YDOT, void *user_data) {
void PIG_ECC::pig_ecc_biophysJ2021(double t){
	
	// PCell* pcell;
	// pcell = (PCell *)user_data;

	// const double* p = get_p();
	// const int NEQ = get_NEQ();


	//Cast data as correct type
	// double PCL = double(p[0]);
	// int nbeats = int(p[2]);
	// double dt = double(p[3]);
	// double output_dt = double(p[4]);
	// bool output_last_two = bool(p[5]);
	// bool hegyi_ion_data = bool(p[6]);
	// int pcell_type = int(p[7]);
	// double s2_pcl = double(p[8]);
	
	

	// realtype y[NEQ];
	// realtype ydot[NEQ];

	// for (int i = 0; i < NEQ; i++){
	// 	y[i] = Ith(Y, i + 1);
	// }

	//  This is the Shannon/Bers EC coupling model Biophys J. 2004, implemented
	//  by Jeff Saucerman with help from Eleonora Grandi and Fei Wang.
	//
	//  Author: Jeff Saucerman <jsaucerman@virginia.edu>
	//  Copyright 2008, University of Virginia, All Rights Reserved
	//
	//  Re-implemented by Anthony Soltis <ars7h@virginia.edu> to include
	//  regulation of Ca2+ fluxes and currents by CaMKII and PKA. Final version
	//  completed 07/21/10
	//
	//  References:
	//  -----------
	//  JJ Saucerman and DM Bers, Calmodulin mediates differential
	//  sensitivity of CaMKII and calcineurin to local Ca2+ in cardiac myocytes.
	//  Biophys J. 2008 Aug 8. [Epub ahead of print]

	// //  Assign passed-in parameters
	


	// int size_const_array = 9; //Number of constant parameters

	// SCALE_ICa 	= 	p[size_const_array +  0];
	// SCALE_INa 	= 	p[size_const_array +  1];
	// SCALE_INaL 	= 	p[size_const_array +  2];
	// SCALE_IK1 	= 	p[size_const_array +  3];
	// SCALE_IKr 	= 	p[size_const_array +  4];
	// SCALE_IKs 	= 	p[size_const_array +  5];
	// SCALE_Isk 	= 	p[size_const_array +  6];
	// SCALE_IClCa 	= 	p[size_const_array +  7];
	// SCALE_INCX 	= 	p[size_const_array +  8];
	// SCALE_INaK 	= 	p[size_const_array +  9];
	// SCALE_JSRrel 	= 	p[size_const_array + 10];
	// SCALE_JSERCA 	= 	p[size_const_array + 11];
	// SCALE_Ito 	= 	p[size_const_array + 12]; //Always set to 0 (removed from model, not present in pigs)
	// SCALE_koCa 	= 	p[size_const_array + 13];

	//These are constants in my model so they are no longer parameters
	//  CaMKII phosphorylated targets (// )
	double LCC_CKp     = 0.547677438908217;		//1: LCC_CKp 
	double RyR_CKp     = 0.195250274557101;		//2: RyR_CKp 
	double PLB_CKp     = 0.0120195262172836;	//3: PLB_CKp 

	//  PKA phosphorylated targets (// )
	double LCCa_PKAp   = 0.0277913210987449;	//4: LCCa_PKAp 
	double LCCb_PKAp   = 0.0327912283306637;	//5: LCCb_PKAp 
	double PLB_PKAn    = 0.992681233585950;		//6: PLB_PKAn //  This is % non-phosphorylated PLB targe]s;  //  This is % non-phosphorylated PLB targe]s
	double RyR_PKAp    = 0.0243941092361056;	//7: RyR_PKA;
	double TnI_PKAp    = 0.00312520780089506;	//8: TnI_PKAp;
	double IKs_PKAp    = 0.0733327839312986;	//9: IKs_PKAp ;
	double ICFTR_PKAp  = 0.162146087312334;		//10: ICFTR_PKAp;

	//  Flag for CKII OE (tells code whether or not it should use Ito and INa changes) - is either 0 (WT) or 1 (OE)
	double CKIIOE      = 0; 
	double rest 	   = 1; 

	
	

	// Biophysical constants Constants
	double R = 8314.0;       //  [mJ/mol*K]
	double Frdy = 96485.0;   //  [C/mol]
	double Temp = 310.0;     //  [K] 310 K (37 C) for BT / 295 K (22 C) for RT
	double FoRT = Frdy / R / Temp;
	double Cmem = cmem;   //  [F] membrane capacitance
	double Qpow = (Temp - 310) / 10.0;

	//  PCell geometry
	double cellLength = 100;     //  pcell length [um]
	double cellRadius = 10.25;   //  pcell radius [um]
	double junctionLength = 160e-3;  //  junc length [um]
	double junctionRadius = 15e-3;   //  junc radius [um]
	double distSLcyto = 0.45;    //  dist. SL to cytosol [um]
	double distJuncSL = 0.5;  //  dist. junc to SL [um]
	double DcaJuncSL = 1.64e-6;  //  Dca junc to SL [cm^2/sec]
	double DcaSLcyto = 1.22e-6; //  Dca SL to cyto [cm^2/sec]
	double DnaJuncSL = 1.09e-5;  //  Dna junc to SL [cm^2/sec]
	double DnaSLcyto = 1.79e-5;  //  Dna SL to cyto [cm^2/sec]
	const double  pi = M_PI;
	double Vcell = pi * cellRadius * cellRadius * cellLength * 1e-15; //  [L]
	double Vmyo = 0.65 * Vcell; double Vsr = 0.035 * Vcell; double Vsl = 0.02 * Vcell; double Vjunc = 0.0539 * .01 * Vcell;
	double SAjunc = 20150 * pi * 2 * junctionLength * junctionRadius; //  [um^2]
	double SAsl = pi * 2 * cellRadius * cellLength;    //  [um^2]
	double J_ca_juncsl = 1.0 / 1.2134e12; //  [L/msec]
	double J_ca_slmyo = 1.0 / 2.68510e11; //  [L/msec]
	double J_na_juncsl = 1.0 / (1.6382e12 / 3.0 * 100); //  [L/msec]
	double J_na_slmyo = 1.0 / (1.8308e10 / 3.0 * 100); //  [L/msec]

	//  Fractional currents in compartments
	double Fjunc = 0.11;
	double Fsl = 1 - Fjunc;
	double Fjunc_CaL = 0.9;
	double Fsl_CaL = 1 - Fjunc_CaL;

	//  Fixed ion concentrations
	double Cli = cli;   //15  Intracellular Cl  [mM]
	double Clo = clo;//150;  //  Extracellular Cl  [mM]
	double Ko = ko;//5.4;   //  Extracellular K   [mM]
	double Nao = nao;//140;  //  Extracellular Na  [mM]
	double Cao = cao;//1.8;  //  Extracellular Ca  [mM] 
	double Mgi = mgi;    //  Intracellular Mg  [mM]

	//  Nernst Potentials
	double ena_junc = (1 / FoRT) * log(Nao / y[31]); //  [mV]
	double ena_sl   = (1 / FoRT) * log(Nao / y[32]); //  [mV]
	double ek       = (1 / FoRT) * log(Ko / y[34]);	 //  [mV]
	double eca_junc = (1 / FoRT / 2) * log(Cao / y[35]); //  [mV]
	double eca_sl   = (1 / FoRT / 2) * log(Cao / y[36]); //  [mV]
	double ecl      = (1 / FoRT) * log(Cli / Clo);      //  [mV]

	//  Na transport parameters
	double GNa = 16.0;        //  [mS/uF] //Moved
	double GNaB = 0.297e-3;    //  [mS/uF]
	double IbarNaK = 1.90719;     //  [uA/uF]
	double KmNaip = 11;         //  [mM]
	double KmKo = 1.5;         //  [mM]
	double Q10NaK = 1.63;
	double Q10KmNai = 1.39;

	//  K current parameters
	double pNaK = 0.01833;
	double GtoSlow = 0.06;     //  [mS/uF]
	double GtoFast = 0.02;     //  [mS/uF]
	double gkp = 0.001;

	//  Cl current parameters
	double GClCa = 0.109625;   //  [mS/uF]
	double GClB = 9e-3;        //  [mS/uF]
	// double KdClCa = 100e-3;    //  [mM]
	

	//  I_Ca parameters
	double pNa = 1.5e-8;       //  [cm/sec]
	double pCa = 5.4e-4;       //  [cm/sec]
	double pK = 2.7e-7;        //  [cm/sec]

	pNa *= SCALE_ICa; //Scaling Factor ICaL Na permeability
	pCa *= SCALE_ICa; //Scaling Factor ICaL Ca permeability
	pK  *= SCALE_ICa; //Scaling Factor ICaL K  permeability

	double KmCa = 0.6e-3;      //  [mM]
	double Q10CaL = 1.8;

	//  Ca transport parameters
	double IbarNCX = 9.0;      //  [uA/uF]
	double KmCai = 3.59e-3;    //  [mM]
	double KmCao = 1.3;        //  [mM]
	double KmNai = 12.29;      //  [mM]
	double KmNao = 87.5;       //  [mM]
	double ksat = 0.27;        //  [none]
	double nu = 0.35;          //  [none]
	double Kdact = 0.256e-3;   //  [mM]
	double Q10NCX = 1.57;      //  [none]
	double IbarSLCaP = 0.0673; //  [uA/uF]
	double KmPCa = 0.5e-3;     //  [mM]
	double GCaB = 2.513e-4;    //  [uA/uF]
	double Q10SLCaP = 2.35;    //  [none]

	//  SR flux parameters
	double Q10SRCaP = 2.6;          //  [none]
	double Vmax_SRCaP = 2.86e-4;  //  [mM/msec] (mmol/L cytosol/msec)
	double Kmf = 0.246e-3;          //  [mM]
	double Kmr = 1.7;               //  [mM]L cytosol
	double hillSRCaP = 1.787;       //  [mM]
	double ks = 25;                 //  [1/ms]
	double koCa = 10;               //  [mM^-2 1/ms]
	koCa *= SCALE_koCa;       //  [mM^-2 1/ms]
	// double koCa = 50;               //  [mM^-2 1/ms]

	double kom = 0.06;              //  [1/ms]
	double kiCa = 0.5;              //  [1/mM/ms]
	double kim = 0.005;             //  [1/ms]
	// double ec50SR = 0.45;           //  [mM]
	double ec50SR = 0.45;           //  [mM]

	//  Buffering parameters
	double Bmax_Naj = 7.561;       //  [mM]
	double Bmax_Nasl = 1.65;       //  [mM]
	double koff_na = 1e-3;         //  [1/ms]
	double kon_na = 0.1e-3;        //  [1/mM/ms]
	double Bmax_TnClow = 70e-3;    //  [mM]                      //  TnC low affinity
	double koff_tncl = 19.6e-3;    //  [1/ms]
	double kon_tncl = 32.7;        //  [1/mM/ms]
	double Bmax_TnChigh = 140e-3;  //  [mM]                      //  TnC high affinity
	double koff_tnchca = 0.032e-3; //  [1/ms]
	double kon_tnchca = 2.37;      //  [1/mM/ms]
	double koff_tnchmg = 3.33e-3;  //  [1/ms]
	double kon_tnchmg = 3e-3;      //  [1/mM/ms]
	double Bmax_myosin = 140e-3;   //  [mM]                      //  Myosin buffering
	double koff_myoca = 0.46e-3;   //  [1/ms]
	double kon_myoca = 13.8;       //  [1/mM/ms]
	double koff_myomg = 0.057e-3;  //  [1/ms]
	double kon_myomg = 0.0157;     //  [1/mM/ms]
	double Bmax_SR = 19 * .9e-3;   //  [mM]
	double koff_sr = 60e-3;        //  [1/ms]
	double kon_sr = 100;           //  [1/mM/ms]
	double Bmax_SLlowsl = 37.38e-3 * Vmyo / Vsl;    //  [mM]    //  SL buffering
	double Bmax_SLlowj = 4.62e-3 * Vmyo / Vjunc * 0.1; //  [mM]
	double koff_sll = 1300e-3;     //  [1/ms]
	double kon_sll = 100;          //  [1/mM/ms]
	double Bmax_SLhighsl = 13.35e-3 * Vmyo / Vsl;   //  [mM]
	double Bmax_SLhighj = 1.65e-3 * Vmyo / Vjunc * 0.1; //  [mM]
	double koff_slh = 30e-3;       //  [1/ms]
	double kon_slh = 100;          //  [1/mM/ms]
	double Bmax_Csqn = 2.7;        // 140e-3*Vmyo/Vsr; [mM]
	double koff_csqn = 65;         //  [1/ms]
	double kon_csqn = 100;         //  [1/mM/ms]

	double Bmax_CaM=24e-3;
	double kon_cam=34e-3;
	double koff_cam=238e-3;


	//  PKA-dependent phosphoregulation of TnI (increases Kd of TnC)
	double fracTnIpo = .0031;  //  Derived quantity (TnI_PKAp(baseline)/TnItot)
	double fPKA_TnI = (1.45 - 0.45 * (1 - TnI_PKAp) / (1 - fracTnIpo));
	koff_tncl = koff_tncl * fPKA_TnI;
	
	//  Set CKIIflag to 1 for CKII OE, 0 otherwise
	int CKIIflag =  0;//CKIIOE;
	//  Set ICa_MarkovFlag to 1 for Markov ICa, 0 otherwise
	int ICa_MarkovFlag = 1;
	//  Set MarkovFlag to 1 for Markov INa, 0 otherwise
	int MarkovFlag = 0;
	//  Set Ito to use either original params (=0) or Grandi Params (=1)
	int ItoFlag = 1;
	double inashift , alphaCKII , deltGbarNal_CKII ;
	// //  I_Na: Fast Na Currenst
	//  Max INa alterations with CKII hyperactivity as in Hund & Rudy 2008
	if (CKIIflag == 1) {
		inashift = -3.25;
		alphaCKII = -.18;
		deltGbarNal_CKII = 2;
	} else {
		inashift = 0;
		alphaCKII = 0;
		deltGbarNal_CKII = 0;
	}

	double am = 0.32 * (y[38] + 47.13) / (1 - exp(-0.1 * (y[38] + 47.13)));
	double bm = 0.08 * exp(-y[38] / 11);
	double ah, aj, bh, bj;
	if ((y[38] - inashift) >= -40) {
		ah = 0; aj = 0;
		bh = 1 / (0.13 * (1 + exp(-((y[38] - inashift) + 10.66) / 11.1)));
		bj = 0.3 * exp(-2.535e-7 * (y[38] - inashift)) / (1 + exp(-0.1 * ((y[38] - inashift) + 32)));
	}
	else {
		ah = 0.135 * exp((80 + (y[38] - inashift)) / -6.8);
		bh = 3.56 * exp(0.079 * (y[38] - inashift)) + 3.1e5 * exp(0.35 * (y[38] - inashift));
		//  Including alteration to aj as in Hund and Rudy 2008
		aj = (1 + alphaCKII) * ((-1.2714e5 * exp(0.2444 * (y[38] - inashift)) - 3.474e-5 * exp(-0.04391 * (y[38] - inashift)))
		                        * ((y[38] - inashift) + 37.78)
		                        / (1 + exp(0.311 * ((y[38] - inashift) + 79.23))));
		bj = 0.1212 * exp(-0.01052 * (y[38] - inashift)) / (1 + exp(-0.1378 * ((y[38] - inashift) + 40.14)));
	}

	ydot[0] = am * (1 - y[0]) - bm * y[0];
	ydot[1] = ah * (1 - y[1]) - bh * y[1];
	ydot[2] = aj * (1 - y[2]) - bj * y[2];

	double I_Na_junc = Fjunc * GNa *  y[0]*y[0]*y[0] * y[1] * y[2] * (y[38] - ena_junc);
	double I_Na_sl = Fsl * GNa * y[0]*y[0]*y[0] * y[1] * y[2] * (y[38] - ena_sl);

	I_Na_junc *= SCALE_INa; //Scaling Factor INa (fast) Junctional
	I_Na_sl *= SCALE_INa; //Scaling Factor INa (fast) Sub Sarcolemmal

	double I_Na = I_Na_junc + I_Na_sl;
	double I_Na_fast = I_Na;

	// //  I_Na,L: Late INa current (as in Hund & Rudy 2008)
	double GbarNal = .0065 * (1 + deltGbarNal_CKII) * 2; //  deltGbar assigned in 'Fast INa' section

	//  h-gate (note - m gate is same as INa m gate - using y(1) for this)
	double hlss = 1.0 / (1 + exp((y[38] + 91) / 6.1));
	double tauhl = 600;    //  600 ms originally
	ydot[46] = (hlss - y[46]) / tauhl;
	double I_Nalj = Fjunc * GbarNal * y[0] * y[0] * y[0] * y[46] * (y[38] - ena_junc);
	double I_Nalsl = Fsl * GbarNal * y[0] * y[0] * y[0] * y[46] * (y[38] - ena_sl);
	
	I_Nalj *= SCALE_INaL; //Scaling Factor INaL Junctional
	I_Nalsl *= SCALE_INaL; //Scaling Factor INaL Sub Sarcolemmal
	
	double I_Nal = I_Nalj + I_Nalsl;


	//  Reassign total junctional and sl currents as sum of fast and late
	//  currents
	I_Na_junc = I_Na_junc + I_Nalj;
	I_Na_sl = I_Na_sl + I_Nalsl;
	

	I_Na = I_Na_junc + I_Na_sl; //total

	// //  I_nabk: Na Background Current
	double I_nabk_junc = Fjunc * GNaB * (y[38] - ena_junc);
	double I_nabk_sl = Fsl * GNaB * (y[38] - ena_sl);
	double I_nabk = I_nabk_junc + I_nabk_sl;

	// //  I_nak: Na/K Pump Current
	double sigma = (exp(Nao / 67.3) - 1) / 7.;
	double fnak = 1. / (1 + 0.1245 * exp(-0.1 * y[38] * FoRT) + 0.0365 * sigma * exp(-y[38] * FoRT));
	double I_nak_junc = Fjunc * IbarNaK * fnak * Ko / (1 + pow( ( KmNaip / y[31] ), 4 )) / (Ko + KmKo);
	double I_nak_sl = Fsl * IbarNaK * fnak * Ko / (1 + pow( ( KmNaip / y[32] ), 4 )) / (Ko + KmKo);

	I_nak_junc *= SCALE_INaK; //Scaling Factor I_NaK Junctional
	I_nak_sl *= SCALE_INaK; //Scaling Factor I_NaK Sub Sarcolemmal

	double I_nak = I_nak_junc + I_nak_sl;

	// //  I_kr: Rapidly Activating K Current
	double gkr = 0.03 * sqrt(Ko / 5.4); 
	double xrss = 1 / (1 + exp(-(y[38] + 50) / 7.5));
	double tauxr = 1 / (1.38e-3 * (y[38] + 7) / (1 - exp(-0.123 * (y[38] + 7))) + 6.1e-4 * (y[38] + 10) / (exp(0.145 * (y[38] + 10)) - 1));
	ydot[11] = (xrss - y[11]) / tauxr;
	double rkr = 1 / (1 + exp((y[38] + 33) / 22.4));
	double I_kr = gkr * y[11] * rkr * (y[38] - ek);
	I_kr *= SCALE_IKr; //Scaling Factor I_Kr;

	// //  I_ks: Slowly Activating K Current
	//  Phosphoregulation of IKs by PKA parameters
	double fracIKspo = .0720;  //  Derived quantity (IKs_PKAp(baseline)/IKstot)
	double fracIKsavail = (0.2 * (IKs_PKAp / fracIKspo) + 0.8);
	double Xs05 = 1.5 * (2.0 - IKs_PKAp / fracIKspo);

	double pcaks_junc = -log10(y[35]) + 3.0;
	double pcaks_sl = -log10(y[36]) + 3.0;
	double gks_junc = fracIKsavail * 0.07 * (0.057 + 0.19 / (1 + exp((-7.2 + pcaks_junc) / 0.6))); //  Now regulated by PKA
	double gks_sl = fracIKsavail * 0.07 * (0.057 + 0.19 / (1 + exp((-7.2 + pcaks_sl) / 0.6))); //  Now regulated by PKA
	double eks = (1 / FoRT) * log((Ko + pNaK * Nao) / (y[34] + pNaK * y[33]));
	double xsss = 1 / (1 + exp(-(y[38] - Xs05) / 16.7)); //  Now regulated by PKA
	double tauxs = 1 / (7.19e-5 * (y[38] + 30) / (1 - exp(-0.148 * (y[38] + 30))) + 1.31e-4 * (y[38] + 30) / (exp(0.0687 * (y[38] + 30)) - 1));
	ydot[12] = (xsss - y[12]) / tauxs;
	double I_ks_junc = Fjunc * gks_junc * y[12] * y[12] * (y[38] - eks);
	double I_ks_sl = Fsl * gks_sl * y[12] * y[12] * (y[38] - eks);

	I_ks_junc *= SCALE_IKs; //Scaling Factor I_ks Junctional
	I_ks_sl *= SCALE_IKs; //Scaling Factor I_ks Sub Sarcolemmal

	double I_ks = I_ks_junc + I_ks_sl;

	// // I_sk: Small Conductance Calcium Sensitive Potassium Channel from Kennedy et al 2017

	double c_j = y[35]; //Junctional Concentration. Units of mM
	double c_sl = y[36]; //Sarcolemmal Concentration. Units of mM. 

	double EC50 = 0.7/1000; //controls affinity of Ca2+ . Converted to mM. Can play around with this value
	double N_sk = 2.2; //Cooperativity factor 
	double Gsk = 0.8/1000; //Conversion from uS/uF (in Kennedy 2017) to mS/uF (in the Shannon model)

	double tausk_sl = (1.0)/((0.047*c_sl)+(1.0/76.0)); //Time constant
	double tausk_j = (1.0)/((0.047*c_j)+(1.0/76.0)); //Time constant

	double xskinf_sl = 0.81 * ((pow(c_sl, N_sk))/(pow(c_sl, N_sk)+pow(EC50, N_sk)));
	double xskinf_j = 0.81 * ((pow(c_j, N_sk))/(pow(c_j, N_sk)+pow(EC50, N_sk)));

	ydot[71] = (xskinf_sl - y[71])/tausk_sl;
	ydot[72] = (xskinf_j - y[72])/tausk_j;

	double I_sk_sl = Fsl* Gsk * y[71] * (y[38]-ek);
	double I_sk_junc = Fjunc * Gsk * y[72] * (y[38]-ek);

	I_sk_junc *= SCALE_Isk; //Scaling Factor I_sk Junctional
	I_sk_sl *= SCALE_Isk; //Scaling Factor I_sk Sub Sarcolemmal

	double I_sk = I_sk_junc + I_sk_sl;


	// //  I_kp: Plateau K current
	double kp_kp = 1 / (1 + exp(7.488 - y[38] / 5.98));
	double I_kp_junc = Fjunc * gkp * kp_kp * (y[38] - ek);
	double I_kp_sl = Fsl * gkp * kp_kp * (y[38] - ek);
	double I_kp = I_kp_junc + I_kp_sl;

	//// I_to: Transient Outward K Current (slow and fast components)
	
	// Set all Ito related parameters to 0 (NOT PRESENT IN PIGS)
	ydot[7] = 0;
	ydot[8] = 0;
	ydot[39] = 0;
	ydot[9] = 0;
	ydot[10] = 0;

	double xtoss = 1. / ( 1 + exp( -( y[38] + 3.0 ) / 15 ) );
	double ytoss = 1. / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) );
	double rtoss = 1. / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) );
	double tauxtos = 9. / ( 1 + exp( ( y[38] + 3.0 ) / 15 ) ) + 0.5;

	double tauytos, taurtos, Py, Pr1, Pr2; //, GtoSlow;
	if ( ItoFlag == 0 ) {
		// Shannon Versions
		tauytos = 3.0e3 / ( 1 + exp( ( y[38] + 60.0 ) / 10 ) ) + 30;
		taurtos = 2.8e3 / ( 1 + exp( ( y[38] + 60.0 ) / 10 ) ) + 220;
	} else if ( ItoFlag == 1 && CKIIflag == 0 ) {
		// Grandi Versions
		Py = 182.;
		Pr1 = 8085.;
		Pr2 = 313.;                // Normal
		tauytos = Py / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) ) + 1;
		taurtos = Pr1 / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) ) + Pr2;
	} else if ( ItoFlag == 1 && CKIIflag == 1 ) {
		Py = 15.;
		Pr1 = 3600.;
		Pr2 = 500.;
		GtoSlow = GtoSlow * 1.5;  // CKII OE
		tauytos = Py / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) ) + 1;
		taurtos = Pr1 / ( 1 + exp( ( y[38] + 33.5 ) / 10 ) ) + Pr2;
		// end
	}

	//Ito removed from model
	// ydot[7] = ( xtoss - y[7] ) / tauxtos;
	// ydot[8] = ( ytoss - y[8] ) / tauytos;
	// ydot[39] = ( rtoss - y[39] ) / taurtos;

	// double I_tos = GtoSlow * y[7] * ( y[8] + 0.5 * y[39] ) * ( y[38] - ek );    // [uA/uF]

	//  tauxtof = 3.5*exp(-y[38]*y[38]/30/30)+1.5;    //  Original
	// double tauxtof = 3.5 * exp( -( ( y[38] + 3 ) / 30 ) * ( ( y[38] + 3 ) / 30 ) ) + 1.5;       // Version in Grandi Code (does not change AP shape)
	// double tauytof = 20.0 / ( 1. + exp( ( y[38] + 33.5 ) / 10. ) ) + 20.0;
	// ydot[9] = ( xtoss - y[9] ) / tauxtof; 
	// ydot[10] = ( ytoss - y[10] ) / tauytof;
	// double I_tof = GtoFast * y[9] * y[10] * ( y[38] - ek );

	
	// I_tof *= SCALE_Ito; //Scaling Factor I_tof
	// I_tos *= SCALE_Ito; //Scaling Factor I_tos

	// double I_to = I_tos + I_tof;

	double I_tof = 0;
	double I_tos = 0;
	double I_to = 0;


	//  I_ki = I_k1: Time-Independent K Current
	double aki = 1.02 / (1 + exp(0.2385 * (y[38] - ek - 59.215)));
	double bki = (0.49124 * exp(0.08032 * (y[38] + 5.476 - ek)) + exp(0.06175 * (y[38] - ek - 594.31))) / (1 + exp(-0.5143 * (y[38] - ek + 4.753)));
	
	double kiss = aki / (aki + bki);
	double I_ki = 0.9 * sqrt(Ko / 5.4) * kiss * (y[38] - ek);


	I_ki *= SCALE_IK1; //Scaling Factor I_k1

	// //  I_ClCa: Ca-activated Cl Current, I_Clbk: background Cl Current

	double KdClCa = 10e-3;    //  [mM] Ca2+ sensitivity


	double I_ClCa_junc = Fjunc * GClCa / (1 + KdClCa / y[35]) * (y[38] - ecl);
	double I_ClCa_sl = Fsl * GClCa / (1 + KdClCa / y[36]) * (y[38] - ecl);


	double I_ClCa = I_ClCa_junc + I_ClCa_sl;
	I_ClCa *= SCALE_IClCa; //Scaling Factor I_Clca

	double I_Clbk = GClB * (y[38] - ecl);

	// //  Original H-H formulation for LCC - unused if ICa_MarkovFlag = 1
	// double dss = 1 / (1 + exp(-(y[38] + 14.5) / 6.0));
	// double taud = dss * (1 - exp(-(y[38] + 14.5) / 6.0)) / (0.035 * (y[38] + 14.5));
	// double fss = 1 / (1 + exp((y[38] + 35.06) / 3.6)) + 0.6 / (1 + exp((50 - y[38]) / 20));
	
	// double tauf = 1 / (0.0197 * exp( -(0.0337 * (y[38] + 14.5)) * (0.0337 * (y[38] + 14.5)) ) + 0.02);
	
	//  ydot(4) = (dss-y(4))/taud;
	//  ydot(5) = (fss-y(5))/(tauf);
	//  ydot(6) = (1.7)*y(36)*(1-y(6))-11.9e-3*y(6); //  fCa_junc
	//  ydot(7) = 1.7*y(37)*(1-y(7))-11.9e-3*y(7); //  fCa_sl
	ydot[3] = 0;
	ydot[4] = 0;
	ydot[5] = 0;
	ydot[6] = 0;
	

	// double ibarca_j = pCa * 4 * (y[38] * Frdy * FoRT) * (0.341 * y[35] * exp(2 * y[38] * FoRT) - 0.341 * Cao) / (exp(2 * y[38] * FoRT) - 1);
	// double ibarca_sl = pCa * 4 * (y[38] * Frdy * FoRT) * (0.341 * y[36] * exp(2 * y[38] * FoRT) - 0.341 * Cao) / (exp(2 * y[38] * FoRT) - 1);
	double ibark = pK * (y[38] * Frdy * FoRT) * (0.75 * y[34] * exp(y[38] * FoRT) - 0.75 * Ko) / (exp(y[38] * FoRT) - 1);
	double ibarna_j = pNa * (y[38] * Frdy * FoRT) * (0.75 * y[31] * exp(y[38] * FoRT) - 0.75 * Nao)  / (exp(y[38] * FoRT) - 1);
	double ibarna_sl = pNa * (y[38] * Frdy * FoRT) * (0.75 * y[32] * exp(y[38] * FoRT) - 0.75 * Nao)  / (exp(y[38] * FoRT) - 1);

	double I_Ca_junc1   = 0.0;// (Fjunc_CaL * ibarca_j * y(4) * y(5) * (1 - y(6)) * pow(Q10CaL, Qpow)) * 0.45;
	double I_Ca_sl1     = 0.0;// (Fsl_CaL * ibarca_sl * y(4) * y(5) * (1 - y(7)) * pow(Q10CaL, Qpow)) * 0.45;
	double I_CaK1       = 0.0;// (ibark * y(4) * y(5) * (Fjunc_CaL * (1 - y(6)) + Fsl_CaL * (1 - y(7))) * pow(Q10CaL, Qpow)) * 0.45;
	double I_CaNa_junc1 = 0.0;// (Fjunc_CaL * ibarna_j * y(4) * y(5) * (1 - y(6)) * pow(Q10CaL, Qpow)) * 0.45;
	double I_CaNa_sl1   = 0.0;// (Fsl_CaL * ibarna_sl * y(4) * y(5) * (1 - y(7)) * pow(Q10CaL, Qpow)) * .45;
	
	// //  LCC MARKOV MODEL - based on Mahajan et al. (2008) // //
		//  This portion contains Markov state transitions for four channel types:
		//  'mode 1' channels in the junction and sl and 'mode 2' channels in the
		//  same two compartments. Markov state transitions are computed for each
		//  channel type independently - total currents are the sum of the two
		//  channel types in each compartment (i.e. ICatot_junc = ICa_mode1_junc +
		//  ICa_mode2_junc). Ca-dependent transition rates differ between juncitonal
		//  and sl channels, whereas closing rate (r2) is adjusted to define mode1
		//  vs. mode2 channels. Parameters determined through microscopic
		//  reversibility are redefined to preserve constraint.

		//  CaMKII shifts distribution of junctional and subsarcolemmal channels to
		//  either mode 2 at the expense of mode 1 channels (i.e. 10//  mode 2 results
		//  in 90//  mode 1).

		//  PKA alters overall availability of channels (favail term that changes
		//  overall scaling factor for currents) and also shifts distribution of
		//  mode1/2 channels. PKA actions act on both junctional and sarcolemmal
		//  channels.

		//  To allow for CDI KO
		double cajLCC = y[35];
		double caslLCC = y[36];

		//  LCC Current Fixed Parameters
		// /*double*/ pCa = 5.4e-4;       //  [cm/sec] - Ca permeability
		double taupo = 1;          //  [ms] - Time constant of activation
		double TBa = 450;          //  [ms] - Time constant
		double s1o = .0221;
		double k1o = .03;
		double kop = 2.5e-3;       //  [mM]
		double cpbar = 8e-3;       //  [mM]
		double tca = 78.0312;
		double ICa_scale = 5.25;
		double recoveryReduc = 3;

		// // //  PKA PHOSPHOREGULATION OF LCC AVAILABLILITY (beta subunit phosph) // // // // // //
		double fracLCCbpo = .0328; //  Derived quantity - (LCCbp(baseline)/LCCbtot)
		double favail = 1 * (.017 * LCCb_PKAp / fracLCCbpo + 0.983); //  Test (max x1.5 pCa)
		/*double*/ ICa_scale =  ICa_scale * favail;

		//  Voltage- and Ca-dependent Parameters
		double poss = 1 / (1 + exp(-y[38] / 8));
		double fcaj = 1 / (1 + (kop / cajLCC) * (kop / cajLCC) * (kop / cajLCC));
		double Rv = 10 + 4954 * exp(y[38] / 15.6);
		double PrLCC = 1 - 1 / (1 + exp(-(y[38] + 40) / 4));
		double PsLCC = 1 / (1 + exp(-(y[38] + 40) / 11.32));
		double TCaj = (tca + 0.1 * (1 + (cajLCC / cpbar) * (cajLCC / cpbar))) / (1 + (cajLCC / cpbar) * (cajLCC / cpbar));
		double tauCaj = (Rv - TCaj) * PrLCC + TCaj;
		double tauBa = (Rv - TBa) * PrLCC + TBa;

		//  Tranisition Rates (20 rates)
		double alphaLCC = poss / taupo;
		double betaLCC = (1 - poss) / taupo;
		double r1 = 0.3;                               //  [1/ms] - Opening rate
		double r2 = 3;                                 //  [1/ms] - closing rate
		double s1 = s1o * fcaj;
		double s1p = .00195;                           //  [ms] - Inactivation rate
		double k1 = k1o * fcaj;
		double k1p = .00413;                           //  [ms] - Inactivation rate
		double k2 = 1e-4;                              //  [ms] - Inactivation rate
		double k2p = .00224;                           //  [ms] - Inactivation rate
		double s2 = s1 * (k2 / k1) * (r1 / r2);
		double s2p = s1p * (k2p / k1p) * (r1 / r2);
		double k3 = exp(-(y[38] + 40) / 3) / (3 * (1 + exp(-(y[38] + 40) / 3)));
		double k3p = k3;
		double k5 = (1 - PsLCC) / tauCaj;
		double k6 = (fcaj * PsLCC) / tauCaj;
		double k5p = (1 - PsLCC) / tauBa;

		//  Recovery terms
		k5 = k5 / recoveryReduc;
		k5p = k5p / recoveryReduc;

		double	k6p = PsLCC / tauBa;
		double k4 = k3 * (alphaLCC / betaLCC) * (k1 / k2) * (k5 / k6);
		double k4p = k3p * (alphaLCC / betaLCC) * (k1p / k2p) * (k5p / k6p);

		// global gates
		// gates(1, tStep) = s1;
		// gates(2, tStep) = k1;

		//  State transitions for MODE 1 junctional LCCs // // //
		//  O = no differential; C2 = 60; C1 = 61; I1Ca = 62; I2Ca = 63;
		//  I1Ba = 64; I2Ba = 65;
		double Po_LCCj_m1 = 1.0 - y[47] - y[48] - y[49] - y[50] - y[51] - y[52];                   //  O_m1j
		ydot[47] = betaLCC * y[48] + k5 * y[50] + k5p * y[52] - (k6 + k6p + alphaLCC) * y[47]; //  C2_m1j
		ydot[48] = alphaLCC * y[47] + k2 * y[49] + k2p * y[51] + r2 * Po_LCCj_m1 - (r1 + betaLCC + k1 + k1p) * y[48]; //  C1_m1j
		ydot[49] = k1 * y[48] + k4 * y[50] + s1 * Po_LCCj_m1 - (k2 + k3 + s2) * y[49];          //  I1Ca_m1j
		ydot[50] = k3 * y[49] + k6 * y[47] - (k4 + k5) * y[50];                                 //  I2Ca_m1j
		ydot[51] = k1p * y[48] + k4p * y[52] + s1p * Po_LCCj_m1 - (k2p + k3p + s2p) * y[51];    //  I1Ba_m1j
		ydot[52] = k3p * y[51] + k6p * y[47] - (k5p + k4p) * y[52];                             //  I2Ba_m1j
		double ibarca_jm1 = (4 * pCa * y[38] * Frdy * FoRT) * (.001 * exp(2 * y[38] * FoRT) - 0.341 * Cao) / (exp(2 * y[38] * FoRT) - 1);
		double I_Ca_junc_m1 = (Fjunc_CaL * ibarca_jm1 * Po_LCCj_m1 * pow(Q10CaL, Qpow)) * ICa_scale;

		// // //  Re-define all parameters as mode 2 specific parameters // // //
		double s1om2 = .0221;
		double k1om2 = .03;
		double kopm2 = 2.5e-3;
		double cpbarm2 = 8e-3;
		double tcam2 = 78.0312;

		double possm2 = 1 / (1 + exp(-y[38] / 8));
		double fcajm2 = 1 / (1 + pow(kopm2 / cajLCC, 3)); //  Depends on junctional Ca
		double Rvm2 = 10 + 4954 * exp(y[38] / 15.6);
		double PrLCCm2 = 1 - 1 / (1 + exp(-(y[38] + 40) / 4)); //  Correct version I believe
		double PsLCCm2 = 1 / (1 + exp(-(y[38] + 40) / 11.32));
		double TCajm2 = (tcam2 + 0.1 * (1 + pow(cajLCC / cpbarm2, 2) )) / (1 + pow(cajLCC / cpbarm2, 2)); //  Caj dependent
		double tauCajm2 = (Rvm2 - TCajm2) * PrLCCm2 + TCajm2; //  Caj dependence
		double tauBam2 = (Rvm2 - TBa) * PrLCCm2 + TBa;

		double alphaLCCm2 = possm2 / taupo;
		double betaLCCm2 = (1 - possm2) / taupo;
		double r1m2 = 0.3;                               //  [1/ms] - Opening rate
		double r2m2 = 3. / 10.;                               //  [1/ms] - closing rate
		double s1m2 = s1om2 * fcajm2;
		double s1pm2 = .00195;                           //  [ms] - Inactivation rate
		double k1m2 = k1om2 * fcajm2;
		double k1pm2 = .00413;                           //  [ms] - Inactivation rate
		double k2m2 = 1e-4;                              //  [ms] - Inactivation rate
		double k2pm2 = .00224;                           //  [ms] - Inactivation rate
		double s2m2 = s1m2 * (k2m2 / k1m2) * (r1m2 / r2m2);
		double s2pm2 = s1pm2 * (k2pm2 / k1pm2) * (r1m2 / r2m2);
		double k3m2 = exp(-(y[38] + 40) / 3) / (3 * (1 + exp(-(y[38] + 40) / 3.)));
		double k3pm2 = k3m2;
		double k5m2 = (1 - PsLCCm2) / tauCajm2;
		double k6m2 = (fcajm2 * PsLCCm2) / tauCajm2;
		double k5pm2 = (1 - PsLCCm2) / tauBam2;
		/*double*/ k5m2 = k5m2 / recoveryReduc;    //  reduced for recovery
		/*double*/ k5pm2 = k5pm2 / recoveryReduc;  //  reduced for recovery
		double k6pm2 = PsLCCm2 / tauBam2;
		double k4m2 = k3m2 * (alphaLCCm2 / betaLCCm2) * (k1m2 / k2m2) * (k5m2 / k6m2);
		double k4pm2 = k3pm2 * (alphaLCCm2 / betaLCCm2) * (k1pm2 / k2pm2) * (k5pm2 / k6pm2);

		// // //  State transitions for MODE 2 junctional LCCs // // //
		//  O = no differential; C2 = 66; C1 = 67; I1Ca = 68; I2Ca = 69;
		//  I1Ba = 70; I2Ba = 71;
		
		double Po_LCCj_m2 = 1.0 - y[53] - y[54] - y[55] - y[56] - y[57] - y[58];                                               // O_m2j
		ydot[53] = betaLCCm2 * y[54] + k5m2 * y[56] + k5pm2 * y[58] - ( k6m2 + k6pm2 + alphaLCCm2 ) * y[53];                          // C2_m2j
		ydot[54] = alphaLCCm2 * y[53] + k2m2 * y[55] + k2pm2 * y[57] + r2m2 * Po_LCCj_m2 - (r1m2 + betaLCCm2 + k1m2 + k1pm2) * y[54]; // C1_m2j
		ydot[55] = k1m2 * y[54] + k4m2 * y[56] + s1m2 * Po_LCCj_m2 - (k2m2 + k3m2 + s2m2) * y[55];                      // I1Ca_m2j
		ydot[56] = k3m2 * y[55] + k6m2 * y[53] - (k4m2 + k5m2) * y[56];                                                 // I2Ca_m2j
		ydot[57] = k1pm2 * y[54] + k4pm2 * y[58] + s1pm2 * Po_LCCj_m2 - (k2pm2 + k3pm2 + s2pm2) * y[57];                // I1Ba_m2j
		ydot[58] = k3pm2 * y[57] + k6pm2 * y[53] - (k5pm2 + k4pm2) * y[58];                                             // I2Ba_m2j
		double ibarca_jm2 = ( 4. * pCa * y[38] * Frdy * FoRT ) * ( .001 * exp( 2. * y[38] * FoRT ) - 0.341 * Cao ) / ( exp( 2. * y[38] * FoRT ) - 1 );

		double I_Ca_junc_m2 = (Fjunc_CaL * ibarca_jm2 * (Po_LCCj_m2) * pow(Q10CaL, Qpow)) * ICa_scale;

		// // //  CaMKII AND PKA-DEPENDENT SHIFTING OF DYADIC LCCS TO MODE 2 // // // //
		double fpkam2 = 0.1543 * LCCa_PKAp - .0043; //  Assumes max phosphorylation results in 15//  mode 2 channels
		double fckiim2 = LCC_CKp * .1;             //  Assumes max phosphorylation results in 10//  mode 2 channels
		//  Sum up total fraction of CKII and PKA-shifted mode 2 channels
		double junc_mode2 = fckiim2 + fpkam2;
		//  Total junctional ICa
		double I_Ca_junc2 = (1 - junc_mode2) * I_Ca_junc_m1 + junc_mode2 * I_Ca_junc_m2;

		// // //  SUB-SARCOLEMMAL LCCs // // //

		//  Re-assign necessary params to be Casl sensitive
		double fcasl = 1 / (1 + pow(kop / caslLCC, 3)); //  Depends on sl Ca
		double TCasl = (tca + 0.1 * pow(1 + (caslLCC / cpbar), 2)) / (1 + (caslLCC / cpbar) * (caslLCC / cpbar));
		double tauCasl = (Rv - TCasl) * PrLCC + TCasl;

		//  Re-assign necessary rates to be Casl sensitive
		double s1sl = s1o * fcasl;
		double k1sl = k1o * fcasl;
		double s2sl = s1sl * (k2 / k1sl) * (r1 / r2);
		double s2psl = s1p * (k2p / k1p) * (r1 / r2);
		double k5sl = (1 - PsLCC) / tauCasl;
		/*double*/ k5sl = k5sl / recoveryReduc; //  Reduced for recovery
		double k6sl = (fcasl * PsLCC) / tauCasl;
		double k4sl = k3 * (alphaLCC / betaLCC) * (k1sl / k2) * (k5sl / k6sl);
		double k4psl = k3p * (alphaLCC / betaLCC) * (k1p / k2p) * (k5p / k6p);

		//  State transitions for 'mode 1' sarcolemmal LCCs
		//  O = no differential; C2 = 72; C1 = 73; I1Ca = 74; I2Ca = 75;
		//  I1Ba = 76; I2Ba = 77;

		double Po_LCCsl_m1 = 1. - y[59] - y[60] - y[61] - y[62] - y[63] - y[64];                                                // O_m1sl
		ydot[59] = betaLCC * y[60] + k5sl * y[62] + k5p * y[64] - (k6sl + k6p + alphaLCC) * y[59];          // C2_m1sl
		ydot[60] = alphaLCC * y[59] + k2 * y[61] + k2p * y[63] + r2 * Po_LCCsl_m1 - (r1 + betaLCC + k1sl + k1p) * y[60]; // C1_m1sl
		ydot[61] = k1sl * y[60] + k4sl * y[62] + s1sl * Po_LCCsl_m1 - (k2 + k3 + s2sl) * y[61];             // I1Ca_m1sl
		ydot[62] = k3 * y[61] + k6sl * y[59] - (k4sl + k5sl) * y[62];                                       // I2Ca_m1sl
		ydot[63] = k1p * y[60] + k4psl * y[64] + s1p * Po_LCCsl_m1 - (k2p + k3p + s2psl) * y[63];           // I1Ba_m1sl
		ydot[64] = k3p * y[63] + k6p * y[59] - (k5p + k4psl) * y[64];
		//  I2Ba_m1sl
		double ibarca_slm1 = (4 * pCa * y[38] * Frdy * FoRT) * (.001 * exp(2 * y[38] * FoRT) - 0.341 * Cao) / (exp(2 * y[38] * FoRT) - 1);
		double I_Casl_m1 = (Fsl_CaL * ibarca_slm1 * Po_LCCsl_m1 * pow(Q10CaL, Qpow)) * ICa_scale;

		//  Adjust closing rate for 'mode 2' sarcolemmal LCCs
		double r2slm2 = r2m2;
		double s2slm2 = s1sl * (k2 / k1sl) * (r1 / r2slm2);
		double s2pslm2 = s1p * (k2p / k1p) * (r1 / r2slm2);

		// // //  State transitions for mode 2 sarcolemmal LCCs
		//  O = no differential; C2 = 78; C1 = 79; I1Ca = 80; I2Ca = 81; I1Ba = 82; I2Ba = 83

		double Po_LCCsl_m2 = 1. - y[65] - y[66] - y[67] - y[68] - y[69] - y[70];                                      // O_m2sl
		ydot[65] = betaLCC * y[66] + k5sl * y[68] + k5p * y[70] - (k6sl + k6p + alphaLCC) * y[65];          // C2_m2sl
		ydot[66] = alphaLCC * y[65] + k2 * y[67] + k2p * y[69] + r2slm2 * Po_LCCsl_m2 - (r1 + betaLCC + k1sl + k1p) * y[66]; // C1_m2sl
		ydot[67] = k1sl * y[66] + k4sl * y[68] + s1sl * Po_LCCsl_m2 - (k2 + k3 + s2slm2) * y[67];           // I1Ca_m2sl
		ydot[68] = k3 * y[67] + k6sl * y[65] - (k4sl + k5sl) * y[68];                                       // I2Ca_m2sl
		ydot[69] = k1p * y[66] + k4psl * y[70] + s1p * Po_LCCsl_m2 - (k2p + k3p + s2pslm2) * y[69];         // I1Ba_m2sl
		ydot[70] = k3p * y[69] + k6p * y[65] - (k5p + k4psl) * y[70];
		//  I2Ba_m2sl
		double ibarca_slm2 = (4 * pCa * y[38] * Frdy * FoRT) * (.001 * exp(2 * y[38] * FoRT) - 0.341 * Cao) / (exp(2 * y[38] * FoRT) - 1);
		double I_Casl_m2 = (Fsl_CaL * ibarca_slm2 * Po_LCCsl_m2 * pow(Q10CaL, Qpow)) * ICa_scale;

		//  Sum mode 1 and mode 2 sl channels for total sl current
		double fckiim2_sl = 0; //  Set to zero since SL LCCp by CaMKII is negligible
		double sl_mode2 = fckiim2_sl + fpkam2;
		double I_Ca_sl2 = (1 - sl_mode2) * I_Casl_m1 + sl_mode2 * I_Casl_m2;

		//  Na and K currents through LCC
		double I_CaKj2 = ibark * Fjunc_CaL * ((1 - junc_mode2) * Po_LCCj_m1 + junc_mode2 * Po_LCCj_m2) * pow(Q10CaL, Qpow) * ICa_scale;
		double I_CaKsl2 = ibark * Fsl_CaL * ((1 - sl_mode2) * Po_LCCsl_m1 + sl_mode2 * Po_LCCsl_m2) * pow(Q10CaL, Qpow) * ICa_scale;
		double I_CaK2 = I_CaKj2 + I_CaKsl2;
		double I_CaNa_junc2 = (Fjunc_CaL * ibarna_j * ((1 - junc_mode2) * Po_LCCj_m1 + junc_mode2 * Po_LCCj_m2) * pow(Q10CaL, Qpow)) * ICa_scale;
		double I_CaNa_sl2 = Fsl_CaL * ibarna_sl * ((1 - sl_mode2) * Po_LCCsl_m1 + sl_mode2 * Po_LCCsl_m2) * pow(Q10CaL, Qpow) * ICa_scale;

		//  These are now able to switch depending on whether or not the flag to
		//  switch to Markov model of ICa is ON
		double I_Ca_junc = (1 - ICa_MarkovFlag) * I_Ca_junc1 + ICa_MarkovFlag * I_Ca_junc2;
		double I_Ca_sl = (1 - ICa_MarkovFlag) * I_Ca_sl1 + ICa_MarkovFlag * I_Ca_sl2;
		double I_Ca = I_Ca_junc + I_Ca_sl; //  Total Ca current throuhgh LCC
		double I_CaNa_junc = (1 - ICa_MarkovFlag) * (I_CaNa_junc1) + (ICa_MarkovFlag) * (I_CaNa_junc2);
		double I_CaNa_sl = (1 - ICa_MarkovFlag) * (I_CaNa_sl1) + (ICa_MarkovFlag) * (I_CaNa_sl2);
		double I_CaNa = I_CaNa_junc + I_CaNa_sl;   //  Total Na current through LCC
		double I_CaK = (1 - ICa_MarkovFlag) * (I_CaK1) + ICa_MarkovFlag * (I_CaK2); //  Total K current through LCC

		//  Collect all currents through LCC
		double I_Catot = I_Ca + I_CaK + I_CaNa;
		ydot[42] = -I_Ca * Cmem / (Vmyo * 2 * Frdy) * 1e3;

	//  --- END LCC MARKOV MODEL --- //
	
	// //  I_ncx: Na/Ca Exchanger flux
	double Ka_junc = 1. / ( 1. + pow( ( Kdact / y[35] ) , 3 ) );
	double Ka_sl = 1. / ( 1. + pow( ( Kdact / y[36] ) , 3 ) );
	double s1_junc = exp( nu * y[38] * FoRT ) * pow( y[31] , 3 ) * Cao;
	double s1_sl = exp( nu * y[38] * FoRT ) * pow( y[32] , 3 ) * Cao;
	double s2_junc = exp( ( nu - 1 ) * y[38] * FoRT ) * pow( Nao , 3 ) * y[35];
	double s3_junc = ( KmCai * pow( Nao , 3 ) * ( 1. + pow( ( y[31] / KmNai ) , 3 ) ) + pow( KmNao , 3 ) * y[35] + pow( KmNai , 3 ) * Cao * ( 1. + y[35] / KmCai ) + KmCao * pow( y[31] , 3 ) + pow( y[31] , 3 ) * Cao + pow( Nao , 3 ) * y[35] ) * ( 1. + ksat * exp( ( nu - 1 ) * y[38] * FoRT ) );
	double s2_sl = exp( ( nu - 1 ) * y[38] * FoRT ) * pow( Nao , 3 ) * y[36];
	double s3_sl = ( KmCai * pow( Nao , 3 ) * ( 1. + pow( ( y[32] / KmNai ) , 3 ) ) + pow( KmNao , 3 ) * y[36] + pow( KmNai , 3 ) * Cao * ( 1. + y[36] / KmCai ) + KmCao * pow( y[32] , 3 ) + pow( y[32] , 3 ) * Cao + pow( Nao , 3 ) * y[36] ) * ( 1. + ksat * exp( ( nu - 1 ) * y[38] * FoRT ) );
	double I_ncx_junc = Fjunc * IbarNCX * pow( Q10NCX , Qpow ) * Ka_junc * ( s1_junc - s2_junc ) / s3_junc;
	double I_ncx_sl = Fsl * IbarNCX * pow( Q10NCX , Qpow ) * Ka_sl * ( s1_sl - s2_sl ) / s3_sl;
	I_ncx_junc *= SCALE_INCX; //Scaling Factor I_NCX Junctional
	I_ncx_sl *= SCALE_INCX; //Scaling Factor I_NCX Sarcolemmal

	double I_ncx = I_ncx_junc + I_ncx_sl;
	ydot[44] = 2. * I_ncx * Cmem / ( Vmyo * 2. * Frdy ) * 1e3;


	double I_pca_junc = Fjunc * pow( Q10SLCaP , Qpow ) * IbarSLCaP * pow( y[35] , 1.6 ) / ( pow( KmPCa , 1.6 ) + pow( y[35] , 1.6 ) );

	double I_pca_sl = Fsl * pow( Q10SLCaP , Qpow ) * IbarSLCaP * pow( y[36] , 1.6 ) / ( pow( KmPCa , 1.6 ) + pow( y[36] , 1.6 ) );
	double I_pca = I_pca_junc + I_pca_sl;
	ydot[43] = -I_pca * Cmem / ( Vmyo * 2 * Frdy ) * 1e3;

	//// I_cabk: Ca Background Current
	double I_cabk_junc = Fjunc * GCaB * ( y[38] - eca_junc );
	double I_cabk_sl = Fsl * GCaB * ( y[38] - eca_sl );
	double I_cabk = I_cabk_junc + I_cabk_sl;
	ydot[45] = -I_cabk * Cmem / ( Vmyo * 2 * Frdy ) * 1e3;

	//// I_CFTR or I_cl_(cAMP) - Cystic Fibrosis Transmembrane Conductance Reg.
	// This is an Em- and time-independent current that is activated by PKA
	double fact_pka_cftr = 1.1933 * ICFTR_PKAp - 0.1933;
	double gCFTR = fact_pka_cftr * 4.9e-3;     // [A/F]  - Max value as in Shannon et al. (2005)
	double I_cftr = gCFTR * ( y[38] - ecl );

	// //  RyR model - SR release fluxes and leak
	double MaxSR = 15; double MinSR = 1;

	double kCaSR = MaxSR - ( MaxSR - MinSR ) / ( 1. + pow( ( ec50SR / y[30] ) , 2.5 ) );

	double koSRCa = koCa / kCaSR; 
	

	double kiSRCa = kiCa * kCaSR;
	double kleak = 5.348e-6;

	// // //  CaMKII and PKA-dependent phosphoregulation of RyR Po // // //
	double fCKII_RyR = (20 * RyR_CKp / 3.0 - 1 / 3.0);
	double fPKA_RyR = RyR_PKAp * 1.025 + 0.9750;
	koSRCa = (fCKII_RyR + fPKA_RyR - 1) * koSRCa;

	// //  ODEs for RyR states and SR release through open RyRs
	double RI = 1. - y[13] - y[14] - y[15];
	ydot[13] = ( kim * RI - kiSRCa * y[35] * y[13] ) - ( koSRCa * y[35] * y[35] * y[13] - kom * y[14]);   //  R
	ydot[14] = ( koSRCa * y[35] * y[35] * y[13] - kom * y[14] ) - ( kiSRCa * y[35] * y[14] - kim * y[15] );//  O
	ydot[15] = ( kiSRCa * y[35] * y[14] - kim * y[15] ) - ( kom * y[15] - koSRCa * y[35] * y[35] * RI );   //  I


	double J_SRCarel = ks * ( y[14]  ) * ( y[30] - y[35] );          // [mmol/L SR/ ms]

	J_SRCarel *= SCALE_JSRrel;

	// Passive RyR leak - includes CaMKII regulation of leak flux
	kleak = ( 1. / 3. + 10. * RyR_CKp / 3. ) * kleak;
	double J_SRleak = kleak * ( y[30] - y[35] );              //   [mmol/L cyt/ ms]

	

	double fCKII_PLB = ( 1. - .5 * PLB_CKp );
	double fracPKA_PLBo = .9926;       // Derived quantity - ((PLBtot - PLBp(baseline))/PLBtot)
	double fPKA_PLB = ( PLB_PKAn / fracPKA_PLBo ) * 3. / 4. + 1. / 4.;

	// Select smaller value (resulting in max reduction of Kmf)
	if ( fCKII_PLB < fPKA_PLB ) {
		Kmf = Kmf * fCKII_PLB;
	} else if ( fPKA_PLB < fCKII_PLB ) {
		Kmf = Kmf * fPKA_PLB;
	}

	double J_serca = ( pow( Q10SRCaP , Qpow )
	                   * Vmax_SRCaP
	                   * ( pow( ( y[37] / Kmf ) , hillSRCaP )
	                       - pow( ( y[30] / Kmr ) , hillSRCaP ) )
	                   / ( 1. + pow( ( y[37] / Kmf ) , hillSRCaP ) + pow( ( y[30] / Kmr ) , hillSRCaP ) ) );

	J_serca *= SCALE_JSERCA;

	//// Sodium and Calcium Buffering
	ydot[16] = kon_na * y[31] * ( Bmax_Naj - y[16] ) - koff_na * y[16];        // NaBj      [mM/ms]
	ydot[17] = kon_na * y[32] * ( Bmax_Nasl - y[17] ) - koff_na * y[17];       // NaBsl     [mM/ms]

	// Cytosolic Ca and Mg Buffers
	ydot[18] = kon_tncl * y[37] * ( Bmax_TnClow - y[18] ) - koff_tncl * y[18];            // TnCL      [mM/ms]
	ydot[19] = kon_tnchca * y[37] * ( Bmax_TnChigh - y[19] - y[20] ) - koff_tnchca * y[19]; // TnCHc     [mM/ms]
	ydot[20] = kon_tnchmg * Mgi * ( Bmax_TnChigh - y[19] - y[20] ) - koff_tnchmg * y[20];   // TnCHm     [mM/ms]
	ydot[21] = kon_cam*y[37]*(Bmax_CaM-y[21])-koff_cam*y[21];                 // CaM       [mM/ms]
	ydot[22] = kon_myoca * y[37] * ( Bmax_myosin - y[22] - y[23] ) - koff_myoca * y[22];    // Myosin_ca [mM/ms]
	ydot[23] = kon_myomg * Mgi * ( Bmax_myosin - y[22] - y[23] ) - koff_myomg * y[23];      // Myosin_mg [mM/ms]
	ydot[24] = kon_sr * y[37] * ( Bmax_SR - y[24] ) - koff_sr * y[24];                    // SRB       [mM/ms]


	double J_CaB_cytosol = 0;
	for ( int it = 18; it < 25; it ++ ) {
		if(it == 20 || it == 23){ //Don't add Magnesium buffering

		}
		else{
			J_CaB_cytosol += ydot[it];	
		}
		

	}

	// Junctional and SL Ca Buffers
	ydot[25] = kon_sll * y[35] * (Bmax_SLlowj - y[25]) - koff_sll * y[25]; // SLLj      [mM/ms]
	ydot[26] = kon_sll * y[36] * (Bmax_SLlowsl - y[26]) - koff_sll * y[26]; // SLLsl     [mM/ms]
	ydot[27] = kon_slh * y[35] * (Bmax_SLhighj - y[27]) - koff_slh * y[27]; // SLHj      [mM/ms]
	ydot[28] = kon_slh * y[36] * (Bmax_SLhighsl - y[28]) - koff_slh * y[28]; // SLHsl     [mM/ms]
	double J_CaB_junction = ydot[25] + ydot[27];
	double J_CaB_sl = ydot[26] + ydot[28];
	

	//// Ion concentrations
	// SR Ca Concentrations
	ydot[29] = (kon_csqn * y[30] * (Bmax_Csqn - y[29]) - koff_csqn * y[29]); // Csqn      [mM/ms]

	ydot[30] = ( J_serca * Vmyo / Vsr - ( J_SRleak * Vmyo / Vsr + J_SRCarel ) - ydot[29] );         // Ca_sr     [mM/ms] //Ratio 3 leak current


	//  Sodium Concentrations
	double I_Na_tot_junc = I_Na_junc + I_nabk_junc + 3 * I_ncx_junc + 3 * I_nak_junc + I_CaNa_junc; //  [uA/uF]
	double I_Na_tot_sl = I_Na_sl + I_nabk_sl + 3 * I_ncx_sl + 3 * I_nak_sl + I_CaNa_sl; // [uA/uF]

	ydot[31] = -I_Na_tot_junc * Cmem / ( Vjunc * Frdy ) + J_na_juncsl / Vjunc * ( y[32] - y[31] ) - ydot[16];
	ydot[32] = -I_Na_tot_sl * Cmem / ( Vsl * Frdy ) + J_na_juncsl / Vsl * ( y[31] - y[32] )
	           + J_na_slmyo / Vsl * ( y[33] - y[32] ) - ydot[17];
	ydot[33] = J_na_slmyo / Vmyo * ( y[32] - y[33] );             // [mM/msec]



	// Potassium Concentration
	double I_K_tot = I_to + I_kr + I_ks + I_ki - 2. * I_nak + I_CaK + I_kp + I_sk;   // [uA/uF]
	ydot[34] = -I_K_tot*Cmem/(Vmyo*Frdy);           // [mM/msec]

	// Calcium Concentrations
	double I_Ca_tot_junc = I_Ca_junc + I_cabk_junc + I_pca_junc - 2. * I_ncx_junc;                   // [uA/uF]
	double I_Ca_tot_sl = I_Ca_sl + I_cabk_sl + I_pca_sl - 2. * I_ncx_sl;            // [uA/uF]
	ydot[35] = ( -I_Ca_tot_junc * Cmem / ( Vjunc * 2. * Frdy ) + J_ca_juncsl / Vjunc * ( y[36] - y[35] )
	             - J_CaB_junction + ( J_SRCarel ) * Vsr / Vjunc + J_SRleak * Vmyo / Vjunc ); // Ca_j
	ydot[36] = ( -I_Ca_tot_sl * Cmem / ( Vsl * 2. * Frdy ) + J_ca_juncsl / Vsl * ( y[35] - y[36] )
	             + J_ca_slmyo / Vsl * ( y[37] - y[36] ) - J_CaB_sl );   // Ca_sl
	ydot[37] = ( -J_serca - J_CaB_cytosol + J_ca_slmyo / Vmyo * ( y[36] - y[37] ) ); // Cai
	double junc_sl = J_ca_juncsl / Vsl * ( y[35] - y[36] );
	double sl_junc = J_ca_juncsl / Vjunc * ( y[36] - y[35] );
	double sl_myo = J_ca_slmyo / Vsl * ( y[37] - y[36] );
	double myo_sl = J_ca_slmyo / Vmyo * ( y[36] - y[37] );


	//// Membrane Potential
	double I_Na_tot = I_Na_tot_junc + I_Na_tot_sl;                 // [uA/uF]
	double I_Cl_tot = I_ClCa + I_Clbk + I_cftr;                         // [uA/uF]
	double I_Ca_tot = I_Ca_tot_junc + I_Ca_tot_sl;
	double I_tot = I_Na_tot + I_Cl_tot + I_Ca_tot + I_K_tot;

	//Ca related current output visualization ODEs (unused)
	ydot[40] = 0;
	ydot[41] = 0;
	ydot[42] = 0;
	ydot[43] = 0;
	ydot[44] = 0;
	ydot[45] = 0;



	double I_stim = is_stim*S1( 0, 22, PCL, t, 3);


	ydot[38] = -( I_tot ) + I_stim; //Voltage from current and stimulation
	dV = ydot[38]; //dV/dt

	//// PCell assignment for output
	V = y[38];//Voltage
	

	//Cytosolic ion concentrations
	// nai = y[33];
	// ki = y[34];
	// cai = y[37]; 

	// m = y[0];
	// h = y[1];
	// j = y[2];

	// //SR Parameters
	// caSR = y[30]; 
	// J_SRrel = J_SRCarel;
	// J_serca = J_serca;

	// //Na Currents
	// I_Na = I_Na_fast; //Fast component of I_Na
	// I_NaL = I_Nal; //Late sodium current

	// //K Currents
	// I_K1 = I_ki;
	// I_Kr = I_kr;
	// I_tof = I_tof;
	// I_tos = I_tos;

	// I_Ks = I_ks; 
	// I_sk = I_sk;// Calcium dependent potassium channel

	// I_kp = I_kp;

	// //Calcium Current
	// I_Ca = I_Ca; 
	
	// //Exchanger Currents
	// I_NaK = I_nak;
	// I_NCX = I_ncx;

	// //Chloride Currents
	// I_ClCa = I_ClCa; 

	// I_SLCaP = I_pca;
	// I_CaBK = I_cabk;
	// J_SRLeak = J_SRleak;
	// I_NaBK = I_nabk;
	// I_ClBK = I_Clbk;

	// caJ = y[35]; //Junctional Calcium
	// caSL = y[36]; //Sarcolemmal Calcium

	// RYR_RI = RI;
	// RYR_R = y[13];
	// RyR_O = y[14];
	// RyR_I = y[15];

	// for (int i = 0; i < NEQ; i++){
	// 	Ith(YDOT, i + 1) = ydot[i];
	// }
	// return 0;
}

#endif
