#ifndef LSMETHOD_H
# define LSMETHOD_H
#include "Method.h"

class LsMethod:public CmdMethod
{
public:
	LsMethod();
	~LsMethod();
	bool msgHandle(std::string &fName, std::string &param);
};

#endif