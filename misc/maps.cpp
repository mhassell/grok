// this is dumb, I'm sorry
// ripped from http://en.cppreference.com/w/cpp/container/map/find

#include <iostream>
#include <map>
#include <typeinfo>
#include <vector>

int main(int argc, char *argv[])
{  
    std::map<int,char> example = {{1,'a'},{2,'b'},{1,'c'}};
    std::multimap<int,char> example2 = {{1,'a'},{2,'b'},{1,'c'}};
 
    auto search = example.find(2);      // using auto keyword (can this be avoided?)
    std::map<int,char>::iterator search2 = example.find(1); // ... this isn't worth it
    auto search3 = example2.find(1);

    // let's try to break this now
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {4,5,6};
    std::vector<int> c = {7,8,9};
    std::map<int, std::vector<int>> vec = {{1,a},{2,b},{3,c}};

    //hmmmm....
    std::cout << typeid(vec).name() << std::endl;
    std::cout << typeid(vec[1]).name() << std::endl;
    std::cout << vec[2][0] << std::endl;  // interesting!

      if(search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
	// std::cout << typeid(search).name() << std::endl;
	std::cout << "Found " << search2->first << " " <<  search2->second << std:: endl;
	search2++;
	std::cout << "Also " << search2->first << " " << search2->second << std::endl; 
	// why not 1 c? (evidently we need multimap for this?)

	std::cout << "Trying again... " << search3->first << search3->second << std::endl;
	search3++;
	std::cout << " and again ... " << search3->first << search3->second << std::endl;
      }
      else {
        std::cout << "Not found\n";
      }
}
