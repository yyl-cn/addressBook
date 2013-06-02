#include "Method.h"

CmdMethod::CmdMethod()
{
}

bool CmdMethod::msgHandle(std::string &fName, std::string &param)
{
	return false;
}



Json::Value *CmdMethod::defaultRoot = NULL;
Json::Value *CmdMethod::changedRoot = NULL;