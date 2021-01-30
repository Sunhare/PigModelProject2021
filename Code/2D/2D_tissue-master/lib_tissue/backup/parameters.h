// Header file for the ICs and RHS functions for the Colman 2013 model

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <math.h>


class UserData {

public:
    UserData();
    UserData(int region, int mutation, int AF_model);
    ~UserData() {};
    void Default_user_parameters();
    void Regional_user_parameters(int region);
    void Mutation_user_parameters(int region, int mutation);
    void AF_user_remodelling(int AF_model);
    void Acacetin_effect_parameters(double acacetin_con);
    double Istim;
    int state_len;
    int state_len2;
    double GNa;
    double GCaL;
    double GKur;
    double GKr;
    double GK1;
    double GKs;
    double Gto;
    double Gf;
    double GNaCa;
    double GNaK;
    double GCap;
    double IRel;
    double GCaT;
    double Gbca;
    double IKur_ac_shift;
    double IKur_inac_shift;
    double IKur_ac_grad;
    double IKur_inac_grad;
    double IKs_shift;
    double IKs_grad;
    double IK1_v_shift;
    double IKr_ac_shift;
    double IKr_grad;
    double IKur_ac1_shift;
    double IKur_ac1_grad;
    double IKur_ac2_shift;
    double IKur_ac2_grad;
    double IKur_ac1_mult;
    double IKur_ac_add;
    double IKur_inac_mult;
    double IKur_inac_add;
    double IKur_ac2_mult;
    double RYR;
    double GSR_leak;
    double BULK_CONST;
    double fRyR;
    double IKur_cnd_grad;
    double If_vshift;
    double If_grad;
    int IKur_type_CNZ;
    int tau_type;
    double INACA;
    double CaSR_ss, CaSR_NJ;
    double Irel, Jrel_ss, Jrel_NJ, Jserca_bulk_NJ, Jserca_bulk_ss;
    double ISac, INa, Ito, IKur, IKr, IKs, ICaL, IK1,
           IbK, IbNa, IbCa, Iab, INaCa, INaK, ICap, If, ICaT;
    double Acacetin_Con;
    // Rice_UserData rice_data;
};

typedef struct {

    double GNa;
    double Gto;
    double GKur;
    double GCaL;
    double GKs;
    double GKr;
    double GK1;
    double Gf;
    double GNaCa;
    double GCaT;
    double Bulk_const;
    double ICaL_inac_shift;
    double ICaL_ac_shift;
    double IKr_ac_grad;
    double IKs_ac_grad;
    double If_vshift;

    double IKr_ac_shift;
    double IKr_grad;
    double IKs_shift;
    double IKs_grad;
    double tau_ina_act;
    double tau_ina_inact;
    double ITo_vshift;
    double ICaL_tau_rate;
    double IK1_v_shift;
    double GSR_leak;
    double If_grad;
    double RyR;
    double fIRel;
    double fRyR;
    int IK1_type_default;
    int IK1_type_AS;
    int IK1_type_PV;
    int IKur_type_default;
    int IKur_type_RAA;
    int IKr_type_default;
    int IKr_type_PV;
    int IKs_type_default;
    int IKs_type_LA;
    int IKs_type_PV;
    int IKur_type_CNZ;
    double IKur_cnd_add;
    double IKur_cnd_mult;
    double IKur_cnd_shift;
    double IKur_cnd_grad;
    double IKur_ac1_mult;
    double IKur_ac1_shift;
    double IKur_ac1_grad;
    double IKur_ac2_mult;
    double IKur_ac2_shift;
    double IKur_ac2_grad;
    double IKur_ac_shift;
    double IKur_ac_grad;
    double IKur_ac_add;
    double IKur_inac_mult;
    double IKur_inac_shift;
    double IKur_inac_grad;
    double IKur_inac_add;


} heterogeneous_params_t;


#endif
