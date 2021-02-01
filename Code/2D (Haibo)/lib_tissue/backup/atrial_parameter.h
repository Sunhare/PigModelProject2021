
#ifndef ATRIAL_PARAMETER_H
#define ATRIAL_PARAMETER_H

#include "EnumSimulationCtrl.hpp"


typedef struct {
	double GNa;
	double tau_ina_act;
	double tau_ina_inact;

	double Gto;
	double ITo_vshift;
	
	double GCaL;
	double ICaL_inac_shift;
	double ICaL_ac_shift;
	double ICaL_tau_rate;
	
	double GKs;
	double IKs_ac_grad;
	double IKs_shift;
	double IKs_grad;

	
	double GKr;
	double IKr_ac_grad;
	double IKr_ac_shift;
	double IKr_grad;

	
	double GK1;
	double IK1_v_shift;

	
	double Gf;
	double If_grad;
	double If_vshift;
	
	double GNaCa;
    double GNaK;
	double GCaT;
    double GCap;    
    double Gbca;

	double BULK_CONST;
	double GSR_leak;
	double RyR;
	double fIRel;
	double fRyR;

	double GKur;
	double IKur_cnd_add;
	double IKur_cnd_mult;
	double IKur_cnd_shift;
	double IKur_cnd_grad;
	double IKur_ac_shift;
	double IKur_ac_grad;
	double IKur_ac1_mult;
	double IKur_ac1_shift;
	double IKur_ac1_grad;
	double IKur_ac2_mult;
	double IKur_ac2_shift;
	double IKur_ac2_grad;
	double IKur_ac_add;
	double IKur_inac_mult;
	double IKur_inac_shift;
	double IKur_inac_grad;
	double IKur_inac_add;
	double Simple_Ikur_ac_shift;
    double Simple_Ikur_ac_grad;
    double Simple_Ikur_inac_shift;
    double Simple_Ikur_inac_grad;
    double Simple_GKur;
    
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
} AtriaParameter;


void AtriaMutationParameters(AtriaParameter * het, IKurMuationType mutation);
void Atria_AF_Parameters(AtriaParameter *het, int AFtype, int celltype);
void Regionalparameters(AtriaParameter *het, float ISO, float Ach, int celltype);
void AtriaParameterInitialise(AtriaParameter *het);





#endif 