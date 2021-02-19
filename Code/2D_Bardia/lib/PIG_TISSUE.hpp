#ifndef PTISSUE__HPP
#define PTISSUE__HPP

#include "pig_ecc_biophysJ2021.hpp"

#ifdef _OPENMP
#include <omp.h>
#endif

class PIG_TISSUE
{
public:
	const int NX;
	const int NY;
	const int NN;

	double *tmp;

	const double dfu=0.0005;
    const double dx=0.015;//0.15 mm

	const double dt; 
	PIG_ECC **tissue = new PIG_ECC* [NN];

	std::ofstream output_file;// output filename
	std::string cell_name; 
	std::string fileout_name;


	PIG_TISSUE(
		int NX,
		int NY,
		double dt, 
       	bool output_data = false, 
       	int PIG_CELL_TYPE = CONTROL
       	)
		: NX(NX)
		, NY(NY)
		, NN(NX*NY)
		, dt(dt)

	{
		

		switch(PIG_CELL_TYPE){
			case CONTROL:
				cell_name = "CONTROL";
				break;
			case REMOTE_HF:
				cell_name = "REMOTE";
				break;
			case BORDER_HF:
				cell_name = "BORDER";
				break;
		}
		std::cout << cell_name << " SIMULATION" << std::endl;
		std::cout << "Initializing tissue..." << std::endl;
		init_tissue(PIG_CELL_TYPE);
		std::cout << "NX: " << NX << " NY: " << NY << std::endl;

		tmp = new double [NN]; //used in Diffusion



		if (output_data) {
			fileout_name = "2D_"+cell_name+"_results.txt";
			output_file.open("./results/2D_RESULTS/"+fileout_name);                      // output filename
		}

	}
	~PIG_TISSUE() {
		delete [] tissue;
		output_file.close();
	}


	void solve_ODEs(double t, double dt);

	void init_tissue(int PIG_CELL_TYPE);
	void print_tissue(void);
	void ekmodel_diffusion();

	void ectopic_beat(std::string ECT_BEAT_TYPE);
	void create_stim_map(std::string STIM_TYPE, int NUM_STIM);


};

void PIG_TISSUE::create_stim_map(std::string STIM_TYPE, int NUM_STIM){

	if(STIM_TYPE == "LEFT"){
		for(int idx=0; idx<NX; idx++){
			for(int idy=0; idy<NY; idy++){
				if(idy < NUM_STIM){
					tissue[idx*NX +idy]->allow_stimulation_flag = true;
				}
				else{
					tissue[idx*NX +idy]->allow_stimulation_flag = false;
				}
			}
		}
	}
	
}

// void PIG_TISSUE::solve_ODEs(double t, double dt){
// 	#pragma omp parallel for
// 	for(int id=0; id<NN; id++){
// 		// ptissue.tissue[id]->solve_single_time_step_vm_para(t+dt, dt);	 //Solve single time step for all cells
// 		tissue[id]->solve_ODEs_Vm_as_para(t, dt);	 //Solve single time step for all cells
// 	}

// }

void PIG_TISSUE::ectopic_beat(std::string ECT_BEAT_TYPE){
	if(ECT_BEAT_TYPE == "TOP"){

		for(int idx=0; idx<NX; idx++){
			for(int idy=0; idy<NY; idy++){
				if(idx > NX/2){
					tissue[idx*NX+idy]->V = 30;
				}
			}
		}
	}
}

void PIG_TISSUE::ekmodel_diffusion(){
	
    //non-flux boundary
    #pragma omp parallel for
    for (int i=0;i<NY;i++) {
      tissue[i*NX+0]->V=tissue[i*NX+2]->V;
      tissue[i*NX+NX-1]->V=tissue[i*NX+NX-3]->V;
    }
    #pragma omp parallel for
    for (int j=0;j<NX;j++) {
      tissue[0*NX+j]->V=tissue[2*NX+j]->V;
      tissue[(NY-1)*NX+j]->V=tissue[(NY-3)*NX+j]->V;
    }
    #pragma omp parallel for
    for (int i=1;i<NY-1;i++) {
      for (int j=1;j<NX-1;j++) {
        tmp[i*NX+j]=tissue[i*NX+j]->V+(tissue[(i-1)*NX+j]->V+tissue[(i+1)*NX+j]->V+tissue[i*NX+(j-1)]->V+tissue[i*NX+(j+1)]->V-4*tissue[i*NX+j]->V)*dfu*dt/(dx*dx)/2;
      }
    }
    #pragma omp parallel for
    for (int i=0;i<NY;i++) {
      tmp[i*NX+0]=tmp[i*NX+2];
      tmp[i*NX+NX-1]=tmp[i*NX+NX-3];
    }
    #pragma omp parallel for
    for (int j=0;j<NX;j++) {
      tmp[0*NX+j]=tmp[2*NX+j];
      tmp[(NY-1)*NX+j]=tmp[(NY-3)*NX+j];
    }

    for (int i=1;i<NY-1;i++) {
	  #pragma omp parallel for
      for (int j=1;j<NX-1;j++) {
        tissue[i*NX+j]->V=tmp[i*NX+j]+(tmp[(i-1)*NX+j]+tmp[(i+1)*NX+j]+tmp[i*NX+(j-1)]+tmp[i*NX+(j+1)]-4*tmp[i*NX+j])*dfu*dt/(dx*dx)/2;
      }
    }
}

void PIG_TISSUE::init_tissue(int PIG_CELL_TYPE){
	#pragma omp parallel for
	for (int id=0; id<NN; id++){
		tissue[id] = new PIG_ECC(dt, false, PIG_CELL_TYPE);
	}
	
}

void PIG_TISSUE::print_tissue(){
	
	for (int id=0; id<NN; id++){
		output_file << tissue[id]->V << "\t";
	}
	output_file << std::endl;

}


#endif