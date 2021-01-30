#ifndef CNZ_H
#define CNZ_H
#include <cstdlib>
#include <iostream>
// #include <cmath>
#include <math.h>

// #include "atrial_parameter.h"
#include "SingleCellParameter.hpp"

// #include "CNZ.tpp"
// template <class T>
double CNZ_ODE(double dt, double Istim, SingleCellPara & het, double *state) ;
// This is the actual model, that is probably called once per timestep.
// cell_params is a struct, defined in cell_params.h.  It contains (in v1) the
// current timestep, and scaling factors for the 13 main currents. While a cell
// doesn't have to use them, it does allow tweaking easily.
// state is an array of doubles, and contains the current state of the model.
// results is an array of doubles that can be used to carry transitory data into
// and out of the cell.
// double CNZ_ODE(double dt, double Istim, AtriaParameter *het, double *state) ;

void CNZ_ODE_Initialise(double *state, int celltype);
int cnz_con_length(void);
// Returns the length of the state array



#endif
