#pragma once
#include <winsvc.h>

class ����
{
public:
	����();
	~����();

public:
	DWORD dwLastError;   //���Ĵ���
	HANDLE hDriver;      //�������
	SC_HANDLE hSCManager;  //SCM���
	SC_HANDLE hService;    //������

public:

	BOOL ��������(LPCWSTR �����ļ�·��, LPCWSTR ������, LPCWSTR ������ʾ��);

	//example: \\\\.\\xxoo
	BOOL Open����(LPCWSTR pLinkName);

	BOOL ж������(LPCWSTR ������);

	// ����ͨѶ
	BOOL IoControl(DWORD dwIoCode, PVOID InBuff, DWORD InBuffLen, PVOID OutBuff, DWORD OutBuffLen, DWORD* RealRetBytes);
};

extern ���� drive;