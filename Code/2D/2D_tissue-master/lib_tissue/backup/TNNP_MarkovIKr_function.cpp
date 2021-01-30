
#include "TNNP_MarkovIKr_function.h"


void TNNP_MarkovIKr_Initialise(double *state, TypeCell m_celltype) {
    state[0]  = -86.2;
    state[1]  = 0.00007;
    state[2]  = 1.3;
    state[3]  = 0.00007;
    state[4]  = 7.67;
    state[5]  = 138.3;
    state[6]  = 0.0;
    state[7]  = 0.75;
    state[8]  = 0.75;
    state[9]  = 0.0;
    state[10] = 1.0;
    state[11] = 0.0;
    state[12] = 1.0;
    state[13] = 0.0;
    state[14] = 0.0;
    state[15] = 1.0;
    state[16] = 1.0;
    state[17] = 1.0;
    state[18] = 1.0;
    state[19] = 0.0;
    state[20] = 0.0;
    state[21] = 1.0;
    state[22] = 0.0;
    state[23] = 0.0;
    state[24] = 0.0;
    state[25] = 0.0;
}


double TNNP_MarkovIKr_ODE(double dt, double Istim, double *state, float ABIndex, TypeCell m_celltype) {
    double svolt  = state[0]; // -86.2;
    double Cai    = state[1]; // 0.00007;
    double CaSR   = state[2]; // 1.3;
    double CaSS   = state[3]; // 0.00007;
    double Nai    = state[4]; // 7.67;
    double Ki     = state[5]; // 138.3;
    double sm     = state[6]; // 0.0;
    double sh     = state[7]; // 0.75;
    double sj     = state[8]; // 0.75;
    double sxr1   = state[9]; // 0.0;
    double sxr2   = state[10]; // 1.0;
    double sxs    = state[11]; // 0.0;
    double ss     = state[12]; // 1.0;
    double sr     = state[13]; // 0.0;
    double sd     = state[14]; // 0.0;
    double sf     = state[15]; // 1.0;
    double sf2    = state[16]; // 1.0;
    double sfcass = state[17]; // 1.0;
    double sRR    = state[18]; // 1.0;
    double mNaL   = state[19];
    double hNaL   = state[20];
    double wt_C3  = state[21];  // 1.0;
    double wt_O   = state[22];  // 0.0;
    double wt_C1  = state[23];  // 0.0;
    double wt_C2  = state[24];  // 0.0;
    double wt_I   = state[25];  // 0.0;


    /*  default values for ABIndex = 0.0 (Value set 0 == Apical Cells)
        and ABIndex ranges from 0.0 -> 1.0 */
    /*
    *   0.0 -- Apical Cells
    *   1.0 -- Basal Cells
    */

    double Gto_ABh = 1.0;
    double InAcTo_Vhalf_ABh = 0.0;
    double InAcTo_Vk_ABh = 1.0;
    double GKs_ABh = 1.0;
    double TauKs_ABh = 1.0;
    double AcKs_Vhalf_ABh = 0.0;

    if (ABIndex < 0.0 or ABIndex > 1.0) {
        std::cerr << "Wrong Apcial-Basal Ratio, at ABIndex = " << ABIndex <<std:: endl;
        std::cerr << "Program Existing... " << std::endl;
        std::exit(0);
    }
    /* V1, ABIndex   == 0.0 -> Apical Cells */
    Gto_ABh          = 1.0/(1.0 + ABIndex * (29.6/16.5 - 1));          // Apical cells: 1.0; Basal Cells: 16.5/29.5
    InAcTo_Vhalf_ABh = ABIndex * 4.0;                            // Apical Cells: 0.0; Basal Cells: 4.0;
    InAcTo_Vk_ABh    = 1.0 + ABIndex * ((-4.5+3.4)/4.5);         // Apical cells: 1.0; Basal Cells: 3.4/4.5
    GKs_ABh          = 1.0 + ABIndex * (5.6/2.1-1.0);            // Apical Cells: 1.0; Basal Cells: 5.6/2.1
    TauKs_ABh        = 1.0 + ABIndex * (516.0/358.0);            // Apical Cells: 1.0; Basal Cells: 516.0/358.0;
    /* end of Apical-Basal heterogeneity settings */

    double Ek = TTCell_RTONF * (log((TTCell_Ko / Ki)));
    double Ena = TTCell_RTONF * (log((TTCell_Nao / Nai)));
    double Eks = TTCell_RTONF * (log((TTCell_Ko + TTCell_pKNa * TTCell_Nao) / (Ki + TTCell_pKNa * Nai)));
    double Eca = 0.5 * TTCell_RTONF * (log((TTCell_Cao / Cai)));
    double Ak1 = 0.1 / (1. + exp(0.06 * (svolt - Ek - 200)));
    double Bk1 = (3.0*exp(0.0002 * (svolt - Ek + 100)) +
                  exp(0.1 * (svolt - Ek - 10))) / (1. + exp(-0.5 * (svolt - Ek)));
    double rec_iK1 = Ak1 / (Ak1 + Bk1);
    double rec_iNaK = (1. / (1. + 0.1245 * exp(-0.1 * svolt * TTCell_F / (TTCell_R * TTCell_T)) + 0.0353 * exp(-svolt * TTCell_F / (TTCell_R * TTCell_T))));
    double rec_ipK = 1. / (1. + exp((25 - svolt) / 5.98));

    double R_INF;
    double S_INF;
    double TAU_R;
    double TAU_S;
    double GNaL, GKs, Gto;

    if (m_celltype == LVEPI) {
        GNaL = 0.0065;
        GKs = 0.392 * 1.4;  // was 0.392, changed in the same way as the ORd model did, to increase the APD difference in EPI and ENDO by haibo
        Gto = 0.294;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 20 + InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.*exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + exp((svolt - 20.) / 5.)) + 3.;
    } else if (m_celltype == LVENDO) {
        GNaL = 0.0065;
        GKs = 0.392;
        Gto = 0.073;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 28 + InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*exp(-(svolt + 67) * (svolt + 67) / 1000.) + 8.;
    } else if (m_celltype == LVMCELL) {
        GNaL = 0.0095;
        GKs = 0.098;
        Gto = 0.294;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 20+ InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.0 * exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + exp((svolt - 20.) / 5.)) + 3.;
    } else if (m_celltype == RVENDO) {
        GNaL = 0.0065;
        GKs = 0.392 * 2.0;
        Gto = 0.073 * 3.0;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 28 + InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*exp(-(svolt + 67) * (svolt + 67) / 1000.) + 8.;
    } else if (m_celltype == RVMCELL) {
        GNaL = 0.0095;
        GKs = 0.098*2.0;
        Gto = 0.294*3.0;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 20 + InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.0 * exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + exp((svolt - 20.) / 5.)) + 3.;
    } else if (m_celltype == RVEPI) {
        GNaL = 0.0065;
        GKs = 0.392 * 1.4*2.0;  // was 0.392, changed in the same way as the ORd model did, by haibo
        Gto = 0.294*3.0;
        R_INF = 1. / (1. + exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + exp((svolt + 20 + InAcTo_Vhalf_ABh) / (5.0*InAcTo_Vk_ABh)));
        TAU_R = 9.5 * exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.*exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + exp((svolt - 20.) / 5.)) + 3.;
    } else {
        std::cerr << "Cell type wrong1!" << std::endl;
        std::exit(0);
    }
    // cout << Gto << endl;
    /* Ito */
    ss = S_INF - (S_INF - ss) * exp(-dt / TAU_S);
    sr = R_INF - (R_INF - sr) * exp(-dt / TAU_R);
    double Ito = Gto_ABh * Gto * sr * ss * (svolt - Ek);

    /* INa */
    double TAU_H;
    double TAU_J;
    double AM = 1. / (1. + exp((-60. - svolt) / 5.));
    double BM = 0.1 / (1. + exp((svolt + 35.) / 5.)) + 0.10 / (1. + exp((svolt - 50.) / 200.));
    double TAU_M = AM * BM;
    double M_INF = 1. / ((1. + exp((-56.86 - svolt) / 9.03)) * (1. + exp((-56.86 - svolt) / 9.03)));
    if (svolt >= -40.) {
        double AH_1 = 0.;
        double BH_1 = (0.77 / (0.13 * (1. + exp(-(svolt + 10.66) / 11.1))));
        TAU_H = 1.0 / (AH_1 + BH_1);
    } else {
        double AH_2 = (0.057 * exp(-(svolt + 80.) / 6.8));
        double BH_2 = (2.7 * exp(0.079 * svolt) + (3.1e5) * exp(0.3485 * svolt));
        TAU_H = 1.0 / (AH_2 + BH_2);
    }
    double H_INF = 1. / ((1. + exp((svolt + 71.55) / 7.43)) * (1. + exp((svolt + 71.55) / 7.43)));
    if (svolt >= -40.) {
        double AJ_1 = 0.;
        double BJ_1 = (0.6 * exp((0.057) * svolt) / (1. + exp(-0.1 * (svolt + 32.))));
        TAU_J = 1.0 / (AJ_1 + BJ_1);
    } else {
        double AJ_2 = (((-2.5428e4) * exp(0.2444 * svolt) - (6.948e-6) *
                        exp(-0.04391 * svolt)) * (svolt + 37.78) /
                       (1. + exp(0.311 * (svolt + 79.23))));
        double BJ_2 = (0.02424 * exp(-0.01052 * svolt) / (1. + exp(-0.1378 * (svolt + 40.14))));
        TAU_J = 1.0 / (AJ_2 + BJ_2);
    }
    double J_INF = H_INF;

    sm = M_INF - (M_INF - sm) * exp(-dt / TAU_M);
    sh = H_INF - (H_INF - sh) * exp(-dt / TAU_H);
    sj = J_INF - (J_INF - sj) * exp(-dt / TAU_J);
    double GNa = 14.838;
    double INa = GNa * sm * sm * sm * sh * sj * (svolt - Ena);

    /* IKr */  // CalculateTTIKr
    double Xr1_INF;
    double Xr2_INF;
    double TAU_Xr1;
    double TAU_Xr2;
    double GKr = 0.153;
    Xr1_INF = 1. / (1. + exp((-26. - svolt) / 7.));
    double axr1 = 450. / (1. + exp((-45. - svolt) / 10.));
    double bxr1 = 6. / (1. + exp((svolt - (-30.)) / 11.5));
    TAU_Xr1 = axr1 * bxr1;
    Xr2_INF = 1. / (1. + exp((svolt - (-88.)) / 24.));
    double axr2 = 3. / (1. + exp((-60. - svolt) / 20.));
    double bxr2 = 1.12 / (1. + exp((svolt - 60.) / 20.));
    TAU_Xr2 = axr2 * bxr2;
    sxr1 = Xr1_INF - (Xr1_INF - sxr1) * exp(-dt / TAU_Xr1);
    sxr2 = Xr2_INF - (Xr2_INF - sxr2) * exp(-dt / TAU_Xr2);
    // double IKr =  GKr * sqrt(TTCell_Ko / 5.4) * sxr1 * sxr2 * (svolt - Ek);
    // CalculateMarkovIKr();

    /* Marcov IKr Model */
    double m_epiMidRatio = 1.5;
    double epi_factor   = 1.8 * m_epiMidRatio;
    double endo_factor  = 1.8;
    double mcell_factor = 1.8;
    double wt_a1 =  2.172;
    double wt_b1 =  1.077;
    double wt_a2 =  0.00655   * exp(0.5 * 0.05547153 * (svolt - 36.));
    double wt_a  =  0.00555   * exp(0.05547153 * (svolt - 12.));
    double wt_b  =  0.002357  * exp(-0.036588 * (svolt));
    double wt_b2 = 0.65 * 0.0029357 * exp(0.69 * -0.02158 * (svolt));
    double wt_ai = 0.11 * 0.439     * exp(1.7 *  -0.02352 * (svolt + 25.)) * (4.5 / TTCell_Ko);
    double wt_bi = 0.4 *  0.656     * exp(      0.000942 * (svolt)) * ((pow((4.5 / TTCell_Ko), 0.3)));
    double wt_mu = (wt_ai * wt_b2) / wt_bi;

    if (m_celltype == LVENDO)
        GKr = 0.0135 * pow(TTCell_Ko, 0.59) * endo_factor;
    else if (m_celltype == LVMCELL)
        GKr = 0.0135 * pow(TTCell_Ko, 0.59) * mcell_factor;
    else
        GKr = 0.0135 * pow(TTCell_Ko, 0.59) * epi_factor;

    double wt_dC3 = (wt_b * wt_C2) - (wt_a * wt_C3);
    double wt_dC2 = -((wt_b + wt_a1) * wt_C2) + (wt_a * wt_C3) + (wt_b1 * wt_C1);
    double wt_dC1 = -((wt_b1 + wt_a2 + wt_a2) * wt_C1) + (wt_a1 * wt_C2) + (wt_b2 * wt_O) + (wt_mu * wt_I);
    double wt_dO  =  -((wt_b2 + wt_bi) * wt_O) + (wt_a2 * wt_C1) + (wt_ai * wt_I);
    double wt_dI  = -((wt_mu + wt_ai) * wt_I) + (wt_a2 * wt_C1) + (wt_bi * wt_O);

    wt_O  += dt * wt_dO;
    wt_C1 += dt * wt_dC1;
    wt_C2 += dt * wt_dC2;
    wt_C3 += dt * wt_dC3;
    wt_I  += dt * wt_dI;
    double IKr = GKr * wt_O * (svolt - Ek);

    /* IKs */
    double Xs_INF = 1. / (1. + exp((-5. - svolt) / 14.));
    double Axs = (1400. / (sqrt(1. + exp((5. - svolt) / 6))));
    double Bxs = (1. / (1. + exp((svolt - 35.) / 15.)));
    double TAU_Xs = Axs * Bxs + 80;
    TAU_Xs = TauKs_ABh * TAU_Xs;
    sxs = Xs_INF - (Xs_INF - sxs) * exp(-dt / TAU_Xs);

    double IKs = GKs_ABh * GKs * sxs * sxs * (svolt - Eks);  // with apicalbasal heterogeneity wit direct scaling factor, by haibo

    /* ICaL */
    double D_INF = 1. / (1. + exp((-8 - svolt) / 7.5));
    double Ad = 1.4 / (1. + exp((-35 - svolt) / 13)) + 0.25;
    double Bd = 1.4 / (1. + exp((svolt + 5) / 5));
    double Cd = 1. / (1. + exp((50 - svolt) / 20));
    double TAU_D = Ad * Bd + Cd;
    double F_INF = 1. / (1. + exp((svolt + 20) / 7));
    double Af = 1102.5 * exp(-(svolt + 27) * (svolt + 27) / 225);
    double Bf = 200. / (1 + exp((13 - svolt) / 10.));
    double Cf = (180. / (1 + exp((svolt + 30) / 10))) + 20;
    double TAU_F = Af + Bf + Cf;

    double F2_INF = 0.67 / (1. + exp((svolt + 35) / 7)) + 0.33;
    double Af2 = 600 * exp(-(svolt + 25) * (svolt + 25) / 170);
    double Bf2 = 31 / (1. + exp((25 - svolt) / 10));
    double Cf2 = 16 / (1. + exp((svolt + 30) / 10));
    double TAU_F2 = Af2 + Bf2 + Cf2;

    sd = D_INF - (D_INF - sd) * exp(-dt / TAU_D);
    sf = F_INF - (F_INF - sf) * exp(-dt / TAU_F);
    sf2 = F2_INF - (F2_INF - sf2) * exp(-dt / TAU_F2);

    double FCaSS_INF = 0.6 / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 0.4;
    double TAU_FCaSS = 80. / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 2.;
    sfcass = FCaSS_INF - (FCaSS_INF - sfcass) * exp(-dt / TAU_FCaSS);

    double ICaL = TTCell_GCaL * sd * sf * sf2 * sfcass * 4 * (svolt - 15) * (TTCell_F * TTCell_F / (TTCell_R * TTCell_T)) *
                  (0.25 * exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) * CaSS - TTCell_Cao) / (exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) - 1.);

    //INaL gates
    double mNaL_INF, hNaL_INF, TAU_mNaL, TAU_hNaL;
    mNaL_INF = hNaL_INF = 0.0;
    // need to update INaL later...
    // mNaL = mNaL_INF - (mNaL_INF - mNaL) * exp(-dt / TAU_mNaL);
    // hNaL = hNaL_INF - (hNaL_INF - hNaL) * exp(-dt / TAU_hNaL);
    // double INaL = GNaL * mNaL * mNaL * mNaL * hNaL * (svolt - Ena);
    double INaL = 0.0;
    double IbNa = TTCell_GbNa * (svolt - Ena);
    double IbCa = TTCell_GbCa * (svolt - Eca);
    double IpK = TTCell_GpK * rec_ipK * (svolt - Ek);
    double IpCa = TTCell_GpCa * Cai / (TTCell_KpCa + Cai);
    double INaK = TTCell_knak * (TTCell_Ko / (TTCell_Ko + TTCell_KmK)) * (Nai / (Nai + TTCell_KmNa)) * rec_iNaK;
    double INaCa = TTCell_knaca * (1. / (TTCell_KmNai * TTCell_KmNai * TTCell_KmNai + TTCell_Nao * TTCell_Nao * TTCell_Nao)) * (1. / (TTCell_KmCa + TTCell_Cao)) *
                   (1. / (1 + TTCell_ksat * exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)))) *
                   (exp(TTCell_n * svolt * TTCell_F / (TTCell_R * TTCell_T)) * Nai * Nai * Nai * TTCell_Cao -
                    exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)) * TTCell_Nao * TTCell_Nao * TTCell_Nao * Cai * 2.5);

    double GK1 = 5.405;
    if (m_celltype == LVEPI)
        GK1 *= 1.2; // according to the ORd model supple, added by haibo
    double IK1 = GK1 * rec_iK1 * (svolt - Ek);
    double sItot = IKr + IKs + IK1 + Ito + INa + IbNa + ICaL + IbCa + INaK + INaCa + IpCa + IpK + INaL + Istim;

    /* update concentrations */
    double kCaSR = TTCell_maxsr - ((TTCell_maxsr - TTCell_minsr) / (1 + (TTCell_EC / CaSR) * (TTCell_EC / CaSR)));
    double k1 = TTCell_k1_ / kCaSR;
    double k2 = TTCell_k2_ * kCaSR;
    double dRR = TTCell_k4 * (1 - sRR) - k2 * CaSS * sRR;
    sRR += dt * dRR;
    double sOO = k1 * CaSS * CaSS * sRR / (TTCell_k3 + k1 * CaSS * CaSS);

    double Irel = TTCell_Vrel * sOO * (CaSR - CaSS);
    double Ileak = TTCell_Vleak * (CaSR - Cai);
    double Iup = TTCell_Vmaxup / (1. + ((TTCell_Kup * TTCell_Kup) / (Cai * Cai)));
    double Ixfer = TTCell_Vxfer * (CaSS - Cai);

    double CaCSQN = TTCell_Bufsr * CaSR / (CaSR + TTCell_Kbufsr);
    double dCaSR = dt * (Iup - Irel - Ileak);
    double bjsr = TTCell_Bufsr - CaCSQN - dCaSR - CaSR + TTCell_Kbufsr;
    double cjsr = TTCell_Kbufsr * (CaCSQN + dCaSR + CaSR);
    CaSR = (sqrt(bjsr * bjsr + 4 * cjsr) - bjsr) / 2;


    double CaSSBuf = TTCell_Bufss * CaSS / (CaSS + TTCell_Kbufss);
    double dCaSS = dt * (-Ixfer * (TTCell_Vc / TTCell_Vss) + Irel * (TTCell_Vsr / TTCell_Vss) + (-ICaL * TTCell_inversevssF2 * TTCell_CAPACITANCE));
    double bcss = TTCell_Bufss - CaSSBuf - dCaSS - CaSS + TTCell_Kbufss;
    double ccss = TTCell_Kbufss * (CaSSBuf + dCaSS + CaSS);
    CaSS = (sqrt(bcss * bcss + 4 * ccss) - bcss) / 2;


    double CaBuf = TTCell_Bufc * Cai / (Cai + TTCell_Kbufc);
    double dCai = dt * ((-(IbCa + IpCa - 2 * INaCa) * TTCell_inverseVcF2 * TTCell_CAPACITANCE) - (Iup - Ileak) * (TTCell_Vsr / TTCell_Vc) + Ixfer);
    double bc = TTCell_Bufc - CaBuf - dCai - Cai + TTCell_Kbufc;
    double cc = TTCell_Kbufc * (CaBuf + dCai + Cai);
    Cai = (sqrt(bc * bc + 4 * cc) - bc) / 2;


    double dNai = -(INa + IbNa + 3 * INaK + 3 * INaCa) * TTCell_inverseVcF * TTCell_CAPACITANCE;
    Nai += dt * dNai;

    double dKi = -(Istim + IK1 + Ito + IKr + IKs - 2 * INaK + IpK) * TTCell_inverseVcF * TTCell_CAPACITANCE;
    Ki += dt * dKi;


    // state[0]   = svolt  ;
    state[1]   = Cai    ;
    state[2]   = CaSR   ;
    state[3]   = CaSS   ;
    state[4]   = Nai    ;
    state[5]   = Ki     ;
    state[6]   = sm     ;
    state[7]   = sh     ;
    state[8]   = sj     ;
    state[9]   = sxr1   ;
    state[10]  = sxr2   ;
    state[11]  = sxs    ;
    state[12]  = ss     ;
    state[13]  = sr     ;
    state[14]  = sd     ;
    state[15]  = sf     ;
    state[16]  = sf2    ;
    state[17]  = sfcass ;
    state[18]  = sRR    ;
    state[19]  = mNaL   ;
    state[20]  = hNaL   ;
    state[21]  = wt_C3  ;
    state[22]  = wt_O   ;
    state[23]  = wt_C1  ;
    state[24]  = wt_C2  ;
    state[25]  = wt_I   ;


    return sItot;
}

