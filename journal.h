#ifndef _JOURNAL_H
#define _JOURNAL_H

#include <iostream>
#include <sstream>
#include <fstream>

#include "note.h"


class Journal {
 public:
  Journal();
  ~Journal();
  
  void takeNote(const std::string);
  void saveNote(const std::string);
  
 private:
  bool openFile();

  std::ofstream journalFile;
  std::stringstream filename;
  Note *note;
};

#endif
