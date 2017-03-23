// a simple header file that prevents re-definition
// re-definition is verboten and would otherwise throw an error

#ifndef SIMPLE_H
#define SIMPLE_H

struct Simple{
	int i,j,k;
	initialize() {i = j = k = 0};  // holy cow you can do this!
};

#endif