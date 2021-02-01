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



#ifndef TNNP_MarkovIKr_C
#define TNNP_MarkovIKr_C
#include "TNNP_MarkovIKr.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

//==================
// ten Tusscher Cell
//==================
//-------------
// Constructors
//-------------
TTCell::TTCell(TypeCell celltype, double epiMidRatio, double HT)
    : m_celltype(celltype), m_epiMidRatio(epiMidRatio), m_HT(HT)  {

    SetCellType(celltype);
    SetEPIMRatio(epiMidRatio);
    Setdt(HT);
    Initialise();
}

//-----------
// Destructor
//-----------
TTCell::~TTCell() {}            // Redundant in this particular case!

void TTCell::Initialise() {


    svolt = -86.2;
    Cai = 0.00007;
    CaSR = 1.3;
    CaSS = 0.00007;
    Nai = 7.67;
    Ki = 138.3;
    GNa = 14.838;
    GKr = 0.153;

    stimduration = 1.;
    stimstrength = -52;
    tbegin = 0;
    tend = tbegin + stimduration;
    counter = 1;
    dia = 5000;
    basicperiod = 1000.0;
    basicapd = 274;
    repeats = 10;
    sm = 0.0;
    sh = 0.75;
    sj = 0.75;
    sxr1 = 0.0;
    sxr2 = 1.0;
    sxs = 0.0;
    ss = 1.0;
    sr = 0.0;
    sd = 0.0;
    sf = 1.0;
    sf2 = 1.0;
    sfcass = 1.0;
    sRR = 1.0;
    sOO = 0.0;
    svolt = -86.2;
    Cai;
    CaSR;
    CaSS;
    Nai;
    Ki;
    sItot = 0.0;

    // SQT1
    wt_C3 = 1.0;
    wt_O = 0.0;
    wt_C1 = 0.0;
    wt_C2 = 0.0;
    wt_I = 0.0;
    // wt_a1 = 2.172;
    // wt_b1 = 1.077;

    // INaL
    mNaL = hNaL = alpha_mNaL = beta_mNaL = mNaL_INF = hNaL_INF = TAU_mNaL = INaL = 0.0;
    TAU_hNaL = 600;
}
void TTCell:: SetPotential(double value) {
    svolt = value;
}
void TTCell:: RunSingleTimeStep(double _dt, double usr_istim) {

    //===============
    m_HT = _dt;
    CurrentDependencies();
    // CalculateINa();
    // CalculateICaL();
    // CalculateIto();
    //CalculateTTIKr();
    CalculateMarkovIKr();
    // CalculateIKs();
    /*CalculateIK1();
    CalculateINaCa();
    CalculateINaK();
    CalculateIpCa();
    CalculateIpK();
    CalculateIbNa();
    CalculateIbCa();
    CalculateINaL();
    CalculateItot();*/
    ComputeSteadyStateValues();
    UpdateConcentrations();
    // UpdateGates();
    UpdateVoltage(usr_istim);
}
void TTCell::ReturnPotentialByReference(double &res) {
    res = svolt;
}
void TTCell::CurrentDependencies()
{
    Ek = TTCell_RTONF * (std::log((TTCell_Ko / Ki)));
    Ena = TTCell_RTONF * (std::log((TTCell_Nao / Nai)));
    Eks = TTCell_RTONF * (std::log((TTCell_Ko + TTCell_pKNa * TTCell_Nao) / (Ki + TTCell_pKNa * Nai)));
    Eca = 0.5 * TTCell_RTONF * (std::log((TTCell_Cao / Cai)));
    double Ak1 = 0.1 / (1. + std::exp(0.06 * (svolt - Ek - 200)));
    double Bk1 = (3.*std::exp(0.0002 * (svolt - Ek + 100)) +
                  std::exp(0.1 * (svolt - Ek - 10))) / (1. + std::exp(-0.5 * (svolt - Ek)));
    rec_iK1 = Ak1 / (Ak1 + Bk1);
    rec_iNaK = (1. / (1. + 0.1245 * std::exp(-0.1 * svolt * TTCell_F / (TTCell_R * TTCell_T)) + 0.0353 * std::exp(-svolt * TTCell_F / (TTCell_R * TTCell_T))));
    rec_ipK = 1. / (1. + std::exp((25 - svolt) / 5.98));
}
//============================
//Markov Model IKr Formulation
//============================
void TTCell:: CalculateMarkovIKr() {
    epi_factor      = 1.8   *   m_epiMidRatio;
    endo_factor     = 1.8;
    mcell_factor    = 1.8;

    double wt_a1 =  2.172;
    double wt_b1 =  1.077;
    double wt_a2 =  0.00655   * std::exp(0.5 *            0.05547153 * (svolt - 36.));
    double wt_a  =  0.00555   * std::exp(                0.05547153 * (svolt - 12.));
    double wt_b  =  0.002357  * std::exp(                -0.036588 * (svolt));
    double wt_b2 = 0.65 *       0.0029357 * std::exp(0.69 *           -0.02158 * (svolt));
    double wt_ai = 0.11 *       0.439     * std::exp(1.7 *            -0.02352 * (svolt + 25.)) * (4.5 / TTCell_Ko);
    double wt_bi = 0.4 *        0.656     * std::exp(                0.000942 * (svolt)) * ((std::pow((4.5 / TTCell_Ko), 0.3)));
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

    wt_O  += m_HT * wt_dO;
    wt_C1 += m_HT * wt_dC1;
    wt_C2 += m_HT * wt_dC2;
    wt_C3 += m_HT * wt_dC3;
    wt_I  += m_HT * wt_dI;

    IKr = GKr * wt_O * (svolt - Ek);
}   //> END Markov IKr

