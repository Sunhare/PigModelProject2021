/*
 * lookup_table.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 *
 */

#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H
#include "parameters.h"

// typedef for a pointer to the function to compute the lookup table for a given
// voltage.
// v:       voltage to compute values for
// params:  user defined params.
// row:     a pointer to the row of the table to be updated.
typedef void (*table_row_function)(double v, void* params, double* row, heterogeneous_params_t * het);

typedef struct {
    // minimum voltage
    int     min;

    // maximum voltage
    int     max;

    // number of steps between the two voltages
    int     steps;

    // number of tables this lookup table contains
    int     tables;

    // the tables themselves
    double  *table;

} lookup_table_t;

// create/destroy functions
//
lookup_table_t* new_lookup_table(void);
// allocates space for a new lookup table struct, though not the table itself.

lookup_table_t* init_lookup_table(int min, int max, int steps, int tables);
// allocates space for a lookup table, including the space for the table.
// min:     minimum voltage to tabulate
// max:     maximum voltage to tabulate
// steps:   steps between the voltages
// tables:  number of parameters to tabulate.

lookup_table_t* create_lookup_table(int min, int max, int steps, int tables,
        void *params, table_row_function f);
// allocates space for a lookup table and then populates it with pre-computed
// values.
// The first four parameters are as in init_lookup_table
// params:  user defined params which will be passed into the table calculations
//          for each voltage
// f:       Function used to calculate the table row

void destroy_lookup_table(lookup_table_t *table);
// de-allocates space for a lookup table


// read functions
//
int get_table_index(lookup_table_t *table, double v);
// calculates the index, given the table and the voltage

double * get_table_row(lookup_table_t *table, double v);
// returns a pointer to the table row that corresponds to the given voltage.

#endif /* LOOKUP_TABLE_H */

