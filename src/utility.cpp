#include <iostream>
#include "utility.h"

std::string Utility::trim(std::string str) {
	std::string whitespaces(" \t\f\v\n\r");
	size_t found;

	found = str.find_last_not_of(whitespaces);
	if (found != std::string::npos) {
		str.erase(found + 1);
	} else {
		str.clear();
	}

	found = str.find_first_not_of(whitespaces);
	if (found != std::string::npos) {
		str.erase(0, found);
	} else {
		str.clear();
	}

	return str;
}
