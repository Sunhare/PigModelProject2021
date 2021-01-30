// #include "GB_ECC.hpp"

// void GB_ECC::Master_ODE_update(double t) {


// 	for (int i = 0; i < ODE_NUM; ++i)
// 	{
// 		ydot[0] = 0.0;
// 	}

// 	// double *y = y;
// 	// double *ydot = ydot;
// 	// double I_Ca_tot_junc = 0.0; // uA_per_uF (in Ca_Concentrations)
// 	// double I_Ca_tot_sl = 0.0; // uA_per_uF (in Ca_Concentrations)
// 	// double J_CaB_cytosol = 0.0; // mM_per_msec (in Cytosolic_Ca_Buffers)
// 	// double I_cabk = 0.0; // uA_per_uF (in I_CaBK)
// 	// double I_cabk_junc = 0.0; // uA_per_uF (in I_CaBK)
// 	// double I_cabk_sl = 0.0; // uA_per_uF (in I_CaBK)
// 	// double I_Ca=0.0;   // uA_per_uF (in I_Ca)
// 	// double I_CaK = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_CaNa = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_CaNa_junc = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_CaNa_sl = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_Ca_junc = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_Ca_sl = 0.0; // uA_per_uF (in I_Ca)
// 	// double I_Catot = 0.0; // uA_per_uF (in I_Ca)
// 	double dss = 0.0; // dimensionless (in I_Ca)
// 	double fcaCaMSL = 0.0; // dimensionless (in I_Ca)
// 	double fcaCaj = 0.0; // dimensionless (in I_Ca)
// 	double fss = 0.0; // dimensionless (in I_Ca)
// 	double ibarca_j = 0.0; // uA_per_uF (in I_Ca)
// 	double ibarca_sl = 0.0; // uA_per_uF (in I_Ca)
// 	double ibark = 0.0; // uA_per_uF (in I_Ca)
// 	double ibarna_j = 0.0; // uA_per_uF (in I_Ca)
// 	double ibarna_sl = 0.0; // uA_per_uF (in I_Ca)
// 	double taud = 0.0; // msec (in I_Ca)
// 	double tauf = 0.0; // msec (in I_Ca)
// 	// double I_ClCa = 0.0; // uA_per_uF (in I_ClCa)
// 	// double I_ClCa_junc = 0.0; // uA_per_uF (in I_ClCa)
// 	// double I_ClCa_sl = 0.0; // uA_per_uF (in I_ClCa)
// 	// double I_Clbk = 0.0; // uA_per_uF (in I_ClCa)
// 	// double I_ki=0.0;   // uA_per_uF (in I_Ki)
// 	double aki = 0.0; // dimensionless (in I_Ki)
// 	double bki = 0.0; // dimensionless (in I_Ki)
// 	double kiss = 0.0; // dimensionless (in I_Ki)
// 	// double I_kp = 0.0; // uA_per_uF (in I_Kp)
// 	// double I_kp_junc = 0.0; // uA_per_uF (in I_Kp)
// 	// double I_kp_sl = 0.0; // uA_per_uF (in I_Kp)
// 	double kp_kp = 0.0; // dimensionless (in I_Kp)
// 	// double I_kr=0.0;   // uA_per_uF (in I_Kr)
// 	double gkr = 0.0; // mS_per_uF (in I_Kr)
// 	double rkr = 0.0; // dimensionless (in I_Kr)
// 	double tauxr = 0.0; // msec (in I_Kr)
// 	double xrss = 0.0; // dimensionless (in I_Kr)
// 	// // double I_ks=0.0;   // uA_per_uF (in I_Ks)
// 	// double I_ks_junc = 0.0; // uA_per_uF (in I_Ks)
// 	// double I_ks_sl = 0.0; // uA_per_uF (in I_Ks)
// 	double eks = 0.0; // mV (in I_Ks)
// 	double gks_junc = 0.0; // mS_per_uF (in I_Ks)
// 	double gks_sl = 0.0; // mS_per_uF (in I_Ks)
// 	double tauxs = 0.0; // msec (in I_Ks)
// 	double xsss = 0.0; // dimensionless (in I_Ks)
// 	// double I_ncx=0.0;   // uA_per_uF (in I_NCX)
// 	// double I_ncx_junc = 0.0; // uA_per_uF (in I_NCX)
// 	// double I_ncx_sl = 0.0; // uA_per_uF (in I_NCX)
// 	double Ka_junc = 0.0; // dimensionless (in I_NCX)
// 	double Ka_sl = 0.0; // dimensionless (in I_NCX)
// 	double s1_junc = 0.0; // mM4 (in I_NCX)
// 	double s1_sl = 0.0; // mM4 (in I_NCX)
// 	double s2_junc = 0.0; // mM4 (in I_NCX)
// 	double s2_sl = 0.0; // mM4 (in I_NCX)
// 	double s3_junc = 0.0; // mM4 (in I_NCX)
// 	double s3_sl = 0.0; // mM4 (in I_NCX)
// 	// double I_nabk=0.0;   // uA_per_uF (in I_NaBK)
// 	// double I_nabk_junc = 0.0; // uA_per_uF (in I_NaBK)
// 	// double I_nabk_sl = 0.0; // uA_per_uF (in I_NaBK)
// 	// double I_nak=0.0;   // uA_per_uF (in I_NaK)
// 	// double I_nak_junc = 0.0; // uA_per_uF (in I_NaK)
// 	// double I_nak_sl = 0.0; // uA_per_uF (in I_NaK)
// 	double fnak = 0.0; // dimensionless (in I_NaK)
// 	double sigma = 0.0; // dimensionless (in I_NaK)
// 	// double I_Na=0.0;   // uA_per_uF (in I_Na)
// 	// double I_Na_junc = 0.0; // uA_per_uF (in I_Na)
// 	// double I_Na_sl = 0.0; // uA_per_uF (in I_Na)
// 	double ah = 0.0; // dimensionless (in I_Na)
// 	double aj = 0.0; // dimensionless (in I_Na)
// 	double bh = 0.0; // dimensionless (in I_Na)
// 	double bj = 0.0; // dimensionless (in I_Na)
// 	double hss = 0.0; // dimensionless (in I_Na)
// 	double jss = 0.0; // dimensionless (in I_Na)
// 	double mss = 0.0; // dimensionless (in I_Na)
// 	double tauh = 0.0; // msec (in I_Na)
// 	double tauj = 0.0; // msec (in I_Na)
// 	double taum = 0.0; // msec (in I_Na)
// 	// double I_pca = 0.0; // uA_per_uF (in I_PCa)
// 	// double I_pca_junc = 0.0; // uA_per_uF (in I_PCa)
// 	// double I_pca_sl = 0.0; // uA_per_uF (in I_PCa)
// 	double GtoFast = 0.0; // mS_per_uF (in I_to)
// 	double GtoSlow = 0.0; // mS_per_uF (in I_to)
// 	// double I_to=0.0;   // uA_per_uF (in I_to)
// 	// double I_tof = 0.0; // uA_per_uF (in I_to)
// 	// double I_tos = 0.0; // uA_per_uF (in I_to)
// 	double tauxtof = 0.0; // msec (in I_to)
// 	double tauxtos = 0.0; // msec (in I_to)
// 	double tauytof = 0.0; // msec (in I_to)
// 	double tauytos = 0.0; // msec (in I_to)
// 	double xtoss = 0.0; // dimensionless (in I_to)
// 	double ytoss = 0.0; // dimensionless (in I_to)
// 	// double J_CaB_junction = 0.0; // mM_per_msec (in Junctional_and_SL_Ca_Buffers)
// 	double J_CaB_sl = 0.0; // mM_per_msec (in Junctional_and_SL_Ca_Buffers)
// 	double I_K_tot = 0.0; // uA_per_uF (in K_Concentration)
// 	double dNa_Bj_dt = 0.0; // mM_per_msec (in Na_Buffers)
// 	double dNa_Bsl_dt = 0.0; // mM_per_msec (in Na_Buffers)
// 	// /*double*/ I_Na_tot_junc = 0.0; // uA_per_uF (in Na_Concentrations)
// 	// double I_Na_tot_junc2 = 0.0; // uA_per_uF (in Na_Concentrations)
// 	// double I_Na_tot_sl = 0.0; // uA_per_uF (in Na_Concentrations)
// 	// /*double*/ I_Na_tot_sl2 = 0.0; // uA_per_uF (in Na_Concentrations)
// 	// /*double*/ J_SRCarel = 0.0; // mM_per_msec (in SR_Fluxes)
// 	// /*double*/ J_SRleak = 0.0; // mM_per_msec (in SR_Fluxes)
// 	// /*double*/ J_serca = 0.0; // mM_per_msec (in SR_Fluxes)
// 	double MaxSR = 0.0; // dimensionless (in SR_Fluxes)
// 	double MinSR = 0.0; // dimensionless (in SR_Fluxes)
// 	double RI = 0.0; // mM (in SR_Fluxes)
// 	double kCaSR = 0.0; // dimensionless (in SR_Fluxes)
// 	double kiSRCa = 0.0; // per_mM_per_msec (in SR_Fluxes)
// 	double koSRCa = 0.0; // per_mM2_per_msec (in SR_Fluxes)
// 	// /*double*/ I_Ca_tot = 0.0; // uA_per_uF (in membrane_potential)
// 	// /*double*/ I_Cl_tot = 0.0; // uA_per_uF (in membrane_potential)
// 	// /*double*/ I_Na_tot = 0.0; // uA_per_uF (in membrane_potential)
// 	// /*double*/ I_tot = 0.0; // uA_per_uF (in membrane_potential)
// 	// double i_Stim=0.0;   // uA_per_uF
// 	double Bmax_CaM = 0.0; // mM (in parameters)
// 	double Bmax_Csqn = 0.0; // mM (in parameters)
// 	double Bmax_Naj = 0.0; // mM (in parameters)
// 	double Bmax_Nasl = 0.0; // mM (in parameters)
// 	double Bmax_SLhighj = 0.0; // mM (in parameters)
// 	double Bmax_SLhighsl = 0.0; // mM (in parameters)
// 	double Bmax_SLlowj = 0.0; // mM (in parameters)
// 	double Bmax_SLlowsl = 0.0; // mM (in parameters)
// 	double Bmax_SR = 0.0; // mM (in parameters)
// 	double Bmax_TnChigh = 0.0; // mM (in parameters)
// 	double Bmax_TnClow = 0.0; // mM (in parameters)
// 	double Bmax_myosin = 0.0; // mM (in parameters)
// 	double Cao = 0.0; // mM (in parameters)
// 	double Cli = 0.0; // mM (in parameters)
// 	double Clo = 0.0; // mM (in parameters)
// 	double Cmem = 0.0; // farad (in parameters)
// 	double DcaJuncSL = 0.0; // cm2_per_sec (in parameters)
// 	double DcaSLcyto = 0.0; // cm2_per_sec (in parameters)
// 	double DnaJuncSL = 0.0; // cm2_per_sec (in parameters)
// 	double DnaSLcyto = 0.0; // cm2_per_sec (in parameters)
// 	double Fjunc = 0.0; // dimensionless (in parameters)
// 	double Fjunc_CaL = 0.0; // dimensionless (in parameters)
// 	double FoRT = 0.0; // per_mV (in parameters)
// 	double Frdy = 0.0; // coulomb_per_mole (in parameters)
// 	double Fsl = 0.0; // dimensionless (in parameters)
// 	double Fsl_CaL = 0.0; // dimensionless (in parameters)
// 	double GCaB = 0.0; // mS_per_uF (in parameters)
// 	double GClB = 0.0; // mS_per_uF (in parameters)
// 	double GClCa = 0.0; // mS_per_uF (in parameters)
// 	double GNa = 0.0; // mS_per_uF (in parameters)
// 	double GNaB = 0.0; // mS_per_uF (in parameters)
// 	double IbarNCX = 0.0; // uA_per_uF (in parameters)
// 	double IbarNaK = 0.0; // uA_per_uF (in parameters)
// 	double IbarSLCaP = 0.0; // uA_per_uF (in parameters)
// 	double J_ca_juncsl = 0.0; // liters_per_msec (in parameters)
// 	double J_ca_slmyo = 0.0; // liters_per_msec (in parameters)
// 	double J_na_juncsl = 0.0; // liters_per_msec (in parameters)
// 	double J_na_slmyo = 0.0; // liters_per_msec (in parameters)
// 	double KdClCa = 0.0; // mM (in parameters)
// 	double Kdact = 0.0; // mM (in parameters)
// 	double KmCai = 0.0; // mM (in parameters)
// 	double KmCao = 0.0; // mM (in parameters)
// 	double KmKo = 0.0; // mM (in parameters)
// 	double KmNai = 0.0; // mM (in parameters)
// 	double KmNaip = 0.0; // mM (in parameters)
// 	double KmNao = 0.0; // mM (in parameters)
// 	double KmPCa = 0.0; // mM (in parameters)
// 	double Kmf = 0.0; // mM (in parameters)
// 	double Kmr = 0.0; // mM (in parameters)
// 	double Ko = 0.0; // mM (in parameters)
// 	double Mgi = 0.0; // mM (in parameters)
// 	double Nao = 0.0; // mM (in parameters)
// 	double Q10CaL = 0.0; // dimensionless (in parameters)
// 	double Q10KmNai = 0.0; // dimensionless (in parameters)
// 	double Q10NCX = 0.0; // dimensionless (in parameters)
// 	double Q10NaK = 0.0; // dimensionless (in parameters)
// 	double Q10SLCaP = 0.0; // dimensionless (in parameters)
// 	double Q10SRCaP = 0.0; // dimensionless (in parameters)
// 	double Qpow = 0.0; // dimensionless (in parameters)
// 	double R = 0.0; // joule_per_kelvin_per_kilomole (in parameters)
// 	double SAjunc = 0.0; // um2 (in parameters)
// 	double SAsl = 0.0; // um2 (in parameters)
// 	double Temp = 0.0; // kelvin (in parameters)
// 	double Vcell = 0.0; // liter (in parameters)
// 	double Vjunc = 0.0; // liter (in parameters)
// 	double Vmax_SRCaP = 0.0; // mM_per_msec (in parameters)
// 	double Vmyo = 0.0; // liter (in parameters)
// 	double Vsl = 0.0; // liter (in parameters)
// 	double Vsr = 0.0; // liter (in parameters)
// 	double cellLength = 0.0; // um (in parameters)
// 	double cellRadius = 0.0; // um (in parameters)
// 	double distJuncSL = 0.0; // um (in parameters)
// 	double distSLcyto = 0.0; // um (in parameters)
// 	double ec50SR = 0.0; // mM (in parameters)
// 	double eca_junc = 0.0; // mV (in parameters)
// 	double eca_sl = 0.0; // mV (in parameters)
// 	double ecl = 0.0; // mV (in parameters)
// 	double ek = 0.0; // mV (in parameters)
// 	double ena_junc = 0.0; // mV (in parameters)
// 	double ena_sl = 0.0; // mV (in parameters)
// 	// double epi=0.0;   // dimensionless (in parameters)
// 	double gkp = 0.0; // mS_per_uF (in parameters)
// 	double hillSRCaP = 0.0; // dimensionless (in parameters)
// 	double junctionLength = 0.0; // um (in parameters)
// 	double junctionRadius = 0.0; // um (in parameters)
// 	double kiCa = 0.0; // per_mM_per_msec (in parameters)
// 	double kim = 0.0; // per_msec (in parameters)
// 	double koCa = 0.0; // per_mM2_per_msec (in parameters)
// 	double koff_cam = 0.0; // per_msec (in parameters)
// 	double koff_csqn = 0.0; // per_msec (in parameters)
// 	double koff_myoca = 0.0; // per_msec (in parameters)
// 	double koff_myomg = 0.0; // per_msec (in parameters)
// 	double koff_na = 0.0; // per_msec (in parameters)
// 	double koff_slh = 0.0; // per_msec (in parameters)
// 	double koff_sll = 0.0; // per_msec (in parameters)
// 	double koff_sr = 0.0; // per_msec (in parameters)
// 	double koff_tnchca = 0.0; // per_msec (in parameters)
// 	double koff_tnchmg = 0.0; // per_msec (in parameters)
// 	double koff_tncl = 0.0; // per_msec (in parameters)
// 	double kom = 0.0; // per_msec (in parameters)
// 	double kon_cam = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_csqn = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_myoca = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_myomg = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_na = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_slh = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_sll = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_sr = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_tnchca = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_tnchmg = 0.0; // per_mM_per_msec (in parameters)
// 	double kon_tncl = 0.0; // per_mM_per_msec (in parameters)
// 	double ks = 0.0; // per_msec (in parameters)
// 	double ksat = 0.0; // dimensionless (in parameters)
// 	double nu = 0.0; // dimensionless (in parameters)
// 	double pCa = 0.0; // cm_per_sec (in parameters)
// 	double pK = 0.0; // cm_per_sec (in parameters)
// 	double pNa = 0.0; // cm_per_sec (in parameters)
// 	double pNaK = 0.0; // dimensionless (in parameters)

