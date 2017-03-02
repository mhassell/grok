#include <iostream>
#include <math.h>

void matrix_multiply_recursive(double *A, double *B, double *C, int n);
void print_matrix(double *A, int m, int n);

int main(){

	// why does caret not work for exponentiation?!
	int n = pow(2,2);   // only for even powers of two (for now)

	double A[n];
	double B[n];
	double C[n];

	for(int i=0; i<n; i++){
		A[i] = (double) (rand()%100);
		B[i] = (double) (rand()%100);
	}

	print_matrix(A,sqrt(n),sqrt(n));
	matrix_multiply_recursive(A,B,C,sqrt(n));

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
				//std::cout << "Top left corner " << std::endl;
				//std::cout << A[i*n+j] << '\n' << std::endl;
				A11[i*(n/2)+j] = A[i*n+j];
				B11[i*(n/2)+j] = B[i*n+j];
			}
		}
		std::cout << "Top left corner " << std::endl;
		print_matrix(A11,n/2,n/2);

		// top right corners
		for(int i=0; i<n/2; i++){
			for(int j=n/2; j<n; j++){
				//std::cout << "Top right corner " << std::endl;
				//std::cout << A[i*n/2+j] << '\n' << std::endl;
				A12[(i-1)*(n/2)+j] = A[i*n+j];
				B12[(i-1)*(n/2)+j] = B[i*n+j];
			}
		}
		std::cout << "Top right corner " << std::endl;
		print_matrix(A12,n/2,n/2);

		// bottom left corners
		for(int i=n/2; i<n; i++){
			for(int j=0; j<n/2; j++){
				//std::cout << "Bottom left corner " << std::endl;
				//std::cout << A[i*n+j] << '\n' << std::endl;
				//std::cout << i*n+j << std::endl;
				//std::cout << i*(n/2)+j  << std::endl;
				A21[i*(n/2)+j-n] = A[i*n+j];
				B21[i*(n/2)+j-n] = B[i*n+j];
			}
		}
		std::cout << "Bottom left corner " << std::endl;
		print_matrix(A21,n/2,n/2);

		// bottom right corners
		for(int i=n/2; i<n; i++){
			for(int j=n/2; j<n; j++){
				//std::cout << "Bottom right corner " << std::endl;
				//std::cout << A[i*n+j] << '\n' << std::endl;
				//std::cout << i*(n/2)+j-(n+2)  << std::endl;
				A22[i*(n/2)+j-(n+2)] = A[i*n+j];
				B22[i*(n/2)+j-(n+2)] = B[i*n+j];
			}
		}
		std::cout << "Bottom right corner " << std::endl;
		print_matrix(A22,n/2,n/2);
	}
}

void print_matrix(double *A, int m, int n){

	for(int i=0;i<m; i++){
		//std::cout << "Row number " << i << std::endl;
		for(int j=0; j<n; j++){
			std::cout << A[i*n+j] << ' ';
		}
		std::cout << '\n' << std::endl;
	}

}