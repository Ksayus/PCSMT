#include <iostream>
#include <Windows.h>

#include "ServerCommandRegister.h"

using namespace std;

int main() {
	setServerCommand();

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