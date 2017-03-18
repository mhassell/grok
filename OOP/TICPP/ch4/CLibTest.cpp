#include "CLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

int main(){
	CStash intStash, stringStash;
	int i;
	char *cp;
	std::ifstream in;
	std::string line;
	const int bufsize = 80;

	initialize(&intStash, sizeof(int));
	for(i=0; i<count(&intStash); i++){
		add(&intStash, &i);
	}
	for(i=0; i<count(&intStash); i++){
		std::cout << "fetch(&intStash," << i << ") = " \
			<< *(int *)fetch(&intStash, i) \
			<< std::endl;

	}
	cleanup(&intStash);
}