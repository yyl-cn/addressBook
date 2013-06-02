#include "RemoveMethod.h"
//#include "CdMethod.h"

RemoveMethod::RemoveMethod()
{

}

RemoveMethod::~RemoveMethod()
{

}

bool RemoveMethod::msgHandle(std::string &fName, std::string &param)
{
	// what will this "remove" command do.
	
	std::cout << "please give the key: ";
	std::string inputKey;
	std::getline(std::cin, inputKey,'\n');
	Json::Value *removeValue = NULL;
	if(CmdMethod::changedRoot != NULL)
		removeValue = CmdMethod::changedRoot;
	else
		removeValue = CmdMethod::defaultRoot;
	std::vector<std::string> members = (*removeValue).getMemberNames();
	std::vector<std::string>::iterator itr = members.begin();
	for(; itr != members.end(); ++itr)
	{
		if(*itr == inputKey)
			break;
	}
	if(itr != members.end())
	{
		(*removeValue).removeMember(inputKey);
		std::cout << inputKey << " was deleted from JSON" << '\n';
	}
	else
	{
		std::cout <<std::endl << "ERROR: trying to delete an non-existed key!" << '\n';
	}
	return true;
}
