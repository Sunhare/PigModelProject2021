#ifndef CVODE_PCELL__HPP
#define CVODE_PCELL__HPP

#include "cvode_solver.hpp"

#include "pig_ecc_biophysJ2021.hpp"
typedef int  (*cvode_func) (realtype t, N_Vector y, N_Vector ydot, void *user_data);

class CVOde_Cell
{
public:
	PIG_ECC cell;
	cvode_solver cvode;// (NEQ, 0.2);
	cvode_func member_cvode_func;
	std::ofstream output_file;// output filename


	CVOde_Cell(
		int NEQ, 
		double t_step_max, 
		cvode_func ode_function,
       	bool output_data = false, 
       	int PIG_CELL_TYPE = CONTROL
       	)
		: cell(PIG_ECC(PIG_CELL_TYPE))
		, cvode(cvode_solver(NEQ, t_step_max))
		, member_cvode_func(ode_function)
	{
		initialise();

		if (output_data) {
			output_file.open("results.txt");                      // output filename
		}

	}
	~CVOde_Cell() {
		if (output_file.is_open()) {
			output_file.close();
		}
	}

	void initialise() {

		cvode.set_IC(cell.y);
		cell.V  = cell.y[38];  // assign Vm here
		cvode.initialise_mem(member_cvode_func);
		cvode.set_user_data(&cell);
	}

	void solve_single_time_step(double tout) {
		// CVode(cvode_mem, tout, y, &t, CV_NORMAL); // 1 time step solution.
		cvode.solve_single_step(tout);
	}

	void solve_single_time_step_vm_para(double tout, double dt) {
		// CVode(cvode_mem, tout, y, &t, CV_NORMAL); // 1 time step solution.
		cvode.solve_single_step(tout);
		cell.V += dt * cell.dV;
	}



	// void print_to_file() {
	// 	cell.print_to_file(cvode.t, output_file);
	// }

	void read_initial_condition(const char * filename) {
		cvode.destroy_cvode_mem();
		cell.read_initial_condition(filename);
		initialise();
	}



};



#endif