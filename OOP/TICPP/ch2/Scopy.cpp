// Copy one file to another, one line at a time
// this copies the file to another file.

#include <string>
#include <fstream>

int main(){
	std::ifstream in ("Scopy.cpp");
	std::ofstream out ("Scopy2.cpp");
	std::string s;
	while(std::getline(in,s))   // this chucks the newline char
		out << s << "\n";  // add it back in
}