// 	double iksmultiply, ik1multiply, ina_c;
// 	double Gkur, g_Ikur, tau_ac_Ikur, tau_inac_Ikur, ac_Ikur_inf, inac_Ikur_inf;  // I_kur

// 	/* Late INa, only in AF condition*/
// 	// double I_NaL_junc;
// 	// double I_NaL_sl;
// 	// double I_NaL;
// 	// double GNaL;
// 	// double aml, bml, hlinf, tauhl;


// 	double GClCFTR = 0; //%4.9e-3*ISO;     % [mS/uF]
// 	double I_ClCFTR ;//= GClCFTR*(y(39)-ecl);
// 	double AF, RA;
// 	// ISO = 0.0;
// 	AF = 0;
// 	RA = 0;


// 	//-------------------------------------------------------------------------
// 	// Computed variables
// 	//-------------------------------------------------------------------------
// 	// Enviromental states

// 	Frdy = 96485.0;
// 	R = 8314.0;
// 	Temp = 310.0;
// 	FoRT = Frdy / (R * Temp);
// 	Cmem = 1.10e-10;  // was 1.10e-10 here by haibo
// 	// cell geometry
// 	cellRadius = 10.25;
// 	cellLength = 100.0;
// 	Vcell = 3.14159265358979 * pow(cellRadius, 2.0) * cellLength * 1.0e-15;   // units in liter L
// 	Vjunc = 0.0539 * 0.01 * Vcell;
// 	Vmyo = 0.65 * Vcell;
// 	Vsr = 0.035 * Vcell; // Haibo, change 29/05/2013
// 	Vsl = 0.02 * Vcell;
// 	// the values in the non-C code. by haibo
// 	DcaJuncSL = 1.64e-6;       // in cm
// 	DcaSLcyto = 1.22e-6;
// 	DnaJuncSL = 1.09e-5;
// 	DnaSLcyto = 1.79e-5;
// 	// comment out by haibo, 29. 05. 2013
// 	/*DcaJuncSL = 1.2205e-5;
// 	DcaSLcyto = 2.8914e-6;
// 	DnaJuncSL = 2.7121e-7;
// 	DnaSLcyto = 1.2722e-6;
// 	*/
// 	junctionLength = 160.0e-3;
// 	junctionRadius = 15.0e-3;
// 	distSLcyto = 0.45;
// 	distJuncSL = 0.5;
// 	SAjunc = 20150.0 * 3.14159265358979 * 2.0 * junctionLength * junctionRadius; // Haibo
// 	SAsl = 3.14159265358979 * 2.0 * cellRadius * cellLength; // Haibo

