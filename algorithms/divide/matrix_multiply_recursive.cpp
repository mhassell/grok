#include <iostream>
#include <math.h>

void matrix_multiply_recursive(double *A, double *B, double *C, int n);
void print_matrix(double *A, int m, int n);

int main(){

	// why does caret not work for exponentiation?!
	int n = pow(2,8);   // only for even powers of two (for now)

	double A[n];
	double B[n];
	double C[n];

	for(int i=0; i<n; i++){
		A[i] = (double) (rand()%100);
		B[i] = (double) (rand()%100);
	}

	matrix_multiply_recursive(A,B,C,sqrt(n));

	return 0;
	
}

void matrix_multiply_recursive(double *A, double *B, double *C, int n){

	if(n==1){
		C[0] = A[0]*B[0];
	}
	else{

		int size = (int) pow(2,(n-1));

		double A11[size];
		double A12[size];
		double A21[size];
		double A22[size];
		double B11[size];
		double B12[size];
		double B21[size];
		double B22[size];

		// pull out top left corners
		int k = 0;
		int l = 0;
		for(int i=0; i<n/2; i++){
			l=0;
			for(int j=0; j<n/2; j++){
				A11[k*(n/2)+l] = A[i*n+j];
				B11[k*(n/2)+l] = B[i*n+j];
				l++;
			}
			k++;
		}
		//std::cout << "Top left corner " << std::endl;
		//print_matrix(A11, n/2, n/2);

		// top right corners
		k = 0;
		for(int i=0; i<n/2; i++){
			l=0;
			for(int j=n/2; j<n; j++){
				A12[k*(n/2)+l] = A[i*n+j];
				B12[k*(n/2)+l] = B[i*n+j];
				l++;
			}
			k++;
		}
		//std::cout << "Top right corner " << std::endl;
		//print_matrix(A12,n/2,n/2);

		// bottom left corners
		k=0;
		for(int i=n/2; i<n; i++){
			l=0;
			for(int j=0; j<n/2; j++){
				A21[k*(n/2)+l] = A[i*n+j];
				B21[k*(n/2)+l] = B[i*n+j];
				l++;
			}
			k++;
		}
		//std::cout << "Bottom left corner " << std::endl;
		//print_matrix(A21,n/2,n/2);

		// bottom right corners
		k = 0;
		for(int i=n/2; i<n; i++){
			l=0;
			for(int j=n/2; j<n; j++){
				A22[k*(n/2)+l] = A[i*n+j];
				B22[k*(n/2)+l] = B[i*n+j];
				l++;
			}
			k++;
		}
		//std::cout << "Bottom right corner " << std::endl;
		//print_matrix(A22,n/2,n/2);
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