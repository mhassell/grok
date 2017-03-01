#include <iostream>
#include <math.h>

void matrix_multiply_recursive(double *A, double *B, double *C, int n);

int main(){

	// why does caret not work for exponentiation?!
	int n = pow(2,4);   // only for powers of two (for now)

	double A[n];
	double B[n];
	double C[n];

	for(int i=0; i<n; i++){
		A[i] = (double) (rand()%100);
		std::cout<<A[i]<<'\n' << std::endl;
		B[i] = (double) (rand()%100);
	}

	matrix_multiply_recursive(A,B,C,n/2);

	return 0;
	
}

void matrix_multiply_recursive(double *A, double *B, double *C, int n){

	if(n==1){
		C[0] = A[0]*B[0];
	}
	else{
		double A11[2^(n-1)];
		double A12[2^(n-1)];
		double A21[2^(n-1)];
		double A22[2^(n-1)];
		double B11[2^(n-1)];
		double B12[2^(n-1)];
		double B21[2^(n-1)];
		double B22[2^(n-1)];

		// pull out top left corners
		for(int i=0; i<n/2; i++){
			for(int j=0; j<n/2; j++){
				//std::cout << A[i*n/2+j] << '\n' << std::endl;
				A11[i*(n/2)+j] = A[i*n/2+j];
				B11[i*(n/2)+j] = B[i*n/2+j];
			}
			
		}

		// top right corners
		for(int i=0; i<n/2; i++){
			for(int j=n/2; j<n; j++){
				A12[i*(n/2)+j] = A[i*n/2+j];
				B12[i*(n/2)+j] = B[i*n/2+j];
			}
		}

		// bottom left corners
		for(int i=n/2; i<n; i++){
			for(int j=0; j<n/2; j++){
				//std::cout << A[i*n+j] << '\n' << std::endl;
				A21[i*(n/2)+j] = A[i*n+j];
				B21[i*(n/2)+j] = B[i*n+j];
			}
		}

		// bottom right corner
		for(int i=n/2; i<n; i++){
			for(int j=n/2; j<n; j++){
				std::cout << A[i*n+j] << '\n' << std::endl;
				A21[i*(n/2)+j] = A[i*n+j];
				B21[i*(n/2)+j] = B[i*n+j];
			}
		}
	}

}