/*
 * crn_con.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Tuesday, October 02, 2007 @ 09:34
 * Modified: Wednesday, October 01, 2008 @ 13:53
 *
 * Header file for functions to solve the Courtemanche, Ramirez, Nattel model of
 * the human atrial myocyte in control conditions.
 *
 * The reason for the unique name is to allow different cells to be easily
 * included in constructed multicellular preparations, for example 2D atrial
 * models.
 *
 * Similar cells in this model should provide a header like this, and in
 * addition, should be placed into a file named cell_name.c, to allow the
 * Rakefile to easily pick the names up.
 *
 */


#ifndef CRN_CON_H
#define CRN_CON_H
#include "cell.h"
#include <stdlib.h>
#include "parameters.h"

void crn_con_initial_conditions_Atrial(double state[]);

void crn_con_initial_conditions_AVN(double state[]);
void crn_con_initial_conditions_Vent(double state[], int cellTissue);

double MIKE(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results, double ach_conc, int GKUR);
// This is the actual model, that is probably called once per timestep.
// cell_params is a struct, defined in cell_params.h.  It contains (in v1) the
// current timestep, and scaling factors for the 13 main currents. While a cell
// doesn't have to use them, it does allow tweaking easily.
// state is an array of doubles, and contains the current state of the model.
// results is an array of doubles that can be used to carry transitory data into
// and out of the cell.


double crn_con(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results);


float Iion_tot(double dt, double *state, float GNa, float Gto, float GKur, float GcaL, float GK1, float GKs, float GKr, float GcaT, float Gf, float Gab, float GNaCa, float Cm, int periph, double Gbna, double Gbca);

void crn_con_compute_table_row_v(double V, void *params, double *row, heterogeneous_params_t *het);
// computes a row of the lookup table for the given voltage and with the given
// cell params

char *crn_con_type(void);
// returns a short string describing the cell type. Used for output functions.

char *crn_con_model(void);
// returns a short string describing the cell model. Used for output functions.

void MIKE_initial_conditions(double state[], int celltype);

void crn_con_initial_conditions_SAN(double state[]);

// Sets up initial conditions for the cell, assigning them to the state array

void crn_con_initial_conditions_atrial(double state[]);

void crn_con_initial_conditions_CT(double state[]);

double Euler_inf(double dt, double gate, double inf, double tau);
double Foward_Euler(double dt, double dy, double y);

double crn_con_Vent_with_drug(double dt, double *state, int ZIndex, int cellTissue, double INa_Drug, double If_Drug, double IKr_Drug, double IKs_Drug, double ICaL_Drug, double INa_V50A, double If_V50A, double IKr_V50A, double IKs_V50A, double ICaL_V50A, double INa_V50I, double If_V50I, double IKr_V50I, double IKs_V50I, double ICaL_V50I, double INa_TauA, double If_TauA, double IKr_TauA, double IKs_TauA, double ICaL_TauA, double INa_TauI, double If_TauI, double IKr_TauI, double IKs_TauI, double ICaL_TauI);

int crn_con_length(void);
// Returns the length of the state array

double *crn_con_init(void);
// Allocates memory and initailises the model with default values.

double *crn_con_empty_state(void);
// Allocates sufficient memory for a single cell and returns a pointer to it,
// uninitialised.

void copy_crn_con_state(double *state1, double *state2);
// copies the state array from state1 to state2.

double crn_con_Vent(double dt, double *state, float ZIndex, unsigned char cellTissue1);
void FK_initial_conditions(double state[], int celltype);

double FK(cell_params *params, lookup_table_t *table, heterogeneous_params_t *het, double *state, double *results, double V);













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

#endif
//end inclusion guard
