// insertion sort, but now with an array

#include<iostream>

void insertion_sort(int A[10]);  // need to know the type and size of array in advance!

int main(){

    int v[10] = {9,8,7,6,5,4,3,2,1,0};

    std::cout << "The original array contains \n the values";
    for(int j=0; j<10; j++){
      std::cout << v[j] << '\n';
    }

    insertion_sort(v);
    
    std::cout << "The sorted array contains \n";
    for(int j=0; j<10; j++){

      std::cout<<  v[j] << '\n';

    }

}

void insertion_sort(int A[10]){

  int i;
  int key;
  
  for(int j=1; j<10; j++){

    key = A[j];
    i = j-1;
    
    while(i>=0 & A[i]>key){
      A[i+1]=A[i];
      i--;
    } 
    A[i+1]=key;
  }

}
