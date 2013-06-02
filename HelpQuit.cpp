#include "HelpQuit.h"
//#include "CdMethod.h"

HelpQuit::HelpQuit()
{

}

HelpQuit::~HelpQuit()
{

}

void HelpQuit::helpHandle()
{
	std::cout << "**********************************************\n";
	std::cout << "*  ls: list the items in current position\n";
	std::cout << "*  cd 'param': go to a directory\n";
	std::cout << "*  cat 'param': display the item data\n";
	std::cout << "*  add: add a new item to current JSON Value\n";
	std::cout << "*  remove: remove one item\n";
	std::cout << "*  !help: get help\n";
	std::cout << "*  !quit: quit from the application\n";
	std::cout << "**********************************************\n";
}

void HelpQuit::quitHandle()
{
	// file to save before quiting from the application.
	std::ofstream jsonOut("json.txt");
	Json::StyledWriter styleWriter;
	jsonOut << styleWriter.write(*CmdMethod::defaultRoot);
	jsonOut << std::flush;
	jsonOut.close();
}

bool HelpQuit::msgHandle(std::string &fName, std::string &param)
{
	// what will this " '!help' || '!quit' " command do.
	if(param == "!quit")
	{
		std::cout << "would you like to save the JSON value of this application: Y/N" << std::endl;
		char q;
		std::cin >> q;
		if(q == 'Y' || q == 'y')
			quitHandle();
		return false;
	}
	helpHandle();
	return true;
}