void crn_con_initial_conditions_Vent_John(double state[], int cellTissue) {
    //This sets the initial conditions from the non-atrial areas of the model.
    //Note - This was adapted from Ismail, so it may well be wrong.

    /*  if(cellTissue == 13 || cellTissue == 14 || cellTissue == 15){
            state[0]  = -86.2;  // V
            state[1]  = 0.00007;    // Cai
            state[2]  = 7.67;   // Nai
            state[3]  = 138.3;      // Ki
            state[4]  = 1.3;    // CaSR
            state[5]  = 0.00007;    // CaSS
            state[6]  = 0.0;    // sm
            state[7]  = 0.75;   // sh
            state[8]  = 0.75;   // sj
            state[9]  = 0.0;    // sd
            state[10] = 1.0;    // sf
            state[11] = 1.0;    // sf2
            state[12] = 1.0;    // sfcass
            state[13] = 0.0006830833;
            state[14] = 0.9717098312;
            state[15] = 0.0;        // sxr1
            state[16] = 0.0;        // sxr2
            state[17] = 0.0;    // sxs
            state[18] = 0.0184308075;
            state[19] = 1.0;    // sRR
            state[20] = 0.0;    // sOO
        }
        else if(cellTissue > 15){
    */
    state[0]  = -86.2;  // V
    state[1]  = 0.00007;    // Cai
    state[2]  = 7.67;   // Nai
    state[3]  = 138.3;      // Ki
    state[4]  = 1.3;    // CaSR
    state[5]  = 0.00007;    // CaSS
    state[6]  = 0.0;    // sm
    state[7]  = 0.75;   // sh
    state[8]  = 0.75;   // sj
    state[9]  = 0.0;    // sd
    state[10] = 1.0;    // sf
    state[11] = 1.0;    // sf2
    state[12] = 1.0;    // sfcass
    state[13] = 0.0;    // sr
    state[14] = 1.0;        // ss
    state[15] = 0.0;        // sxr1
    state[16] = 0.0;        // sxr2
    state[17] = 0.0;    // sxs
    state[18] = 0.0;    // y
    state[19] = 1.0;    // sRR
    state[20] = 0.0;    // sOO
}


