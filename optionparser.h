#ifndef _OPTIONPARSER_H
#define _OPTIONPARSER_H

#include <boost/program_options.hpp>
#include <boost/unordered_map.hpp>
#include <iostream>

namespace po = boost::program_options;
typedef boost::unordered_map<std::string, std::string> options_map;


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
