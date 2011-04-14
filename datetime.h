#include <ctime>

class DateTime {
		time_t rawtime;
		struct tm *timeinfo;
public:
		DateTime();
		std::string getCurrentDateTime();
};

