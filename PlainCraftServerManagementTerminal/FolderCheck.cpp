#include "FolderCheck.h"

void CheckPCSMTFolder()
{
	if (_access("./PCSMT", 0) == -1)
	{
		std::cout << "�ļ��в����ڣ�������..." << std::endl;
		int serverposition = _mkdir("./PCSMT");
		std::cout << "������ɣ�" << std::endl;
	}
	else {
		std::cout << "�����ϣ��ļ��д��ڣ�" << std::endl;
	}
}
