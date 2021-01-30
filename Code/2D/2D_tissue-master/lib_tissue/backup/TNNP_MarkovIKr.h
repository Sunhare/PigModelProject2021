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

#ifndef TNNP_MarkovIKr_H
#define TNNP_MarkovIKr_H
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
//==================
// ten Tusscher Cell
//==================
//===========
// Cell types
//===========
// enum TypeCell { EPI, MCELL, ENDO };

class TTCell {
public:
    //-------------
    // Constructors
    //-------------
    TTCell(TypeCell celltype = EPI, double epiMidRatio = 1.5, double HT = 0.02);
    //-----------
    // Destructor
    //-----------
    ~TTCell();            // Redundant in this particular case!
    
    void Initialise();
    void SetPotential(double value);
    void RunSingleTimeStep(double,double );
    void ReturnPotentialByReference(double &res);
    void CurrentDependencies();
    //============================
    //Markov Model IKr Formulation
    //============================
    void CalculateMarkovIKr();
    void ComputeSteadyStateValues();
    void UpdateConcentrations();
    void UpdateGates();
    void UpdateVoltage(double);
    
    void SetCellType(TypeCell celltype = EPI);
    void SetEPIMRatio( double epiMidRatio = 1.5);
    void Setdt(double dt);

    double GetPotential();

    // void CalculateINa();
    // void CalculateICaL();

    // void CalculateIto();

    // void CalculateTTIKr();

    // void SetIStim(double value);


    // void CalculateIKs();

    // void CalculateIK1();

    // void CalculateINaCa();

    // void CalculateINaK();

    // void CalculateIpCa();

    // void CalculateIpK();

    // void CalculateIbNa();

    // void CalculateIbCa();

    // void CalculateINaL();

    // void CalculateItot();

    // void setBeats( std::size_t beats );
    // void setBCL( double bcl );
    // //=========
    // // Run Cell
    // //=========
    // void operator()( std::ofstream &output_file );
    double svolt;
private:


    //==================================
    // PARAMETERS FOR INITIAL CONDITIONS
    //==================================
    //Initial values of state variables
    double Cai;
    double CaSR;
    double CaSS;
    double Nai;
    double Ki;




    /*double dNai;
    double dKi;
    double dCai;
    double dCaSR;
    double dCaSS;
    double dRR;*/


    double Ek;
    double Ena;
    double Eks;
    double Eca;
    double CaCSQN;
    /*double bjsr;
    double cjsr;*/
    double CaSSBuf;
    /*double bcss;
    double ccss;*/
    double CaBuf;
    /* double bc;
     double cc;
     double Ak1;
     double Bk1;*/
    double rec_iK1;
    double rec_ipK;
    double rec_iNaK;
    /*double AM;
    double BM;
    double AH_1;
    double BH_1;
    double AH_2;
    double BH_2;
    double AJ_1;
    double BJ_1;
    double AJ_2;
    double BJ_2;*/
    double M_INF;
    double H_INF;
    double J_INF;
    double TAU_M;
    double TAU_H;
    double TAU_J;
    double axr1;
    double bxr1;
    double axr2;
    double bxr2;
    double Xr1_INF;
    double Xr2_INF;
    double TAU_Xr1;
    double TAU_Xr2;
    double Axs;
    double Bxs;
    double Xs_INF;
    double TAU_Xs;
    double R_INF;
    double TAU_R;
    double S_INF;
    double TAU_S;
    /*    double Ad;
        double Bd;
        double Cd;
        double Af;
        double Bf;
        double Cf;
        double Af2;
        double Bf2;
        double Cf2;*/
    double TAU_D;
    double D_INF;
    double TAU_F;
    double F_INF;
    double TAU_F2;
    double F2_INF;
    double TAU_FCaSS;
    double FCaSS_INF;

    double sm;
    double sh;
    double sj;
    double sxr1;
    double sxr2;
    double sxs;
    double ss;
    double sr;
    double sd;
    double sf;
    double sf2;
    double sfcass;
    double sRR;
    double sOO;
    double sItot;

    //==========================
    //Markov Formulation for IKr
    //==========================
    double wt_O;                                    /* Markov Model - Open Probability for IKr */
    double wt_C1;                                   /* Markov Model - C1 Probability for IKr */
    double wt_C2;                                   /* Markov Model - C2 Probability for IKr */
    double wt_C3;                                   /* Markov Model - C3 Probability for IKr */
    double wt_I;                                    /* Markov Model - I Probability for IKr */

    // double wt_dO;                                   /* Markov Model - dOpen Probability for IKr */
    // double wt_dC1;                              /* Markov Model - dC1 Probability for IKr */
    // double wt_dC2;                              /* Markov Model - dC2 Probability for IKr */
    // double wt_dC3;                              /* Markov Model - dC3 Probability for IKr */
    // double wt_dI;                                   /* Markov Model - dI Probability for IKr */

    // double wt_a1;                                   /* C1->O or C1->I */
    // double wt_a2;                                   /* C2->C1 */
    // double wt_a;                                    /* C3->C2 */
    // double wt_b;                                    /* C2->C3 */
    // double wt_b1;                                   /* C1->C2 */
    // double wt_b2;                                   /* O->C1 */
    // double wt_ai;                                   /* I->O */
    // double wt_bi;                                   /* O->I */
    // double wt_mu;

    double epi_factor, endo_factor, mcell_factor;

    //=====
    // INaL
    //=====
    double INaL;
    double GNaL;
    double mNaL;
    double hNaL;
    double alpha_mNaL;
    double beta_mNaL;
    double mNaL_INF;
    double hNaL_INF;
    double TAU_mNaL;
    double TAU_hNaL;
    //=====================================
    // PARAMETERS FOR STIMULATION PROTOCOLS
    //=====================================
    double stimduration;
    double stimstrength;
    double tbegin;
    double tend;
    double dia;
    double basicperiod;
    double basicapd;
    int counter;
    int repeats;
    double Istim;

    //
    double IKr;
    double IKs;
    double IK1;
    double Ito;
    double INa;
    double IbNa;
    double ICaL;
    double IbCa;
    double INaCa;
    double IpCa;
    double IpK;
    double INaK;
    double Irel;
    double Ileak;
    double Iup;
    double Ixfer;
    double k1;
    double k2;
    double kCaSR;


    /*almost constants */
    double m_epiMidRatio;
    TypeCell m_celltype;

    //Parameters for currents
    //Parameters for IKr
    double GKr;

    //Parameters for Iks
    double GKs;

    //Parameters for Ik1
    double GK1;

    //Parameters for Ito
    double Gto;

    //Parameters for INa
    double GNa;


  
    //==========================
    // PARAMETER FOR INTEGRATION
    //==========================
    double  m_HT; // time step
};




#endif