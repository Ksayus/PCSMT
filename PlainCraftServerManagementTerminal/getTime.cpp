#include "getTime.h"

tm* GetTime()
{
	time_t nowtime;
	time(&nowtime); //��ȡ1970��1��1��0��0��0�뵽���ھ���������
	tm* NowTime = localtime(&nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	return NowTime;
}

int YMD()
{
	tm* getymd = GetTime();
	int Years = getymd->tm_year + 1900;
	int Months = getymd->tm_mon + 1;
	int Days = getymd->tm_mday;
	return Years, Months, Days;
}
