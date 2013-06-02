#include "LsMethod.h"

LsMethod::LsMethod()
{

}

LsMethod::~LsMethod()
{

}

bool LsMethod::msgHandle(std::string &fName, std::string &param)
{
	// what will this command do.
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
	std::cout << fName << " > ";
	std::vector<std::string> members = (*val).getMemberNames();
	for(std::vector<std::string>::iterator itr = members.begin(); itr != members.end(); ++itr)
		std::cout << *itr << "  ";
	std::cout << std::endl;
	return true;
}