// a union is like a compound variable - it decides how much memory you need
// based on the largest possible variable in the union

#include <iostream>

union Packed{
	int i;
	short j;
	int k;
	float f;
	double d;
};

int main(){
	std::cout << "Sizeof packed = " << sizeof(Packed) << std::endl;

	Packed x;

	x.i = 'c';
	std::cout << x.i << std::endl;
	x.d = 3.14;
	std::cout << x.d << std::endl;
	
	// this is garbage (no type checking)
	std::cout << x.i << std::endl;

}