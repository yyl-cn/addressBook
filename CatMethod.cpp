#include "CatMethod.h"
//#include "CdMethod.h"

CatMethod::CatMethod()
{

}

CatMethod::~CatMethod()
{

}

bool CatMethod::msgHandle(std::string &fName, std::string &param)
{
	// what will this "cat" command do.

	std::string parameter = param.substr(param.find_first_of(32) + 1);
	Json::Value *catValue = NULL;
	if(CmdMethod::changedRoot != NULL)
		catValue = CmdMethod::changedRoot;
	else
	{
		if(CmdMethod::defaultRoot == NULL)
		{
			std::cout << "the JSON Value is not initialized!" << std::endl;
			return true;
		}
		catValue = CmdMethod::defaultRoot;
	}
	std::vector<std::string> members = (*catValue).getMemberNames();
	std::vector<std::string>::iterator itr = members.begin();
	for(; itr != members.end(); ++itr)
	{
		if(*itr == parameter)
			break;
	}
	if(itr != members.end())
	{
		std::cout << fName << " > \"" << parameter << "\" : ";
		Json::FastWriter fastwriter;
		std::cout << fastwriter.write((*catValue)[parameter]);
	}
	else
	{
		std::cout <<std::endl << "this JSON value does not exist in this directory!" << std::endl;
	}
	return true;
}