// 	// fractional parameters:

// 	Fjunc = 0.11;
// 	Fjunc_CaL = 0.9;
// 	Fsl_CaL = 1.0 - Fjunc_CaL;
// 	Fsl = 1.0 - Fjunc;

// 	// fixed ion concerntrations.
// 	Cli = 15;   // Intracellular Cl  [mM]
// 	Clo = 150;  // Extracellular Cl  [mM]
// 	Ko  = 5.4;   // Extracellular K   [mM]
// 	Nao = 140;  // Extracellular Na  [mM]
// 	Cao = 1.8;  // Extracellular Ca  [mM]
// 	Mgi = 1.0;    // Intracellular Mg  [mM]


// 	// Na transport parameters
// 	GNa      = para[0] * 23.0 * (1.0 - 0.1 * AF); // [mS/uF]
// 	GNaB     = para[1] * 0.597e-3;  // [mS/uF]
// 	IbarNaK  = para[2] * 1.26;   // [uA/uF]    // 1.8*0.7
// 	KmNaip   = 11.0 * (1.0 - 0.25 * ISO);         // [mM]11 by haibo, from matlab code
// 	KmKo     = 1.5;         // [mM]1.5
// 	Q10NaK   = 1.63;
// 	Q10KmNai = 1.39;

// 	// K current parameters:
// 	pNaK = para[3] * 0.01833;
// 	gkp  = para[4] * 0.002;

// 	// Cl current parameters
// 	GClCa = para[5] * 0.5 * 0.109625;
// 	KdClCa = 100.0e-3;
// 	GClB = para[6] * 1.0 * 9.0e-3;


