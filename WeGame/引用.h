#pragma once

typedef ULONG64(__fastcall* _Func_Call)(
	ULONGLONG RCX__,
	ULONGLONG RDX__,
	ULONGLONG R8__,
	ULONGLONG R9__,
	ULONGLONG R10__,
	ULONGLONG R11__,
	ULONGLONG R12__,
	ULONGLONG R13__,
	ULONGLONG R14__,
	ULONGLONG R15__
	);

ULONG64 Func_CALL(ULONGLONG ADDR__, ULONGLONG RCX__ = 0, ULONGLONG RDX__ = 0, ULONGLONG R8__ = 0, ULONGLONG R9__ = 0, ULONGLONG R10__ = 0, ULONGLONG R11__ = 0, ULONGLONG R12__ = 0, ULONGLONG R13__ = 0, ULONGLONG R14__ = 0, ULONGLONG R15__ = 0);

int ȡ�����(int ��Сֵ, int ���ֵ);

wstring ���ı�(int ����ֵ);

ULONG64 �ڴ�����(size_t size);

void д�ֽڼ�(ULONG64 ��_�ڴ��ַ, vector<byte> ��_д������);

vector<byte> ���ֽڼ�(ULONG64  i, int λ�� = NULL);

vector<byte> ���ֽڼ�(ULONG64 ��_�ڴ��ַ, DWORD ��_��ȡ����);

wstring ȡ�ı��ұ�(wstring �ı�, size_t ��ֵ);

wstring ȡ�ı����(wstring �ı�, size_t ��ֵ);

wstring ͨ��ʱ��(int ��ַ);

void �ָ��ı�(const wstring& str, vector<wstring>& tokens, const wstring& delimiters);

double ��С����(ULONG64 ��_�ڴ��ַ);

DWORD ��������(ULONG64 ��_�ڴ��ַ);

ULONG64 ��������(ULONG64 ��_�ڴ��ַ);

BYTE ���ֽ���(ULONG64 ��_�ڴ��ַ);

BYTE ��������(ULONG64 ��_�ڴ��ַ);

void д������(ULONG64 ��_�ڴ��ַ, ULONG64 ��_д������);

void д�ֽ���(ULONG64 ��_�ڴ��ַ, BYTE ��_д������);

void д������(ULONG64 ��_�ڴ��ַ, DWORD ��_д������);

void дС����(ULONG64 ��_�ڴ��ַ, float ��_д������);

void д������(ULONG64 ��_�ڴ��ַ, WORD ��_д������);