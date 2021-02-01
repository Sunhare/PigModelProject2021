/* this model implements the mutation effects of G269S -IKs
mutation with suppressing the effects of PKA*/

/* mutation paper:A Molecular Mechanism for Adrenergic-Induced Long QT Syndrome
url: http://www.sciencedirect.com/science/article/pii/S0735109713057410
 */

/* implementation of PKA regulations:
Quantitative comparison of cardiac ventricular myocyte electrophysiology
and response to drugs in human and nonhuman species
url: http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3311457/

Arrhythmia formation in subclinical (“silent”) long QT syndrome requires multiple insults:
Quantitative mechanistic study using the KCNQ1 mutation Q357R as example
url: http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3443981/
*/

/*
 * This program re-implements in C++ the O'Hara-Rudy  ventricular cardiac myocyte model.
 *
 * Simulation of the undiseased human cardiac ventricular action potential: model formulation and experimental validation.
 * O'Hara T, Virág L, Varró A, Rudy Y.
 * PLoS Comput Biol. 2011 May;7(5):e1002061. doi: 10.1371/journal.pcbi.1002061. Epub 2011 May 26.
 *
 * Author (this version)    : Ismail Adeniran <ismail.adeniran@gmail.com>
 * Date                 : 2011
 * Date Modified                : 16-10-2013
 *
 * Compile with         : g++ -O3 -m64 -o ordcell ORdCell.cpp
 */

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

#include "EnumSimulationCtrl.hpp"
//===========
// Cell types
//===========
// enum TypeCell { RVEPI, RVMCELL, RVENDO, LVEPI, LVMCELL, LVENDO };
enum class IKsMutation {WT, WT_G269S, G269S };

class ORDCell {
public:
	ORDCell( TypeCell celltype = LVENDO, double time_step = 0.005, IKsMutation mutation = IKsMutation::WT, bool ISO = false) {
		CL           = 1000; //pacing cycle length
		dia          = CL;
		repeats      = 10;
		ft           = repeats * CL + dia; //final time
		skip         = 10;                   //number of timesetps to skip in sampling of data in output file
		safetime     = 25.0;            //time from the beginning of each beat during which dt is fixed to small values
		beatssave    = 10;             //number of beats to save in the output

		amp          = -80;              //stimulus amplitude in uA/uF
		start        = 0;                    //start time of the stimulus, relative to each beat
		duration     = 0.5;             //duration of teh stimulus in ms
		tend         = start + duration;
		beat_counter = 1;

		m_celltype   = celltype;
		m_mutation = mutation;
		m_ISO = ISO;

		state_initialise();

		if (m_celltype == LVENDO) {
			read_in_init_value("LVENDO_ini.dat");
		}
		if (m_celltype == LVMCELL) {
			read_in_init_value("LVMCELL_ini.dat");
		}
		if (m_celltype == LVEPI) {
			read_in_init_value("LVEPI_ini.dat");
		}
		// Introduce APD, timing, and counting parameters
		APD_flag    = 0;
		vo      = v;
		dt      = time_step;//0.005;
		t0      = 0;
		t       = 0;
		vdot        = 0;
		p       = 1;
		n       = 0;
		count   = 1;

		counter = 1;
		dvdt = 0;
	}

	void state_initialise() {
		// Initial values for state variables, there are 41 of them.
		v      = -87.5;
		nai    = 7;
		nass   = nai;
		ki     = 145;
		kss    = ki;
		cai    = 1.0e-4;
		cass   = cai;
		cansr  = 1.2;
		cajsr  = cansr;
		m      = 0;
		hf     = 1;
		hs     = 1;
		j      = 1;
		hsp    = 1;
		jp     = 1;
		mL     = 0;
		hL     = 1;
		hLp    = 1;
		a      = 0;
		iF     = 1;
		iS     = 1;
		ap     = 0;
		iFp    = 1;
		iSp    = 1;
		d      = 0;
		ff     = 1;
		fs     = 1;
		fcaf   = 1;
		fcas   = 1;
		jca    = 1;
		nca    = 0;
		ffp    = 1;
		fcafp  = 1;
		xrf    = 0;
		xrs    = 0;
		xs1    = 0;
		xs2    = 0;
		xk1    = 1;
		Jrelnp = 0;
		Jrelp  = 0;

		CaMKt  = 0;

		/* ICaL pka*/
		d_pPKA    = 0;
		ff_pPKA   = 1;
		fs_pPKA   = 1;
		fcaf_pPKA = 1;
		fcas_pPKA = 1;
		jca_pPKA  = 1;
		nca_pPKA  = 0;
		/*IKs pka*/
		xs1_pPKA = 0;

		/*INa pka */
		j_pPKA = 1;
		hf_pPKA = 1;
		hs_pPKA = 1;
		hsp_pPKA = 1;
		jp_pPKA = 1;

		/* Jrel PKA*/
		Jrel_pPKA = 0.0;
		Jrelp_pPKA = 0.0;


		// Constants
		nao = 140.0; //extracellular sodium in mM
		cao = 1.8;      //extracellular calcium in mM
		ko = 5.4;   //extracellular potassium in mM


		if (m_ISO) {
			fLCC_PKA  = 1.0;
			fKb_PKA   = 1.0;
			fNa_PKA   = 1.0;
			fJrel_PKA = 1.0;
			fJup_PKA  = 1.0;
			fTron_PKA = 1.0;
			fNaK_PKA  = 1.0;
			if (m_mutation == IKsMutation::WT) {
				fKs_PKA   = 1.0;
			} else if (m_mutation == IKsMutation::WT_G269S) {
				fKs_PKA   = 0.5;
			} else if (m_mutation == IKsMutation::G269S) {
				fKs_PKA   = 0.0;
			}
		} else {
			fLCC_PKA  = 0.0;
			fKs_PKA   = 0.0;
			fKb_PKA   = 0.0;
			fNa_PKA   = 0.0;
			fJrel_PKA = 0.0;
			fJup_PKA  = 0.0;
			fTron_PKA = 0.0;
			fNaK_PKA  = 0.0;
		}


		fca_pPKA  = 0;
		f_pPKA    = 0;

		// Buffer paramaters
		BSRmax = 0.047;
		KmBSR = 0.00087;
		BSLmax = 1.124;
		KmBSL = 0.0087;
		cmdnmax = 0.05;
		kmcmdn = 0.00238;
		trpnmax = 0.07;
		kmtrpn = 0.0005;
		csqnmax = 10.0;
		kmcsqn = 0.8;

		// CaMK paramaters
		aCaMK = 0.05;
		bCaMK = 0.00068;
		CaMKo = 0.05;
		KmCaM = 0.0015;
		KmCaMK = 0.15;

		// Physical constants
		R = 8314.0;
		T = 310.0;
		F = 96485.0;

		// Cell geometry
		L = 0.01;
		rad = 0.0011;
		vcell = 1000 * 3.14 * rad * rad * L;
		Ageo = 2 * 3.14 * rad * rad + 2 * 3.14 * rad * L;
		Acap = 2 * Ageo;
		vmyo = 0.68 * vcell;
		vmito = 0.26 * vcell;
		vsr = 0.06 * vcell;
		vnsr = 0.0552 * vcell;
		vjsr = 0.0048 * vcell;
		vss = 0.02 * vcell;
	}

	void revpots() {
		ENa = (R * T / F) * log(nao / nai);
		EK = (R * T / F) * log(ko / ki);
		EKs = (R * T / F) * log((ko + 0.01833 * nao) / (ki + 0.01833 * nai));
	}

