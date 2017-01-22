#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &v);

int main()
{
  std::vector<int> v = {7,5,16,8};
  v.push_back(25);
  v.push_back(13);

  std::cout << "The vector v contains " << v.size() << " elements" << "\n";

  std::cout << "Unsorted vector: \n";
  for(int n=0; n<v.size(); n++){
    std::cout << v.at(n) << "\n";
  }
  
  insertion_sort(v);

  std::cout << "Sorted vector: \n";
  for(int n=0; n<v.size(); n++){
    std::cout << v[n] << "\n";
  }
}

void insertion_sort(std::vector<int> &v){
  int key;
  int i;
  for(int j=1; j<v.size(); j++){
    key = v[j];
    i = j-1;
    // keep bumping stuff to the right until we find where we should insert the key
    while(i>=0 & v[i]>key){
      v[i+1] = v[i];
      i--;
    }
    // once we've shifted everyone else right, drop the key where it belongs
    v[i+1] = key;
  }
}
