#include "FolderCheck.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void CheckPCSMTFolder()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

	std::string PCSMTFolderPosition = ADot + PCSMTPositionFolder;

	if (_access(PCSMTFolderPosition.c_str(), 0) == -1)
	{
		Output("�ļ��в����ڣ�������...");
		int serverposition = _mkdir(PCSMTFolderPosition.c_str());
		Output("������ɣ�");
	}
	else {
		Output("�����ϣ��ļ��д��ڣ�");
	}
	LogFile.close();
}

void CheckTimeFolder()
{
	std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
	auto Output = [&](const std::string& text) {
		std::cout << text << std::endl;
		LogFile << text << std::endl;
		};

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
		Output("�ļ���" + PCSMTLogPositionFolder + "�����ڣ�������...");
		int serverposition = _mkdir(LogFolderPath.c_str());
		Output("������ɣ�");
	}
	else {
		Output("�����ϣ��ļ���" + PCSMTLogPositionFolder + "���ڣ�");
	}

	//YearsFolder
	if (_access(YearFolderPath.c_str(), 0) == -1)
	{
		Output("�ļ���" + Year + "�����ڣ�������...");
		int serverposition = _mkdir(YearFolderPath.c_str());
		Output("������ɣ�");
	}
	else {
		Output("�����ϣ��ļ���" + Year + "���ڣ�");
	}

	//MonthsFolder
	if (_access(MonthFolderPath.c_str(), 0) == -1)
	{
		Output("�ļ���" + Month + "�����ڣ�������...");
		int serverposition = _mkdir(MonthFolderPath.c_str());
		Output("������ɣ�");
	}
	else {
		Output("�����ϣ��ļ���" + Month + "���ڣ�");
	}

	//DaysFolder
	if (_access(DayFolderPath.c_str(), 0) == -1)
	{
		Output("�ļ���" + Day + "�����ڣ�������...");
		int serverposition = _mkdir(DayFolderPath.c_str());
		Output("������ɣ�");
	}
	else {
		Output("�����ϣ��ļ���" + Day + "���ڣ�");
	}
	LogFile.close();
}
