#include <iostream>
#include <math.h>

void matrix_multiply_recursive(double *A, double *B, double *C, int n);
void print_matrix(double *A, int m, int n);
void merge_matrices(double *C11, double *C12, double *C21, double *C22, double *C, int n);

int main(){

	// why does caret not work for exponentiation?!
	int n = pow(2,4);   // only for powers of two (for now)

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
		double C11[size];
		double C12[size];
		double C21[size];
		double C22[size];

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

		// now that we've split the matrices up we can multiply
		matrix_multiply_recursive(A11,B11,C11,n/2); // UH OH!


		// and now we merge
		merge_matrices(C11, C12, C21, C22, C, n/2);
		print_matrix(C,n,n);
	}

}

// print a matrix nicely-ish
void print_matrix(double *A, int m, int n){

	for(int i=0;i<m; i++){
		//std::cout << "Row number " << i << std::endl;
		for(int j=0; j<n; j++){
			std::cout << A[i*n+j] << ' ';
		}
		std::cout << '\n' << std::endl;
	}

}

// merge four matrices into a single larger matrix 
void merge_matrices(double *C11, double *C12, double *C21, double *C22, double *C, int n){

	//n is the size of C11 (& the other three) (i.e. if it is an 8x8 matrix, n = 8)
	//therefore, C will be 2n \times 2n
 
	// Pull C11 into C
	int k=0;
	int l;
	for(int i=0; i<n; i++){
		l=0;
		for(int j=0; j<n; j++){
			std::cout << C11[i*n+j] << std::endl;
			C[k*(2*n)+l] = C11[i*n+j];
			l++;
		}
		k++;
	}
}