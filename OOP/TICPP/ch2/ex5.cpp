// exercise 5 - read in a file line by line, and then print it reversed

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]){
	std::vector<std::string> v;
	if(argc != 2){ // first argument is the name of the program
		std::cout << "Please enter one file to reverse " << std::endl;
		return 0;
	}
	std::ifstream in(argv[1]);
	std::string line;
	while(std::getline(in,line))
		v.push_back(line);
	for(int i=v.size(); i>0; i--)
		std::cout << i << ": " << v[i] << std::endl;

	return 0;
}