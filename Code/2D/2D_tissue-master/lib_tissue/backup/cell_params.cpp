/*
 * cell_params.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 *
 * Implements a few helpful functions for dealing with the parameters struct
 * see the header for explanations of non-trivial functions.
 */
#include "cell_params.h"
#include <stdlib.h>
#include "util.h"

cell_params * init_cell_params() {
    cell_params * params;
    // MALLOC(params, sizeof(cell_params));
    params = new cell_params();
    params->version = 1;
    params->dt      = 0.005;
    params->ina     = 1.0;
    params->ito     = 1.0;
    params->ikur    = 1.0;
    params->ikr     = 1.0;
    params->iks     = 1.0;
    params->icaL    = 1.0;
    params->ik1     = 1.0;
    params->ibna    = 1.0;
    params->ibk     = 1.0;
    params->ibca    = 1.0;
    params->inak    = 1.0;
    params->icap    = 1.0;
    params->inaca    = 1.0;
    return params;
}

int fprintf_cell_params(FILE * file, cell_params *params) {
    fprintf(file,"dt: %g\n",params->dt);
    fprintf(file,"currents:\n");
    fprintf(file,"  ina: %g\n",params->ina);
    fprintf(file,"  ito: %g\n",params->ito);
    fprintf(file,"  ikur: %g\n",params->ikur);
    fprintf(file,"  ikr: %g\n",params->ikr);
    fprintf(file,"  iks: %g\n",params->iks);
    fprintf(file,"  icaL: %g\n",params->icaL);
    fprintf(file,"  ik1: %g\n",params->ik1);
    fprintf(file,"  ibca: %g\n",params->ibca);
    fprintf(file,"  ibk: %g\n",params->ibk);
    fprintf(file,"  ibca: %g\n",params->ibca);
    fprintf(file,"  inak: %g\n",params->inak);
    fprintf(file,"  icap: %g\n",params->icap);
    fprintf(file,"  inaca: %g\n",params->inaca);

    return 0;
}

int print_cell_params(cell_params *params) {
    return fprintf_cell_params(stdout,params);
}

void destroy_cell_params(cell_params *params) {
    if (NULL != params) {
        free(params);
    }
    params = NULL;
    return;
}


void copy_cell_params(cell_params *in, cell_params *out) {
// copies the values in one cell params struct to the other.
// arguments:
//  in:  the params struct to copy values from
//  out: the params struct that will be a copy of in
    if ((NULL == in)||(NULL == out)) {
        return;
    }

    out->version = in->version;
    out->dt = in->dt;
    out->ina = in->ina;
    out->ito = in->ito;
    out->ikur = in->ikur;
    out->ikr = in->ikr;
    out->iks = in->iks;
    out->icaL = in->icaL;
    out->ik1 = in->ik1;
    out->ibna = in->ibna;
    out->ibk = in->ibk;
    out->ibca = in->ibca;
    out->inak = in->inak;
    out->icap = in->icap;
    out->inaca = in->inaca;
}


