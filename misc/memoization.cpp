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

  static std::map<int,int> memo;    // (key type, mapped type)
  
  if(n<=1)
    return n;
  if(memo.count(n)>0){
    return memo[n];
  }
  
  int ret = n*factorial_memo(n-1);
  memo[n]=ret;
  return ret;
  
}

int fib_memo(int n){

  static std::map<int,int> fib_map;
  
  if(n<=1)
    return n;
  if(fib_map.count(n)>0)
    return fib_map[n];
  int ret = fib_memo(n-1)+fib_memo(n-2);
  fib_map[n]=ret;
  return ret;

}

int fib(int n){

  if(n<=1)
    return n;
  return fib(n-1)+fib(n-2);

}

int main(int argc, char *argv[]){

  int opt = (int) *argv[1]-48;   // this 48 is great /s

  if(opt==0){

    std::clock_t t;

    int n = 12;
    t=clock();
    std::cout<< factorial_memo(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for memoized code: " << t << std::endl;

    t=clock();
    std::cout<< factorial_memo(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for second call of memoized code: " << t << std::endl;

    t=clock();
    std::cout<< factorial_memo(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for regular code: " << t << std::endl;

  }

  if(opt==1){

    std::clock_t t;
    
    int n=25;
    t=clock();
    std::cout << fib_memo(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for memo code: " << t << std::endl;

    n = 40;
    t=clock();
    std::cout << fib_memo(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for memo code #2: " << t << std::endl;

    t=clock();
    std::cout << fib(n) << std::endl;
    t=clock()-t;
    std::cout<< "Elapsed cycles for regular code: " << t << std::endl;
    

  }
  
  return 0;

}
