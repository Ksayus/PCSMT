#ifndef HELP
#define HELP

#include <iostream>
//Help���ݵ�ָ����
const int HelpQuantity = 50;

//Help�ľ�������
std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver"
};

std::string HelpCommandRole[HelpQuantity] = {
	"-���ļ�",
	"-��ӷ�����·��"
};

std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}"
};

#endif // !HELP


