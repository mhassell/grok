#include <string>
#include <iostream>

int main(){
	std::string s1, s2;
	std::string s3 = "Hello world";
	std::string s4("I am"); // interesting
	s2 = "Today";
	s1 = s3 + " " + s4;
	s1 += " 8 ";
	std::cout << s1 + s2 + "!" << std::endl;
}