	void RGC() {
		CaMKb = CaMKo * (1.0 - CaMKt) / (1.0 + KmCaM / cass);
		CaMKa = CaMKb + CaMKt;
		vffrt = v * F * F / (R * T);
		vfrt = v * F / (R * T);
		// Compute_INa();
		Compute_TNNP_INa();
		Compute_INaL();
		Compute_Ito();
		Compute_ICaL();
		Compute_IKr();
		// std::cout <<"a";
		// Compute_IKs();
		Compute_Mutation_IKs();
		Compute_INaK();
		Compute_INaCa();
		Compute_IK1();
		Compute_IpCa();
		Compute_Ibackgroud();
	}
	void Compute_INa() {
		mss = 1.0 / (1.0 + exp((-(v + 39.57)) / 9.871));
		tm = 1.0 / (6.765 * exp((v + 11.64) / 34.77) + 8.552 * exp(-(v + 77.42) / 5.955));
		m = mss - (mss - m) * exp(-dt / tm);
		// m = mss;
		hss = 1.0 / (1 + exp((v + 82.90) / 6.086));
		thf = 1.0 / (1.432e-5 * exp(-(v + 1.196) / 6.285) + 6.149 * exp((v + 0.5096) / 20.27));
		ths = 1.0 / (0.009794 * exp(-(v + 17.95) / 28.05) + 0.3343 * exp((v + 5.730) / 56.66));
		Ahf = 0.99;
		Ahs = 1.0 - Ahf;
		hf = hss - (hss - hf) * exp(-dt / thf);
		hs = hss - (hss - hs) * exp(-dt / ths);
		h = Ahf * hf + Ahs * hs;
		jss = hss;
		tj = 2.038 + 1.0 / (0.02136 * exp(-(v + 100.6) / 8.281) + 0.3052 * exp((v + 0.9941) / 38.45));
		j = jss - (jss - j) * exp(-dt / tj);
		hssp = 1.0 / (1 + exp((v + 89.1) / 6.086));
		thsp = 3.0 * ths;
		hsp = hssp - (hssp - hsp) * exp(-dt / thsp);
		hp = Ahf * hf + Ahs * hsp;
		tjp = 1.46 * tj;
		jp = jss - (jss - jp) * exp(-dt / tjp);
		GNa = 75;
		/* PKA */
		hss = 1.0 / (1 + exp((v + 82.90 + 5.0) / 6.086));  // no change to the time constants
		/*thf = 1.0 / (1.432e-5 * exp(-(v + 1.196) / 6.285) + 6.149 * exp((v + 0.5096) / 20.27));
		ths = 1.0 / (0.009794 * exp(-(v + 17.95) / 28.05) + 0.3343 * exp((v + 5.730) / 56.66));*/
		Ahf = 0.99;
		Ahs = 1.0 - Ahf;
		hf_pPKA = hss - (hss - hf_pPKA) * exp(-dt / thf);
		hs_pPKA = hss - (hss - hs_pPKA) * exp(-dt / ths);
		double h_pPKA = Ahf * hf_pPKA + Ahs * hs_pPKA;
		jss = hss;
		// tj = 2.038 + 1.0 / (0.02136 * exp(-(v + 100.6) / 8.281) + 0.3052 * exp((v + 0.9941) / 38.45));
		j_pPKA = jss - (jss - j_pPKA) * exp(-dt / tj);



		/* PKA and CAM binding */
		hss = 1.0 / (1 + exp((v + 89.1 + 5.0) / 6.086));
		thsp = 3.0 * ths;
		hsp_pPKA = hss - (hss - hsp_pPKA) * exp(-dt / thsp);
		double hp_pPKA = Ahf * hf_pPKA + Ahs * hsp_pPKA;
		tjp = 1.46 * tj;
		jss = hss;
		jp_pPKA = jss - (jss - jp_pPKA) * exp(-dt / tjp);
		double GNa_PKA = GNa * 2.7;


		fINap = (1.0 / (1.0 + KmCaMK / CaMKa));
		double fNa_both = fINap * fNa_PKA;
		double fNa_PKA_only = fNa_PKA - fNa_both;
		double fNa_CaM_only = fINap - fNa_both;
		double fNa_NonP = 1 - fNa_both -  fNa_PKA_only - fNa_CaM_only;

		INa =  GNa * (v - ENa) * m * m * m * (fNa_NonP * h * j + fNa_CaM_only * hp * jp) +
		       GNa_PKA * (v - ENa) * m * m * m * (fNa_PKA_only * h_pPKA * j_pPKA + fNa_both * hp_pPKA * jp_pPKA);
	}
	void Compute_TNNP_INa() {
		// m = mss - (mss - m) * exp(-dt / tm);
		double AM = 1. / (1. + std::exp((-60. - v) / 5.));
		double BM = 0.1 / (1. + std::exp((v + 35.) / 5.)) + 0.10 / (1. + std::exp((v - 50.) / 200.));
		double TAU_M = AM * BM;
		double M_INF = 1. / ((1. + std::exp((-56.86 - v) / 9.03)) * (1. + std::exp((-56.86 - v) / 9.03)));
		m = M_INF - (M_INF - m) * exp(-dt / M_INF);
		// m = mss;


		double TAU_H;
		double TAU_J;
		if (v >= -40.) {
			double AH_1 = 0.;
			double BH_1 = (0.77 / (0.13 * (1. + std::exp(-(v + 10.66) / 11.1))));
			TAU_H = 1.0 / (AH_1 + BH_1);
		} else {
			double AH_2 = (0.057 * std::exp(-(v + 80.) / 6.8));
			double BH_2 = (2.7 * std::exp(0.079 * v) + (3.1e5) * std::exp(0.3485 * v));
			TAU_H = 1.0 / (AH_2 + BH_2);
		}
		thf = TAU_H;
		ths = 1.0 / (0.009794 * exp(-(v + 17.95) / 28.05) + 0.3343 * exp((v + 5.730) / 56.66));
		hss = 1. / ((1. + std::exp((v + 71.55) / 7.43)) * (1. + std::exp((v + 71.55) / 7.43)));


		Ahf = 0.99;
		Ahs = 1.0 - Ahf;
		hf = hss - (hss - hf) * exp(-dt / thf);
		hs = hss - (hss - hs) * exp(-dt / ths);
		h = Ahf * hf + Ahs * hs;
		jss = hss;
		tj = 2.038 + 1.0 / (0.02136 * exp(-(v + 100.6) / 8.281) + 0.3052 * exp((v + 0.9941) / 38.45));
		j = jss - (jss - j) * exp(-dt / tj);
		hssp = 1.0 / (1 + exp((v + 89.1) / 6.086));
		thsp = 3.0 * ths;
		hsp = hssp - (hssp - hsp) * exp(-dt / thsp);
		hp = Ahf * hf + Ahs * hsp;
		tjp = 1.46 * tj;
		jp = jss - (jss - jp) * exp(-dt / tjp);
		GNa = 75;
		/* PKA */
		hss = 1.0 / (1 + exp((v + 82.90 + 5.0) / 6.086));  // no change to the time constants
		/*thf = 1.0 / (1.432e-5 * exp(-(v + 1.196) / 6.285) + 6.149 * exp((v + 0.5096) / 20.27));
		ths = 1.0 / (0.009794 * exp(-(v + 17.95) / 28.05) + 0.3343 * exp((v + 5.730) / 56.66));*/
		Ahf = 0.99;
		Ahs = 1.0 - Ahf;
		hf_pPKA = hss - (hss - hf_pPKA) * exp(-dt / thf);
		hs_pPKA = hss - (hss - hs_pPKA) * exp(-dt / ths);
		double h_pPKA = Ahf * hf_pPKA + Ahs * hs_pPKA;
		jss = hss;
		// tj = 2.038 + 1.0 / (0.02136 * exp(-(v + 100.6) / 8.281) + 0.3052 * exp((v + 0.9941) / 38.45));
		j_pPKA = jss - (jss - j_pPKA) * exp(-dt / tj);



		/* PKA and CAM binding */
		hss =  1. / ((1. + std::exp((v + 71.55+5.0) / 7.43)) * (1. + std::exp((v + 71.55+5.0) / 7.43)));
		thsp = 3.0 * ths;
		hsp_pPKA = hss - (hss - hsp_pPKA) * exp(-dt / thsp);
		double hp_pPKA = Ahf * hf_pPKA + Ahs * hsp_pPKA;
		tjp = 1.46 * tj;
		jss = hss;
		jp_pPKA = jss - (jss - jp_pPKA) * exp(-dt / tjp);
		// double GNa_PKA = GNa * 2.7;
		double GNa_PKA = GNa * 1.5;


		fINap = (1.0 / (1.0 + KmCaMK / CaMKa));
		double fNa_both = fINap * fNa_PKA;
		double fNa_PKA_only = fNa_PKA - fNa_both;
		double fNa_CaM_only = fINap - fNa_both;
		double fNa_NonP = 1 - fNa_both -  fNa_PKA_only - fNa_CaM_only;

		INa =  GNa * (v - ENa) * m * m * m * (fNa_NonP * h * j + fNa_CaM_only * hp * jp) +
		       GNa_PKA * (v - ENa) * m * m * m * (fNa_PKA_only * h_pPKA * j_pPKA + fNa_both * hp_pPKA * jp_pPKA);
	}

