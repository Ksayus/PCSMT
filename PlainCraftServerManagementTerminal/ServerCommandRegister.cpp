#include "ServerCommandRegister.h"

void setServerCommand()
{
	//ע��ָ��
	//ע��ָ���ǵ���ServerCommand.cpp��ʵ��ָ��,������ServerCommand.h������
	registerServerCommand("start", Start);
	registerServerCommand("help", Help);
	registerServerCommand("addserver", AddServer);
}
