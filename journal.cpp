#include <cerrno>
#include <cstring>
#include <cstdlib>

#include "journal.h"
#include "note.h"

Journal::Journal() {
		filename << std::getenv("XDG_DATA_HOME") << "/" << "journal";
		note = NULL;
}

void Journal::takeNote(const std::string str) {
  note = new Note(str);
}

void Journal::saveNote() {
  if (note != NULL) {
	openFile();
	journalFile << ">> " << note->timestamp() << "\n\n";
	journalFile << note->content() << "\n";
	journalFile << std::string(80, '-') << "\n\n";
	journalFile.close();
  }
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


Journal::~Journal() {
  if (journalFile.is_open()) {
	journalFile.close();
  }
  if (note != NULL) {
	delete note;
  }
}
