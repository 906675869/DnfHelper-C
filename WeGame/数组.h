#pragma once
#include "�ļ�.h"
#include "�ṹ.h"

struct �հ�����
{
	wstring ��_��������;
	HWND ��Ϸ���;
	WNDPROC ������Ϣ;
	������ ��_��ǰ����;
	������ ��_��������;
	int ��_��ͼ���;
	int ��_��ͼ�Ѷ�;
	int ��_��ͼ���;
	int ��_��������;
	int ��_��������;
	int ��_ʰȡ����;
	int ��_ʰȡ����;
	int ��_�հ��ƴ�;
	int ��_��Ʒ���;
	int ��_ͨ�ؼƴ�;

	vector<short>����ID;

};

extern �հ����� �հ�;

struct ��������
{
	wstring ��������;

	wstring ���ܴ���;
	wstring �����˺�;
	wstring ����Ƶ��;
	wstring ���ܸ���;
	wstring ���ܴ�С;

	wstring �Զ�ģʽ;
	wstring �������;
	wstring �����Ѷ�;

	wstring Ԥ��ƣ��;
	wstring ���淽ʽ;
	wstring ʰȡ��ʽ;
	wstring ˳ͼ��ʽ;



	wstring ��ɫװ��;
	wstring ��ɫװ��;
	wstring ��ɫװ��;
	wstring ��ɫװ��;
	wstring ʷʫװ��;
	wstring ����װ��;
	wstring ��˵װ��;

	wstring δ��ȫͼ;

};

extern �������� ����;

struct ȫ������
{
	bool ���ܿ���;
	bool ���ӿ���;
	bool �Զ�����;
	HANDLE �߳̾��;
	bool ����˳ͼ;
	int ������;
	int ˳ͼ�ƴ�;
	int ʰȡ����;
	int �������;
	int �����Ѷ�;

	int ��ǰλ��;
	int ��ɫ����;
	bool ��ɫ����;

	int ����1 = NULL;
	int ����2 = NULL;
	int ����3 = NULL;
	int �ظ� = NULL;

	int ˳ͼ����;

	int ���Ӵ���;

	bool ������ķ���;
	bool ���˳ͼ;
};

extern ȫ������ ȫ��;

struct ��������
{
	ULONG64 ����ָ��;
	ULONG64 ��ͼָ��;
	ULONG64 ����ָ��;
	ULONG64 ����Ѫ��;

	ULONG64 �׵�ַ;
	ULONG64 β��ַ;

	int ��������;
	int ��������;
	int ������Ӫ;

	ULONG64 ��Ʒָ��;

	size_t ��������;
	int ��������;

	int ���ܸ��� = NULL;

	wstring ��������;

	wstring ��Ʒ����;

	int ��Ʒ����;
	int ��Ʒ����;
	������ ����λ��;
};

struct ����ṹ
{
	ULONG64 �����ַ;
	ULONG64 �׵�ַ;
	ULONG64 β��ַ;
	int ��������;
	int �������;
	ULONG64 ����ָ��;
	int ��������;
	ULONG ����ȼ�;
	int �ֲ����;
	int ���񳤶�;
	LPCWSTR ��������;
	LPCWSTR ��������;
	int ���񸱱�;
	int �ֲ�����;
};

extern ����ṹ ����;

struct ��������
{
	ULONG64 ������ַ;
	ULONG64 �׵�ַ;
	int ��Ʒ����;
	ULONG64 װ��ָ��;
	int װ������;
	int װ������;
	LPCTSTR װ������;

	int ��ɫ���� = NULL;
	int ��ɫ���� = NULL;
	int ��ɫ���� = NULL;
	int ��ɫ���� = NULL;
	int ʷʫ���� = NULL;
	int ���߼��� = NULL;
	int ��˵���� = NULL;

};

struct  δ��ṹ
{
	ULONG64 ����ָ��;
	ULONG64 �׵�ַ;
	ULONG64 ��Ʒ��ַ;
	ULONG64 ��Ʒָ��;

	ULONG ��Ʒ����;

	ULONG ����;

	ULONG ˾������;
	ULONG ��������;

	ULONG ��Ʒ��ֵ;
	ULONG ��Ʒ����;


	ULONG ��Ʒλ��;

	LPCTSTR ��Ʒ����;

};

struct ��ͼ��
{
	vector<int> ͨ��;
	������ ��ʼ;
	������ �յ�;
	int ���;
	int �߶�;
	vector<������> �߷�;
	int ����;
};

struct ·����
{
	������ ����;
	bool ��� = false;
	bool �ұ� = false;
	bool �ϱ� = false;
	bool �±� = false;
	int ͨ��;
	int ��ɫ;
};

struct �ڵ���
{
	int F_��;
	int G_��;
	int H_��;
	������ ��ǰ;
	������ ����;
};