double crn_con_Vent_John(double dt, double *state, int ABIndex, int cellTissue, double INa_Drug, double If_Drug, double IKr_Drug, double IKs_Drug, double ICaL_Drug, double INa_V50A, double If_V50A, double IKr_V50A, double IKs_V50A, double ICaL_V50A, double INa_V50I, double If_V50I, double IKr_V50I, double IKs_V50I, double ICaL_V50I, double INa_TauA, double If_TauA, double IKr_TauA, double IKs_TauA, double ICaL_TauA, double INa_TauI, double If_TauI, double IKr_TauI, double IKs_TauI, double ICaL_TauI) {
    
    double R      = 8314.472;
    double F      = 96485.3415;
    double T      = 310.0;
    
    double Ko     = 5.4;
    double Cao    = 2.0;
    double Nao    = 140.0;
    
    double Vc     = 0.016404;
    double Vsr    = 0.001094;
    double Vss    = 0.00005468;
    
    double Bufc   = 0.2;
    double Kbufc  = 0.001;
    double Bufsr  = 10.;
    double Kbufsr = 0.3;
    double Bufss  = 0.4;
    double Kbufss = 0.00025;

    double Vmaxup = 0.006375;
    double Kup = 0.00025;
    double Vrel = 0.102;
    double k1_ = 0.15;
    double k2_ = 0.045;
    double k3 = 0.060;
    double k4 = 0.005;
    double EC = 1.5;
    double maxsr = 2.5;
    double minsr = 1.;
    double Vleak = 0.00036;
    double Vxfer = 0.0038;

    double CAPACITANCE = 0.185;

    double pKNa = 0.03;
    double GbNa = 0.00029;
    double KmK = 1.0;
    double KmNa = 40.0;
    double knak = 2.724;
    double GCaL = 0.00003980;
    double GbCa = 0.000592;
    double knaca = 1000;
    double KmNai = 87.5;
    double KmCa = 1.38;
    double ksat = 0.1;
    double n = 0.35;
    double GpCa = 0.1238;
    double KpCa = 0.0005;
    double GpK = 0.0146;

    double RTONF    = (R * T / F);
    double inverseVcF2  =  (1. / (2 * Vc * F));
    double inverseVcF   =  (1. / (Vc * F));
    double inversevssF2 = (1. / (2 * Vss * F));

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

    Ek = RTONF * (log((Ko / state[3])));
    Ena = RTONF * (log((Nao / state[2])));
    Eks = RTONF * (log((Ko + pKNa * Nao) / (state[3] + pKNa * state[2])));
    Eca = 0.5 * RTONF * (log((Cao / state[1])));

    /*if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GNa = 14.838;
    else
        GNa = 130.5744;*/  // the original implementation of PF and VW cells were in the other way round regarding the INa conductance..
    // change to the true values: here: haibo Sun 10 May 2015 09:44:30 BST


    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GNa = 130.5744;
    else
        GNa = 14.838;



    AM = 1. / (1. + exp((-60. - state[0]) / 5.));
    BM = 0.1 / (1. + exp((state[0] + 35.) / 5.)) + 0.10 / (1. + exp((state[0] - 50.) / 200.));
    TAU_M = AM * BM * INa_TauA;
    M_INF = 1. / ((1. + exp((-56.86 - (state[0] + INa_V50A)) / 9.03)) * (1. + exp((-56.86 - state[0]) / 9.03)));
    if (state[0] >= -40.)
    {
        AH_1 = 0.;
        BH_1 = (0.77 / (0.13 * (1. + exp(-((state[0] + INa_V50I) + 10.66) / 11.1))));
        TAU_H = INa_TauI * 1.0 / (AH_1 + BH_1);
    }
    else
    {
        AH_2 = (0.057 * exp(-((state[0] + INa_V50I) + 80.) / 6.8));
        BH_2 = (2.7 * exp(0.079 * (state[0] + INa_V50I)) + (3.1e5) * exp(0.3485 * state[0]));
        TAU_H = INa_TauI * 1.0 / (AH_2 + BH_2);
    }
    H_INF = 1. / ((1. + exp(((state[0] + INa_V50I) + 71.55) / 7.43)) * (1. + exp((state[0] + 71.55) / 7.43)));
    if (state[0] >= -40.)
    {
        AJ_1 = 0.;
        BJ_1 = (0.6 * exp((0.057) * (state[0] + INa_V50I)) / (1. + exp(-0.1 * (state[0] + 32.))));
        TAU_J = 1.0 / (AJ_1 + BJ_1);
    }
    else
    {
        AJ_2 = (((-2.5428e4) * exp(0.2444 * (state[0] + INa_V50I)) - (6.948e-6) * exp(-0.04391 * (state[0] + INa_V50I))) * (state[0] + 37.78) / (1. + exp(0.311 * ((state[0] + INa_V50I) + 79.23))));
        BJ_2 = (0.02424 * exp(-0.01052 * (state[0] + INa_V50I)) / (1. + exp(-0.1378 * ((state[0] + INa_V50I) + 40.14))));
        TAU_J = 1.0 / (AJ_2 + BJ_2);
    }
    J_INF = H_INF;
    state[6] = M_INF - (M_INF - state[6]) * exp(-dt / TAU_M);
    state[7] = H_INF - (H_INF - state[7]) * exp(-dt / TAU_H);
    state[8] = J_INF - (J_INF - state[8]) * exp(-dt / TAU_J);
    INa = GNa * state[6] * state[6] * state[6] * state[7] * state[8] * (state[0] - Ena);

    D_INF = 1. / (1. + exp((-8 - state[0] + ICaL_V50A) / 7.5));
    Ad = 1.4 / (1. + exp((-35 - state[0] + ICaL_V50A) / 13)) + 0.25;
    Bd = 1.4 / (1. + exp((state[0] + ICaL_V50A + 5) / 5));
    Cd = 1. / (1. + exp((50 - state[0] + ICaL_V50A) / 20));
    TAU_D = ICaL_TauA * (Ad * Bd + Cd);
    F_INF = 1. / (1. + exp((state[0] + 20 + ICaL_V50I) / 7));
    Af = 1102.5 * exp(-(state[0] + ICaL_V50I + 27) * (state[0] + ICaL_V50I + 27) / 225);
    Bf = 200. / (1 + exp((13 - state[0] + ICaL_V50I) / 10.));
    Cf = (180. / (1 + exp((state[0] + ICaL_V50I + 30) / 10))) + 20;
    TAU_F = ICaL_TauI * (Af + Bf + Cf);
    F2_INF = 0.67 / (1. + exp((state[0] + ICaL_V50I + 35) / 7)) + 0.33;
    Af2 = 562 * exp(-(state[0] + 27) * (state[0] + ICaL_V50I + 27) / 240);
    Bf2 = 31 / (1. + exp((25 - state[0] + ICaL_V50I) / 10));
    Cf2 = 80 / (1. + exp((state[0] + ICaL_V50I + 30) / 10));
    TAU_F2 = ICaL_TauI * (Af2 + Bf2 + Cf2);
    FCaSS_INF = 0.6 / (1 + (state[5] / 0.05) * (state[5] / 0.05)) + 0.4;
    TAU_FCaSS = 80. / (1 + (state[5] / 0.05) * (state[5] / 0.05)) + 2.;
    state[9] = D_INF - (D_INF - state[9]) * exp(-dt / TAU_D);
    state[10] = F_INF - (F_INF - state[10]) * exp(-dt / TAU_F);
    state[11] = F2_INF - (F2_INF - state[11]) * exp(-dt / TAU_F2);
    state[12] = FCaSS_INF - (FCaSS_INF - state[12]) * exp(-dt / TAU_FCaSS);
    ICaL = GCaL * state[9] * state[10] * state[11] * state[12] * 4 * (state[0] - 15) * (F * F / (R * T)) * (0.25 * exp(2 * (state[0] - 15) * F / (R * T)) * state[5] - Cao) / (exp(2 * (state[0] - 15) * F / (R * T)) - 1.);

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
    {
        Gto = 0.08184;
        R_INF = 1. / (1. + exp((20 - state[0]) / 13.));
        S_INF = 1. / (1. + exp((state[0] + 27) / 13.));
        TAU_R = 10.45 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 7.3;
        TAU_S = 85.*exp(-(state[0] + 25.) * (state[0] + 25.) / 320.) + 5. / (1. + exp((state[0] - 40.) / 5.)) + 42.;
    }
    else if (cellTissue == 20)
    {
        Gto = 0.073;
        R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
        S_INF = 1. / (1. + exp((state[0] + 28) / 5.));
        TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*exp(-(state[0] + 67) * (state[0] + 67) / 1000.) + 8.;
    }
    else if (cellTissue == 21 || cellTissue == 22)
    {
        Gto = 0.294;
        R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
        S_INF = 1. / (1. + exp((state[0] + 20) / 5.));
        TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
        TAU_S = 85.*exp(-(state[0] + 45.) * (state[0] + 45.) / 320.) + 5. / (1. + exp((state[0] - 20.) / 5.)) + 3.;
    }
    else if (cellTissue == 23)
    {
        Gto = 0.073 * 4;
        R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
        S_INF = 1. / (1. + exp((state[0] + 28) / 5.));
        TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*exp(-(state[0] + 67) * (state[0] + 67) / 1000.) + 8.;
    }
    else
    {
        Gto = 0.294 * 4;
        R_INF = 1. / (1. + exp((20 - state[0]) / 6.));
        S_INF = 1. / (1. + exp((state[0] + 20) / 5.));
        TAU_R = 9.5 * exp(-(state[0] + 40.) * (state[0] + 40.) / 1800.) + 0.8;
        TAU_S = 85.*exp(-(state[0] + 45.) * (state[0] + 45.) / 320.) + 5. / (1. + exp((state[0] - 20.) / 5.)) + 3.;
    }
    state[14] = S_INF - (S_INF - state[14]) * exp(-dt / TAU_S);
    state[13] = R_INF - (R_INF - state[13]) * exp(-dt / TAU_R);

    Ito = Gto * state[13] * state[14] * (state[0] - Ek);

    //APEX BASE HETERO
    if (cellTissue == 20 || cellTissue == 21 || cellTissue == 22) { // LEFT VENT
        Ito = Ito * ((-1.0 * (ABIndex - 10) / 318) + 2.0);
    }

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GKr = 0.0918;
    else
        GKr = 0.153;
    Xr1_INF = 1. / (1. + exp((-26. - state[0] + IKr_V50A) / 7.));
    axr1 = 450. / (1. + exp((-45. - state[0] + IKr_V50A) / 10.));
    bxr1 = 6. / (1. + exp((state[0] + IKr_V50A - (-30.)) / 11.5));
    TAU_Xr1 = IKr_TauA * axr1 * bxr1;
    Xr2_INF = 1. / (1. + exp((state[0] + IKr_V50I - (-88.)) / 24.));
    axr2 = 3. / (1. + exp((-60. - state[0] + IKr_V50I) / 20.));
    bxr2 = 1.12 / (1. + exp((state[0] + IKr_V50I - 60.) / 20.));
    TAU_Xr2 = IKr_TauI * axr2 * bxr2;
    state[15] = Xr1_INF - (Xr1_INF - state[15]) * exp(-dt / TAU_Xr1);
    state[16] = Xr2_INF - (Xr2_INF - state[16]) * exp(-dt / TAU_Xr2);

    IKr = GKr * sqrt(Ko / 5.4) * state[15] * state[16] * (state[0] - Ek);

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GKs = 0.2352;
    else if (cellTissue == 21)
        GKs = 0.098;
    else if (cellTissue == 20 || cellTissue == 22)
        GKs = 0.392;
    else if (cellTissue == 24)
        GKs = 0.098 * 2;
    else
        GKs = 0.392 * 2;
    Xs_INF = 1. / (1. + exp((-5. - state[0]) / 14.));
    Axs = (1400. / (sqrt(1. + exp((5. - state[0] + IKs_V50A) / 6))));
    Bxs = (1. / (1. + exp((state[0] + IKr_V50I - 35.) / 15.)));
    TAU_Xs = IKr_TauA * Axs * Bxs + 80;
    state[17] = Xs_INF - (Xs_INF - state[17]) * exp(-dt / TAU_Xs);

    IKs = GKs * state[17] * state[17] * (state[0] - Eks);

    //APEX BASE HETERO
    if (cellTissue == 20 || cellTissue == 21 || cellTissue == 22) {
        IKs = IKs * ((-1.0 * (ABIndex - 10) / 318) + 2.0);
    }

    if (cellTissue != 13 && cellTissue != 14 && cellTissue != 15)
    {
        GK1 = 5.405;
        Ak1 = 0.1 / (1. + exp(0.06 * (state[0] - Ek - 200)));
        Bk1 = (3.*exp(0.0002 * (state[0] - Ek + 100)) + exp(0.1 * (state[0] - Ek - 10))) / (1. + exp(-0.5 * (state[0] - Ek)));
        rec_iK1 = Ak1 / (Ak1 + Bk1);
        IK1 = GK1 * rec_iK1 * (state[0] - Ek);
    }
    else
    {
        GK1 = 0.065;
        rec_iK1 = 1. / (1. + exp(0.1 * (state[0] + 75.44)));
        IK1 = GK1 * rec_iK1 * (state[0] - Ek - 8.0);
    }

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
    {
        Gsus = 0.0227;
        susa = 1. / (1. + exp((5 - state[0]) / 17.));
        Isus = Gsus * susa * (state[0] - Ek);
    }
    else
        Isus = 0.0;

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
    {
        Gfna = 0.0145654;
        Gfk = 0.0234346;
        y_inf = 1.0 / (1.0 + exp((state[0] + 80.6) / 6.8));
        Ay = exp(-2.9 - (0.04 * state[0] + If_V50A));
        By = exp(3.6 + (0.11 * state[0] + If_V50I));
        tau_y = If_TauA * 4000. / (Ay + By);
        state[18] = y_inf - (y_inf - state[18]) * exp(-dt / tau_y);
        ifna = Gfna * state[18] * (state[0] - Ena);
        ifk = Gfk * state[18] * (state[0] - Ek);
        If = ifk + ifna;
    }
    else
    {
        ifna = 0.0;
        ifk = 0.0;
        If = 0.0;
    }

    INaCa = knaca * (1. / (KmNai * KmNai * KmNai + Nao * Nao * Nao)) * (1. / (KmCa + Cao)) * (1. / (1 + ksat * exp((n - 1) * state[0] * F / (R * T)))) * (exp(n * state[0] * F / (R * T)) * state[2] * state[2] * state[2] * Cao - exp((n - 1) * state[0] * F / (R * T)) * Nao * Nao * Nao * state[1] * 2.5);

    rec_iNaK = (1. / (1. + 0.1245 * exp(-0.1 * state[0] * F / (R * T)) + 0.0353 * exp(-state[0] * F / (R * T))));
    INaK = knak * (Ko / (Ko + KmK)) * (state[2] / (state[2] + KmNa)) * rec_iNaK;

    IpCa = GpCa * state[1] / (KpCa + state[1]);

    rec_ipK = 1. / (1. + exp((25 - state[0]) / 5.98));
    IpK = GpK * rec_ipK * (state[0] - Ek);

    IbNa = GbNa * (state[0] - Ena);

    IbCa = GbCa * (state[0] - Eca);

    kCaSR = maxsr - ((maxsr - minsr) / (1 + (EC / state[4]) * (EC / state[4])));
    k1 = k1_ / kCaSR;
    k2 = k2_ * kCaSR;
    dRR = k4 * (1 - state[19]) - k2 * state[5] * state[19];
    state[19] += dt * dRR;
    state[20] = k1 * state[5] * state[5] * state[19] / (k3 + k1 * state[5] * state[5]);

    Irel = Vrel * state[20] * (state[4] - state[5]);
    Ileak = Vleak * (state[4] - state[1]);
    Iup = Vmaxup / (1. + ((Kup * Kup) / (state[1] * state[1])));
    Ixfer = Vxfer * (state[5] - state[1]);

    CaCSQN = Bufsr * state[4] / (state[4] + Kbufsr);
    dCaSR = dt * (Iup - Irel - Ileak);
    bjsr = Bufsr - CaCSQN - dCaSR - state[4] + Kbufsr;
    cjsr = Kbufsr * (CaCSQN + dCaSR + state[4]);
    state[4] = (sqrt(bjsr * bjsr + 4 * cjsr) - bjsr) / 2;

    CaSSBuf = Bufss * state[5] / (state[5] + Kbufss);
    dCaSS = dt * (-Ixfer * (Vc / Vss) + Irel * (Vsr / Vss) + (-ICaL * inversevssF2 * CAPACITANCE));
    bcss = Bufss - CaSSBuf - dCaSS - state[5] + Kbufss;
    ccss = Kbufss * (CaSSBuf + dCaSS + state[5]);
    state[5] = (sqrt(bcss * bcss + 4 * ccss) - bcss) / 2;

    CaBuf = Bufc * state[1] / (state[1] + Kbufc);
    dCai = dt * ((-(IbCa + IpCa - 2 * INaCa) * inverseVcF2 * CAPACITANCE) - (Iup - Ileak) * (Vsr / Vc) + Ixfer);
    bc = Bufc - CaBuf - dCai - state[1] + Kbufc;
    cc = Kbufc * (CaBuf + dCai + state[1]);
    state[1] = (sqrt(bc * bc + 4 * cc) - bc) / 2;

    dNai = -(INa + IbNa + 3 * INaK + 3 * INaCa + ifna) * inverseVcF * CAPACITANCE;
    state[2] += dt * dNai;

    dKi = -(IK1 + Ito + Isus + IKr + IKs - 2 * INaK + IpK + ifk) * inverseVcF * CAPACITANCE;
    state[3] += dt * dKi;

    return ((IKr_Drug * IKr) + (IKs_Drug * IKs) + IK1 + Ito + Isus + (INa_Drug * INa) + IbNa + (ICaL_Drug * ICaL) + IbCa + INaK + INaCa + IpCa + IpK + (If_Drug * If));
}

