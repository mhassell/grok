#include <math.h>
#include <iostream>

void print_matrix(double *A, int m, int n);
void merge_matrices(double *C11, double *C12, double *C21, double *C22, double *C, int n);
void zero_array(double *C, int n);
void sum_arrays(double *A, double *B, double *C, int n);
void diff_arrays(double *A, double *B, double *C, int n);
void strassen(double *A, double *B, double *C, int n);

int main(){

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


	print_matrix(A,sqrt(n),sqrt(n));
	print_matrix(B,sqrt(n),sqrt(n));

	strassen(A,B,C,sqrt(n));
	print_matrix(C,sqrt(n),sqrt(n));

	return 0;

}

void strassen(double *A, double *B, double *C, int n){
	// multiply A and B using strassen and store the result in C

	if(n==1){
		C[0] = A[0]*B[0];
	}
	else{

		int size = (int) pow(2,(n-1));

		// what a mess
		double A11[size], A12[size], A21[size], A22[size];
		double B11[size], B12[size], B21[size], B22[size];
		double C11[size], C12[size], C21[size], C22[size];
		double S1[size], S2[size], S3[size], S4[size], S5[size];
		double S6[size], S7[size], S8[size], S9[size], S10[size];
		double P1[size], P2[size], P3[size], P4[size], P5[size], P6[size], P7[size];

		// not happy about this
		double TMP1[size]; 
		double TMP2[size];

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

		// this needs overloaded operators
		diff_arrays(B12,B22,S1,n/2);
		sum_arrays(A11,A12,S2,n/2);
		sum_arrays(A21,A22,S3,n/2);
		diff_arrays(B21,B11,S4,n/2);
		sum_arrays(A11,A22,S5,n/2);
		sum_arrays(B11,B22,S6,n/2);
		diff_arrays(A12,A22,S7,n/2);
		sum_arrays(B21,B22,S8,n/2);
		diff_arrays(A11,A21,S9,n/2);
		sum_arrays(B11,B12,S10,n/2);

		// this does too!
		strassen(A11,S1,P1,n/2);
		strassen(S2,B22,P2,n/2);
		strassen(S3,B11,P3,n/2);
		strassen(A22,S4,P4,n/2);
		strassen(S5,S6,P5,n/2);
		strassen(S7,S8,P6,n/2);
		strassen(S9,S10,P7,n/2);

		// oh man! 
		sum_arrays(P5,P4,TMP1,n/2);
		diff_arrays(TMP1,P2,TMP2,n/2);
		sum_arrays(TMP2,P6,C11,n/2); // C11 computed
		zero_array(TMP1,n/2);
		zero_array(TMP2,n/2);

		sum_arrays(P1,P2,C12,n/2);
		sum_arrays(P3,P4,C21,n/2);

		sum_arrays(P5,P1,TMP1,n/2);
		diff_arrays(TMP1,P3,TMP2,n/2);
		diff_arrays(TMP2,P7,C22,n/2);

		merge_matrices(C11,C12,C21,C22,C,n/2);

	}

}

void diff_arrays(double *A, double *B, double *C, int n){
		// the arrays are assumed to be n \times n
		// compute A-B and store the result in C

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			C[i*n+j] = A[i*n+j]-B[i*n+j];
		}
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