	void Compute_INaL() {
		mLss = 1.0 / (1.0 + exp((-(v + 42.85)) / 5.264));
		tmL = tm;
		mL = mLss - (mLss - mL) * exp(-dt / tmL);
		hLss = 1.0 / (1.0 + exp((v + 87.61) / 7.488));
		thL = 200.0;
		hL = hLss - (hLss - hL) * exp(-dt / thL);
		hLssp = 1.0 / (1.0 + exp((v + 93.81) / 7.488));
		thLp = 3.0 * thL;
		hLp = hLssp - (hLssp - hLp) * exp(-dt / thLp);
		GNaL = 0.0075;
		if ( m_celltype == LVEPI ) {
			GNaL *= 0.6;
		}
		fINaLp = (1.0 / (1.0 + KmCaMK / CaMKa));
		INaL = GNaL * (v - ENa) * mL * ((1.0 - fINaLp) * hL + fINaLp * hLp);
	}
	void Compute_Ito() {

		ass = 1.0 / (1.0 + exp((-(v - 14.34)) / 14.82));
		ta = 1.0515 / (1.0 / (1.2089 * (1.0 + exp(-(v - 18.4099) / 29.3814))) + 3.5 / (1.0 + exp((v + 100.0) / 29.3814)));
		a = ass - (ass - a) * exp(-dt / ta);
		iss = 1.0 / (1.0 + exp((v + 43.94) / 5.711));
		delta_epi;
		if ( m_celltype == LVEPI ) {
			delta_epi = 1.0 - (0.95 / (1.0 + exp((v + 70.0) / 5.0)));
		} else {
			delta_epi = 1.0;
		}
		tiF = 4.562 + 1 / (0.3933 * exp((-(v + 100.0)) / 100.0) + 0.08004 * exp((v + 50.0) / 16.59));
		tiS = 23.62 + 1 / (0.001416 * exp((-(v + 96.52)) / 59.05) + 1.780e-8 * exp((v + 114.1) / 8.079));
		tiF *= delta_epi;
		tiS *= delta_epi;
		AiF = 1.0 / (1.0 + exp((v - 213.6) / 151.2));
		AiS = 1.0 - AiF;
		iF = iss - (iss - iF) * exp(-dt / tiF);
		iS = iss - (iss - iS) * exp(-dt / tiS);
		i = AiF * iF + AiS * iS;
		assp = 1.0 / (1.0 + exp((-(v - 24.34)) / 14.82));
		ap = assp - (assp - ap) * exp(-dt / ta);
		dti_develop = 1.354 + 1.0e-4 / (exp((v - 167.4) / 15.89) + exp(-(v - 12.23) / 0.2154));
		dti_recover = 1.0 - 0.5 / (1.0 + exp((v + 70.0) / 20.0));
		tiFp = dti_develop * dti_recover * tiF;
		tiSp = dti_develop * dti_recover * tiS;
		iFp = iss - (iss - iFp) * exp(-dt / tiFp);
		iSp = iss - (iss - iSp) * exp(-dt / tiSp);
		ip = AiF * iFp + AiS * iSp;
		Gto = 0.02;
		if ( m_celltype == LVENDO )
			Gto = 0.02;
		else if ( m_celltype == RVENDO )
			Gto = 0.02 * 4.0;
		else if ( m_celltype == LVEPI or m_celltype == LVMCELL ) {
			Gto = 0.02 * 4.0;
			// Gto = 0.02;
		} else if ( m_celltype == RVEPI or m_celltype == RVMCELL ) {
			Gto = 0.02 * 4.0 * 4.0;
		}
		fItop = (1.0 / (1.0 + KmCaMK / CaMKa));
		Ito = Gto * (v - EK) * ((1.0 - fItop) * a * i + fItop * ap * ip);
	}


	void Compute_ICaL() {

		/*ICaL */     // IcaL, CaK, CaNa
		double cass_for_LCC = cass;
		if (cass_for_LCC >= 0.015) {
			cass_for_LCC = 0.015;    // 0.03 mM ceiling for cass in sLCC
		}

		fICaLp = (1.0 / (1.0 + KmCaMK / CaMKa));  // fraction with CaMKII
		double fLCC_both = fLCC_PKA * fICaLp;
		double fLCC_PKA_only = fLCC_PKA - fLCC_both;
		double fLCC_CAMK_only = fICaLp - fLCC_both;
		double fLCC_NP = 1 - fLCC_both - fLCC_PKA_only - fLCC_CAMK_only;

		dss = 1.0 / (1.0 + exp((-(v + 3.940)) / 4.230));
		td = 0.6 + 1.0 / (exp(-0.05 * (v + 6.0)) + exp(0.09 * (v + 14.0)));
		d = dss - (dss - d) * exp(-dt / td);
		fss = 1.0 / (1.0 + exp((v + 19.58) / 3.696));
		tff = 7.0 + 1.0 / (0.0045 * exp(-(v + 20.0) / 10.0) + 0.0045 * exp((v + 20.0) / 10.0));
		tfs = 1000.0 + 1.0 / (0.000035 * exp(-(v + 5.0) / 4.0) + 0.000035 * exp((v + 5.0) / 6.0));
		Aff = 0.6;
		Afs = 1.0 - Aff;
		ff = fss - (fss - ff) * exp(-dt / tff);
		fs = fss - (fss - fs) * exp(-dt / tfs);
		f = Aff * ff + Afs * fs;
		fcass = fss;
		tfcaf = 7.0 + 1.0 / (0.04 * exp(-(v - 4.0) / 7.0) + 0.04 * exp((v - 4.0) / 7.0));
		tfcas = 100.0 + 1.0 / (0.00012 * exp(-v / 3.0) + 0.00012 * exp(v / 7.0));
		Afcaf = 0.3 + 0.6 / (1.0 + exp((v - 10.0) / 10.0));
		Afcas = 1.0 - Afcaf;
		fcaf = fcass - (fcass - fcaf) * exp(-dt / tfcaf);
		fcas = fcass - (fcass - fcas) * exp(-dt / tfcas);
		fca = Afcaf * fcaf + Afcas * fcas;
		tjca = 75.0;
		jca = fcass - (fcass - jca) * exp(-dt / tjca);
		tffp = 2.5 * tff;
		ffp = fss - (fss - ffp) * exp(-dt / tffp);
		fp = Aff * ffp + Afs * fs;
		tfcafp = 2.5 * tfcaf;
		fcafp = fcass - (fcass - fcafp) * exp(-dt / tfcafp);
		fcap = Afcaf * fcafp + Afcas * fcas;
		Kmn = 0.002;
		k2n = 1000.0;
		km2n = jca * 1.0;
		anca = 1.0 / (k2n / km2n + pow(1.0 + Kmn / cass_for_LCC, 4.0));
		nca = anca * k2n / km2n - (anca * k2n / km2n - nca) * exp(-km2n * dt);
		PhiCaL = 4.0 * vffrt * (cass_for_LCC * exp(2.0 * vfrt) - 0.341 * cao) / (exp(2.0 * vfrt) - 1.0);
		PhiCaNa = 1.0 * vffrt * (0.75 * nass * exp(1.0 * vfrt) - 0.75 * nao) / (exp(1.0 * vfrt) - 1.0);
		PhiCaK = 1.0 * vffrt * (0.75 * kss * exp(1.0 * vfrt) - 0.75 * ko) / (exp(1.0 * vfrt) - 1.0);
		zca = 2.0;
		PCa = 0.0001;
		double PCa_ori = PCa;
		if ( m_celltype == LVEPI or m_celltype == RVEPI ) {
			PCa *= 1.2;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			PCa *= 2.5;
		}
		PCap = 1.1 * PCa;
		PCaNa = 0.00125 * PCa;
		PCaK = 3.574e-4 * PCa;
		PCaNap = 0.00125 * PCap;
		PCaKp = 3.574e-4 * PCap;
		double ICaL_NP = fLCC_NP * PCa * PhiCaL * d * (f * (1.0 - nca) + jca * fca * nca) ;
		double ICaL_CaMK = fLCC_CAMK_only * PCap * PhiCaL * d * (fp * (1.0 - nca) + jca * fcap * nca);
		double ICaNa_NonPKA = (1.0 - fICaLp) * PCaNa * PhiCaNa * d * (f * (1.0 - nca) + jca * fca * nca) + fICaLp * PCaNap * PhiCaNa * d * (fp * (1.0 - nca) + jca * fcap * nca);
		double ICaK_NonPKA = (1.0 - fICaLp) * PCaK * PhiCaK * d * (f * (1.0 - nca) + jca * fca * nca) + fICaLp * PCaKp * PhiCaK * d * (fp * (1.0 - nca) + jca * fcap * nca);

		// ISO phos ff_pPKA gate
		dss   = 1.0 / (1.0 + exp((-(v + 3.940 + 3.0)) / 4.230));   // change to 8 will give good results  // the original value from rudy paper was 16.0
		/*Figure 3 in paper 		// from  paper : Chen et al. L-Type Ca2+ Channel Density and Regulation Are Altered in Failing Human Ventricular Myocytes and Recover After Support With Mechanical Assist Devices
		ISO caused a significant leftward shift of the voltage dependence of I Ca,L activation in
		NF- (change of V 0.5 (dρ): -9.9 mV; PϽ0.05) and LVAD- (change of V 0.5 (dρ): -5.8 mV; P0.05) HVMs but no significant shift in F- (change of V 0.5 (dρ): -2.2 mV; PϾ0.05) HVMs.*/
		// td    = 0.6 + 1.0 / (exp(-0.05 * (v + 6.0 + 16.0)) + exp(0.09 * (v + 14.0 + 16.0)));  // in the rudy paper, the td was not changed by pka..
		d_pPKA = dss - (dss - d_pPKA) * exp(-dt / td);

		double fss_PKA = 1.0 / (1.0 + exp((v + 19.58 + 2.8) / 3.696));    // in the paper, no change to the time constants here.
		double tff_pPKA =  0.6 * tff; // ISO caused significant acceleration in inactivation of ICaL,
		// from Figure 4.  paper : Chen et al. L-Type Ca2+ Channel Density and Regulation Are Altered in Failing Human Ventricular Myocytes and Recover After Support With Mechanical Assist Devices
		//in control tff_pPKA was  7.0 + 1.0 / (0.0045 * exp(-(v + 20.0) / 10.0) + 0.0045 * exp((v + 20.0) / 10.0));
		tfs = 1000.0 + 1.0 / (0.000035 * exp(-(v + 5.0) / 4.0) + 0.000035 * exp((v + 5.0) / 6.0));
		Aff = 0.6;
		Afs = 1.0 - Aff;
		ff_pPKA = fss_PKA - (fss_PKA - ff_pPKA) * exp(-dt / tff_pPKA);
		fs_pPKA = fss_PKA - (fss_PKA - fs_pPKA) * exp(-dt / tfs);
		f_pPKA = Aff * ff_pPKA + Afs * fs_pPKA;
		fcass = fss_PKA;
		tfcaf = 7.0 + 1.0 / (0.04 * exp(-(v - 4.0) / 7.0) + 0.04 * exp((v - 4.0) / 7.0));
		tfcas = 100.0 + 1.0 / (0.00012 * exp(-v / 3.0) + 0.00012 * exp(v / 7.0));
		Afcaf = 0.3 + 0.6 / (1.0 + exp((v - 10.0) / 10.0));
		Afcas = 1.0 - Afcaf;
		fcaf_pPKA = fcass - (fcass - fcaf_pPKA) * exp(-dt / tfcaf);
		fcas_pPKA = fcass - (fcass - fcas_pPKA) * exp(-dt / tfcas);
		fca_pPKA = Afcaf * fcaf_pPKA + Afcas * fcas_pPKA;
		tjca = 75.0;
		jca_pPKA = fcass - (fcass - jca_pPKA) * exp(-dt / tjca);

		Kmn = 0.002;
		k2n = 1000.0;
		km2n = jca_pPKA * 1.0;
		anca = 1.0 / (k2n / km2n + pow(1.0 + Kmn / cass_for_LCC, 4.0));
		nca_pPKA = anca * k2n / km2n - (anca * k2n / km2n - nca_pPKA) * exp(-km2n * dt);
		PhiCaL = 4.0 * vffrt * (cass_for_LCC * exp(2.0 * vfrt) - 0.341 * cao) / (exp(2.0 * vfrt) - 1.0);
		zca = 2.0;
		double PCa_pPKA = 0.0001 * 2.5;
		if ( m_celltype == LVEPI or m_celltype == RVEPI ) {
			PCa_pPKA *= 1.2;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			PCa_pPKA *= 2.5;
		}

		PCaNa = 0.00125 * PCa_pPKA;
		PCaK = 3.574e-4 * PCa_pPKA;


		double ICaL_PKA = fLCC_PKA_only * PCa_pPKA * PhiCaL * d_pPKA * (f_pPKA * (1.0 - nca_pPKA) + jca_pPKA * fca_pPKA * nca_pPKA) ;
		double ICaL_both_p = fLCC_both * PCa_pPKA * PhiCaL * d_pPKA * (f_pPKA * (1.0 - nca_pPKA) + jca * fca * nca) ;
		ICaL = ICaL_NP + ICaL_CaMK  + ICaL_PKA + ICaL_both_p;
		if (ICaL >= 0.0) {
			ICaL = -0.0001;
		}
		ICaNa = fLCC_PKA * PCaNa * PhiCaNa * d_pPKA * (f_pPKA * (1.0 - nca_pPKA) + jca_pPKA * fca_pPKA * nca_pPKA)  + (1 - fLCC_PKA) * ICaNa_NonPKA;
		ICaK = fLCC_PKA * PCaK * PhiCaK * d_pPKA * (f_pPKA * (1.0 - nca_pPKA) + jca_pPKA * fca_pPKA * nca_pPKA)  + (1 - fLCC_PKA) * ICaK_NonPKA;
	}

