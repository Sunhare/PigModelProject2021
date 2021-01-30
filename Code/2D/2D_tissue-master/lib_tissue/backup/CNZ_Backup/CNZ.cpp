#include "CNZ.h"
#include "ExplicitSolver.hpp"
#define CNZ_CON_STATE_LENGTH (34)

// double crn_con(cell_params *params, double *state, double *results)
// double
// The current state of the model is stored in state, and all but the membrane
// potential is updated during the timestep, using the euler method for
// concentrations and the rush-larsen method for the gating parameters.
// constants
double static const    CRN_vcell = 20100.0; /* um3 */
double static const    CRN_vi = 13668;
double static const    CRN_vup = 1109.52/*0.0552*vcell*/;
double static const    CRN_vrel = 96.48/*0.0048*vcell*/;
double static const    T = 310; /* 37 Celcius */
double static const    CRN_Tfac = 3;
double static const    CRN_Csp = 1e+6; /* pF/cm2 */
double static const    F = 96.4867; /* coul/mmol */
double static const    R = 8.3143; /* J K-1 mol-1 */
double static const    CRN_kb = 5.4; /* mM */
double static const    CRN_nab = 140; /* mM */
double static const    CRN_cab = 1.8; /* mM */
double static const    CRN_nac = 140;
double static const    CRN_cac = 1.8;
double static const    CRN_kc = 5.4;
double static const    CRN_gna = 7.8; /* nS/pF */
double static const    CRN_gto = 0.1652; /* nS/pF */
double static const    CRN_gkr = 0.029411765; /* nS/pF */
double static const    CRN_gks = 0.12941176; /* nS/pF */
double static const    CRN_gcaL = 0.1294; /* nS/pF */
double static const    CRN_ErL = 65.0; /* mV */
double static const    CRN_gk1 = 0.09; /* nS/pF */
double static const    CRN_gbna = 0.0006744375; /* nS/pF */
double static const    CRN_gbk = 0.0;
double static const    CRN_gbca = 0.001131; /* nS/pF */
double static const    CRN_inakbar = 0.59933874; /* pA/pF */
double static const    CRN_kmnai = 10.0; /* mM */
double static const    CRN_kmko = 1.5; /* mM */
double static const    CRN_icapbar = 0.275; /* pA/pF */
double static const    CRN_kmcap = 0.0005; /* mM */
double static const    CRN_knacalr = 1600.0; /* pA/pF */
double static const    CRN_kmnalr = 87.5; /* mM */
double static const    CRN_kmcalr = 1.38; /* mM */
double static const    CRN_ksatlr = 0.1;
double static const    CRN_gammalr = 0.35;
double static const    CRN_trpnbar = 0.070; /* mM */
double static const    CRN_cmdnbar = 0.050; /* mM */
double static const    CRN_csqnbar = 10; /* mM */
double static const    CRN_kmcsqn = 0.8; /* mM */
double static const    CRN_kmcmdn = 0.00238; /* mM */
double static const    CRN_kmtrpn = 0.0005; /* mM */
double static const    CRN_grelbar = 30.0; /* ms-1 */
double static const    CRN_kmup = 0.00092; /* mM */
double static const    CRN_iupbar = 0.005; /* mM/ms */
double static const    CRN_caupmax = 15.0; /* mM */
double static const    CRN_kupleak = 0.00033333336/*iupbar/caupmax*/; /* ms-1 */
double static const    CRN_tautr = 180.0; /* ms */
double static const    CRN_gf_na = 0.0944;////0.10/* 0.09*/; /* nS/pF */
double static const    CRN_gf_k = /*0.0752*/ 0.0752;
double static const    CRN_gf = 0.025;//0.0752;
double static const    CRN_Ef = -22.0; /* mV */

double static const    gcaT = (0.15 * 0.22) / 17.62;
double static const    EcaT = 45.0;

double static const    MAL_gto = 0.75471 * 0.1962; //nS/pF **** in manuscript it is given in nS, so has been /100 here
// double static const    MAL_gto = 0.1962; //nS/pF **** in manuscript it is given in nS, so has been /100 here
double static const    MAL_gkur = 0.05874;
double static const    CNZ_gkur = 0.006398;

