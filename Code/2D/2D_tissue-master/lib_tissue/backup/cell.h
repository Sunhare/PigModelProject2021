/*
 * cell.h
 * Jonathan D. Stott <jonathan.stott@gmail.com>
 * Created: Monday, January 08, 2007 @ 11:21
 * Modified: Wednesday, October 01, 2008 @ 13:55
 *
 * Defines the various functions used to create cell models for the cardiac
 * simulator utility. There are two classes of function defined in this header.
 * The first four should be provided by any cellular code. The latter four are
 * provided by the statement '#include "shared.c"' in the relevent cell file.
 *
 * In addition to the four required functions, all cell codes should #define a
 * parameter called VECLENGTH, the length of the state array.
 *
 */


#ifndef CELL_H
#define CELL_H

#include <math.h>
#include "cell_params.h"
#include "lookup_table.h"

// defined models
#include "crn_con.h"

// end defined models

// typedef for a pointer to a single cell code.
typedef double (*pcell_fn)(cell_params*,lookup_table_t*,double*,double*);

#endif //end inclusion guard
