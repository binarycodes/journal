#include <sstream>
#include <iostream>

#include "optionparser.h"

OptionParser::OptionParser(const int & ac, const char **&av, std::stringstream & ss)
 :general("General Options") {
	addOptionsToParser();
	ss << general << "\n";
	po::store(po::parse_command_line(ac, av, general), vm);
	po::notify(vm);
}


OptionParser::~OptionParser() {
}


void OptionParser::addOptionsToParser() {
	general.add_options()
		("help,h", "show help message")
		("readline,r", "use the GNU readline library")
		("append,a", po::value< std::vector <std::string> >(&linedata)->multitoken(), "append the rest of the arguments to the journal")
		;
}


const int OptionParser::processOptions(std::string & cc) {
	
	if (vm.count("help")) {
		std::cout << general << "\n";
		return 2;
	}
	
	if (vm.count("append")) {
		std::stringstream ss;
		for (unsigned int i=0; i < linedata.size(); i++) {
			ss << linedata[i] << " ";
		}
		ss << "\n";
		cc = ss.str();
		return 1;
	}
	return 0;
}

