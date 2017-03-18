#include "ex1.h"

#include <iostream>

int main(){

	int i = 7;
	float f = 6.0;
	char c = 'B';

	int j = func1(i);
	char d = func2(c);
	float g = func3(f);

	std::cout << "j = " << j << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "g = " << g << std::endl;

}