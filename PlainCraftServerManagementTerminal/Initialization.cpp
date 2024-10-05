#include "Initialization.h"

#include "FilesFoldersPosition.h"

int InitializationServerPosition()
{
	const int MaxServerTotals = 512;
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerTotals];
	std::ifstream ReadServerPosition;
	//���ļ�
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	if (ReadServerPosition.is_open() == false)
	{
		std::cout << "�ļ���ʧ�ܣ�" << std::endl;
		return 0;
	}

	std::cout << "��ȡ�ļ�" + ServerPositionTxt + "�У�" << std::endl;


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		std::cout << "��ȡ��������ַ:" + ServerPositionReaded[ReadServerPostionContent] << std::endl;
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
		ReadServerPostionContent++;
	}
	return ReadServerPostionContent;
}

int InitializationServerName()
{
	const int MaxServerTotals = 512;
	int ReadServerNameContent = 0;

	std::string ServerNameReaded[MaxServerTotals];
	std::ifstream ReadServerName;
	//���ļ�
	ReadServerName.open(ADot + PCSMTPositionFolder + ServerNameTxt, std::ios::in);

	if (ReadServerName.is_open() == false)
	{
		std::cout << "�ļ���ʧ�ܣ�" << std::endl;
		return 0;
	}

	std::cout << "��ȡ�ļ�" + ServerNameTxt + "�У�" << std::endl;

	while (std::getline(ReadServerName, ServerNameReaded[ReadServerNameContent]))
	{
		std::cout << "��ȡ����������" + ServerNameReaded[ReadServerNameContent] << std::endl;
		ServerName[ReadServerNameContent] = ServerNameReaded[ReadServerNameContent];
		std::cout << ReadServerNameContent << std::endl;
		ReadServerNameContent++;
	}
	return ReadServerNameContent;
}

int InitializationServerFolder() 
{
	const int MaxServerTotals = 512;
	int ReadServerFolderContent = 0;

	std::string ServerFolderReaded[MaxServerTotals];
	std::ifstream ReadServerFolder;
	//���ļ�
	ReadServerFolder.open(ADot + PCSMTPositionFolder + ServerFolderTxt, std::ios::in);

	if (ReadServerFolder.is_open() == false)
	{
		std::cout << "�ļ���ʧ�ܣ�" << std::endl;
		return 0;
	}

	std::cout << "��ȡ�ļ�" + ServerFolderTxt + "�У�" << std::endl;

	while (std::getline(ReadServerFolder, ServerFolderReaded[ReadServerFolderContent]))
	{
		std::cout << "��ȡ�����������ļ��У�" + ServerFolderReaded[ReadServerFolderContent] << std::endl;
		ServerFolder[ReadServerFolderContent] = ServerFolderReaded[ReadServerFolderContent];
		std::cout << ReadServerFolderContent << std::endl;
		ReadServerFolderContent++;
	}
	return ReadServerFolderContent;
}