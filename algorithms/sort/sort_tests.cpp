// just to test something

#include<math.h>
#include "sort.h"
#include<iostream>
#include<vector>

// need to compile as 
// g++ -std=c++11 -o test.out test.cpp sort.cpp
// the sort.cpp needs to explicitly included so the compiler can find it

int main(){

  std::vector<int> v = {17, 6, 4, 13, 12, 7};
  std::vector<int> w = {8, 22, 43, 9, 16};
  std::vector<int> x = {9, 63, 12, 16, 11, 105};

  insertion_sort(v);

  std::cout << "The sorted vector v contains: " << std::endl;
  for(int j = 0; j<v.size();j++){
    std::cout << v[j] << "\n";
  }

  merge_sort(w,0,w.size());

  std::cout << "The sorted vector w contains: " << std::endl;
  for(int j = 0; j<w.size();j++){
    std::cout << w[j] << "\n";
  }

  merge_sort_truncated(x,0,x.size(),3);

  std::cout << "The sorted vector x contains: " << std::endl;
  for(int j = 0; j<x.size();j++){
    std::cout << x[j] << "\n";
  }

  return 0;
}
