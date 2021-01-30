#include "parameters.h"

void UserData::Default_user_parameters() {

    // Default scaling factors
    GNa = GCaL = GKur = GKr = GK1 = GKs = Gto =  GNaCa = GNaK = GCap = IRel = RYR = GSR_leak = GCaT = Gbca = 1.0;
    IKur_ac_grad = IKur_inac_grad = IKs_grad = IKr_grad = 1;
    BULK_CONST = 1.2;
    fRyR = IKur_ac_shift = IKur_inac_shift = IKs_shift =  IK1_v_shift = IKr_ac_shift  =  0.0;

    IKur_ac1_grad = IKur_ac2_grad = 1;
    IKur_ac1_mult = IKur_inac_mult = IKur_ac2_mult = 1;
    IKur_ac_add = IKur_inac_add = 0;
    IKur_ac1_shift = IKur_ac2_shift = 0;
    If_vshift = 0;
    If_grad = 1;
    Gf = 0.0;
    Istim = 0;

}

UserData::UserData(int region, int mutation, int AF_model) {
    Default_user_parameters();
    Regional_user_parameters(region);
    Mutation_user_parameters(region, mutation);
    AF_user_remodelling(AF_model);
}

UserData::UserData() {
    Default_user_parameters();
}


void UserData::Regional_user_parameters(int region) {


    if (region == 0) {
        //        BULK_CONST = 1.4;
    }
    else  if (region == 1) { // PM
        GCaL = 0.94 * GCaL;
    }
    else if (region == 2) { // CT
        GCaL = 1.68;//2;  // note 1.68 = Biophysically based (Feng et al), 2 better replicates APD differences (1.68 is still within expt range)
        Gto = 1.35 * Gto;
    }
    else if (region == 3 || region == 7) { // RAA / AS
        BULK_CONST = 1.5;
        Gto = 0.4; // or 0.53 /*0.53;//*/
        if (region == 7) { // AS
            GCaL = 0.4;//0.25;
            GKur = 0.667;
            Gto = 0.4 * 0.4;
            IK1_v_shift = -6;
            GNa = 1.3;
        }
        /*if (IKur_type_CNZ == 0){
            IKur_ac_shift = -14;
            IKur_inac_shift = 25;
            IKur_ac_grad = 2.1317;
            IKur_inac_grad = 1.769;
        }*/
    }
    else if (region == 4) { // AVR
        GCaL = 0.67;
        GKr = 1.63;
        Gto = 0.6;
    }
    else if (region == 5) { // BB
        GCaL = 2.32;//2.2;//1.6;
        Gto = 1.17;//0.8;
        GK1 = 0.85;
        BULK_CONST = 1.6;//1.22;

    }
    else if (region == 6) { // LA
        Gf = 1;
        GKr = 1.6;

    }
    else if (region == 8) { // LAA
        Gf = 1;
        GKr = 1.6;
        Gto = 0.53;

        if (IKur_type_CNZ == 0) {
            IKur_ac_shift = -14;
            IKur_inac_shift = 25;
            IKur_ac_grad = 2.1317;
            IKur_inac_grad = 1.769;
        }
        GKur = 0.8;
    }
    else if (region == 9) { // PV

        IKr_ac_shift = -4.2;
        IKr_grad = 0.938;
        IKs_shift = -9.6;
        IKs_grad = 1.047;
        IK1_v_shift = -15;
        GK1 = 0.65;

    }
    else if (region == 10) { // PV new (rough ehrlich) -- note wrong on GKr and GKs
        GKr = 0.75 * 1.6;
        Gto = 0.8 * 0.53;
        GKs = 0.7 * 1.8;
        IKs_shift = -13.43;
        IKs_grad = 0.5;//0.75;
        BULK_CONST = 1.3;
        GK1 = 0.7;
        GCaL = 0.65;//0.75;
        IK1_v_shift = -10;
    }
    else if (region == 11) { // PV new Ehrlich + Cha (Primarily Ehrlich) - USE THIS PV MODEL
        GKr = 1.5 * 1.6; //1.6*1.6;
        Gto = 0.75;//0.72*0.53;
        GKs = 1.5;//1.75*1.8;
        GCaL = 0.7;
        GK1 = 0.62;//0.69;
    }
    else if (region == 14) { // SAN C
        GNa = 0.06;
        GKur = 0.26;
        GK1 = 0.42;
        GCaT = 4.5 * 17; //5.2*17;
        Gf = 4.4;
        GNaCa = 0.5;
        Gto = 0.4;
        GCaL = 0.68;
        GKs = 0.69;
        GKr = 0.45;
        BULK_CONST = 3;
        If_grad = 1.1;
    }
    else if (region == 15) { // SAN P

        GNa = 0.3;
        GKur = 0.26;
        GK1 = 0.3;//0.42;
        GCaT = 4.5 * 17;
        Gf = 3.93 * 4.4;
        GNaCa = 0.5;
        Gto = 0.8;//0.92;
        GCaL = 2.28;
        GKs = 2;//4.19;
        GKr = 2.75;
        BULK_CONST = 3;
        If_grad = 1.075;


    }

} // end region Params


