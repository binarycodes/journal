#include <ctime>
#include <iostream>
#include <cstring>

#include "datetime.h"


DateTime::DateTime() {
    time(&rawtime);
	timeinfo = localtime(&rawtime);
}

std::string DateTime::getCurrentDateTime(const std::string dateformat) {
		char ts[50];
		strftime(ts,200,dateformat.c_str(),timeinfo);
		std::string timeString(ts);
		return timeString;
}
