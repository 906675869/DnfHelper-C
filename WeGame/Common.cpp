#include "pch.h"
#include "Common.h"

DWORD _GetProcessId(LPCWSTR ����) {
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnap) {
		return 0;
	}

	if (Process32First(hSnap, &pe))
	{
		while (Process32Next(hSnap, &pe)) {
			if (lstrcmpi(����, pe.szExeFile) == 0) {
				return pe.th32ProcessID;
			}
		}
	}
	CloseHandle(hSnap);
	return 0;
}

CString _IntToCString(int value)
{
	CString str;
	str.Format(L"%d", value);
	return str;
}

char* _AnsiToUnicode(char* str)
{
	int dwNum = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	char* pwText;
	pwText = new char[(__int64)dwNum * 2];
	MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)pwText, dwNum);
	return pwText;
}

CString _UnicodeToAnsi(vector<byte> vby)
{
	int length = (int)vby.size();
	byte* str = new byte[vby.size()]();
	for (int i = 0; i < length; ++i)
	{
		str[i] = vby[i];
	}
	length = length / 2;
	length = ::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, NULL, 0, NULL, NULL);
	char* resultCha = new char[(__int64)length + 1]();
	::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, resultCha, length, NULL, NULL);
	CString result(resultCha);
	return result;
}

CString _GetDesktopPath()
{
	char desktop[MAX_PATH];
	::SHGetSpecialFolderPathA(0, desktop, CSIDL_DESKTOPDIRECTORY, 0);
	CString path(desktop);
	return path + L"\\";
}
VOID _WriteConfig(CString ��, CString ��, CString ֵ)
{
	::WritePrivateProfileString(��, ��, ֵ, _GetDesktopPath() + L"WeGame.ini");
}
DWORD _ReadConfig(CString ��, CString ��)
{
	DWORD  result;
	result = GetPrivateProfileIntW(��, ��, 0, _GetDesktopPath() + L"WeGame.ini");
	return result;
}

VOID _InitConfig()
{
	_WriteConfig(L"�Զ�����", L"ˢͼ��ʽ", L"1");
	_WriteConfig(L"�Զ�����", L"��ɫ����", L"1");
	_WriteConfig(L"�Զ�����", L"�������", L"104");
	_WriteConfig(L"�Զ�����", L"�����ȼ�", L"4");
	_WriteConfig(L"�Զ�����", L"˳ͼ��ʽ", L"1");


	_WriteConfig(L"ȫ������", L"���ܴ���", L"70231");
	_WriteConfig(L"ȫ������", L"�����˺�", L"5201314");
	_WriteConfig(L"ȫ������", L"����Ƶ��", L"500");
	_WriteConfig(L"ȫ������", L"���ܸ���", L"3");
}

void _IntToByte(int i, byte* bytes)
{
	size_t length = sizeof(int);
	// ��ʼ������
	memset(bytes, 0, sizeof(byte) * length);
	bytes[0] = (byte)(0xff & i);
	bytes[1] = (byte)((0xff00 & i) >> 8);
	bytes[2] = (byte)((0xff0000 & i) >> 16);
	bytes[3] = (byte)((0xff000000 & i) >> 24);
	return;
}

VOID _Long64ToBytes(DWORD64 i, BYTE *bytes)
{
	size_t length = sizeof(DWORD64);
	memset(bytes, 0, sizeof(BYTE) * length);
	bytes[0] = (BYTE)(0xff & i);
	bytes[1] = (BYTE)((0xff00 & i) >> 8);
	bytes[2] = (BYTE)((0xff0000 & i) >> 16);
	bytes[3] = (BYTE)((0xff000000 & i) >> 24);
	bytes[4] = (BYTE)((0xff00000000 & i) >> 32);
	bytes[5] = (BYTE)((0xff0000000000 & i) >> 40);
	bytes[6] = (BYTE)((0xff000000000000 & i) >> 48);
	bytes[7] = (BYTE)((0xff00000000000000 & i) >> 56);
}

HANDLE _CreateThread(PVOID �߳��ӳ���)
{
	HANDLE handle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)�߳��ӳ���, NULL, 0, 0);
	return handle;
}
BOOL _DeleteThread(HANDLE �߳̾��)
{
	if (CloseHandle(�߳̾��)) {
		::TerminateThread(�߳̾��, 0);
	}
	return true;
}

//ת��16����
BYTE _ConvertHexChar(BYTE ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else
		return -1;
}

//���������Сֵ-���ֵ
INT _Rand(int min, int max)
{
	int m;
	m = (max - min);
	m = min + (int)double(rand()) / RAND_MAX * m;
	return m;
}

// ��ȡ��ǰʱ��
CString _GetCurrentTime() 
{
	CString str;
	CTime tm(CTime::GetCurrentTime());
	return tm.Format(L"WeGame��%Y��%m��%d�� %X");
}
