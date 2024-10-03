#ifndef REGISTERSERVERCOMMAND
#define REGISTERSERVERCOMMAND

#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>

// ����ָ�������
typedef std::function<void(std::string)> StartServer;


void registerServerCommand(const std::string& CommandName, StartServer servercmd);

void excuteServerCommand(const std::string& servercommandLine);

#endif // !REGISTERSERVERCOMMAND


