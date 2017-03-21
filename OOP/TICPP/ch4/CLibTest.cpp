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
	std::cout << count(&intStash) << std::endl;
	for(i=0; i<100; i++){
		add(&intStash, &i);
	}

	for(i=0; i<count(&intStash); i++){
		std::cout << "fetch(&intStash," << i << ") = " \
			<< *(int *)fetch(&intStash, i) \
			<< std::endl;

	}
	
	// holds 80-char strings (defined up above)
	initialize(&stringStash, sizeof(char)*bufsize);
	in.open("CLibTest.cpp");
	assert(in);
	while(getline(in,line))
		add(&stringStash,line.c_str());
	i = 0;
	while((cp=(char*)fetch(&stringStash,i++))!=0)
		std::cout<< "fetch(&stringStash, " << i << ")= " << cp << std::endl;

	cleanup(&intStash);
	cleanup(&stringStash);
}