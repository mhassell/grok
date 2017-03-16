#include <iostream>
#include <string>

bool debug = false;

int main(int argc, char* argv[]){

	for(int i = 0; i< argc; i++){
		if(std::string(argv[i]) == "--debug=on")
			debug = true;
		bool go = true;
		while(go){
			if(debug){
				// debugging code here
				std::cout << "debugger is now on " << std::endl;
			}
			else{
				std::cout << "debugger is now off " << std::endl;
			}
			std::cout << "Turn debug [on/off/quit]" << std::endl;
			std::string reply;

			std::cin >> reply;
			if(reply == "on") debug = true;
			if(reply == "false") debug = false;
			if(reply == "quit") break;

		}
	}

}