#pragma once

#include "Ioc.h"

class Vu����
{
public:
	template<class T>
	T ���ڴ�(DWORD ����ID, DWORD64 ���̵�ַ)
	{
		T buffer;
		VU_�ڴ�_���ֽڼ�(����ID, ���̵�ַ, &buffer, sizeof(T));
		return buffer;
	}

	template <class T>
	BOOL д�ڴ�(DWORD ����ID, DWORD64 ���̵�ַ, T д������) {
		return VU_�ڴ�_д�ֽڼ�(����ID, ���̵�ַ, &д������, sizeof(T));
	}


	VOID �����������(HANDLE hDrv);
	ULONG64 Ч����Ч��(const char* key);
	ULONG64 VU_�ڴ�_�ö�дģʽ(DWORD ģʽ, DWORD ����);
	//ö��ָ������ģ�� 
	DWORD64	VU_�ڴ�_ȡģ���ַ(DWORD pid, const char* moduleName);
	//���ڴ溯�����Լ���װ
	BOOL VU_�ڴ�_���ֽڼ�(DWORD pid, PVOID addr, PVOID pBuf, INT32 size);
	//д�ڴ溯�����Լ���װ
	BOOL VU_�ڴ�_д�ֽڼ�(DWORD pid, PVOID addr, PVOID pBuf, INT32 size);
	DWORD64 VU_�ڴ�_����(DWORD ����ID, DWORD64 ���̵�ַ, DWORD64 ���볤��, DWORD64 �ڴ�����, BOOL �Ƿ�����);
	DWORD64 VU_�ڴ�_�ͷ�(DWORD ����ID, DWORD64 ���̵�ַ, DWORD64 �ڴ泤��, BOOL �Ƿ�����);
	DWORD64 VU_�ڴ�_�޸�����(DWORD ����ID, DWORD64 ��ַ, DWORD64 ����, DWORD64 �ڴ�����);
	DWORD64 VU_�ڴ�_��ѯ����(DWORD ����ID, DWORD64 ��ַ);


	DWORD64 VU_����ע��CALL_�����̻߳�ȡģʽ(DWORD64 ģʽ);
	DWORD64 VU_Զ��ע��CALL(DWORD ����ID, PBYTE CALL����, DWORD CALL���볤��, BOOL Ӳ������ִ��);
	DWORD64 VU_Զ��ִ��CALL(DWORD ����ID, DWORD64 Ŀ���ַ, DWORD64 ������ַ);
	DWORD64 VU_����ע��CALL(DWORD ����ID, PBYTE CALL����, DWORD CALL���볤��, DWORD �߳�ID, BOOL Ӳ������ִ��);
	DWORD64 VU_����ִ��CALL(DWORD ����ID, DWORD64 Ŀ���ַ, DWORD64 ������ַ, DWORD �߳�ID);

	BOOL VU_����_��װ();

	BOOL VU_�����ļ�_��װ();
	BOOL VU_�����ļ�_ж��();
	DWORD64 VU_�����ļ�_�ļ�(CHAR* �ļ�·��);
	DWORD64 VU_�����ļ�_Ŀ¼(CHAR* Ŀ¼·��);


	BOOL VU_����_��װ();
	BOOL VU_����_ж��();
	BOOL VU_����_����_��ʼ(DWORD64 ����ID, BOOL �Ƿ񱣻�����);
	BOOL VU_����_����_����(DWORD64 ����ID);


	BOOL VU_����_����_��ʼ(DWORD64 ���ھ��, DWORD64 ����ID);
	BOOL VU_����_����_����(DWORD64 ���ھ��, DWORD64 ����ID);
	BOOL VU_����_��Ϸ_��ʼ(DWORD64 ���ھ��, DWORD64 ����ID);
	BOOL VU_����_��Ϸ_����(DWORD64 ���ھ��, DWORD64 ����ID);

	BOOL VU_Ӳ��_�޸�Ӳ�����(CHAR* ���, DWORD64 �ı�����);
	BOOL VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����);
	BOOL VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����);
	BOOL VU_Ӳ��_�޸��������(CHAR* ���, DWORD64 �ı�����);
	BOOL VU_Ӳ��_�޸��Կ����(CHAR* ���, DWORD64 �ı�����);	
};