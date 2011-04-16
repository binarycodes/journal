#ifndef _NOTE_H
#define _NOTE_H

#include "datetime.h"


class Note {
 private:
  DateTime *dt;
  std::string data;

 public:
  Note(std::string);
  ~Note();

  std::string timestamp();
  std::string content();  
};

#endif
