#include "pch.h"
#include "����.h"

DWORD ȡ����ID(TCHAR ����[]) {
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

CString �������ı�(int ֵ)
{
	CString str;
	str.Format(L"%d", ֵ);
	return str;
}

char* AnsiToUnicode(char* str)
{
	DWORD64 dwNum = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	char* pwText;
	pwText = new char[dwNum * 2];
	MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)pwText, dwNum);
	return pwText;
}

CString UnicodeתAnsi(vector<byte> vby)
{
	__int64 length = (int)vby.size();
	byte* str = new byte[vby.size()]();
	for (int i = 0; i < length; ++i)
	{
		str[i] = vby[i];
	}
	length = length / 2;
	length = ::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, NULL, 0, NULL, NULL);
	char* resultCha = new char[length + 1]();
	::WideCharToMultiByte(CP_ACP, NULL, (LPCWCH)str, length, resultCha, length, NULL, NULL);
	CString result(resultCha);
	return result;
}

CString ȡ����Ŀ¼()
{
	char desktop[MAX_PATH];
	::SHGetSpecialFolderPathA(0, desktop, CSIDL_DESKTOPDIRECTORY, 0);
	CString path(desktop);
	return path + L"\\";
}
VOID д������(CString ��, CString ��, CString ֵ)
{
	::WritePrivateProfileString(��, ��, ֵ, ȡ����Ŀ¼() + L"WeGame.ini");
}
DWORD ��������(CString ��, CString ��)
{
	DWORD  result;
	result = GetPrivateProfileIntW(��, ��, 0, ȡ����Ŀ¼() + L"WeGame.ini");
	return result;
}

VOID ��ʼ������()
{
	д������(L"�Զ�����", L"ˢͼ��ʽ", L"1");
	д������(L"�Զ�����", L"��ɫ����", L"1");
	д������(L"�Զ�����", L"�������", L"104");
	д������(L"�Զ�����", L"�����ȼ�", L"4");
	д������(L"�Զ�����", L"˳ͼ��ʽ", L"1");


	д������(L"ȫ������", L"���ܴ���", L"70231");
	д������(L"ȫ������", L"�����˺�", L"5201314");
	д������(L"ȫ������", L"����Ƶ��", L"500");
	д������(L"ȫ������", L"���ܸ���", L"3");
}

void intToByte(int i, byte* bytes)
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

VOID long64ToBytes(DWORD64 i, BYTE *bytes)
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

HANDLE �����߳�(PVOID �߳��ӳ���)
{
	HANDLE �߳̾�� = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)�߳��ӳ���, NULL, 0, 0);
	return �߳̾��;
}
BOOL �����߳�(HANDLE �߳̾��)
{
	//CloseHandle(�߳̾��);
	return ::TerminateThread(�߳̾��, 0);
}

//ת��16����
BYTE ConvertHexChar(BYTE ch)
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
int ȡ�����(int min, int max)
{
	int m;
	m = (max - min);
	m = min + (int)double(rand()) / RAND_MAX * m;
	return m;
}

CString ȡ����ʱ��() {
	CString str;
	CTime tm(CTime::GetCurrentTime());
	return tm.Format(L"WeGame��%Y��%m��%d�� %X");
}