void UserData::Mutation_user_parameters(int region, int mutation) {

    // IKur mutations, in Colman J Physiol model
    // note - reverse signs on shifts as formuation has "V+shift" and should be "V-shift" as "V-V1/2" and V1/2 is being shfited
    /*
       if (IKur_type_CNZ == 0){
       if (mutation == 1){ // D332H
       GKur = 1.7795*GKur;
       IKur_ac_shift += 3.26;
       IKur_ac_grad *= 0.8087;
       IKur_inac_shift += -9.61;
       IKur_inac_grad *= 0.8008;
       }
       else if (mutation == 2){ // E48G
       GKur = 1.32*GKur;
       IKur_ac_shift += 3.02;
       IKur_ac_grad *= 0.96;
       IKur_inac_shift += -4.03;
       IKur_inac_grad *= 0.94;
       }
       if (mutation == 3){ // A305T
       GKur = 1.45*GKur;
       IKur_ac_shift += 4.07;
       IKur_ac_grad *= 1.1;
       IKur_inac_shift += -6.03;
       IKur_inac_grad *= 0.75;
       }
       if (mutation == 4){ // Y155C
       GKur = 0.4745*GKur;
       IKur_ac_shift += 0.89;
       IKur_ac_grad *= 0.76;
       IKur_inac_shift += -5.01;
       IKur_inac_grad *= 0.78;
       }
       if (mutation == 5){ // D469E
       GKur = 0.55*GKur;
       IKur_ac_shift += -0.5;
       IKur_ac_grad *= 0.9113;
       IKur_inac_shift += -4.55;
       IKur_inac_grad *= 0.84;
       }
       if (mutation == 6){ // P488S
       GKur = 0.039*GKur;
       IKur_ac_shift += 0.0337;
       IKur_ac_grad *= 0.83;
       IKur_inac_shift += 1.41;
       IKur_inac_grad *= 0.68;
       }
       } // end model type if
       else {*/
    if (mutation == 1) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  = -9.3932825747999988;
        IKur_ac1_grad   = 1.3785501205210822;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 15.229362644299998;
        IKur_ac2_grad   = 0.25822502847411422;
        IKur_ac_add     = 0.0;
        // Inactivation
        IKur_inac_mult  = 0.87254304449870279;
        IKur_inac_shift = -9.6150807654200001;
        IKur_inac_grad  = 0.80075124328979652;
        IKur_inac_add   = 0.073931087206000057;

        GKur = 1.755384 * GKur;

    }
    else if (mutation == 2) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  =  -8.914978286109998;
        IKur_ac1_grad   = 1.687979145508135 ;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 14.395569738899999;
        IKur_ac2_grad   = 0.312429308790384;
        IKur_ac_add     = 0.0;
        // // Inactivation
        IKur_inac_mult  = 0.935206196986113;
        IKur_inac_shift = -4.02829;
        IKur_inac_grad  = 0.940280253452448;
        IKur_inac_add   = 0.039197146604;

        GKur = 1.302611 * GKur;

    }
    else if (mutation == 3) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  = -5.135031219399998 ;
        IKur_ac1_grad   = 2.40452882662690 ;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 13.643107896399998;
        IKur_ac2_grad   = 0.387170393885174;
        IKur_ac_add     = 0.0;
        // Inactivation
        IKur_inac_mult  = 0.874602534570044;
        IKur_inac_shift = -6.032311251379999;
        IKur_inac_grad  = 0.748490912918043;
        IKur_inac_add   = 0.070656047487;

        GKur = 1.388272 * GKur;

    }
    else if (mutation == 4) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  = -4.430626802899999 ;
        IKur_ac1_grad   = 1.651529981648123 ;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 3.3770968185;
        IKur_ac2_grad   =  0.517356087786261;
        IKur_ac_add     = 0.0;
        // Inactivation
        IKur_inac_mult  = 0.936476668495346;
        IKur_inac_shift = -5.012779270500001;
        IKur_inac_grad  = 0.781775743434569;
        IKur_inac_add   = 0.034583585385;

        GKur = 0.468289 * GKur;

    }
    else if (mutation == 5) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  = -9.674129740199998 ;
        IKur_ac1_grad   = 1.872887568793469 ;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 7.825694557299999;
        IKur_ac2_grad   =  0.495836222570499;
        IKur_ac_add     = 0.0;
        // Inactivation
        IKur_inac_mult  =  1.174004519012284;
        IKur_inac_shift = -4.5454272743;
        IKur_inac_grad  = 0.842432589996777;
        IKur_inac_add   = -0.09291551303;

        GKur = 0.555646 * GKur;

    }
    else if (mutation == 6) {
        IKur_ac1_mult   = 1.0;
        IKur_ac1_shift  = -10.717546440049999 ;
        IKur_ac1_grad   = 1.073001198054284 ;
        IKur_ac2_mult   = 1.0;
        IKur_ac2_shift  = 37.524891077699998;
        IKur_ac2_grad   =  2.054330062518264;
        IKur_ac_add     = 0.0;
        // Inactivation
        IKur_inac_mult  =  1.212942827258507;
        IKur_inac_shift = 1.4151025432;
        IKur_inac_grad  = 0.687940393974062;
        IKur_inac_add   = -0.110508855073;

        GKur = 0.039484 * GKur;
    }
    else if (mutation == 10) {
        Gto = 1.75;
    }
    //} // end else if

} // end mutation function

