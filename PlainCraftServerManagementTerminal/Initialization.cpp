#include "Initialization.h"

int InitializationServerPosition()
{
	int ReadServerPostionContent = 0;

	std::string ServerPositionReaded[MaxServerPositonTotals];
	std::ifstream ReadServerPosition;
	//���ļ�
	ReadServerPosition.open(ADot + PCSMTPositionFolder + ServerPositionTxt, std::ios::in);

	std::cout << "��ȡ�ļ�" + ServerPositionTxt + "�У�" << std::endl;


	while (std::getline(ReadServerPosition, ServerPositionReaded[ReadServerPostionContent]))
	{
		std::cout << "��ȡ��������ַ:" + ServerPositionReaded[ReadServerPostionContent] << std::endl;
		ServerPosition[ReadServerPostionContent] = ServerPositionReaded[ReadServerPostionContent];
		//return ServerPositionReaded[ReadServerPostionContent];
	}
	return ReadServerPostionContent;
}
