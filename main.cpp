#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cerrno>


#include "datetime.h"
#include "journal.h"
#include "utility.h"
#include "cinterface.h"


int main(int argc, char **argv) {
	CInterface ci;
	
	// fetch user input from the interfacing code
	std::string cc = ci.getUserInput();
  	// remove beginning and trailing whitespaces with custom function
	cc = Utility::trim(cc);
  
	// write to file only if content is not totally blank
	if (!cc.empty()) {
		Journal journal;
		journal.takeNote(cc);
		journal.saveNote();
	}
	return 0;
}
