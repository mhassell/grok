#include "ex1.h"
#include <iostream>
// definitions of the functions

int func1(int i){
	std::cout << "called function 1 " << std::endl;
	std::cout << "argument (int) i= " << i << std::endl;
	std::cout << "returns an int " << std::endl;
	return i;
}

char func2(char c){
	std::cout << "called function 2 " << std::endl;
	std::cout << "argument (char) c= " << c << std::endl;
	std::cout << "returns a char " << std::endl;
	return c;
}

float func3(float f){
	std::cout << "called function 3 " << std::endl;
	std::cout << "argument (float) f = " << f << std::endl;
	std::cout << "returns a float " << std::endl;
	return f;
}