#pragma once
#include <winsvc.h>
#include "tlhelp32.h"

#include <vector>
using namespace std;


typedef int ������;
typedef __int64 ��������;
typedef float С����;
typedef double ˫���ȸ�����;
typedef bool �߼���;
typedef char �ı���;
typedef PVOID �ӳ���ָ��;

#define ע���ȼ� RegisterHotKey 
// RegisterHotKey(NULL, 1, 0, VK_HOME);
// RegisterHotKey(NULL, 1, MOD_ALT, VK_LEFT);
// RegisterHotKey(NULL, 0xC005, MOD_CONTROL, VK_LEFT);

#define ��Ϣ�� MessageBoxA
// MessageBoxA(NULL, "���ť�¼�", "����", MB_OK);

#define �رն��� CloseHandle

#define �����߳� CreateThread
// �����߳�(NULL, 0, (LPTHREAD_START_ROUTINE)������, NULL, 0, &�߳�id);

#define ����ʱ�� SetTimer
// HWND hWnd = FindWindow(TEXT("���³�����ʿ"), TEXT("���³�����ʿ"));
// SetTimer(hWnd, 1, Ƶ��, (TIMERPROC)������);
#define ����ʱ�� KillTimer
// KillTimer(hWnd, 1);

#define �ֽڼ� vector<int>
#define ��� printf
#define debug OutputDebugString

//#define д���� WritePrivateProfileStringW
//#define ������ GetPrivateProfileIntA
// д����(L"����ȫ��", L"����", L"48102", L"C:\\���.ini");
// ������("����ȫ��", "����", 0, "c:\\���.ini");


DWORD _GetProcessId(LPCWSTR ����);

CString _IntToCString(int value);

char* _AnsiToUnicode(char* str);

CString _UnicodeToAnsi(vector<byte> vby);

CString _GetDesktopPath();

VOID _WriteConfig(CString ��, CString ��, CString ֵ);

DWORD _ReadConfig(CString ��, CString ��);

VOID _InitConfig();

VOID _Long64ToBytes(DWORD64 i, BYTE* bytes);

HANDLE _CreateThread(PVOID �߳��ӳ���);

BOOL _DeleteThread(HANDLE �߳̾��);

BYTE _ConvertHexChar(BYTE ch);

INT _Rand(int min, int max);

CString _GetCurrentTime();

VOID _DebugStringA(const wchar_t* lpcwszOutputString, ...);
VOID _DebugStringW(const wchar_t* lpcwszOutputString, ...);

VOID _Int64ToBytes(DWORD64 num, unsigned char* bytes);
DWORD64 _BytesToInt64(const unsigned char* bytes);