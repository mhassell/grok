// third exercise - open a file and count the whitespace separated words

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

	std::ifstream fin(argv[1]);
	std::string word;
	int wc = 0;
	while(fin >> word)  // reads in whitespace separated words
		wc++;

	std::cout << "Number of words: " << wc << std::endl;

}