// 	// I_Ca parameters
// 	/*pNa = 0.75e-8;     //   [cm/sec]  was    pNa = 3.375e-9; here, haibo
// 	pCa = 2.7e-4;      //  [cm/sec]
// 	pK = 1.35e-7;      //   [cm/sec]    was    pK = 6.075e-8; by haibo*/
// 	pNa = para[7] * (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 0.75e-8; // [cm/sec]
// 	pCa = para[7] * (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 2.7e-4; // [cm/sec]
// 	pK  = para[7] * (1.0 + 0.5 * ISO) * (1.0 - 0.5 * AF) * 1.35e-7;  // [cm/sec]
// 	Q10CaL = 1.8;      //

// 	IbarNCX = para[8] * (1.0 + 0.4 * AF) * 3.15; //  % [uA/uF]4.5 in ventricle
// 	KmCai = 3.59e-3;    // [mM]
// 	KmCao = 1.3;        // [mM]
// 	KmNai = 12.29;      // [mM]
// 	KmNao = 87.5;       // [mM]
// 	ksat = 0.27;        // [none]   was 0.32 here, by haibo
// 	nu = 0.35;          // [none]   // from SK code, not in atrial paper. Haibo.
// 	Kdact = 0.384e-3;   // [mM] was 0.225 e-3 haibo
// 	Q10NCX = 1.57;      // [none]
// 	IbarSLCaP = 0.0471; //  was 0.0673
// 	KmPCa = 0.5e-3;     // [mM]
// 	GCaB = 6.0643e-4;   // [uA/uF]  was    GCaB = 5.513e-4; haibo
// 	Q10SLCaP = 2.35;    // [none]


// 	// SR SR_Fluxes
// 	Q10SRCaP = 2.6;
// 	Vmax_SRCaP = para[9] * 5.3114e-3; // [mM/msec] (286 umol/L cytosol/sec)
// 	Kmf = (2.5 - 1.25 * ISO) * 0.246e-3 * kmf_scale;      // [mM] was    Kmf = 2.0*0.246e-3; // Haibo
// 	Kmr = 1.7;               // [mM]L cytosol
// 	hillSRCaP = 1.787;       // [mM]
// 	ks = para[10] * 25.0;               // [1/ms]
// 	koCa = 10.0 + 20.0 * AF + 10.0 * ISO * (1.0 - AF);             // [mM^-2 1/ms]   %default 10   modified 20
// 	kom = 0.06;              // [1/ms]
// 	kiCa = 0.5;              // [1/mM/ms]
// 	kim = 0.005;             // [1/ms]
// 	ec50SR = 0.45;           // [mM]

// 	// % Buffering parameters
// 	// % koff: [1/s] = 1e-3*[1/ms];  kon: [1/uM/s] = [1/mM/ms]
// 	Bmax_Naj = 7.561;
// 	Bmax_Nasl = 1.65;
// 	koff_na = 1.0e-3;
// 	kon_na = 0.1e-3;
// 	Bmax_TnClow = 70.0e-3;
// 	koff_tncl =  (1.0 + 0.5 * ISO) * 19.6e-3;  // according to the matlab code
// 	kon_tncl = 32.7;
// 	Bmax_TnChigh = 140.0e-3;

// 	kon_sll = 100.0;
// 	Bmax_SLlowj = 4.6e-3 * Vmyo / Vjunc * 0.1;
// 	koff_sll = 1300.0e-3;
// 	kon_slh = 100.0;
// 	Bmax_SLhighj = 1.65e-3 * Vmyo / Vjunc * 0.1;
// 	koff_slh = 30.0e-3;

// 	Bmax_SLlowsl = 37.4e-3 * Vmyo / Vsl;
// 	Bmax_SLhighsl = 13.4e-3 * Vmyo / Vsl;

// 	kon_tnchca = 2.37;
// 	koff_tnchca = 0.032e-3;
// 	kon_tnchmg = 3.0e-3;
// 	koff_tnchmg = 3.33e-3;
// 	kon_cam = 34.0;
// 	Bmax_CaM = 24.0e-3;
// 	koff_cam = 238.0e-3;
// 	kon_myoca = 13.8;
// 	Bmax_myosin = 140.0e-3;
// 	koff_myoca = 0.46e-3;
// 	kon_myomg = 0.0157;
// 	koff_myomg = 0.057e-3;
// 	kon_sr = 100.0;
// 	Bmax_SR = 19.0 * 0.9e-3;
// 	koff_sr = 60.0e-3;
// 	fcaCaj = 0.0;
// 	fcaCaMSL = 0.0;
// 	Qpow = (Temp - 310.0) / 10.0;

// 	ecl = 1.0 / FoRT * log(Cli / Clo);

// 	/* epi ventricle parameters */
// 	// GtoSlow = para[12] * 0.0156; // 0.0156 (mS/microF)
// 	// GtoFast = para[12] * 0.165; // 0.1144  (mS/microF) Haibo
// 	iksmultiply = 1.0;  // gks  0.0035  (mS/microF)
// 	ik1multiply = 1.0; //  gk1 0.35     (mS/microF)
// 	ina_c = 0.0; // ina ss
// 	/**************************************/

// 	kon_csqn = 100.0;
// 	Bmax_Csqn = 140.0e-3 * Vmyo / Vsr;
// 	koff_csqn = 65.0;
// 	MaxSR = 15.0;
// 	MinSR = 1.0;

// 	J_ca_juncsl = 8.2413e-13;
// 	J_ca_slmyo = 3.7243e-12;
// 	J_na_juncsl = 1.8313e-14;
// 	//  J_na_juncsl = 1.8313e-10; // CHANGE: Simulink and C
// 	J_na_slmyo = 1.6386e-12;
// 	//   J_na_slmyo = 1.6386e-8; // CHANGE: Simulink and C

// 	//
// 	//  Nernst Potentials
// 	// time: time (msec)

