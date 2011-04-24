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
	DateTime dt;
	Journal journal;
	CInterface ci;
	
  	// remove beginning and trailing whitespaces with custom function
	std::string cc = Utility::trim(ci.getUserInput());
  
	// write to file only if content is not totally blank
	if (!cc.empty()) {
		journal.takeNote(cc);
		journal.saveNote();
	}
	return 0;
}
