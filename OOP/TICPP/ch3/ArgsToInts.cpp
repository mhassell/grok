// converting command line arguments

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){

	for(int i = 1; i<argc; i++){
		std::cout << "atoi(argv[" << i << "])= " << atoi(argv[i]) << std::endl;
	}
	// let's try something
	/*
	for(int i = 0; i < argc; i++){
		std::cout << "(int) argv[" << i << "]= " << (int) argv[i] << std::endl; // doesn't work
	}
	*/

}