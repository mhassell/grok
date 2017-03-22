// test the cpp library we just made

// not using the "require" library for error checking

#include "CppLib.h"
#include <fstream>
#include <iostream>
#include <string>

int main(){
	Stash intStash;
	intStash.initialize(sizeof(int));

	for(int i = 0; i<100; i++){
		intStash.add(&i);
	}

	for(int j=0; j<intStash.count(); j++){
		std::cout << "intStash.fetch(" << j << ")= " << *(int*)intStash.fetch(j) << std::endl;
	}

	intStash.cleanup();
}