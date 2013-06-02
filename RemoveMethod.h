#ifndef REMOVEMETHOD_H
# define REMOVEMETHOD_H
#include "Method.h"

class RemoveMethod:public CmdMethod
{
public:
	RemoveMethod();
	~RemoveMethod();
	bool msgHandle(std::string &fName, std::string &param);
};

#endif