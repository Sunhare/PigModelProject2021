#ifndef diffusion_class_H
#define diffusion_class_H
#include "one_d_conduction.h"
#include "util.h"
#include <iostream>



class OneD_Diff
{
public:


	double                   *lap;
	int                      *nbd;
	unsigned char            *tissue;

	int count;

	double DIFF_COEF;
	static const int NUM_NBH = 3;

	OneD_Diff(int NX = 100, double diff_coef = 0.3, double dx = 0.1) {

		count = NX;
		tissue = new unsigned char [NX];
		for (int id = 0; id < count; id++) {
			tissue[id] = 14;
		}
		int                      **neighbourhood;
		double                   **laplacian;
		laplacian = generate_one_D_laplacian_test(NX, tissue, DIFF_COEF, dx);
		neighbourhood = generate_one_D_neighboors(NX);

		nbd = new int [count * NUM_NBH];
		lap = new double [count * NUM_NBH];

		for (int id = 0; id < count; id++) {
			for (int i = 0; i < NUM_NBH; i++) {
				nbd[(id * NUM_NBH) + i] = neighbourhood[id][i];
				lap[(id * NUM_NBH) + i] = laplacian[id][i];
			}
		}



		deallocate_and_zero_2d_matrix(neighbourhood, count, NUM_NBH);
		deallocate_and_zero_2d_matrix(laplacian, count, NUM_NBH);

		std::cerr << " >> Succesfully read in Geometry <<" << std::endl;
		std::cerr << " >> Total Number of Cells: " << count << " <<" << std::endl;
	};

	
	~OneD_Diff() {
		delete [] tissue;
		delete [] nbd;
		delete [] lap;
	};


};


#endif