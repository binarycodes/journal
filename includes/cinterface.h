#ifndef _CINTERFACE_H
#define _CINTERFACE_H

class CInterface {
public:
	CInterface();
	~CInterface();
	
	std::string getUserInput(const bool);
private:
	std::string prompt;

	std::string getPrompt();
};

#endif
