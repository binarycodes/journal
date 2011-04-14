#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cerrno>


#include "datetime.h"

std::string trim(std::string);

int main(int argc, char **argv) {
		DateTime dt;

		std::string line;
		std::ofstream journalFile;

		// content is first appended here for checking empty contents etc.
		std::stringstream contents;
		
		std::stringstream filename;
		filename << std::getenv("HOME") << "/" << ".journal";
		
		journalFile.open(filename.str().c_str(), std::ios::app);
		
		if (! journalFile.is_open()) {
				std::cout << "cannot open file :: " << strerror(errno) << "\n";
				exit(1);
		}
		while (! std::cin.eof()) {
				std::getline(std::cin, line);
				contents << line <<"\n";
		}

		// remove beginning and trailing whitespaces with custom function
		std::string cc = trim(contents.str());

		// write to file only if content is not totally blank
		if (!cc.empty()) {
				journalFile << "++" << dt.getCurrentDateTime() << "++" << "\n";
				journalFile << cc << "\n";
				journalFile << std::string(80, '-') << "\n\n";
		}
		journalFile.close();
		return 0;
}


std::string trim(std::string str) {
		std::string whitespaces (" \t\f\v\n\r");
		size_t found;
		
		found = str.find_last_not_of(whitespaces);
		if (found != std::string::npos) {
				str.erase(found+1);
		} else {
				str.clear();
		}
		
		found = str.find_first_not_of(whitespaces);
		if (found != std::string::npos) {
				str.erase(0,found);
		} else {
				str.clear();
		}
		
		return str;
}
