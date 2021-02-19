#ifndef PCELL__HPP
#define PCELL__HPP

// #include "cvode_solver.hpp"

#include "pig_ecc_biophysJ2021.hpp"
// typedef int  (*cvode_func) (realtype t, N_Vector y, N_Vector ydot, void *user_data);

class PCell
{
public:
	PIG_ECC cell;
	std::ofstream output_file;// output filename
	const int NEQ;
	double dt;


	PCell(int NEQ, double dt, bool output_data = false, int PIG_CELL_TYPE = CONTROL)
		: cell(PIG_ECC(PIG_CELL_TYPE)), NEQ(NEQ)
	{
		initialise();
		dt = dt;

		if (output_data) {
			output_file.open("results.txt");                      // output filename
		}

	}
	~PCell() {
		if (output_file.is_open()) {
			output_file.close();
		}
	}

	void initialise() {
		cell.V  = cell.y[38];  // assign Vm here
	}

	
	void solve_ODEs(double dt){
		// #pragma omp parallel for
		for(int i=0; i<NEQ; i++){
			cell.y += cell.ydot*dt;
		}
		cell.V += cell.dV * dt;

	}

	void solve_single_time_step(double tout) {
		// CVode(cvode_mem, tout, y, &t, CV_NORMAL); // 1 time step solution.
		// cvode.solve_single_step(tout);
	}
	void solve_single_time_step_vm_para(double tout, double dt) {
		// CVode(cvode_mem, tout, y, &t, CV_NORMAL); // 1 time step solution.
		// cvode.solve_single_step(tout);
		cell.V += dt * cell.dV;
	}




};



#endif