double static const    GONG_gto = 0.103;
double static const    gf = 0.0385;

// KM model intracellular model parameters
double static const Vss = 2 * 4.99232e-5;
double static const rjunct = 6.5;
double static const lcell = 122.051;

double static const dx = 1.625;

// Fibroblast stuff
double static const Cmf = 6.3; // pF
double static const vif = 0.00000137;//0.00000137;//0.00000000137; // um3  (from 0.00137 nL -> 0.00000137 nm3 -> 0.00000000137 um3
double static const naof = 130.0110; //mM
double static const kof = 5.3581; //mM


double static const Cm = 100.0;
// template <class Type>
double CNZ_ODE(double dt, double Istim, SingleCellPara & het, double *state) {


	double V = state[0];
	double m = state[1];
	double h = state[2];
	double j = state[3];
	double d = state[4];
	double f = state[5];
	double xr = state[6];
	double xs = state[7];
	double nai = state[8];
	double cai = state[9];
	double ki = state[10];
	double fca = state[11];
	double itr = state[12];
	double its = state[13];
	double isusr = state[14];
	double isuss = state[15];
	double Cass = state[16];
	double CaSR1 = state[17];
	double CaSR2 = state[18];
	double SERCACa = state[19];
	double SERCACass = state[20];
	double RyRoss = state[21];
	double RyRcss = state[22];
	double RyRass = state[23];
	double RyRo3 = state[24];
	double RyRc3 = state[25];
	double RyRa3 = state[26];
	double dd = state[27];
	double ff = state[28];
	double CNZ_a = state[29];
	double CNZ_i = state[30];
	double If_y = state[33];


	double Aj_nj = 2492.324412;// = M_PI*rjunct*2*lcell*0.5; // atea between junct and non junct
	double xj_nj = 0.822500;// = 0.02/2 + dx/2; // diffusion distance from center to center of junct to first njunct
	double xj_nj_Nai = 3.260000;// = 0.02/2 + 2*dx; // diffusion distance from center of junct to center of njunct (between 2nd and 3rd njunct)

	double Vnonjunct3 = 6 * 0.002531;
	double VSR3 = 2 * 0.000057;
	double VSR4 = 2 * 0.000080;
	double Vcytosol = 0.008150;
	double Vnonjunct_Nai = 0.008100;

	double BCa = 24e-3;
	double SLlow = 165;
	double SLhigh = 13;

	double KdBCa = 2.38e-3;
	double KdSLlow = 1.1;
	double KdSLhigh = 13e-3;

	double CSQN =  6.7;
	double KdCSQN = 0.8;

	double BNa = 1.1319;
	double KdBNa = 10;

	double DCa = 780;// % µm2/s
	double DCaSR = 44;//
	double DCaBm = 25; //% µm2/s

	double DNa = 0.12;

	double SERCAKmf = 0.25e-3;
	double SERCAKmr = 1.8;
	double k4 = 7.5 ;// % pump rate
	double k3 = 2.314815; //= k4 / SERCAKmr^2;
	double k1 = 7500000.000000;// = 1000^2 * k4;
	double k2 = 0.468750;// = k1 * SERCAKmf^2;
	double cpumps = 40e-3;
	double kSRleak = 6e-3;



	double Ena, Ek, Eca, Ekf, Enaf;
	double alpha, beta, tau, inf, a, b;
	double INa, IKr, IKs, ICaL, IK1, Iab, IbK, IbCa;
	double IbNa, ICap, INaCa, INaK, Ito, IKur, If, ICaT;
	double fnak, sigma;
	double naidot, kidot, caidot;


	// Reversal Potentials
	Ena = 26.71 * log(CRN_nac / nai);
	Ek = 26.71 * log(CRN_kc / ki);
	Eca = 13.35 * log(CRN_cac / cai);

	//INa
	INa = het.GNa * Cm * CRN_gna * m * m * m * h * j * (V - Ena);

	// m gate
	alpha =  0.32 * (V + 47.13) / (1 - exp(-0.1 * (V + 47.13)));
	if (fabs(V + 47.13) < 1e-10) alpha = 3.2;
	beta = 0.08 * exp(-V / 11.0);

	tau = 1 / (alpha + beta);
	inf = alpha * tau;

	m = inf + (m - inf) * exp(-dt/2.0 / tau); // steady state approx due to fast tau
	// m = inf + (m - inf) * exp(-dt / tau); // steady state approx due to fast tau
	m = inf + (m - inf) * exp(-dt/2.0 / tau); // steady state approx due to fast tau
	//m = table_row[INA_M_INF] + (m - table_row[INA_M_INF])*table_row[INA_M_TAU];

	// j gate
	if (V >= -40.0)
	{
		alpha  = 0.0;
		beta = 0.3 * exp(-2.535e-7 * V) / (1 + exp(-0.1 * (V + 32)));
	}
	else
	{
		alpha = (-1.2714e5 * exp(0.2444 * V) - 3.474e-5 * exp(-0.04391 * V)) * (V + 37.78) / (1 + exp(0.311 * (V + 79.23)));
		beta = 0.1212 * exp(-0.01052 * V) / (1 + exp(-0.1378 * (V + 40.14)));
	}
	tau = 1 / (alpha + beta);
	inf = alpha * tau;

	j = inf + (j - inf) * exp(-dt / tau);
	//j = table_row[INA_J_INF] + (j - table_row[INA_J_INF])*table_row[INA_J_TAU];

	// h gate
	if (V >= -40.0)
	{
		alpha  = 0.0;
		beta = 1 / (0.13 * (1 + exp((V + 10.66) / -11.1)));
	}
	else
	{
		alpha = 0.135 * exp((V + 80) / -6.8);
		beta = 3.56 * exp(0.079 * V) + 3.1e5 * exp(0.35 * V);
	}
	tau = 1 / (alpha + beta);
	inf = alpha * tau;

	h = inf + (h - inf) * exp(-dt / tau);
	//h = table_row[INA_H_INF] + (h - table_row[INA_H_INF])*table_row[INA_H_TAU];

	// IKr
	IKr = het.GKr * Cm * CRN_gkr * xr * (V - Ek) / (1 + exp((V + 15) / 22.4));

	// xr gate
	a = 0.0003 * (V + 14.1) / (1 - exp((V + 14.1) / -5));
	b = 0.000073898 * (V - 3.3328) / (exp((V - 3.3328) / 5.1237) - 1);
	if (fabs(V + 14.1) < 1e-10) a = 0.0015; /* denominator = 0 */
	if (fabs(V - 3.3328) < 1e-10) b = 3.7836118e-4; /* denominator = 0 */
	tau = 1 / (a + b);
	inf = 1 / (1 + exp((V + het.IKr_ac_shift + 14.1) / (-6.5 * het.IKr_grad)));
	xr = inf + (xr - inf) * exp(-dt / tau);

	// IKs
	IKs = het.GKs * Cm * CRN_gks * xs * xs * (V - Ek);

	// xs gate
	a = 0.00004 * (V - 19.9) / (1 - exp((V - 19.9) / -17));
	b = 0.000035 * (V - 19.9) / (exp((V - 19.9) / 9) - 1);
	if (fabs(V - 19.9) < 1e-10) // denominator = 0
	{
		a = 0.00068;
		b = 0.000315;
	}
	tau = 0.5 / (a + b); // note lagrer taus may be more accurate
	inf = sqrt(1 / (1 + exp((V - 19.9 - het.IKs_shift) / (-12.7 * het.IKs_grad))));
	xs = inf + (xs - inf) * exp(-dt / tau);
	//xs = table_row[IKS_INF] + (xs - table_row[IKS_INF])*table_row[IKS_TAU];
	//ICaL
	ICaL = 2.125 * het.GCaL * Cm * CRN_gcaL * d * f * fca * (V - CRN_ErL);

	// fca gate
	inf = 1 / (1 + (Cass / 0.00035));
	tau = 2.0;
	fca = inf + (fca - inf) * exp(-dt / tau);

	// d gate
	a = 1 / (1 + exp((V + 10) / -6.24));
	tau = a * (1 - exp((V + 10) / -6.24)) / (0.035 * (V + 10));
	if (fabs(V + 10) < 1e-10) tau = a * 4.579;
	inf = 1 / (1 + exp((V + 10) / -8));
	d = inf + (d - inf) * exp(-dt / tau);

	// f gate
	inf = exp(-(V + 28) / 6.9) / (1 + exp(-(V + 28) / 6.9));
	tau = 1.5 * 2 * 3 / (0.0197 * exp(-0.0337 * 0.0337 * (V + 10) * (V + 10)) + 0.02);
	f = inf + (f - inf) * exp(-dt / tau);

	//Ito
	Ito = het.Gto * Cm * MAL_gto * itr * its * (V - Ek);

	//r gate
	inf = 1.0 / (1.0 + exp((V - 1.0) / -11.0));
	tau = (0.0035 * exp(-(V / 30.0) * 2) + 0.0015);
	itr = inf + (itr - inf) * exp(-(dt / 1000) / tau);
	//itr = table_row[ITO_ITR_INF] + (itr - table_row[ITO_ITR_INF])*table_row[ITO_ITR_TAU];

	// s gate
	inf = 1.0 / (1.0 + exp((V + 40.5) / 11.5));
	tau = (0.025635 * exp (-((V + 52.45) / 15.8827) * 2) + 0.01414);
	its = inf + (its - inf) * exp(-(dt / 1000) / tau);
	//its = table_row[ITO_ITS_INF] + (its - table_row[ITO_ITS_INF])*table_row[ITO_ITS_TAU];

	//IKur
	IKur = het.GKur * Cm * CNZ_gkur * (4.5128 + 1.899769 / (1.0 + exp((V - 20.5232) / (-8.26597)))) * CNZ_a * CNZ_i * (V - Ek);
	// IKur = GKur * IKur;

	/*inf = 1 / (1 + exp(-(V + IKur_ac1_shift + 6) / (8.6 * IKur_ac1_grad)));
	tau = (0.009 / (1.0 + exp((V + 5) / 12)) + 0.0005);
	isusr = inf + (isusr - inf) * exp(-(dt / 1000) / tau);

	inf = 1 / (1 + exp((V + IKur_inac_shift + 7.5) / (10 * IKur_inac_grad)));
	tau = (0.59 / (1 + exp((V + 60.0) / 10)) + 3.05);
	isuss = inf + (isuss - inf) * exp(-(dt / 1000) / tau);*/

	double K_Q10 = 3.0;//3.5308257834747638;
	//CNZ_a
	inf = ((het.IKur_ac1_mult * 1.0) / (1 + exp((V + 17.6684 + het.IKur_ac1_shift) / (-5.75418 * het.IKur_ac1_grad))) ) * ((het.IKur_ac2_mult * 1.0) / (1 + exp((V + 8.4153 + het.IKur_ac2_shift) / (-11.51037561 * het.IKur_ac2_grad)))) + het.IKur_ac_add;
	tau = (45.6666746826 / (1 + exp((V + 11.2306497073) / 11.5254705962)) + 4.26753514993) * (0.262186042981 / (1 + exp((V + 35.8658312707) / (-3.87510627762))) + 0.291755017928); //
	tau = tau / K_Q10;

	CNZ_a = inf + (CNZ_a - inf) * exp(-(dt) / tau);

	// CNZ_i
	inf = (het.IKur_inac_mult * 0.52424) / (1.0 + exp((V + 15.1142 + het.IKur_inac_shift) / (7.567021 * het.IKur_inac_grad))) + 0.4580778 + het.IKur_inac_add;
	tau = 2328 / (1 + exp(((V) - 9.435) / (3.5827))) + 1739.139;
	tau = tau / K_Q10;


	CNZ_i = inf + (CNZ_i - inf) * exp(-(dt) / tau);



	//If
	If = het.Gf * Cm * CRN_gf * If_y * (V - (-22));

	//If y gate
	inf = 1 / (1 + exp((V + 90.95 + het.If_vshift) / (10.1 * het.If_grad))   );
	tau = 1 / (1.2783E-04 * exp(-V / 9.2424) + 121.6092 * exp(V / 9.2424)   );

	If_y = inf + (If_y - inf) * exp(-dt / tau);

	//ICaT
	ICaT = het.GCaT * Cm * gcaT * ff * dd * (V - EcaT);

	// dd gate
	a = 1.0680 * exp((V + 26.3) / 30.0);
	b  = 1.0680 * exp(-(V + 26.3) / 30.0);
	tau = 1.0 / (a + b);
	inf = 1.0 / (1.0 + exp(-(V + 37.0) / 6.8));
	dd = inf + (dd - inf) * exp(-dt / tau);

	// ff gate
	a = 0.0153 * exp(-(V + 71.0) / 83.3);
	b  = 0.0150 * exp((V + 71.0) / 15.38);
	tau = 1.0 / (a + b);
	inf = 1.0 / (1.0 + exp((V + 71.0) / 9.0));
	ff = inf + (ff - inf) * exp(-dt / tau);

	//IK1
	IK1 = het.GK1 * Cm * CRN_gk1 * (V - Ek + het.IK1_v_shift) / (1 + exp(0.07 * (V + 80 + het.IK1_v_shift)));
	//IK1 = GK1 * Cm * CRN_gk1 * (V-Ek+het.IK1_v_shift) * (het.IK1_type_default * (table_row[IK1_FAC]) + het.IK1_type_AS *(table_row[IK1_FAC_AS])  );

	//Iab
	Iab = Cm * 0.0003879 * (V + 69.6) / (1 - 0.8377 * exp((V + 49.06) / 1056));

	//Ibk
	IbK = Cm * CRN_gbk * (V - Ek);

	//IbCa
	IbCa = Cm * CRN_gbca * (V - Eca);

	// IbNa
	IbNa = Cm * CRN_gbna * (V - Ena);

	//ICap
	ICap = 1.4 * Cm * CRN_icapbar * Cass / (Cass + CRN_kmcap);

	//INaCa
	INaCa = het.GNaCa * Cm * CRN_knacalr / (pow(CRN_kmnalr, 3.0) + pow(CRN_nac, 3.0)) / (CRN_kmcalr + CRN_cac) /
	        (1 + CRN_ksatlr * exp((CRN_gammalr - 1) * V * F / (R * T))) *
	        (nai * nai * nai * CRN_cac * exp(V * CRN_gammalr * F / (R * T)) - CRN_nac * CRN_nac * CRN_nac * Cass *
	         exp(V * (CRN_gammalr - 1) * F / (R * T)));

	//INaK
	sigma = (exp(CRN_nac / 67.3) - 1) / 7.0;
	fnak = 1 / (1 + 0.1245 * exp(-0.1 * V * F / (R * T)) + 0.0365 * sigma * exp(-V * F / (R * T)));
	INaK = Cm * CRN_inakbar * fnak * CRN_kc / (CRN_kc + CRN_kmko) / (1 + pow(CRN_kmnai / nai, 1.5));


	// concentrations
	naidot = (-3 * INaK - 3 * INaCa - IbNa - INa) / (F * CRN_vi);
	kidot = (2 * INaK - IK1 - Ito - IKur - IKr - IKs - IbK) / (F * CRN_vi);
	nai = nai + dt * naidot;
	ki = ki + dt * kidot;

	//Calcium Handling
	double betass;
	betass = pow(( 1 + SLlow * KdSLlow / pow(((Cass) + KdSLlow), 2) + SLhigh * KdSLhigh / pow(((Cass) + KdSLhigh), 2) + BCa * KdBCa / pow(((Cass) + KdBCa), 2)  ), (-1));

	double betai, gammai;
	betai = pow(( 1 + BCa * KdBCa / pow((cai + KdBCa), 2)  ), (-1));
	gammai = BCa * KdBCa / pow((cai + KdBCa), 2);

	double betaSR1, betaSR2;
	betaSR1 = pow( ( 1 + CSQN * KdCSQN / pow((CaSR1 + KdCSQN), 2) ), (-1));
	betaSR2 = pow( ( 1 + CSQN * KdCSQN / pow((CaSR2 + KdCSQN), 2) ), (-1));

	double Jj_nj;
	Jj_nj = DCa * Aj_nj / xj_nj * ((Cass) - cai) * 1e-6;

	double J_SERCASR, J_bulkSERCA;
	double J_SERCASRss, J_bulkSERCAss;

	J_SERCASR =  (-k3 * pow(CaSR1, 2) * (cpumps - SERCACa) + k4 * (SERCACa)) * Vnonjunct3 * 2;
	J_bulkSERCA = (k1 * pow(cai, 2) * (cpumps - (SERCACa)) - k2 * (SERCACa)) * Vnonjunct3 * 2;

	J_SERCASRss = (-k3 * pow(CaSR2, 2) * (cpumps - (SERCACass)) + k4 * (SERCACass)) * Vss * 2;
	J_bulkSERCAss = (k1 * pow((Cass), 2) * (cpumps - (SERCACass)) - k2 * (SERCACass)) * Vss * 2;

	double RyRtauadapt = 1;

	double RyRtauactss = 5e-3;
	double RyRtauinactss = 15e-3;
	double  RyRtauact = 18.75e-3;
	double RyRtauinact = 87.5e-3;

	double nuss = 625 * Vss;
	double RyRSRCass = (1 - 1 / (1 +  exp((CaSR2 - 0.3) / 0.1)));
	double RyRainfss = 0.505 - 0.427 / (1 + exp((( Cass + (het.fRyR * Cass) ) * 1000 - 0.29) / 0.082));
	double RyRoinfss = (1 - 1 / (1 +  exp(((Cass + (het.fRyR * Cass)   ) * 1000 - ((RyRass) + 0.22)) / 0.03)));
	double RyRcinfss = (1 / (1 + exp(((Cass + (het.fRyR * Cass )) * 1000 - ((RyRass) + 0.02)) / 0.01)));
	double Jrelss = nuss * ( (RyRoss) ) * (RyRcss) * RyRSRCass * ( CaSR2 -  (Cass) );

	double nu3 = 1 * Vnonjunct3;
	double RyRSRCa3 = (1 - 1 / (1 +  exp((CaSR1 - 0.3) / 0.1)));
	double RyRainf3 =  0.505 - 0.427 / (1 + exp(( (cai + ( het.fRyR * cai)  ) * 1000 - 0.29) / 0.082));
	double RyRoinf3 = (1 - 1 / (1 +  exp(( (cai + ( het.fRyR * cai) ) * 1000 - ((RyRa3) + 0.22)) / 0.03)));
	double RyRcinf3 = (1 / (1 +  exp(( (cai + (het.fRyR * cai ) ) * 1000 - ((RyRa3) + 0.02)) / 0.01)));
	double Jrel3 = nu3 * ( (RyRo3) ) * (RyRc3) * RyRSRCa3 * ( CaSR1 -  cai );

	Jrelss = het.fIRel * Jrelss;
	Jrel3 = het.fIRel * Jrel3;

	double JSRCaleak3 = het.GSR_leak * kSRleak * ( CaSR1 - cai ) * Vnonjunct3;
	double JSRCaleakss = het.GSR_leak * kSRleak * ( CaSR2 - (Cass) ) * Vss;

	double JCa, JCass;
	JCa = -het.BULK_CONST * J_bulkSERCA + JSRCaleak3 + Jrel3 + Jj_nj;
	JCass = -Jj_nj + JSRCaleakss - het.BULK_CONST * J_bulkSERCAss + Jrelss;

	double JSRCa1, JSRCa2;
	JSRCa1 = J_SERCASR - JSRCaleak3 - Jrel3;
	JSRCa2 = J_SERCASRss - JSRCaleakss - Jrelss;

	double dy;

	dy = 0.5 * (-J_SERCASR + J_bulkSERCA) / Vnonjunct3;
	SERCACa = Foward_Euler(dt / 1000, dy, SERCACa);
	dy = 0.5 * (-J_SERCASRss + J_bulkSERCAss) / Vss;
	SERCACass = Foward_Euler(dt / 1000, dy, SERCACass);

	RyRoss = Euler_inf(dt / 1000, RyRoss, RyRoinfss, RyRtauactss);
	RyRcss = Euler_inf(dt / 1000, RyRcss, RyRcinfss, RyRtauinactss);
	RyRass = Euler_inf(dt / 1000, RyRass, RyRainfss, RyRtauadapt);
	RyRo3 = Euler_inf(dt / 1000, RyRo3, RyRoinf3, RyRtauact);
	RyRc3 = Euler_inf(dt / 1000, RyRc3, RyRcinf3, RyRtauinact);
	RyRa3 = Euler_inf(dt / 1000, RyRa3, RyRainf3, RyRtauadapt);

	dy =  betass * ( JCass / Vss + ((-( het.RyR * ICaL) - IbCa - ICap - ICaT + 2 * INaCa)) / (2 * Vss * 1000 * F) );
	Cass = Foward_Euler(dt / 1000, dy, Cass);

	dy = JCa / Vnonjunct3 * betai;
	cai = Foward_Euler(dt / 1000, dy, cai);

	dy =  betaSR1 * (DCaSR) * ( (CaSR2 - 2 * CaSR1 + CaSR1) / (dx * dx) + (CaSR1 - CaSR2) / (2 * 3 * (dx * dx)) ) + JSRCa1 / VSR3 * betaSR1;

	CaSR1 = Foward_Euler(dt, dy, CaSR1);

	dy = betaSR2 * (DCaSR) * ( (CaSR2 - 2 * CaSR2 + CaSR1) / (dx * dx) + (CaSR2 - CaSR1) / (2 * 4 * (dx * dx)) ) + JSRCa2 / VSR4 * betaSR2;

	CaSR2 = Foward_Euler(dt, dy, CaSR2);

	// return state variables
	state[1] = m;
	state[2] = h;
	state[3] = j;
	state[4] = d;
	state[5] = f;
	state[6] = xr;
	state[7] = xs;
	state[9] = cai;
	state[10] = ki;
	state[11] = fca;
	state[12] = itr;
	state[13] = its;
	state[14] = isusr;
	state[15] = isuss;
	state[16] = Cass;
	state[17] = CaSR1;
	state[18] = CaSR2;
	state[19] = SERCACa;
	state[20] = SERCACass;
	state[21] = RyRoss;
	state[22] = RyRcss;
	state[23] = RyRass;
	state[24] = RyRo3;
	state[25] = RyRc3;
	state[26] = RyRa3;
	state[27] = dd;
	state[28] = ff;
	state[29] = CNZ_a;
	state[30] = CNZ_i;

	state[33] = If_y;
	return (Istim + (INa + Ito + IKur + IKr + IKs + ICaL + IK1 + IbK + IbNa + IbCa + Iab + INaCa + INaK + ICap + If + ICaT ) / Cm);
} // end CNZ




