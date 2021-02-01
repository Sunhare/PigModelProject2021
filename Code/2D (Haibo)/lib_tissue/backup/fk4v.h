/*
 * fk4v.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Tuesday, May 13, 2008 @ 09:42
 * Modified: Friday, May 16, 2008 @ 11:46
 *
 */

#ifndef FK4V_H
#define FK4V_H

#include <math.h>
#include "fk4v_params.h"

double fk4v(double dt, double stim, fk4v_params * fkp, double * state);
// integrates one timestep of the fenton karma four variable model,
// takes the timestep and the current state, the current stimulus 
// strengh and a params struct.
// returns the current du

#endif /* FK4V_H */

