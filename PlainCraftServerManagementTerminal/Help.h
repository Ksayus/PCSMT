#ifndef HELP
#define HELP

#include <iostream>
//Help���ݵ�ָ����
const int HelpQuantity = 50;

//Help�ľ�������
static std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver"
};

static std::string HelpCommandRole[HelpQuantity] = {
	"-���ļ�",
	"-��ӷ�����·��"
};

static std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}"
};

#endif // !HELP