	void Compute_IKr()
	{	xrss = 1.0 / (1.0 + exp((-(v + 8.337)) / 6.789));
		txrf = 12.98 + 1.0 / (0.3652 * exp((v - 31.66) / 3.869) + 4.123e-5 * exp((-(v - 47.78)) / 20.38));
		txrs = 1.865 + 1.0 / (0.06629 * exp((v - 34.70) / 7.355) + 1.128e-5 * exp((-(v - 29.74)) / 25.94));
		Axrf = 1.0 / (1.0 + exp((v + 54.81) / 38.21));
		Axrs = 1.0 - Axrf;
		xrf = xrss - (xrss - xrf) * exp(-dt / txrf);
		xrs = xrss - (xrss - xrs) * exp(-dt / txrs);
		xr = Axrf * xrf + Axrs * xrs;
		rkr = 1.0 / (1.0 + exp((v + 55.0) / 75.0)) * 1.0 / (1.0 + exp((v - 10.0) / 30.0));
		GKr = 0.046;
		if ( m_celltype == LVEPI or m_celltype == RVEPI ) {
			GKr *= 1.3;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			GKr *= 0.80; // was 0.8
		}
		IKr = GKr * sqrt(ko / 5.4) * xr * rkr * (v - EK);
	}

	void Compute_IKs() {
		xs1ss = 1.0 / (1.0 + exp((-(v + 11.60)) / 8.932));
		txs1 = 817.3 + 1.0 / (2.326e-4 * exp((v + 48.28) / 17.80) + 0.001292 * exp((-(v + 210.0)) / 230.0));
		xs1 = xs1ss - (xs1ss - xs1) * exp(-dt / txs1);
		xs2ss = xs1ss;
		txs2 = 1.0 / (0.01 * exp((v - 50.0) / 20.0) + 0.0193 * exp((-(v + 66.54)) / 31.0));
		xs2 = xs2ss - (xs2ss - xs2) * exp(-dt / txs2);
		KsCa = 1.0 + 0.6 / (1.0 + pow(3.8e-5 / cai, 1.4));
		GKs = 0.0034;

		if ( m_celltype == LVENDO or m_celltype == LVMCELL ) {
			GKs = 0.0034;
		} else if ( m_celltype == RVENDO or m_celltype == RVMCELL ) {
			GKs = 0.0034 * 2.0;
		} else if ( m_celltype == LVEPI ) {
			//GKs*=1.4;
			GKs = 0.0034 * 1.4;
		} else //if ( m_celltype == RVEPI )
			GKs = 0.0034 * 1.4 * 2.0;
		double IKs_NonP = GKs * KsCa * xs1 * xs2 * (v - EKs);


		// in the paper says: http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3443981/
		// / say: previous work in human [(20) using original current formulations (21) with τxs1,PKA = 0.6 * τxs1 and GKs,PKA = 3.2 * GKs,

		double txs1_pPKA = txs1 * 0.6;
		xs1_pPKA = xs1ss - (xs1ss - xs1_pPKA) * exp(-dt / txs1_pPKA);
		double GKs_pPKA = GKs * 3.2;
		double IKs_pPKA = GKs_pPKA * KsCa * xs1_pPKA * xs2 * (v - EKs);

		IKs = (1 - fKs_PKA) * IKs_NonP + fKs_PKA * IKs_pPKA;
	}
	void Compute_Mutation_IKs() {
		double v_half;
		double slope;
		double Tau_Factor;
		double GKs_mutation;
		if (m_mutation == IKsMutation::WT) {
			v_half = -2.4;
			slope = 13.2;
			Tau_Factor = 1.0;
			GKs_mutation = 0.00414 * 0.94;
		} else if (m_mutation == IKsMutation::WT_G269S) {
			v_half = 8.9;
			slope = 15.2;
			Tau_Factor = 0.8367;  // sqrt(0.7)
			GKs_mutation = 0.0022 * 0.94 * 0.7954971857410882;
		} else if (m_mutation == IKsMutation::G269S) {
			v_half = 68.3;
			slope = 23.4;
			Tau_Factor = 0.6325;	// sqrt(0.4)
			GKs_mutation = 0.00414 * 4.75 * 0.94 * 0.6463414634146342;
		}
		xs1ss = 1.0 / (1.0 + exp((-(v - v_half)) / slope));
		// txs1 = 817.3 + 1.0 / (2.326e-4 * exp(-(v + 48.28) / 17.80) + 0.001292 * exp(((v + 210.0)) / 230.0));
		txs1 = Tau_Factor * (817.3 + 0.1 / (2.326e-4 * exp(-(v + 480) / 230) + 0.001292 * exp(-((v + 210.0)) / 230.0)));
		xs1 = xs1ss - (xs1ss - xs1) * exp(-dt / txs1);
		xs2ss = xs1ss;
		txs2 = Tau_Factor * (1.0 / (0.01 * exp((v - 50.0) / 20.0) + 0.0193 * exp((-(v + 66.54)) / 31.0)));
		xs2 = xs2ss - (xs2ss - xs2) * exp(-dt / txs2);
		KsCa = 1.0 + 0.6 / (1.0 + pow(3.8e-5 / cai, 1.4));

		if ( m_celltype == LVENDO or m_celltype == LVMCELL ) {
			GKs = GKs_mutation;
		} else if ( m_celltype == RVENDO or m_celltype == RVMCELL ) {
			GKs = GKs_mutation * 2.0;
		} else if ( m_celltype == LVEPI ) {
			GKs = GKs_mutation * 1.4;
		} else //if ( m_celltype == RVEPI )
			GKs = GKs_mutation * 1.4 * 2.0;
		double IKs_NonP = GKs * KsCa * xs1 * xs2 * (v - EKs);

		// in the paper says: http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3443981/
		// / say: previous work in human [(20) using original current formulations (21) with τxs1,PKA = 0.6 * τxs1 and GKs,PKA = 3.2 * GKs,

		double txs1_pPKA = txs1 * 0.7;
		xs1_pPKA = xs1ss - (xs1ss - xs1_pPKA) * exp(-dt / txs1_pPKA);
		double GKs_pPKA = GKs * 3.2;
		double IKs_pPKA = GKs_pPKA * KsCa * xs1_pPKA * xs2 * (v - EKs);

		IKs = (1 - fKs_PKA) * IKs_NonP + fKs_PKA * IKs_pPKA;
	}

