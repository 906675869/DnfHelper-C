#pragma once
#include <winsvc.h>
#include "tlhelp32.h"

#include <vector>
using namespace std;

// RegisterHotKey(NULL, 1, 0, VK_HOME);
// RegisterHotKey(NULL, 1, MOD_ALT, VK_LEFT);
// RegisterHotKey(NULL, 0xC005, MOD_CONTROL, VK_LEFT);

// MessageBoxA(NULL, "���ť�¼�", "����", MB_OK);

// CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)������, NULL, 0, &�߳�id);

// HWND hWnd = FindWindow(TEXT("���³�����ʿ"), TEXT("���³�����ʿ"));
// SetTimer(hWnd, 1, Ƶ��, (TIMERPROC)������);
// KillTimer(hWnd, 1);

#define ByteArr vector<byte>
#define debug OutputDebugString

DWORD _GetProcessId(LPCWSTR ����);

CString _IntToCString(int value);

char* _AnsiToUnicode(char* str);

CString _UnicodeToAnsi(vector<byte> vby);

CString _GetDesktopPath();

VOID _WriteConfig(CString ��, CString ��, CString ֵ);

DWORD _ReadConfig(CString ��, CString ��);

VOID _InitConfig();

HANDLE _CreateThread(PVOID �߳��ӳ���);

BOOL _DeleteThread(HANDLE �߳̾��);

BYTE _ConvertHexChar(BYTE ch);

INT _Rand(int min, int max);

CString _GetCurrentTime();

VOID _DebugStringA(const char* lpcszOutputString, ...);

VOID _DebugStringW(const wchar_t* lpcwszOutputString, ...);

ByteArr _IntToBytes(DWORD64 num, int lenght);

ByteArr _AppendToBytes(ByteArr oldBytes, ByteArr newBytes);

ByteArr ȡ�հ�ByteArr(int num);

ByteArr AnsiToUnicode(string str);