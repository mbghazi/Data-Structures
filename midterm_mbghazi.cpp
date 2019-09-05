/*
**  PROGRAM: Matrix Multiply
**
**  PURPOSE: This is a simple matrix multiply program. 
**           It will compute the product
**
**                C  = A * B
**
**           A and B are set to constant matrices so we
**           can make a quick test of the multiplication.
**
**  USAGE:   Right now, I hardwire the martix dimensions. 
**           later, I'll take them from the command line.
**
**  HISTORY: Written by Tim Mattson, Nov 1999.
*/
#include <iostream>
#include <omp.h>

using namespace std;

#define ORDER 500
#define AVAL 3.0
#define BVAL 5.0
#define TOL  0.001
#define Ndim ORDER
#define Pdim ORDER
#define Mdim ORDER
#define NUM_THREADS 4//added
int main(int argc, char **argv)
{
	double A[Ndim][Pdim], B[Pdim][Mdim], C[Ndim][Mdim]; 
	int i,j,k;
	//double *A, *B, *C, 
	double cval, tmp, err, errsq;
        double dN, mflops;
	double start_time, run_time;
	double sum;
	omp_set_num_threads(NUM_THREADS);

	start_time = omp_get_wtime(); 
	/* Initialize matrices */
	
	
	for (i=0; i<Ndim; i++)
		for (j=0; j<Pdim; j++)
			A[i][j] = AVAL;

	for (i=0; i<Pdim; i++)
		for (j=0; j<Mdim; j++)
			B[i][j] = BVAL;

	for (i=0; i<Ndim; i++)
		for (j=0; j<Mdim; j++)
			C[i][j] = 0.0;


	/* Do the matrix product */
	
	#pragma parallel for schedule(dynamic) lastprivate(sum) red(-tmp)
	for (i=0; i<Ndim; i++){
//added
		//#pragma parallel for 			
		for (j=0; j<Mdim; j++){
			tmp = 0.0;
				//#pragma parallel for schedule(dynamic) lastprivate(tmp) 			
				for(k=0;k<Pdim;k++){
				/* C(i,j) = sum(over k) A(i,k) * B(k,j) */
				tmp += A[i][k] *  B[k][j];
			}
			C[i][j] = tmp;
			sum += tmp;
		}
	}
	/* Check the answer */
	
	
	cout << "Summary is " << sum << endl;

	cval = Pdim * AVAL * BVAL;
	errsq = 0.0;
	for (i=0; i<Ndim; i++){
		for (j=0; j<Mdim; j++){
			err = C[i][j] - cval;
		    errsq += err * err;
		}
	}
	
	errsq += sum - cval*Ndim*Mdim;
	if (errsq > TOL) 
		cout << "Errors in multiplication: "<< errsq<< endl;
	else
		cout << "Hey, it worked! Error is: " << errsq << endl;

	run_time = omp_get_wtime() - start_time;

	cout << "Order " << ORDER << " multiplication in " << run_time << " seconds "<< endl;
        dN = (double)ORDER;
        mflops = 2.0 * dN * dN * dN/(1000000.0* run_time);
	cout << "Order " << " multiplication at " << mflops << " mflops" << endl; 
	cout << "All done "<< endl;
	return 0;
}
