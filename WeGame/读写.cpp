#include "pch.h"
#include "��д.h"

#include "Api��д.h"

Api��д apiRw;

DWORD static ȫ_����ID;

HWND static ȫ_���̾��;

VOID ���ý���ID(DWORD ����ID, HWND ���ھ��) {
	ȫ_����ID = ����ID;
	ȫ_���̾�� = ���ھ��;
}

LPVOID ����_�ڴ�(DWORD ���볤��) {
	return apiRw.�����ڴ�64(ȫ_����ID, ���볤��);
}

BOOL ���ֽڼ�(DWORD64 ��ַ, PVOID ����ֵ, INT32 д�볤��) {
	return apiRw.����_���ֽڼ�(ȫ_����ID, ��ַ, ����ֵ, д�볤��);
}

BOOL д�ֽڼ�(DWORD64 ��ַ, PVOID д��ֵ, INT32 д�볤��) {
	return apiRw.����_д�ֽڼ�(ȫ_����ID, ��ַ, д��ֵ, д�볤��);
}

DWORD ��������(DWORD64 ��ַ)
{
	DWORD result;
	���ֽڼ�(��ַ, &result, sizeof(result));
	return result;
}

DWORD64 ����������(DWORD64 ��ַ)
{
	DWORD64 result;
	���ֽڼ�(��ַ, &result, sizeof(result));
	return result;
}

BOOL д������(DWORD64 ��ַ, DWORD ����)
{
	return д�ֽڼ�(��ַ, &����, sizeof(����));
}

BOOL д��������(DWORD64 ��ַ, DWORD64 ����)
{
	return д�ֽڼ�(��ַ, &����, sizeof(����));
}

// BYTE* ԭ�ֽڼ� = ���ֽڼ���(�Ʋû�ַ, 2);
BYTE* ���ֽڼ���(DWORD64 ��ַ, INT32 ����) {
	BYTE* result = new BYTE[����];
	���ֽڼ�(��ַ, result, ����);
	return result;
}

// д�ֽڼ���(�Ʋû�ַ, new BYTE[]{ 0xC3, 0x90 }, 2);
BOOL д�ֽڼ���(DWORD64 ��ַ, PBYTE д��ֵ, INT32 ����) {
	return д�ֽڼ�(��ַ, д��ֵ, ����);
}

vector<BYTE> API_���ֽڼ�(DWORD64 ��ַ, INT32 ����) {
	return apiRw.API_���ֽڼ�(ȫ_����ID, ��ַ, ����);
}

BOOL API_д�ֽڼ�(DWORD64 ��ַ, vector<BYTE> ֵ) {
	return apiRw.API_д�ֽڼ�(ȫ_����ID, ��ַ, ֵ);
}


VOID ���ִ��(BYTE* ������) {

	DWORD64 static �հ׵�ַ, �����ת, Hook��ַ, Hook����, �жϵ�ַ = 0;
	BYTE* Hook����[] = { 0 };
	if (�հ׵�ַ == 0)
	{

		�հ׵�ַ = (DWORD64)����_�ڴ�(1024);
		�����ת = (DWORD64)����_�ڴ�(1024) + 100;
		�жϵ�ַ = �����ת - 100;
	}
}