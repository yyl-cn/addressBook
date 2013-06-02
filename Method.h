#ifndef METHOD_H
# define METHOD_H

#include <string>
#include "json/json.h"

class CmdMethod
{
public:
	CmdMethod();
	//virtual ~CmdMethod();
	virtual bool msgHandle(std::string &fName, std::string &param);
	static Json::Value *defaultRoot;
	static Json::Value *changedRoot;
};


#endif
