#include <iostream>
#include <string>
#include <fstream>
#include "MethodFactory.h"
#include "json/json.h"

int main(int argc, char* argv[])
{
	Json::Value root;
	std::ifstream jsonIn("json.txt");
	Json::Reader reader;
	if(!reader.parse(jsonIn,root))
	{
		std::cout << "reader parse wrong!";
		return 0;
	}
	jsonIn.close();

	std::string fPath(argv[0]);
	std::string fName = fPath.substr(fPath.find_last_of('/') + 1);

        std::cout << fPath << std::endl;
	std::string cmdline;
	std::cout << fName << " > ";
	bool retJudge = true;
	MethodFactory *methodFactory  = MethodFactory::instance();
	methodFactory->initJsonValue(&root);
	CmdMethod * cmdMethod = NULL;

	while(retJudge)
	{
		getline(std::cin,cmdline,'\n');
		cmdMethod = methodFactory->CreateMethod(cmdline);
		if(cmdMethod != NULL)
		{
			retJudge = cmdMethod->msgHandle(fName, cmdline);
		}
		std::cout << fName << " > ";
	}

	return 0;
}
