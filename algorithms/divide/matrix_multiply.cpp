#include <iostream>

void matrix_multiply(double A[], double B[], double C[], int m, int n, int p);

int main(){

	int m,n,p;

	m = 3;
	n = 3;
	p = 2;

	//double A[m*n]; 
	double A[] = {1,2,3,4,5,6,7,8,9};
	//double B[n*p]; 
	double B[] = {9,8,7,6,5,4};
	double C[m*p];

	matrix_multiply(A, B, C, m, n, p);

	for(int i = 0; i<m; i++){
		for(int j = 0; j<p; j++){
			std::cout << C[i*p+j] << std::endl;
		}
	}

}

void matrix_multiply(double A[], double B[], double C[], int m, int n, int p){

	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			C[i*p+j]=0;
			for(int k=0; k<n; k++){
				C[i*p+j]+=A[i*n+k]*B[k*p+j];
			}
		}
	}

}