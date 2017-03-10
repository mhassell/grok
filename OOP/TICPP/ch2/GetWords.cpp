// break a file into whitespace separated words

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main(){
	std::vector<std::string> words;
	std::ifstream in("GetWords.cpp");
	std::string word;
	while(in>>word)
		words.push_back(word);
	for(int i=0; i<words.size(); i++)
		std::cout<< words[i] << std::endl;
}