#include "ServerCommand.h"

#include "registerServerCommand.h"
#include "Help.h"
#include "fstream"
#include "FolderCheck.h"
#include "FileCheck.h"
#include "Initialization.h"
#include "FilesFoldersPosition.h"

//#include "FilesFoldersPosition.cpp"


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
    const char* ServerPath = args.c_str();
    //std::wstring StartBarchWstring(StartBatch.begin(), StartBatch.end());
    //std::wstring midServerPath(args.begin(), args.end());
    //std::wstring ServerPositionFolder = midServerPath + StartBarchWstring;

    const int ServerAbsolutePathLong = 512;
    char ServerAbsolutePath[ServerAbsolutePathLong]{};

    //��ȡ��ǰ����ľ���·��
    GetCurrentDirectory(ServerAbsolutePathLong, ServerAbsolutePath);

    //LPCWSTR ServerAbsolutePositionFolder = ServerPositionFolder.c_str();

    //GetFullPathName(ServerAbsolutePositionFolder, MAX_PATH, ServerAbsolutePath, NULL);

    std::string getServerName;

    for (char get : args)
    {
        if (get != '.' && get != '/') {
            getServerName += get;
        }
    }

    std::cout << "����������" + getServerName << std::endl;

    CheckPCSMTFolder();
    //�����./PCSMT/ServerPosition.txt�ļ��ʹ򿪣�û���򴴽�
    //�洢ServerPosition
    std::fstream ServerAddress(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::out | std::ios::app);

    //����ļ��Ƿ��
    if (!ServerAddress.is_open())
    {
        std::cout << "������·���洢���󣡴��ļ�ʱ��������" << std::endl;
        ServerAddress.close();
    }
    else {
        //std::cout << args << StartBatch << std::endl;
        //std::cout << ServerPath << StartBatch << std::endl;
        std::cout << "������·����" << ServerAbsolutePath + RightSlash + getServerName; std::cout << StartBatch << std::endl;
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << StartBatch << std::endl;
        ServerAddress.close();
        //���Start.bat�ļ��Ĵ��ڲ�д��Start.bat��
        CheckStartBatch(ServerAbsolutePath + RightSlash + getServerName);
        //�����Ϣ
        std::cout << "������·���洢��ɣ�" << std::endl;
    }

    //�洢ServerName
    ServerAddress.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        std::cout << "���������洢���󣡴��ļ�ʱ��������" << std::endl;
        ServerAddress.close();
    }
    else {
        
        ServerAddress << getServerName << std::endl;
        ServerAddress.close();

        std::cout << "���������洢��ɣ�" << std::endl;
    }

    ServerAddress.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::out | std::ios::app);

    if (!ServerAddress.is_open())
    {
        std::cout << "�����������ļ��д洢���󣡴��ļ�ʱ��������" << std::endl;
        ServerAddress.close();
    }
    else {
        std::cout << "�����������ļ��У�" << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress << ServerAbsolutePath << RightSlash + getServerName << std::endl;
        ServerAddress.close();

        std::cout << "�����������ļ��д洢��ɣ�" << std::endl;
    }

    InitializationServerPosition();
    InitializationServerName();
    InitializationServerFolder();
}

void ToStartServer(std::string args) {

    //�������ת��Ϊ����
    int ServerNamePositionTotals = std::atoi(args.c_str());
    std::cout << "������������" + ServerName[ServerNamePositionTotals] << std::endl;

    //��std::string ServerPositionת����const char* ServerNamePosition
    std::string cdServerPosition = CD + ServerFolder[ServerNamePositionTotals];
    std::string startServer = StartString + ServerFolder[ServerNamePositionTotals] + StartBatch;

    //ִ������
    system(cdServerPosition.c_str());
    int excuteResult = system(startServer.c_str());
    while (excuteResult != 0)
    {
        std::cout << "ִ�������ű�ʧ�ܣ�" << std::endl;
        return;
    }
    std::cout << "ִ�������ű��ɹ���" << std::endl;
    std::cout << "��ǰ������������" + ServerName[ServerNamePositionTotals] << std::endl;
}

void ServerList(std::string args) {
    //��ȡ�б������������
    ServerNameNumber = InitializationServerName();

    std::cout << "�������б�" << std::endl;
    
    //����������б�
    std::cout << ServerNameNumber << std::endl;
    for (int OutputServerName = 0; OutputServerName < ServerNameNumber; OutputServerName++)
    {
        std::cout << OutputServerName << ADot << ServerName[OutputServerName].c_str() << std::endl;
    }
}
