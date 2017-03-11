// some thoughts on static and extern variables

#include <iostream>

void static_fun();
void extern_fun();

extern int n;   // this doesn't declare n, just tells the linker it is declared somewhere

int main(){

	int n = 3;

	for(int i=0; i<4; i++)
		static_fun();

	extern_fun();

	// this won't work if we comment out the definition of n above (n is not in scope, it only has the function scope?)
	std::cout << "The value of the extern variable within main is ";
	std::cout << n << std::endl;

}

void static_fun(){

	// hmmm...
	static int m = 1;
	std::cout << "The value of the static variable is ";
	std::cout << m++ << std::endl;

}

void extern_fun(){

	int n = 3;
	n++;
	std::cout << "The value of the extern variable in the function is ";
	std::cout << n << std::endl;

}