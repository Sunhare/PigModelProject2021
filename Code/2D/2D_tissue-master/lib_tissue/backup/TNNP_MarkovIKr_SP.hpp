/*
 * This header implements the ten Tusscher 2006 cardiac cell.
 * K. H. W. J. ten Tusscher and A. V. Panfilov, “Alternans
 * and spiral breakup in a human ventricular tissue model,”
 * Am. J. Physiol. Heart Circ. Physiol.
 *
 * Author (Original Version): KHJW ten Tusscher
 * Author (This C++ version): Ismail Adeniran <ismail.adeniran@manchester.ac.uk>
 * Date                     : 28th January, 2012
 * Date Modified            : 2nd January, 2015
 * Last Update: Haibo Ni, to include SingleTimeStep() function in.
 * Compile with: g++ -O3 -m64 -o ttcell TNNP_MarkovIKr.cpp (on Linux)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
// #include "AbstractCell.hpp"

#ifndef TNNP_MarkovIKr_SP_HPP
#define TNNP_MarkovIKr_SP_HPP
//===========
// Cell types
//===========
enum TypeCell { EPI, MCELL, ENDO };

#define TTCell_Ko ( 5.4)
#define TTCell_Cao ( 2.0)
#define TTCell_Nao ( 140.0)
#define TTCell_Vc ( 0.016404)
#define TTCell_Vsr ( 0.001094)
#define TTCell_Vss ( 0.00005468)
#define TTCell_Bufc ( 0.2)
#define TTCell_Kbufc ( 0.001)
#define TTCell_Bufsr ( 10.)
#define TTCell_Kbufsr ( 0.3)
#define TTCell_Bufss ( 0.4)
#define TTCell_Kbufss ( 0.00025)
#define TTCell_Vmaxup ( 0.006375)
#define TTCell_Kup ( 0.00025)
#define TTCell_Vrel ( 0.102) //40.8)
#define TTCell_k1_ ( 0.15)
#define TTCell_k2_ ( 0.045)
#define TTCell_k3 ( 0.060)
#define TTCell_k4 ( 0.005) //0.000015)
#define TTCell_EC ( 1.5)
#define TTCell_maxsr ( 2.5)
#define TTCell_minsr ( 1.)
#define TTCell_Vleak ( 0.00036)
#define TTCell_Vxfer ( 0.0038)
#define TTCell_R ( 8314.472)
#define TTCell_F ( 96485.3415)
#define TTCell_T ( 310.0)
#define TTCell_CAPACITANCE ( 0.185)
#define TTCell_pKNa ( 0.03)
#define TTCell_GbNa ( 0.00029)
#define TTCell_KmK ( 1.0)
#define TTCell_KmNa ( 40.0)
#define TTCell_knak ( 2.724)
#define TTCell_GCaL ( 0.00003980)
#define TTCell_GbCa ( 0.000592)
#define TTCell_knaca ( 1000)
#define TTCell_KmNai ( 87.5)
#define TTCell_KmCa ( 1.38)
#define TTCell_ksat ( 0.1)
#define TTCell_n ( 0.35)
#define TTCell_GpCa ( 0.1238)
#define TTCell_KpCa ( 0.0005)
#define TTCell_GpK ( 0.0146)

//
const static double TTCell_RTONF = (TTCell_R *TTCell_T) / TTCell_F;
const static double TTCell_inverseVcF2 = 1.0 / (2.0 * TTCell_Vc *TTCell_F);
const static double TTCell_inverseVcF = 1. / (TTCell_Vc *TTCell_F);
const static double TTCell_inversevssF2 = 1.0 / (2.0 * TTCell_Vss *TTCell_F);

class TNNP_MarkovIKr_SP/*: public AbstractCell*/ {
public:
    TNNP_MarkovIKr_SP(TypeCell usr_celltype=EPI, double usr_ratio=1.5, double usr_dt=0.02);
    ~TNNP_MarkovIKr_SP(){};
    double state[30];
    TypeCell m_celltype;
    float ZIndex;
    double m_epiMidRatio;
    void InitialiseStates( TypeCell usr_celltype);
    void SetPotential(double value);
    void RunSingleTimeStep(double dt, double Istim);
    void ReturnPotentialByReference(double &target);
    void SetCellType(TypeCell usr_celltype);
    double GetPotential();
};

