// trying to grok some of the syntax for typedefs

#include <iostream>

// just a vanilla struct 
struct basicStruct{
	int i;
	char c;
};

// typedef a struct
typedef struct {
	int i;
	char c;
} newStruct;

int main(){

	// vanilla stuff
	struct basicStruct a;
	a.i = 1;
	a.c = 'A';
	std::cout << "a.i = " << a.i << std::endl;
	std::cout << "a.c = " << a.c << std::endl;

	// typedef'd
	newStruct b;
	b.i = 2;
	b.c = 'b';
	std::cout << "b.i = " << b.i << std::endl;
	std::cout << "b.c = " << b.c << std::endl;

}