#include <ctime>

class DateTime {
		time_t rawtime;
public:
		DateTime();
		std::string getCurrentDateTime();
};