	void Compute_IK1() {

		xk1ss = 1.0 / (1.0 + exp(-(v + 2.5538 * ko + 144.59) / (1.5692 * ko + 3.8115)));
		txk1 = 122.2 / (exp((-(v + 127.2)) / 20.36) + exp((v + 236.8) / 69.33));
		xk1 = xk1ss - (xk1ss - xk1) * exp(-dt / txk1);
		rk1 = 1.0 / (1.0 + exp((v + 105.8 - 2.6 * ko) / 9.493));
		GK1 = 0.19080*0.5;
		if ( m_celltype == LVEPI  or m_celltype == RVEPI ) {
			GK1 *= 1.2;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			GK1 *= 1.3;
		}
		IK1 = GK1 * sqrt(ko) * rk1 * xk1 * (v - EK);
	}

	void Compute_INaCa() {

		kna1 = 15.0;
		kna2 = 5.0;
		kna3 = 88.12;
		kasymm = 12.5;
		wna = 6.0e4;
		wca = 6.0e4;
		wnaca = 5.0e3;
		kcaon = 1.5e6;
		kcaoff = 5.0e3;
		qna = 0.5224;
		qca = 0.1670;
		hca = exp((qca * v * F) / (R * T));
		hna = exp((qna * v * F) / (R * T));
		h1 = 1 + nai / kna3 * (1 + hna);
		h2 = (nai * hna) / (kna3 * h1);
		h3 = 1.0 / h1;
		h4 = 1.0 + nai / kna1 * (1 + nai / kna2);
		h5 = nai * nai / (h4 * kna1 * kna2);
		h6 = 1.0 / h4;
		h7 = 1.0 + nao / kna3 * (1.0 + 1.0 / hna);
		h8 = nao / (kna3 * hna * h7);
		h9 = 1.0 / h7;
		h10 = kasymm + 1.0 + nao / kna1 * (1.0 + nao / kna2);
		h11 = nao * nao / (h10 * kna1 * kna2);
		h12 = 1.0 / h10;
		k1 = h12 * cao * kcaon;
		k2 = kcaoff;
		k3p = h9 * wca;
		k3pp = h8 * wnaca;
		k3 = k3p + k3pp;
		k4p = h3 * wca / hca;
		k4pp = h2 * wnaca;
		k4 = k4p + k4pp;
		k5 = kcaoff;
		k6 = h6 * cai * kcaon;
		k7 = h5 * h2 * wna;
		k8 = h8 * h11 * wna;
		x1 = k2 * k4 * (k7 + k6) + k5 * k7 * (k2 + k3);
		x2 = k1 * k7 * (k4 + k5) + k4 * k6 * (k1 + k8);
		x3 = k1 * k3 * (k7 + k6) + k8 * k6 * (k2 + k3);
		x4 = k2 * k8 * (k4 + k5) + k3 * k5 * (k1 + k8);
		E1 = x1 / (x1 + x2 + x3 + x4);
		E2 = x2 / (x1 + x2 + x3 + x4);
		E3 = x3 / (x1 + x2 + x3 + x4);
		E4 = x4 / (x1 + x2 + x3 + x4);
		KmCaAct = 150.0e-6;
		allo = 1.0 / (1.0 + pow(KmCaAct / cai, 2.0));
		zna = 1.0;
		JncxNa = 3.0 * (E4 * k7 - E1 * k8) + E3 * k4pp - E2 * k3pp;
		JncxCa = E2 * k2 - E1 * k1;
		Gncx = 0.0008;
		if ( m_celltype == LVEPI or m_celltype == RVEPI ) {
			Gncx *= 1.1;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Gncx *= 1.4;
		}
		INaCa_i = 0.8 * Gncx * allo * (zna * JncxNa + zca * JncxCa);

		h1 = 1 + nass / kna3 * (1 + hna);
		h2 = (nass * hna) / (kna3 * h1);
		h3 = 1.0 / h1;
		h4 = 1.0 + nass / kna1 * (1 + nass / kna2);
		h5 = nass * nass / (h4 * kna1 * kna2);
		h6 = 1.0 / h4;
		h7 = 1.0 + nao / kna3 * (1.0 + 1.0 / hna);
		h8 = nao / (kna3 * hna * h7);
		h9 = 1.0 / h7;
		h10 = kasymm + 1.0 + nao / kna1 * (1 + nao / kna2);
		h11 = nao * nao / (h10 * kna1 * kna2);
		h12 = 1.0 / h10;
		k1 = h12 * cao * kcaon;
		k2 = kcaoff;
		k3p = h9 * wca;
		k3pp = h8 * wnaca;
		k3 = k3p + k3pp;
		k4p = h3 * wca / hca;
		k4pp = h2 * wnaca;
		k4 = k4p + k4pp;
		k5 = kcaoff;
		k6 = h6 * cass * kcaon;
		k7 = h5 * h2 * wna;
		k8 = h8 * h11 * wna;
		x1 = k2 * k4 * (k7 + k6) + k5 * k7 * (k2 + k3);
		x2 = k1 * k7 * (k4 + k5) + k4 * k6 * (k1 + k8);
		x3 = k1 * k3 * (k7 + k6) + k8 * k6 * (k2 + k3);
		x4 = k2 * k8 * (k4 + k5) + k3 * k5 * (k1 + k8);
		E1 = x1 / (x1 + x2 + x3 + x4);
		E2 = x2 / (x1 + x2 + x3 + x4);
		E3 = x3 / (x1 + x2 + x3 + x4);
		E4 = x4 / (x1 + x2 + x3 + x4);
		KmCaAct = 150.0e-6;
		allo = 1.0 / (1.0 + pow(KmCaAct / cass, 2.0));
		JncxNa = 3.0 * (E4 * k7 - E1 * k8) + E3 * k4pp - E2 * k3pp;
		JncxCa = E2 * k2 - E1 * k1;
		INaCa_ss = 0.2 * Gncx * allo * (zna * JncxNa + zca * JncxCa);

		INaCa = INaCa_i + INaCa_ss;
	}

