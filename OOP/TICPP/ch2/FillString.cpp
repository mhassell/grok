// read an entire file into a string (the string dynamically resizes)

#include <fstream>
#include <string>
#include <iostream>

int main(){
	std::ifstream in ("FillString.cpp");
	std::string s, line;
	while(std::getline(in, line))  // this reads line by line, but removes the \n char
		s+=line + "\n";
	std::cout << s << std::endl;
}