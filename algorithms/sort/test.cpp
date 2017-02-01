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
  
  return 0;
}
