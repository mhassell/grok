// bit manipulation

// don't forget to include printBinary.cpp in the compiler!

#include "printBinary.h"
#include <iostream>

// hmmm.... when should we use macros over functions?
#define PRINT(STR,EXPR) \
	std::cout << STR; printBinary(EXPR); std::cout << std::endl; 

int main(){

	unsigned int getval;
	unsigned char a, b;

	std::cout << "Enter a number between 0 and 255: ";
	std::cin >> getval; a = getval;
	PRINT("a in binary ", a);

	std::cout << "Enter another number between 0 and 255: ";
	std::cin >> getval; b = getval;

	PRINT("b in binary ", b);
	PRINT("a | b = ", a | b);
	PRINT("a & b = ", a & b);
	PRINT("a ^ b = ", a ^ b);
	PRINT("~a = ", ~a);
	PRINT("~b = ", ~b);

	// an interesting bit pattern
	unsigned char c = 0x5A;
	PRINT("c in binary ", c);
	a |= c;
	PRINT("a |= c; a = ", a);
	b &= c;
	PRINT("b &=c; b = ", b);
	b ^= a; 
	PRINT("b ^= a; b = ", b);
}