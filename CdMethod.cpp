#include "CdMethod.h"

CdMethod::CdMethod()
{

}

CdMethod::~CdMethod()
{

}

bool CdMethod::msgHandle(std::string &fName, std::string &param)
{
	// what will this "cd" command do.
	std::string parameter = param.substr(param.find_last_of(' ') +1);
	if(parameter == "~")
	{
		if(CmdMethod::changedRoot != NULL)
			changedRoot = NULL;
		return true;
	}
	Json::Value *val = NULL;
	if(CmdMethod::changedRoot != NULL)
		val = CmdMethod::changedRoot;
	else
	{
		if(CmdMethod::defaultRoot == NULL)
		{
			std::cout << "the JSON Value is not initialized!" << std::endl;
			return true;
		}
		val = CmdMethod::defaultRoot;
	}
	std::vector<std::string> members = val->getMemberNames();
	std::vector<std::string>::iterator itr;
	for(itr = members.begin(); itr != members.end(); ++itr)
	{
		if(parameter == *itr)
			break;
	}
	if(itr != members.end())
		CmdMethod::changedRoot = &(*val)[parameter];
	else
		std::cout << fName << " > input parameter is not a JSON value!" << std::endl;
	return true;
}