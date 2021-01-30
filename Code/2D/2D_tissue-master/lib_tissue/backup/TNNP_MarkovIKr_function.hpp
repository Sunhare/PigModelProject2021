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
#include "EnumSimulationCtrl.hpp"

#ifndef TNNP_MarkovIKr_function_HPP
#define TNNP_MarkovIKr_function_HPP
//===========
// Cell types
//===========
// enum TypeCell { LVEPI, LVM, LVENDO };

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

void TNNP_MarkovIKr_Initialise(double *state, TypeCell m_celltype);
double TNNP_MarkovIKr_ODE(double dt, double Istim, double *state, float ZIndex, TypeCell m_celltype);

#endif