#include "pch.h"
#include "VuDriver.h"

static HANDLE g_hDrv = INVALID_HANDLE_VALUE;

VOID Vu����::�����������(HANDLE hDrv)
{
	g_hDrv = hDrv;
	return;
}

ULONG64 Vu����::Ч����Ч��(const char* key)
{
	IOCTL_BUFFER		pInfo = { 0 };
	pInfo.Buf = (ULONG64)key;
	ULONG64 �������� = 0;
	DWORD				returnLegth = 0;

	DeviceIoControl(g_hDrv, IOCTL_IO_FILE_CHECK, &pInfo, sizeof(pInfo), &��������, sizeof(��������), &returnLegth, NULL);

	return ��������;

	/*
	�������� > 0 = (�����������ɹ�!��)
	0 = (���������� - ����DLL·���Ƿ���ʵ�����Լ����ļ������Ƿ���ȷ��)
	-1= (�������벻���ڡ�)
	-2=(���˻����㡱)
	-3=(���۷�ʧ�ܡ�)
	-4=(���������)
	-5=(��������װʧ�ܡ�)
	-6=(����Ч��Ч��ʧ�ܡ�)
	����(��δ֪����)
	*/

}


ULONG64 Vu����::VU_�ڴ�_�ö�дģʽ(DWORD ģʽ, DWORD ����)
{
	BOOL				bResult = FALSE;
	ULONG64             returnCode = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER		pInfo = { 0 };
	pInfo.Addr = ģʽ;
	pInfo.Size = ����;
	bResult = DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_MOD, &pInfo, sizeof(pInfo), &returnCode, sizeof(returnCode), &returnLegth, NULL);
	return returnCode;
}

//ö��ָ������ģ�� 
DWORD64	Vu����::VU_�ڴ�_ȡģ���ַ(DWORD pid, const char* moduleName)
{
	BOOL				bResult = FALSE;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER_GetBase		pInfo = { 0 };
	ALLOCATE_FREE_MEMORY_RESULT result = { 0 };

	pInfo.ModelAddr = 0;
	pInfo.PID = (ULONG)pid;
	sprintf_s(pInfo.ModelName, "%s", moduleName);

	bResult = DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_GETMODULEBASE, &pInfo, sizeof(pInfo), &result, sizeof(result), &returnLegth, NULL);

	return result.address;

}


//���ڴ溯�����Լ���װ
BOOL Vu����::VU_�ڴ�_���ֽڼ�(DWORD pid, PVOID addr, PVOID pBuf, INT32 size)
{
	BOOL				bResult = FALSE;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER		pInfo = { 0 };

	pInfo.PID = pid;
	pInfo.Addr = (ULONG64)addr;
	pInfo.Size = size;

	bResult = DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_READ, &pInfo, sizeof(pInfo), pBuf, size, &returnLegth, NULL);

	return bResult;
}

//д�ڴ溯�����Լ���װ
BOOL Vu����::VU_�ڴ�_д�ֽڼ�(DWORD pid, PVOID addr, PVOID pBuf, INT32 size)
{

	BOOL				bResult = FALSE;
	DWORD				returnLegth = 0;


	DWORD len = sizeof(IOCTL_BUFFER_Write) + size;
	IOCTL_BUFFER_Write* pInfo = (IOCTL_BUFFER_Write*)malloc(len);
	if (!pInfo)
		return FALSE;

	ZeroMemory(pInfo, len);


	pInfo->PID = pid;
	pInfo->Addr = (ULONG64)addr;
	pInfo->Size = size;
	memcpy(pInfo->Buf, pBuf, size);

	bResult = DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_WRITE, pInfo, len, 0, 0, &returnLegth, NULL);

	free(pInfo);
	return bResult;
}


DWORD64 Vu����::VU_�ڴ�_����(DWORD ����ID, DWORD64 ���̵�ַ, DWORD64 ���볤��, DWORD64 �ڴ�����, BOOL �Ƿ�����)
{


	DWORD					returnLegth = 0;
	ALLOCATE_FREE_MEMORY	msgInfo = { 0 };
	ALLOCATE_FREE_MEMORY_RESULT result = { 0 };
	msgInfo.pid = ����ID;
	msgInfo.base = ���̵�ַ;
	msgInfo.size = ���볤��;
	msgInfo.protection = �ڴ�����;
	msgInfo.allocate = TRUE;
	msgInfo.physical = �Ƿ�����;
	msgInfo.type = MEM_COMMIT;

	DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_ALLOC, &msgInfo, sizeof(msgInfo), &result, sizeof(result), &returnLegth, NULL);
	return result.address;
}


