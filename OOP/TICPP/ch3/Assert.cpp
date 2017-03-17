// using assert statements

#define NDEBUG   	// disables the call to assert
#include <cassert>

int main(){
	int i = 100;
	assert(i!=100); // interesting, don't need std::assert here
}