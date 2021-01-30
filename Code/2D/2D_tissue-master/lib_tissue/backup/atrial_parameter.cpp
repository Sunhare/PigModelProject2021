#include "atrial_parameter.h"
#include <cmath>

#include <iostream>
#include <cstdlib>

void AtriaParameterInitialise(AtriaParameter *het) {
	het->GNa = 1;
	het->Gto = 1;
	het->GKur = 1;
	het->GCaL = 1;
	het->GKs = 1;
	het->GKr = 1;
	het->GK1 = 1;
	het->Gf = 0.4;
	het->GNaCa = 1;
	het->GCaT = 1;
	het->BULK_CONST = 1.2;
	het->ICaL_inac_shift = 0;
	het->ICaL_ac_shift = 0;
	het->IKr_ac_grad = 1;
	het->IKs_ac_grad = 1;
	het->If_vshift = 0;
	het->IKur_ac_shift = 0;
	het->IKur_inac_shift = 0;
	het->IKur_ac_grad = 1;
	het->IKur_inac_grad = 1;
	het->IKr_ac_shift = 0;
	het->IKr_grad = 1;
	het->IKs_shift = 0;
	het->IKs_grad = 1;
	het->tau_ina_act = 1;
	het->tau_ina_inact = 1;
	het->ITo_vshift = 0;
	het->ICaL_tau_rate = 1;
	het->IK1_v_shift = 0;
	het->GSR_leak = 1;
	het->If_grad = 1;
	het->RyR = 1;
	het->fIRel = 1;
	het->fRyR = 0.0;


	het->IK1_type_default = 1;
	het->IK1_type_AS = 0;
	het->IK1_type_PV = 0;
	het->IKur_type_default = 1;
	het->IKur_type_RAA = 0;
	het->IKr_type_default = 1;
	het->IKr_type_PV = 0;
	het->IKs_type_default = 1;
	het->IKs_type_LA = 0;
	het->IKs_type_PV = 0;

	het->IKur_type_CNZ = 1.0;//IKur_switch; // note = 0 if default, 1 if CNZ version
	het->IKur_cnd_add = 0.0;
	het->IKur_cnd_mult = 1.0;
	het->IKur_cnd_shift = 0.0;
	het->IKur_cnd_grad = 1.0;
	het->IKur_ac1_mult = 1.0;
	het->IKur_ac1_shift = 0.0;
	het->IKur_ac1_grad = 1.0;
	het->IKur_ac2_mult = 1.0;
	het->IKur_ac2_shift = 0.0;
	het->IKur_ac2_grad = 1.0;
	het->IKur_ac_add = 0.0;
	het->IKur_inac_mult = 1.0;
	het->IKur_inac_shift = 0.0;
	het->IKur_inac_grad = 1.0;
	het->IKur_inac_add = 0.0;
	het->Simple_Ikur_ac_shift = 0;
	het->Simple_Ikur_ac_grad = 1;
	het->Simple_Ikur_inac_shift = 0;
	het->Simple_Ikur_inac_grad = 1;
	het->Simple_GKur = 1;
}

