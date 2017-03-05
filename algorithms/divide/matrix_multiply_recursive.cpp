#include <iostream>
#include <math.h>

void matrix_multiply_recursive(double *A, double *B, double *C, int n);
void print_matrix(double *A, int m, int n);
void merge_matrices(double *C11, double *C12, double *C21, double *C22, double *C, int n);
void zero_array(double *C, int n);
void sum_arrays(double *A, double *B, double *C, int n);

int main(){

	// why does caret not work for exponentiation?!
	int n = pow(2,4);   // only for powers of two (for now)

	double A[n];
	double B[n];
	double C[n];

	for(int i=0; i<n; i++){
		A[i] = i;
		B[i] = i+4;
	}

	/*
	for(int i=0; i<n; i++){
		A[i] = (double) (rand()%100);
		B[i] = (double) (rand()%100);
	}
	*/


	//print_matrix(A,sqrt(n),sqrt(n));
	//print_matrix(B,sqrt(n),sqrt(n));

	matrix_multiply_recursive(A,B,C,sqrt(n));
	print_matrix(C,sqrt(n),sqrt(n));

	return 0;
	
}

void matrix_multiply_recursive(double *A, double *B, double *C, int n){

	if(n==1){
		C[0] = A[0]*B[0];
	}
	else{

		int size = (int) pow(2,(n-1));

		// what a mess
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

		// not happy about this
		double TMP1[size]; 
		double TMP2[size];

		// zero out the C's just to be sure
		zero_array(C11, size);
		zero_array(C12, size);
		zero_array(C21, size);
		zero_array(C22, size);

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

		// do C11
		matrix_multiply_recursive(A11,B11,TMP1,n/2);
		matrix_multiply_recursive(A12,B21,TMP2,n/2);
		sum_arrays(TMP1,TMP2,C11,n/2);
		zero_array(TMP1,n/2);
		zero_array(TMP2,n/2);

		// C12 
		matrix_multiply_recursive(A11,B12,TMP1,n/2);
		matrix_multiply_recursive(A12,B22,TMP2,n/2);
		sum_arrays(TMP1,TMP2,C12,n/2);
		zero_array(TMP1,n/2);
		zero_array(TMP2,n/2);

		// C21
		matrix_multiply_recursive(A21,B11,TMP1,n/2);
		matrix_multiply_recursive(A22,B21,TMP2,n/2);
		sum_arrays(TMP1,TMP2,C21,n/2);
		zero_array(TMP1,n/2);
		zero_array(TMP2,n/2);

		//C22
		matrix_multiply_recursive(A21,B12,TMP1,n/2);
		matrix_multiply_recursive(A22,B22,TMP2,n/2);
		sum_arrays(TMP1,TMP2,C22,n/2);


		// and now we merge
		merge_matrices(C11, C12, C21, C22, C, n/2);
		//print_matrix(C,n,n);
	}

}

void sum_arrays(double *A, double *B, double *C, int n){
	// the arrays are assumed to be n \times n
	// Add A and B and store the result in C

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			C[i*n+j] = A[i*n+j]+B[i*n+j];
		}
	}

}

// print a matrix nicely-ish
void print_matrix(double *A, int m, int n){

	std::cout << "Matrix: " << std::endl;
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
	int l=0;
	for(int i=0; i<n; i++){
		l=0;
		for(int j=0; j<n; j++){
			C[k*(2*n)+l] = C11[i*n+j];
			l++;
		}
		k++;
	}

	k=0;
	// Pull C12 into C
	for(int i=0; i<n; i++){
		l=0;
		for(int j=0; j<n; j++){
			C[(2*k+1)*n+l] = C12[i*n+j];
			l++;
		}
		k++;
	}

	k=n;
	// Pull C21 into C
	for(int i=0; i<n; i++){
		l=0;
		for(int j=0; j<n; j++){
			C[(2*k)*n+l] = C21[i*n+j];
			l++;
		}
		k++;
	}

	k=n;
	// Pull C22 into C
	for(int i=0; i<n; i++){
		l=0;
		for(int j=0; j<n; j++){
			C[(2*k+1)*n+l] = C22[i*n+j];
			l++;
		}
		k++;
	}

}

void zero_array(double *C, int n){
	// zeros an n \times n array

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){

			C[i*n+j] = 0;

		}
	}

}