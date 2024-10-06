#include "FileCheck.h"
#include "FileFind.h"

#include "FilesFoldersPosition.h"

std::string XmsRam = "4096M";
std::string XmxRam = "4096M";

std::string ServerCoreFileName;

void CheckStartBatch(std::string StartBatchpath)
{
	ServerCoreFileName = FindFilesWithExtension(StartBatchpath, ".jar");
	std::string StartBatchPath = StartBatchpath + "/Start.bat";

	if (ServerCoreFileName == "")
	{
		return;
	}
	else {
		// ���Դ��ļ�
		std::fstream StartBatch;
		StartBatch.open(StartBatchPath);

		// ����ļ��Ƿ�ɹ���
		if (!StartBatch.is_open())
		{
			std::cout << "δ����Start.bat�ļ���" << std::endl;
			std::cout << "����Start.bat�ļ���" << std::endl;
			StartBatch.open(StartBatchPath, std::fstream::out | std::fstream::trunc);

			//����ļ��Ƿ񴴽�
			if (StartBatch.is_open()) {
				std::cout << "����������Start.bat�ļ���" << std::endl;

				//����������Start.bat�ļ�
				StartBatch << "cd " + StartBatchpath << std::endl;
				StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
				std::cout << "���óɹ���" << std::endl;
				StartBatch.close(); // ������ɺ�ر��ļ�
			}
			else {
				std::cout << "���Դ����ļ�ʧ�ܣ�" << std::endl;
			}
		}
		else {
			//�󶨲�����Start.bat�ļ�
			std::cout << "�Ѱ�Start.bat�ļ���" << std::endl;
			StartBatch << "cd " + StartBatchpath << std::endl;
			StartBatch << "java -jar -Xms" + XmsRam + " -Xmx" + XmxRam + " -jar " + ServerCoreFileName << std::endl;
			std::cout << "���óɹ���" << std::endl;
			StartBatch.close(); // ������ɺ�ر��ļ�
		}
	}
}
