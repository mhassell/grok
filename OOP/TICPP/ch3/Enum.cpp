// using enums

#include <iostream>

enum ShapeType{

	circle,
	square,
	rectangle      // no semicolon or anything
};

int main(){
	ShapeType shape = circle;
	// do stuff
	switch(shape){
		case circle:
			// circle stuff
			break;
		case square:
			// square stuff
			break;
		case rectangle:
			// rectangle
			break;
		default:
			break;
			// if none of the above
	}

	// I wonder if switch statements work in other ways:
	char grade = 'B';
	switch(grade){
		case 'A':
			std::cout << "Excellent" << std::endl;
			break;
		case 'B':
			std::cout << "Not bad" << std::endl;
			break;
		case 'C':
			std::cout << "Satisfactory" << std::endl;
			break;
		default:
			std::cout << "Unsatisfactory" << std::endl;
			break;
	}

	// enums just map the values to ints: 0, 1, and so on

	enum snap {crackle = 25, pop};
	snap test = pop;
	switch(test){
		case crackle:
			std::cout << crackle << std::endl;
		case pop:
			std::cout << pop << std::endl;   // careful! compiler just adds one to crackle
		}

}