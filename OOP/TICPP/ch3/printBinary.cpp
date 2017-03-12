// print a byte in binary format

#include <iostream>

void printBinary(const unsigned char val){
	for(int i=7; i>=0; i--)
		if(val&(1 << i))		// for the powers of 2 from zero to seven, determine if it divides our number
			std::cout << "1";
		else
			std::cout<< "0";
}