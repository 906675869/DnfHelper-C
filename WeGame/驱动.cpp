#include "pch.h"
#include "����.h"


����::����() //���캯��
{
	//��ʼ������
	hSCManager = NULL;
	hService = NULL;
	hDriver = INVALID_HANDLE_VALUE;

	dwLastError = 0;
}

����::~����() //��������
{
	//�ͷ���Դ
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCManager);
	CloseHandle(hDriver);
}


BOOL ����::��������(LPCWSTR �����ļ�·��, LPCWSTR ������, LPCWSTR ������ʾ��) {

	BOOL result = false;

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hSCManager != NULL) {

		hService = CreateService(
			hSCManager,
			������,//����������ע����е�����
			������ʾ��,// ע������������ DisplayName ֵ
			SERVICE_ALL_ACCESS,// ������������ķ���Ȩ��
			SERVICE_KERNEL_DRIVER,// ��ʾ���صķ�������������
			SERVICE_DEMAND_START,// ע������������ Start ֵ
			SERVICE_ERROR_IGNORE,// ע������������ ErrorControl ֵ
			�����ļ�·��,// ע������������ ImagePath ֵ
			NULL, NULL, NULL, NULL, NULL);

		if (hService == NULL && GetLastError() == ERROR_SERVICE_EXISTS)  // �����Ѿ�����
		{
			hService = OpenService(hSCManager, ������, SERVICE_ALL_ACCESS);
		}
		if (hService != NULL)
		{
			BOOL �������� = StartService(hService, NULL, NULL);
			dwLastError = GetLastError();
			if (�������� || dwLastError == ERROR_SERVICE_ALREADY_RUNNING)
			{
				result = true;
			}
			else
			{
				CloseServiceHandle(hService);
			}
		}
		else
		{
			CloseServiceHandle(hSCManager);
		}
		
	}
	return result;
}

//example: \\\\.\\xxoo
BOOL ����::Open����(LPCWSTR pLinkName)
{
	if (hDriver != INVALID_HANDLE_VALUE)
	{
		return true;
	}
	hDriver = CreateFile(pLinkName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hDriver != INVALID_HANDLE_VALUE)
	{
		return true;
	}
	return false;
}

BOOL ����::ж������(LPCWSTR ������) {

	BOOL result = false;

	if (hSCManager != NULL) {
		if (hService != NULL) {
			SERVICE_STATUS ss;
			if (ControlService(hService, SERVICE_CONTROL_STOP, &ss))  // ֹͣ����
			{
				DeleteService(hService);
				CloseServiceHandle(hService);
				result = true;
			}
		}
		CloseServiceHandle(hSCManager);
	}

	return result;
}

BOOL ����::IoControl(DWORD dwIoCode, PVOID InBuff, DWORD InBuffLen, PVOID OutBuff, DWORD OutBuffLen, DWORD* RealRetBytes)
{
	return DeviceIoControl(hService, dwIoCode, InBuff, InBuffLen, OutBuff, OutBuffLen, RealRetBytes, NULL);
}