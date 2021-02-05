#ifndef CVODE_PTISSUE__HPP
#define CVODE_PTISSUE__HPP

#include "CVOde_Cell.hpp"

typedef int  (*cvode_func) (realtype t, N_Vector y, N_Vector ydot, void *user_data);

class CVOde_TISSUE
{
public:
	const int NX;
	const int NY;
	const int NN;
	const int NEQ;

	double *tmp;

	const double dfu=0.0005;
    const double dx=0.015;//0.15 mm

	const double dt_max; 
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
		, dt_max(t_step_max)

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
	void ekmodel_diffusion(double t);

};

// void CVOde_TISSUE::ekmodel_diffusion(double t){
	
//     //non-flux boundary
//     for (int i=0;i<NX;i++) {
//       tissue[i*NY+0]->cell.V=tissue[i*NY+2]->cell.V;
//       tissue[i*NY+NY-1]->cell.V=tissue[i*NY+NY-3]->cell.V;
//     }
//     for (int j=0;j<NY;j++) {
//       tissue[0*NY+j]->cell.V=tissue[2*NY+j]->cell.V;
//       tissue[(NX-1)*NY+j]->cell.V=tissue[(NX-3)*NY+j]->cell.V;
//     }
//     for (int i=1;i<NX-1;i++) {
//       for (int j=1;j<NY-1;j++) {
//         tmp[i*NY+j]->cell.V=tissue[i*NY+j]->cell.V+(tissue[(i-1)*NY+j]->cell.V+tissue[(i+1)*NY+j]->cell.V+tissue[i*NY+(j-1)]->cell.V+tissue[i*NY+(j+1)]->cell.V-4*tissue[i*NY+j]->cell.V)*dfu*dt/(dx*dx)/2;
//       }
//     }

//     for (int i=0;i<NX;i++) {
//       tmp[i*NY+0]->cell.V=tmp[i*NY+2]->cell.V;
//       tmp[i*NY+NY-1]->cell.V=tmp[i*NY+NY-3]->cell.V;
//     }
//     for (int j=0;j<NY;j++) {
//       tmp[0*NY+j]->cell.V=tmp[2*NY+j]->cell.V;
//       tmp[(NX-1)*NY+j]->cell.V=tmp[(NX-3)*NY+j]->cell.V;
//     }
//     for (int i=1;i<NX-1;i++) {
//       for (int j=1;j<NY-1;j++) {
//         tissue[i*NY+j]->cell.V=tmp[i*NY+j]->cell.V+(tmp[(i-1)*NY+j]->cell.V+tmp[(i+1)*NY+j]->cell.V+tmp[i*NY+(j-1)]->cell.V+tmp[i*NY+(j+1)]->cell.V-4*tmp[i*NY+j]->cell.V)*dfu*dt/(dx*dx)/2;
//       }
//     }
// }

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