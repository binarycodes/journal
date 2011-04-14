#include <ctime>
#include <iostream>
#include <cstring>

#include "datetime.h"


DateTime::DateTime() {
    time(&rawtime);
}

std::string DateTime::getCurrentDateTime() {
		std::string timeString = ctime(&rawtime);
		// ctime appends a newline at the end which is being stripped here
		timeString.erase(timeString.length()-1);
		return timeString;
}

