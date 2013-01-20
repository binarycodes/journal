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

	std::stringstream usage;
	std::string cc = "";

	// hash map for fetching options data
	options_map op_data;

	try {
		// process command line arguments and 'usage' should contain
		// the usage message.
		OptionParser op(argc, argv, usage);

		int rval = op.processOptions(op_data);

		if (rval == 0) {
			// fetch user input from the interfacing code
			CInterface ci;

			// yes means load readline support
			cc = ci.getUserInput(op_data["r"] == "yes");
		} else if (rval == 2) {
			std::cout << usage.str();
			return 0;
		}

	} catch (po::error & e) {
		std::cout << "Invalid options passed ...\n";
		std::cout << usage.str();
		return 1;
	}

	// add data meant to be appended to the beginning
	cc = op_data["a"] + "\n" + cc;

	// remove beginning and trailing whitespaces with custom function
	cc = Utility::trim(cc);

	// write to file only if content is not totally blank
	if (!cc.empty()) {
		Journal journal;
		journal.takeNote(cc);

		std::string dateformat = op_data["d"];
		if (dateformat.begin() == dateformat.end()) {
			dateformat = "%d/%m/%Y-%H:%M:%S";
		}

		journal.saveNote(dateformat);
	}

	return 0;
}
