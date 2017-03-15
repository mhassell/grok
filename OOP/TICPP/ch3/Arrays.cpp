// arrays, a structure after my own heart!

#include <iostream>

int main(){
	int a[10];
	for(int i = 0; i < 10; i++){
		a[i] = i*10;
		std::cout << "a[" << i << "] = " << a[i] << std::endl; 
	}
}