void TTCell:: ComputeSteadyStateValues()
{
    /* INa */
    double AM = 1. / (1. + std::exp((-60. - svolt) / 5.));
    double BM = 0.1 / (1. + std::exp((svolt + 35.) / 5.)) + 0.10 / (1. + std::exp((svolt - 50.) / 200.));
    TAU_M = AM * BM;
    M_INF = 1. / ((1. + std::exp((-56.86 - svolt) / 9.03)) * (1. + std::exp((-56.86 - svolt) / 9.03)));
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
    H_INF = 1. / ((1. + std::exp((svolt + 71.55) / 7.43)) * (1. + std::exp((svolt + 71.55) / 7.43)));
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
    J_INF = H_INF;

    sm = M_INF - (M_INF - sm) * std::exp(-m_HT / TAU_M);
    sh = H_INF - (H_INF - sh) * std::exp(-m_HT / TAU_H);
    sj = J_INF - (J_INF - sj) * std::exp(-m_HT / TAU_J);

    INa = GNa * sm * sm * sm * sh * sj * (svolt - Ena);

    /* IKr */
    Xr1_INF = 1. / (1. + std::exp((-26. - svolt) / 7.));
    double axr1 = 450. / (1. + std::exp((-45. - svolt) / 10.));
    double bxr1 = 6. / (1. + std::exp((svolt - (-30.)) / 11.5));
    TAU_Xr1 = axr1 * bxr1;
    Xr2_INF = 1. / (1. + std::exp((svolt - (-88.)) / 24.));
    double axr2 = 3. / (1. + std::exp((-60. - svolt) / 20.));
    double bxr2 = 1.12 / (1. + std::exp((svolt - 60.) / 20.));
    TAU_Xr2 = axr2 * bxr2;
    sxr1 = Xr1_INF - (Xr1_INF - sxr1) * std::exp(-m_HT / TAU_Xr1);
    sxr2 = Xr2_INF - (Xr2_INF - sxr2) * std::exp(-m_HT / TAU_Xr2);
    // CalculateMarkovIKr();

    /* IKs */
    Xs_INF = 1. / (1. + std::exp((-5. - svolt) / 14.));
    double Axs = (1400. / (std::sqrt(1. + std::exp((5. - svolt) / 6))));
    double Bxs = (1. / (1. + std::exp((svolt - 35.) / 15.)));
    TAU_Xs = Axs * Bxs + 80;
    sxs = Xs_INF - (Xs_INF - sxs) * std::exp(-m_HT / TAU_Xs);
    IKs = GKs * sxs * sxs * (svolt - Eks);


    /* Ito */
    if (m_celltype == EPI) {
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 20) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.*std::exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + std::exp((svolt - 20.) / 5.)) + 3.;
    }
    else if (m_celltype == ENDO) {
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 28) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 1000.*std::exp(-(svolt + 67) * (svolt + 67) / 1000.) + 8.;
    }
    else {
        R_INF = 1. / (1. + std::exp((20 - svolt) / 6.));
        S_INF = 1. / (1. + std::exp((svolt + 20) / 5.));
        TAU_R = 9.5 * std::exp(-(svolt + 40.) * (svolt + 40.) / 1800.) + 0.8;
        TAU_S = 85.*std::exp(-(svolt + 45.) * (svolt + 45.) / 320.) + 5. / (1. + std::exp((svolt - 20.) / 5.)) + 3.;
    }
    ss = S_INF - (S_INF - ss) * std::exp(-m_HT / TAU_S);
    sr = R_INF - (R_INF - sr) * std::exp(-m_HT / TAU_R);
    Ito = Gto * sr * ss * (svolt - Ek);


    /* ICaL */
    D_INF = 1. / (1. + std::exp((-8 - svolt) / 7.5));
    double Ad = 1.4 / (1. + std::exp((-35 - svolt) / 13)) + 0.25;
    double Bd = 1.4 / (1. + std::exp((svolt + 5) / 5));
    double Cd = 1. / (1. + std::exp((50 - svolt) / 20));
    TAU_D = Ad * Bd + Cd;
    F_INF = 1. / (1. + std::exp((svolt + 20) / 7));
    double Af = 1102.5 * std::exp(-(svolt + 27) * (svolt + 27) / 225);
    double Bf = 200. / (1 + std::exp((13 - svolt) / 10.));
    double Cf = (180. / (1 + std::exp((svolt + 30) / 10))) + 20;
    TAU_F = Af + Bf + Cf;

    F2_INF = 0.67 / (1. + std::exp((svolt + 35) / 7)) + 0.33;
    double Af2 = 600 * std::exp(-(svolt + 25) * (svolt + 25) / 170);
    double Bf2 = 31 / (1. + std::exp((25 - svolt) / 10));
    double Cf2 = 16 / (1. + std::exp((svolt + 30) / 10));
    TAU_F2 = Af2 + Bf2 + Cf2;

    sd = D_INF - (D_INF - sd) * std::exp(-m_HT / TAU_D);
    sf = F_INF - (F_INF - sf) * std::exp(-m_HT / TAU_F);
    sf2 = F2_INF - (F2_INF - sf2) * std::exp(-m_HT / TAU_F2);

    ICaL = TTCell_GCaL * sd * sf * sf2 * sfcass * 4 * (svolt - 15) * (TTCell_F * TTCell_F / (TTCell_R * TTCell_T)) *
           (0.25 * std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) * CaSS - TTCell_Cao) / (std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) - 1.);

    FCaSS_INF = 0.6 / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 0.4;
    TAU_FCaSS = 80. / (1 + (CaSS / 0.05) * (CaSS / 0.05)) + 2.;
    sfcass = FCaSS_INF - (FCaSS_INF - sfcass) * std::exp(-m_HT / TAU_FCaSS);

    //INaL gates
    mNaL = mNaL_INF - (mNaL_INF - mNaL) * std::exp(-m_HT / TAU_mNaL);
    hNaL = hNaL_INF - (hNaL_INF - hNaL) * std::exp(-m_HT / TAU_hNaL);

    if       (m_celltype == EPI)   GNaL = 0.0065;
    else if  (m_celltype == ENDO)  GNaL = 0.0065;
    else if  (m_celltype == MCELL) GNaL = 0.0095;

    INaL = GNaL * mNaL * mNaL * mNaL * hNaL * (svolt - Ena);
    IbNa = TTCell_GbNa * (svolt - Ena);
    IbCa = TTCell_GbCa * (svolt - Eca);
    IpK = TTCell_GpK * rec_ipK * (svolt - Ek);
    IpCa = TTCell_GpCa * Cai / (TTCell_KpCa + Cai);
    INaK = TTCell_knak * (TTCell_Ko / (TTCell_Ko + TTCell_KmK)) * (Nai / (Nai + TTCell_KmNa)) * rec_iNaK;
    INaCa = TTCell_knaca * (1. / (TTCell_KmNai * TTCell_KmNai * TTCell_KmNai + TTCell_Nao * TTCell_Nao * TTCell_Nao)) * (1. / (TTCell_KmCa + TTCell_Cao)) *
            (1. / (1 + TTCell_ksat * std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)))) *
            (std::exp(TTCell_n * svolt * TTCell_F / (TTCell_R * TTCell_T)) * Nai * Nai * Nai * TTCell_Cao -
             std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)) * TTCell_Nao * TTCell_Nao * TTCell_Nao * Cai * 2.5);
    IK1 = GK1 * rec_iK1 * (svolt - Ek);
    sItot = IKr + IKs + IK1 + Ito + INa + IbNa + ICaL + IbCa + INaK + INaCa + IpCa + IpK + INaL;
}
void TTCell:: UpdateConcentrations()
{
    double kCaSR = TTCell_maxsr - ((TTCell_maxsr - TTCell_minsr) / (1 + (TTCell_EC / CaSR) * (TTCell_EC / CaSR)));
    double k1 = TTCell_k1_ / kCaSR;
    double k2 = TTCell_k2_ * kCaSR;
    double dRR = TTCell_k4 * (1 - sRR) - k2 * CaSS * sRR;
    sRR += m_HT * dRR;
    double sOO = k1 * CaSS * CaSS * sRR / (TTCell_k3 + k1 * CaSS * CaSS);


    Irel = TTCell_Vrel * sOO * (CaSR - CaSS);
    Ileak = TTCell_Vleak * (CaSR - Cai);
    Iup = TTCell_Vmaxup / (1. + ((TTCell_Kup * TTCell_Kup) / (Cai * Cai)));
    Ixfer = TTCell_Vxfer * (CaSS - Cai);

    double CaCSQN = TTCell_Bufsr * CaSR / (CaSR + TTCell_Kbufsr);
    double dCaSR = m_HT * (Iup - Irel - Ileak);
    double bjsr = TTCell_Bufsr - CaCSQN - dCaSR - CaSR + TTCell_Kbufsr;
    double cjsr = TTCell_Kbufsr * (CaCSQN + dCaSR + CaSR);
    CaSR = (std::sqrt(bjsr * bjsr + 4 * cjsr) - bjsr) / 2;


    double CaSSBuf = TTCell_Bufss * CaSS / (CaSS + TTCell_Kbufss);
    double dCaSS = m_HT * (-Ixfer * (TTCell_Vc / TTCell_Vss) + Irel * (TTCell_Vsr / TTCell_Vss) + (-ICaL * TTCell_inversevssF2 * TTCell_CAPACITANCE));
    double bcss = TTCell_Bufss - CaSSBuf - dCaSS - CaSS + TTCell_Kbufss;
    double ccss = TTCell_Kbufss * (CaSSBuf + dCaSS + CaSS);
    CaSS = (std::sqrt(bcss * bcss + 4 * ccss) - bcss) / 2;


    double CaBuf = TTCell_Bufc * Cai / (Cai + TTCell_Kbufc);
    double dCai = m_HT * ((-(IbCa + IpCa - 2 * INaCa) * TTCell_inverseVcF2 * TTCell_CAPACITANCE) - (Iup - Ileak) * (TTCell_Vsr / TTCell_Vc) + Ixfer);
    double bc = TTCell_Bufc - CaBuf - dCai - Cai + TTCell_Kbufc;
    double cc = TTCell_Kbufc * (CaBuf + dCai + Cai);
    Cai = (std::sqrt(bc * bc + 4 * cc) - bc) / 2;


    double dNai = -(INa + IbNa + 3 * INaK + 3 * INaCa) * TTCell_inverseVcF * TTCell_CAPACITANCE;
    Nai += m_HT * dNai;

    double dKi = -(Istim + IK1 + Ito + IKr + IKs - 2 * INaK + IpK) * TTCell_inverseVcF * TTCell_CAPACITANCE;
    Ki += m_HT * dKi;
}