void UserData::AF_user_remodelling(int AF_model) {


    if (AF_model == 1) { // Bosch based model
        GCaL = 0.3 * GCaL;
        Gto = 0.3 * Gto;
        GK1 = 2 * GK1;
    }
    else if (AF_model == 2) { // Workman based model
        GCaL = 0.35 * GCaL;
        Gto = 0.35 * Gto;
        GK1 = 1.75 * GK1;
    }
    else if (AF_model == 3) { // Wagoner based model
        GCaL = 0.37 * GCaL;
        Gto = 0.34 * Gto;
        GKur = 0.51 * GKur;
        GK1 = 2.06 * GK1;
    }
    else if (AF_model == 4) { // Generic
        GCaL = 0.3 * GCaL;
        Gto = 0.35 * Gto;
        GK1 = 2 * GK1;
        GKur = 0.5 * GKur;
        GNaCa = 1.55 * GNaCa;
        BULK_CONST = 1.5; // Increase according to shanmugam et al, AF_SR_updatke
        GSR_leak = 1.25;
        IRel = 3 * IRel;
        GKs = 2 * GKs;
        RYR = 2.5;
    }
}




void UserData::Acacetin_effect_parameters(double Acacetin_Con) {

    if (Acacetin_Con <= 1.0e-14)
    {
        Acacetin_Con = 1.0e-14;   // just want to make sure that this data be positive;
    }

    double Aca_IC50_IKur = 3.2; // um
    double Aca_IC50_Ito = 9.3; // um
    double Aca_IC50_IKr = 32.4; // um
    double Aca_IC50_IKs = 81.4; // um
    double Aca_hill_IKur = 0.8; // um
    double Aca_hill_Ito = 0.9; // um
    double Aca_hill_IKr = 0.9; // um
    double Aca_hill_IKs = 0.8; // um
    double IKur_Acacetin_B =  1.0 - 1.0 / (1 + pow((Aca_IC50_IKur / Acacetin_Con), Aca_hill_IKur));
    double Ito_Acacetin_B =  1.0 - 1.0 / (1 + pow((Aca_IC50_Ito / Acacetin_Con), Aca_hill_Ito));
    double IKr_Acacetin_B =  1.0 - 1.0 / (1 + pow((Aca_IC50_IKr / Acacetin_Con), Aca_hill_IKr));
    double IKs_Acacetin_B =  1.0 - 1.0 / (1 + pow((Aca_IC50_IKs / Acacetin_Con), Aca_hill_IKs));
    Gto  = Ito_Acacetin_B * Gto;
    GKur = IKur_Acacetin_B * GKur;
    GKr  = IKr_Acacetin_B * GKr;
    GKs  = IKs_Acacetin_B * GKs;
}


