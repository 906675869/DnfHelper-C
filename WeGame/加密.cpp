#include "pch.h"
#include "�ļ�.h"
#include "����.h"
#include "Address.h"

int ��������(ULONG64 ��_���ܵ�ַ)
{
	return  (*(long*)��_���ܵ�ַ ^ 0x1F2A025C) - 4;

}

void ��������(ULONG64 address, int value)
{
	*(long long*)address = (value + 4) ^ 0x1f2a025c;
}

