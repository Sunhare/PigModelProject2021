#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <ctime>
#include <vector>

#include "pig_ecc_biophysJ2021.hpp"
#include "CVOde_Cell.hpp"



int main(){

	// Cell cell(dt, NEQ, p);
	// // CVODE Solver
	// 	N_Vector y0n;
	// 	cvode_solver cvode(NEQ,1);
	// 	realtype tout;
	// 	tout = dt;
		
	// 	y0n = N_VNew_Serial(NEQ); // for solver		
		

	// 	Initialize_y_vec(y0n, NEQ, stateFileName);
	// 	cvode.set_IC(y0n);
	// 	cvode.initialise_mem(soltis_biophysJ2010_eccODEfile);	
	// 	cvode.set_user_data(&cell);	

	// CVOde_Cell **cell_vec = new CVOde_Cell* [top.local_cell_num];
	
	int NEQ = 73;
	CVOde_Cell single_cell(NEQ, 0.2, fnew_pig, false, CONTROL);
}

















