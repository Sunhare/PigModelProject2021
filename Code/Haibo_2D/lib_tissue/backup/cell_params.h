/*
 * cell_params.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 *
 * Defines a struct to pass certain variables into the cell model. Currently
 * these variables are the timestep and various current magnitudes.
 *
 * This file also defines several functions to initialize and print the params
 * struct.
 */

#ifndef CELL_PARAMS_H
#define CELL_PARAMS_H
#include <stdio.h>

typedef struct  {
    int version;
    double dt;
    double ina;
	double  ito;
	double  ikur;
	double  ikr;
	double  iks;
	double  icaL;
	double  ik1;
	double  ibna;
	double  ibk;
	double  ibca;
	double  inak;
	double  icap;
	double  inaca;
} cell_params;

cell_params * init_cell_params(void);
// initialises the params hash with default values, making it suitable to pass
// into the cell.

int print_cell_params(cell_params *params);
// prints out the params hash that is passed in to std out.

int fprintf_cell_params(FILE * file, cell_params *params);
// prints the params to a given file pointer

void destroy_cell_params(cell_params *params);
// destroys a cell params pointer, freeing the associated memory

void copy_cell_params(cell_params *in, cell_params *out);
// copies the values in one cell params struct to the other.
// arguments:
//  in:  the params struct to copy values from
//  out: the params struct that will be a copy of in


// reading params from files

cell_params * read_cell_params(FILE * file);
// reads cell params from a file, returning a pointer to a newly allocated
// cell_params struct. Exits in case of failure.
// arguments:
//   file: The file to read from.
// returns:
//   The initialized params struct.

cell_params * read_cell_params_file(const char * filename);
// reads cell params from a file, returning a pointer to a newly allocated
// cell_params struct. Exits in case of failure.
// arguments:
//   filename: The filename to read from.
// returns:
//   The initialized params struct.

#endif /* CELL_PARAMS_H */

