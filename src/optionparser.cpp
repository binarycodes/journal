#include <sstream>
#include <iostream>

#include "optionparser.h"

OptionParser::OptionParser(const int & ac, const char **&av,
		std::stringstream & ss) :
		general("General Options") {
	addOptionsToParser();
	ss << general << "\n";
	po::store(po::parse_command_line(ac, av, general), vm);
	po::notify(vm);
}

OptionParser::~OptionParser() {
}

// setup and configure parameter types for command line options
void OptionParser::addOptionsToParser() {
	general.add_options()("help,h", "show help message")("readline,r",
			"use the GNU readline library")("datefmt,d",
			po::value<std::string>(&dateformat),
			"specify dateformat as per strftime specs, default is %d/%m/%Y-%H:%M:%S")(
			"append,a",
			po::value<std::vector<std::string> >(&linedata)->multitoken(),
			"append the rest of the arguments to the journal");
}

const int OptionParser::processOptions(options_map & data) {

	if (vm.count("help")) {
		return 2;
	}

	if (vm.count("readline")) {
		data["r"] = "yes";
	}

	if (vm.count("append")) {
		std::stringstream ss;
		for (unsigned int i = 0; i < linedata.size(); i++) {
			ss << linedata[i] << " ";
		}
		ss << "\n";
		data["a"] = ss.str();
	}

	if (vm.count("datefmt")) {
		data["d"] = dateformat;
	}

	return 0;
}