void TTCell:: UpdateGates()
{
    sm = M_INF - (M_INF - sm) * std::exp(-m_HT / TAU_M);
    sh = H_INF - (H_INF - sh) * std::exp(-m_HT / TAU_H);
    sj = J_INF - (J_INF - sj) * std::exp(-m_HT / TAU_J);
    sxr1 = Xr1_INF - (Xr1_INF - sxr1) * std::exp(-m_HT / TAU_Xr1);
    sxr2 = Xr2_INF - (Xr2_INF - sxr2) * std::exp(-m_HT / TAU_Xr2);
    sxs = Xs_INF - (Xs_INF - sxs) * std::exp(-m_HT / TAU_Xs);
    ss = S_INF - (S_INF - ss) * std::exp(-m_HT / TAU_S);
    sr = R_INF - (R_INF - sr) * std::exp(-m_HT / TAU_R);
    sd = D_INF - (D_INF - sd) * std::exp(-m_HT / TAU_D);
    sf = F_INF - (F_INF - sf) * std::exp(-m_HT / TAU_F);
    sf2 = F2_INF - (F2_INF - sf2) * std::exp(-m_HT / TAU_F2);
    sfcass = FCaSS_INF - (FCaSS_INF - sfcass) * std::exp(-m_HT / TAU_FCaSS);

    //INaL gates
    mNaL = mNaL_INF - (mNaL_INF - mNaL) * std::exp(-m_HT / TAU_mNaL);
    hNaL = hNaL_INF - (hNaL_INF - hNaL) * std::exp(-m_HT / TAU_hNaL);
}

