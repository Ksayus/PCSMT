#ifndef HELP
#define HELP

#include <iostream>
//Help���ݵ�ָ����
const int HelpQuantity = 50;

//Help�ľ�������
static std::string HelpCommandName[HelpQuantity] = {
	"-start",
	"-addserver",
	"-tostartserver",
	"-serverlist",
};

static std::string HelpCommandRole[HelpQuantity] = {
	"-���ļ�",
	"-��ӷ�����·���ͷ�������",
	"-����������",
	"�г��������б�",
};

static std::string HelpCommandUsage[HelpQuantity] = {
	"-start {path}",
	"-addserver {path}",
	"-tostartserver {number}",
	"-serverlist",
};

#endif // !HELP


