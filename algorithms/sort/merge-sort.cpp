#include<iostream>
#include<vector>
#include<math.h>

void merge(std::vector<int> &v, int p, int q, int r);
void merge_sort(std::vector<int> &v, int p, int r);

int main(){

  std::vector<int> v;

  v = {0,2,4,1,3,5,7};
  merge_sort(v,0,v.size());

  for(int j=0; j<v.size(); j++){
    std::cout << v[j] << '\n';
  }

  return 0;

}

void merge(std::vector<int> &v, int p, int q, int r){

  int n1 = q-p+1;
  int n2 = r-q;

  std::vector<int> L(n1,0); // initialize to a vector of zeros
  std::vector<int> R(n2,0);
  
  for(int j=0; j<n1; j++){
    L[j] = v[p+j];
  }

  for(int j=0; j<n2; j++){
    R[j] = v[q+j+1];
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
      }
    }
    else if(i==n1 & j<n2){  // emptied L out
      v[k]=R[j];
      j++;
    }
    else if(i<n1 & j==n2){  // emptied R out
      v[k]=L[i];
      i++;
    }
  }
}

void merge_sort(std::vector<int> &v, int p, int r){

  if(p<r){
      int q = floor((p+r)/2);
      merge_sort(v,p,q);
      merge_sort(v,q+1,r);
      merge(v,p,q,r);
    }

}
