/*
 * crn_con.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Friday, March 14, 2008 @ 14:39
 * Modified: Saturday, August 30, 2008 @ 21:42
 *
 * Functions to solve the Courtemanche, Ramirez, Nattel model of
 * the human atrial myocyte in control conditions.
 *
 * The reason for the unique name is to allow different cells to be easily
 * included in constructed multicellular preparations, for example 2D atrial
 * models.
 *
 */
#include "crn_con.h"
// #include "lookup_table.c"

#define CRN_CON_STATE_LENGTH (39)
#define INaBlock 1.0
#define IfBlock 1.0

enum crn_con_v_lookup {
    GKUR,
    IKR_FAC,
    IK1_FAC,
    IK1_FAC_AS,
    IK1_FAC_PV,
    FNAK,
    INACA_EXP_GAMMA,
    INACA_EXP_GAMMA_MINUS,
    INACA_DENOM,
    INA_M_INF,
    INA_M_TAU,
    INA_H_INF,
    INA_H_TAU,
    INA_J_INF,
    INA_J_TAU,
    ITO_OA_INF,
    ITO_OA_TAU,
    ITO_OI_INF,
    ITO_OI_TAU,
    IKUR_UA_INF,
    IKUR_UA_INF_APG,
    IKUR_UA_TAU,
    IKUR_UI_INF,
    IKUR_UI_INF_APG,
    IKUR_UI_TAU,
    IKR_XR_INF,
    IKR_XR_INF_PV,
    IKR_XR_TAU,
    IKS_XS_INF,
    IKS_XS_INF_LA,
    IKS_XS_INF_PV,
    IKS_XS_TAU,
    ICAL_D_INF,
    ICAL_D_TAU,
    ICAL_F_INF,
    ICAL_F_TAU,
    SR_W_INF,
    SR_W_TAU,
    ITO_ITR_INF,
    ITO_ITR_TAU,
    ITO_ITS_INF,
    ITO_ITS_TAU,
    IKS_TAU,
    IKS_INF
};
inline double Euler_inf(double dt, double gate, double inf, double tau) {

    gate = inf + (gate - inf) * exp(-(dt) / tau);
    return gate;
}

inline double Foward_Euler(double dt, double dy, double y) {

    double Y;
    Y = y + (dt) * dy;
    return Y;
}

// void crn_con_initial_conditions(double *state)
//
// Fills the given state with CRN initial conditions
void MIKE_initial_conditions(double state[], int celltype) {

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
} // end inital conds function


// void crn_con_initial_conditions(double *state)
//
// Fills the given state with CRN initial conditions
void crn_con_initial_conditions_SAN(double state[]) {

    /* steady-state initial conditions as used in the manuscript */
    state[0] = -8.118e+01; // u
    state[1] = 2.908e-03; //m
    state[2] = 9.649e-01;  //hh
    state[3] = 9.775e-01;  //jj
    state[4] = 1.367e-04;  //d
    state[5] = 9.996e-01;  //f
    state[6] = 3.296e-05;  //xr
    state[7] = 1.869e-02;  //xs
    state[8] = 1.117e+01;  //nai
    state[9] = 1.013e-04;  //cai
    state[10] = 1.390e+02;  //ki
    state[11] = 1.488e+00;  //caup
    state[12] = 1.488e+00;  //carel
    state[13] = 3.043e-02;  //oa
    state[14] = 9.992e-01;  //oi
    state[15] = 4.966e-03;   //ua
    state[16] = 9.986e-01;  //ui
    state[17] = 7.755e-01;  //fca
    state[18] = 2.042e-03;  //cmdn
    state[19] = 1.180e-02;  //trpn
    state[20] = 6.504e+00;  //csqn
    state[21] = 2.350e-11;   // w
    state[22] = 1.000e+00;  //v
    state[23] = 9.992e-01;  //uu
    state[24] = 0.42074;    //dd
    state[25] = 0.03897;    //ff
    state[26] = 0.03889;  //aa

    return;
}

void crn_con_initial_conditions_Atrial(double state[]) {

    /* steady-state initial conditions as used in the manuscript */
    state[0] = -8.118e+01; // u^M
    state[1] = 2.908e-03; //m ^M
    state[2] = 9.649e-01;  //hh^M
    state[3] = 9.775e-01;  //jj^M
    state[4] = 1.367e-04;  //d^M
    state[5] = 9.996e-01;  //f^M
    state[6] = 3.296e-05;  //xr^M
    state[7] = 1.869e-02;  //xs^M
    state[8] = 1.117e+01;  //nai^M
    state[9] = 1.013e-04;  //cai^M
    state[10] = 1.390e+02;  //ki^M
    state[11] = 1.488e+00;  //caup^M
    state[12] = 1.488e+00;  //carel^M
    state[13] = 3.043e-02;  //oa^M
    state[14] = 9.992e-01;  //oi^M
    state[15] = 4.966e-03;   //ua^M
    state[16] = 9.986e-01;  //ui^M
    state[17] = 7.755e-01;  //fca^M
    state[18] = 2.042e-03;  //cmdn^M
    state[19] = 1.180e-02;  //trpn^M
    state[20] = 6.504e+00;  //csqn^M
    state[21] = 9.99e-1;   // w  ^M
    state[22] = 1.000e+00;  //v^M
    state[23] = 0e-00;  //uu^M
    state[24] = 0.42074;    //dd^M
    state[25] = 0.03897;        //ff^M
    state[26] = 0.03889;  //aa

    state[24] = 0.42074;    //dd^M
    state[25] = 0.03897;        //ff^M
    state[26] = 0.03889;  //aa
    /*
            state[0] = -74.524110;
    state[1] = 0.008570;
    state[2] = 0.778693;
    state[3] = 0.499440;
    state[4] = 0.000315;
    state[5] = 0.815081;
    state[6] = 0.038926;
    state[7] = 0.056966;
    state[8] = 11.197338;
    state[9] = 0.000265;
    state[10] = 138.973352;
    state[11] = 1.712708;
    state[12] = 0.240112;
    state[13] = 0.044266;
    state[14] = 0.974915;
    state[15] = 0.010058;
    state[16] = 0.993282;
    state[17] = 0.567579;
    state[18] = 0.005009;
    state[19] = 0.024248;
    state[20] = 2.308483;
    state[21] = 0.000000;
    state[22] = 1.000000;
    state[23] = 0.998814;
    */
    return;
}


void crn_con_initial_conditions_CT(double state[]) {

    state[24] = 0.42074;    //dd^M
    state[25] = 0.03897;        //ff^M
    state[26] = 0.03889;  //aa

    state[0] = -54.186690;
    state[1] = 0.166531;
    state[2] = 0.024362;
    state[3] = 0.016116;
    state[4] = 0.004096;
    state[5] = 0.572809;
    state[6] = 0.145276;
    state[7] = 0.106027;
    state[8] = 11.183869;
    state[9] = 0.000348;
    state[10] = 138.950939;
    state[11] = 1.878342;
    state[12] = 0.253680;
    state[13] = 0.137352;
    state[14] = 0.342912;
    state[15] = 0.088897;
    state[16] = 0.986840;
    state[17] = 0.499522;
    state[18] = 0.006384;
    state[19] = 0.028744;
    state[20] = 2.407523;
    state[21] = 0.000000;
    state[22] = 1.000000;
    state[23] = 0.996063;
}

void crn_con_initial_conditions_AVN(double state[]) {

    state[0] = -78.932961;
    state[1] = 0.004203;
    state[2] = 0.943029;
    state[3] = 0.960723;
    state[4] = 0.000181;
    state[5] = 0.909458;
    state[6] = 0.004605;
    state[7] = 0.022563;
    state[8] = 11.170000;
    state[9] = 134.863836;
    state[10] = 0.000127;
    state[11] = 0.000147;
    state[12] = 0.918477;
    state[13] = 0.917612;
    state[14] = 0.008564;
    state[15] = 0.008437;
    state[16] = 0.000033;
    state[17] = 0.999984;
    state[18] = 0.216007;
    state[19] = 0.000091;
    state[20] = 0.995827;
    state[21] = 0.205009;
    state[22] = 0.000698;
    state[23] = 0.965843;
    state[24] = 0.000207;
    state[25] = 0.952503;
    state[26] = 0.734209;
    state[27] = 0.380302;
    state[28] = 0.480759;
    state[29] = 0.233294;
    state[30] = 0.002094;
    state[31] = 0.707121;

}

void crn_con_initial_conditions_Vent(double state[], int cellTissue) {
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
    //  }
}


// int crn_con_length()
//
// Returns the length of the CRN state variables array, used in various places
int crn_con_length() {
    return CRN_CON_STATE_LENGTH;
}

// double* crn_con_init()
//
// returns a double pointer, initialized with the CRN state

// double * crn_con_empty_state()
//
// returns an empty crn state.
double *crn_con_empty_state() {
    double *state;
    state = (double *) malloc(CRN_CON_STATE_LENGTH * sizeof(double));
    if (state == NULL) {
        perror("CRN98 model state array");
        return NULL;
    }
    return state;
}

// copies the state array from state1 to state2.
void copy_crn_con_state(double *state1, double *state2) {
    int i;
    for (i = CRN_CON_STATE_LENGTH; i--;)
        state2[i] = state1[i];
    return;
}

char *crn_con_type() {
    return "con";
}

char *crn_con_model() {
    return "CRN98";
}

