#include<iostream>
#include<vector>

void merge(std::vector<int> &v, int p, int q, int r);
void merge_sort(std::vector<int> &v, int p, int r);

int main(){

  std::vector<int> v;
  v = {0,2,4,1,3,5,7};
  merge(v,0,2,6);

  for(int j=0; j<7; j++){
    std::cout << v[j] << '\n';
  }

}

void merge(std::vector<int> &v, int p, int q, int r){

  int n1 = q-p+1;
  int n2 = r-q;
  std::vector<int> L(n1+1,0); // initialize to a vector of zeros
  std::vector<int> R(n2+1,0);
  
  for(int j=0; j<n1; j++){
    L[j] = v[p+j+1];
  }

  for(int j=0; j<n2; j++){
    R[j] = v[q+j+1];
  }

  int i=0;
  int j=0;
  // need more logic here
  for(int k=p; k<r; k++){
    if(L[i] <= R[j]){   
      v[k] = L[i];
      i++;
    }
    else{
      v[k]=R[j];
      j++;
    }
  }
}

void merge_sort(std::vector<int> &v, int p, int q){
}
