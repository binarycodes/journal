#ifndef _OPTIONPARSER_H
#define _OPTIONPARSER_H

#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

class OptionParser {

public:
	OptionParser(const int &, const char **&, std::stringstream &);
	~OptionParser();
	
	const int processOptions(std::string &);
	
	po::variables_map vm;
	po::options_description general;
	
private:
	std::vector<std::string> linedata;
	void addOptionsToParser();
};


#endif
