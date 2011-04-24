#include <iostream>
#include <sstream>
#include <cstdlib>
#include <readline/readline.h>

#include "cinterface.h"

CInterface::CInterface()
	:prompt(">> ") {
}

std::string CInterface::getPrompt() {
	return prompt;
}

CInterface::~CInterface() {
}

std::string CInterface::getUserInput(const bool rl) {
	// content is first appended here
	std::stringstream contents;
	// rl refers to readline, if enabled (command line arg) use it, else fall
	// back to std::getline
	if (!rl) {
		std::string line;
		
		while (! std::cin.eof()) {
			std::cout << getPrompt();
			std::getline(std::cin, line);
			contents << line <<"\n";
		}
	} else {
		char *line = NULL;
		
		do {
			if (line !=NULL) {free(line);}
			line = readline(getPrompt().c_str());
			contents << line <<"\n";
		} while (line != NULL);
		free(line);
	}
	std::cout << "\n";
	return contents.str();
}
