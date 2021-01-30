/*
 * fk4v.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Tuesday, May 13, 2008 @ 09:48
 * Modified: Friday, May 23, 2008 @ 12:29
 *
 */

#include "fk4v.h"


// integrates one timestep of the fenton karma four variable model,
// takes the timestep and the current state, the current stimulus 
// strengh and a params struct.
// returns the current du
double fk4v(double dt, double stim, fk4v_params * fkp, double * state) {

    // temp variables
    double r, q, p, m, w_inf, v_inf, t_o, t_s, t_so, t_w_minus, t_v_minus,
           j_si, j_so, j_fi, ds, dw, dv, du;

    double u = state[0];
    double v = state[1];
    double w = state[2];
    double s = state[3];

    
    // gates
    r = (u < fkp->u_r) ? 0.0 : 1.0;
    q = (u < fkp->u_q) ? 0.0 : 1.0;
    p = (u < fkp->u_p) ? 0.0 : 1.0;
    m = (u < fkp->u_m) ? 0.0 : 1.0;

    // w_inf
    w_inf = (1-r)*(1 - u/fkp->t_wi) + r*fkp->ws_inf;

    // v_inf
    v_inf = 1 - q;

    // t_o
    t_o = ((1-r) * fkp->t_o1) + (r * fkp->t_o2);

    // t_s
    t_s = ((1-p) * fkp->t_s1) + (p * fkp->t_s2);

    // t_so
    t_so = fkp->t_so1 + (fkp->t_so2 - fkp->t_so1) * 
        (1 + tanh(fkp->k_so*(u - fkp->u_so)))*0.5;

    // t_w_minus
    t_w_minus = fkp->tw1m + 
        (fkp->tw2m - fkp->tw1m) * 
        (1 + tanh(fkp->kwm*(u - fkp->uwm)))*0.5;

    // t_v_minus
    t_v_minus = (1-q)*fkp->tv1m + q*fkp->tv2m;

    // currents
    // j_si
    j_si = - p * w * s / fkp->t_si;
    // j_si = 0.0;

    // j_so
    j_so = ((u - fkp->u_0) * (1 - p))/t_o + p/t_so;
    // j_so = 0.0;

    // j_fi
    j_fi = - v * m * (u - fkp->u_m) * (fkp->u_u - u) / fkp->t_fi;
    // j_fi = 0.0;

    // time derivatives
    // ds
    ds = (((1 + tanh(fkp->k_s * (u - fkp->u_s))) * 0.5) - s)/t_s;

    // dw 
    dw = (1 - p) * (w_inf - w)/t_w_minus - ((p * w)/fkp->twp);

    // dv
    dv = (1 - m) * (v_inf - v)/t_v_minus - ((m * v)/fkp->tvp);

    // du
    du = -(j_si + j_so + j_fi - stim);

//    state[0] += du*dt;
    state[1] += dv*dt;
    state[2] += dw*dt;
    state[3] += ds*dt;
    return du;

}


