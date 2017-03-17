
#include <iostream>

#define P(A) std::cout << #A << ": " << (A) <<std::endl;  // don't need parens around the A

int main(){
	int a = 1, b = 2, c = 3;
	P(a); P(b); P(c);
	P(a+b);
	P((a+b)/2);
}