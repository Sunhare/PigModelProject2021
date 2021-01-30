/*
 * fk4v_params_struct.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Friday, May 16, 2008 @ 11:12
 * Modified: Thursday, May 22, 2008 @ 22:17
 *
 */

#include "fk4v_params.h"

/*
struct fk4v_params {
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
*/

// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated.
fk4v_params * new_fk4v_params(void) {
   fk4v_params *fkp;
   // fkp = malloc(sizeof(fk4v_params));
   fkp = new fk4v_params();
   if (!fkp) {
    perror("fk4v_params allocation");
    exit(EXIT_FAILURE);
   }

   return fkp;
}


// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The struct's params will be assigned default
// (in this case, EPI) cell parameters;
fk4v_params * default_fk4v_params(void) {
    fk4v_params *fkp;

    fkp = new_fk4v_params();

    // now assifgn everything!
    fkp->u_0 = 0.0;
    fkp->u_u = 1.55;
    fkp->u_m = 0.3;
    fkp->u_p = 0.13;
    fkp->u_q = 0.006;
    fkp->u_r = 0.006;
    fkp->tv1m = 60;
    fkp->tv2m = 1150;
    fkp->tvp = 1.4506;
    fkp->tw1m = 60;
    fkp->tw2m = 15;
    fkp->kwm = 65;
    fkp->uwm = 0.03;
    fkp->twp = 200;
    fkp->t_fi = 0.11;
    fkp->t_o1 = 400;
    fkp->t_o2 = 6;
    fkp->t_so1 = 30.0181;
    fkp->t_so2 = 0.9957;
    fkp->k_so = 2.0458;
    fkp->u_so = 0.65;
    fkp->t_s1 = 2.7342;
    fkp->t_s2 = 16;
    fkp->k_s = 2.0994;
    fkp->u_s = 0.9087;
    fkp->t_si = 1.8875;
    fkp->t_wi = 0.07;
    fkp->ws_inf = 0.94;

    return fkp;
}


// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The struct's params will be assigned CRN
// duplicating parameters
fk4v_params * crn_fk4v_params(void) {
    fk4v_params *fkp;

    fkp = new_fk4v_params();

    // now assifgn everything!
    fkp->u_0 = 0.0;
    fkp->u_u = 1.02;
    fkp->u_m = 0.302; // or sigma_v
    fkp->u_p = 0.33; // or sigma w
    fkp->u_q = 0.172; // or sigma v minus
    fkp->u_r = 0.06; // or sigma o
    fkp->tv1m = 65.6;
    fkp->tv2m = 1150;
    fkp->tvp = 0.95;
    fkp->tw1m = 170.8;
    fkp->tw2m = 112.4;
    fkp->kwm = 135;
    fkp->uwm = 0.0744;
    fkp->twp = 217;
    fkp->t_fi = 0.0678;
    fkp->t_o1 = 100;
    fkp->t_o2 = 64.87;
    fkp->t_so1 = 53.54;
    fkp->t_so2 = 8.03;
    fkp->k_so = 1.748;
    fkp->u_so = 0.644;
    fkp->t_s1 = 5.406;
    fkp->t_s2 = 52.91;
    fkp->k_s = 1.008;
    fkp->u_s = 0.814;
    fkp->t_si = 6.978;
    fkp->t_wi = 4.97;
    fkp->ws_inf = 1.0;

    return fkp;
}

// allocates memory for a new fk4v_params struct and returns a pointer to it, or
// null if it cannot be allocated. The struct's params will be assigned the
// values of the array passed in!
fk4v_params * array_fk4v_params(double *a) {
    fk4v_params *fkp;

    fkp = new_fk4v_params();

    // now assifgn everything!
    fkp->u_0 = a[0];
    fkp->u_u = a[1];
    fkp->u_m = a[2];
    fkp->u_p = a[3];
    fkp->u_q = a[4];
    fkp->u_r = a[5];
    fkp->tv1m = a[6];
    fkp->tv2m = a[7];
    fkp->tvp = a[8];
    fkp->tw1m = a[9];
    fkp->tw2m = a[10];
    fkp->kwm = a[11];
    fkp->uwm = a[12];
    fkp->twp = a[13];
    fkp->t_fi = a[14];
    fkp->t_o1 = a[15];
    fkp->t_o2 = a[16];
    fkp->t_so1 = a[17];
    fkp->t_so2 = a[18];
    fkp->k_so = a[19];
    fkp->u_so = a[20];
    fkp->t_s1 = a[21];
    fkp->t_s2 = a[22];
    fkp->k_s = a[23];
    fkp->u_s = a[24];
    fkp->t_si = a[25];
    fkp->t_wi = a[26];
    fkp->ws_inf = a[27];

    return fkp;
}

// prints information on the params to the indicated file
void fprintf_fk4v_params(FILE * file, fk4v_params * fkp) {
    fprintf(file, "fk4v_params:\n");
    fprintf(file, "  u_0:\t\t%g\n", fkp->u_0);
    fprintf(file, "  u_u:\t\t%g\n", fkp->u_u);
    fprintf(file, "  u_m:\t\t%g\n", fkp->u_m);
    fprintf(file, "  u_p:\t\t%g\n", fkp->u_p);
    fprintf(file, "  u_q:\t\t%g\n", fkp->u_q);
    fprintf(file, "  u_r:\t\t%g\n", fkp->u_r);
    fprintf(file, "  tv1m:\t\t%g\n", fkp->tv1m);
    fprintf(file, "  tv2m:\t\t%g\n", fkp->tv2m);
    fprintf(file, "  tvp:\t\t%g\n", fkp->tvp);
    fprintf(file, "  tw1m:\t\t%g\n", fkp->tw1m);
    fprintf(file, "  tw2m:\t\t%g\n", fkp->tw2m);
    fprintf(file, "  kwm:\t\t%g\n", fkp->kwm);
    fprintf(file, "  uwm:\t\t%g\n", fkp->uwm);
    fprintf(file, "  twp:\t\t%g\n", fkp->twp);
    fprintf(file, "  t_fi:\t\t%g\n", fkp->t_fi);
    fprintf(file, "  t_o1:\t\t%g\n", fkp->t_o1);
    fprintf(file, "  t_o2:\t\t%g\n", fkp->t_o2);
    fprintf(file, "  t_so1:\t\t%g\n", fkp->t_so1);
    fprintf(file, "  t_so2:\t\t%g\n", fkp->t_so2);
    fprintf(file, "  k_so:\t\t%g\n", fkp->k_so);
    fprintf(file, "  u_so:\t\t%g\n", fkp->u_so);
    fprintf(file, "  t_s1:\t\t%g\n", fkp->t_s1);
    fprintf(file, "  t_s2:\t\t%g\n", fkp->t_s2);
    fprintf(file, "  k_s:\t\t%g\n", fkp->k_s);
    fprintf(file, "  u_s:\t\t%g\n", fkp->u_s);
    fprintf(file, "  t_si:\t\t%g\n", fkp->t_si);
    fprintf(file, "  t_wi:\t\t%g\n", fkp->t_wi);
    fprintf(file, "  ws_inf:\t\t%g\n", fkp->ws_inf);

}

// prints information on the params to stdout.
void printf_fk4v_params(fk4v_params * fkp) {
    fprintf_fk4v_params(stdout, fkp);
}

// frees the associated memory.
void destroy_fk4v_params(fk4v_params * fkp) {
    if (fkp)
        free(fkp);
}

