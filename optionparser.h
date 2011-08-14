#ifndef _OPTIONPARSER_H
#define _OPTIONPARSER_H

#include <boost/program_options.hpp>
#include <iostream>

#include "utility.h"

namespace po = boost::program_options;

class OptionParser {

public:
	OptionParser(const int &, const char **&, std::stringstream &);
	~OptionParser();
	
	const int processOptions(options_map &);
	
	po::variables_map vm;
	po::options_description general;
	
private:
	void addOptionsToParser();
	
	std::vector<std::string> linedata;
	std::string dateformat;
};


#endif
