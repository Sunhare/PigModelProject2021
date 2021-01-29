
#ifndef CELL_ODE_H
#define CELL_ODE_H

#include <cmath>
#include "cell.h"
#include "cvode_solver.hpp"

int soltis_biophysJ2010_eccODEfile(realtype t, N_Vector Y, N_Vector YDOT, void *user_data);


#endif