	void Compute_INaK()
	{	k1p = 949.5;
		k1m = 182.4;
		k2p = 687.2;
		k2m = 39.4;
		k3p = 1899.0;
		k3m = 79300.0;
		k4p = 639.0;
		k4m = 40.0;
		Knai0 = 9.073;
		Knao0 = 27.78;
		delta = -0.1550;
		Knai = Knai0 * exp((delta * v * F) / (3.0 * R * T));
		Knao = Knao0 * exp(((1.0 - delta) * v * F) / (3.0 * R * T));
		Kki = 0.5;
		Kko = 0.3582;
		MgADP = 0.05;
		MgATP = 9.8;
		Kmgatp = 1.698e-7;
		H = 1.0e-7;
		eP = 4.2;
		Khp = 1.698e-7;
		Knap = 224.0;
		Kxkur = 292.0;
		P = eP / (1.0 + H / Khp + nai / Knap + ki / Kxkur);
		a1 = (k1p * pow(nai / Knai, 3.0)) / (pow(1.0 + nai / Knai, 3.0) + pow(1.0 + ki / Kki, 2.0) - 1.0);
		b1 = k1m * MgADP;
		a2 = k2p;
		b2 = (k2m * pow(nao / Knao, 3.0)) / (pow(1.0 + nao / Knao, 3.0) + pow(1.0 + ko / Kko, 2.0) - 1.0);
		a3 = (k3p * pow(ko / Kko, 2.0)) / (pow(1.0 + nao / Knao, 3.0) + pow(1.0 + ko / Kko, 2.0) - 1.0);
		b3 = (k3m * P * H) / (1.0 + MgATP / Kmgatp);
		a4 = (k4p * MgATP / Kmgatp) / (1.0 + MgATP / Kmgatp);
		b4 = (k4m * pow(ki / Kki, 2.0)) / (pow(1.0 + nai / Knai, 3.0) + pow(1.0 + ki / Kki, 2.0) - 1.0);
		x1 = a4 * a1 * a2 + b2 * b4 * b3 + a2 * b4 * b3 + b3 * a1 * a2;
		x2 = b2 * b1 * b4 + a1 * a2 * a3 + a3 * b1 * b4 + a2 * a3 * b4;
		x3 = a2 * a3 * a4 + b3 * b2 * b1 + b2 * b1 * a4 + a3 * a4 * b1;
		x4 = b4 * b3 * b2 + a3 * a4 * a1 + b2 * a4 * a1 + b3 * b2 * a1;
		E1 = x1 / (x1 + x2 + x3 + x4);
		E2 = x2 / (x1 + x2 + x3 + x4);
		E3 = x3 / (x1 + x2 + x3 + x4);
		E4 = x4 / (x1 + x2 + x3 + x4);
		zk = 1.0;
		JnakNa = 3.0 * (E1 * a3 - E2 * b3);
		JnakK = 2.0 * (E4 * b1 - E3 * a1);
		Pnak = 0.4*30;
		if ( m_celltype == LVEPI or m_celltype == RVEPI) {
			Pnak *= 0.9;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Pnak *= 0.7;
		}

		double INaK_NP = Pnak * (zna * JnakNa + zk * JnakK);

		/*PKA*/
		double Knai_pPKA = 0.7 * Knai;
		a1 = (k1p * pow(nai / Knai_pPKA, 3.0)) / (pow(1.0 + nai / Knai_pPKA, 3.0) + pow(1.0 + ki / Kki, 2.0) - 1.0);
		b4 = (k4m * pow(ki / Kki, 2.0)) / (pow(1.0 + nai / Knai_pPKA, 3.0) + pow(1.0 + ki / Kki, 2.0) - 1.0);
		x1 = a4 * a1 * a2 + b2 * b4 * b3 + a2 * b4 * b3 + b3 * a1 * a2;
		x2 = b2 * b1 * b4 + a1 * a2 * a3 + a3 * b1 * b4 + a2 * a3 * b4;
		x3 = a2 * a3 * a4 + b3 * b2 * b1 + b2 * b1 * a4 + a3 * a4 * b1;
		x4 = b4 * b3 * b2 + a3 * a4 * a1 + b2 * a4 * a1 + b3 * b2 * a1;
		E1 = x1 / (x1 + x2 + x3 + x4);
		E2 = x2 / (x1 + x2 + x3 + x4);
		E3 = x3 / (x1 + x2 + x3 + x4);
		E4 = x4 / (x1 + x2 + x3 + x4);
		zk = 1.0;
		JnakNa = 3.0 * (E1 * a3 - E2 * b3);
		JnakK = 2.0 * (E4 * b1 - E3 * a1);
		Pnak = 30;
		if ( m_celltype == LVEPI or m_celltype == RVEPI) {
			Pnak *= 0.9;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Pnak *= 0.7;
		}
		double INaK_pPKA = Pnak * (zna * JnakNa + zk * JnakK);
		INaK = (1 - fNaK_PKA) * INaK_NP + fNaK_PKA * INaK_pPKA;
	}

	void Compute_IpCa() {
		GpCa = 0.0005;
		IpCa = GpCa * cai / (0.0005 + cai);

	}
	void Compute_Ibackgroud()
	{	xkb = 1.0 / (1.0 + exp(-(v - 14.48) / 18.34));
		GKb = 0.003;
		double GKb_PKA = GKb * 3.63;
		IKb = ((1 - fKb_PKA) * GKb  + fKb_PKA * GKb_PKA) * xkb * (v - EK) ;

		PNab = 3.75e-10;
		INab = PNab * vffrt * (nai * exp(vfrt) - nao) / (exp(vfrt) - 1.0);

		PCab = 2.5e-8;
		ICab = PCab * 4.0 * vffrt * (cai * exp(2.0 * vfrt) - 0.341 * cao) / (exp(2.0 * vfrt) - 1.0);
	}

