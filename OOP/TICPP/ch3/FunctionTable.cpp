// using an array of pointers to functions
 
#include <iostream>

// a macro to define dummy functions
#define DF(N) void N() {\
	std::cout << "function "  #N " called..." << std::endl; }

// this needs some unpacking...
DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);
void (*func_table[])() = {a,b,c,d,e,f,g};

int main(){
	// char test = 'a';
	// std:: cout << "value of the character a is " << (int) test << std::endl;
	while(1){
		std::cout<< "press a key from 'a' to 'g' or 'q' to quit " << std::endl;
		char c, cr;
		std::cin.get(c); std::cin.get(cr);  // cr catches the carriage return when you press enter
 		if(c=='q')
			break;
		if(c<'a'|| c>'g')
			continue;
		// std::cout << (int) c - 'a' << std::endl;  // this prints our distance from the start of the array
		(*func_table[c-'a'])(); 	// what is c-'a' doing?? we segfault without it (see below)
	}
}

// http://ee.hawaii.edu/~tep/EE160/Book/chap4/subsection2.1.1.2.html

// making another script to test an idea

/* 
void (*func_table[])() = {a,b,c,d,e,f,g}; 

Let's think about this declaration (& initialization)

Inside out rule:
	func_table is a pointer an array of functions that take no arguments and return void
	
*/ 

/*
Comment on the array indexing: the call (*func_table[c-'a'])() is looking up the index of
the character c in the array - subtracting a centers us at zero (because chars are also integers
in ascii) so by subtracting a, we start from zero)
*/