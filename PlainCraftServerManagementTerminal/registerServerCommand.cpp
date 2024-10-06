#include "registerServerCommand.h"

#include "FilesFoldersPosition.h"

// ����һ��ӳ�䣬���ڴ洢ָ��Ͷ�Ӧ�ĺ���
std::map<std::string, StartServer> StartServerCommand;

// ע��ָ��
void registerServerCommand(const std::string& CommandName, StartServer servercmd) {
    StartServerCommand[CommandName] = servercmd;
}
// ִ��ָ��
void excuteServerCommand(const std::string& scLine) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

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
        Output("Unkown command: " + servercommand);
        Output("ʹ�á�help���Բ�ѯָ��");
    }
    LogFile.close();
}