// 	ibarca_j = pCa * 4.0 * y[38] * Frdy * FoRT * (0.341 * y[1] * exp(2.0 * y[38] * FoRT) - 0.341 * Cao) / (exp(2.0 * y[38] * FoRT) - 1.0);
// 	I_Ca_junc = Fjunc_CaL * ibarca_j * y[10] * y[11] * (1.0 - y[12] + fcaCaj) * pow(Q10CaL, Qpow) * 0.45 * 1.0;
// 	eca_junc = 1.0 / FoRT / 2.0 * log(Cao / y[1]);
// 	I_cabk_junc = Fjunc * GCaB * (y[38] - eca_junc);
// 	I_pca_junc = Fjunc * pow(Q10SLCaP, Qpow) * IbarSLCaP * pow(y[1], 1.6) / (pow(KmPCa, 1.6) + pow(y[1], 1.6));
// 	Ka_junc = 1.0 / (1.0 + pow(Kdact / y[1], 2.0));
// 	s1_junc = exp(nu * y[38] * FoRT) * pow(y[31], 3.0) * Cao;
// 	s2_junc = exp((nu - 1.0) * y[38] * FoRT) * pow(Nao, 3.0) * y[1];
// 	s3_junc = KmCai * pow(Nao, 3.0) * (1.0 + pow(y[31] / KmNai, 3.0)) + pow(KmNao, 3.0) * y[1] * (1.0 + y[1] / KmCai) + KmCao * pow(y[31], 3.0) + pow(y[31], 3.0) * Cao + pow(Nao, 3.0) * y[1];
// 	I_ncx_junc = Fjunc * IbarNCX * pow(Q10NCX, Qpow) * Ka_junc * (s1_junc - s2_junc) / s3_junc / (1.0 + ksat * exp((nu - 1.0) * y[38] * FoRT));
// 	I_Ca_tot_junc = I_Ca_junc + I_cabk_junc + I_pca_junc - 2.0 * I_ncx_junc;
// 	ibarca_sl = pCa * 4.0 * y[38] * Frdy * FoRT * (0.341 * y[2] * exp(2.0 * y[38] * FoRT) - 0.341 * Cao) / (exp(2.0 * y[38] * FoRT) - 1.0);
// 	I_Ca_sl = Fsl_CaL * ibarca_sl * y[10] * y[11] * (1.0 - y[13] + fcaCaMSL) * pow(Q10CaL, Qpow) * 0.45 * 1.0;
// 	eca_sl = 1.0 / FoRT / 2.0 * log(Cao / y[2]);
// 	I_cabk_sl = Fsl * GCaB * (y[38] - eca_sl);
// 	I_pca_sl = Fsl * pow(Q10SLCaP, Qpow) * IbarSLCaP * pow(y[2], 1.6) / (pow(KmPCa, 1.6) + pow(y[2], 1.6));
// 	Ka_sl = 1.0 / (1.0 + pow(Kdact / y[2], 2.0));
// 	s1_sl = exp(nu * y[38] * FoRT) * pow(y[32], 3.0) * Cao;
// 	s2_sl = exp((nu - 1.0) * y[38] * FoRT) * pow(Nao, 3.0) * y[2];
// 	s3_sl = KmCai * pow(Nao, 3.0) * (1.0 + pow(y[32] / KmNai, 3.0)) + pow(KmNao, 3.0) * y[2] * (1.0 + y[2] / KmCai) + KmCao * pow(y[32], 3.0) + pow(y[32], 3.0) * Cao + pow(Nao, 3.0) * y[2];
// 	I_ncx_sl = Fsl * IbarNCX * pow(Q10NCX, Qpow) * Ka_sl * (s1_sl - s2_sl) / s3_sl / (1.0 + ksat * exp((nu - 1.0) * y[38] * FoRT));
// 	I_Ca_tot_sl = I_Ca_sl + I_cabk_sl + I_pca_sl - 2.0 * I_ncx_sl;


// 	J_CaB_junction = kon_sll * y[1] * (Bmax_SLlowj - y[25]) - koff_sll * y[25]
// 	                 + (kon_slh * y[1] * (Bmax_SLhighj - y[23]) - koff_slh * y[23]);
// 	J_SRCarel = ks * y[36] / 1.0 * (y[33] - y[1]);

// 	J_SRleak = para[13] * 5.348e-6 * (1.0 + 0.25 * AF) * (y[33] - y[1]);

// 	ydot[1] = -I_Ca_tot_junc * Cmem / (Vjunc * 2.0 * Frdy) + J_ca_juncsl / Vjunc * (y[2] - y[1]) - J_CaB_junction + J_SRCarel * Vsr / Vjunc + J_SRleak * Vmyo / Vjunc;
// 	J_CaB_sl = kon_sll * y[2] * (Bmax_SLlowsl - y[26]) - koff_sll * y[26] + (kon_slh * y[2] * (Bmax_SLhighsl - y[24]) - koff_slh * y[24]);
// 	ydot[2] = -I_Ca_tot_sl * Cmem / (Vsl * 2.0 * Frdy) + J_ca_juncsl / Vsl * (y[1] - y[2]) + J_ca_slmyo / Vsl * (y[0] - y[2]) - J_CaB_sl;
// 	J_serca = pow(Q10SRCaP, Qpow) * Vmax_SRCaP * (pow(y[0] / Kmf, hillSRCaP) - pow(y[33] / Kmr, hillSRCaP)) / (1.0 + pow(y[0] / Kmf, hillSRCaP) + pow(y[33] / Kmr, hillSRCaP));

// 	ydot[9] = kon_tncl * y[0] * (Bmax_TnClow - y[9]) - koff_tncl * y[9];
// 	ydot[7] = kon_tnchca * y[0] * (Bmax_TnChigh - y[7] - y[8]) - koff_tnchca * y[7];
// 	ydot[8] = kon_tnchmg * Mgi * (Bmax_TnChigh - y[7] - y[8]) - koff_tnchmg * y[8];
// 	ydot[3] = kon_cam * y[0] * (Bmax_CaM - y[3]) - koff_cam * y[3];
// 	ydot[4] = kon_myoca * y[0] * (Bmax_myosin - y[4] - y[5]) - koff_myoca * y[4];
// 	ydot[5] = kon_myomg * Mgi * (Bmax_myosin - y[4] - y[5]) - koff_myomg * y[5];
// 	ydot[6] = kon_sr * y[0] * (Bmax_SR - y[6]) - koff_sr * y[6];


// 	J_CaB_cytosol = ydot[9] //kon_tncl * y[0] * (Bmax_TnClow - y[9]) - koff_tncl * y[9]
// 	                + ydot[7] // kon_tnchca * y[0] * (Bmax_TnChigh - y[7] - y[8]) - koff_tnchca * y[7]
// 	                + kon_tnchmg * Mgi * (Bmax_TnChigh - y[7] - y[8]) - koff_tnchmg * y[8]
// 	                + kon_cam * y[0] * (Bmax_CaM - y[3]) - koff_cam * y[3]
// 	                + kon_myoca * y[0] * (Bmax_myosin - y[4] - y[5]) - koff_myoca * y[4]
// 	                + kon_myomg * Mgi * (Bmax_myosin - y[4] - y[5]) - koff_myomg * y[5]
// 	                + (kon_sr * y[0] * (Bmax_SR - y[6]) - koff_sr * y[6]);


// 	J_CaB_cytosol = ydot[9] + ydot[7] + ydot[8] + ydot[3] + ydot[4] + ydot[5] + ydot[6];

// 	ydot[0] = -J_serca * Vsr / Vmyo - J_CaB_cytosol + J_ca_slmyo / Vmyo * (y[2] - y[0]);
// 	/* atrial ICaL */
// 	dss = 1.0 / (1.0 + exp(-(y[38] + 3.0 * ISO + 9.0) / 6.0));
// 	taud = 1.0 * dss * (1.0 - exp(-(y[38] + 3.0 * ISO + 9.0) / 6.0)) / (0.035 * (y[38] + 3.0 * ISO + 9.0));
// 	fss = 1.0 / (1.0 + exp((y[38] + 3.0 * ISO + 30.0) / 7.0)) + 0.2 / (1.0 + exp((50.0 - y[38] - 3.0 * ISO) / 20.0));
// 	tauf = 1.0 / (0.0197 * exp(-pow(0.0337 * (y[38] + 3.0 * ISO + 25.0), 2.0)) + 0.02);
// 	ydot[10] = (dss - y[10]) / taud;   // derivative of d
// 	ydot[11] = (fss - y[11]) / tauf;   // derivative of f
// 	ydot[12] = 1.7 * y[1] / 1.0 * (1.0 - y[12]) - 11.9e-3 * y[12]; // derivative of fca_bj
// 	ydot[13] = 1.7 * y[2] / 1.0 * (1.0 - y[13]) - 11.9e-3 * y[13]; // derivative of fca_bsl
// 	ibark = pK * y[38] * Frdy * FoRT * (0.75 * y[27] * exp(y[38] * FoRT) - 0.75 * Ko) / (exp(y[38] * FoRT) - 1.0);
// 	ibarna_j = pNa * y[38] * Frdy * FoRT * (0.75 * y[31] * exp(y[38] * FoRT) - 0.75 * Nao) / (exp(y[38] * FoRT) - 1.0);
// 	ibarna_sl = pNa * y[38] * Frdy * FoRT * (0.75 * y[32] * exp(y[38] * FoRT) - 0.75 * Nao) / (exp(y[38] * FoRT) - 1.0);
// 	I_Ca = I_Ca_junc + I_Ca_sl;
// 	/***********************/

