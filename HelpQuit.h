#ifndef HELPQUITMETHOD_H
# define HELPQUITMETHOD_H
#include "Method.h"
#include <fstream>

class HelpQuit:public CmdMethod
{
public:
	HelpQuit();
	~HelpQuit();
	bool msgHandle(std::string &fName, std::string &param);
private:
	void helpHandle();
	void quitHandle();
};

#endif