#include <iostream>

#include "datetime.h"
#include "note.h"

Note::Note(std::string str):
  data(str) {
  dt = new DateTime();
}

Note::~Note() {
  if (dt != NULL) {
	delete dt;
  }
}


std::string Note::timestamp() {
  return dt->getCurrentDateTime();
}

std::string Note::content() {
  return data;
}