void Regionalparameters(AtriaParameter *het, float ISO, float Ach, int celltype) {
	AtriaParameterInitialise(het);
	float fICaL = 0.0;//1.0 / ( 1.0 + exp((-4.362 * (log(ISO) + 3.27)) ) );
	float fRyR  = 0.0;//1.0 / ( 1.0 + exp((-2.55 * (log(ISO) + 1.2)) ) );
	float fIKs  = 0.0;//1.0 / ( 1.0 + exp((-4 * (log(ISO) + 1.4)) ) );
	float fIKur = 0.0;//1.0 / ( 1.0 + exp((-1.8 * (log(ISO) + 2.2)) ) );
	float fINa  = 0.0;//1.0 / ( 1.0 + exp((-2.55 * (log(ISO) + 2.5)) ) );
	float fPLB  = 0.0;//1.0 / ( 1.0 + exp((-3 * (log(ISO) + 2.2)) ) );
	float fIf = fINa;
	het->fRyR = fRyR;


	// assign values for different cell types
	if (celltype == 10) { // SAN
		std::cout << "SAN not supported yet!!!" << std::endl;
		/*het->GNa = 0.06 + (Fcell[n] * 0.24);
		het->GKur = 0.26;
		het->GK1 = 0.42 - (Fcell[n] * 0.12);
		het->GCaT = 1.1 * (4.5 * 17);
		het->Gf = 1.1 * (4.4 + (Fcell[n] * 12.892));
		het->GNaCa = 0.5;
		het->Gto = 0.4 + (Fcell[n] * 0.4);
		het->GCaL = 0.68 + (Fcell[n] * 1.6);
		het->GKs = 0.69 + (Fcell[n] * 1.31);
		het->GKr = 0.45 + (Fcell[n] * 2.3);
		het->BULK_CONST = 3;
		het->If_grad = 1.1 - (Fcell[n] * 0.025);*/
	}
	else if (celltype == 11) { // CT
		het->GCaL = 1.68;
		het->Gto = 1.35;
	}
	else if (celltype == 12) { // PM
		het->GCaL = 0.94;
	}
	else if (celltype == 202) { // RAA / APG
		het->BULK_CONST = 1.5;
		het->Gto = 0.53;
	}
	else if (celltype == 201) { //LAA
		het->GKr = 1.6;
		het->Gto = 0.53;
		het->Gf = 1;
		het->GKur = 0.8;
	}
	else if (celltype == 13 || celltype == 14 || celltype == 200) {
		// RA (no change)11
	}
	else if (celltype == 15) { // BB
		het->GCaL = 1.72;
		het->Gto = 1.35;
	}
	else if (celltype == 16) { // LA
		het->GKr = 1.6;
		het->Gf = 1;
	}
	else if (celltype == 17) { // AS
		het->Gto = 0.4 * 0.4;
		het->GCaL = 0.4;
		het->GKur = 0.677;
		het->IK1_v_shift = -6;
		het->GNa = 1.3;
		het->BULK_CONST = 1.5;
	}
	else if (celltype == 18) { // AVR
		het->GCaL = 0.67;
		het->GKr = 1.63;
		het->Gto = 0.6;
	}
	else if (celltype == 106) { // AVN - compact node
		het->GCaL = 1.05;
		het->Gf = 4.4;
		het->GK1 = 0.44;
		het->GKur = 0.45;
		het->GNa = 0.25;
		het->fIRel = 0.32;
		het->BULK_CONST = 2.2;
		het->Gto = 0.4;
		het->GCaT = 17.62;
		het->If_grad = 1.03;

	}
	else if (celltype == 104) { // AVN - inferior nodal extension
		het->GCaL = 1.8;
		het->Gf = 2.2;
		het->GK1 = 0.42;
		het->GKur = 0.22;
		het->GNa = 1;
		het->BULK_CONST = 2.2;//1.2 * 0.48;
		het->GCaT = 6.5; //0.4;//0.
		het->Gto = 0.7;
		het->If_grad = 1.03;
	}

	else if (celltype == 105) { // AVN - Penetrating bundle
		het->Gto = 0.4;
		het->GCaL = 1.5;
		het->GCaT = 5.47;
		het->Gf = 1;
		het->GK1 = 0.96;
		het->GKur = 0.41;
		het->GNa = 0.6;
		het->fIRel = 0.82;
	}
	else if (celltype == 102 || celltype == 103) { // AVN - transitional area
		het->GCaL = 1.15;
		het->Gf =  1.04;
		het->GK1 = 0.48;
		het->GKur = 0.52;
		het->GNa = 0.66;
		het->fIRel = 0.89;
		het->BULK_CONST = 1.15;
		het->Gto = 0.38;
		het->GCaT = 3.5;
	}
	else if (celltype == 101) { // PV
		het->GKr = 1.5 * 1.6; // New PV model
		het->Gto = 0.75;//*0.53;
		het->GKs = 1.5;//*1.8;
		het->GK1 = 0.62;
		het->GCaL = 0.7;

	} else {

		std::cerr << "---------------fatal error--------------" << std::endl;
		std::cerr << " wrong cell type!" << std::endl;
		std::exit(0);
	}

	// ISO/ACh/AF remodelling scaling factors apply to all
	//ISO
	/*het->GCaL = (1 + (fICaL * 2)) * het->GCaL;
	het->GKur = (1 + (fIKur * 0.6)) * het->GKur;
	het->GKs = (1 + (fIKs * 1.5)) * het->GKs;
	het->BULK_CONST = (het->BULK_CONST + (fPLB * 0.1));
	//het->GNa = (1 - (fINa*0.5)) *het->GNa;
	het->ICaL_inac_shift = het->ICaL_inac_shift  + (fICaL * 5);
	het->ICaL_ac_shift = het->ICaL_ac_shift + (fICaL * 5) ;
	het->If_vshift = het->If_vshift + (fIf * -7);
	*/
	//ACH If v shift
	//het->If_vshift ;//= het->If_vshift + (-7.2 * ( (pow(Ach, 0.69)) / ( pow(1.26E-8 , 0.69 ) + (pow(Ach, 0.69)  ) ) ));

}


