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

// typedef a struct with a (tag?)
typedef struct newStruct2{
	int i;
	char c;
} newStruct2;

// a deluxe struct
typedef struct newStruct3{
	int i;
	char c;
	newStruct3* p;
} newStruct3;

/* 
// a non-example (the compiler fails)
typedef struct{
	int i;
	char c;
	newStruct4* p;
} newStruct4;
*/

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

	// deluxe typedef'd
	newStruct2 c;
	c.i = 3;
	c.c = 'c'; //hwut
	std::cout << "c.i = " << c.i << std::endl;
	std::cout << "c.c = " << c.c << std::endl;

	// deluxe structures
	newStruct3 d, e;
	d.i = 4;
	d.c = 'd';
	d.p = &e;

	e.i = 5;
	e.c = 'e';
	e.p = &d;

	std::cout << "d.i = " << d.i << std::endl;
	std::cout << "d.c = " << d.c << std::endl;
	std::cout << "d.p = " << d.p << std::endl;

	std::cout << "e.i = " << e.i << std::endl;
	std::cout << "e.c = " << e.c << std::endl;
	std::cout << "e.p = " << e.p << std::endl;

	//hmmm, let's break things
	std::cout << "e.p->i = " << e.p->i << std::endl;
	e.p->i+=12;
	std::cout << "e.p->i+=12 = " << e.p->i << std::endl;




}