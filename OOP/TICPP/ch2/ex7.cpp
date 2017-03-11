// exercise 7 - print a file line by line, and wait for the user to press enter between prints

#include <fstream>
#include <vector>
#include <stdlib.h> 
#include <string>
#include <iostream>

int main(int argc, char* argv[]){

	std::ifstream file(argv[1]);
	std::vector<std::string> lines;
	std::string line;
	while(std::getline(file,line)){

		std::cout << line <<std::endl;
		std::system("read");  // how do I get rid of the newlines?

	}
}