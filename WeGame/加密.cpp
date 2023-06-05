#include "pch.h"
#include "文件.h"
#include "引用.h"
#include "Address.h"

int 超级解密(ULONG64 参_解密地址)
{
	return  (*(long*)参_解密地址 ^ 0x1F2A025C) - 4;

}

void 超级加密(ULONG64 address, int value)
{
	*(long long*)address = (value + 4) ^ 0x1f2a025c;
}

