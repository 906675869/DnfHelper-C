#pragma once

#include <vector>
using namespace std;

class ApiReadWrite
{
public:
	
	LPVOID �����ڴ�64(DWORD ����ID, DWORD ���볤��);

	BOOL ����_д�ֽڼ�(DWORD ����ID, DWORD64 ��ַ, PVOID ����ֵ, INT32 д�볤��);
	BOOL ����_���ֽڼ�(DWORD ����ID, DWORD64 ��ַ, PVOID д��ֵ, INT32 д�볤��);

	DWORD ��������(DWORD ����ID, DWORD64 ��ַ);
	BOOL д������(DWORD ����ID, DWORD64 ��ַ, DWORD ����);

	DWORD64 ����������(DWORD ����ID, DWORD64 ��ַ);
	BOOL д��������(DWORD ����ID, DWORD64 ��ַ, DWORD64 ����);

	vector<byte> API_���ֽڼ�(DWORD ����ID, DWORD64 ��ַ, INT32 ����);
	BOOL API_д�ֽڼ�(DWORD ����ID, DWORD64 ��ַ, vector<byte> ֵ);
};

extern ApiReadWrite apiRw;