TNNP_MarkovIKr_SP::TNNP_MarkovIKr_SP(TypeCell usr_celltype,double usr_ratio, double usr_dt)
    : m_celltype(usr_celltype),
    m_epiMidRatio(usr_ratio) {
    InitialiseStates(usr_celltype);
}
void TNNP_MarkovIKr_SP::InitialiseStates(TypeCell m_celltype) {
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

void TNNP_MarkovIKr_SP::SetPotential(double value) {
    state[0] = value;
}
void TNNP_MarkovIKr_SP::RunSingleTimeStep(double dt, double Istim) {

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

    double Ek = TTCell_RTONF * (std::log((TTCell_Ko / Ki)));
    double Ena = TTCell_RTONF * (std::log((TTCell_Nao / Nai)));
    double Eks = TTCell_RTONF * (std::log((TTCell_Ko + TTCell_pKNa * TTCell_Nao) / (Ki + TTCell_pKNa * Nai)));
    double Eca = 0.5 * TTCell_RTONF * (std::log((TTCell_Cao / Cai)));
    double Ak1 = 0.1 / (1. + std::exp(0.06 * (svolt - Ek - 200)));
    double Bk1 = (3.*std::exp(0.0002 * (svolt - Ek + 100)) +
                  std::exp(0.1 * (svolt - Ek - 10))) / (1. + std::exp(-0.5 * (svolt - Ek)));
    double rec_iK1 = Ak1 / (Ak1 + Bk1);
    double rec_iNaK = (1. / (1. + 0.1245 * std::exp(-0.1 * svolt * TTCell_F / (TTCell_R * TTCell_T)) + 0.0353 * std::exp(-svolt * TTCell_F / (TTCell_R * TTCell_T))));
    double rec_ipK = 1. / (1. + std::exp((25 - svolt) / 5.98));



    double R_INF;
    double S_INF;
    double TAU_R;
    double TAU_S;
    double GNaL, GKs, Gto;

    if (m_celltype == EPI) {
        GNaL = 0.0065;
        GKs = 0.392;
        Gto = 0.294;
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 20) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.*std::exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + std::exp((svolt - 20.) / 5.)) + 3.;
    } else if (m_celltype == ENDO) {
        GNaL = 0.0065;
        GKs = 0.392;
        Gto = 0.073;
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 28) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*std::exp(-(svolt + 67) * (svolt + 67) / 1000.) + 8.;
    } else if (m_celltype == MCELL) {
        GNaL = 0.0095;
        GKs = 0.098;
        Gto = 0.294;
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 20) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.0 * std::exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + std::exp((svolt - 20.) / 5.)) + 3.;
    }
    // std::cout << Gto << std::endl;
    /* Ito */
    ss = S_INF - (S_INF - ss) * std::exp(-dt / TAU_S);
    sr = R_INF - (R_INF - sr) * std::exp(-dt / TAU_R);
    double Ito = Gto * sr * ss * (svolt - Ek);

    /* INa */
    double TAU_H;
    double TAU_J;
    double AM = 1. / (1. + std::exp((-60. - svolt) / 5.));
    double BM = 0.1 / (1. + std::exp((svolt + 35.) / 5.)) + 0.10 / (1. + std::exp((svolt - 50.) / 200.));
    double TAU_M = AM * BM;
    double M_INF = 1. / ((1. + std::exp((-56.86 - svolt) / 9.03)) * (1. + std::exp((-56.86 - svolt) / 9.03)));
    if (svolt >= -40.)
    {
        double AH_1 = 0.;
        double BH_1 = (0.77 / (0.13 * (1. + std::exp(-(svolt + 10.66) / 11.1))));
        TAU_H = 1.0 / (AH_1 + BH_1);
    }
    else
    {
        double AH_2 = (0.057 * std::exp(-(svolt + 80.) / 6.8));
        double BH_2 = (2.7 * std::exp(0.079 * svolt) + (3.1e5) * std::exp(0.3485 * svolt));
        TAU_H = 1.0 / (AH_2 + BH_2);
    }
    double H_INF = 1. / ((1. + std::exp((svolt + 71.55) / 7.43)) * (1. + std::exp((svolt + 71.55) / 7.43)));
    if (svolt >= -40.)
    {
        double AJ_1 = 0.;
        double BJ_1 = (0.6 * std::exp((0.057) * svolt) / (1. + std::exp(-0.1 * (svolt + 32.))));
        TAU_J = 1.0 / (AJ_1 + BJ_1);
    }
    else
    {
        double AJ_2 = (((-2.5428e4) * std::exp(0.2444 * svolt) - (6.948e-6) *
                        std::exp(-0.04391 * svolt)) * (svolt + 37.78) /
                       (1. + std::exp(0.311 * (svolt + 79.23))));
        double BJ_2 = (0.02424 * std::exp(-0.01052 * svolt) / (1. + std::exp(-0.1378 * (svolt + 40.14))));
        TAU_J = 1.0 / (AJ_2 + BJ_2);
    }
    double J_INF = H_INF;

    sm = M_INF - (M_INF - sm) * std::exp(-dt / TAU_M);
    sh = H_INF - (H_INF - sh) * std::exp(-dt / TAU_H);
    sj = J_INF - (J_INF - sj) * std::exp(-dt / TAU_J);
    double GNa = 14.838;
    double INa = GNa * sm * sm * sm * sh * sj * (svolt - Ena);

    /* IKr */  // CalculateTTIKr
    double Xr1_INF;
    double Xr2_INF;
    double TAU_Xr1;
    double TAU_Xr2;
    double GKr = 0.153;
    Xr1_INF = 1. / (1. + std::exp((-26. - svolt) / 7.));
    double axr1 = 450. / (1. + std::exp((-45. - svolt) / 10.));
    double bxr1 = 6. / (1. + std::exp((svolt - (-30.)) / 11.5));
    TAU_Xr1 = axr1 * bxr1;
    Xr2_INF = 1. / (1. + std::exp((svolt - (-88.)) / 24.));
    double axr2 = 3. / (1. + std::exp((-60. - svolt) / 20.));
    double bxr2 = 1.12 / (1. + std::exp((svolt - 60.) / 20.));
    TAU_Xr2 = axr2 * bxr2;
    sxr1 = Xr1_INF - (Xr1_INF - sxr1) * std::exp(-dt / TAU_Xr1);
    sxr2 = Xr2_INF - (Xr2_INF - sxr2) * std::exp(-dt / TAU_Xr2);
    // double IKr =  GKr * std::sqrt(TTCell_Ko / 5.4) * sxr1 * sxr2 * (svolt - Ek);
    // CalculateMarkovIKr();

    /* Marcov IKr Model */
     // m_epiMidRatio = 1.5;
    double epi_factor   = 1.8 * m_epiMidRatio;
    double endo_factor  = 1.8;
    double mcell_factor = 1.8;
    double wt_a1 =  2.172;
    double wt_b1 =  1.077;
    double wt_a2 =  0.00655   * std::exp(0.5 * 0.05547153 * (svolt - 36.));
    double wt_a  =  0.00555   * std::exp(      0.05547153 * (svolt - 12.));
    double wt_b  =  0.002357  * std::exp(      -0.036588 * (svolt));
    double wt_b2 = 0.65 * 0.0029357 * std::exp(0.69 * -0.02158 * (svolt));
    double wt_ai = 0.11 * 0.439     * std::exp(1.7 *  -0.02352 * (svolt + 25.)) * (4.5 / TTCell_Ko);
    double wt_bi = 0.4 *  0.656     * std::exp(      0.000942 * (svolt)) * ((std::pow((4.5 / TTCell_Ko), 0.3)));
    double wt_mu = (wt_ai * wt_b2) / wt_bi;

    if (m_celltype == ENDO)
        GKr = 0.0135 * std::pow(TTCell_Ko, 0.59) * endo_factor;
    else if (m_celltype == MCELL)
        GKr = 0.0135 * std::pow(TTCell_Ko, 0.59) * mcell_factor;
    else
        GKr = 0.0135 * std::pow(TTCell_Ko, 0.59) * epi_factor;

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
    double Xs_INF = 1. / (1. + std::exp((-5. - svolt) / 14.));
    double Axs = (1400. / (std::sqrt(1. + std::exp((5. - svolt) / 6))));
    double Bxs = (1. / (1. + std::exp((svolt - 35.) / 15.)));
    double TAU_Xs = Axs * Bxs + 80;
    sxs = Xs_INF - (Xs_INF - sxs) * std::exp(-dt / TAU_Xs);
    double IKs = GKs * sxs * sxs * (svolt - Eks);

    /* ICaL */
    double D_INF = 1. / (1. + std::exp((-8 - svolt) / 7.5));
    double Ad = 1.4 / (1. + std::exp((-35 - svolt) / 13)) + 0.25;
    double Bd = 1.4 / (1. + std::exp((svolt + 5) / 5));
    double Cd = 1. / (1. + std::exp((50 - svolt) / 20));
    double TAU_D = Ad * Bd + Cd;
    double F_INF = 1. / (1. + std::exp((svolt + 20) / 7));
    double Af = 1102.5 * std::exp(-(svolt + 27) * (svolt + 27) / 225);
    double Bf = 200. / (1 + std::exp((13 - svolt) / 10.));
    double Cf = (180. / (1 + std::exp((svolt + 30) / 10))) + 20;
    double TAU_F = Af + Bf + Cf;

    double F2_INF = 0.67 / (1. + std::exp((svolt + 35) / 7)) + 0.33;
    double Af2 = 600 * std::exp(-(svolt + 25) * (svolt + 25) / 170);
    double Bf2 = 31 / (1. + std::exp((25 - svolt) / 10));
    double Cf2 = 16 / (1. + std::exp((svolt + 30) / 10));
    double TAU_F2 = Af2 + Bf2 + Cf2;

    sd = D_INF - (D_INF - sd) * std::exp(-dt / TAU_D);
    sf = F_INF - (F_INF - sf) * std::exp(-dt / TAU_F);
    sf2 = F2_INF - (F2_INF - sf2) * std::exp(-dt / TAU_F2);

    double FCaSS_INF = 0.6 / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 0.4;
    double TAU_FCaSS = 80. / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 2.;
    sfcass = FCaSS_INF - (FCaSS_INF - sfcass) * std::exp(-dt / TAU_FCaSS);

    double ICaL = TTCell_GCaL * sd * sf * sf2 * sfcass * 4 * (svolt - 15) * (TTCell_F * TTCell_F / (TTCell_R * TTCell_T)) *
                  (0.25 * std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) * CaSS - TTCell_Cao) / (std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) - 1.);

    //INaL gates
    double mNaL_INF, hNaL_INF, TAU_mNaL, TAU_hNaL;
    mNaL_INF = hNaL_INF = 0.0;
    // need to update INaL later...
    // mNaL = mNaL_INF - (mNaL_INF - mNaL) * std::exp(-dt / TAU_mNaL);
    // hNaL = hNaL_INF - (hNaL_INF - hNaL) * std::exp(-dt / TAU_hNaL);
    // double INaL = GNaL * mNaL * mNaL * mNaL * hNaL * (svolt - Ena);
    double INaL = 0.0;
    double IbNa = TTCell_GbNa * (svolt - Ena);
    double IbCa = TTCell_GbCa * (svolt - Eca);
    double IpK = TTCell_GpK * rec_ipK * (svolt - Ek);
    double IpCa = TTCell_GpCa * Cai / (TTCell_KpCa + Cai);
    double INaK = TTCell_knak * (TTCell_Ko / (TTCell_Ko + TTCell_KmK)) * (Nai / (Nai + TTCell_KmNa)) * rec_iNaK;
    double INaCa = TTCell_knaca * (1. / (TTCell_KmNai * TTCell_KmNai * TTCell_KmNai + TTCell_Nao * TTCell_Nao * TTCell_Nao)) * (1. / (TTCell_KmCa + TTCell_Cao)) *
                   (1. / (1 + TTCell_ksat * std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)))) *
                   (std::exp(TTCell_n * svolt * TTCell_F / (TTCell_R * TTCell_T)) * Nai * Nai * Nai * TTCell_Cao -
                    std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)) * TTCell_Nao * TTCell_Nao * TTCell_Nao * Cai * 2.5);

    double GK1 = 5.405;
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
    CaSR = (std::sqrt(bjsr * bjsr + 4 * cjsr) - bjsr) / 2;


    double CaSSBuf = TTCell_Bufss * CaSS / (CaSS + TTCell_Kbufss);
    double dCaSS = dt * (-Ixfer * (TTCell_Vc / TTCell_Vss) + Irel * (TTCell_Vsr / TTCell_Vss) + (-ICaL * TTCell_inversevssF2 * TTCell_CAPACITANCE));
    double bcss = TTCell_Bufss - CaSSBuf - dCaSS - CaSS + TTCell_Kbufss;
    double ccss = TTCell_Kbufss * (CaSSBuf + dCaSS + CaSS);
    CaSS = (std::sqrt(bcss * bcss + 4 * ccss) - bcss) / 2;


    double CaBuf = TTCell_Bufc * Cai / (Cai + TTCell_Kbufc);
    double dCai = dt * ((-(IbCa + IpCa - 2 * INaCa) * TTCell_inverseVcF2 * TTCell_CAPACITANCE) - (Iup - Ileak) * (TTCell_Vsr / TTCell_Vc) + Ixfer);
    double bc = TTCell_Bufc - CaBuf - dCai - Cai + TTCell_Kbufc;
    double cc = TTCell_Kbufc * (CaBuf + dCai + Cai);
    Cai = (std::sqrt(bc * bc + 4 * cc) - bc) / 2;


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

    state[0] += sItot*dt;
}

void TNNP_MarkovIKr_SP::ReturnPotentialByReference(double &target){
    target = state[0];
}

void TNNP_MarkovIKr_SP::SetCellType(TypeCell usr_celltype) {
    m_celltype = usr_celltype;
}
double TNNP_MarkovIKr_SP::GetPotential() {
    return state[0];
}
#endif