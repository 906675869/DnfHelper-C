#pragma once
#include "Common.h"

static ByteArr packData;

VOID ����Call(__int64 ����ָ��, int ���ܴ���, int �����˺�, int x, int y, int z, int ��С);
VOID ͸��Call(__int64 ����ָ��);
VOID ����Call(int Value);
VOID ��ͼCall(int ����);
VOID ����Call(__int64 �������);
VOID ����Call(__int64 ���ܲ���, int ���ܳ���);
VOID ����Call(__int64 �������);

__int64 ȡ����ָ��Call(__int64 globleRwAddr);

VOID SetPerson(__int64 pAddr, __int64 pPointer);

__int64 GetPersonAddr();

__int64 GetPersonPointer();

VOID ȡ����ָ���߳�();