void TTCell::UpdateVoltage(double usr_istim)
{
    svolt = svolt + m_HT * (-sItot + usr_istim);
}


void TTCell:: SetCellType(TypeCell celltype) {
    if (m_celltype == EPI)
        GKs = 0.392;
    else if (m_celltype == ENDO)
        GKs = 0.392;
    else
        GKs = 0.098;

    GK1 = 5.405;
    //Parameters for Ito
    if (m_celltype == EPI)
        Gto = 0.294;
    else if (m_celltype == ENDO)
        Gto = 0.073;
    else
        Gto = 0.294;
}
void TTCell::SetEPIMRatio(double epiMidRatio) {
    m_epiMidRatio = epiMidRatio;
}
void TTCell:: Setdt(double dt) {
    m_HT = dt;
}
double TTCell::GetPotential() {
    return svolt;
}



/*void TTCell:: CalculateINa()
{
    INa = GNa * sm * sm * sm * sh * sj * (svolt - Ena);
}

void TTCell:: CalculateICaL()
{
    ICaL = TTCell_GCaL * sd * sf * sf2 * sfcass * 4 * (svolt - 15) * (TTCell_F * TTCell_F / (TTCell_R * TTCell_T)) *
           (0.25 * std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) * CaSS - TTCell_Cao) / (std::exp(2 * (svolt - 15) * TTCell_F / (TTCell_R * TTCell_T)) - 1.);
}

void TTCell:: CalculateIto()
{
    Ito = Gto * sr * ss * (svolt - Ek);
}

void TTCell:: CalculateTTIKr()
{
    IKr = GKr * std::sqrt(TTCell_Ko / 5.4) * sxr1 * sxr2 * (svolt - Ek);
}



void TTCell:: SetIStim(double value) {
    Istim = value;
}



void TTCell:: CalculateIKs()
{
    IKs = GKs * sxs * sxs * (svolt - Eks);
}

void TTCell:: CalculateIK1()
{
    IK1 = GK1 * rec_iK1 * (svolt - Ek);
}

void TTCell:: CalculateINaCa() {
    INaCa = TTCell_knaca * (1. / (TTCell_KmNai * TTCell_KmNai * TTCell_KmNai + TTCell_Nao * TTCell_Nao * TTCell_Nao)) * (1. / (TTCell_KmCa + TTCell_Cao)) *
            (1. / (1 + TTCell_ksat * std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)))) *
            (std::exp(TTCell_n * svolt * TTCell_F / (TTCell_R * TTCell_T)) * Nai * Nai * Nai * TTCell_Cao -
             std::exp((TTCell_n - 1) * svolt * TTCell_F / (TTCell_R * TTCell_T)) * TTCell_Nao * TTCell_Nao * TTCell_Nao * Cai * 2.5);
}

void TTCell:: CalculateINaK()
{
    INaK = TTCell_knak * (TTCell_Ko / (TTCell_Ko + TTCell_KmK)) * (Nai / (Nai + TTCell_KmNa)) * rec_iNaK;
}

void TTCell:: CalculateIpCa()
{
    IpCa = TTCell_GpCa * Cai / (TTCell_KpCa + Cai);
}

void TTCell:: CalculateIpK()
{
    IpK = TTCell_GpK * rec_ipK * (svolt - Ek);
}

void TTCell:: CalculateIbNa()
{
    IbNa = TTCell_GbNa * (svolt - Ena);
}

void TTCell:: CalculateIbCa()
{
    IbCa = TTCell_GbCa * (svolt - Eca);
}

void TTCell:: CalculateINaL() {
    if       (m_celltype == EPI)   GNaL = 0.0065;
    else if  (m_celltype == ENDO)  GNaL = 0.0065;
    else if  (m_celltype == MCELL) GNaL = 0.0095;

    INaL = GNaL * mNaL * mNaL * mNaL * hNaL * (svolt - Ena);
}

void TTCell:: CalculateItot()
{
    sItot = IKr + IKs + IK1 + Ito + INa + IbNa + ICaL + IbCa + INaK + INaCa + IpCa + IpK + INaL ;
}



void TTCell:: setBeats( std::size_t beats ) {
    repeats = beats;
}

void TTCell:: setBCL( double bcl ) {
    basicperiod = bcl;
}

//=========
// Run Cell
//=========
void TTCell::operator()( std::ofstream &output_file )
{
    double t = 0;   // Time
    std::size_t total_simulation_steps = static_cast<std::size_t>( repeats * basicperiod / m_HT );
    double Istim;
    for ( std::size_t step = 0; step < total_simulation_steps; ++step )
    {
        t += m_HT;

        if (t >= tbegin and t <= tend)
            Istim = stimstrength;
        if (t > tend) {
            Istim = 0.0;
            tbegin = tbegin + basicperiod;
            tend = tbegin + stimduration;
            ++counter;

            std::cout << "Stimulus " << counter << " applied, Time = " << tbegin << std::endl;
        }

        //===============
        CurrentDependencies();
        CalculateINa();
        CalculateICaL();
        CalculateIto();
        // CalculateTTIKr();
        CalculateMarkovIKr();
        CalculateIKs();
        CalculateIK1();
        CalculateINaCa();
        CalculateINaK();
        CalculateIpCa();
        CalculateIpK();
        CalculateIbNa();
        CalculateIbCa();
        CalculateINaL();
        CalculateItot();
        UpdateConcentrations();

        // Write Currents To File
        if ( step >= ( static_cast<std::size_t>((repeats - 1)*basicperiod / m_HT) - 50 / m_HT ) ) { // Output last beat
            output_file << TTCell_T        << std::setw(15)
                        << svolt    << std::setw(15)
                        << IKr      << std::setw(15)
                        << std::endl;
        }

        ComputeSteadyStateValues();
        UpdateGates();
        UpdateVoltage(Istim);
        //===============

    } // END: step loop
}
*/
#endif