// 	I_CaK = ibark * y[10] * y[11] * (Fjunc_CaL * (fcaCaj + (1.0 - y[12])) + Fsl_CaL * (fcaCaMSL + (1.0 - y[13]))) * pow(Q10CaL, Qpow) * 0.45 * 1.0;
// 	I_CaNa_junc = Fjunc_CaL * ibarna_j * y[10] * y[11] * (1.0 - y[12] + fcaCaj) * pow(Q10CaL, Qpow) * 0.45 * 1.0;
// 	I_CaNa_sl = Fsl_CaL * ibarna_sl * y[10] * y[11] * (1.0 - y[13] + fcaCaMSL) * pow(Q10CaL, Qpow) * 0.45 * 1.0;
// 	I_CaNa = I_CaNa_junc + I_CaNa_sl;
// 	I_Catot = I_Ca + I_CaK + I_CaNa;
// 	I_cabk = I_cabk_junc + I_cabk_sl;
// 	I_ClCa_junc = Fjunc * GClCa / (1.0 + KdClCa / y[1]) * (y[38] - ecl);
// 	I_ClCa_sl = Fsl * GClCa / (1.0 + KdClCa / y[2]) * (y[38] - ecl);
// 	I_ClCa = I_ClCa_junc + I_ClCa_sl;
// 	I_Clbk = GClB * (y[38] - ecl);

// 	/* I_ki */
// 	ek = 1.0 / FoRT * log(Ko / y[27]);
// 	aki = 1.02 / (1.0 + exp(0.2385 * (y[38] - ek - 59.215)));
// 	bki = (0.49124 * exp(0.08032 * (y[38] + 5.476 - ek)) + exp(0.06175 * (y[38] - ek - 594.31))) / (1.0 + exp(-0.5143 * (y[38] - ek + 4.753)));
// 	kiss = aki / (aki + bki);
// 	I_ki = para[15] * (1.0 + 1.0 * AF) * 0.0525 * sqrt(Ko / 5.4) * kiss * (y[38] - ek);



// 	kp_kp = 1.0 / (1.0 + exp(7.488 - y[38] / 5.98));
// 	double I_kp_junc = Fjunc * gkp * kp_kp * (y[38] - ek);
// 	double I_kp_sl = Fsl * gkp * kp_kp * (y[38] - ek);
// 	I_kp = I_kp_junc + I_kp_sl;


// 	// I_kr
// 	gkr = 0.035 * sqrt(Ko / 5.4);
// 	xrss = 1.0 / (1.0 + exp(-(y[38] + 10.0) / 5.0));
// 	tauxr = 550.0 / (1.0 + exp((-22.0 - y[38]) / 9.0)) * 6.0 / (1.0 + exp((y[38] - (-11.0)) / 9.0)) + 230.0 / (1.0 + exp((y[38] - (-40.0)) / 20.0));
// 	ydot[14] = (xrss - y[14]) / tauxr;
// 	rkr = 1.0 / (1.0 + exp((y[38] + 74.0) / 24.0));
// 	I_kr = gkr * y[14] * rkr * (y[38] - ek);

// 	/*I_ks HH model*/
// 	gks_junc = para[11] * 1.0 * (1.0 + 1.0 * AF + 2.0 * ISO) * 0.0035;
// 	gks_sl = para[11] * 1.0 * (1.0 + 1.0 * AF + 2.0 * ISO) * 0.0035; // %FRA
// 	eks = 1.0 / FoRT * log((Ko + pNaK * Nao) / (y[27] + pNaK * y[30]));
// 	xsss = 1.0 / (1.0 + exp(-(y[38] + 40.0 * ISO + 3.8) / 14.25));
// 	tauxs = 990.1 / (1.0 + exp(-(y[38] + 40.0 * ISO + 2.436) / 14.12));
// 	ydot[15] = (xsss - y[15]) / tauxs;
// 	I_ks_junc = Fjunc * gks_junc * pow(y[15], 2.0) * (y[38] - eks);
// 	I_ks_sl = Fsl * gks_sl * pow(y[15], 2.0) * (y[38] - eks);
// 	I_ks = iksmultiply * (I_ks_junc + I_ks_sl);
// 	I_ncx = I_ncx_junc + I_ncx_sl;


// 	/* I_Na */
// 	mss = 1.0 / pow(1.0 + exp(-(56.86 + y[38]) / 9.03), 2.0);
// 	taum = 0.1292 * exp(-pow((y[38] + 45.79) / 15.54, 2.0)) + 0.06487 * exp(-pow((y[38] - 4.823) / 51.12, 2.0));

// 	/*if (y[38] >= -40.0)
// 	    ah = 0.0;
// 	else
// 	    ah = 0.057 * exp(-(y[38] + 80.0) / 6.8);*/

// 	ah = y[38] >= -40.0 ? 0.0 : 0.057 * exp(-(y[38] + 80.0) / 6.8);

// 	if (y[38] >= -40.0)
// 		bh = 0.77 / (0.13 * (1.0 + exp(-(y[38] + 10.66) / 11.1)));
// 	else
// 		bh = 2.7 * exp(0.079 * y[38]) + 3.1e5 * exp(0.3485 * y[38]);

// 	tauh = 1.0 / (ah + bh);
// 	//  hss = 1.0/pow(1.0+exp((y[38]+71.55)/7.43), 2.0);
// 	hss = (1.0 - ina_c) / pow(1 + exp((y[38] + 71.55) / 7.43), 2.0) + ina_c;

// 	if (y[38] >= -40.0)
// 		aj = 0.0;
// 	else
// 		aj = (-2.5428e4 * exp(0.2444 * y[38]) - 6.948e-6 * exp(-0.04391 * y[38])) * (y[38] + 37.78) / (1.0 + exp(0.311 * (y[38] + 79.23)));

// 	if (y[38] >= -40.0)
// 		bj = 0.6 * exp(0.057 * y[38]) / (1.0 + exp(-0.1 * (y[38] + 32.0)));
// 	else
// 		bj = 0.02424 * exp(-0.01052 * y[38]) / (1.0 + exp(-0.1378 * (y[38] + 40.14)));