void AtriaMutationParameters(AtriaParameter * het, IKurMuationType mutation) {


	if (mutation != WT) {
		if (mutation == D322H) {
			het->IKur_ac1_mult   = 1.0;
			het->IKur_ac1_shift  = -9.3932825747999988;
			het->IKur_ac1_grad   = 1.3785501205210822;
			het->IKur_ac2_mult   = 1.0;
			het->IKur_ac2_shift  = 15.229362644299998;
			het->IKur_ac2_grad   = 0.25822502847411422;
			het->IKur_ac_add     = 0.0;
			het->IKur_inac_mult  = 0.87254304449870279;
			het->IKur_inac_shift = -9.6150807654200001;
			het->IKur_inac_grad  = 0.80075124328979652;
			het->IKur_inac_add   = 0.073931087206000057;

			het->GKur = het->GKur * 1.720232;
			het->Simple_Ikur_ac_shift += -3.2641;
			het->Simple_Ikur_ac_grad *= 0.8;
			het->Simple_Ikur_inac_shift += 9.61;
			het->Simple_Ikur_inac_grad *= 0.8;
			het->Simple_GKur *= 1.7995;

		}
		else if (mutation == E48G) {
			het->IKur_ac1_mult   = 1.0;
			het->IKur_ac1_shift  =  -8.914978286109998;
			het->IKur_ac1_grad   = 1.687979145508135 ;
			het->IKur_ac2_mult   = 1.0;
			het->IKur_ac2_shift  = 14.395569738899999;
			het->IKur_ac2_grad   = 0.312429308790384;
			het->IKur_ac_add     = 0.0;
			het->IKur_inac_mult  = 0.935206196986113;
			het->IKur_inac_shift = -4.02829;
			het->IKur_inac_grad  = 0.940280253452448;
			het->IKur_inac_add   = 0.039197146604;

			het->GKur = het->GKur * 1.286906;
			het->Simple_Ikur_ac_shift += -3.02;
			het->Simple_Ikur_ac_grad *= 0.95;
			het->Simple_Ikur_inac_shift += 4.02;
			het->Simple_Ikur_inac_grad *= 0.94;
			het->Simple_GKur *= 1.32;
		}
		else if (mutation == A305T) {
			het->IKur_ac1_mult   = 1.0;
			het->IKur_ac1_shift  = -5.135031219399998 ;
			het->IKur_ac1_grad   = 2.40452882662690 ;
			het->IKur_ac2_mult   = 1.0;
			het->IKur_ac2_shift  = 13.643107896399998;
			het->IKur_ac2_grad   = 0.387170393885174;
			het->IKur_ac_add     = 0.0;
			het->IKur_inac_mult  = 0.874602534570044;
			het->IKur_inac_shift = -6.032311251379999;
			het->IKur_inac_grad  = 0.748490912918043;
			het->IKur_inac_add   = 0.070656047487;

			het->GKur = het->GKur * 1.388228;
			het->Simple_Ikur_ac_shift += -4.068;
			het->Simple_Ikur_ac_grad *= 1.102;
			het->Simple_Ikur_inac_shift += 6.03;
			het->Simple_Ikur_inac_grad *= 0.74;
			het->Simple_GKur *= 1.445;
		}
		else if (mutation == Y155C) {
			het->IKur_ac1_mult   = 1.0;
			het->IKur_ac1_shift  = -4.430626802899999 ;
			het->IKur_ac1_grad   = 1.651529981648123 ;
			het->IKur_ac2_mult   = 1.0;
			het->IKur_ac2_shift  = 3.3770968185;
			het->IKur_ac2_grad   =  0.517356087786261;
			het->IKur_ac_add     = 0.0;
			het->IKur_inac_mult  = 0.936476668495346;
			het->IKur_inac_shift = -5.012779270500001;
			het->IKur_inac_grad  = 0.781775743434569;
			het->IKur_inac_add   = 0.034583585385;

			het->GKur = het->GKur *  0.461283;
			het->Simple_Ikur_ac_shift += -.89;
			het->Simple_Ikur_ac_grad *= 0.75;
			het->Simple_Ikur_inac_shift += 5.01;
			het->Simple_Ikur_inac_grad *= 0.78;
			het->Simple_GKur *= 0.4745;

		}
		else if (mutation == D469E) {
			het->IKur_inac_mult  =  1.174004519012284;
			het->IKur_inac_shift = -4.5454272743;
			het->IKur_inac_grad  = 0.842432589996777;
			het->IKur_inac_add   = -0.09291551303;

			het->GKur = het->GKur * 0.563448;

			het->Simple_Ikur_inac_shift += 4.5455;
			het->Simple_Ikur_inac_grad *= 0.84;
			het->Simple_GKur *= 0.5457;

		}
		else if (mutation == P488S) {

			het->IKur_inac_mult  =  1.212942827258507;
			het->IKur_inac_shift = 1.4151025432;
			het->IKur_inac_grad  = 0.687940393974062;
			het->IKur_inac_add   = -0.110508855073;
			het->GKur = het->GKur * 0.038593;
			het->Simple_Ikur_ac_grad *= 0.83;
			het->Simple_Ikur_inac_shift += -1.4251;
			het->Simple_Ikur_inac_grad *= 0.68;
			het->Simple_GKur *= 0.0384;

		}
		else {
			std::cerr << ("Invalid IKur mutation\n");
			std::exit(0);
		}
	} // IKur mutation stuffs
}


