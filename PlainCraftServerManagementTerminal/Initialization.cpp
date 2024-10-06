#include "Initialization.h"

#include "FilesFoldersPosition.h"

int InitializationServerPosition()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerTotals];
	std::ifstream ReadServerPosition;
	//���ļ�
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	if (ReadServerPosition.is_open() == false)
	{
		Output("�ļ���ʧ�ܣ�");
		return 0;
	}

	Output("��ȡ�ļ�" + ServerPositionTxt + "�У�");


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		Output("��ȡ��������ַ:" + ServerPositionReaded[ReadServerPostionContent]);
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
		ReadServerPostionContent++;
	}
	LogFile.close();
	return ReadServerPostionContent;
}

int InitializationServerName()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerNameContent = 0;

	std::string ServerNameReaded[MaxServerTotals];
	std::ifstream ReadServerName;
	//���ļ�
	ReadServerName.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::in);

	if (ReadServerName.is_open() == false)
	{
		Output("�ļ���ʧ�ܣ�");
		return 0;
	}

	Output("��ȡ�ļ�" + ServerNameTxt + "�У�");

	while (std::getline(ReadServerName, ServerNameReaded[ReadServerNameContent]))
	{
		Output("��ȡ����������" + ServerNameReaded[ReadServerNameContent]);
		ServerName[ReadServerNameContent] = ServerNameReaded[ReadServerNameContent];
		//std::cout << ReadServerNameContent << std::endl;
		ReadServerNameContent++;
	}
	LogFile.close();
	return ReadServerNameContent;
}

int InitializationServerFolder() 
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	const int MaxServerTotals = 512;
	int ReadServerFolderContent = 0;

	std::string ServerFolderReaded[MaxServerTotals];
	std::ifstream ReadServerFolder;
	//���ļ�
	ReadServerFolder.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::in);

	if (ReadServerFolder.is_open() == false)
	{
		Output("�ļ���ʧ�ܣ�");
		return 0;
	}

	Output("��ȡ�ļ�" + ServerFolderTxt + "�У�");

	while (std::getline(ReadServerFolder, ServerFolderReaded[ReadServerFolderContent]))
	{
		Output("��ȡ�����������ļ��У�" + ServerFolderReaded[ReadServerFolderContent]);
		ServerFolder[ReadServerFolderContent] = ServerFolderReaded[ReadServerFolderContent];
		//std::cout << ReadServerFolderContent << std::endl;
		ReadServerFolderContent++;
	}
	LogFile.close();
	return ReadServerFolderContent;
}