// really digging into the last example
 
#include <iostream>

/*
#define DF(N) void N() {\
	std::cout << "function "  #N " called..." << std::endl; }

// the DF macro is expanded by the preprocessor to make void functions a - g
DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);
*/

// this is the same as
void a() { std::cout << "function a called..." << std::endl; }
void b() { std::cout << "function b called..." << std::endl; }
void c() { std::cout << "function c called..." << std::endl; }
void d() { std::cout << "function d called..." << std::endl; }
void e() { std::cout << "function e called..." << std::endl; }
void f() { std::cout << "function f called..." << std::endl; }
void g() { std::cout << "function g called..." << std::endl; }

void (*func_table[])() = {a,b,c,d,e,f,g};

int main(){
	// char test = 'a';
	// std:: cout << "value of the character a is " << (int) test << std::endl;
	while(1){
		std::cout<< "press a key from 'a' to 'g' or 'q' to quit " << std::endl;
		char c, cr;
		std::cin.get(c); std::cin.get(cr);  // cr catches the return that is read in when you press enter
 		if(c=='q')
			break;
		if(c<'a'|| c>'g')
			continue;
		(*func_table[c-'a'])();
	}
}