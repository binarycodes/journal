#include <cerrno>
#include <cstring>
#include <cstdlib>

#include "journal.h"

Journal::Journal() {
		filename << std::getenv("XDG_DATA_HOME") << "/" << "journal";
}

bool Journal::openFile() {
		journalFile.open(filename.str().c_str(), std::ios::app);
		if (! journalFile.is_open()) {
				std::cout << "cannot open file :: " << strerror(errno) << "\n";
				return false;
		} else {
				return true;
		}
}

std::ofstream& Journal::file() {
		return journalFile;
}

Journal::~Journal() {
		if (journalFile.is_open()) {
				journalFile.close();
		}
}
