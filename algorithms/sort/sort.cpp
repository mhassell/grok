// a collection of sort algorithms from CLRS

#include<vector>
#include<math.h>
#include "sort.h"

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

void merge_sort(std::vector<int> &v, int p, int r)
{
  if(p<r)
    {
      int q = floor((p+r)/2);
      merge_sort(v,p,q);
      merge_sort(v,q+1,r);
      merge(v,p,q,r);
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


