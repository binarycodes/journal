#include <iostream>
#include <sstream>
#include <fstream>

class Journal {

public:
		Journal();
		~Journal();

		bool openFile();
		std::ofstream& file();

private:
		std::ofstream journalFile;
		std::stringstream filename;
};