// double crn_con(cell_params *params, double *state, double *results)
//
// integrates the CRN model through dt ms, applying a stimulus current of stim.
// The current state of the model is stored in state, and all but the membrane
// potential is updated during the timestep, using the euler method for
// concentrations and the rush-larsen method for the gating parameters.
double MIKE(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results, double ach_conc, int GKUR) {

    // constants
    double const    CRN_vcell = 20100.0; /* um3 */
    double const    CRN_vi = 13668;
    double const    CRN_vup = 1109.52/*0.0552*vcell*/;
    double const    CRN_vrel = 96.48/*0.0048*vcell*/;
    double const    T = 310; /* 37 Celcius */
    double const    CRN_Tfac = 3;
    double const    CRN_Csp = 1e+6; /* pF/cm2 */
    double const    F = 96.4867; /* coul/mmol */
    double const    R = 8.3143; /* J K-1 mol-1 */
    double const    CRN_kb = 5.4; /* mM */
    double const    CRN_nab = 140; /* mM */
    double const    CRN_cab = 1.8; /* mM */
    double const    CRN_nac = 140;
    double const    CRN_cac = 1.8;
    double const    CRN_kc = 5.4;
    double const    CRN_gna = 7.8; /* nS/pF */
    double const    CRN_gto = 0.1652; /* nS/pF */
    double const    CRN_gkr = 0.029411765; /* nS/pF */
    double const    CRN_gks = 0.12941176; /* nS/pF */
    double const    CRN_gcaL = 0.1294; /* nS/pF */
    double const    CRN_ErL = 65.0; /* mV */
    double const    CRN_gk1 = 0.09; /* nS/pF */
    double const    CRN_gbna = 0.0006744375; /* nS/pF */
    double const    CRN_gbk = 0.0;
    double const    CRN_gbca = 0.001131; /* nS/pF */
    double const    CRN_inakbar = 0.59933874; /* pA/pF */
    double const    CRN_kmnai = 10.0; /* mM */
    double const    CRN_kmko = 1.5; /* mM */
    double const    CRN_icapbar = 0.275; /* pA/pF */
    double const    CRN_kmcap = 0.0005; /* mM */
    double const    CRN_knacalr = 1600.0; /* pA/pF */
    double const    CRN_kmnalr = 87.5; /* mM */
    double const    CRN_kmcalr = 1.38; /* mM */
    double const    CRN_ksatlr = 0.1;
    double const    CRN_gammalr = 0.35;
    double const    CRN_trpnbar = 0.070; /* mM */
    double const    CRN_cmdnbar = 0.050; /* mM */
    double const    CRN_csqnbar = 10; /* mM */
    double const    CRN_kmcsqn = 0.8; /* mM */
    double const    CRN_kmcmdn = 0.00238; /* mM */
    double const    CRN_kmtrpn = 0.0005; /* mM */
    double const    CRN_grelbar = 30.0; /* ms-1 */
    double const    CRN_kmup = 0.00092; /* mM */
    double const    CRN_iupbar = 0.005; /* mM/ms */
    double const    CRN_caupmax = 15.0; /* mM */
    double const    CRN_kupleak = 0.00033333336/*iupbar/caupmax*/; /* ms-1 */
    double const    CRN_tautr = 180.0; /* ms */
    double const    CRN_gf_na = 0.0944;////0.10/* 0.09*/; /* nS/pF */
    double const    CRN_gf_k = /*0.0752*/ 0.0752;
    double const    CRN_gf = 0.025;//0.0752;
    double const    CRN_Ef = -22.0; /* mV */

    double const    gcaT = (0.15 * 0.22) / 17.62;
    double const    EcaT = 45.0;

    double const    MAL_gto = 0.75471 * 0.1962; //nS/pF **** in manuscript it is given in nS, so has been /100 here
    double const    MAL_gkur = 0.05874;
    double const    CNZ_gkur = 0.006398;

    double const    GONG_gto = 0.103;
    double const    gf = 0.0385;

    // KM model intracellular model parameters
    double const Vss = 2 * 4.99232e-5;
    double const rjunct = 6.5;
    double const lcell = 122.051;

    double const dx = 1.625;
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

    // Fibroblast stuff
    double const Cmf = 6.3; // pF
    double const vif = 0.00000137;//0.00000137;//0.00000000137; // um3  (from 0.00137 nL -> 0.00000137 nm3 -> 0.00000000137 um3
    double const naof = 130.0110; //mM
    double const kof = 5.3581; //mM


    double const Cm = 100.0;


    double GNa, Gto, GKur, GCaL, GKs, GKr, GK1, GNaCa, GCaT;
    double GNAB, GKB;
    double BULK_CONST;
    double CaL_inac_shift;
    double CaL_ac_shift;
    double IKr_ac_grad;
    double IKs_ac_grad;
    double IK1_v_shift;
    double Gf;
    double If_vshift;
    double IKur_ac_shift, IKur_inac_shift, IKur_ac_grad, IKur_inac_grad;
    double IKr_ac_shift, IKr_grad, IKs_shift, IKs_grad;
    double tau_INa_act, tau_INa_inact;
    double Ito_vshift,  ICaL_tau_rate, GSR_leak;
    double If_grad;
    double IREL, RYR;
    double fRyR;
    double dt = params->dt;

    double IKur_ac1_mult, IKur_ac1_shift, IKur_ac1_grad, IKur_ac2_mult, IKur_ac2_shift, IKur_ac2_grad;
    double IKur_ac_add, IKur_inac_mult, IKur_inac_shift2, IKur_inac_grad2, IKur_inac_add, IKur_cnd_add;
    double  IKur_cnd_mult, IKur_cnd_shift, IKur_cnd_grad, IKur_type_CNZ;
    //int tau_type;
    //int tau_average;


    //assign all variables which depend on cell type or iso/ach/AF from het struct

    GNa = het->GNa;
    Gto = het->Gto;
    GKur = het->GKur;
    GCaL = het->GCaL;
    GKs = het->GKs;
    GKr = het->GKr;
    GK1 = het->GK1;
    Gf = het->Gf;
    GNaCa = het->GNaCa;
    GCaT = het->GCaT;
    BULK_CONST = het->Bulk_const;
    CaL_inac_shift = het->ICaL_inac_shift;
    CaL_ac_shift = het->ICaL_ac_shift;
    IKr_ac_grad = het->IKr_ac_grad;
    IKs_ac_grad = het->IKs_ac_grad;
    If_vshift = het->If_vshift;
    IKur_ac_shift = het->IKur_ac_shift;
    IKur_inac_shift = het->IKur_inac_shift;
    IKur_ac_grad = het->IKur_ac_grad;
    IKur_inac_grad = het->IKur_inac_grad;
    IKr_ac_shift = het->IKr_ac_shift;
    IKr_grad = het->IKr_grad;
    IKs_shift = het->IKs_shift;
    IKs_grad = het->IKs_grad;
    tau_INa_act = het->tau_ina_act;
    tau_INa_inact = het->tau_ina_inact;
    Ito_vshift = het->ITo_vshift;
    ICaL_tau_rate = het->ICaL_tau_rate;
    GSR_leak = het->GSR_leak;
    If_grad = het->If_grad;
    IK1_v_shift = het->IK1_v_shift;
    RYR = het->RyR;
    IREL = het->fIRel;
    fRyR = het->fRyR;

    IKur_ac1_mult   = het->IKur_ac1_mult;
    IKur_ac1_shift  = het->IKur_ac1_shift;
    IKur_ac1_grad   = het->IKur_ac1_grad;
    IKur_ac2_mult   = het->IKur_ac2_mult;
    IKur_ac2_shift  = het->IKur_ac2_shift;
    IKur_ac2_grad   = het->IKur_ac2_grad;
    IKur_ac_add     = het->IKur_ac_add;
    IKur_inac_mult  = het->IKur_inac_mult;
    IKur_inac_shift2 = het->IKur_inac_shift;
    IKur_inac_grad2  = het->IKur_inac_grad;
    IKur_inac_add   = het->IKur_inac_add;
    IKur_cnd_add    = het->IKur_cnd_add;
    IKur_cnd_mult   = het->IKur_cnd_mult;
    IKur_cnd_shift  = het->IKur_cnd_shift;
    IKur_cnd_grad   = het->IKur_cnd_grad;

    IKur_type_CNZ = het->IKur_type_CNZ;
    //tau_type = het->IKur_tau_type;
    //tau_average = het->IKur_tau_average;

    double Ena, Ek, Eca, Ekf, Enaf;
    double alpha, beta, tau, inf, a, b;
    double INa, IKr, IKs, ICaL, IK1, Iab, IbK, IbCa;
    double IbNa, ICap, INaCa, INaK, Ito, IKur, If, ICaT;
    double fnak, sigma;
    double naidot, kidot, caidot;

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

    double *table_row = get_table_row(table, V);

    // Reversal Potentials
    Ena = 26.71 * log(CRN_nac / nai);
    Ek = 26.71 * log(CRN_kc / ki);
    Eca = 13.35 * log(CRN_cac / cai);

    //INa
    INa = GNa * Cm * CRN_gna * m * m * m * h * j * (V - Ena);

    // m gate
    alpha =  0.32 * (V + 47.13) / (1 - exp(-0.1 * (V + 47.13)));
    if (fabs(V + 47.13) < 1e-10) alpha = 3.2;
    beta = 0.08 * exp(-V / 11.0);

    tau = 1 / (alpha + beta);
    inf = alpha * tau;

    m = inf + (m - inf) * exp(-dt / tau); // steady state approx due to fast tau
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
    IKr = GKr * Cm * CRN_gkr * xr * (V - Ek) / (1 + exp((V + 15) / 22.4));

    // xr gate
    a = 0.0003 * (V + 14.1) / (1 - exp((V + 14.1) / -5));
    b = 0.000073898 * (V - 3.3328) / (exp((V - 3.3328) / 5.1237) - 1);
    if (fabs(V + 14.1) < 1e-10) a = 0.0015; /* denominator = 0 */
    if (fabs(V - 3.3328) < 1e-10) b = 3.7836118e-4; /* denominator = 0 */
    tau = 1 / (a + b);
    inf = 1 / (1 + exp((V + IKr_ac_shift + 14.1) / (-6.5 * IKr_grad)));
    xr = inf + (xr - inf) * exp(-dt / tau);

    // IKs
    IKs = GKs * Cm * CRN_gks * xs * xs * (V - Ek);

    // xs gate
    a = 0.00004 * (V - 19.9) / (1 - exp((V - 19.9) / -17));
    b = 0.000035 * (V - 19.9) / (exp((V - 19.9) / 9) - 1);
    if (fabs(V - 19.9) < 1e-10) // denominator = 0
    {
        a = 0.00068;
        b = 0.000315;
    }
    tau = 0.5 / (a + b); // note lagrer taus may be more accurate
    inf = sqrt(1 / (1 + exp((V - 19.9 - IKs_shift) / (-12.7 * IKs_grad))));
    xs = inf + (xs - inf) * exp(-dt / tau);
    //xs = table_row[IKS_INF] + (xs - table_row[IKS_INF])*table_row[IKS_TAU];
    //ICaL
    ICaL = 2.125 * GCaL * Cm * CRN_gcaL * d * f * fca * (V - CRN_ErL);

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
    Ito = Gto * Cm * MAL_gto * itr * its * (V - Ek);

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
    IKur = ((1 - IKur_type_CNZ) * ( Cm * MAL_gkur * isusr * isuss * (V - Ek))) +
           ((IKur_type_CNZ) * (Cm * CNZ_gkur * (4.5128 + 1.899769 / (1.0 + exp((V - 20.5232) / (-8.26597)))) * CNZ_a * CNZ_i * (V - Ek)));
    IKur = GKur * IKur;

    inf = 1 / (1 + exp(-(V + IKur_ac1_shift + 6) / (8.6 * IKur_ac1_grad)));
    tau = (0.009 / (1.0 + exp((V + 5) / 12)) + 0.0005);
    isusr = inf + (isusr - inf) * exp(-(dt / 1000) / tau);

    inf = 1 / (1 + exp((V + IKur_inac_shift + 7.5) / (10 * IKur_inac_grad)));
    tau = (0.59 / (1 + exp((V + 60.0) / 10)) + 3.05);
    isuss = inf + (isuss - inf) * exp(-(dt / 1000) / tau);

    double K_Q10 = 3.5308257834747638;
    //CNZ_a
    inf = ((IKur_ac1_mult * 1.0) / (1 + exp((V + 17.6684 + IKur_ac1_shift) / (-5.75418 * IKur_ac1_grad))) ) * ((IKur_ac2_mult * 1.0) / (1 + exp((V + 8.4153 + IKur_ac2_shift) / (-11.51037561 * IKur_ac2_grad)))) + IKur_ac_add;
    tau = (45.6666746826 / (1 + exp((V + 11.2306497073) / 11.5254705962)) + 4.26753514993) * (0.262186042981 / (1 + exp((V + 35.8658312707) / (-3.87510627762))) + 0.291755017928); //
    tau = tau / K_Q10;

    CNZ_a = inf + (CNZ_a - inf) * exp(-(dt) / tau);

    // CNZ_i
    inf = (IKur_inac_mult * 0.52424) / (1.0 + exp((V + 15.1142 + IKur_inac_shift) / (7.567021 * IKur_inac_grad))) + 0.4580778 + IKur_inac_add;
    tau = 2328 / (1 + exp(((V) - 9.435) / (3.5827))) + 1739.139;
    tau = tau / K_Q10;


    CNZ_i = inf + (CNZ_i - inf) * exp(-(dt) / tau);



    //If
    If = Gf * Cm * CRN_gf * If_y * (V - (-22));

    //If y gate
    inf = 1 / (1 + exp((V + 90.95 + If_vshift) / (10.1 * If_grad))   );
    tau = 1 / (1.2783E-04 * exp(-V / 9.2424) + 121.6092 * exp(V / 9.2424)   );

    If_y = inf + (If_y - inf) * exp(-dt / tau);

    //ICaT
    ICaT = GCaT * Cm * gcaT * ff * dd * (V - EcaT);

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
    IK1 = GK1 * Cm * CRN_gk1 * (V - Ek + IK1_v_shift) / (1 + exp(0.07 * (V + 80 + IK1_v_shift)));
    //IK1 = GK1 * Cm * CRN_gk1 * (V-Ek+IK1_v_shift) * (het->IK1_type_default * (table_row[IK1_FAC]) + het->IK1_type_AS *(table_row[IK1_FAC_AS])  );

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
    INaCa = GNaCa * Cm * CRN_knacalr / (pow(CRN_kmnalr, 3.0) + pow(CRN_nac, 3.0)) / (CRN_kmcalr + CRN_cac) /
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
    double RyRainfss = 0.505 - 0.427 / (1 + exp((( Cass + (fRyR * Cass) ) * 1000 - 0.29) / 0.082));
    double RyRoinfss = (1 - 1 / (1 +  exp(((Cass + (fRyR * Cass)   ) * 1000 - ((RyRass) + 0.22)) / 0.03)));
    double RyRcinfss = (1 / (1 + exp(((Cass + (fRyR * Cass )) * 1000 - ((RyRass) + 0.02)) / 0.01)));
    double Jrelss = nuss * ( (RyRoss) ) * (RyRcss) * RyRSRCass * ( CaSR2 -  (Cass) );

    double nu3 = 1 * Vnonjunct3;
    double RyRSRCa3 = (1 - 1 / (1 +  exp((CaSR1 - 0.3) / 0.1)));
    double RyRainf3 =  0.505 - 0.427 / (1 + exp(( (cai + ( fRyR * cai)  ) * 1000 - 0.29) / 0.082));
    double RyRoinf3 = (1 - 1 / (1 +  exp(( (cai + ( fRyR * cai) ) * 1000 - ((RyRa3) + 0.22)) / 0.03)));
    double RyRcinf3 = (1 / (1 +  exp(( (cai + (fRyR * cai ) ) * 1000 - ((RyRa3) + 0.02)) / 0.01)));
    double Jrel3 = nu3 * ( (RyRo3) ) * (RyRc3) * RyRSRCa3 * ( CaSR1 -  cai );

    Jrelss = IREL * Jrelss;
    Jrel3 = IREL * Jrel3;

    double JSRCaleak3 = GSR_leak * kSRleak * ( CaSR1 - cai ) * Vnonjunct3;
    double JSRCaleakss = GSR_leak * kSRleak * ( CaSR2 - (Cass) ) * Vss;

    double JCa, JCass;
    JCa = -BULK_CONST * J_bulkSERCA + JSRCaleak3 + Jrel3 + Jj_nj;
    JCass = -Jj_nj + JSRCaleakss - BULK_CONST * J_bulkSERCAss + Jrelss;

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

    dy =  betass * ( JCass / Vss + ((-( RYR * ICaL) - IbCa - ICap - ICaT + 2 * INaCa)) / (2 * Vss * 1000 * F) );
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

    double Iion_tot = (INa + Ito + IKur + IKr + IKs + ICaL + IK1 + IbK + IbNa + IbCa + Iab + INaCa + INaK + ICap + If + ICaT ) / Cm;

    return Iion_tot;
} // end MIKE

