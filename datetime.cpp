#include <ctime>
#include <iostream>
#include <cstring>

#include "datetime.h"


DateTime::DateTime() {
    time(&rawtime);
	timeinfo = localtime(&rawtime);
}

std::string DateTime::getCurrentDateTime() {
		char ts[30];
		strftime(ts,200,"%d/%m/%Y @ %H:%M:%S",timeinfo);
		std::string timeString(ts);
		return timeString;
}