// 	tauj = 1.0 / (aj + bj);
// 	//   jss = 1.0/pow(1.0+exp((y[38]+71.55)/7.43), 2.0);
// 	jss = (1.0 - ina_c) / pow(1 + exp((y[38] + 71.55) / 7.43), 2.0) + ina_c;

// 	ydot[18] = (mss - y[18]) / taum;
// 	ydot[16] = (hss - y[16]) / tauh;
// 	ydot[17] = (jss - y[17]) / tauj;

// 	ena_junc = 1.0 / FoRT * log(Nao / y[31]);
// 	I_Na_junc = Fjunc * GNa * pow(y[18], 3.0) * y[16] * y[17] * (y[38] - ena_junc);
// 	ena_sl = 1.0 / FoRT * log(Nao / y[32]);
// 	I_Na_sl = Fsl * GNa * pow(y[18], 3.0) * y[16] * y[17] * (y[38] - ena_sl);
// 	I_Na = I_Na_junc + I_Na_sl;


// 	/*late I_Na, only in AF condition*/
// 	// Matlab code, change to C when needed.
// 	//% Late I_Na
// 	double GNaL = 0 * para[16] * 0.0025/* * AF*/;  // 0* in AF
// 	double aml = 0.32 * (y[38] + 47.13) / (1.0 - exp(-0.1 * (y[38] + 47.13)));
// 	double bml = 0.08 * (exp(-y[38] / 11.0));
// 	double hlinf = 1.0 / (1.0 + exp((y[38] + 91.0) / 6.1));
// 	double tauhl = 600.0;
// 	ydot[41] = aml * (1.0 - y[41]) - bml * y[41];
// 	ydot[42] = (hlinf - y[42]) / tauhl;

// 	/*double*/ I_NaL_junc = Fjunc * GNaL * pow(y[41], 3.0) * y[42] * (y[38] - ena_junc);
// 	/*double*/ I_NaL_sl   = Fsl * GNaL * pow(y[41], 3.0) * y[42] * (y[38] - ena_sl);
// 	/*double*/ I_NaL      = I_NaL_junc + I_NaL_sl;





// 	I_nabk_junc = Fjunc * GNaB * (y[38] - ena_junc);
// 	I_nabk_sl = Fsl * GNaB * (y[38] - ena_sl);
// 	I_nabk = I_nabk_junc + I_nabk_sl;



// 	// I_nak % I_nak: Na/K Pump Current
// 	sigma = (exp(Nao / 67.3) - 1.0) / 7.0;
// 	fnak = 1.0 / (1.0 + 0.1245 * exp(-0.1 * y[38] * FoRT) + 0.0365 * sigma * exp(-y[38] * FoRT));
// 	I_nak_junc = Fjunc * IbarNaK * fnak * Ko / (1.0 + pow(KmNaip / y[31], 4.0)) / (Ko + KmKo);
// 	I_nak_sl = Fsl * IbarNaK * fnak * Ko / (1.0 + pow(KmNaip / y[32], 4.0)) / (Ko + KmKo);
// 	I_nak = I_nak_junc + I_nak_sl;



// 	I_pca = I_pca_junc + I_pca_sl;



// 	xtoss = 1.0 / (1.0 + exp(-(y[38] + 1.0) / 11.0)); // Haibo
// 	ytoss = 1.0 / (1.0 + exp((y[38] + 40.5) / 11.5)); // Haibo
// 	// tauxtos = 9.0 / (1.0 + exp((y[38] + 3.0) / 15.0)) + 0.5;
// 	// tauytos = 800.0 / (1.0 + exp((y[38] + 60.0) / 10.0)) + 30.0;
// 	ydot[20] = 0.0;//(xtoss - y[20]) / tauxtos;
// 	ydot[22] = 0.0;//(ytoss - y[22]) / tauytos;
// 	double I_tos = 0.0;// * GtoSlow * y[20] * y[22] * (y[38] - ek); // Haibo I_to slow has been removed


// 	// 11/12/09; changed Itof to that from maleckar/giles/2009; removed I_tos
// 	// atrium
// 	// equations for activation;
// 	// the Ito_f in atrium, time constant, by haibo
// 	// tauxtof = 3.5 / (1.0 + exp(- pow((y[38] / 30.0), 2.0))) + 1.5;    // for atrium  // former version, not right, haibo
// 	tauxtof = 3.5 * ( exp(- pow((y[38] / 30.0), 2.0))) + 1.5;    // for atrium
// 	// tauytof = 85.0 * exp(-pow(y[38] + 52.45, 2.0) / 15.8) + 24.14; // check haibo wrong version
// 	tauytof = 25.635 * exp(-(pow((y[38] + 52.45) / 15.8827, 2.0))) + 24.14; //%14.14  from matlab version
// 	GtoFast = para[12] * (1.0 - 0.7 * AF) * 0.165; // to be careful
// 	ydot[19] = (xtoss - y[19]) / tauxtof; // activation of Itof
// 	ydot[21] = (ytoss - y[21]) / tauytof; // inactivation of Itof by haibo

// 	I_tof = GtoFast * y[19] * y[21] * (y[38] - ek);
// 	I_to = I_tos + I_tof;
// 	ydot[25] = kon_sll * y[1] * (Bmax_SLlowj - y[25]) - koff_sll * y[25];
// 	ydot[26] = kon_sll * y[2] * (Bmax_SLlowsl - y[26]) - koff_sll * y[26];
// 	ydot[23] = kon_slh * y[1] * (Bmax_SLhighj - y[23]) - koff_slh * y[23];
// 	ydot[24] = kon_slh * y[2] * (Bmax_SLhighsl - y[24]) - koff_slh * y[24];




// 	//// I_kur: Ultra rapid delayed rectifier Outward K Current
// 	/* I_kur formulation 2, based on the original grandi model I_kur(from mal..2009)
// 	*   take mutation effects into consideration.
// 	*   modified by haibo
// 	*     */
// 	// original comments
// 	//Equation for I_kur; from Maleckar et al. 2009 - EG
// 	//atrium equations for activation;
// 	Gkur = para[14] * 1.0 * (1.0 - 0.5 * AF) * (1.0 + 2.0 * ISO) * 0.045 * (1.0 + 0.2 * RA); //*(1+0.2*RA); //nS/pF maleckar 0.045
// 	// Gkur = 0.5 * Gkur;
// 	tau_ac_Ikur = 9.0 / (1.0 + exp((y[38] + 5.0) / 12.0)) + 0.5;
// 	tau_inac_Ikur = 590.0 / (1.0 +  exp((y[38] + 60.0) / 10.0)) + 3050.0;
// 	// shift and change slope according to the effects of the mutations, by haibo
// 	ac_Ikur_inf = 1.0 / (1.0 + exp(-(y[38] + 6.0) / (8.6 )));
// 	inac_Ikur_inf = 1.0 / (1.0 + exp((y[38]  + 7.5) / (10.0 )));
// 	ydot[39] = (ac_Ikur_inf - y[39]) / tau_ac_Ikur;
// 	ydot[40] = (inac_Ikur_inf - y[40]) / tau_inac_Ikur;
// 	I_kur = Gkur * y[39] * y[40] * (y[38] - ek);
// 	// I_kur = Gkur * y[39] * y[40] * (y[38] - ek);





