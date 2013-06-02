#ifndef ADDMETHOD_H
# define ADDMETHOD_H
#include "Method.h"

class AddMethod:public CmdMethod
{
public:
	AddMethod();
	~AddMethod();
	bool msgHandle(std::string &fName, std::string &param);
};

#endif