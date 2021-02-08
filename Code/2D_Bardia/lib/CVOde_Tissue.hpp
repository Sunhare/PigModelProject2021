#ifndef CVODE_PTISSUE__HPP
#define CVODE_PTISSUE__HPP

#include "CVOde_Cell.hpp"

#ifdef _OPENMP
#include <omp.h>
#endif


typedef int  (*cvode_func) (realtype t, N_Vector y, N_Vector ydot, void *user_data);

class CVOde_TISSUE
{
public:
	const int NX;
	const int NY;
	const int NN;
	const int NEQ;

	double *tmp;

	const double dfu=0.0001;
	// const double dfu=0.0001;
    const double dx=0.05;//0.15 mm

	const double dt; 
	CVOde_Cell **tissue = new CVOde_Cell* [NN];

	std::ofstream output_file;// output filename
	std::string cell_name; 
	std::string fileout_name;


	CVOde_TISSUE(
		int NX,
		int NY,
		int NEQ, 
		double t_step_max, 
		cvode_func ode_function,
       	bool output_data = false, 
       	int PIG_CELL_TYPE = CONTROL
       	)
		: NX(NX)
		, NY(NY)
		, NN(NX*NY)
		, NEQ(NEQ)
		, dt(t_step_max)

	{
		init_tissue();
		tmp = new double [NN];

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
		if (output_data) {
			fileout_name = "2D_"+cell_name+"_results.txt";
			output_file.open("./results/2D_RESULTS/"+fileout_name);                      // output filename
		}

	}
	~CVOde_TISSUE() {
		delete [] tissue;
		output_file.close();
	}


	void init_tissue(void);
	void print_tissue(int tn);
<<<<<<< HEAD
<<<<<<< HEAD
	void ekmodel_diffusion(void);
=======
	void ekmodel_diffusion(double t);
>>>>>>> parent of 9dd1908... Quick stash
	void ectopic_beat(std::string ECT_BEAT_TYPE);
=======
	void ekmodel_diffusion(double t);
>>>>>>> parent of 1ba6ac1... Successful 2D Control Ectopic Beat
	void create_stim_map(std::string STIM_TYPE, int NUM_STIM);

};

void CVOde_TISSUE::create_stim_map(std::string STIM_TYPE, int NUM_STIM){

	if(STIM_TYPE == "LEFT"){
		for(int id=0; id<NN; id++){
			if((id*NX+id)%NX < NUM_STIM ){
				tissue[id]->cell.allow_stimulation_flag = true;
			}
			else{
				tissue[id]->cell.allow_stimulation_flag = false;
			}		
		}
	}
	
}


void CVOde_TISSUE::ekmodel_diffusion(double t){
	
    //non-flux boundary
    #pragma omp parallel for
    for (int i=0;i<NY;i++) {
      tissue[i*NX+0]->cell.V=tissue[i*NX+2]->cell.V;
      tissue[i*NX+NX-1]->cell.V=tissue[i*NX+NX-3]->cell.V;
    }
    #pragma omp parallel for
    for (int j=0;j<NX;j++) {
      tissue[0*NX+j]->cell.V=tissue[2*NX+j]->cell.V;
      tissue[(NY-1)*NX+j]->cell.V=tissue[(NY-3)*NX+j]->cell.V;
    }
    #pragma omp parallel for
    for (int i=1;i<NY-1;i++) {
      for (int j=1;j<NX-1;j++) {
        tmp[i*NX+j]=tissue[i*NX+j]->cell.V+(tissue[(i-1)*NX+j]->cell.V+tissue[(i+1)*NX+j]->cell.V+tissue[i*NX+(j-1)]->cell.V+tissue[i*NX+(j+1)]->cell.V-4*tissue[i*NX+j]->cell.V)*dfu*dt/(dx*dx)/2;
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
        tissue[i*NX+j]->cell.V=tmp[i*NX+j]+(tmp[(i-1)*NX+j]+tmp[(i+1)*NX+j]+tmp[i*NX+(j-1)]+tmp[i*NX+(j+1)]-4*tmp[i*NX+j])*dfu*dt/(dx*dx)/2;
      }
    }
}

void CVOde_TISSUE::init_tissue(){
	for (int id=0; id<NN; id++){
		tissue[id] = new CVOde_Cell(NEQ, 0.2, fnew_pig_vm_as_para, false, CONTROL);
	}
}

void CVOde_TISSUE::print_tissue(int tn){
	// output_file << t << "\t";
	
	for (int id=0; id<NN; id++){
		output_file << tissue[id]->cell.V << "\t";
	}
	output_file << std::endl;

}

#endif