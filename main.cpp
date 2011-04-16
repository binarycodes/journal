#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cerrno>


#include "datetime.h"
#include "journal.h"
#include "utility.h"


int main(int argc, char **argv) {
  DateTime dt;
  Journal journal;
  
  std::string line;
  
  // content is first appended here for checking empty contents etc.
  std::stringstream contents;
  
  while (! std::cin.eof()) {
	std::getline(std::cin, line);
	contents << line <<"\n";
  }
  
  // remove beginning and trailing whitespaces with custom function
  std::string cc = Utility::trim(contents.str());
  
  // write to file only if content is not totally blank
  if (!cc.empty()) {
	journal.takeNote(cc);
	journal.saveNote();
  }
  return 0;
}
