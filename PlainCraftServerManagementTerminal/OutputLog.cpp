#include "OutputLog.h"

#include "getTime.h"
#include "FilesFoldersPosition.h"

void TimeLog()
{
	//��ȡʱ��
	tm* gettime = GetTime();

	//��intתΪstring������ "/"
	std::string YearsPath = RightSlash + std::to_string(gettime->tm_year + 1900);
	std::string MonthsPath = RightSlash + std::to_string(gettime->tm_mon + 1);
	std::string DaysPath = RightSlash + std::to_string(gettime->tm_mday);

	//�����ļ�������־���Ŀ¼
	std::string LogName = std::to_string(gettime->tm_hour) + HorizontalLine + std::to_string(gettime->tm_min) + HorizontalLine + std::to_string(gettime->tm_sec) + Txt;
	std::string LogOutputPath = ADot + PCSMTLogPositionFolder + YearsPath + MonthsPath + DaysPath + RightSlash + LogName;
	
	//
	//std::cout << LogOutputPath << std::endl;

	std::ofstream fout; //�ļ����������

	fout.open(LogOutputPath, std::ios::out);

	if (!fout.is_open())
	{
		std::cout << "���ļ�ʧ�ܣ�" << std::endl;
		return;
	}
	else {
		std::cout << "�ɹ����ļ�" + LogName << std::endl;
		std::streambuf* pOld = std::cout.rdbuf(fout.rdbuf());
		std::cout << std::to_string(gettime->tm_hour) + Colon + std::to_string(gettime->tm_min) + Colon + std::to_string(gettime->tm_sec) + " ������PCSMT" << std::endl;
		std::cout.rdbuf(pOld);
		fout.close();
	}
}
