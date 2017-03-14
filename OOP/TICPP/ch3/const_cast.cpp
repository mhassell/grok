// using const_cast

#include <iostream>

int main(){
	// i is constant, cannot be changed
	const int i = 0;
	int *j = (int*) &i;   // old way

	// j now holds the same value of i, but it is not constant
	j = const_cast<int*>(&i); // preferred

	// won't work:
	// long* l = const_cast<long*>(&i);  
	volatile int k  = 0;
	int *u = const_cast<int*>(&k);

	// hm...
	(*j)+=1;
	std::cout << "i = " << i << std::endl;
	std::cout << "j = " << *j << std::endl;
}