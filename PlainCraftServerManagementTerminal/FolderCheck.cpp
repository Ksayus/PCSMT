#include "FolderCheck.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void CheckPCSMTFolder()
{
	std::string PCSMTFolderPosition = ADot + PCSMTPositionFolder;

	if (_access(PCSMTFolderPosition.c_str(), 0) == -1)
	{
		std::cout << "�ļ��в����ڣ�������..." << std::endl;
		int serverposition = _mkdir(PCSMTFolderPosition.c_str());
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ��д��ڣ�" << std::endl;
	}
}

void CheckTimeFolder()
{
	tm* gettime = GetTime();

	//�洢ʱ��
	std::string Year = RightSlash + std::to_string(gettime->tm_year + 1900);
	std::string Month = RightSlash + std::to_string(gettime->tm_mon + 1);
	std::string Day = RightSlash + std::to_string(gettime->tm_mday);

	//��־�ļ�·��
	std::string LogFolderPath = ADot + PCSMTLogPositionFolder;
	std::string YearFolderPath = LogFolderPath + Year;
	std::string MonthFolderPath = YearFolderPath + Month;
	std::string DayFolderPath = MonthFolderPath + Day;

	if (_access(LogFolderPath.c_str(), 0) == -1)
	{
		std::cout << "�ļ���" << PCSMTLogPositionFolder << "�����ڣ�������..." << std::endl;
		int serverposition = _mkdir(LogFolderPath.c_str());
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ���" << PCSMTLogPositionFolder << "���ڣ�" << std::endl;
	}

	//YearsFolder
	if (_access(YearFolderPath.c_str(), 0) == -1)
	{
		std::cout << "�ļ���" << Year << "�����ڣ�������..." << std::endl;
		int serverposition = _mkdir(YearFolderPath.c_str());
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ���" << Year << "���ڣ�" << std::endl;
	}

	//MonthsFolder
	if (_access(MonthFolderPath.c_str(), 0) == -1)
	{
		std::cout << "�ļ���" << Month << "�����ڣ�������..." << std::endl;
		int serverposition = _mkdir(MonthFolderPath.c_str());
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ���" << Month << "���ڣ�" << std::endl;
	}

	//DaysFolder
	if (_access(DayFolderPath.c_str(), 0) == -1)
	{
		std::cout << "�ļ���" << Day << "�����ڣ�������..." << std::endl;
		int serverposition = _mkdir(DayFolderPath.c_str());
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ���" << Day << "���ڣ�" << std::endl;
	}
}
