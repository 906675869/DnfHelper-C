#pragma once

#include <vector>
using namespace std;

VOID ���ý���ID(DWORD ����ID, HWND ���ھ��);

LPVOID ����_�ڴ�(DWORD ���볤��);

BOOL ���ֽڼ�(DWORD64 ��ַ, PVOID ����ֵ, INT32 д�볤��);

BOOL д�ֽڼ�(DWORD64 ��ַ, PVOID д��ֵ, INT32 д�볤��);

DWORD ��������(DWORD64 ��ַ);

DWORD64 ����������(DWORD64 ��ַ);

BOOL д������(DWORD64 ��ַ, DWORD ����);

BOOL д��������(DWORD64 ��ַ, DWORD64 ����);

BYTE* ���ֽڼ���(DWORD64 ��ַ, INT32 ����);

BOOL д�ֽڼ���(DWORD64 ��ַ, PBYTE д��ֵ, INT32 ����);

vector<BYTE> API_���ֽڼ�(DWORD64 ��ַ, INT32 ����);

BOOL API_д�ֽڼ�(DWORD64 ��ַ, vector<byte> ֵ);

VOID ���ִ��(BYTE *bytes);