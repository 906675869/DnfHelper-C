#pragma once
#include "DataType.h"

// ȡ��Ϸ����
class GetGameData
{
public:
	int ����(__int64 ����ָ��);
	VOID ����(__int64 ����ָ��, int �޸���ֵ);
	int ȡ��Ϸ״̬();
	bool ȡ�Ƿ���();
	bool ȡ�Ƿ�ͨ��();
	������ ȡBOSS����();
	������ ȡ��ǰ����();
	int ȡ��ͼ���();
	int ȡ��ɫƣ��();
	int ȡ��ɫ�ȼ�();
};

extern GetGameData getGameData;