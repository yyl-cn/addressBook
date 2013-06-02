#ifndef CATMETHOD_H
# define CATMETHOD_H
#include "Method.h"

class CatMethod:public CmdMethod
{
public:
	CatMethod();
	~CatMethod();
	bool msgHandle(std::string &fName, std::string &param);
};

#endif