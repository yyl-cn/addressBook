#include "MethodFactory.h"

MethodFactory::MethodFactory()
{
	catMethod = new CatMethod();
	lsMethod = new LsMethod();
	addMethod = new AddMethod();
	cdMethod = new CdMethod();
	removeMethod = new RemoveMethod();
	helpQuit = new HelpQuit();
}

MethodFactory::~MethodFactory()
{

}

MethodFactory *MethodFactory::_instance = NULL;


MethodFactory *MethodFactory::instance()
{
	if(NULL == _instance)
	{
		static MethodFactory methodFactory;
		_instance = &methodFactory;
	}
	return _instance;
}

void MethodFactory::cmdParse(std::string &cmdline)
{
	std::string::size_type i = 0;
	for(; cmdline[i] == ' ' || cmdline[i] == '\t'; i++)
		;
	cmdline = cmdline.substr(i);
	std::string cmd, param;
	std::string::size_type begin1 = cmdline.find_first_of(' ');
	std::string::size_type begin2 = cmdline.find_first_of('\t');
	std::string::size_type itr1 =begin1<begin2?begin1:begin2;
	if(itr1 >= cmdline.length())
	{
		return;
	}
	cmd = cmdline.substr(0,itr1);
	for(;(cmdline[itr1] == ' ' || cmdline[itr1] == '\t') && itr1 <= cmdline.length();itr1++)
		;
	param = cmdline.substr(itr1);
	cmdline = cmd + " " + param;
}

void MethodFactory::initJsonValue(Json::Value *value)
{
	CmdMethod::defaultRoot = &(*value);
	if(value->empty())
		std::cout << "please add item to this JSON Value first!" << std::endl;
}

CmdMethod *MethodFactory::CreateMethod(std::string &cmdLine)
{
	// choose different methods according to input command line.
	cmdParse(cmdLine);
	if(cmdLine.find("ls") == 0)
		return lsMethod;
	else if(cmdLine.find("add") == 0)
		return addMethod;
	else if(cmdLine.find("remove") == 0)
		return removeMethod;
	else if(cmdLine.find("cd") == 0)
		return cdMethod;
	else if(cmdLine.find("cat") == 0)
		return catMethod;
	else
		return helpQuit;
}
