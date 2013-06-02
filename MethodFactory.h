#ifndef METHODFACTORY_H
#define METHODFACTORY_H
#include<string>
#include "Method.h"
#include "LsMethod.h"
#include "CdMethod.h"
#include "AddMethod.h"
#include "CatMethod.h"
#include "RemoveMethod.h"
#include "HelpQuit.h"


class MethodFactory
{
public:
	//MethodFactory();
	//~MethodFactory();
	static MethodFactory *instance();
	CmdMethod *CreateMethod(std::string &);
	void initJsonValue(Json::Value *value);
private:
	MethodFactory();
	~MethodFactory();
	static MethodFactory *_instance;
	void cmdParse(std::string &);
	LsMethod *lsMethod;
	CdMethod *cdMethod;
	AddMethod *addMethod;
	CatMethod *catMethod;
	RemoveMethod *removeMethod;
	HelpQuit *helpQuit;
};
#endif
