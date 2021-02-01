/*
 * lookup_table.c
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 *
 */
#include "lookup_table.h"
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

// create/destroy functions
//
lookup_table_t* new_lookup_table(void) {
// allocates space for a new lookup table struct, though not the table itself.
    lookup_table_t *table;

    // table = malloc(sizeof(lookup_table_t));
    table = new lookup_table_t();
    if (!table) {
        perror("Lookup table struct allocation!");
        exit(EXIT_FAILURE);
    }

    // zero it
    table->min      = 0;
    table->max      = 0;
    table->steps    = 0;
    table->tables   = 0;
    table->table    = NULL;

    return table;
}

lookup_table_t* init_lookup_table(int min, int max, int steps, int tables) {
// allocates space for a lookup table, including the space for the table.
// min:     minimum voltage to tabulate
// max:     maximum voltage to tabulate
// steps:   steps between the voltages
// tables:  number of parameters to tabulate.
    lookup_table_t *table = new_lookup_table();

    table->min      = min;
    table->max      = max;
    table->steps    = steps;
    table->tables   = tables;

    // allocate space for tables
    // MALLOC(table->table, steps*tables*sizeof(double));
    table->table = new double [steps*tables];
    return table;
}

lookup_table_t* create_lookup_table(int min, int max, int steps, int tables,
        void *params, table_row_function f) {
// allocates space for a lookup table and then populates it with pre-computed
// values.
// The first four parameters are as in init_lookup_table
// params:  user defined params which will be passed into the table calculations
//          for each voltage
// f:       Function used to calculate the table row
    lookup_table_t *table = init_lookup_table(min, max, steps, tables);
    int i;
    double v;


    for (i = 0; i < steps; ++i) {
        v = i;

        // compute the voltage value for this row.
        v = ((v/steps)*(max - min)) + min;

        // compute this row
        // f(v, params, &table->table[(table->tables*i)]);
    }

    return table;
}

void destroy_lookup_table(lookup_table_t *table) {
// de-allocates space for a lookup table
    if (table) {
        if (table->table) {
            // free(table->table);
            delete [] table->table;
            table->table = NULL;
        }

        table->min      = 0;
        table->max      = 0;
        table->steps    = 0;
        table->tables   = 0;

        // free(table);
        delete table;
        table = NULL;
    }
}

// read functions
//
int get_table_index(lookup_table_t *t, double v) {
// calculates the index, given the table and the voltage
    return ((v - t->min)/(t->max - t->min))*t->steps;
}

double * get_table_row(lookup_table_t *table, double v) {
// returns a pointer to the table row that corresponds to the given voltage.
    return &table->table[get_table_index(table, v)*table->tables];
}