double crn_con_Vent_with_drug(double dt, double *state, int ZIndex, int cellTissue, double INa_Drug, double If_Drug, double IKr_Drug, double IKs_Drug, double ICaL_Drug, double INa_V50A, double If_V50A, double IKr_V50A, double IKs_V50A, double ICaL_V50A, double INa_V50I, double If_V50I, double IKr_V50I, double IKs_V50I, double ICaL_V50I, double INa_TauA, double If_TauA, double IKr_TauA, double IKs_TauA, double ICaL_TauA, double INa_TauI, double If_TauI, double IKr_TauI, double IKs_TauI, double ICaL_TauI) {

    double R = 8314.472;
    double F = 96485.3415;
    double T = 310.0;

    double Ko = 5.4;
    double Cao = 2.0;
    double Nao = 140.0;

    double Vc = 0.016404;
    double Vsr = 0.001094;
    double Vss = 0.00005468;

    double Bufc = 0.2;
    double Kbufc = 0.001;
    double Bufsr = 10.;
    double Kbufsr = 0.3;
    double Bufss = 0.4;
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

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GNa = 14.838;
    else
        GNa = 130.5744;
    AM = 1. / (1. + exp((-60. - state[0]) / 5.));
    BM = 0.1 / (1. + exp((state[0] + 35.) / 5.)) + 0.10 / (1. + exp((state[0] - 50.) / 200.));
    TAU_M = AM * BM * INa_TauA;
    M_INF = 1. / ((1. + exp((-56.86 - (state[0] + INa_V50A)) / 9.03)) * (1. + exp((-56.86 - state[0]) / 9.03)));
    if (state[0] >= -40.)
    {
        AH_1 = 0.;
        BH_1 = (0.77 / (0.13 * (1. + exp(-((state[0] + INa_V50I) + 10.66) / 11.1))));
        TAU_H = INa_TauI * 1.0 / (AH_1 + BH_1);
        AJ_1 = 0.;
        BJ_1 = (0.6 * exp((0.057) * (state[0] + INa_V50I)) / (1. + exp(-0.1 * (state[0] + 32.))));
        TAU_J = 1.0 / (AJ_1 + BJ_1);
    }
    else
    {
        AH_2 = (0.057 * exp(-((state[0] + INa_V50I) + 80.) / 6.8));
        BH_2 = (2.7 * exp(0.079 * (state[0] + INa_V50I)) + (3.1e5) * exp(0.3485 * state[0]));
        AJ_2 = (((-2.5428e4) * exp(0.2444 * (state[0] + INa_V50I)) - (6.948e-6) * exp(-0.04391 * (state[0] + INa_V50I))) * (state[0] + 37.78) / (1. + exp(0.311 * ((state[0] + INa_V50I) + 79.23))));
        BJ_2 = (0.02424 * exp(-0.01052 * (state[0] + INa_V50I)) / (1. + exp(-0.1378 * ((state[0] + INa_V50I) + 40.14))));
        TAU_J = 1.0 / (AJ_2 + BJ_2);
        TAU_H = INa_TauI * 1.0 / (AH_2 + BH_2);
    }
    H_INF = 1. / ((1. + exp(((state[0] + INa_V50I) + 71.55) / 7.43)) * (1. + exp((state[0] + 71.55) / 7.43)));
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
        Ito = Ito * ((-1.0 * (ZIndex - 10) / 318) + 2.0);
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
        IKs = IKs * ((-1.0 * (ZIndex - 10) / 318) + 2.0);
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

void crn_con_compute_table_row_v(double V,  void *p, double *row, heterogeneous_params_t *het) {
    cell_params *params = (cell_params *) p;


    double const    CRN_vcell = 20100.0; /* um3 */
    double const    CRN_vi = 13668;
    double const    CRN_vup = 1109.52/*0.0552*vcell*/;
    double const    CRN_vrel = 96.48/*0.0048*vcell*/;
    double const    T = 310; /* 37 Celcius */
    double const    CRN_Tfac = 3;
    double const    CRN_Csp = 1e+6; /* pF/cm2 */
    double const    F = 96.4867; /* coul/mmol */
    double const    R = 8.3143; /* J K-1 mol-1 */
    double const    CRN_kb = 5.4; /* mM */
    double const    CRN_nab = 140; /* mM */
    double const    CRN_cab = 1.8; /* mM */
    double const    CRN_nac = 140;
    double const    CRN_cac = 1.8;
    double const    CRN_kc = 5.4;
    double const    CRN_gna = 7.8; /* nS/pF */
    double const    CRN_gto = 0.1652; /* nS/pF */
    double const    CRN_gkr = 0.029411765; /* nS/pF */
    double const    CRN_gks = 0.12941176; /* nS/pF */
    double const    CRN_gcaL = 0.1294; /* nS/pF */
    double const    CRN_ErL = 65.0; /* mV */
    double const    CRN_gk1 = 0.09; /* nS/pF */
    double const    CRN_gbna = 0.0006744375; /* nS/pF */
    double const    CRN_gbk = 0.0;
    double const    CRN_gbca = 0.001131; /* nS/pF */
    double const    CRN_inakbar = 0.59933874; /* pA/pF */
    double const    CRN_kmnai = 10.0; /* mM */
    double const    CRN_kmko = 1.5; /* mM */
    double const    CRN_icapbar = 0.275; /* pA/pF */
    double const    CRN_kmcap = 0.0005; /* mM */
    double const    CRN_knacalr = 1600.0; /* pA/pF */
    double const    CRN_kmnalr = 87.5; /* mM */
    double const    CRN_kmcalr = 1.38; /* mM */
    double const    CRN_ksatlr = 0.1;
    double const    CRN_gammalr = 0.35;
    double const    CRN_trpnbar = 0.070; /* mM */
    double const    CRN_cmdnbar = 0.050; /* mM */
    double const    CRN_csqnbar = 10; /* mM */
    double const    CRN_kmcsqn = 0.8; /* mM */
    double const    CRN_kmcmdn = 0.00238; /* mM */
    double const    CRN_kmtrpn = 0.0005; /* mM */
    double const    CRN_grelbar = 30.0; /* ms-1 */
    double const    CRN_kmup = 0.00092; /* mM */
    double const    CRN_iupbar = 0.005; /* mM/ms */
    double const    CRN_caupmax = 15.0; /* mM */
    double const    CRN_kupleak = 0.00033333336/*iupbar/caupmax*/; /* ms-1 */
    double const    CRN_tautr = 180.0; /* ms */
    double const    CRN_gf_na = 0.0944;////0.10/* 0.09*/; /* nS/pF */
    double const    CRN_gf_k = /*0.0752*/ 0.0752;
    double const    CRN_gf = 0.025;//0.0752;
    double const    CRN_Ef = -22.0; /* mV */

    double const    gcaT = (0.15 * 0.22) / 17.62;
    double const    EcaT = 45.0;

    double const    MAL_gto = 0.75471 * 0.1962; //nS/pF **** in manuscript it is given in nS, so has been /100 here
    double const    MAL_gkur = 0.05874;
    double const    CNZ_gkur = 0.006398;

    double const    GONG_gto = 0.103;
    double const    gf = 0.0385;

    // KM model intracellular model parameters
    double const Vss = 2 * 4.99232e-5;
    double const rjunct = 6.5;
    double const lcell = 122.051;

    double const dx = 1.625;
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

    // Fibroblast stuff
    double const Cmf = 6.3; // pF
    double const vif = 0.00000137;//0.00000137;//0.00000000137; // um3  (from 0.00137 nL -> 0.00000137 nm3 -> 0.00000000137 um3
    double const naof = 130.0110; //mM
    double const kof = 5.3581; //mM


    double const Cm = 100.0;


    double GNa, Gto, GKur, GCaL, GKs, GKr, GK1, GNaCa, GCaT;
    double Gbca, GNAB, GKB, GCap;
    double BULK_CONST;
    double CaL_inac_shift;
    double CaL_ac_shift;
    double IKr_ac_grad;
    double IKs_ac_grad;
    double IK1_v_shift;
    double Gf;
    double If_vshift;
    double IKur_ac_shift, IKur_inac_shift, IKur_ac_grad, IKur_inac_grad;
    double IKr_ac_shift, IKr_grad, IKs_shift, IKs_grad;
    double tau_INa_act, tau_INa_inact;
    double Ito_vshift,  ICaL_tau_rate, GSR_leak;
    double If_grad;
    double IREL, RYR;
    double fRyR;
    double dt = params->dt;

    double IKur_ac1_mult, IKur_ac1_shift, IKur_ac1_grad, IKur_ac2_mult, IKur_ac2_shift, IKur_ac2_grad;
    double IKur_ac_add, IKur_inac_mult, IKur_inac_shift2, IKur_inac_grad2, IKur_inac_add, IKur_cnd_add;
    double  IKur_cnd_mult, IKur_cnd_shift, IKur_cnd_grad, IKur_type_CNZ;
    int tau_type;


    //assign all variables which depend on cell type or iso/ach/AF from het struct

    GNa = het->GNa;
    Gto = het->Gto;
    GKur = het->GKur;
    GCaL = het->GCaL;
    GKs = het->GKs;
    GKr = het->GKr;
    GK1 = het->GK1;
    Gf = het->Gf;
    GNaCa = het->GNaCa;
    GCaT = het->GCaT;
    //Gbca = het->Gbca;
    //GCap = het->Gcap;
    BULK_CONST = het->Bulk_const;
    CaL_inac_shift = het->ICaL_inac_shift;
    CaL_ac_shift = het->ICaL_ac_shift;
    IKr_ac_grad = het->IKr_ac_grad;
    IKs_ac_grad = het->IKs_ac_grad;
    If_vshift = het->If_vshift;
    IKur_ac_shift = het->IKur_ac_shift;
    IKur_inac_shift = het->IKur_inac_shift;
    IKur_ac_grad = het->IKur_ac_grad;
    IKur_inac_grad = het->IKur_inac_grad;
    IKr_ac_shift = het->IKr_ac_shift;
    IKr_grad = het->IKr_grad;
    IKs_shift = het->IKs_shift;
    IKs_grad = het->IKs_grad;
    tau_INa_act = het->tau_ina_act;
    tau_INa_inact = het->tau_ina_inact;
    Ito_vshift = het->ITo_vshift;
    ICaL_tau_rate = het->ICaL_tau_rate;
    GSR_leak = het->GSR_leak;
    If_grad = het->If_grad;
    IK1_v_shift = het->IK1_v_shift;
    RYR = het->RyR;
    IREL = het->fIRel;
    fRyR = het->fRyR;

    IKur_ac1_mult   = het->IKur_ac1_mult;
    IKur_ac1_shift  = het->IKur_ac1_shift;
    IKur_ac1_grad   = het->IKur_ac1_grad;
    IKur_ac2_mult   = het->IKur_ac2_mult;
    IKur_ac2_shift  = het->IKur_ac2_shift;
    IKur_ac2_grad   = het->IKur_ac2_grad;
    IKur_ac_add     = het->IKur_ac_add;
    IKur_inac_mult  = het->IKur_inac_mult;
    IKur_inac_shift2 = het->IKur_inac_shift;
    IKur_inac_grad2  = het->IKur_inac_grad;
    IKur_inac_add   = het->IKur_inac_add;
    IKur_cnd_add    = het->IKur_cnd_add;
    IKur_cnd_mult   = het->IKur_cnd_mult;
    IKur_cnd_shift  = het->IKur_cnd_shift;
    IKur_cnd_grad   = het->IKur_cnd_grad;

    IKur_type_CNZ = het->IKur_type_CNZ;
    //tau_type = het->IKur_tau_type;

    double Ena, Ek, Eca, Ekf, Enaf;
    double alpha, beta, tau, inf, a, b;
    double INa, IKr, IKs, ICaL, IK1, Iab, IbK, IbCa;
    double IbNa, ICap, INaCa, INaK, Ito, IKur, If, ICaT;
    double fnak, sigma;
    double naidot, kidot, caidot;
    //double const    vcell = 20100.0; /* um3 */
    //
    // m gate
    alpha =  0.32 * (V + 47.13) / (1 - exp(-0.1 * (V + 47.13)));
    if (fabs(V + 47.13) < 1e-10) alpha = 3.2;
    beta = 0.08 * exp(-V / 11.0);

    tau = 1 / (alpha + beta);
    inf = alpha * tau;

    row[INA_M_INF] = inf;
    row[INA_M_TAU] = exp(-params->dt / tau);

    //j gate
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

    row[INA_H_INF] = inf;
    row[INA_H_TAU] = exp(-params->dt / tau);

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

    row[INA_J_INF] = inf;
    row[INA_J_TAU] = exp(-params->dt / tau);

    //IK1 factors
    row[IK1_FAC] =  1 / (1 + exp(0.07 * (V + 80)));
    row[IK1_FAC_AS] = 1 / (1 + exp(0.07 * (V + 80 - 6)));

    //Ito
    inf = 1.0 / (1.0 + exp((V - 1.0) / -11.0));
    tau = (0.0035 * exp(-(V / 30.0) * 2) + 0.0015);
    row[ITO_ITR_TAU] = exp(-(params->dt / 1000) / tau);
    row[ITO_ITR_INF] = inf;

    // s gate
    inf = 1.0 / (1.0 + exp((V + 40.5) / 11.5));
    tau = (0.025635 * exp (-((V + 52.45) / 15.8827) * 2) + 0.01414);
    row[ITO_ITS_TAU] = exp(-(params->dt / 1000) / tau);
    row[ITO_ITS_INF] = inf;

    //IKs
    a = 0.00004 * (V - 19.9) / (1 - exp((V - 19.9) / -17));
    b = 0.000035 * (V - 19.9) / (exp((V - 19.9) / 9) - 1);
    if (fabs(V - 19.9) < 1e-10) /* denominator = 0 */
    {
        a = 0.00068;
        b = 0.000315;
    }
    tau = 0.5 / (a + b); // note lagrer taus may be more accurate
    inf = sqrt(1 / (1 + exp((V - 19.9) / (-12.7))));
    row[IKS_INF] = inf;
    row[IKS_TAU] = exp(-params->dt / tau);

}


double crn_con_Vent(double dt, double *state, float ZIndex, unsigned char cellTissue) {

    const double Tent_RTONF = (Tent_R * Tent_T / Tent_F);
    const double Tent_inverseVcF2  =  (1. / (2 * Tent_Vc * Tent_F));
    const double Tent_inverseVcF   =  (1. / (Tent_Vc * Tent_F));
    const double Tent_inversevssF2 = (1. / (2 * Tent_Vss * Tent_F));

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

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
        GNa = 14.838;
    else
        GNa = 130.5744;
    AM = 1. / (1. + exp((-60. - state[0]) / 5.));
    BM = 0.1 / (1. + exp((state[0] + 35.) / 5.)) + 0.10 / (1. + exp((state[0] - 50.) / 200.));
    TAU_M = AM * BM;
    M_INF = 1. / ((1. + exp((-56.86 - state[0]) / 9.03)) * (1. + exp((-56.86 - state[0]) / 9.03)));
    if (state[0] >= -40.)
    {
        AH_1 = 0.;
        BH_1 = (0.77 / (0.13 * (1. + exp(-(state[0] + 10.66) / 11.1))));
        TAU_H = 1.0 / (AH_1 + BH_1);
    }
    else
    {
        AH_2 = (0.057 * exp(-(state[0] + 80.) / 6.8));
        BH_2 = (2.7 * exp(0.079 * state[0]) + (3.1e5) * exp(0.3485 * state[0]));
        TAU_H = 1.0 / (AH_2 + BH_2);
    }
    H_INF = 1. / ((1. + exp((state[0] + 71.55) / 7.43)) * (1. + exp((state[0] + 71.55) / 7.43)));
    if (state[0] >= -40.)
    {
        AJ_1 = 0.;
        BJ_1 = (0.6 * exp((0.057) * state[0]) / (1. + exp(-0.1 * (state[0] + 32.))));
        TAU_J = 1.0 / (AJ_1 + BJ_1);
    }
    else
    {
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
    if (cellTissue == 20 || cellTissue == 21 || cellTissue == 22) {
        Ito = Ito * ((-1.0 * (ZIndex - 10) / 318) + 2.0);
    }

    if (cellTissue == 13 || cellTissue == 14 || cellTissue == 15)
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
    Axs = (1400. / (sqrt(1. + exp((5. - state[0]) / 6))));
    Bxs = (1. / (1. + exp((state[0] - 35.) / 15.)));
    TAU_Xs = Axs * Bxs + 80;
    state[17] = Xs_INF - (Xs_INF - state[17]) * exp(-dt / TAU_Xs);

    IKs = GKs * state[17] * state[17] * (state[0] - Eks);

    //APEX BASE HETERO
    if (cellTissue == 20 || cellTissue == 21 || cellTissue == 22) {
        IKs = IKs * ((-1.0 * (ZIndex - 10) / 318) + 2.0);
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
        Ay = exp(-2.9 - (0.04 * state[0]));
        By = exp(3.6 + (0.11 * state[0]));
        tau_y = 4000. / (Ay + By);
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

    return (IKr + IKs + IK1 + Ito + Isus + (INaBlock * INa) + IbNa + ICaL + IbCa + INaK + INaCa + IpCa + IpK + (IfBlock * If));
}


double crn_con_AVN(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results, double ach_conc) {

    double const    vcell = 20100.0; /* um3 */
    double const    vi = 13668;
    double const    vup = 1109.52/*0.0552*vcell*/;
    double const    vrel = 96.48/*0.0048*vcell*/;
    double const    T = 310; /* 37 Celcius */
    double const    Tfac = 3;
    double const    Csp = 1e+6; /* pF/cm2 */
    double const    Cm = 100.0; /* pF */
    double const    F = 96.4867; /* coul/mmol */
    double const    R = 8.3143; /* J K-1 mol-1 */
    double const    kb = 5.4; /* mM */
    double const    nab = 140; /* mM */
    double const    cab = 1.8; /* mM */
    double const    nac = 140;
    double const    cac = 1.8;
    double const    kc = 5.4;
    double const    gna = 7.8; /* nS/pF */
    double const    gto = 0.1962; /* nS/pF */
    double const    gkur = 0.05874;
    double const    gkr = 0.029411765; /* nS/pF */
    double const    gks = 0.12941176; /* nS/pF */
    double const    gcaL = 0.1375; /* nS/pF */
    double const    ErL = 65.0; /* mV */
    double const    gk1 = 0.09; /* nS/pF */
    double const    gbna = 0.0006744375; /* nS/pF */
    double const    gbk = 0.0;
    double const    gbca = 0.001131; /* nS/pF */
    double const    inakbar = 0.59933874; /* pA/pF */
    double const    kmnai = 10.0; /* mM */
    double const    kmko = 1.5; /* mM */
    double const    icapbar = 0.275; /* pA/pF */
    double const    kmcap = 0.0005; /* mM */
    double const    knacalr = 1600.0; /* pA/pF */
    double const    kmnalr = 87.5; /* mM */
    double const    kmcalr = 1.38; /* mM */
    double const    ksatlr = 0.1;
    double const    gammalr = 0.35;
    double const    trpnbar = 0.070; /* mM */
    double const    cmdnbar = 0.050; /* mM */
    double const    csqnbar = 10; /* mM */
    double const    kmcsqn = 0.8; /* mM */
    double const    kmcmdn = 0.00238; /* mM */
    double const    kmtrpn = 0.0005; /* mM */
    double const    grelbar = 30.0; /* ms-1 */
    double const    kmup = 0.00092; /* mM */
    double const    iupbar = 0.005; /* mM/ms */
    double const    caupmax = 15.0; /* mM */
    double const    kupleak = 0.00033333336/*iupbar/caupmax*/; /* ms-1 */
    double const    tautr = 180.0; /* ms */
    double const    gf = 0.025; //ns/pf
    double const    gcaT = (0.15 * 0.22) / 17.62;; //(0.45*0.22)/17.62; /* nS/pF */
    float const    EcaT = 45.0; /* mV */
    double const gKAcH_max = 13 * 2.3362448698; //13*2.3362448698; // nS/pF
    double const Vss = 2 * 4.99232e-5;
    double const rjunct = 6.5;
    double const lcell = 122.051;
    //Ca diffusion
    double const dx = 1.625;
    //double r start, rend, j, j'  -> figure out
    // add in after electrophysiology is done
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

    double GNa, Gto, GKur, GCaL, GKs, GKr, GK1, GNACA, GCAT;
    double GCAB, GNAB, GKB;
    double BULK_CONST;
    double CaL_inac_shift;
    double CaL_ac_shift;
    double IKr_ac_grad;
    double IKs_ac_grad;
    double IK1_V_shift;
    double Gf;
    double If_vshift;
    double IKur_ac_shift, IKur_inac_shift, IKur_ac_grad, IKur_inac_grad;
    double IKr_ac_shift, IKr_grad, IKs_shift, IKs_grad;
    double tau_INa_act, tau_INa_inact;
    double Ito_vshift,  ICaL_tau_rate, GSR_leak;
    double If_grad;
    double IREL, RYR;
    double fRyR;
    double dt = params->dt;

    //assign all variables which depend on cell type or iso/ach/AF from het struct

    GNa = het->GNa;
    Gto = het->Gto;
    GKur = het->GKur;
    GCaL = het->GCaL;
    GKs = het->GKs;
    GKr = het->GKr;
    GK1 = het->GK1;
    Gf = het->Gf;
    GNACA = het->GNaCa;
    GCAT = het->GCaT;
    BULK_CONST = het->Bulk_const;
    CaL_inac_shift = het->ICaL_inac_shift;
    CaL_ac_shift = het->ICaL_ac_shift;
    IKr_ac_grad = het->IKr_ac_grad;
    IKs_ac_grad = het->IKs_ac_grad;
    If_vshift = het->If_vshift;
    IKur_ac_shift = het->IKur_ac_shift;
    IKur_inac_shift = het->IKur_inac_shift;
    IKur_ac_grad = het->IKur_ac_grad;
    IKur_inac_grad = het->IKur_inac_grad;
    IKr_ac_shift = het->IKr_ac_shift;
    IKr_grad = het->IKr_grad;
    IKs_shift = het->IKs_shift;
    IKs_grad = het->IKs_grad;
    tau_INa_act = het->tau_ina_act;
    tau_INa_inact = het->tau_ina_inact;
    Ito_vshift = het->ITo_vshift;
    ICaL_tau_rate = het->ICaL_tau_rate;
    GSR_leak = het->GSR_leak;
    If_grad = het->If_grad;
    IK1_V_shift = het->IK1_v_shift;
    RYR = het->RyR;
    IREL = het->fIRel;
    fRyR = het->fRyR;

    //now assign all state variables and decalre computed quantities

    double     V = state[0];
    double     m = state[1];
    double     h = state[2];;
    double     j = state[3];
    double     d = state[4];
    double     f = state[5];
    double     xr = state[6];
    double     xs = state[7];
    double     nai = state[8];
    double     ki = state[9];
    double     Cass = state[10];
    double     Cai =  state[11];
    double     CaSR1 = state[12];
    double     CaSR2 = state[13];
    double      SERCACa = state[14];
    double      SERCACass = state[15];
    double    RyRoss = state[16];
    double    RyRcss = state[17];
    double        RyRass = state[18];
    double  RyRo3 = state[19];
    double RyRc3 = state[20];
    double RyRa3 = state[21];
    double  Itr = state[22];
    double  Its = state[23];
    double  Isusr = state[24];
    double  Isuss = state[25];
    double     fca = state[26];

    double AcHj = state[27];
    double AcHk = state[28];

    double if_y = state[29];

    double dd = state[30];
    double ff = state[31];

    double Ek, Ena, Eca, ina, ik, ibna, ibk, ibca, inak, ik1;
    double ito, ikur, ikr, iks;
    double iab, inaca, icaL;
    double naidot, kidot;
    double caidot, IRel;
    double itr, iup, iupleak;
    double fnak, caflux, icap, sigma;

    /* utility variables */
    double a, b, tau, inf, vshift;

    double ICaL, gCaL, ECa_app;
    double kCan, kCa;
    double fcainf;
    double icaT;

    double gKAcH, IKAcH, aj, bj, ak, bk, khalf_ach, nkach;

    /* compute Ek */
    Ek = 26.71 * log(kc / ki);
    /* compute Ena */
    Ena = 26.71 * log(nac / nai);
    /* compute Eca */
    Eca = 13.35 * log(cac / Cass);
    /* compute sodium current */
    ina = GNa * Cm * gna * m * m * m * h * j * (V - Ena);

    /* maleckar currents */
    // Ito
    //  double gt;
    //  gt =  (1.09*7.5)/*/50*/;

    // If
    double If, if_fna, if_fk;
    if_fna = 0.2677;
    if_fk = 1 - if_fna;

    //  If = Cm*gf*if_y*(if_fna*(V-Ena) + if_fk* (V-Ek) );
    If = Gf * Cm * gf * if_y * (V - (-22));

    inf = 1 / (1 + exp((V + 90.95 + If_vshift) / (10.1 * If_grad))   );
    tau = 1 / (1.2783E-04 * exp(-V / 9.2424) + 121.6092 * exp(V / 9.2424)   );

    if_y = inf + (if_y - inf) * exp(-dt / tau);


    // ICaT
    icaT = GCAT * Cm * gcaT * ff * dd * (V - EcaT);

    a = 1.0680 * exp((V + 26.3) / 30.0);
    b  = 1.0680 * exp(-(V + 26.3) / 30.0);
    tau = 1.0 / (a + b);
    inf = 1.0 / (1.0 + exp(-(V + 37.0) / 6.8));
    dd = inf + (dd - inf) * exp(-dt / tau);

    a = 0.0153 * exp(-(V + 71.0) / 83.3);
    b  = 0.0150 * exp((V + 71.0) / 15.38);
    tau = 1.0 / (a + b);
    inf = 1.0 / (1.0 + exp((V + 71.0) / 9.0));
    ff = inf + (ff - inf) * exp(-dt / tau);




    ito = ((Cm * Gto * gto * (Itr) * (Its) * ((V) - Ek)));

    // r gate
    inf = 1 / (1 + exp(((V) - 1 + Ito_vshift) / -11));
    tau = 0.0035 * exp( -pow((((V) + 0) / 30), 2) ) + 0.0015;
    //    Itr = Euler_inf(dt/1000, Itr, inf, tau);
    Itr = inf + (Itr - inf) * exp(-(dt / 1000) / tau); // dt/1000 to convert from s to ms

    // s gate
    inf = 1 / (1 + exp(((V) + 40.5) / 11.5));
    tau = 0.025635 * exp( -pow((((V) + 52.45) / 15.8827), 2) ) + 0.01414;
    // Its = Euler_inf(dt/1000, Its, inf, tau);
    Its = inf + (Its - inf) * exp(-(dt / 1000) / tau);

    // IKur
    //  double gsus;
    //  gsus = 0.89*2.75;

    ikur = Cm * GKur * gkur * (Isusr) * (Isuss) * ((V) - Ek);

    // r gate
    inf = 1 / (1 + exp(((V) + 6 + IKur_ac_shift) / (-8.6 * IKur_ac_grad)));
    //   inf = 1/(1+exp(((V)-8)/-11*0.6));

    tau = 0.009 / (1 + exp(((V) + 5) / 12)) + 0.0005;
    //  susr = Euler_inf(dt/1000, susr, inf, tau);
    Isusr = inf + (Isusr - inf) * exp(-(dt / 1000) / tau);

    // s gate
    inf = 1 / (1 + exp(((V) + 7.5 + IKur_inac_shift) / (10 * IKur_inac_grad)));
    // inf = 1/(1+exp(((V)+32.5)/11.5*0.65));
    tau = 0.59 / (1 + exp(((V) + 60) / 10)) + 3.05;
    //    suss = Euler_inf(dt/1000, suss, inf, tau);
    Isuss = inf + (Isuss - inf) * exp(-(dt / 1000) / tau);

    // IKACh
    khalf_ach = 2.8E-07;
    nkach = 1.5;

    gKAcH = gKAcH_max * AcHj * AcHk * ( pow(ach_conc, nkach) / ( pow(khalf_ach, nkach) + pow(ach_conc, nkach) ) );
    IKAcH = gKAcH * (kc / (10 + kc)) * ((V - Ek - 5) / (1 + exp( ( ( V - Ek - 145) * F) / (2.5 * R * T))));

    aj = 63.99740379;
    bj = 132.4254996 / (1 + exp (-(V + 36.58863658) / 8.18192955));

    tau = 1 / (aj + bj);
    inf = aj * tau;
    AcHj =  inf + (AcHj - inf) * exp(-dt / tau);

    ak = 3.00882853;
    bk = 7.272612229 / (1 + exp (-(V + 69.84216904 ) / (0.369147) ) );

    tau = 1 / (ak + bk);
    inf = ak * tau;
    AcHk =  inf + (AcHk - inf) * exp(-dt / tau);



    /* compute the rapid delayed outward rectifier K current */
    ikr = GKr * Cm * gkr * xr * (V - Ek) / (1 + exp((V + 15) / 22.4));

    /* compute the slow delayed outward rectifier K current */
    iks = GKs * Cm * gks * xs * xs * (V - Ek);

    ik = ikr + iks;

    /* compute calcium current */
    icaL =/* 2.37*/2 * GCaL * Cm * gcaL * d * f * fca * (V - ErL);

    /* update the fca gate immediately */
    inf = 1 / (1 + ((Cass) / 0.00035));
    tau = 2.0;
    fca = inf + (fca - inf) * exp(-dt / tau);

    /* compute time independent potassium current */
    ik1 = GK1 * Cm * gk1 * (V - Ek + IK1_V_shift) / (1 + exp(0.07 * (V + 80 + IK1_V_shift)));
    //iab - NO3- sensitive background current
    iab = 0;
    iab = Cm * 0.0003879 * (V + 69.6) / (1 - 0.8377 * exp((V + 49.06) / 1056));
    /* compute ibna background current */
    ibna = Cm * gbna * (V - Ena);

    /* compute potassium background current */
    ibk = Cm * gbk * (V - Ek);

    /* compute ibca background current */
    ibca = Cm * gbca * (V - Eca);

    /* compute inak sodium-potassium pump current, LR-style */
    sigma = (exp(nac / 67.3) - 1) / 7.0;
    fnak = 1 / (1 + 0.1245 * exp(-0.1 * V * F / (R * T)) + 0.0365 * sigma * exp(-V * F / (R * T)));
    inak = Cm * inakbar * fnak * kc / (kc + kmko) / (1 + pow(kmnai / nai, 1.5));

    /* compute icap calcium pump current LR-style */
    icap = 1.4 * Cm * icapbar * Cass / (/*1.013e-04*/Cass + kmcap);

    inaca = GNACA * Cm * knacalr / (pow(kmnalr, 3.0) + pow(nac, 3.0)) / (kmcalr + cac) /
            (1 + ksatlr * exp((gammalr - 1) * V * F / (R * T))) *
            (nai * nai * nai * cac * exp(V * gammalr * F / (R * T)) - nac * nac * nac * (Cass) *
             exp(V * (gammalr - 1) * F / (R * T)));

    /* compute naidot sodium concentration derivative */
    naidot = (-3 * inak - 3 * inaca - ibna - ina) / (F * vi);

    /* compute kidot potassium concentration derivative */
    kidot = (2 * inak - ik1 - ito - ikur - ikr - iks - ibk) / (F * vi);

    /* update all concentrations */
    nai = nai + dt * naidot;
    ki = ki + dt * kidot;

    /* update ina m gate */
    a = 0.32 * (V + 47.13) / (1 - exp(-0.1 * (V + 47.13)));
    if (fabs(V + 47.13) < 1e-10) a = 3.2; /* denominator = 0 */
    b = 0.08 * exp(-V / 11);
    tau = tau_INa_act * (1 / (a + b)); inf = a * tau;
    m = inf + (m - inf) * exp(-dt / tau);

    /* update ina h gate */
    if (V >= -40.0)
    {
        a  = 0.0;
        b = 1 / (0.13 * (1 + exp((V + 10.66) / -11.1)));
    }
    else
    {
        a = 0.135 * exp((V + 80) / -6.8);
        b = 3.56 * exp(0.079 * V) + 3.1e5 * exp(0.35 * V);
    }
    tau = tau_INa_inact * (1 / (a + b)); inf = a * tau;
    h = inf + (h - inf) * exp(-dt / tau);

    /* update ina j gate */
    if (V >= -40.0)
    {
        a  = 0.0;
        b = 0.3 * exp(-2.535e-7 * V) / (1 + exp(-0.1 * (V + 32)));
    }
    else
    {
        a = (-1.2714e5 * exp(0.2444 * V) - 3.474e-5 * exp(-0.04391 * V)) * (V + 37.78) /
            (1 + exp(0.311 * (V + 79.23)));
        b = 0.1212 * exp(-0.01052 * V) / (1 + exp(-0.1378 * (V + 40.14)));
    }
    tau = 1 / (a + b); inf = a * tau;
    j = inf + (j - inf) * exp(-dt / tau);

    /* update oa ito gate */
    /* corrected for 37 deg */
    /* define an voltage shift due to junctional potential
          and effect of Cd++ */
    /* update the xr ikr gate */
    vshift = 0;
    a = 0.0003 * (V - vshift + 14.1) / (1 - exp((V - vshift + 14.1) / -5));
    b = 0.000073898 * (V - vshift - 3.3328) / (exp((V - vshift - 3.3328) / 5.1237) - 1);
    if (fabs(V - vshift + 14.1) < 1e-10) a = 0.0015; /* denominator = 0 */
    if (fabs(V - vshift - 3.3328) < 1e-10) b = 3.7836118e-4; /* denominator = 0 */
    tau = 1 / (a + b);
    inf = 1 / (1 + exp((V + IKr_ac_shift + 14.1) / (-6.5 * IKr_grad)));
    xr = inf + (xr - inf) * exp(-dt / tau);

    /* update the xs ikr gate */
    vshift = 0;
    a = 0.00004 * (V - vshift - 19.9) / (1 - exp((V - vshift - 19.9) / -17));
    b = 0.000035 * (V - vshift - 19.9) / (exp((V - vshift - 19.9) / 9) - 1);
    if (fabs(V - vshift - 19.9) < 1e-10) /* denominator = 0 */
    {
        a = 0.00068;
        b = 0.000315;
    }
    /* tau reduced by 50% as described in manuscript */
    tau = 0.5 / (a + b);
    inf = sqrt(1 / (1 + exp((V - IKs_shift - 19.9) / (-12.7 * IKs_grad))));
    xs = inf + (xs - inf) * exp(-dt / tau);

    /* update icaL d gate */
    vshift = CaL_ac_shift;
    a = 1 / (1 + exp((V - vshift + 10) / -6.24));
    tau = a * (1 - exp((V - vshift + 10) / -6.24)) / (0.035 * (V - vshift + 10));
    if (fabs(V - vshift + 10) < 1e-10) tau = a * 4.579; /* denominator = 0 */
    inf = 1 / (1 + exp((V - vshift + 10) / -8));
    d = inf + (d - inf) * exp(-dt / tau);

    /* update icaL f gate */
    vshift = CaL_inac_shift;
    inf = exp(-(V - vshift + 28) / 6.9) / (1 + exp(-(V - vshift + 28) / 6.9));
    tau = ICaL_tau_rate * (1.5 * 2 * 3 / (0.0197 * exp(-0.0337 * 0.0337 * (V - vshift + 10) *
                                          (V - vshift + 10)) + 0.02));
    f = inf + (f - inf) * exp(-dt / tau);

    //new concs

    double betass;
    betass = pow(( 1 + SLlow * KdSLlow / pow(((Cass) + KdSLlow), 2) + SLhigh * KdSLhigh / pow(((Cass) + KdSLhigh), 2) + BCa * KdBCa / pow(((Cass) + KdBCa), 2)  ), (-1));

    double betai, gammai;
    betai = pow(( 1 + BCa * KdBCa / pow((Cai + KdBCa), 2)  ), (-1));
    gammai = BCa * KdBCa / pow((Cai + KdBCa), 2);

    double betaSR1, betaSR2;
    betaSR1 = pow( ( 1 + CSQN * KdCSQN / pow((CaSR1 + KdCSQN), 2) ), (-1));
    betaSR2 = pow( ( 1 + CSQN * KdCSQN / pow((CaSR2 + KdCSQN), 2) ), (-1));

    double Jj_nj;
    Jj_nj = DCa * Aj_nj / xj_nj * ((Cass) - Cai) * 1e-6;

    double J_SERCASR, J_bulkSERCA;
    double J_SERCASRss, J_bulkSERCAss;

    J_SERCASR =  (-k3 * pow(CaSR1, 2) * (cpumps - SERCACa) + k4 * (SERCACa)) * Vnonjunct3 * 2;
    J_bulkSERCA = (k1 * pow(Cai, 2) * (cpumps - (SERCACa)) - k2 * (SERCACa)) * Vnonjunct3 * 2;

    J_SERCASRss = (-k3 * pow(CaSR2, 2) * (cpumps - (SERCACass)) + k4 * (SERCACass)) * Vss * 2;
    J_bulkSERCAss = (k1 * pow((Cass), 2) * (cpumps - (SERCACass)) - k2 * (SERCACass)) * Vss * 2;

    double RyRtauadapt = 1;

    double RyRtauactss = 5e-3;
    double RyRtauinactss = 15e-3;
    double  RyRtauact = 18.75e-3;
    double RyRtauinact = 87.5e-3;

    double nuss = 625 * Vss;
    double RyRSRCass = (1 - 1 / (1 +  exp((CaSR2 - 0.3) / 0.1)));
    double RyRainfss = 0.505 - 0.427 / (1 + exp((( Cass + (fRyR * Cass) ) * 1000 - 0.29) / 0.082));
    double RyRoinfss = (1 - 1 / (1 +  exp(((Cass + (fRyR * Cass)   ) * 1000 - ((RyRass) + 0.22)) / 0.03)));
    double RyRcinfss = (1 / (1 + exp(((Cass + (fRyR * Cass )) * 1000 - ((RyRass) + 0.02)) / 0.01)));
    double Jrelss = nuss * ( (RyRoss) ) * (RyRcss) * RyRSRCass * ( CaSR2 -  (Cass) );

    double nu3 = 1 * Vnonjunct3;
    double RyRSRCa3 = (1 - 1 / (1 +  exp((CaSR1 - 0.3) / 0.1)));
    double RyRainf3 =  0.505 - 0.427 / (1 + exp(( (Cai + ( fRyR * Cai)  ) * 1000 - 0.29) / 0.082));
    double RyRoinf3 = (1 - 1 / (1 +  exp(( (Cai + ( fRyR * Cai) ) * 1000 - ((RyRa3) + 0.22)) / 0.03)));
    double RyRcinf3 = (1 / (1 +  exp(( (Cai + (fRyR * Cai ) ) * 1000 - ((RyRa3) + 0.02)) / 0.01)));
    double Jrel3 = nu3 * ( (RyRo3) ) * (RyRc3) * RyRSRCa3 * ( CaSR1 -  Cai );


    Jrelss = IREL * Jrelss;
    Jrel3 = IREL * Jrel3;
    //  Jrelss = 0;

    double JSRCaleak3 = GSR_leak * kSRleak * ( CaSR1 - Cai ) * Vnonjunct3;
    double JSRCaleakss = GSR_leak * kSRleak * ( CaSR2 - (Cass) ) * Vss;


    double JCa, JCass;
    JCa = -BULK_CONST * J_bulkSERCA + JSRCaleak3 + Jrel3 + Jj_nj;
    JCass = -Jj_nj + JSRCaleakss - BULK_CONST * J_bulkSERCAss + Jrelss;

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

    dy =  betass * ( JCass / Vss + ((-( RYR * icaL) - ibca - icap - icaT + 2 * inaca)) / (2 * Vss * 1000 * F) );
    Cass = Foward_Euler(dt / 1000, dy, Cass);

    dy = /*betai * (DCa + gammai*DCaBm) * ( (Cai[4]-2*Cai[3]+Cai[2])/(dx*dx) + (Cai[4]-Cai[2])/(2*3)*(dx*dx) ) - 2*betai[3]*gammai[3]*DCaBm/(KdBCa + Cai[3]) * pow(((Cai[4]-Cai[2])/(2*dx)),2) + */JCa / Vnonjunct3 * betai;
    Cai = Foward_Euler(dt / 1000, dy, Cai);

    dy =  betaSR1 * (DCaSR) * ( (CaSR2 - 2 * CaSR1 + CaSR1) / (dx * dx) + (CaSR1 - CaSR2) / (2 * 3 * (dx * dx)) ) + JSRCa1 / VSR3 * betaSR1;

    CaSR1 = Foward_Euler(dt, dy, CaSR1);

    dy = betaSR2 * (DCaSR) * ( (CaSR2 - 2 * CaSR2 + CaSR1) / (dx * dx) + (CaSR2 - CaSR1) / (2 * 4 * (dx * dx)) ) + JSRCa2 / VSR4 * betaSR2;

    CaSR2 = Foward_Euler(dt, dy, CaSR2);



    /* update membrane voltage */
    double Itot;
    Itot = ((INaBlock * ina) + icaL + icap + ik1 + ito + ikur + ikr + iks + ibna + ibk + ibca + inak + inaca + iab + IKAcH + (IfBlock * If) + icaT) / Cm;

    state[ 1] = m ;
    state[ 2] = h ;
    state[ 3] = j ;
    state[ 4] = d ;
    state[ 5] = f ;
    state[ 6] = xr ;
    state[ 7] = xs ;
    state[9] = ki ;
    state[10] = Cass;
    state[11] = Cai;
    state[12] = CaSR1;
    state[13] = CaSR2;

    state[14] = SERCACa;
    state[15] = SERCACass;

    state[16] = RyRoss;
    state[17] = RyRcss;
    state[18] = RyRass;
    state[19] = RyRo3;
    state[20] = RyRc3;
    state[21] = RyRa3;
    state[22] = Itr;
    state[23] = Its;
    state[24] = Isusr;
    state[25] = Isuss;
    state[26] = fca ;

    state[27] =   AcHj;
    state[28] =  AcHk;


    state[29] = if_y;
    state[30] = dd;
    state[31] = ff;

    return Itot;

} // end MIKE



// double crn_con(cell_params *params, double *state, double *results)
//
// integrates the CRN model through dt ms, applying a stimulus current of stim.
// The current state of the model is stored in state, and all but the membrane
// potential is updated during the timestep, using the euler method for
// concentrations and the rush-larsen method for the gating parameters.
double crn_con(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results) {

    //double const    vcell = 20100.0; /* um3 */
    double const    vi =  0.68 * 20100.0;
    double const    vup = 0.0552 * 20100.0;
    double const    vrel = 0.0048 * 20100.0;
    double const    T = 310; /* 37 Celcius */
    double const    Tfac = 3;
    //double const    Csp = 1e+6; /* pF/cm2 */
    double const    Cm = 100.0; /* pF */
    double const    F = 96.4867; /* coul/mmol */
    double const    R = 8.3143; /* J K-1 mol-1 */
    //double const    kb = 5.4; /* mM */
    //double const    nab = 140; /* mM */
    //double const    cab = 1.8; /* mM */
    double const    nac = 140.;
    double const    cac = 1.8;
    double const    kc = 5.4;
    double const    gna = 7.8; /* nS/pF */
    double const    gto = 0.1652; /* nS/pF */
    double const    gkr = 0.029411765; /* nS/pF */
    double const    gks = 0.12941176; /* nS/pF */
    double const    gcaL = 0.1294; /* nS/pF */
    double const    ErL = 65.0; /* mV */
    double const    gk1 = 0.09; /* nS/pF */
    double const    gbna = 0.0006744375; /* nS/pF */
    double const    gbk = 0.0;
    double const    gbca = 0.001131; /* nS/pF */
    double const    inakbar = 0.59933874; /* pA/pF */
    double const    kmnai = 10.0; /* mM */
    double const    kmko = 1.5; /* mM */
    double const    icapbar = 0.275; /* pA/pF */
    double const    kmcap = 0.0005; /* mM */
    double const    knacalr = 1600.0; /* pA/pF */
    double const    kmnalr = 87.5; /* mM */
    double const    kmcalr = 1.38; /* mM */
    double const    ksatlr = 0.1;
    double const    gammalr = 0.35;
    double const    trpnbar = 0.070; /* mM */
    double const    cmdnbar = 0.050; /* mM */
    double const    csqnbar = 10; /* mM */
    double const    kmcsqn = 0.8; /* mM */
    double const    kmcmdn = 0.00238; /* mM */
    double const    kmtrpn = 0.0005; /* mM */
    double const    grelbar = 30.0; /* ms-1 */
    double const    kmup = 0.00092; /* mM */
    double const    iupbar = 0.005; /* mM/ms */
    //double const    caupmax = 15.0; /* mM */
    double const    kupleak = 0.005 / 15.0; /* ms-1 */
    double const    tautr = 180.0; /* ms */

    double     V = state[0];
    double     m = state[1];
    double     h = state[2];
    double     j = state[3];
    double     d = state[4];
    double     f = state[5];
    double     xr = state[6];
    double     xs = state[7];
    double     nai = state[8];
    double     cai = state[9];
    double     ki = state[10];
    double     caup = state[11];
    double     carel = state[12];
    double     oa = state[13];
    double     oi = state[14];
    double     ua = state[15];
    double     ui = state[16];
    double     fca = state[17];
    double     u = state[23];
    double     v = state[22];
    double     w = state[21];

    /* computed quantities */
    double cmdn, trpn, csqn;
    double Ek, Ena, Eca, ina, icaL, ik, ibna, ibk, ibca, inak, ik1;
    double ito, gkur, ikur, ikr, iks;
    double inaca, iab;
    double IRel;
    double itr, iup, iupleak;
    double fnak, caflux, icap, sigma;
    double natot, ktot, catot, itot;
    double dcai, dki, dnai, dcaup, dcarel;

    /* utility variables */
    double a, b, tau, inf;

    // lookup table
    double *table_row = get_table_row(table, V);

    /* compute Ek */
    Ek = 26.71 * log(kc / ki);

    /* compute Ena */
    Ena = 26.71 * log(nac / nai);

    /* compute Eca */
    Eca = 13.35 * log(cac / cai);

    /* compute sodium current */
    ina = Cm * params->ina * gna * m * m * m * h * j * (V - Ena);

    /* compute transient outward current */
    ito = het->Gto * Cm * params->ito * gto * oa * oa * oa * oi * (V - Ek);

    /* compute ultra-rapid potassium current */
    gkur = table_row[GKUR];

    iab = 0;
    iab = Cm * 0.0003879 * (V + 69.6) / (1 - 0.8377 * exp((V + 49.06) / 1056));



    /* sustained outward current */
    ikur = Cm * params->ikur * gkur * ua * ua * ua * ui * (V - Ek);

    ikr = het->GKr * Cm * params->ikr * gkr * xr * (V - Ek) * table_row[IKR_FAC];

    /* compute the slow delayed outward rectifier K current */
    iks = Cm * params->iks * gks * xs * xs * (V - Ek);
    ik = ikr + iks;

    /* compute calcium current */
    icaL = het->GCaL * Cm * params->icaL * gcaL * d * f * fca * (V - ErL);

    /* compute time independent potassium current */
    ik1 = Cm * params->ik1 * gk1 * (V - Ek) * table_row[IK1_FAC];

    /* compute ibna background current */
    ibna = Cm * params->ibna * gbna * (V - Ena);

    /* compute potassium background current */
    ibk = Cm * params->ibk * gbk * (V - Ek);

    /* compute ibca background current */
    ibca = Cm * params->ibca * gbca * (V - Eca);

    /* compute inak sodium-potassium pump current, LR-style */
    inak = Cm * params->inak * inakbar * table_row[FNAK] * (1 / (1 + pow(kmnai / nai, 1.5))) * (kc / (kc + kmko));

    /* compute icap calcium pump current LR-style */
    icap = Cm * params->icap * icapbar * cai / (cai + kmcap);

    /* compute inaca exchanger current LR-style */
    a = knacalr * ((table_row[INACA_EXP_GAMMA] * nai * nai * nai * cac) - (table_row[INACA_EXP_GAMMA_MINUS] * nac * nac * nac * cai));
    inaca = Cm * params->inaca * a * table_row[INACA_DENOM];

    /* compute naidot sodium concentration derivative */
    // include the stimulus current as a sodium flux
    // natot = -3*inak-3*inaca-ibna-ina+stim;
    natot = -3 * inak - 3 * inaca - ibna - ina;
    dnai = natot / (F * vi);

    /* compute kidot potassium concentration derivative */
    ktot = (2 * inak - ik1 - ito - ikur - ikr - iks - ibk);
    dki = ktot / (F * vi);

    /* calcium buffer dynamics */
    cmdn = cmdnbar * cai / (cai + kmcmdn);
    trpn = trpnbar * cai / (cai + kmtrpn);
    csqn = csqnbar * carel / (carel + kmcsqn);

    /* SR calcium handling */
    IRel = grelbar * u * u * v * w * (carel - cai);
    iup = iupbar / (1 + kmup / cai);
    iupleak = kupleak * caup;
    itr = (caup - carel) / tautr;

    /* compute caidot calcium concentration derivative */
    /* using steady-state buffer approximation */
    catot = 2 * inaca - icap - icaL - ibca;
    dcai = (catot / (2 * F * vi) +
            (iupleak - iup) * vup / vi + IRel * vrel / vi) /
           (1 + trpnbar * kmtrpn / (cai * cai + 2 * cai * kmtrpn + kmtrpn * kmtrpn) +
            cmdnbar * kmcmdn / (cai * cai + 2 * cai * kmcmdn + kmcmdn * kmcmdn));

    /* update caup calcium in uptake compartment */
    dcaup = (iup - itr * vrel / vup - iupleak);

    /* update carel calcium in release compartment */
    dcarel = ((itr - IRel) / (1 + (csqnbar * kmcsqn /
                                   (carel * carel + 2 * carel * kmcsqn + kmcsqn * kmcsqn))));


    /* update ina gates */
    m = table_row[INA_M_INF] + (m - table_row[INA_M_INF]) * table_row[INA_M_TAU];
    h = table_row[INA_H_INF] + (h - table_row[INA_H_INF]) * table_row[INA_H_TAU];
    j = table_row[INA_J_INF] + (j - table_row[INA_J_INF]) * table_row[INA_J_TAU];

    /* update oa ito gate */
    oa = table_row[ITO_OA_INF] + (oa - table_row[ITO_OA_INF]) * table_row[ITO_OA_TAU];
    oi = table_row[ITO_OI_INF] + (oi - table_row[ITO_OI_INF]) * table_row[ITO_OI_TAU];

    /* update ua ikur gate */
    ua = table_row[IKUR_UA_INF] + (ua - table_row[IKUR_UA_INF]) * table_row[IKUR_UA_TAU];
    ui = table_row[IKUR_UI_INF] + (ui - table_row[IKUR_UI_INF]) * table_row[IKUR_UI_TAU];

    /* update the xr ikr gate */
    xr = table_row[IKR_XR_INF] + (xr - table_row[IKR_XR_INF]) * table_row[IKR_XR_TAU];

    /* update the xs ikr gate */
    xs = table_row[IKS_XS_INF] + (xs - table_row[IKS_XS_INF]) * table_row[IKS_XS_TAU];

    /* update icaL d gate */
    d = table_row[ICAL_D_INF] + (d - table_row[ICAL_D_INF]) * table_row[ICAL_D_TAU];

    /* update icaL f gate */
    f = table_row[ICAL_F_INF] + (f - table_row[ICAL_F_INF]) * table_row[ICAL_F_TAU];

    /* update the SR gating variables */

    caflux = (1e-12 * vrel * IRel) - ((1e-12 / (2 * F)) * (0.5 * icaL - 0.2 * inaca));
    inf = 1 / (1 + exp(-(caflux - 3.4175e-13) / 13.67e-16));
    tau = 8.0;
    u = inf + (u - inf) * exp(-params->dt / tau);

    inf = 1 - 1 / (1 + exp(-(caflux - 6.835e-14) / 13.67e-16));
    tau = 1.91 + 2.09 / (1 + exp(-(caflux - 3.4175e-13) / 13.67e-16));
    v = inf + (v - inf) * exp(-params->dt / tau);

    w = table_row[SR_W_INF] + (w - table_row[SR_W_INF]) * table_row[SR_W_TAU];

    /* update the fca gate */
    inf = 1 / (1 + (cai / 0.00035));
    tau = 2.0;
    fca = inf + (fca - inf) * exp(-params->dt / tau);

    // update concentrations
    nai     += dnai * params->dt;
    cai     += dcai * params->dt;
    ki      += dki * params->dt;
    caup    += dcaup * params->dt;
    carel   += dcarel * params->dt;


    /* update membrane voltage */

    // itot = (catot+ktot+natot)/Cm;

    itot = ((INaBlock * ina) + icaL + icap + ik1 + ito + ikur + ikr + iks + ibna + ibk + ibca + inak + inaca + iab) / Cm;

    state[ 1] = m ;
    state[ 2] = h ;
    state[ 3] = j ;
    state[ 4] = d ;
    state[ 5] = f ;
    state[ 6] = xr ;
    state[ 7] = xs ;
    state[ 8] = nai ;
    state[ 9] = cai ;
    state[10] = ki ;
    state[11] = caup ;
    state[12] = carel ;
    state[13] = oa ;
    state[14] = oi ;
    state[15] = ua ;
    state[16] = ui ;
    state[17] = fca ;
    state[23] = u ;
    state[22] = v ;
    state[21] = w ;

    return itot;
}

void FK_initial_conditions(double state[], int celltype) {

    state[0] = 0.010066;
    state[1] = 0.999027;
    state[2] = 0.9095441;

    state[3] = 0.000905; // Itr
    state[4] = 0.956638; // Its


    state[5] = 0.006676; // m
    state[6] = 0.896736; // h
    state[7] = 0.918836; // j
} // end FK ICs


double FK(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results, double V) {
    int e1 = 0;
    double dt = params->dt;

    double t_fast = 0.055;
    double t_slow = 2;
    double t_fopen1 = 1.0;
    double t_fopen2 = 10;
    double t_fclose = 60;
    double t_sopen = 10;
    double t_sclose = 20;
    double t_ung1 = 30;
    double t_ung2 = 30;
    double Vf = 0.065;
    double Vs = 0.06;
    double Vu = 0.05;
    double Vfopen = 1;
    double Vslow = 0.8;
    double k = 10.0;

    double Ek;
    double itr = state[3];
    double its = state[4];
    double inf, tau;

    Ek = -70;

    double Ito, INa;

    double Ena;
    double m = state[5];
    double h = state[6];
    double j = state[7];
    double alpha, beta;

    // Heterogeneous params
    // double het_param_1 = het->het_param_1;

    Ena = 46;

    INa = 6 * m * m * m * h * j * (V - Ena);
    alpha =  0.32 * (V + 47.13) / (1 - exp(-0.1 * (V + 47.13)));
    if (fabs(V + 47.13) < 1e-10) alpha = 3.2;
    beta = 0.08 * exp(-V / 11.0);

    tau = 1 / (alpha + beta);
    inf = alpha * tau;

    m = inf + (m - inf) * exp(-dt / tau);

    if (V >= -40.0)
    {
        alpha  = 0.0;
        beta = 3 * exp(-2.535e-7 * V) / (1 + exp(-0.1 * (V + 32)));
    }
    else
    {
        alpha = (-0.714e5 * exp(0.2444 * V) - 3.474e-5 * exp(-0.04391 * V)) * (V + 37.78) / (1 + exp(0.311 * (V + 79.23)));
        beta = 0.212 * exp(-0.01052 * V) / (1 + exp(-0.1378 * (V + 40.14)));
    }
    tau = 1 / (alpha + beta);
    inf = alpha * tau;

    j = inf + (j - inf) * exp(-dt / tau);

    if (V >= -40.0)
    {
        alpha  = 0.0;
        beta = 1 / (0.3 * (1 + exp((V + 10.66) / -11.1)));
    }
    else
    {
        alpha = 1.135 * exp((V + 80) / -6.8);
        beta = 3.56 * exp(0.079 * V) + 3.1e5 * exp(0.35 * V);
    }
    tau = 1 / (alpha + beta);
    inf = alpha * tau;

    h = inf + (h - inf) * exp(-dt / tau);


    //Ito
    Ito = 5 * itr * its * (V - Ek);
    inf = 2 / (5 + exp((V - 10.0) / -11.0));
    tau = (0.06 * exp(-(V / 300.0) * 1) + 0.1);
    itr = inf + (itr - inf) * exp(-(dt / 500) / tau);

    inf = 0.2 / (1.0 + exp((V + 40.5) / 11.5));
    tau = (0.2635 * exp (-((V + 52.45) / 15.8827) * .1) + 0.1414);
    its = inf + (its - inf) * exp(-(dt / 500) / tau);

    double f_inf, t_fopen, t_f, t_s, s_inf, t_ung, ds, df, du, Sv, Uv, Fv;

    double j_si, j_ung, j_fi;

    double u = state[0];
    double f = state[1];
    double s = state[2];

    f_inf = (u < Vf) ? 1 : 0;
    t_fopen = (u < Vfopen) ? t_fopen1 : t_fopen2;
    t_f = (u < Vf) ? t_fopen : t_fclose;

    s_inf = (u < Vs) ? 1 : 0;
    t_s = (u < Vs) ? t_sopen : t_sclose;

    t_ung = (u < Vu) ? t_ung1 : t_ung2;

    Sv = (1 + tanh(k * (u - Vslow)));
    j_si = -(s / t_slow) * Sv;

    Uv = (u < Vu) ? u : 1;
    j_ung = 5 * (1.0 / t_ung) * Uv;

    Fv = (u < Vf) ? 0 : (u - Vf) * (1 - u);
    j_fi = -12 * (f / t_fast) * Fv;

    df = (f_inf - f) / t_f;
    ds = (s_inf - s) / t_s;

    /*
    printf("INa = %f\n",INa);
    printf("Itoa = %f\n",Ito);
    printf("j_si = %f\n",j_si);
    printf("j_ung = %f\n",j_ung);
    printf("j_fi = %f\n",j_fi);
    printf("%d\n",e1);
    */

    double Iion_tot = INa + Ito + j_si + j_ung + j_fi ;

    //double Iion_tot = INa;

    state[1] += df * dt;
    state[2] += ds * dt;
    state[3] = itr;
    state[4] = its;
    state[5] = m;
    state[6] = h;
    state[7] = j;


    return (Iion_tot);
} // end FK