DWORD64 Vu����::VU_�ڴ�_�ͷ�(DWORD ����ID, DWORD64 ���̵�ַ, DWORD64 �ڴ泤��, BOOL �Ƿ�����)
{


	DWORD					returnLegth = 0;
	ALLOCATE_FREE_MEMORY	msgInfo = { 0 };
	ALLOCATE_FREE_MEMORY_RESULT result = { 0 };
	msgInfo.pid = ����ID;
	msgInfo.base = ���̵�ַ;
	msgInfo.size = �ڴ泤��;
	msgInfo.protection = 0;
	msgInfo.allocate = FALSE;
	msgInfo.physical = �Ƿ�����;
	msgInfo.type = MEM_RELEASE;

	DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_ALLOC, &msgInfo, sizeof(msgInfo), &result, sizeof(result), &returnLegth, NULL);
	return result.address;
}


DWORD64 Vu����::VU_�ڴ�_�޸�����(DWORD ����ID, DWORD64 ��ַ, DWORD64 ����, DWORD64 �ڴ�����)
{
	DWORD64 pAddr = 0;

	DWORD					returnLegth = 0;
	ALLOCATE_FREE_MEMORY	msgInfo = { 0 };
	msgInfo.pid = ����ID;
	msgInfo.base = ��ַ;
	msgInfo.size = ����;
	msgInfo.protection = �ڴ�����;
	msgInfo.allocate = TRUE;
	msgInfo.physical = 1;
	msgInfo.type = MEM_RELEASE;

	DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_PROTECT, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}


