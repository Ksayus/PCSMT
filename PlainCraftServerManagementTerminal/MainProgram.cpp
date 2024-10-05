#include <iostream>
#include <Windows.h>

#include "ServerCommandRegister.h"
#include "HomePage.h"
#include "FolderCheck.h"
#include "Initialization.h"
#include "registerServerCommand.h"

using namespace std;

int main() {
	setServerCommand();
    HomePage();
    CheckPCSMTFolder();
    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();

    //��������
    std::string input;
    while (true) {
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