void CNZ_ODE_Initialise(double *state, int celltype) {
	state[0] = -76.079842; // V
	state[1] = 0.006676; // m
	state[2] = 0.896736; // h
	state[3] = 0.918836; // j
	state[4] = 0.000259; // d
	state[5] = 0.999059; // f
	state[6] = 0.000072; // xr
	state[7] = 0.022846; // xs
	state[8] = 11.170000; // nai
	state[9] = 0.000098;  // Cai
	state[10] = 115.632438; // ki
	state[11] = 0.770253; // fca
	state[12] = 0.000905; // Itr
	state[13] = 0.956638; // Its
	state[14] = 0.000289; // Isusr
	state[15] = 0.998950; // Isuss
	state[16] = 0.000104; // Cass
	state[17] = 0.437859; // CaSR1
	state[18] = 0.434244; // CaSR2
	state[19] = 0.002432; // SERCACa
	state[20] = 0.002443; // SERCACass
	state[21] = 0.000412; // RyRoss
	state[22] = 0.967156; // RyRcss
	state[23] = 0.118222; // RyRass
	state[24] = 0.000365; // RyRo3
	state[25] = 0.977008; // RyRc3
	state[26] = 0.115451; // RyRa3
	state[27] = 0.003182; // dd
	state[28] = 0.637475; // ff
	state[29] = 0; // CNZ_a
	state[30] = 1;//0.9; // CNZ_i
	state[31] = 0; //ACh_i
	state[32] = 0; // ACh_j
	state[33] = 0; // if y
}


/*double Euler_inf(double dt, double gate, double inf, double tau) {
	gate = inf + (gate - inf) * exp(-(dt) / tau);
	return gate;
}

double Foward_Euler(double dt, double dy, double y) {
	double Y;
	Y = y + (dt) * dy;
	return Y;
}
*/

int cnz_con_length() {
    return CNZ_CON_STATE_LENGTH;
}

