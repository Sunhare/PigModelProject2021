/*
 * new_atrium_LAA_RAA.c
 * new atrium code with LAA and RAA included, geometry has no AVN, SAN modelled as SAN or CT
 *
 */
#include <memory>
#include <algorithm>
#include <vector>
#include <zlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "util.h"
// #include "conduction.h"
#include "tissue.h"
// #include "cell.h"
#include "stimulus.h"
#include "input_output.h"
#include <string.h>
#include "simulation_config.h"
#include <iomanip>
#include <exception>
#include <iostream>
#include <string>
// #include "Tent_Vent.h"
// #include "CNZ.h"
// #include "Updated_CNZ.h"

// #include "NCZ_ODE.h"

// #include "rudy.h"
// #include "EnumSimulationCtrl.hpp"

// #include "TNNP_MarkovIKr_SP.hpp"
// #include "TNNP_MarkovIKr_function.hpp"
// #include "TNNP_ISO.hpp"
// #include "TNNP_MarkovIKr.h"
#include "one_d_conduction.h"
#include "APInfo.hpp"
#include "topology.h"

// if we're compiling with openMP, include the file, else define some stub
#include <omp.h>
#include <mpi.h>



// #include "Spatial_Cell.h"



// functions
#ifdef _OPENMP
#include <omp.h>
#else
// #define omp_get_num_threads() (48)
// #define omp_get_thread_num() (0)
#endif
// #define NX (235)
// #define NY (269)
// #define NZ (298)

#define OUT_TO_TXT (1)
// #define BREAK_IF_CVM // break if CV measured values reach steady-state values.
// #define OUT_INICOND
/* define the num of neighboorhood ( related to the model dimension */
// #define CV_COM (1)
#define NUM_NBH (3)
#define DIFF_COEF (0.15*1.525*0.63*1.45)  // wild type, CV = 0.752688


/* Downsampled IS ventricle dimension */
#define NX (31) // 200 cells in a single strand
#define NY (325)
#define NZ (358)
// #define DIFF_COEF (0)
#define FIRST_ACT (1)
#define SECOND_ACT (NX-1)


// #define PROFILE_TIME
/*#define NX (100)
#define NY (100)
#define NZ (100)*/


// #define D2 (0.21)
// #define DD (8*0.21)
/* to be determined later */
/* The diffusion parameter */
#define D2 (0.18/10.0)
#define DD (0.18)

// typedef TTCell TNNP_MarkovIKr;

#define STATE_LEN (40)//cnz_con_length())  /* the state length of Tent model is 21,crn_con_length() = 39*/




double u_exact(double x, double t) {
	double L = 1.5;
	return x * (L - x) * 5 * t; //  # fulfills BC at x=0 and x=L
}

double I(double x) {
	return u_exact(x, 0);
}

double f(double x, double t, double a) {
	double L = 1.5;
	return 5 * x * (L - x) + 10 * a * t; //
}







