#include "pch.h"
#include <winsvc.h>
#include "tlhelp32.h"
#include "ApiReadWrite.h"

LPVOID ApiReadWrite::�����ڴ�64(DWORD ����ID, DWORD ���볤��) {
	HANDLE ���̾�� = ::OpenProcess(PROCESS_ALL_ACCESS, 0, ����ID);
	LPVOID �ڴ��ַ = VirtualAllocEx(���̾��, 0, ���볤��, 4096, 64);
	CloseHandle(���̾��);
	return �ڴ��ַ;
}

BOOL ApiReadWrite::����_���ֽڼ�(DWORD ����ID, DWORD64 ��ַ, PVOID ����ֵ, INT32 д�볤��) {
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, ����ID);
	if (hProcess == NULL) {
		return FALSE;
	}

	BOOL result = ::ReadProcessMemory(hProcess, (LPVOID)��ַ, ����ֵ, д�볤��, NULL);
	if (result == false)
	{
		return 0;
	}
	::CloseHandle(hProcess);
	return result;
}
BOOL ApiReadWrite::����_д�ֽڼ�(DWORD ����ID, DWORD64 ��ַ, PVOID д��ֵ, INT32 д�볤��) {

	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, ����ID);
	if (hProcess == NULL) {
		return FALSE;
	}

	BOOL result = ::WriteProcessMemory(hProcess, (LPVOID)��ַ, д��ֵ, д�볤��, NULL);
	if (result == false)
	{
		return 0;
	}
	::CloseHandle(hProcess);
	return result;
}

DWORD ApiReadWrite::��������(DWORD ����ID, DWORD64 ��ַ)
{
	DWORD result;
	����_���ֽڼ�(����ID, ��ַ, &result, sizeof(result));
	return result;
}
BOOL ApiReadWrite::д������(DWORD ����ID, DWORD64 ��ַ, DWORD ����)
{
	return ����_д�ֽڼ�(����ID, ��ַ, &����, sizeof(����));
}

DWORD64 ApiReadWrite::����������(DWORD ����ID, DWORD64 ��ַ)
{
	DWORD64 result;
	����_���ֽڼ�(����ID, ��ַ, &result, sizeof(result));
	return result;
}
BOOL ApiReadWrite::д��������(DWORD ����ID, DWORD64 ��ַ, DWORD64 ����)
{
	return ����_д�ֽڼ�(����ID, ��ַ, &����, sizeof(����));
}

vector<BYTE> ApiReadWrite::API_���ֽڼ�(DWORD ����ID, DWORD64 ��ַ, INT32 ����)
{
	vector<BYTE> result;

	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, ����ID);
	if (hProcess == NULL) {
		return result;
	}

	BYTE* tempResult = new BYTE[(__int64)���� + 1];

	memset(tempResult, 0, ����);
	ReadProcessMemory(hProcess, (LPVOID)��ַ, tempResult, ����, NULL);
	CloseHandle(hProcess);

	result.resize(����);
	for (int i = 0; i < ����; i++)
	{
		result[i] = tempResult[i];
	}
	return result;
}
// API_д�ֽڼ�(�����ַ, { 0x90, 0x90, 0x90, 0x90, 0x90 });
BOOL ApiReadWrite::API_д�ֽڼ�(DWORD ����ID, DWORD64 ��ַ, vector<byte> ֵ)
{
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, NULL, ����ID);
	if (hProcess == NULL) {
		return FALSE;
	}

	int length;
	length = (int)ֵ.size();
	byte* val = new byte[length]();
	for (int i = 0; i < length; i++)
	{
		val[i] = ֵ[i];
	}
	WriteProcessMemory(hProcess, (LPVOID)��ַ, (LPCVOID)val, length, 0);
	CloseHandle(hProcess);
	return TRUE;
}