#include "FolderCheck.h"

void CheckServerPosition()
{
	if (_access("./ServerPosition", 0) == -1)
	{
		std::cout << "�ļ��в����ڣ�������..." << std::endl;
		int serverposition = _mkdir("./ServerPosition");
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ��д��ڣ�" << std::endl;
	}
}
