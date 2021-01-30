/*
 * fk4v_params_struct.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Friday, May 16, 2008 @ 11:00
 * Modified: Thursday, May 22, 2008 @ 22:18
 *
 * A struct to define the parameters of the FK4V model, and several utility
 * functions for dealing with them, including allocation, printing and
 * destruction.
 */

#ifndef FK4V_PARAMS_STRUCT_H
#define FK4V_PARAMS_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

struct fk4v_parameters {
    double u_0;
    double u_u;
    double u_m;
    double u_p;
    double u_q;
    double u_r;
    double tv1m;
    double tv2m;
    double tvp;
    double tw1m;
    double tw2m;
    double kwm;
    double uwm;
    double twp;
    double t_fi;
    double t_o1;
    double t_o2;
    double t_so1;
    double t_so2;
    double k_so;
    double u_so;
    double t_s1;
    double t_s2;
    double k_s;
    double u_s;
    double t_si;
    double t_wi;
    double ws_inf;
};

typedef struct fk4v_parameters fk4v_params;

fk4v_params * new_fk4v_params(void);
// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated.

fk4v_params * default_fk4v_params(void);
// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The struct's params will be assigned default
// (in this case, EPI) cell parameters;

fk4v_params * crn_fk4v_params(void);
// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The structs params will be allocated to std
// CRN parameters.  (GS CINC 2008)

fk4v_params * array_fk4v_params(double *a);
// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The struct's params will be assigned the
// values of the array passed in!

void fprintf_fk4v_params(FILE * file, fk4v_params * fkp);
// prints information on the params to the indicated file

void printf_fk4v_params(fk4v_params * fkp);
// prints information on the params to stdout.

void destroy_fk4v_params(fk4v_params * fkp);
// frees the associated memory.



#endif /* FK4V_PARAMS_STRUCT_H */

