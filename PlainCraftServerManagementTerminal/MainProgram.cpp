#include <iostream>
#include <Windows.h>

#include "ServerCommandRegister.h"
#include "HomePage.h"
#include "FolderCheck.h"
#include "Initialization.h"
#include "registerServerCommand.h"
#include "getTime.h"
#include "OutputLog.h"
#include "FilesFoldersPosition.h"

using namespace std;

int main() {
    //����ָ��
	setServerCommand();

    //���ҳ��
    HomePage();

    //����ļ���
    CheckPCSMTFolder();
    CheckTimeFolder();

    //����־
    TimeLog();

    //��ʼ��
    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();

    tm* getalltime = GetTime();

    //��������
    std::string input;

    //ѭ��
    while (true) {
        std::cout << std::to_string(getalltime->tm_year + 1900) + std::to_string(getalltime->tm_mon + 1) + std::to_string(getalltime->tm_mday) + std::to_string(getalltime->tm_hour) + Colon + std::to_string(getalltime->tm_min) + Colon + std::to_string(getalltime->tm_sec);
        std::cout << "����> ";
        std::getline(std::cin, input);
        //�˳�����
        if (input == "exit") {
            break;
        }
        //����������м��ִ��
        excuteServerCommand(input);
    }
	return 0;
}