	void Compute_Jrel() {
		fJrelp = (1.0 / (1.0 + KmCaMK / CaMKa));
		double fJrel_both = fJrelp * fJrel_PKA;
		double fJrel_PKA_only = fJrel_PKA - fJrel_both;
		double fJrel_CaM_only = fJrelp - fJrel_both;
		double fJrel_NonP = 1 - fJrel_both -  fJrel_PKA_only - fJrel_CaM_only;

		bt = 4.75;
		a_rel = 0.5 * bt;
		Jrel_inf = a_rel * (-ICaL) / (1.0 + pow(1.5 / cajsr, 8.0));
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jrel_inf *= 1.7;
		}
		tau_rel = bt / (1.0 + 0.0123 / cajsr);
		if (tau_rel < 0.005) {
			tau_rel = 0.005;
		}
		Jrelnp = Jrel_inf - (Jrel_inf - Jrelnp) * exp(-dt / tau_rel);
		btp = 1.25 * bt;
		a_relp = 0.5 * btp;
		Jrel_infp = a_relp * (-ICaL) / (1.0 + pow(1.5 / cajsr, 8.0));
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jrel_infp *= 1.7;
		}
		tau_relp = btp / (1.0 + 0.0123 / cajsr);
		if (tau_relp < 0.005) {
			tau_relp = 0.005;
		}
		Jrelp = Jrel_infp - (Jrel_infp - Jrelp) * exp(-dt / tau_relp);


		/* PKA */
		bt = 4.75;
		double a_rel_pPKA = 1.75 * a_rel;
		Jrel_inf = a_rel_pPKA * (-ICaL) / (1.0 + pow(1.5 / cajsr, 8.0));
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jrel_inf *= 1.2;
		}
		// tau_rel_pPKA = bt / (1.0 + 0.0123 / cajsr);
		double tau_rel_pPKA = tau_rel * 0.5;
		if (tau_rel_pPKA < 0.005) {
			tau_rel_pPKA = 0.005;
		}
		Jrel_pPKA = Jrel_inf - (Jrel_inf - Jrel_pPKA) * exp(-dt / tau_rel_pPKA);

		/*PKA - CAM both */
		btp = 1.75 * bt;
		double a_relp_pPKA = 1.75 * a_relp;
		Jrel_infp = a_relp_pPKA * (-ICaL) / (1.0 + pow(1.5 / cajsr, 8.0));
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jrel_infp *= 1.2;
		}
		double tau_relp_pPKA = tau_relp * 0.5;
		if (tau_rel_pPKA < 0.005) {
			tau_rel_pPKA = 0.005;
		}
		Jrelp_pPKA = Jrel_infp - (Jrel_infp - Jrelp_pPKA) * exp(-dt / tau_rel_pPKA);

		Jrel = fJrel_NonP * Jrelnp + fJrel_CaM_only * Jrelp + Jrel_pPKA * fJrel_PKA_only + Jrelp_pPKA * fJrel_both;
	}

	void Compute_Jup() {
		fJupp = (1.0 / (1.0 + KmCaMK / CaMKa));
		fJup_PKA = 0.0;
		double fJup_both = fJupp * fJup_PKA;
		double fJup_PKA_only = fJup_PKA - fJup_both;
		double fJup_CaM_only = fJupp - fJup_both;
		double fJup_NonP = 1 -  fJup_CaM_only;
		Jupnp = 0.004375 * cai / (cai + 0.00092);
		Jupp = 2.75 * 0.004375 * cai / (cai + 0.00092 - 0.00017);
		if ( m_celltype == LVEPI  or m_celltype == RVEPI ) {
			Jupnp *= 1.3;
			Jupp *= 1.3;
		}

		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jupnp *= 1.4;
			Jupp *= 1.4;
		}
		/* PKA */
		double Jup_pPKA = 0.004375 * cai / (cai + 0.00092 * 0.54);
		/*PKA and CAMK*/
		double Jupp_pPKA = 2.75 * 0.004375 * cai / (cai + (0.00092 - 0.00017) * 0.54);
		if ( m_celltype == LVEPI  or m_celltype == RVEPI ) {
			Jup_pPKA *= 1.3;
			Jupp_pPKA *= 1.3;
		}
		if ( m_celltype == LVMCELL or m_celltype == RVMCELL ) {
			Jup_pPKA *= 1.4;
			Jupp_pPKA *= 1.4;
		}
		Jleak = 0.0039375 * cansr / 15.0;
		Jup = fJup_NonP * Jupnp + fJup_CaM_only * Jupp + Jup_pPKA * fJup_PKA_only + Jupp_pPKA * fJup_both - Jleak;

	}

	void FBC() {
		CaMKb = CaMKo * (1.0 - CaMKt) / (1.0 + KmCaM / cass);
		CaMKa = CaMKb + CaMKt;
		CaMKt += dt * (aCaMK * CaMKb * (CaMKb + CaMKt) - bCaMK * CaMKt);

		JdiffNa = (nass - nai) / 2.0;
		JdiffK = (kss - ki) / 2.0;
		Jdiff = (cass - cai) / 0.2;
		Compute_Jrel();
		Compute_Jup();



		Jtr = (cansr - cajsr) / 100.0;

		nai += dt * (-(INa + INaL + 3.0 * INaCa_i + 3.0 * INaK + INab) * Acap / (F * vmyo) + JdiffNa * vss / vmyo);
		nass += dt * (-(ICaNa + 3.0 * INaCa_ss) * Acap / (F * vss) - JdiffNa);

		ki += dt * (-(Ito + IKr + IKs + IK1 + IKb + Ist - 2.0 * INaK) * Acap / (F * vmyo) + JdiffK * vss / vmyo);
		kss += dt * (-(ICaK) * Acap / (F * vss) - JdiffK);

		/* Troponin PKA Effects */
		double tronp_NP = trpnmax * kmtrpn / ( (kmtrpn + cai) * (kmtrpn + cai)) ;//pow(kmtrpn + cai, 2.0);
		double tronp_pPKA = trpnmax * 1.6 * kmtrpn / ( (1.6 * kmtrpn + cai) * (1.6 * kmtrpn + cai)) ;;
		double trop_buff = (1 - fTron_PKA) * tronp_NP + fTron_PKA * tronp_pPKA;
		if ( m_celltype == LVEPI  or m_celltype == RVEPI ) {
			Bcai = 1.0 / (1.0 + 1.3 * cmdnmax * kmcmdn / pow(kmcmdn + cai, 2.0) + trop_buff);
		} else {
			Bcai = 1.0 / (1.0 + cmdnmax * kmcmdn / pow(kmcmdn + cai, 2.0) + trop_buff);
		}
		cai += dt * (Bcai * (-(IpCa + ICab - 2.0 * INaCa_i) * Acap / (2.0 * F * vmyo) - Jup * vnsr / vmyo + Jdiff * vss / vmyo));

		Bcass = 1.0 / (1.0 + BSRmax * KmBSR / pow(KmBSR + cass, 2.0) + BSLmax * KmBSL / pow(KmBSL + cass, 2.0));
		cass += dt * (Bcass * (-(ICaL - 2.0 * INaCa_ss) * Acap / (2.0 * F * vss) + Jrel * vjsr / vss - Jdiff));

		cansr += dt * (Jup - Jtr * vjsr / vnsr);

		Bcajsr = 1.0 / (1.0 + csqnmax * kmcsqn / pow(kmcsqn + cajsr, 2.0));
		cajsr += dt * (Bcajsr * (Jtr - Jrel));
	}


	void Compute_dVdt() {
		dvdt = -(INa + INaL + Ito + ICaL + ICaNa + ICaK + IKr + IKs + IK1 + INaCa + INaK + INab + IKb + IpCa + ICab + Ist);
	}

	double stimulus() {
		double stims;
		if ((t > (start + n * CL) and t < (start + duration + n * CL - dt))) {
			if (Ist == 0) {
				vrest = v;
			}
			stims = amp;
		} else if (t > (start + duration + n * CL - dt)) {
			Ist = 0.0;
			n = n + 1;
		} else
			stims = 0.0;
		return stims;
	}

	void dVdt_APD() {
		vdot_old = vdot;
		vdot = (v - vo) / dt;
		if (APD_flag == 0 and v > -40 and vdot < vdot_old) {
			vdot_max = vdot_old;
			t_vdot_max = t - dt;
			APD_flag = 1;
		}
		if  (APD_flag == 1 and v < 0.9 * vrest) {
			APD = t - t_vdot_max;
			APD_flag = 0;
		}
	}
	void SetPotential(double & value) {
		value = v;
	}
	double RunSingleTimeStep(double _dt, double stims) {

		Ist = stims;
		dt = _dt;
		revpots();   // calculate reverse potential
		RGC();       //
		vo = v;
		Compute_dVdt();
		FBC();
		t += dt;
		return dvdt;
	}
	double Run( std::ofstream &out ) {

		dia     = 0.0;//5000;
		CL      = 1000;                 // Pacing cycle length
		repeats = 10 * 10/**10*/;
		dt 		= 0.005;
		ft      = repeats * CL + dia; // Final/total simulation time

		for ( unsigned int step = 0; step < static_cast<unsigned int>(ft / dt); ++step ) {


			double stim = stimulus();
			RunSingleTimeStep(0.005, stim);
			v += dvdt * dt;
			dVdt_APD();
			if (count % 500000 == 0) {
				std::cout << std::ceil(t / ft * 100) << "% complete" << std::endl; //output runtime progress to the screen
			}

			//=======
			// OUTPUT
			//=======
			if ( step % 1000 == 0 )         // Uncomment to output all beats every 5 ms. Comment line below.
				//if ( step >= 199790000 )      // Uncomment to output last beat only. Comment line above.
				out << t    << std::setw(15) //0
				    << v    << std::setw(15) //1
				    << cai  << std::setw(15) //2
				    << IKs  << std::setw(15) //3
				    << ICaL  << std::setw(15) //4
				    << cass  << std::setw(15) //5
				    << cai  << std::setw(15) //6
				    << std::endl;

			++count;// Increase the loop counter
		}// END: step loop

		std::cout << "APD: " << APD << std::endl;
		return v;
	}
	void output_init_value(char *filename) {
		std::ofstream  out(filename);
		out << v          << '\n'
		    << nai        << '\n'
		    << nass       << '\n'
		    << ki         << '\n'
		    << kss        << '\n'
		    << cai        << '\n'
		    << cass       << '\n'
		    << cansr      << '\n'
		    << cajsr      << '\n'
		    << m          << '\n'
		    << hf         << '\n'
		    << hs         << '\n'
		    << j          << '\n'
		    << hsp        << '\n'
		    << jp         << '\n'
		    << mL         << '\n'
		    << hL         << '\n'
		    << hLp        << '\n'
		    << a          << '\n'
		    << iF         << '\n'
		    << iS         << '\n'
		    << ap         << '\n'
		    << iFp        << '\n'
		    << iSp        << '\n'
		    << d          << '\n'
		    << ff         << '\n'
		    << fs         << '\n'
		    << fcaf       << '\n'
		    << fcas       << '\n'
		    << jca        << '\n'
		    << nca        << '\n'
		    << ffp        << '\n'
		    << fcafp      << '\n'
		    << xrf        << '\n'
		    << xrs        << '\n'
		    << xs1        << '\n'
		    << xs2        << '\n'
		    << xk1        << '\n'
		    << Jrelnp     << '\n'
		    << Jrelp      << '\n'
		    << CaMKt      << '\n'
		    << d_pPKA     << '\n'
		    << ff_pPKA    << '\n'
		    << fs_pPKA    << '\n'
		    << fcaf_pPKA  << '\n'
		    << fcas_pPKA  << '\n'
		    << jca_pPKA   << '\n'
		    << nca_pPKA   << '\n'
		    << xs1_pPKA   << '\n'
		    << j_pPKA     << '\n'
		    << hf_pPKA    << '\n'
		    << hs_pPKA    << '\n'
		    << hsp_pPKA   << '\n'
		    << jp_pPKA    << '\n'
		    << Jrel_pPKA  << '\n'
		    << Jrelp_pPKA << '\n';
		out.close();
	}
	void read_in_init_value(char *filename) {
		std::ifstream  outin(filename);
		outin >>  v
		      >>  nai
		      >>  nass
		      >>  ki
		      >>  kss
		      >>  cai
		      >>  cass
		      >>  cansr
		      >>  cajsr
		      >>  m
		      >>  hf
		      >>  hs
		      >>  j
		      >>  hsp
		      >>  jp
		      >>  mL
		      >>  hL
		      >>  hLp
		      >>  a
		      >>  iF
		      >>  iS
		      >>  ap
		      >>  iFp
		      >>  iSp
		      >>  d
		      >>  ff
		      >>  fs
		      >>  fcaf
		      >>  fcas
		      >>  jca
		      >>  nca
		      >>  ffp
		      >>  fcafp
		      >>  xrf
		      >>  xrs
		      >>  xs1
		      >>  xs2
		      >>  xk1
		      >>  Jrelnp
		      >>  Jrelp
		      >>  CaMKt
		      >>  d_pPKA
		      >>  ff_pPKA
		      >>  fs_pPKA
		      >>  fcaf_pPKA
		      >>  fcas_pPKA
		      >>  jca_pPKA
		      >>  nca_pPKA
		      >>  xs1_pPKA
		      >>  j_pPKA
		      >>  hf_pPKA
		      >>  hs_pPKA
		      >>  hsp_pPKA
		      >>  jp_pPKA
		      >>  Jrel_pPKA
		      >>  Jrelp_pPKA ;
		outin.close();
	}
	void vclamp() {
		double V, Vhold, Vstart, Vend, Vstep, Vstep_size, Vstep_end;
		double clamp_time;
		double peak_current_pos, peak_current_neg, end_current;
		FILE *volt_out, *current_out;
		double I, t;
		int end_switch = 0;
		double dt = 0.005;
		// define values for general parameters
		Vhold = -80;
		Vstart = -70.1;
		Vend = -50;
		Vstep_end = 40;
		double holding_time = 500;
		clamp_time = 2000;
		Vstep_size = 10;

		//file names
		volt_out = fopen("IV_Relationship.txt", "wt");
		current_out = fopen("Current_Trace.txt", "wt");
		for (Vstep = Vstart; Vstep < Vstep_end + 1; Vstep = Vstep + Vstep_size) {
			// initial conditions for gating variables (reset before each step)
			double V;
			// Vstep = 30;

			peak_current_pos = peak_current_neg = 0.0;
			end_switch = 0;
			count = 0;
			state_initialise();
			for (t = 0.0; t < 2 * holding_time + clamp_time; t = t + dt) {
				count ++;
				if (t < holding_time) V = Vhold;
				else if (t < holding_time +  clamp_time) V = Vstep;
				else {
					V = Vend;
					// end_current = I;
					if (end_switch <= 5) {
						end_switch += 1;
					}

					if (end_switch == 2) {
						end_current = I;
					}
				}
				v = V;
				// revpots();
				// RGC();
				// stimulus();
				vo = v;
				// Compute_dVdt();
				// dVdt_APD();
				// FBC();
				revpots() ;
				Compute_Mutation_IKs();
				// Compute_IKs();
				I = IKs;
				// calculate peak current values
				if ( V == Vstep) {
					if (I > peak_current_pos) peak_current_pos = I;
					if (I < peak_current_neg) peak_current_neg = I;
				}
				if ((count % 100) == 0) {
					fprintf(current_out, "%f %f %f\n", t, I, V);
				}
				// fprintf(current_out, "%f %f %f\n", t, I / Cm, V);
			} // end time for loop

			// fprintf(current_out, "**************\n"
			//         "Vstep = %f \n", Vstep);
			// for steady state and tau, include equations here with Vstep as the V term

			fprintf(volt_out, "%f %f %f %f\n", Vstep, peak_current_pos, peak_current_neg, end_current);
		} // end for V loop
	}
	//private:
	//=====================================
	// PARAMETERS FOR STIMULATION PROTOCOLS
	//=====================================
	double stimduration;
	double stimstrength;
	double tbegin;
	double tend;
	int    beat_counter;
	double basicperiod;
	double basicapd;
	double time;

	double dia;         // Diastolic Interval
	double CL;          //pacing cycle length
	double ft;          //final time
	int        skip;            //number of timesetps to skip in sampling of data in output file
	double safetime;        //time from the beginning of each beat during which dt is fixed to small values
	double beatssave;   //number of beats to save in the output
	double repeats;

	double amp;         //stimulus amplitude in uA/uF
	double start;       //start time of the stimulus, relative to each beat
	double duration;        //duration of teh stimulus in ms

	TypeCell m_celltype;

	// Initial values for state variables, there are 41 of them
	double v;
	double nai;
	double nass;
	double ki;
	double kss;
	double cai;
	double cass;
	double cansr;
	double cajsr;
	double m;
	double hf;
	double hs;
	double j;
	double hsp;
	double jp;
	double mL;
	double hL;
	double hLp;
	double a;
	double iF;
	double iS;
	double ap;
	double iFp;
	double iSp;
	double d;
	double ff;
	double fs;
	double fcaf;
	double fcas;
	double jca;
	double nca;
	double ffp;
	double fcafp;
	double xrf;
	double xrs;
	double xs1;
	double xs2;
	double xk1;
	double Jrelnp;
	double Jrelp;
	double CaMKt;

	// Constants
	double nao;//extracellular sodium in mM
	double cao;//extracellular calcium in mM
	double ko;//extracellular potassium in mM

	// Buffer paramaters
	double BSRmax;
	double KmBSR;
	double BSLmax;
	double KmBSL;
	double cmdnmax;
	double kmcmdn;
	double trpnmax;
	double kmtrpn;
	double csqnmax;
	double kmcsqn;

	// CaMK paramaters
	double aCaMK;
	double bCaMK;
	double CaMKo;
	double KmCaM;
	double KmCaMK;

	// Physical constants
	double R;
	double T;
	double F;

	// Cell geometry
	double L;
	double rad;
	double vcell;
	double Ageo;
	double Acap;
	double vmyo;
	double vmito;
	double vsr;
	double vnsr;
	double vjsr;
	double vss;

	// Introduce varaibles for reversal potentials, currents, fluxes, and CaMK
	double ENa, EK, EKs;
	double INa, INaL, Ito, ICaL, ICaNa, ICaK, IKr, IKs, IK1, INaCa_i, INaCa_ss, INaCa, INaK, IKb, INab, IpCa, ICab, Ist;
	double Jrel, Jup, Jtr, Jdiff, JdiffNa, JdiffK, Jleak;
	double CaMKa, CaMKb;

	// Introduce APD, timing, and counting parameters
	int APD_flag;
	double APD;
	double t_vdot_max;
	double vrest;
	double vo;
	double dt;
	double t0;
	double t;
	double dto;
	double vdot_old;
	double vdot;
	double vdot_max;
	int p;
	int n;
	int count;

	// Value holders for state variables in the case that the increase in dt was too aggressive, so a smaller one can be taken
	double  nai0, nass0, ki0, kss0, cai0, cass0, cansr0, cajsr0, m0, hf0, hs0, jO, hsp0, jp0, mL0, hL0, hLp0, a0, iF0, iS0, ap0, iFp0, iSp0, d0, ff0, fs0, fcaf0, fcas0, jca0, nca0, ffp0, fcafp0, xrf0, xrs0, xs10, xs20, xk10, Jrelnp0, Jrelp0, CaMKt0;

	int counter;
	double dvdt;

	double vffrt;
	double vfrt;

	double mss;
	double tm;
	double hss;
	double thf;
	double ths;
	double Ahf;
	double Ahs;
	double h;
	double jss;
	double tj;
	double hssp;
	double thsp;
	double hp;
	double tjp;
	double GNa;
	double fINap;
	double mLss;
	double tmL;
	double hLss;
	double thL;;
	double hLssp;
	double thLp;
	double GNaL;
	double fINaLp;
	double ass;
	double ta;
	double iss;
	double delta_epi;
	double tiF;
	double tiS;
	double AiF;
	double AiS;
	double i;
	double assp;
	double dti_develop;
	double dti_recover;
	double tiFp;
	double tiSp;;
	double ip;
	double Gto;
	double fItop;
	double dss;
	double td;
	double fss;
	double tff;
	double tfs;
	double Aff;
	double Afs;;
	double f;
	double fcass;
	double tfcaf;
	double tfcas;
	double Afcaf;
	double Afcas;;
	double fca;
	double tjca;
	double tffp;
	double fp;
	double tfcafp;
	double fcap;
	double Kmn;
	double k2n;
	double km2n;
	double anca;
	double PhiCaL;
	double PhiCaNa;
	double PhiCaK;
	double zca;
	double PCa;
	double PCap;
	double PCaNa;
	double PCaK;
	double PCaNap;
	double PCaKp;
	double fICaLp;
	double xrss;
	double txrf;
	double txrs;
	double Axrf;
	double Axrs;
	double xr;
	double rkr;
	double GKr;
	double xs1ss;
	double txs1;;
	double xs2ss;
	double txs2;
	double KsCa;
	double GKs;
	double xk1ss;
	double txk1;
	double rk1;
	double GK1;
	double kna1;
	double kna2;
	double kna3;
	double kasymm;
	double wna;
	double wca;
	double wnaca;
	double kcaon;
	double kcaoff;
	double qna;
	double qca;
	double hca;
	double hna;
	double h1;
	double h2;
	double h3;
	double h4;
	double h5;
	double h6;
	double h7;
	double h8;
	double h9;
	double h10;
	double h11;
	double h12;
	double k1;
	double k2;
	double k3p;
	double k3pp;
	double k3;
	double k4p;
	double k4pp;
	double k4;
	double k5;
	double k6;
	double k7;
	double k8;
	double x1;
	double x2;
	double x3;
	double x4;
	double E1;
	double E2;
	double E3;
	double E4;
	double KmCaAct;
	double allo;
	double zna;
	double JncxNa;
	double JncxCa;
	double Gncx;
	double k1p;
	double k1m;
	double k2p;
	double k2m;
	double k3m;
	double k4m;
	double Knai0;
	double Knao0;
	double delta;
	double Knai;
	double Knao;
	double Kki;
	double Kko;
	double MgADP;
	double MgATP;
	double Kmgatp;
	double H;
	double eP;
	double Khp;
	double Knap;
	double Kxkur;
	double P;
	double a1;
	double b1;
	double a2;
	double b2;
	double a3;
	double b3;
	double a4;
	double b4;
	double zk;
	double JnakNa;
	double JnakK;
	double Pnak;
	double xkb;
	double GKb;
	double PNab;
	double PCab;
	double GpCa;
	double bt;
	double a_rel;
	double Jrel_inf;
	double tau_rel;
	double btp;
	double a_relp;
	double Jrel_infp;
	double tau_relp;
	double fJrelp;
	double Jupnp;
	double Jupp;
	double fJupp;
	double Bcai;
	double Bcass;
	double Bcajsr;


	double fLCC_PKA;
	double d_pPKA;
	double ff_pPKA;
	double fs_pPKA;
	double f_pPKA;
	double fcaf_pPKA;
	double fcas_pPKA;
	double fca_pPKA;
	double jca_pPKA;
	double nca_pPKA;

	double xs1_pPKA;
	double fKs_PKA;
	double fKb_PKA;
	double fNa_PKA;
	double fJrel_PKA;
	double fJup_PKA;
	double fTron_PKA;
	double fNaK_PKA;
	double j_pPKA;
	double hf_pPKA;
	double hs_pPKA;
	double hsp_pPKA;
	double jp_pPKA;

	double Jrel_pPKA;
	double Jrelp_pPKA;
	IKsMutation m_mutation;
	bool m_ISO;

};


