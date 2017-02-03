// playing with memoization 
// inspired by this http://programminggenin.blogspot.com/2013/01/memoization-in-c.html

#include<math.h>
#include<map>
#include<iostream>
#include<time.h>

int factorial(int n){
  if(n<=1)
    return n;
  else
    return n*factorial(n-1);
}

int factorial_memo(int n){

  static std::map<int,int> memo;    // (key type, mapped type)   (why static??)
  
  if(n<=1)
    return n;
  if(memo.count(n)>0){
    return memo[n];
  }
  
  int ret = n*factorial_memo(n-1);
  memo[n]=ret;
  return ret;
  
}

int main(){

  std::clock_t t1, t2;

  int n = 10;
  t1=clock();
  std::cout<< factorial_memo(n) << std::endl;
  t2=clock();
  std::cout<< "Elapsed cycles for memoized code: " << t2 << std::endl;

  t1=clock();
  std::cout<< factorial_memo(n) << std::endl;
  t2=clock();
  std::cout<< "Elapsed cycles for second call of memoized code: " << t2 << std::endl;

  t1=clock();
  std::cout<< factorial_memo(n) << std::endl;
  t2=clock();
  std::cout<< "Elapsed cycles for regular code: " << t2 << std::endl;
  
  return 0;

}
