#include <iostream>
#include <sstream>

#include "cinterface.h"

CInterface::CInterface() {
	prompt = ">> ";
}

std::string CInterface::getPrompt() {
	return prompt;
}

CInterface::~CInterface() {
}

std::string CInterface::getUserInput() {
	// content is first appended here for checking empty contents etc.
	std::stringstream contents;
	std::string line;

	while (! std::cin.eof()) {
		std::cout << getPrompt();
		std::getline(std::cin, line);
		contents << line <<"\n";
	}
	std::cout << "\n";
	return contents.str();
}
