// this is dumb, I'm sorry
// ripped from http://en.cppreference.com/w/cpp/container/map/find

#include <iostream>
#include <map>
#include <typeinfo>
 
int main()
{  
    std::map<int,char> example = {{1,'a'},{2,'b'},{1,'c'}};
 
    auto search = example.find(2);      // using auto keyword (can this be avoided?)
    std::map<int,char>::iterator search2 = example.find(1); // ... this isn't worth it

    if(search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
	// std::cout << typeid(search).name() << std::endl;
	std::cout << "Found " << search2->first << " " <<  search2->second << std:: endl;
	search2++;
	std::cout << "Also " << search2->first << " " << search2->second << std::endl; 
	// why not 1 c? (evidently we need multimap from boost for this)
    }
    else {
        std::cout << "Not found\n";
    }
}
