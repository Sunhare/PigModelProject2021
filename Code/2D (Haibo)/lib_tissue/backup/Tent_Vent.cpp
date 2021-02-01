
#include "Tent_Vent.h"
#include <cmath>
// double TentVentByJohn(double dt, double *state, float ZIndex, TypeCell cellTissue1);
double TentVentByJohn(double dt, double Istim, double *state, float ZIndex, TypeCell cellTissue) {

	static double Tent_RTONF = (Tent_R * Tent_T / Tent_F);
	static double Tent_inverseVcF2  =  (1. / (2 * Tent_Vc * Tent_F));
	static double Tent_inverseVcF   =  (1. / (Tent_Vc * Tent_F));
	static double Tent_inversevssF2 = (1. / (2 * Tent_Vss * Tent_F));

	double Ek, Ena, Eks, Eca;
	double INa, GNa, AM, BM, TAU_M, M_INF, AH_1, BH_1, TAU_H, AH_2, BH_2, H_INF, AJ_1, BJ_1, TAU_J, AJ_2, BJ_2, J_INF;
	double ICaL, D_INF, Ad, Bd, Cd, TAU_D, F_INF, Af, Bf, Cf, TAU_F, F2_INF, Af2, Bf2, Cf2, TAU_F2, FCaSS_INF, TAU_FCaSS;
	double Ito, Gto, R_INF, S_INF, TAU_R, TAU_S;
	double IKr, GKr, Xr1_INF, axr1, bxr1, TAU_Xr1, Xr2_INF, axr2, bxr2, TAU_Xr2;
	double IKs, GKs, Xs_INF, Axs, Bxs, TAU_Xs;
	double IK1, GK1, Ak1, Bk1, rec_iK1;
	double INaCa;
	double INaK, rec_iNaK;
	double Isus, Gsus, susa;
	double If, ifk, ifna, Gfna, Gfk, y_inf, Ay, By, tau_y;
	double IpCa;
	double IpK, rec_ipK;
	double IbNa;
	double IbCa;
	double kCaSR, k1, k2, dRR;
	double Irel, Ileak, Iup, Ixfer;
	double CaCSQN, bjsr, cjsr;
	double CaSSBuf, bcss, ccss;
	double CaBuf, bc, cc;
	double dNai, dKi, dCai, dCaSR, dCaSS;

	Ek = Tent_RTONF * (log((Tent_Ko / state[3])));
	Ena = Tent_RTONF * (log((Tent_Nao / state[2])));
	Eks = Tent_RTONF * (log((Tent_Ko + Tent_pKNa * Tent_Nao) / (state[3] + Tent_pKNa * state[2])));
	Eca = 0.5 * Tent_RTONF * (log((Tent_Cao / state[1])));

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI)
		GNa = 14.838;
	else
		GNa = 130.5744;   
	AM = 1. / (1. + exp((-60. - state[0]) / 5.));
	BM = 0.1 / (1. + exp((state[0] + 35.) / 5.)) + 0.10 / (1. + exp((state[0] - 50.) / 200.));
	TAU_M = AM * BM;
	M_INF = 1. / ((1. + exp((-56.86 - state[0]) / 9.03)) * (1. + exp((-56.86 - state[0]) / 9.03)));
	if (state[0] >= -40.) {
		AH_1 = 0.;
		BH_1 = (0.77 / (0.13 * (1. + exp(-(state[0] + 10.66) / 11.1))));
		TAU_H = 1.0 / (AH_1 + BH_1);
	} else {
		AH_2 = (0.057 * exp(-(state[0] + 80.) / 6.8));
		BH_2 = (2.7 * exp(0.079 * state[0]) + (3.1e5) * exp(0.3485 * state[0]));
		TAU_H = 1.0 / (AH_2 + BH_2);
	}
	H_INF = 1. / ((1. + exp((state[0] + 71.55) / 7.43)) * (1. + exp((state[0] + 71.55) / 7.43)));
	if (state[0] >= -40.) {
		AJ_1 = 0.;
		BJ_1 = (0.6 * exp((0.057) * state[0]) / (1. + exp(-0.1 * (state[0] + 32.))));
		TAU_J = 1.0 / (AJ_1 + BJ_1);
	} else {
		AJ_2 = (((-2.5428e4) * exp(0.2444 * state[0]) - (6.948e-6) * exp(-0.04391 * state[0])) * (state[0] + 37.78) / (1. + exp(0.311 * (state[0] + 79.23))));
		BJ_2 = (0.02424 * exp(-0.01052 * state[0]) / (1. + exp(-0.1378 * (state[0] + 40.14))));
		TAU_J = 1.0 / (AJ_2 + BJ_2);
	}
	J_INF = H_INF;
	state[6] = M_INF - (M_INF - state[6]) * exp(-dt / TAU_M);
	state[7] = H_INF - (H_INF - state[7]) * exp(-dt / TAU_H);
	state[8] = J_INF - (J_INF - state[8]) * exp(-dt / TAU_J);
	INa = GNa * state[6] * state[6] * state[6] * state[7] * state[8] * (state[0] - Ena);

	D_INF = 1. / (1. + exp((-8 - state[0]) / 7.5));
	Ad = 1.4 / (1. + exp((-35 - state[0]) / 13)) + 0.25;
	Bd = 1.4 / (1. + exp((state[0] + 5) / 5));
	Cd = 1. / (1. + exp((50 - state[0]) / 20));
	TAU_D = Ad * Bd + Cd;
	F_INF = 1. / (1. + exp((state[0] + 20) / 7));
	Af = 1102.5 * exp(-(state[0] + 27) * (state[0] + 27) / 225);
	Bf = 200. / (1 + exp((13 - state[0]) / 10.));
	Cf = (180. / (1 + exp((state[0] + 30) / 10))) + 20;
	TAU_F = Af + Bf + Cf;
	F2_INF = 0.67 / (1. + exp((state[0] + 35) / 7)) + 0.33;
	Af2 = 562 * exp(-(state[0] + 27) * (state[0] + 27) / 240);
	Bf2 = 31 / (1. + exp((25 - state[0]) / 10));
	Cf2 = 80 / (1. + exp((state[0] + 30) / 10));
	TAU_F2 = Af2 + Bf2 + Cf2;
	FCaSS_INF = 0.6 / (1 + (state[5] / 0.05) * (state[5] / 0.05)) + 0.4;
	TAU_FCaSS = 80. / (1 + (state[5] / 0.05) * (state[5] / 0.05)) + 2.;
	state[9] = D_INF - (D_INF - state[9]) * exp(-dt / TAU_D);
	state[10] = F_INF - (F_INF - state[10]) * exp(-dt / TAU_F);
	state[11] = F2_INF - (F2_INF - state[11]) * exp(-dt / TAU_F2);
	state[12] = FCaSS_INF - (FCaSS_INF - state[12]) * exp(-dt / TAU_FCaSS);
	ICaL = Tent_GCaL * state[9] * state[10] * state[11] * state[12] * 4 * (state[0] - 15) * (Tent_F * Tent_F / (Tent_R * Tent_T)) * (0.25 * exp(2 * (state[0] - 15) * Tent_F / (Tent_R * Tent_T)) * state[5] - Tent_Cao) / (exp(2 * (state[0] - 15) * Tent_F / (Tent_R * Tent_T)) - 1.);

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI) {
		Gto = 0.08184;
		R_INF = 1. / (1. + exp((20 - state[0]) / 13.));
		S_INF = 1. / (1. + exp((state[0] + 27) / 13.));
		TAU_R = 10.45 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 7.3;
		TAU_S = 85.*exp(-(state[0] + 25.) * (state[0] + 25.) / 320.) + 5. / (1. + exp((state[0] - 40.) / 5.)) + 42.;
	} else if (cellTissue == LVENDO) {
		Gto = 0.073;
		R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
		S_INF = 1. / (1. + exp((state[0] + 28) / 5.));
		TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
		TAU_S = 1000.*exp(-(state[0] + 67) * (state[0] + 67) / 1000.) + 8.;
	} else if (cellTissue == LVMCELL || cellTissue == LVEPI) {
		Gto = 0.294;
		R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
		S_INF = 1. / (1. + exp((state[0] + 20) / 5.));
		TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
		TAU_S = 85.0 * exp(-(state[0] + 45.) * (state[0] + 45.) / 320.) + 5. / (1. + exp((state[0] - 20.) / 5.)) + 3.;
	} else if (cellTissue == RVENDO) {
		Gto = 0.073 * 4;
		R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
		S_INF = 1. / (1. + exp((state[0] + 28) / 5.));
		TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
		TAU_S = 1000.*exp(-(state[0] + 67) * (state[0] + 67) / 1000.) + 8.;
	} else {
		Gto = 0.294 * 0.8;
		R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
		S_INF = 1. / (1. + exp((state[0] + 20) / 5.));
		TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
		TAU_S = 85.*exp(-(state[0] + 45.) * (state[0] + 45.) / 320.) + 5. / (1. + exp((state[0] - 20.) / 5.)) + 3.;
	}
	state[14] = S_INF - (S_INF - state[14]) * exp(-dt / TAU_S);
	state[13] = R_INF - (R_INF - state[13]) * exp(-dt / TAU_R);

	Ito = Gto * state[13] * state[14] * (state[0] - Ek);

	//APEX BASE HETERO
	// first remove heterogeneity in Ito, by haibo time: Feb 27 2015
	/*if (cellTissue == LVENDO || cellTissue == LVMCELL || cellTissue == LVEPI) {
	    Ito = Ito * ((-1.0 * (ZIndex - 10) / 318) + 2.0);
	}*/

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI)
		GKr = 0.0918;
	else
		GKr = 0.153;
	Xr1_INF = 1. / (1. + exp((-26. - state[0]) / 7.));
	axr1 = 450. / (1. + exp((-45. - state[0]) / 10.));
	bxr1 = 6. / (1. + exp((state[0] - (-30.)) / 11.5));
	TAU_Xr1 = axr1 * bxr1;
	Xr2_INF = 1. / (1. + exp((state[0] - (-88.)) / 24.));
	axr2 = 3. / (1. + exp((-60. - state[0]) / 20.));
	bxr2 = 1.12 / (1. + exp((state[0] - 60.) / 20.));
	TAU_Xr2 = axr2 * bxr2;
	state[15] = Xr1_INF - (Xr1_INF - state[15]) * exp(-dt / TAU_Xr1);
	state[16] = Xr2_INF - (Xr2_INF - state[16]) * exp(-dt / TAU_Xr2);


	IKr = GKr * sqrt(Tent_Ko / 5.4) * state[15] * state[16] * (state[0] - Ek);

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI)
		GKs = 0.2352;
	else if (cellTissue == LVMCELL)
		GKs = 0.098;
	else if (cellTissue == LVENDO || cellTissue == LVEPI)
		GKs = 0.392;
	else if (cellTissue == RVMCELL)
		GKs = 0.098 * 2;
	else
		GKs = 0.392 * 2;
	Xs_INF = 1. / (1. + exp((-5. - state[0]) / 14.));
	Axs = (1400. / (sqrt(1. + exp((5. - state[0]) / 6))));
	Bxs = (1. / (1. + exp((state[0] - 35.) / 15.)));
	TAU_Xs = Axs * Bxs + 80;
	state[17] = Xs_INF - (Xs_INF - state[17]) * exp(-dt / TAU_Xs);

	IKs = GKs * state[17] * state[17] * (state[0] - Eks);

	//APEX BASE HETERO
	if (cellTissue == LVENDO || cellTissue == LVMCELL || cellTissue == LVEPI) {
		// IKs = IKs * ((-1.0 * (ZIndex - 10) / 318) + 2.0);  // John's version
		IKs = IKs * ZIndex;   //  by haibo
	}

	if (cellTissue != PF && cellTissue != PFMB && cellTissue != PFI) {
		GK1 = 5.405;
		Ak1 = 0.1 / (1. + exp(0.06 * (state[0] - Ek - 200)));
		Bk1 = (3.*exp(0.0002 * (state[0] - Ek + 100)) + exp(0.1 * (state[0] - Ek - 10))) / (1. + exp(-0.5 * (state[0] - Ek)));
		rec_iK1 = Ak1 / (Ak1 + Bk1);
		IK1 = GK1 * rec_iK1 * (state[0] - Ek);
	} else {
		GK1 = 0.065;
		rec_iK1 = 1. / (1. + exp(0.1 * (state[0] + 75.44)));
		IK1 = GK1 * rec_iK1 * (state[0] - Ek - 8.0);
	}

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI) {
		Gsus = 0.0227;
		susa = 1. / (1. + exp((5 - state[0]) / 17.));
		Isus = Gsus * susa * (state[0] - Ek);
	} else
		Isus = 0.0;

	if (cellTissue == PF || cellTissue == PFMB || cellTissue == PFI) {
		Gfna = 0.0145654;
		Gfk = 0.0234346;
		y_inf = 1.0 / (1.0 + exp((state[0] + 80.6) / 6.8));
		Ay = exp(-2.9 - (0.04 * state[0]));
		By = exp(3.6 + (0.11 * state[0]));
		tau_y = 4000. / (Ay + By);
		state[18] = y_inf - (y_inf - state[18]) * exp(-dt / tau_y);
		ifna = Gfna * state[18] * (state[0] - Ena);
		ifk = Gfk * state[18] * (state[0] - Ek);
		If = ifk + ifna;
	} else {
		ifna = 0.0;
		ifk = 0.0;
		If = 0.0;
	}

	INaCa = Tent_knaca * (1. / (Tent_KmNai * Tent_KmNai * Tent_KmNai + Tent_Nao * Tent_Nao * Tent_Nao)) * (1. / (Tent_KmCa + Tent_Cao)) * (1. / (1 + Tent_ksat * exp((Tent_n - 1) * state[0] * Tent_F / (Tent_R * Tent_T)))) * (exp(Tent_n * state[0] * Tent_F / (Tent_R * Tent_T)) * state[2] * state[2] * state[2] * Tent_Cao - exp((Tent_n - 1) * state[0] * Tent_F / (Tent_R * Tent_T)) * Tent_Nao * Tent_Nao * Tent_Nao * state[1] * 2.5);

	rec_iNaK = (1. / (1. + 0.1245 * exp(-0.1 * state[0] * Tent_F / (Tent_R * Tent_T)) + 0.0353 * exp(-state[0] * Tent_F / (Tent_R * Tent_T))));
	INaK = Tent_knak * (Tent_Ko / (Tent_Ko + Tent_KmK)) * (state[2] / (state[2] + Tent_KmNa)) * rec_iNaK;

	IpCa = Tent_GpCa * state[1] / (Tent_KpCa + state[1]);

	rec_ipK = 1. / (1. + exp((25 - state[0]) / 5.98));
	IpK = Tent_GpK * rec_ipK * (state[0] - Ek);

	IbNa = Tent_GbNa * (state[0] - Ena);

	IbCa = Tent_GbCa * (state[0] - Eca);

	kCaSR = Tent_maxsr - ((Tent_maxsr - Tent_minsr) / (1 + (Tent_EC / state[4]) * (Tent_EC / state[4])));
	k1 = Tent_k1_ / kCaSR;
	k2 = Tent_k2_ * kCaSR;
	dRR = Tent_k4 * (1 - state[19]) - k2 * state[5] * state[19];
	state[19] += dt * dRR;
	state[20] = k1 * state[5] * state[5] * state[19] / (Tent_k3 + k1 * state[5] * state[5]);

	Irel = Tent_Vrel * state[20] * (state[4] - state[5]);
	Ileak = Tent_Vleak * (state[4] - state[1]);
	Iup = Tent_Vmaxup / (1. + ((Tent_Kup * Tent_Kup) / (state[1] * state[1])));
	Ixfer = Tent_Vxfer * (state[5] - state[1]);

	CaCSQN = Tent_Bufsr * state[4] / (state[4] + Tent_Kbufsr);
	dCaSR = dt * (Iup - Irel - Ileak);
	bjsr = Tent_Bufsr - CaCSQN - dCaSR - state[4] + Tent_Kbufsr;
	cjsr = Tent_Kbufsr * (CaCSQN + dCaSR + state[4]);
	state[4] = (sqrt(bjsr * bjsr + 4 * cjsr) - bjsr) / 2;

	CaSSBuf = Tent_Bufss * state[5] / (state[5] + Tent_Kbufss);
	dCaSS = dt * (-Ixfer * (Tent_Vc / Tent_Vss) + Irel * (Tent_Vsr / Tent_Vss) + (-ICaL * Tent_inversevssF2 * Tent_CAPACITANCE));
	bcss = Tent_Bufss - CaSSBuf - dCaSS - state[5] + Tent_Kbufss;
	ccss = Tent_Kbufss * (CaSSBuf + dCaSS + state[5]);
	state[5] = (sqrt(bcss * bcss + 4 * ccss) - bcss) / 2;

	CaBuf = Tent_Bufc * state[1] / (state[1] + Tent_Kbufc);
	dCai = dt * ((-(IbCa + IpCa - 2 * INaCa) * Tent_inverseVcF2 * Tent_CAPACITANCE) - (Iup - Ileak) * (Tent_Vsr / Tent_Vc) + Ixfer);
	bc = Tent_Bufc - CaBuf - dCai - state[1] + Tent_Kbufc;
	cc = Tent_Kbufc * (CaBuf + dCai + state[1]);
	state[1] = (sqrt(bc * bc + 4 * cc) - bc) / 2;

	dNai = -(INa + IbNa + 3 * INaK + 3 * INaCa + ifna) * Tent_inverseVcF * Tent_CAPACITANCE;
	state[2] += dt * dNai;

	dKi = -(IK1 + Ito + Isus + IKr + IKs - 2 * INaK + IpK + ifk) * Tent_inverseVcF * Tent_CAPACITANCE;
	state[3] += dt * dKi;

	return (IKr + IKs + IK1 + Ito + Isus + (INa) + IbNa + ICaL + IbCa + INaK + INaCa + IpCa + IpK + (If)+Istim);
}

void InitialseTentVentByJohn(double *state, TypeCell cellTissue1) {

	state[0]  = -86.2;   // V
	state[1]  = 0.00007; // Cai
	state[2]  = 7.67;    // Nai
	state[3]  = 138.3;   // Ki
	state[4]  = 1.3;     // CaSRf
	state[5]  = 0.00007; // CaSS
	state[6]  = 0.0;     // sm
	state[7]  = 0.75;    // sh
	state[8]  = 0.75;    // sj
	state[9]  = 0.0;     // sd
	state[10] = 1.0;     // sf
	state[11] = 1.0;     // sf2
	state[12] = 1.0;     // sfcass
	state[13] = 0.0;     // sr
	state[14] = 1.0;     // ss
	state[15] = 0.0;     // sxr1
	state[16] = 0.0;     // sxr2
	state[17] = 0.0;     // sxs
	state[18] = 0.0;     // y
	state[19] = 1.0;     // sRR
	state[20] = 0.0;     // sOO

}
