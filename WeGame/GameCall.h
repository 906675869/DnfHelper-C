#pragma once
#include "Common.h"

class Call
{
public:
	VOID ����CALL(INT64 ����ָ��, INT ���ܴ���, INT �����˺�, INT x, INT y, INT z);

	VOID �ͷ�Call(INT64 ����ָ��, INT ���ܴ���, INT �����˺�, INT x, INT y, INT z);

	VOID ��ƷCall(INT64 ��Ʒ����);

	VOID ��ЧCall(INT type);

	VOID ͸��Call(INT64 ����ָ��);

	VOID ����Call(INT x, INT y, INT Speed);

	VOID ����Call(INT Value);

	VOID ��ͼCall(INT ����);
};

VOID ���ִ��(ByteArr ������);

__int64 ȡ����ָ��Call(__int64 globleRwAddr);

VOID SetPerson(__int64 pAddr, __int64 pPointer);

__int64 GetPersonAddr();

__int64 GetPersonPointer();

VOID ȡ����ָ���߳�();