// 	I_K_tot = I_to + I_kr + I_ks + I_ki - 2.0 * I_nak + I_CaK + I_kp + I_kur;
// 	ydot[27] = 0.0;
// 	dNa_Bj_dt = kon_na * y[31] * (Bmax_Naj - y[28]) - koff_na * y[28];
// 	ydot[28] = dNa_Bj_dt;
// 	dNa_Bsl_dt = kon_na * y[32] * (Bmax_Nasl - y[29]) - koff_na * y[29];
// 	ydot[29] = dNa_Bsl_dt;
// 	I_Na_tot_junc = I_Na_junc + I_nabk_junc + 3.0 * I_ncx_junc + 3.0 * I_nak_junc + I_CaNa_junc + I_NaL_junc;
// 	I_Na_tot_sl = I_Na_sl + I_nabk_sl + 3.0 * I_ncx_sl + 3.0 * I_nak_sl + I_CaNa_sl + I_NaL_sl;
// 	// I_Na_tot_sl2 = 3.0 * I_ncx_sl + 3.0 * I_nak_sl + I_CaNa_sl;
// 	// I_Na_tot_junc2 = 3.0 * I_ncx_junc + 3.0 * I_nak_junc + I_CaNa_junc;
// 	ydot[31] = -I_Na_tot_junc * Cmem / (Vjunc * Frdy) + J_na_juncsl / Vjunc * (y[32] - y[31]) - dNa_Bj_dt;
// 	ydot[32] = -I_Na_tot_sl * Cmem / (Vsl * Frdy) + J_na_juncsl / Vsl * (y[31] - y[32]) + J_na_slmyo / Vsl * (y[30] - y[32]) - dNa_Bsl_dt;
// 	ydot[30] = J_na_slmyo / Vmyo * (y[32] - y[30]);
// 	ydot[34] = kon_csqn * y[33] * (Bmax_Csqn - y[34]) - koff_csqn * y[34];
// 	ydot[33] = J_serca - (J_SRleak * Vmyo / Vsr + J_SRCarel) - (kon_csqn * y[33] * (Bmax_Csqn - y[34]) - koff_csqn * y[34]);
// 	kCaSR = MaxSR - (MaxSR - MinSR) / (1.0 + pow(ec50SR / y[33], 2.5));
// 	koSRCa = koCa / kCaSR;
// 	kiSRCa = kiCa * kCaSR;
// 	RI = 1.0 - y[37] - y[36] - y[35];
// 	ydot[37] = kim * RI - kiSRCa * y[1] * y[37] - (koSRCa * pow(y[1], 2.0) * y[37] - kom * y[36]);
// 	ydot[36] = koSRCa * pow(y[1], 2.0) * y[37] - kom * y[36] - (kiSRCa * y[1] * y[36] - kim * y[35]);
// 	ydot[35] = kiSRCa * y[1] * y[36] - kim * y[35] - (kom * y[35] - koSRCa * pow(y[1], 2.0) * RI);





// 	/* I_clcfTR */
// 	GClCFTR = 0; //4.9e-3 * ISO;
// 	I_ClCFTR = GClCFTR * (y[38] - ecl);

// 	I_Na_tot = I_Na_tot_junc + I_Na_tot_sl;
// 	I_Cl_tot = I_ClCa + I_Clbk + I_ClCFTR;
// 	I_Ca_tot = I_Ca_tot_junc + I_Ca_tot_sl;
// 	I_tot = I_Na_tot + I_Cl_tot + I_Ca_tot + I_K_tot;

// 	double i_Stim = S1(20,  12.5,  BCL,  t,  5.0);
// 	ydot[38] = -(I_tot - i_Stim);

// 	I_app = i_Stim;

// 	dV = ydot[38];
// 	CaSR = y[33];
// 	Caj = y[1];
// 	Casl = y[2];
// 	Cai = y[0];
// 	Nai = y[30];
// 	Naj = y[31];
// 	Nasl = y[32];
// }



// void GB_ECC::initialiser() {
// 	y[0]   = 8.597401e-5;   ///    = 0.0040891;
// 	y[1]   = 1.737475e-4;   ///    = 0.9449988;
// 	y[2]   = 1.031812e-4;   ///    = 0.9622242;
// 	y[3]   = 2.911916e-4;   ///    = 0.0000084;
// 	y[4]   = 1.298754e-3;   ///    = 0.9994133;
// 	y[5]   = 1.381982e-1;   ///    = 0.0515998;
// 	y[6]   = 2.143165e-3;   ///    = 0.0362242;
// 	y[7]   = 1.078283e-1;   ///    = 0.0002035;
// 	y[8]   = 1.524002e-2;   ///    = 0.9567656;
// 	y[9]   = 8.773191e-3;   ///    = 0.0008244;
// 	y[10]  = 7.175662e-6;   ///    = 0.9662879;
// 	y[11]  = 1.000681;   ///    = 0.0025541;
// 	y[12]  = 2.421991e-2;   ///    = 0.0050455;
// 	y[13]  = 1.452605e-2;   ///    = 0.7883706;
// 	y[14]  = 8.641386e-3;   ///    = 0.0000028;
// 	y[15]  = 5.412034e-3;   ///    = 0.0000007;
// 	y[16]  = 9.867005e-1;   ///    = 3.7422141;
// 	y[17]  = 9.915620e-1;   ///    = 0.8166018;
// 	y[18]  = 1.405627e-3;   ///    = 0.0197666;
// 	y[19]  = 9.945511e-1;   ///    = 0.1290834;
// 	y[20]  = 4.051574e-3;   ///    = 0.0051135;
// 	y[21]  = 9.945511e-1;   ///    = 0.0007777;
// 	y[22]  = 9.945511e-1;   ///    = 0.0044295;
// 	y[23]  = 7.347888e-3;   ///    = 0.1350567;
// 	y[24]  = 7.297378e-2;   ///    = 0.0048088;
// 	y[25]  = 9.566355e-3;   ///    = 0.0156659;
// 	y[26]  = 1.110363e-1;   ///    = 0.0237294;
// 	y[27]  = 120.0;   ///    = 0.1109636;
// 	y[28]  = 3.539892;   ///    = 0.2020127;
// 	y[29]  = 7.720854e-1;   ///    = 1.1559742;
// 	y[30]  = 9.136;   ///    = 0.5203395;
// 	y[31]  = 9.136;   ///    = 9.7950634;
// 	y[32]  = 9.136;   ///    = 9.7950461;
// 	y[33]  = 0.01;   ///    = 9.7952094;
// 	y[34]  = 1.242988;   ///    =  120.0000000;
// 	y[35]  = 1.024274e-7;   ///    = 0.0003778;
// 	y[36]  = 8.156628e-7;   ///    = 0.0002588;
// 	y[37]  = 8.884332e-1;   ///    = 0.0002343;
// 	y[38]  = -8.09763e+1;   ///    = -79.1012084;
// 	y[39]  = 0.0;   ///    = 0.0040891;
// 	y[40]  = 1.0;   ///    = 0.1040307;
// 	y[41]  = 0;   ///    = 0.2013751;
// 	y[42]  = 0.2;   ///    = 0.2013751;
// }

