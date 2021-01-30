#include "Grandi_2011_ODE.h"
#include <cmath>

void Grandi_2011_Simplified_ODE_Initialise(double *state, int celltype) {
	state[0] = 8.72509677797499e-5;
	state[1 ] = Y1;
	state[2 ] = Y2;

	state[3 ] = Y39;  // assigned to IKur a
	state[4 ] = Y4;
	state[5 ] = Y5;
	state[6 ] = 1.0;//Y40;   // assigned to IKur inac, haibo

	state[7 ] = Y7;
	state[8 ] = Y8;
	state[9 ] = Y9;
	state[10] = Y10;
	state[11] = Y11;
	state[12] = Y12;
	state[13] = Y13;
	state[14] = Y14;
	state[15] = Y15;
	state[16] = Y16;
	state[17] = Y17;
	state[18] = Y18;
	state[19] = Y19;
	state[20] = Y30;  // Nai -> 20, haibo
	state[21] = Y21;
	state[22] = Y31;   // Naj -> 22, haibo
	state[23] = Y32;   // Na_sl ->23, Haibo
	state[24] = Y33;   // CaSR ->24
	state[25] = Y35;    // Ry_Ri ->25
	state[26] = Y36;	// Ry_Ro -> 26 haibo
	state[27] = Y37;    // Ry_Rr -> 27 haibo
	state[28] = Y38;    // V -> 28, haibo
	state[29] = Y27;  // Ki  ->29
	state[30] = 0;
	state[31] = 0.8;


	// state[30] = Y30;
	// state[31] = Y31;
	// state[32] = Y32;
	// state[33] = Y33;
	// state[34] = Y34;
	// state[35] = Y35;
	// state[36] = Y36;
	// // state[37] = Y37;
	// state[38] = Y38;
	// state[39] = Y39;
	// state[40] = Y40;
// 41
}


void Grandi_2011_Simplified_ODE(double t, double *Y, double * dY, void *usr_data) {
	SingleCellPara *Data = (SingleCellPara*) usr_data;

	Data->V = Y[28];

	Grandi_2011_Simplified_ODE( t,  Y,   dY, Data);
	dY[28] = Data->dV;
}







