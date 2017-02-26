#include <iostream>
#include <tuple>
#include <vector>
#include <limits>
#include <math.h>

std::tuple <int,int,double> max_crossing_subarray(std::vector<double> A, int low, int mid, int high);
std::tuple<int,int,double> max_subarray(std::vector<double> A, int low, int high);

int main(){

	std::vector<double> A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	//std::vector<double> A = {1, -1, 9};

	std::tuple<int,int,double> answer = max_subarray(A,0,A.size()-1);

	std::cout << std::get<0>(answer) << '\n' << std::get<1>(answer) << '\n' << std::get<2>(answer) << std::endl;

	return 0;

}

std::tuple<int,int,double> max_subarray(std::vector<double> A, int low, int high){

	std::tuple<int,int,double> ans;
	std::tuple<int,int,double> left_sub;
	std::tuple<int,int,double> right_sub;
	std::tuple<int,int,double> crossing_sub;

	if(high==low){
		ans = {low,high,A[low]};
		return ans;
	}
	else{
		int mid = floor((low+high)/2);
		left_sub = max_subarray(A, low, mid);
		right_sub = max_subarray(A, mid+1, high);
		crossing_sub = max_crossing_subarray(A, low, mid, high);
	}

	// is my left subarray the largest?
	if(std::get<2>(left_sub)>std::get<2>(right_sub) & std::get<2>(left_sub)>std::get<2>(crossing_sub)){
		ans = left_sub;
	}
	//is my right subarray largest?
	else if (std::get<2>(right_sub)>std::get<2>(left_sub) & std::get<2>(right_sub)>std::get<2>(crossing_sub)){
		ans = right_sub;
	}
	// my crossing subarray is largest
	else{
		ans = crossing_sub;
	}

	return ans;

}

std::tuple <int,int,double> max_crossing_subarray(std::vector<double> A, int low, int mid, int high){

	double inf = std::numeric_limits<double>::infinity();  // is this wise?
	double sum = 0;

	int max_left = 0;
	double left_sum = -inf;
	for(int i=mid; i>=low; i--){
		sum += A[i];
		if(sum>left_sum){
			left_sum = sum;
			max_left = i;
		}
	}

	int max_right = 0;
	double right_sum = -inf;
	sum = 0;
	for(int j=mid+1; j<=high; j++){
		sum += A[j];
		if(sum > right_sum){
			right_sum = sum;
			max_right = j;
		}

	}

	std::tuple<int,int,double> out = {max_left, max_right, left_sum+right_sum};

	return out;

}