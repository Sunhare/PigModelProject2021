
#ifndef TENT_VENT_H
#define TENT_VENT_H
#include "EnumSimulationCtrl.hpp"

/* constants */
// constants for Tent ventricle model
#ifndef TENT_VENT_CONSTANTS
#define TENT_VENT_CONSTANTS
static const double Tent_R = 8314.472;
static const double Tent_F = 96485.3415;
static const double Tent_T = 310.0;
static const double Tent_Ko = 5.4;
static const double Tent_Cao = 2.0;
static const double Tent_Nao = 140.0;
static const double Tent_Vc = 0.016404;
static const double Tent_Vsr = 0.001094;
static const double Tent_Vss = 0.00005468;
static const double Tent_Bufc = 0.2;
static const double Tent_Kbufc = 0.001;
static const double Tent_Bufsr = 10.;
static const double Tent_Kbufsr = 0.3;
static const double Tent_Bufss = 0.4;
static const double Tent_Kbufss = 0.00025;
static const double Tent_Vmaxup = 0.006375;
static const double Tent_Kup = 0.00025;
static const double Tent_Vrel = 0.102;
static const double Tent_k1_ = 0.15;
static const double Tent_k2_ = 0.045;
static const double Tent_k3 = 0.060;
static const double Tent_k4 = 0.005;
static const double Tent_EC = 1.5;
static const double Tent_maxsr = 2.5;
static const double Tent_minsr = 1.;
static const double Tent_Vleak = 0.00036;
static const double Tent_Vxfer = 0.0038;
static const double Tent_CAPACITANCE = 0.185;
static const double Tent_pKNa  = 0.03;
static const double Tent_GbNa  = 0.00029;
static const double Tent_KmK   = 1.0;
static const double Tent_KmNa  = 40.0;
static const double Tent_knak  = 2.724;
static const double Tent_GCaL  = 0.00003980;
static const double Tent_GbCa  = 0.000592;
static const double Tent_knaca = 1000;
static const double Tent_KmNai = 87.5;
static const double Tent_KmCa  = 1.38;
static const double Tent_ksat  = 0.1;
static const double Tent_n     = 0.35;
static const double Tent_GpCa  = 0.1238;
static const double Tent_KpCa  = 0.0005;
static const double Tent_GpK   = 0.0146;
#endif

double TentVentByJohn(double dt, double Istim, double *state, float ZIndex, TypeCell cellTissue1);
void InitialseTentVentByJohn(double *state, TypeCell cellTissue1);



#endif 