void Grandi_2011_Simplified_ODE(double t, double *Y, double * dY, SingleCellPara *Data)
{



	// int i;

	// for (i = 0; i < NEQ; i++)
	//     Y[i] = Ith(y, i + 1);

	double I_Ca_tot_junc;   // uA_per_uF (in Ca_Concentrations)
	double I_Ca_tot_sl;   // uA_per_uF (in Ca_Concentrations)
	double J_CaB_cytosol;   // mM_per_msec (in Cytosolic_Ca_Buffers)
	double I_cabk;   // uA_per_uF (in I_CaBK)
	double I_cabk_junc;   // uA_per_uF (in I_CaBK)
	double I_cabk_sl;   // uA_per_uF (in I_CaBK)
	double I_Ca;   // uA_per_uF (in I_Ca)
	double I_CaK;   // uA_per_uF (in I_Ca)
	double I_CaNa;   // uA_per_uF (in I_Ca)
	double I_CaNa_junc;   // uA_per_uF (in I_Ca)
	double I_CaNa_sl;   // uA_per_uF (in I_Ca)
	double I_Ca_junc;   // uA_per_uF (in I_Ca)
	double I_Ca_sl;   // uA_per_uF (in I_Ca)
	double I_Catot;   // uA_per_uF (in I_Ca)
	double dss;   // dimensionless (in I_Ca)
	double fss;   // dimensionless (in I_Ca)
	double ibarca_j;   // uA_per_uF (in I_Ca)
	double ibarca_sl;   // uA_per_uF (in I_Ca)
	double ibark;   // uA_per_uF (in I_Ca)
	double ibarna_j;   // uA_per_uF (in I_Ca)
	double ibarna_sl;   // uA_per_uF (in I_Ca)
	double taud;   // msec (in I_Ca)
	double tauf;   // msec (in I_Ca)
	double I_ClCa;   // uA_per_uF (in I_ClCa)
	double I_ClCa_junc;   // uA_per_uF (in I_ClCa)
	double I_ClCa_sl;   // uA_per_uF (in I_ClCa)
	double I_Clbk;   // uA_per_uF (in I_ClCa)
	double I_ki;   // uA_per_uF (in I_Ki)
	double aki;   // dimensionless (in I_Ki)
	double bki;   // dimensionless (in I_Ki)
	double kiss;   // dimensionless (in I_Ki)
	double I_kp;   // uA_per_uF (in I_Kp)
	double I_kp_junc;   // uA_per_uF (in I_Kp)
	double I_kp_sl;   // uA_per_uF (in I_Kp)
	double kp_kp;   // dimensionless (in I_Kp)
	double I_kr;   // uA_per_uF (in I_Kr)
	double gkr;   // mS_per_uF (in I_Kr)
	double rkr;   // dimensionless (in I_Kr)
	double tauxr;   // msec (in I_Kr)
	double xrss;   // dimensionless (in I_Kr)
	double I_ks;   // uA_per_uF (in I_Ks)
	double I_ks_junc;   // uA_per_uF (in I_Ks)
	double I_ks_sl;   // uA_per_uF (in I_Ks)
	double eks;   // mV (in I_Ks)
	double gks_junc;   // mS_per_uF (in I_Ks)
	double gks_sl;   // mS_per_uF (in I_Ks)
	double tauxs;   // msec (in I_Ks)
	double xsss;   // dimensionless (in I_Ks)
	double I_ncx;   // uA_per_uF (in I_NCX)
	double I_ncx_junc;   // uA_per_uF (in I_NCX)
	double I_ncx_sl;   // uA_per_uF (in I_NCX)
	double Ka_junc;   // dimensionless (in I_NCX)
	double Ka_sl;   // dimensionless (in I_NCX)
	double s1_junc;   // mM4 (in I_NCX)
	double s1_sl;   // mM4 (in I_NCX)
	double s2_junc;   // mM4 (in I_NCX)
	double s2_sl;   // mM4 (in I_NCX)
	double s3_junc;   // mM4 (in I_NCX)
	double s3_sl;   // mM4 (in I_NCX)
	double I_nabk;   // uA_per_uF (in I_NaBK)
	double I_nabk_junc;   // uA_per_uF (in I_NaBK)
	double I_nabk_sl;   // uA_per_uF (in I_NaBK)
	double I_nak;   // uA_per_uF (in I_NaK)
	double I_nak_junc;   // uA_per_uF (in I_NaK)
	double I_nak_sl;   // uA_per_uF (in I_NaK)
	double fnak;   // dimensionless (in I_NaK)
	double sigma;   // dimensionless (in I_NaK)
	double I_Na;   // uA_per_uF (in I_Na)
	double I_Na_junc;   // uA_per_uF (in I_Na)
	double I_Na_sl;   // uA_per_uF (in I_Na)
	double ah;   // dimensionless (in I_Na)
	double aj;   // dimensionless (in I_Na)
	double bh;   // dimensionless (in I_Na)
	double bj;   // dimensionless (in I_Na)
	double hss;   // dimensionless (in I_Na)
	double jss;   // dimensionless (in I_Na)
	double mss;   // dimensionless (in I_Na)
	double tauh;   // msec (in I_Na)
	double tauj;   // msec (in I_Na)
	double taum;   // msec (in I_Na)
	double I_pca;   // uA_per_uF (in I_PCa)
	double I_pca_junc;   // uA_per_uF (in I_PCa)
	double I_pca_sl;   // uA_per_uF (in I_PCa)
	double GtoFast;   // mS_per_uF (in I_to)
	double I_to;   // uA_per_uF (in I_to)
	double I_tof;   // uA_per_uF (in I_to)
	double I_tos;   // uA_per_uF (in I_to)
	double tauxtof;   // msec (in I_to)
	double tauxtos;   // msec (in I_to)
	double tauytof;   // msec (in I_to)
	double tauytos;   // msec (in I_to)
	double xtoss;   // dimensionless (in I_to)
	double ytoss;   // dimensionless (in I_to)
	double J_CaB_junction;   // mM_per_msec (in Junctional_and_SL_Ca_Buffers)
	double J_CaB_sl;   // mM_per_msec (in Junctional_and_SL_Ca_Buffers)
	double I_K_tot;   // uA_per_uF (in K_Concentration)
	double I_Na_tot_junc;   // uA_per_uF (in Na_Concentrations)
	double I_Na_tot_junc2;   // uA_per_uF (in Na_Concentrations)
	double I_Na_tot_sl;   // uA_per_uF (in Na_Concentrations)
	double I_Na_tot_sl2;   // uA_per_uF (in Na_Concentrations)
	double J_SRCarel;   // mM_per_msec (in SR_Fluxes)
	double J_SRleak;   // mM_per_msec (in SR_Fluxes)
	double J_serca;   // mM_per_msec (in SR_Fluxes)
	double RI;   // mM (in SR_Fluxes)
	double kCaSR;   // dimensionless (in SR_Fluxes)
	double kiSRCa;   // per_mM_per_msec (in SR_Fluxes)
	double koSRCa;   // per_mM2_per_msec (in SR_Fluxes)
	double I_Ca_tot;   // uA_per_uF (in membrane_potential)
	double I_Cl_tot;   // uA_per_uF (in membrane_potential)
	double I_Na_tot;   // uA_per_uF (in membrane_potential)
	double I_tot;   // uA_per_uF (in membrane_potential)

	double eca_junc;   // mV (in parameters)
	double eca_sl;   // mV (in parameters)
	double ek;   // mV (in parameters)
	double ena_junc;   // mV (in parameters)
	double ena_sl;   // mV (in parameters)
	// double epi;   // dimensionless (in parameters)
	double Gkur, g_Ikur, tau_ac_Ikur, tau_inac_Ikur, ac_Ikur_inf, inac_Ikur_inf;  // Ikur
	double Ikur;

	double static const Frdy = 96485.0;
	double static const R = 8314.0;
	double static const Temp = 310.0;
	double static const FoRT = Frdy / (R * Temp);
	double static const Cmem = 1.10e-10;  // was 1.10e-10 here by haibo
	// cell geometry
	double static const cellRadius = 10.25;
	double static const cellLength = 100.0;
	double static const Vcell = 3.14159265358979 * cellRadius * cellRadius * cellLength * 1.0e-15; // units in liter L
	double static const Vjunc = 0.0539 * 0.01 * Vcell;
	double static const Vmyo = 0.65 * Vcell;
	double static const Vsr = 0.035 * Vcell; // Haibo, change 29/05/2013
	double static const Vsl = 0.02 * Vcell;
	// the values in the non-C code. by haibo
	double static const DcaJuncSL = 1.64e-6;       // in cm
	double static const DcaSLcyto = 1.22e-6;
	double static const DnaJuncSL = 1.09e-5;
	double static const DnaSLcyto = 1.79e-5;

	double static const junctionLength = 160.0e-3;
	double static const junctionRadius = 15.0e-3;
	double static const distSLcyto = 0.45;
	double static const distJuncSL = 0.5;
	double static const SAjunc = 20150.0 * 3.14159265358979 * 2.0 * junctionLength * junctionRadius; // Haibo
	double static const SAsl = 3.14159265358979 * 2.0 * cellRadius * cellLength; // Haibo

	// fixed ion concerntrations.
	double static const Cli = 15;   // Intracellular Cl  [mM]
	double static const Clo = 150;  // Extracellular Cl  [mM]
	double static const Ko  = 5.4;   // Extracellular K   [mM]
	double static const Nao = 140;  // Extracellular Na  [mM]
	double static const Cao = 1.8;  // Extracellular Ca  [mM]
	double static const Mgi = 1.0;    // Intracellular Mg  [mM]

	double const static Q10CaL = 1.8;      //

	double const static KmCai = 3.59e-3;    // [mM]
	double const static KmCao = 1.3;        // [mM]
	double const static KmNai = 12.29;      // [mM]
	double const static KmNao = 87.5;       // [mM]
	double const static ksat = 0.27;        // [none]   was 0.32 here, by haibo
	double const static nu = 0.35;          // [none]   // from SK code, not in atrial paper. Haibo.
	double const static Kdact = 0.384e-3;   // [mM] was 0.225 e-3 haibo
	double const static Q10NCX = 1.57;      // [none]
	double const static IbarSLCaP = 0.0471; //  was 0.0673
	double const static KmPCa = 0.5e-3;     // [mM]
	double const static GCaB = 6.0643e-4;   // [uA/uF]  was    GCaB = 5.513e-4; haibo
	double const static Q10SLCaP = 2.35;    // [none]


	// SR SR_Fluxes
	double const static Q10SRCaP = 2.6;
	double const static Vmax_SRCaP = 5.3114e-3;  // [mM/msec] (286 umol/L cytosol/sec)
	double const static Kmr = 1.7;               // [mM]L cytosol
	double const static hillSRCaP = 1.787;       // [mM]
	double const static ks = 25.0;                 // [1/ms]
	double const static kom = 0.06;              // [1/ms]
	double const static kiCa = 0.5;              // [1/mM/ms]
	double const static kim = 0.005;             // [1/ms]
	double const static ec50SR = 0.45;           // [mM]

	// % Buffering parameters
	// % koff: [1/s] = 1e-3*[1/ms];  kon: [1/uM/s] = [1/mM/ms]
	double const static Bmax_Naj = 7.561;
	double const static Bmax_Nasl = 1.65;
	double const static koff_na = 1.0e-3;
	double const static kon_na = 0.1e-3;
	double const static Bmax_TnClow = 70.0e-3;
	double const static kon_tncl = 32.7;
	double const static Bmax_TnChigh = 140.0e-3;

	double const static kon_sll = 100.0;
	double const static Bmax_SLlowj = 4.6e-3 * Vmyo / Vjunc * 0.1;
	double const static koff_sll = 1300.0e-3;
	double const static kon_slh = 100.0;
	double const static Bmax_SLhighj = 1.65e-3 * Vmyo / Vjunc * 0.1;
	double const static koff_slh = 30.0e-3;

	double const static Bmax_SLlowsl = 37.4e-3 * Vmyo / Vsl;
	double const static Bmax_SLhighsl = 13.4e-3 * Vmyo / Vsl;

	double const static kon_tnchca = 2.37;
	double const static koff_tnchca = 0.032e-3;
	double const static kon_tnchmg = 3.0e-3;
	double const static koff_tnchmg = 3.33e-3;
	double const static kon_cam = 34.0;
	double const static Bmax_CaM = 24.0e-3;
	double const static koff_cam = 238.0e-3;
	double const static kon_myoca = 13.8;
	double const static Bmax_myosin = 140.0e-3;
	double const static koff_myoca = 0.46e-3;
	double const static kon_myomg = 0.0157;
	double const static koff_myomg = 0.057e-3;
	double const static kon_sr = 100.0;
	double const static Bmax_SR = 19.0 * 0.9e-3;
	double const static koff_sr = 60.0e-3;
	double const static fcaCaj = 0.0;
	double const static fcaCaMSL = 0.0;
	double const static Qpow = (Temp - 310.0) / 10.0;
	double const static ecl = 1.0 / FoRT * log(Cli / Clo);


	/* epi ventricle parameters */

	double const static iksmultiply = 1.0;  // gks  0.0035  (mS/microF)
	double const static ik1multiply = 1.0; //  gk1 0.35     (mS/microF)
	double const static ina_c = 0.0; // ina ss
	/**************************************/

	double const static kon_csqn = 100.0;
	double const static Bmax_Csqn = 140.0e-3 * Vmyo / Vsr;
	double const static koff_csqn = 65.0;
	double const static MaxSR = 15.0;
	double const static MinSR = 1.0;

	double const static J_ca_juncsl = 8.2413e-13;
	double const static J_ca_slmyo = 3.7243e-12;
	double const static J_na_juncsl = 1.8313e-14;
	double const static J_na_slmyo = 1.6386e-12;

	// fractional parameters:

	double static const Fjunc = 0.11;
	double static const Fjunc_CaL = 0.9;
	double static const Fsl_CaL = 1.0 - Fjunc_CaL;
	double static const Fsl = 1.0 - Fjunc;



	// Na transport parameters
	double static const GNaB     = 0.597e-3;    // [mS/uF]
	double static const KmKo     = 1.5;         // [mM]1.5
	double static const Q10NaK   = 1.63;
	double static const Q10KmNai = 1.39;
	double static const IbarNaK  = 1.26;     // [uA/uF]    // 1.8*0.7
	// K current parameters:
	double static const pNaK = 0.01833;
	double static const gkp  = 0.002;

	// Cl current parameters
	double static const GClCa = 0.5 * 0.109625;
	double static const KdClCa = 100.0e-3;
	double static const GClB = 1.0 * 9.0e-3;


	double GClCFTR = 0; //%4.9e-3*ISO;     % [mS/uF]
	double I_ClCFTR ;//= GClCFTR*(y(39)-ecl);
	double ISO, AF, RA;
	ISO = 0.0;
	AF = 0;
	RA = 0;

	double Vm = Data->V;


	//-------------------------------------------------------------------------
	// Computed variables
	//-------------------------------------------------------------------------
	// Enviromental states




	double KmNaip   = 11.0 * (1.0 - 0.25 * ISO);         // [mM]11 by haibo, from matlab code
	double GNa      = 23.0 * (1.0 - 0.1 * AF); // [mS/uF]
	double pNa = (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 0.75e-8;   // [cm/sec]
	double pCa = (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 2.7e-4;   // [cm/sec]
	double pK  = (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 1.35e-7;    // [cm/sec]
	double IbarNCX = (1.0 + 0.4 * AF) * 3.15;  //  % [uA/uF]4.5 in ventricle
	double Kmf = (2.5 - 1.25 * ISO) * 0.246e-3;        // [mM] was    Kmf = 2.0*0.246e-3; // Haibo
	double koCa = 10.0 + 20.0 * AF + 10.0 * ISO * (1.0 - AF);             // [mM^-2 1/ms]   %default 10   modified 20
	double koff_tncl =  (1.0 + 0.5 * ISO) * 19.6e-3;  // according to the matlab code



	// I_Ca parameters
	/*pNa = 0.75e-8;     //   [cm/sec]  was    pNa = 3.375e-9; here, haibo
	pCa = 2.7e-4;      //  [cm/sec]
	pK = 1.35e-7;      //   [cm/sec]    was    pK = 6.075e-8; by haibo*/


	//  J_na_juncsl = 1.8313e-10; // CHANGE: Simulink and C
	//   J_na_slmyo = 1.6386e-8; // CHANGE: Simulink and C

	//
	//  Nernst Potentials
	// time: time (msec)
	ibarca_j = pCa * 4.0 * Vm * Frdy * FoRT * (0.341 * Y[1] * exp(2.0 * Vm * FoRT) - 0.341 * Cao) / (exp(2.0 * Vm * FoRT) - 1.0);
	I_Ca_junc = Fjunc_CaL * ibarca_j * Y[10] * Y[11] * (1.0 - Y[12] + fcaCaj) /** pow(Q10CaL, Qpow) */ * 0.45 * 1.0;
	eca_junc = 1.0 / FoRT / 2.0 * log(Cao / Y[1]);
	I_cabk_junc = Fjunc * GCaB * (Vm - eca_junc);
	I_pca_junc = Fjunc/* * pow(Q10SLCaP, Qpow)*/ * IbarSLCaP * pow(Y[1], 1.6) / (pow(KmPCa, 1.6) + pow(Y[1], 1.6));
	Ka_junc = 1.0 / (1.0 + pow(Kdact / Y[1], 2.0));
	s1_junc = exp(nu * Vm * FoRT) * pow(Y[22], 3.0) * Cao;
	s2_junc = exp((nu - 1.0) * Vm * FoRT) * pow(Nao, 3.0) * Y[1];
	s3_junc = KmCai * pow(Nao, 3.0) * (1.0 + pow(Y[22] / KmNai, 3.0)) + pow(KmNao, 3.0) * Y[1] * (1.0 + Y[1] / KmCai) + KmCao * pow(Y[22], 3.0) + pow(Y[22], 3.0) * Cao + pow(Nao, 3.0) * Y[1];
	I_ncx_junc = Fjunc * IbarNCX /** pow(Q10NCX, Qpow)*/ * Ka_junc * (s1_junc - s2_junc) / s3_junc / (1.0 + ksat * exp((nu - 1.0) * Vm * FoRT));
	I_Ca_tot_junc = I_Ca_junc + I_cabk_junc + I_pca_junc - 2.0 * I_ncx_junc;
	ibarca_sl = pCa * 4.0 * Vm * Frdy * FoRT * (0.341 * Y[2] * exp(2.0 * Vm * FoRT) - 0.341 * Cao) / (exp(2.0 * Vm * FoRT) - 1.0);
	I_Ca_sl = Fsl_CaL * ibarca_sl * Y[10] * Y[11] * (1.0 - Y[13] + fcaCaMSL) /** pow(Q10CaL, Qpow)*/ * 0.45 * 1.0;
	eca_sl = 1.0 / FoRT / 2.0 * log(Cao / Y[2]);
	I_cabk_sl = Fsl * GCaB * (Vm - eca_sl);
	I_pca_sl = Fsl /** pow(Q10SLCaP, Qpow)*/ * IbarSLCaP * pow(Y[2], 1.6) / (pow(KmPCa, 1.6) + pow(Y[2], 1.6));
	Ka_sl = 1.0 / (1.0 + pow(Kdact / Y[2], 2.0));
	s1_sl = exp(nu * Vm * FoRT) * pow(Y[23], 3.0) * Cao;
	s2_sl = exp((nu - 1.0) * Vm * FoRT) * pow(Nao, 3.0) * Y[2];
	s3_sl = KmCai * pow(Nao, 3.0) * (1.0 + pow(Y[23] / KmNai, 3.0)) + pow(KmNao, 3.0) * Y[2] * (1.0 + Y[2] / KmCai) + KmCao * pow(Y[23], 3.0) + pow(Y[23], 3.0) * Cao + pow(Nao, 3.0) * Y[2];
	I_ncx_sl = Fsl * IbarNCX /** pow(Q10NCX, Qpow)*/ * Ka_sl * (s1_sl - s2_sl) / s3_sl / (1.0 + ksat * exp((nu - 1.0) * Vm * FoRT));
	I_Ca_tot_sl = I_Ca_sl + I_cabk_sl + I_pca_sl - 2.0 * I_ncx_sl;


	// dY[25] = 0.0 ; //kon_sll * Y[1] * (Bmax_SLlowj - Y[25]) - koff_sll * Y[25];
	// dY[26] = 0.0 ; //kon_sll * Y[2] * (Bmax_SLlowsl - Y[26]) - koff_sll * Y[26];
	// dY[23] = 0.0 ; //kon_slh * Y[1] * (Bmax_SLhighj - Y[23]) - koff_slh * Y[23];
	// dY[24] = 0.0 ; //kon_slh * Y[2] * (Bmax_SLhighsl - Y[24]) - koff_slh * Y[24];



	J_CaB_junction = 0.0;// kon_sll * Y[1] * (Bmax_SLlowj - Y[25]) - koff_sll * Y[25] + (kon_slh * Y[1] * (Bmax_SLhighj - Y[23]) - koff_slh * Y[23]);

	double beta = 0;  // for buffer
	beta = 1.0 + Bmax_SLlowj * koff_sll / kon_sll / (koff_sll / kon_sll + Y[1]) / (koff_sll / kon_sll + Y[1]) + Bmax_SLhighj * koff_slh  / kon_slh / (koff_slh / kon_slh + Y[1]) / (koff_slh / kon_slh + Y[1]);
	beta = 1.0 / beta;

	J_SRCarel = ks * Y[26] / 1.0 * (Y[24] - Y[1]);

	J_SRleak = 5.348e-6 * (1.0 + 0.25 * AF) * (Y[24] - Y[1]);

	// dY[1] = -I_Ca_tot_junc * Cmem / (Vjunc * 2.0 * Frdy) + J_ca_juncsl / Vjunc * (Y[2] - Y[1]) - J_CaB_junction + J_SRCarel * Vsr / Vjunc + J_SRleak * Vmyo / Vjunc;
	dY[1] = beta * (-I_Ca_tot_junc * Cmem / (Vjunc * 2.0 * Frdy) + J_ca_juncsl / Vjunc * (Y[2] - Y[1]) - J_CaB_junction + J_SRCarel * Vsr / Vjunc + J_SRleak * Vmyo / Vjunc);


	J_CaB_sl = 0.0;//kon_sll * Y[2] * (Bmax_SLlowsl - Y[26]) - koff_sll * Y[26] + (kon_slh * Y[2] * (Bmax_SLhighsl - Y[24]) - koff_slh * Y[24]);
	beta = 1.0 + Bmax_SLlowsl * koff_sll / kon_sll / (koff_sll / kon_sll + Y[2]) / (koff_sll / kon_sll + Y[2]) + Bmax_SLhighsl * koff_slh / kon_slh / (koff_slh / kon_slh + Y[2]) / (koff_slh / kon_slh + Y[2]);
	beta = 1.0 / beta;

	dY[2] = beta * (-I_Ca_tot_sl * Cmem / (Vsl * 2.0 * Frdy) + J_ca_juncsl / Vsl * (Y[1] - Y[2]) + J_ca_slmyo / Vsl * (Y[0] - Y[2]) - J_CaB_sl);

	J_serca = /*pow(Q10SRCaP, Qpow) * */Vmax_SRCaP * (pow(Y[0] / Kmf, hillSRCaP) - pow(Y[24] / Kmr, hillSRCaP)) / (1.0 + pow(Y[0] / Kmf, hillSRCaP) + pow(Y[24] / Kmr, hillSRCaP));


	dY[9] = kon_tncl * Y[0] * (Bmax_TnClow - Y[9]) - koff_tncl * Y[9];
	dY[7] = kon_tnchca * Y[0] * (Bmax_TnChigh - Y[7] - Y[8]) - koff_tnchca * Y[7];
	dY[8] = kon_tnchmg * Mgi * (Bmax_TnChigh - Y[7] - Y[8]) - koff_tnchmg * Y[8];
	// dY[3] = 0.0;// kon_cam * Y[0] * (Bmax_CaM - Y[3]) - koff_cam * Y[3];   // reassigned to IKur a,
	dY[4] = kon_myoca * Y[0] * (Bmax_myosin - Y[4] - Y[5]) - koff_myoca * Y[4];
	dY[5] = kon_myomg * Mgi * (Bmax_myosin - Y[4] - Y[5]) - koff_myomg * Y[5];
	// dY[6] = 0.0;//kon_sr * Y[0] * (Bmax_SR - Y[6]) - koff_sr * Y[6];   // reassigned to IKur inac

	J_CaB_cytosol = dY[9]
	                + dY[7]
	                + dY[8]
	                + dY[4]
	                + dY[5];
	// + dY[3]  // CaM
	// + dY[6];  // SR
	beta = 1.0 + Bmax_CaM * koff_cam / kon_cam / (koff_cam / kon_cam + Y[0]) / (koff_cam / kon_cam + Y[0]) + Bmax_SR * koff_sr / kon_sr / (koff_sr / kon_sr + Y[0]) / (koff_sr / kon_sr + Y[0]);
	beta = 1.0 / beta;

	dY[0] = beta * (-J_serca * Vsr / Vmyo - J_CaB_cytosol + J_ca_slmyo / Vmyo * (Y[2] - Y[0]));

	/* atrial ICaL */
	dss = 1.0 / (1.0 + exp(-(Vm + 3.0 * ISO + 9.0) / 6.0));
	taud = 1.0 * dss * (1.0 - exp(-(Vm + 3.0 * ISO + 9.0) / 6.0)) / (0.035 * (Vm + 3.0 * ISO + 9.0));
	fss = 1.0 / (1.0 + exp((Vm + 3.0 * ISO + 30.0) / 7.0)) + 0.2 / (1.0 + exp((50.0 - Vm - 3.0 * ISO) / 20.0));
	tauf = 1.0 / (0.0197 * exp(-pow(0.0337 * (Vm + 3.0 * ISO + 25.0), 2.0)) + 0.02);
	dY[10] = (dss - Y[10]) / taud;   // derivative of d
	dY[11] = (fss - Y[11]) / tauf;   // derivative of f
	dY[12] = 1.7 * Y[1] / 1.0 * (1.0 - Y[12]) - 11.9e-3 * Y[12]; // derivative of fca_bj
	dY[13] = 1.7 * Y[2] / 1.0 * (1.0 - Y[13]) - 11.9e-3 * Y[13]; // derivative of fca_bsl
	ibark = pK * Vm * Frdy * FoRT * (0.75 * Y[29] * exp(Vm * FoRT) - 0.75 * Ko) / (exp(Vm * FoRT) - 1.0);
	ibarna_j = pNa * Vm * Frdy * FoRT * (0.75 * Y[22] * exp(Vm * FoRT) - 0.75 * Nao) / (exp(Vm * FoRT) - 1.0);
	ibarna_sl = pNa * Vm * Frdy * FoRT * (0.75 * Y[23] * exp(Vm * FoRT) - 0.75 * Nao) / (exp(Vm * FoRT) - 1.0);
	I_Ca = I_Ca_junc + I_Ca_sl;
	/***********************/

	I_CaK = ibark * Y[10] * Y[11] * (Fjunc_CaL * (fcaCaj + (1.0 - Y[12])) + Fsl_CaL * (fcaCaMSL + (1.0 - Y[13]))) /** pow(Q10CaL, Qpow)*/ * 0.45 * 1.0;
	I_CaNa_junc = Fjunc_CaL * ibarna_j * Y[10] * Y[11] * (1.0 - Y[12] + fcaCaj) /** pow(Q10CaL, Qpow)*/ * 0.45 * 1.0;
	I_CaNa_sl = Fsl_CaL * ibarna_sl * Y[10] * Y[11] * (1.0 - Y[13] + fcaCaMSL) /** pow(Q10CaL, Qpow)*/ * 0.45 * 1.0;
	I_CaNa = I_CaNa_junc + I_CaNa_sl;
	I_Catot = I_Ca + I_CaK + I_CaNa;
	I_cabk = I_cabk_junc + I_cabk_sl;
	I_ClCa_junc = Fjunc * GClCa / (1.0 + KdClCa / Y[1]) * (Vm - ecl);
	I_ClCa_sl = Fsl * GClCa / (1.0 + KdClCa / Y[2]) * (Vm - ecl);
	I_ClCa = I_ClCa_junc + I_ClCa_sl;
	I_Clbk = GClB * (Vm - ecl);

	/* I_ki */
	ek = 1.0 / FoRT * log(Ko / Y[29]);
	aki = 1.02 / (1.0 + exp(0.2385 * (Vm - ek - 59.215)));
	bki = (0.49124 * exp(0.08032 * (Vm + 5.476 - ek)) + exp(0.06175 * (Vm - ek - 594.31))) / (1.0 + exp(-0.5143 * (Vm - ek + 4.753)));
	kiss = aki / (aki + bki);
	I_ki = (1.0 + 1.0 * AF) * 0.0525 * sqrt(Ko / 5.4) * kiss * (Vm - ek);



	kp_kp = 1.0 / (1.0 + exp(7.488 - Vm / 5.98));
	I_kp_junc = Fjunc * gkp * kp_kp * (Vm - ek);
	I_kp_sl = Fsl * gkp * kp_kp * (Vm - ek);
	I_kp = I_kp_junc + I_kp_sl;


	// I_kr
	gkr = 0.035 * sqrt(Ko / 5.4);
	xrss = 1.0 / (1.0 + exp(-(Vm + 10.0) / 5.0));
	tauxr = 550.0 / (1.0 + exp((-22.0 - Vm) / 9.0)) * 6.0 / (1.0 + exp((Vm - (-11.0)) / 9.0)) + 230.0 / (1.0 + exp((Vm - (-40.0)) / 20.0));
	dY[14] = (xrss - Y[14]) / tauxr;
	rkr = 1.0 / (1.0 + exp((Vm + 74.0) / 24.0));
	I_kr = gkr * Y[14] * rkr * (Vm - ek);

	/*I_ks HH model*/
	gks_junc = 1.0 * (1.0 + 1.0 * AF + 2.0 * ISO) * 0.0035;
	gks_sl = 1.0 * (1.0 + 1.0 * AF + 2.0 * ISO) * 0.0035; // %FRA


	eks = 1.0 / FoRT * log((Ko + pNaK * Nao) / (Y[29] + pNaK * Y[20]));
	xsss = 1.0 / (1.0 + exp(-(Vm + 40.0 * ISO + 3.8) / 14.25));
	tauxs = 990.1 / (1.0 + exp(-(Vm + 40.0 * ISO + 2.436) / 14.12));
	dY[15] = (xsss - Y[15]) / tauxs;
	I_ks_junc = Fjunc * gks_junc * pow(Y[15], 2.0) * (Vm - eks);
	I_ks_sl = Fsl * gks_sl * pow(Y[15], 2.0) * (Vm - eks);
	I_ks = iksmultiply * (I_ks_junc + I_ks_sl);
	I_ncx = I_ncx_junc + I_ncx_sl;


	/* I_Na */
	mss = 1.0 / pow(1.0 + exp(-(56.86 + Vm) / 9.03), 2.0);
	taum = 0.1292 * exp(-pow((Vm + 45.79) / 15.54, 2.0)) + 0.06487 * exp(-pow((Vm - 4.823) / 51.12, 2.0));

	/*if (Vm >= -40.0)
	    ah = 0.0;
	else
	    ah = 0.057 * exp(-(Vm + 80.0) / 6.8);*/

	ah = Vm >= -40.0 ? 0.0 : 0.057 * exp(-(Vm + 80.0) / 6.8);

	if (Vm >= -40.0)
		bh = 0.77 / (0.13 * (1.0 + exp(-(Vm + 10.66) / 11.1)));
	else
		bh = 2.7 * exp(0.079 * Vm) + 3.1e5 * exp(0.3485 * Vm);

	tauh = 1.0 / (ah + bh);
	//  hss = 1.0/pow(1.0+exp((Vm+71.55)/7.43), 2.0);
	hss = (1.0 - ina_c) / pow(1 + exp((Vm + 71.55) / 7.43), 2.0) + ina_c;

	if (Vm >= -40.0)
		aj = 0.0;
	else
		aj = (-2.5428e4 * exp(0.2444 * Vm) - 6.948e-6 * exp(-0.04391 * Vm)) * (Vm + 37.78) / (1.0 + exp(0.311 * (Vm + 79.23)));

	if (Vm >= -40.0)
		bj = 0.6 * exp(0.057 * Vm) / (1.0 + exp(-0.1 * (Vm + 32.0)));
	else
		bj = 0.02424 * exp(-0.01052 * Vm) / (1.0 + exp(-0.1378 * (Vm + 40.14)));

	tauj = 1.0 / (aj + bj);
	//   jss = 1.0/pow(1.0+exp((Vm+71.55)/7.43), 2.0);
	jss = (1.0 - ina_c) / pow(1 + exp((Vm + 71.55) / 7.43), 2.0) + ina_c;

	dY[18] = (mss - Y[18]) / taum;
	dY[16] = (hss - Y[16]) / tauh;
	dY[17] = (jss - Y[17]) / tauj;

	ena_junc = 1.0 / FoRT * log(Nao / Y[22]);
	I_Na_junc = Fjunc * GNa * pow(Y[18], 3.0) * Y[16] * Y[17] * (Vm - ena_junc);
	ena_sl = 1.0 / FoRT * log(Nao / Y[23]);
	I_Na_sl = Fsl * GNa * pow(Y[18], 3.0) * Y[16] * Y[17] * (Vm - ena_sl);
	I_Na = I_Na_junc + I_Na_sl;



	/* Late INa, only in AF condition*/

	/*late I_Na, only in AF condition*/
	// Matlab code, change to C when needed.
	//% Late I_Na
	double GNaL = 0.0025 * AF;
	double aml = 0.32 * (Vm + 47.13) / (1.0 - exp(-0.1 * (Vm + 47.13)));
	double bml = 0.08 * exp((-Vm) / 11.0);
	double hlinf = 1.0 / (1.0 + exp((Vm + 91.0) / 6.1));
	double tauhl = 600.0;
	dY[30] = aml * (1.0 - Y[30]) - bml * Y[30];
	dY[31] = (hlinf - Y[31]) / tauhl;

	double I_NaL_junc = Fjunc * GNaL * pow(Y[30], 3.0) * Y[31] * (Vm - ena_junc);
	double I_NaL_sl   = Fsl * GNaL * pow(Y[30], 3.0) * Y[31] * (Vm - ena_sl);
	double I_NaL      = I_NaL_junc + I_NaL_sl;






	I_nabk_junc = Fjunc * GNaB * (Vm - ena_junc);
	I_nabk_sl = Fsl * GNaB * (Vm - ena_sl);
	I_nabk = I_nabk_junc + I_nabk_sl;



	// I_nak % I_nak: Na/K Pump Current
	sigma = (exp(Nao / 67.3) - 1.0) / 7.0;
	fnak = 1.0 / (1.0 + 0.1245 * exp(-0.1 * Vm * FoRT) + 0.0365 * sigma * exp(-Vm * FoRT));
	I_nak_junc = Fjunc * IbarNaK * fnak * Ko / (1.0 + pow(KmNaip / Y[22], 4.0)) / (Ko + KmKo);
	I_nak_sl = Fsl * IbarNaK * fnak * Ko / (1.0 + pow(KmNaip / Y[23], 4.0)) / (Ko + KmKo);
	I_nak = I_nak_junc + I_nak_sl;


	I_pca = I_pca_junc + I_pca_sl;


	xtoss = 1.0 / (1.0 + exp(-(Vm + 1.0) / 11.0)); // Haibo
	ytoss = 1.0 / (1.0 + exp((Vm + 40.5) / 11.5)); // Haibo
	/*tauxtos = 9.0 / (1.0 + exp((Vm + 3.0) / 15.0)) + 0.5;
	tauytos = 800.0 / (1.0 + exp((Vm + 60.0) / 10.0)) + 30.0;
	dY[20] = (xtoss - Y[20]) / tauxtos;
	dY[22] = (ytoss - Y[22]) / tauytos;*/

	// dY[20] = 0.0;//
	// dY[22] = 0.0;//

	I_tos = 0.0; //0.0 * GtoSlow * Y[20] * Y[22] * (Vm - ek); // Haibo I_to slow has been removed


	// 11/12/09; changed Itof to that from maleckar/giles/2009; removed I_tos
	// atrium
	// equations for activation;
	// the Ito_f in atrium, time constant, by haibo
	// tauxtof = 3.5 / (1.0 + exp(- pow((Vm / 30.0), 2.0))) + 1.5;    // for atrium  // former version, not right, haibo
	tauxtof = 3.5 * ( exp(- pow((Vm / 30.0), 2.0))) + 1.5;    // for atrium
	// tauytof = 85.0 * exp(-pow(Vm + 52.45, 2.0) / 15.8) + 24.14; // check haibo wrong version
	tauytof = 25.635 * exp(-(pow((Vm + 52.45) / 15.8827, 2.0))) + 24.14; //%14.14  from matlab version
	GtoFast = (1.0 - 0.7 * AF) * 0.165; // to be careful
	dY[19] = (xtoss - Y[19]) / tauxtof; // activation of Itof
	dY[21] = (ytoss - Y[21]) / tauytof; // inactivation of Itof by haibo

	I_tof = GtoFast * Y[19] * Y[21] * (Vm - ek);
	I_to = I_tos + I_tof;

	Gkur = 1.0 * (1.0 - 0.5 * AF) * (1.0 + 2.0 * ISO) * 0.045 * (1.0 + 0.2 * RA); //*(1+0.2*RA); //nS/pF maleckar 0.045
	// Gkur = 0.5 * Gkur;
	tau_ac_Ikur = 9.0 / (1.0 + exp((Vm + 5.0) / 12.0)) + 0.5;
	tau_inac_Ikur = 590.0 / (1.0 +  exp((Vm + 60.0) / 10.0)) + 3050.0;
	// shift and change slope according to the effects of the mutations, by haibo
	ac_Ikur_inf = 1.0 / (1.0 + exp(-(Vm - Data->Simple_Ikur_ac_shift + 6.0) / (8.6 * Data->Simple_Ikur_ac_grad)));
	inac_Ikur_inf = 1.0 / (1.0 + exp((Vm - Data->Simple_Ikur_inac_shift + 7.5) / (10.0 * Data->Simple_Ikur_inac_grad)));
	dY[3] = (ac_Ikur_inf - Y[3]) / tau_ac_Ikur;
	dY[6] = (inac_Ikur_inf - Y[6]) / tau_inac_Ikur;
	Ikur = Data->Simple_GKur * Gkur * Y[3] * Y[6] * (Vm - ek);

	// Y[39]=Y[40] = 0.0;


	I_K_tot = I_to + I_kr + I_ks + I_ki - 2.0 * I_nak + I_CaK + I_kp + Ikur;
	dY[29] = 0.0;  // KI


	I_Na_tot_junc = I_Na_junc + I_NaL_junc + I_nabk_junc + 3.0 * I_ncx_junc + 3.0 * I_nak_junc + I_CaNa_junc;
	I_Na_tot_sl = I_Na_sl + I_NaL_sl + I_nabk_sl + 3.0 * I_ncx_sl + 3.0 * I_nak_sl + I_CaNa_sl;
	

	// I_Na_tot_sl2 = 3.0 * I_ncx_sl + 3.0 * I_nak_sl + I_CaNa_sl;
	beta = 1.0 + Bmax_Naj * koff_na / kon_na / (koff_na / kon_na + Y[22]) / (koff_na / kon_na + Y[22]);
	beta = 1.0 / beta;
	// I_Na_tot_junc2 = 3.0 * I_ncx_junc + 3.0 * I_nak_junc + I_CaNa_junc;
	dY[22] = beta * (-I_Na_tot_junc * Cmem / (Vjunc * Frdy) + J_na_juncsl / Vjunc * (Y[23] - Y[22])) ; //- dNa_Bj_dt;


	// dNa_Bsl_dt = kon_na * Y[23] * (Bmax_Nasl - Y[29]) - koff_na * Y[29];
	dY[29] = 0.0;// dNa_Bsl_dt;

	beta = 1.0 + Bmax_Nasl * koff_na / kon_na / (koff_na / kon_na + Y[23]) / (koff_na / kon_na + Y[23]);
	beta = 1.0 / beta;
	dY[23] = beta * (-I_Na_tot_sl * Cmem / (Vsl * Frdy) + J_na_juncsl / Vsl * (Y[22] - Y[23]) + J_na_slmyo / Vsl * (Y[20] - Y[23])); // - dNa_Bsl_dt;

	dY[20] = J_na_slmyo / Vmyo * (Y[23] - Y[20]);


	// dY[34] = 0.0;// kon_csqn * Y[24] * (Bmax_Csqn - Y[34]) - koff_csqn * Y[34];
	beta = 1.0 + Bmax_Csqn * koff_csqn / kon_csqn / (koff_csqn / kon_csqn + Y[24]) / (koff_csqn / kon_csqn + Y[24]);
	beta = 1.0 / beta;

	dY[24] = beta * (J_serca - (J_SRleak * Vmyo / Vsr + J_SRCarel) ); // - (kon_csqn * Y[24] * (Bmax_Csqn - Y[34]) - koff_csqn * Y[34]);
	kCaSR = MaxSR - (MaxSR - MinSR) / (1.0 + pow(ec50SR / Y[24], 2.5));
	koSRCa = koCa / kCaSR;
	kiSRCa = kiCa * kCaSR;
	RI = 1.0 - Y[27] - Y[26] - Y[25];
	dY[27] = kim * RI - kiSRCa * Y[1] * Y[27] - (koSRCa * pow(Y[1], 2.0) * Y[27] - kom * Y[26]);
	dY[26] = koSRCa * pow(Y[1], 2.0) * Y[27] - kom * Y[26] - (kiSRCa * Y[1] * Y[26] - kim * Y[25]);
	dY[25] = kiSRCa * Y[1] * Y[26] - kim * Y[25] - (kom * Y[25] - koSRCa * pow(Y[1], 2.0) * RI);





	/* I_clcfTR */
	GClCFTR = 0; //4.9e-3 * ISO;
	I_ClCFTR = 0.0;// GClCFTR * (Vm - ecl);

	I_Na_tot = I_Na_tot_junc + I_Na_tot_sl;
	I_Cl_tot = I_ClCa + I_Clbk + I_ClCFTR;
	I_Ca_tot = I_Ca_tot_junc + I_Ca_tot_sl;
	I_tot = I_Na_tot + I_Cl_tot + I_Ca_tot + I_K_tot;
	Data->dV = -(I_tot - Data->Istim);

	// for (i = 0; i < NEQ; i++)
	//     Ith(ydot, i + 1) = dY[i];
	// return (0);
}