DWORD64 Vu����::VU_�ڴ�_��ѯ����(DWORD ����ID, DWORD64 ��ַ)
{
	DWORD64 pAddr = 0;

	DWORD					returnLegth = 0;
	ALLOCATE_FREE_MEMORY	msgInfo = { 0 };
	msgInfo.pid = ����ID;
	msgInfo.base = ��ַ;
	msgInfo.size = 4096;
	msgInfo.protection = 64;
	msgInfo.allocate = FALSE;
	msgInfo.physical = 1;
	msgInfo.type = 0;

	DeviceIoControl(g_hDrv, IOCTL_IO_MEMORY_QUERY, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}


DWORD64 Vu����::VU_����ע��CALL_�����̻߳�ȡģʽ(DWORD64 ģʽ)
{

	BOOL				bResult = FALSE;
	DWORD64				pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Addr = ģʽ;

	DeviceIoControl(g_hDrv, IOCTL_IO_INJECT_SET_THREADMOD, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}

DWORD64 Vu����::VU_Զ��ע��CALL(DWORD ����ID, PBYTE CALL����, DWORD CALL���볤��, BOOL Ӳ������ִ��)
{
	DWORD len = sizeof(IOCTL_BUFFER_InjectCode) + CALL���볤��;
	IOCTL_BUFFER_InjectCode* pInfo = (IOCTL_BUFFER_InjectCode*)malloc(len);
	if (!pInfo)
		return FALSE;
	ZeroMemory(pInfo, len);
	pInfo->PID = ����ID;
	pInfo->isPhyMem = Ӳ������ִ��;
	pInfo->Size = CALL���볤��;

	memcpy(pInfo->Buf, CALL����, CALL���볤��);

	DWORD64 pAddr = 0;
	DWORD	returnLegth = 0;

	DeviceIoControl(g_hDrv, IOCTL_IO_INJECT_REMOTE_CALL, pInfo, len, &pAddr, sizeof(pAddr), &returnLegth, NULL);
	free(pInfo);
	return pAddr;

}


DWORD64 Vu����::VU_Զ��ִ��CALL(DWORD ����ID, DWORD64 Ŀ���ַ, DWORD64 ������ַ)
{
	DWORD64 pAddr = 0;
	DWORD	returnLegth = 0;
	IOCTL_BUFFER_InjectCode	msgInfo = { 0 };
	msgInfo.PID = ����ID;
	msgInfo.Size = ������ַ;
	msgInfo.Addr = Ŀ���ַ;

	DeviceIoControl(g_hDrv, IOCTL_IO_INJECT_REMOTE_CALLEX, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}

DWORD64 Vu����::VU_����ע��CALL(DWORD ����ID, PBYTE CALL����, DWORD CALL���볤��, DWORD �߳�ID, BOOL Ӳ������ִ��)
{
	DWORD len = sizeof(IOCTL_BUFFER_InjectCode) + CALL���볤��;
	IOCTL_BUFFER_InjectCode* pInfo = (IOCTL_BUFFER_InjectCode*)malloc(len);
	if (!pInfo)
		return FALSE;
	ZeroMemory(pInfo, len);

	pInfo->PID = ����ID;
	pInfo->isPhyMem = Ӳ������ִ��;
	pInfo->Size = CALL���볤��;

	memcpy(pInfo->Buf, CALL����, CALL���볤��);
	pInfo->Addr = �߳�ID;


	DWORD64 pAddr = 0;
	DWORD	returnLegth = 0;


	DeviceIoControl(g_hDrv, IOCTL_IO_INJECT_SUPER_CALL, pInfo, len, &pAddr, sizeof(pAddr), &returnLegth, NULL);
	free(pInfo);
	return pAddr;

}


DWORD64 Vu����::VU_����ִ��CALL(DWORD ����ID, DWORD64 Ŀ���ַ, DWORD64 ������ַ, DWORD �߳�ID)
{
	DWORD64 pAddr = 0;
	DWORD	returnLegth = 0;
	IOCTL_BUFFER_InjectCode	msgInfo = { 0 };
	msgInfo.PID = ����ID;
	msgInfo.Addr = Ŀ���ַ;
	msgInfo.Size = ������ַ;
	msgInfo.isPhyMem = �߳�ID;


	DeviceIoControl(g_hDrv, IOCTL_IO_INJECT_SUPER_CALLEX, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}


BOOL Vu����::VU_����_��װ()
{
	BOOL				bResult = FALSE;
	DWORD				returnLegth = 0;

	return DeviceIoControl(g_hDrv, IOCTL_IO_INPUT_INIT, 0, 0, 0, 0, &returnLegth, NULL);

}

BOOL Vu����::VU_�����ļ�_��װ()
{
	DWORD				returnLegth = 0;

	return DeviceIoControl(g_hDrv, IOCTL_IO_FILTER_INIT, 0, 0, 0, 0, &returnLegth, NULL);
}

BOOL Vu����::VU_�����ļ�_ж��()
{
	DWORD				returnLegth = 0;

	return DeviceIoControl(g_hDrv, IOCTL_IO_FILTER_UNINIT, 0, 0, 0, 0, &returnLegth, NULL);
}


DWORD64 Vu����::VU_�����ļ�_�ļ�(CHAR* �ļ�·��)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	CHAR strPath[MAX_PATH] = { 0 };
	sprintf_s(strPath, "\\??\\%s", �ļ�·��);
	msgInfo.Buf = (DWORD64)&strPath;
	DeviceIoControl(g_hDrv, IOCTL_IO_FILTER_FILE, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}

DWORD64 Vu����::VU_�����ļ�_Ŀ¼(CHAR* Ŀ¼·��)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };

	CHAR strPath[MAX_PATH] = { 0 };
	sprintf_s(strPath, "\\??\\%s", Ŀ¼·��);
	msgInfo.Buf = (DWORD64)&strPath;
	DeviceIoControl(g_hDrv, IOCTL_IO_FILTER_DIR, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
	return pAddr;
}





BOOL Vu����::VU_����_��װ()
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.PID = 1;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_BEGIN_OR_END, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_ж��()
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.PID = 0;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_BEGIN_OR_END, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_����_��ʼ(DWORD64 ����ID, BOOL �Ƿ񱣻�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.PID = ����ID;
	if (�Ƿ񱣻�����)
		msgInfo.Size = 100;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_PROCESS_BEGIN, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_����_����(DWORD64 ����ID)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.PID = ����ID;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_PROCESS_END, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}


BOOL Vu����::VU_����_����_��ʼ(DWORD64 ���ھ��, DWORD64 ����ID)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = ���ھ��;
	msgInfo.PID = ����ID;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_WINDOW_BEGIN, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_����_����(DWORD64 ���ھ��, DWORD64 ����ID)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = ���ھ��;
	msgInfo.PID = ����ID;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_WINDOW_END, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_��Ϸ_��ʼ(DWORD64 ���ھ��, DWORD64 ����ID)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = ���ھ��;
	msgInfo.PID = ����ID;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_GAME_BEGIN, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}

BOOL Vu����::VU_����_��Ϸ_����(DWORD64 ���ھ��, DWORD64 ����ID)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = ���ھ��;
	msgInfo.PID = ����ID;

	return DeviceIoControl(g_hDrv, IOCTL_IO_PROTECT_GAME_END, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}



BOOL Vu����::VU_Ӳ��_�޸�Ӳ�����(CHAR* ���, DWORD64 �ı�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = (DWORD64)���;
	msgInfo.Size = �ı�����;

	return DeviceIoControl(g_hDrv, IOCTL_IO_HARDWARE_DISK, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}


BOOL Vu����::VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = (DWORD64)���;
	msgInfo.Size = �ı�����;

	return DeviceIoControl(g_hDrv, IOCTL_IO_HARDWARE_VOLUMES, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}


BOOL Vu����::VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = (DWORD64)���;
	msgInfo.Size = �ı�����;

	return DeviceIoControl(g_hDrv, IOCTL_IO_HARDWARE_MAC, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}


BOOL Vu����::VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER				msgInfo = { 0 };
	msgInfo.Buf = (DWORD64)���;
	msgInfo.Size = �ı�����;

	return DeviceIoControl(g_hDrv, IOCTL_IO_HARDWARE_SMBOIS, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}


BOOL Vu����::VU_Ӳ��_�޸��Կ����(CHAR* ���, DWORD64 �ı�����)
{
	DWORD64 pAddr = 0;
	DWORD				returnLegth = 0;
	IOCTL_BUFFER		msgInfo = { 0 };
	msgInfo.Buf = (DWORD64)���;
	msgInfo.Size = �ı�����;

	return DeviceIoControl(g_hDrv, IOCTL_IO_HARDWARE_GPU, &msgInfo, sizeof(msgInfo), &pAddr, sizeof(pAddr), &returnLegth, NULL);
}