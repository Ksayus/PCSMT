#include "registerServerCommand.h"

// ����һ��ӳ�䣬���ڴ洢ָ��Ͷ�Ӧ�ĺ���
std::map<std::string, StartServer> StartServerCommand;

// ע��ָ��
void registerServerCommand(const std::string& CommandName, StartServer servercmd) {
    StartServerCommand[CommandName] = servercmd;
}
// ִ��ָ��
void excuteServerCommand(const std::string& scLine) {
    std::istringstream server(scLine);
    std::string servercommand;
    server >> servercommand;
    if (StartServerCommand.find(servercommand) != StartServerCommand.end()) {
        std::string serverargs;
        server >> serverargs;
        StartServerCommand[servercommand](serverargs);
    }
    else {
        //���������Ϣ
        std::cout << "Unkown command: " << servercommand << std::endl;
        std::cout << "ʹ�á�help���Բ�ѯָ��" << std::endl;
    }
}
