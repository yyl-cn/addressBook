#include "AddMethod.h"
//#include "CdMethod.h"

AddMethod::AddMethod()
{

}

AddMethod::~AddMethod()
{

}

bool AddMethod::msgHandle(std::string &fName, std::string &param)
{
	// what will this "add" command do.
	std::cout << "key: ";
	std::string inputKey, inputValue;
        std::getline(std::cin, inputKey,'\n');
	std::cout << "value: ";
	std::getline(std::cin, inputValue,'\n');
	Json::Value *addValue = NULL;
	if(CmdMethod::changedRoot != NULL)
		addValue = CmdMethod::changedRoot;
	else
	{
		if(CmdMethod::defaultRoot == NULL)
		{
			std::cout << "the JSON Value is not initialized!" << std::endl;
			return true;
		}
		addValue = CmdMethod::defaultRoot;
	}
	std::vector<std::string> members = (*addValue).getMemberNames();
	std::vector<std::string>::iterator itr = members.begin();
	for(; itr != members.end(); ++itr)
	{
		if(*itr == inputValue)
		{
			std::cout << "ERROR: input JSON value did exisit!" << std::endl;
			return true;
		}
	}
	Json::Reader reader;
	Json::Value added;
	if(!reader.parse(inputValue,added))
	{
		std::cout << "AddMethod: reader parse wrong!" << std::endl;
		return true;
	}
	(*addValue)[inputKey] = added;
	std::cout << "address entry added" << std::endl;
	return true;
}