int main (int argc, char **argv) {

	// omp_set_num_threads(4);
	// MPI stuff
	int numprocs, rank, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int iam = 0, np = 1;
	int provided = 1;

	MPI_Init_thread(&argc, &argv, MPI_THREAD_SINGLE, &provided);
	// MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(processor_name, &namelen);

	// omp_set_dynamic(1);
	// counters
	int i, count = 0, c;

	// tissue variables
	// unsigned char           *** atrium;
	unsigned char            *tissue;

	// propagation variables
	double a = 3.5;
	double L = 1.5;
	double Nx = 30;
	double F = 0.6;
	// double # Compute dt from Nx and F
	double dx = L / Nx;
	double dt = F / a * dx * dx;
	// const double dt      = 0.1;  // large Dt here, addpative dt for single cell computations.
	// const double            dx = 0.30;
	int                      *nbd;
	int                      **neighbourhood;
	double                   *lap;
	double                   **laplacian;
	double                   *v_new;
	double                   *v_old;


	double 					 *RK_K1;
	double 					 *RK_K2;
	double 					 *RK_K3;
	double 					 *RK_K4;
	double 					 *v_temp;
	double 					 *v_temp_2;
	double *v_global;
	double *v_global_temp_1;
	double *v_global_temp_2;
	double *Cai_out;

	const int S1_number = 10;

	// time variables
	double  t_max        = 2000.0;
	double  t;

	Simulation_Config Config_para(argc, argv);
	Config_para.dt = dt;
	if (rank == 0)

		Config_para.Report_Config();
	// #ifdef OUT_INICOND
	// 	const double t_start = 0.0;//(Config_para.S1_number-1)*Config_para.BCL - 10;
	// #else
	// 	const double t_start = - 10 + dt;//(Config_para.S1_number - 1) * Config_para.BCL - 10 + dt;
	// #endif
	// cell stuff
	double *state;

	int conduction = 1;
	// std::vector<TNNP_MarkovIKr> cell_vec;

	// stim stuff
	const double stim   = 20.0;
	char         *san   = NULL;
	char         *sanin = NULL;
	float        *stims = NULL;
	gzFile       gz     = NULL;
	int          iStim  = 0;

	// output variables
	int       outcount  = 0;
	int       filecount = 0;
	int       outindex  = 0;
	float     *v_out;

	float *Fcell;
	FILE *in;
	int *FB_number;
	int FB_type;

	float ISO, ACH;
	int AF;

	int BCL, S2;
	double stimint;
	int intBCL, intstim, stimcount, timeint, durationint;
	double stimduration;

	double Dscale    = 1.0;

	double Ggap;

	int IKur_switch  = 0;

	// #ifdef _OPENMP
	double start     = omp_get_wtime();
	double end       = 0;
	double end_setup = 0;
	// #endif
	float *Stim_amp, * Stim_time, *Stim_amp_S2;

	std::vector<int> AP_Number(NX);
	// Dealing with Config_paraments etc
	// Default values

	// Config_para.Total_time = (Config_para.S1_number) * Config_para.BCL + Config_para.S2 * 2 + 100.0;
	std::vector<double> PrePotential(NX);
	std::vector<double> TemPotential(NX);
	std::vector<double> ActTime(NX);
	ISO     = ACH = AF = 0;
	BCL     = 1000;
	S2      = 0;
	FB_type = 0;
	Ggap    = 3.0;
	double timeelasped;
	// SingleCellPara *cell_para;

	std::ofstream cv_out_file("cv_out_file.dat", std::ios::out);
	// std::vector<TypeCell> cell_type_vec;
	std::vector<double> cv; // for recording cv
	// std::vector<std::shared_ptr<APInfor> > APInfor_vec;

	for (auto& x : Config_para.Popul_scalingF)
		std::cout << x << ' ';


	std::setprecision(10);
	// assign scaling factors to conductances.

	tissue = new unsigned char [NX];
	for (int id = 0; id < NX; id++) {
		tissue[id] = 14;
	}
	c = NX;

	const int total_cell_num = c;

	std::cerr << ">>Succesfully read in Geometry and Fibre Files<<\n";
	std::cerr << ">>Total Number of Cells: " << c << " <<\n";
	laplacian = generate_one_D_laplacian_test(NX, tissue, a, dx);
	neighbourhood = generate_one_D_neighboors(NX);

	std::ofstream OneD_output;
	std::ofstream OneD_output_Cai;
	std::string filename = "OneD_output.dat." + std::to_string(rank);
	std::string filename2 = "OneD_output_Cai.dat." + std::to_string(rank);
	// OneD_output = fopen("OneD_output.dat", "wt");
	OneD_output.open(filename.c_str());
	OneD_output_Cai.open(filename2.c_str());
	//output_matrix(laplacian, c, 19);


	nbd = new int [c * NUM_NBH];
	lap = new double [c * NUM_NBH];


	for (int n = 0; n < c; n++) {
		for (int i = 0; i < NUM_NBH; i++) {
			nbd[(n * NUM_NBH) + i] = neighbourhood[n][i];
			lap[(n * NUM_NBH) + i] = laplacian[n][i];
		}
	}


	deallocate_and_zero_2d_matrix(neighbourhood, c, NUM_NBH);
	deallocate_and_zero_2d_matrix(laplacian, c, NUM_NBH);


	int local_cell_num = c / numprocs;

	// if (c % numprocs)
	if (rank < c % numprocs) {
		local_cell_num = local_cell_num + 1;
	}



	printf("Hybrid: Hello from thread from process %d out of %d on %s, cell num is %d\n",
	       rank, numprocs, processor_name, local_cell_num);

	int local_cell_num_vec [numprocs];
	int offset_cell_num_vec [numprocs];

	for (int i = 0; i < numprocs; ++i)
	{
		local_cell_num_vec[i] = c / numprocs;
		if (i < c % numprocs) {
			local_cell_num_vec[i] ++ ;
		}
	}


	int starting_index = 0;
	offset_cell_num_vec[0] = 0;


	for (int i = 0; i < numprocs; ++i)
	{
		if (i < rank) {
			starting_index += local_cell_num_vec[i];

		}
	}

	for (int i = 1; i < numprocs; ++i)
	{
		offset_cell_num_vec[i] = offset_cell_num_vec[i - 1] + local_cell_num_vec[i - 1];
	}

	// if (rank == 0)
	// 	for (int i = 0; i < numprocs; ++i)
	// 	{
	// 		printf("***********cell %d, offset %d \n",
	// 		       local_cell_num_vec[i], offset_cell_num_vec[i]);
	// 	}

	// printf("Hybrid: Hello from thread from process %d out of %d on %s, cell num is %d, starting at %d\n",
	//        rank, numprocs, processor_name, local_cell_num, starting_index);
	double t_first_act, t_second_act;


	Topology top(MPI_COMM_WORLD, c);
	top.setup_dependecies(nbd, NUM_NBH);




	{


		// create local copies of the neighbourhood and laplacian.
		const int count = top.local_cell_num;

		std::string tubular_structure_file = "tub_input_ver2_4.txt";

		// MALLOC(v_out, count * sizeof(float));
		v_out = new float [count];

		Cai_out = new double [count];
		// dv    = new double [count];
		// MALLOC(dv, count * sizeof(double));


		// allocate voltage arrays


		Stim_time = new float [total_cell_num];
		Stim_amp  = new float [total_cell_num];
		Stim_amp_S2 = new float[total_cell_num];


		v_global = new double [ total_cell_num];
		v_global_temp_1 = new double [ total_cell_num];
		v_global_temp_2 = new double [ total_cell_num];

		state = new double [ STATE_LEN * count];
		// het       = new heterogeneous_params_t [count];
		v_new     = new double [count];
		v_old     = new double [count];

		v_temp = new double [count];
		v_temp_2 = new double [count];
		RK_K1 = new double [count];
		RK_K2 = new double [count];
		RK_K3 = new double [count];
		RK_K4 = new double [count];
		san       = new  char [count];
		FB_number = new int [count];
		Fcell     = new float [count];


		// assign voltages
		#pragma omp parallel for schedule(static)
		for (int n = 0; n < count; n++) {
			// Regionalparameters(&cell_para[n], 1e-15, 1e-15, tissue[n]);


			// cell_type_vec.push_back(celltype);
			// TNNP_MarkovIKr_Initialise(&(state[n * STATE_LEN]), celltype);
			// InitialseTentVentByJohn(&(state[n * STATE_LEN]), celltype);
			// v_new[n] = v_old[n] = state[n * STATE_LEN];
			v_new[n] = v_old[n] = u_exact(n * dx, 0);

		}

		// v_new[count-1] = v_old[count-1] = 1;

		// #ifdef _OPENMP
		#pragma omp master
		{
			end_setup = omp_get_wtime();
			// fprintf(stderr, "Setup time:   %6g\n", end_setup - start);
			std::cerr << "Setup time:  " << end_setup - start << std::endl;
		}
		// #endif
		// #pragma omp barrier
		#pragma omp master
		{
			// fprintf(stderr, ">>Assigned regional and modulation parameters<<\n>>Starting time loop now<<\n");
			std::cerr << ">>Assigned regional and modulation parameters<<\n>>Starting time loop now<<" << std::endl;
		}
		#pragma omp barrier

		double output_time = 0.0;
		timeelasped = omp_get_wtime();
		int Thread_ID = omp_get_thread_num();
		int threadnum = omp_get_thread_num();
		int    numthreads = omp_get_num_threads();
		int low = count * threadnum / numthreads;
		int    high = count * (threadnum + 1) / numthreads;

		int outcounter = 0;
		// loop over time.
		for (double t = 0; t < Config_para.Total_time; t += dt) {




#ifdef OUT_TO_TXT
			#pragma omp single
			{
				// if (t > Config_para.Total_time - 2 * Config_para.BCL - 10)
				if (outcounter % 10 == 0)
				{

					if (rank == 0)
						std::cerr << "in time loop now, t = " << t << " <<" << std::endl;
					OutPutArrayToTxt(OneD_output, v_new, count);
				}



			}

			outcounter++;
#endif



#ifdef PROFILE_TIME
			#pragma omp single
			{
				std::cerr << "Setup time:  " <<  omp_get_wtime() - end_setup << std::endl;
				timeelasped = omp_get_wtime();
			}
#endif

			/*operator spliting part 1*/

			/*RK4 method*/
			/* using RK4 here*/
			#pragma omp barrier
			// MPI_Barrier( MPI_COMM_WORLD ); // add a barier here to ensure Synchronization

// 			#pragma omp master
// 			{

// 				MPI_Barrier(MPI_COMM_WORLD);
// 			}


// 			// v_global
// 			#pragma omp master
// 			{
// 				// int error = MPI_Allgatherv(v_old, count,
// 				//                            MPI_DOUBLE, v_global, local_cell_num_vec,
// 				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);


// 				top.set_ghost_cells(v_old, v_global);
// 			}
// 			#pragma omp barrier




// 			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
// 			for (int n = 1; n < count-1; n++) {

// 				v_new[n] = v_old[n];  // keep a copy of v_old[n], which is y_i;
// 				//dv[n] = 0.0;
// 				double sum = 0.0;
// 				int ii = 0;

// 				// #pragma omp simd reduction // not available on icpc 12.0
// 				for (ii = 0; ii < NUM_NBH; ii++) {
// 					sum +=  (lap[((n + starting_index) * NUM_NBH) + ii] * v_global[nbd[((n + starting_index) * NUM_NBH) + ii]]); // this is f(t, y_i)
// 				}
// 				// dv[n] = sum;
// 				//y_bar_i+1
// 				RK_K1[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
// 				v_temp[n] = v_old[n] + sum * dt / 2.0 / 2.0; // devide by two because of operator splitting. // y_n_K1/2
// 			}

// 			#pragma omp master
// 			{
// 				// int error = MPI_Allgatherv(v_temp, count,
// 				//                            MPI_DOUBLE, v_global_temp_1, local_cell_num_vec,
// 				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);
// 				top.set_ghost_cells(v_temp, v_global_temp_1);
// 			}
// 			#pragma omp barrier

// 			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
// 			for (int n = 1; n < count-1; n++) {

// 				// v_new[n] = v_old[n];  // keep a copy of v_old[n], which is y_i;
// 				//dv[n] = 0.0;
// 				double sum = 0.0;
// 				int ii = 0;

// 				// #pragma omp simd reduction // not available on icpc 12.0
// 				for (ii = 0; ii < NUM_NBH; ii++) {
// 					sum +=  (lap[((n + starting_index)  * NUM_NBH) + ii] * v_global_temp_1[nbd[((n + starting_index)  * NUM_NBH) + ii]]); // this is f(t, y_i)
// 				}
// 				// dv[n] = sum;
// 				//y_bar_i+1
// 				RK_K2[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
// 				v_temp_2[n] = v_old[n] + sum * dt / 2.0 / 2.0; // devide by two because of operator splitting. // y_n_K2/2
// 			}


// 			#pragma omp master
// 			{
// 				// int error = MPI_Allgatherv(v_temp_2, count,
// 				//                            MPI_DOUBLE, v_global_temp_2, local_cell_num_vec,
// 				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);
// 				top.set_ghost_cells(v_temp_2, v_global_temp_2);

// 			}
// 			#pragma omp barrier

// 			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
// 			for (int n = 1; n < count-1; n++) {

// 				// v_new[n] = v_old[n];  // keep a copy of v_old[n], which is y_i;
// 				//dv[n] = 0.0;
// 				double sum = 0.0;
// 				int ii = 0;

// 				// #pragma omp simd reduction // not available on icpc 12.0
// 				for (ii = 0; ii < NUM_NBH; ii++) {
// 					sum +=  (lap[((n + starting_index)  * NUM_NBH) + ii] * v_global_temp_2[nbd[((n + starting_index)  * NUM_NBH) + ii]]); // this is f(t, y_i)
// 				}
// 				// dv[n] = sum;
// 				//y_bar_i+1
// 				RK_K3[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
// 				v_temp[n] = v_old[n] + sum * dt / 2.0; // devide by two because of operator splitting. // y_n_K3/2
// 			}

// 			#pragma omp master
// 			{
// 				// int error = MPI_Allgatherv(v_temp, count,
// 				//                            MPI_DOUBLE, v_global_temp_1, local_cell_num_vec,
// 				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);
// 				top.set_ghost_cells(v_temp, v_global_temp_1);
// 			}
// 			#pragma omp barrier


// 			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
// 			for (int n = 1; n < count-1; n++) {

// 				// v_new[n] = v_old[n];  // keep a copy of v_old[n], which is y_i;
// 				//dv[n] = 0.0;
// 				double sum = 0.0;
// 				int ii = 0;

// 				// #pragma omp simd reduction // not available on icpc 12.0
// 				for (ii = 0; ii < NUM_NBH; ii++) {
// 					sum +=  (lap[((n + starting_index)  * NUM_NBH) + ii] * v_global_temp_1[nbd[((n + starting_index)  * NUM_NBH) + ii]]); // this is f(t, y_i)
// 				}
// 				v_new[n] = v_new[n] + (sum + RK_K1[n] + 2 * RK_K2[n] + 2 * RK_K3[n]) * dt / 2.0 / 6.0; // devide by two because of operator splitting. // y_n_K3/2
// 				// APInfor_vec[n]->MeasureAPD90Using_dVdtMax(t, 0, Config_para.BCL, dt, v_new[n]);  // measure APD at the end of each time step.
// 			}


// 			// #pragma omp parallel for schedule(auto)
// 			for (int n = 1; n < count-1; n++) {


// 				// v_new[n] = cell_vec[n]->cc.v;
// 				// if(n==count-1){
// 				// 	v_new[n]+=dt*0.0;
// 				// }

// 				v_new[n] += f(n * dx, t, a) * dt;
// 				if (v_new[n] != v_new[n]) {
// 					std::cerr << " NaNs Encountered, Exiting Programe... ... \n\n\n";
// 					std::exit(0);
// 				}

// 				// state[(n * STATE_LEN)] = v_new[n];
// 			}


// #ifdef PROFILE_TIME
// 			#pragma omp single
// 			{
// 				// end_setup = omp_get_wtime();
// 				// fprintf(stderr, "Setup time:   %6g\n", end_setup - start);
// 				std::cerr << "Setup time:  " <<  omp_get_wtime() - end_setup << std::endl;
// 				timeelasped = omp_get_wtime();
// 			}
// #endif





// 			/*operator spliting part 2*/

// 			/* using RK4 here*/

			#pragma omp master
			{

				MPI_Barrier(MPI_COMM_WORLD);
				// int error = MPI_Allgatherv(v_new, count,
				//                            MPI_DOUBLE, v_global, local_cell_num_vec,
				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);
				top.set_ghost_cells(v_new, v_global);
			}
			#pragma omp barrier



			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
			for (int n = 1; n < count-1; n++) {

				// v_old[n] = v_new[n];  // keep a copy of v_new[n], which is y_i;
				//dv[n] = 0.0;
				double sum = 0.0;
				int ii = 0;

				// #pragma omp simd reduction // not available on icpc 12.0
				for (ii = 0; ii < NUM_NBH; ii++) {
					sum +=  (lap[((n + starting_index) * NUM_NBH) + ii] * v_new[nbd[((n + starting_index) * NUM_NBH) + ii]]); // this is f(t, y_i)
				}
				// dv[n] = sum;
				//y_bar_i+1
				sum+=f(dx*n, t,a);
				RK_K1[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
				v_temp[n] = v_old[n] + sum * (dt) / 2.0; // devide by two because of operator splitting. // y_n_K1/2
			}

			#pragma omp single
			{
				// int error = MPI_Allgatherv(v_temp, count,
				//                            MPI_DOUBLE, v_global_temp_1, local_cell_num_vec,
				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);

				top.set_ghost_cells(v_temp, v_global_temp_1);
			}
			// #pragma omp barrier


			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
			for (int n = 1; n < count-1; n++) {

				// v_old[n] = v_new[n];  // keep a copy of v_new[n], which is y_i;
				//dv[n] = 0.0;
				double sum = 0.0;
				int ii = 0;

				// #pragma omp simd reduction // not available on icpc 12.0
				for (ii = 0; ii < NUM_NBH; ii++) {
					sum +=  (lap[((n + starting_index) * NUM_NBH) + ii] * v_temp[nbd[((n + starting_index) * NUM_NBH) + ii]]); // this is f(t, y_i)
				}
				// dv[n] = sum;
				//y_bar_i+1
				sum+=f(dx*n, t+0.5*dt,a);

				RK_K2[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
				v_temp_2[n] = v_old[n] + sum * (dt) / 2.0; // devide by two because of operator splitting. // y_n_K2/2
			}



			#pragma omp master
			{
				// int error = MPI_Allgatherv(v_temp_2, count,
				//                            MPI_DOUBLE, v_global_temp_2, local_cell_num_vec,
				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);

				top.set_ghost_cells(v_temp_2, v_global_temp_2);

			}
			#pragma omp barrier

			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
			for (int n = 1; n < count-1; n++) {

				// v_old[n] = v_new[n];  // keep a copy of v_new[n], which is y_i;
				//dv[n] = 0.0;
				double sum = 0.0;
				int ii = 0;

				// #pragma omp simd reduction // not available on icpc 12.0
				for (ii = 0; ii < NUM_NBH; ii++) {
					sum +=  (lap[((n + starting_index) * NUM_NBH) + ii] * v_temp_2[nbd[((n + starting_index) * NUM_NBH) + ii]]); // this is f(t, y_i)
				}
				// dv[n] = sum;
				//y_bar_i+1
				sum+=f(dx*n, t+0.5*dt,a);

				RK_K3[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
				v_temp[n] = v_old[n] + sum * (dt); // devide by two because of operator splitting. // y_n_K3/2
			}



			#pragma omp master
			{
				// int error = MPI_Allgatherv(v_temp, count,
				//                            MPI_DOUBLE, v_global_temp_1, local_cell_num_vec,
				//                            offset_cell_num_vec, MPI_DOUBLE, MPI_COMM_WORLD);

				top.set_ghost_cells(v_temp, v_global_temp_1);

			}
			#pragma omp barrier

			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
			for (int n = 1; n < count-1; n++) {

				// v_old[n] = v_new[n];  // keep a copy of v_new[n], which is y_i;
				//dv[n] = 0.0;
				double sum = 0.0;
				int ii = 0;

				// #pragma omp simd reduction // not available on icpc 12.0
				for (ii = 0; ii < NUM_NBH; ii++) {
					sum +=  (lap[((n + starting_index)  * NUM_NBH) + ii] * v_temp[nbd[((n + starting_index)  * NUM_NBH) + ii]]); // this is f(t, y_i)
				}
				// dv[n] = sum;
				sum+=f(dx*n, t+1*dt,a);
				//y_bar_i+1
				RK_K4[n] = sum; // clear to 0 first, otherwise its going to accumulate ...
			}


			#pragma omp parallel for schedule(static)   // part 1, y_bar_j+1 = y_i + h*f(t, y(t))
			for (int n = 1; n < count-1; ++n)
			{
				v_new[n] = v_old[n] + (RK_K4[n] + RK_K1[n] + 2 * RK_K2[n] + 2 * RK_K3[n]) * (dt) / 6.0; // devide by two because of operator splitting. // y_n_K3/2
				
			}

			// for (int i = 1; i < count-1; ++i)
			// {
			// 	v_new[i] = v_old[i] + F*(v_old[i-1] - 2*v_old[i] + v_old[i+1]) + dt*f(dx*i, t,a);
			// }




			for (int i = 1; i < count-1; ++i)
			{
				v_old[i] = v_new[i];// = v_new[i]+dt*f(dx*i, t,a);
				v_old[0]=v_new[0]=0;
				v_old[count-1]=v_new[count-1]=0;
			}


			for (int i = 0; i < count; ++i)
			{
				double diff = fabs(v_old[i] - u_exact(dx*i, t+dt));

				if(diff>1E-14)
					std::cerr<<" dffii = " << v_old[i] - u_exact(dx*i, t+dt) << " " << i << " " <<t<< std::endl;
			}


		} // end of time loop
		if (v_out)
			delete [] v_out;
	} // end parallel loops


	end = omp_get_wtime();
	std::cerr << "Elapsed Time : " << end - start << std::endl;
	std::cerr << "Time per ms : " << (end - end_setup) / (t_max - Config_para.t_start) << std::endl;



	delete [] Stim_time       ;//= new float [total_cell_num];
	delete [] Stim_amp        ;//= new float [total_cell_num];
	delete [] Stim_amp_S2     ;//= new float[total_cell_num];


	delete [] v_global        ;//= new double [ total_cell_num];
	delete [] v_global_temp_1 ;//= new double [ total_cell_num];
	delete [] v_global_temp_2 ;//= new double [ total_cell_num];

	delete [] state           ;//= new double [ STATE_LEN * count];

	delete [] v_new           ;//= new double [count];
	delete [] v_old           ;//= new double [count];

	delete [] v_temp          ;//= new double [count];
	delete [] v_temp_2        ;//= new double [count];
	delete [] RK_K1           ;//= new double [count];
	delete [] RK_K2           ;//= new double [count];
	delete [] RK_K3           ;//= new double [count];
	delete [] san             ;//= new  char [count];
	delete [] FB_number       ;//= new int [count];
	delete [] Fcell           ;//= new float [count];


	delete [] nbd;
	delete [] lap;
	delete [] Cai_out;
	MPI_Finalize();


	return 0;
}
/* end of main() */
