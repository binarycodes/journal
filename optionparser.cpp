#include <sstream>
#include <iostream>

#include "optionparser.h"

OptionParser::OptionParser(const int & ac, const char **&av)
 :general("General Options") {
	addOptionsToParser();
	po::store(po::parse_command_line(ac, av, general), vm);
	po::notify(vm);
}


OptionParser::~OptionParser() {
}


void OptionParser::addOptionsToParser() {
	general.add_options()
		("help,h", "show help message")
		("version,v", "show the version")
		("append,a", po::value< std::vector <std::string> >(&linedata)->multitoken(), "append the rest of the arguments to the journal")
		;
}


const int OptionParser::processOptions(std::string & cc) {
	
	int i=showHelp();
	if (i==2) {return i;}
	
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


const int OptionParser::showHelp() {
	if (vm.count("help")) {
		std::cout << general << "\n";
		return 2;
	}
	return 0;
}
