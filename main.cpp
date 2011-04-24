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
#include "optionparser.h"


int main(const int argc, const char **argv) {
	CInterface ci;
	std::stringstream usage;
	std::string cc = "";
	
	try {
		OptionParser op(argc, argv, usage);
		
		int rval = op.processOptions(cc);
		
		if (rval == 0) {
			// fetch user input from the interfacing code9
			cc = ci.getUserInput(op.vm.count("readline"));
		} else if (rval == 2) {
			return 0;
		}
		
	} catch (po::error e) {
		std::cout << usage.str() << "\n";
		return 1;
	}
	
		
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
