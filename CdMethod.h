#ifndef CDMETHOD_H
# define CDMETHOD_H
#include "Method.h"

class CdMethod:public CmdMethod
{
public:
	CdMethod();
	~CdMethod();
	bool msgHandle(std::string &fName, std::string &param);
};

#endif