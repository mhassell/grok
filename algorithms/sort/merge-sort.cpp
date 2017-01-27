#include<iostream>
#include<vector>

void merge(std::vector<int> &v, int p, int q, int r);
void merge_sort(std::vector<int> &v, int p, int r);

int main(){

  std::vector<int> v;
  v = {0,2,4,1,3,5,7};
  // v = {1,3,5,7,0,2,4};

  merge(v,0,2,6);

  for(int j=0; j<v.size(); j++){
    std::cout << v[j] << '\n';
  }

}

void merge(std::vector<int> &v, int p, int q, int r){

  int n1 = q-p+1;
  int n2 = r-q;

  // std::cout << "n1 = "<< n1 << '\n';
  // std::cout << "n2 = "<< n2 << '\n';
  // std::cout << "r = " << r << '\n';

  std::vector<int> L(n1,0); // initialize to a vector of zeros
  std::vector<int> R(n2,0);
  
  for(int j=0; j<n1; j++){
    L[j] = v[p+j];
    // std::cout << "L[j] = " << L[j] << '\n';
  }

  for(int j=0; j<n2; j++){
    R[j] = v[q+j+1];
    // std::cout << "R[j] = " << R[j] << '\n';
  }

  int i=0;
  int j=0;
  for(int k=p; k<=r; k++){
    if(i<n1 & j<n2){ // L and R still have entries
      if(L[i]<=R[j]){   
	v[k] = L[i];
	i++;
      }
      else{
	v[k]=R[j];
	j++;
	// std::cout << "R[j]= " << R[j] << '\n';
	// std::cout << "i = " << i << '\n';
	// std::cout << "j = " << j << '\n';
	// std::cout << "k = " << k << '\n';
      }
    }
    else if(i==n1 & j<n2){  // emptied L out
      v[k]=R[j];
      j++;
      // std::cout << "R[j]= " << R[j] << '\n';
    }
    else if(i<n1 & j==n2){  // emptied R out
      v[k]=L[i];
      i++;
      // std::cout << "L[i]= " << L[i] << '\n';
      // std::cout << "k = " << k << '\n';
      // std::cout << "i = " << i << '\n';
      // std::cout << "j = " << j << '\n';
    }
  }
}

void merge_sort(std::vector<int> &v, int p, int q){
}
