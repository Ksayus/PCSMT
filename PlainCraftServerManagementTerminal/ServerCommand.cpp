#include "ServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"

const char* TabKey = "\t";

std::string StartString = "start";
std::string StartBatch = "/Start.bat";

void Start(std::string args) {
    //std::cout << "Start " << args << " units" << std::endl;
    //������ת��Ϊconst char*���͵ĳ���
    std::string ServerPathString = StartString + args;
    const char *ServerPathChar = ServerPathString.c_str();
    //ʹ��system�������д��ļ�
    system(ServerPathChar);
    //�����Ϣ
    std::cout << "���ļ�:" << args << std::endl;
}

void Help(std::string args) {
    int HelpLoop = HelpQuantity;
    int HelpPosition = 0;

    //��Help�ڶ�����ı�������
    for (size_t HelpPosition = 0; HelpPosition < HelpCommandName[HelpPosition].size(); ++HelpPosition) {
        if (HelpCommandName[HelpPosition] == " ") {
            continue; // �����ǰԪ���ǿո��ַ�����������
        }
        //�����Ϣ
        std::cout << HelpCommandName[HelpPosition] << TabKey << HelpCommandRole[HelpPosition] << TabKey << HelpCommandUsage[HelpPosition] << std::endl;
    }

}

void AddServer(std::string args) {
    const char* ServerPosition = args.c_str();

    CheckServerPosition();
    //�����./ServerPosition/ServerPosition.txt�ļ��ʹ򿪣�û���򴴽�
    std::fstream ServerAddress("./ServerPosition/ServerPosition.txt",std::ios::out|std::ios::app);

    //����ļ��Ƿ��
    if (!ServerAddress.is_open())
    {
        std::cout << "�洢���󣡴��ļ�ʱ��������" << std::endl;
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPosition << StartBatch << std::endl;
        ServerAddress << ServerPosition << StartBatch << std::endl;
        ServerAddress.close();
        //���Start.bat�ļ��Ĵ��ڲ�д��Start.bat��
        CheckStartBatch(args);
        //�����Ϣ
        std::cout << "������·���洢��ɣ�" << std::endl;
    }
}
