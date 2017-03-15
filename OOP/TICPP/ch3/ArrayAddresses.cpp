// arrays are stored contiguously in memory

#include <iostream>

int main(){

	int a[10];
	int b[10];
	std::cout << "size of an int = " << sizeof(int) << std::endl;
	for(int i = 0; i<10; i++){
		std::cout << "&a[" << i << "]=" << (long) &a[i] <<std::endl;
	}
	// interesting! all 4 bytes away from each other

	//hmmm...
	std::cout << "&b[" << 0 << "]=" << (long) &b[0] <<std::endl;
	// not necessarily stored contiguously in memory with a[]  (run several times to see this)
}