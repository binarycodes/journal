#ifndef _DATETIME_H
#define _DATETIME_H

#include <ctime>

class DateTime {
		time_t rawtime;
		struct tm *timeinfo;
public:
		DateTime();
		std::string getCurrentDateTime();
};


#endif