void Atria_AF_Parameters(AtriaParameter *het, int AFtype, int celltype) {
	if (celltype != 10) {
		// AF remodelling
		if (AFtype == 1) { // Bosch
			het->GCaL = 0.3 * het->GCaL;
			het->Gto = 0.3 * het->Gto;
			het->GK1 = 2 * het->GK1;
			het->ICaL_tau_rate = 1.62 * het->ICaL_tau_rate;
		}
		else if (AFtype == 2) { // Workman
			het->GCaL = 0.35 * het->GCaL;
			het->Gto = 0.35 * het->Gto;
			het->GK1 = 1.75 * het->GK1;
		}
		else if (AFtype == 3) { // Wagoner
			het->GCaL = 0.37 * het->GCaL;
			het->Gto = 0.34 * het->Gto;
			het->GKur = 0.51 * het->GKur;
			het->GK1 = 2.06 * het->GK1;
		}
		else if (AFtype == 4) { // Global
			het->GCaL = 0.3 * het->GCaL;
			het->Gto = 0.35 * het->Gto;
			het->GK1 = 2 * het->GK1;
			// in AFtype-4 IKur paper, modifications of AFtype-4 to IKur was not included; 12/03/2014
			// het->GKur =0.5*het->GKur;
			het->GNaCa = 1.55 * het->GNaCa;
			het->BULK_CONST = 1.5; // Increase according to shanmugam et al, AF_SR_updatke
			het->GSR_leak = 1.25;
			het->fIRel = 3 * het->fIRel;
			het->GKs = 2 * het->GKs;
			het->RyR = 2.5;
		}
	} // end AF remodelling tissue = 10 if
}


void ISO_parameters(double ISO, AtriaParameter *het) {


	double    fICaL = 1 / ( 1 + exp((-4.362 * (log(ISO) + 3.27)) ) );
	double    fRyR = 1 / ( 1 + exp((-2.55 * (log(ISO) + 1.2)) ) );
	double    fIKs = 1 / ( 1 + exp((-4 * (log(ISO) + 1.4)) ) );
	double    fIKur = 1 / ( 1 + exp((-1.8 * (log(ISO) + 2.2)) ) );
	double    fINa = 1 / ( 1 + exp((-2.55 * (log(ISO) + 2.5)) ) );
	double    fPLB = 1 / ( 1 + exp((-3 * (log(ISO) + 2.2)) ) );

	het->GCaL = (1 + (fICaL * 2)) * het->GCaL;
	het->GKur = (1 + (fIKur * 0.6)) * het->GKur;
	het->GKs = (1 + (fIKs * 1.5)) * het->GKs;
	het->BULK_CONST = (het->BULK_CONST + (fPLB * 0.1));
	het->GNa = (1 + (fINa * 0.25)) * het->GNa;
}
