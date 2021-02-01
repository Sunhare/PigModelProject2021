
#ifndef _pig_ecc_biophysJ2021_H_
#define _pig_ecc_biophysJ2021_H_

#include <cmath>
#include "cell.h"
#include "cvode_solver.hpp"

int pig_ecc_biophysJ2021(realtype t, N_Vector Y, N_Vector YDOT, void *user_data);


#endif