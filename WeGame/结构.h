#pragma once
#include "����.h"

struct ������ {
	DWORD x;
	DWORD y;
	DWORD z;
};

struct ������
{
	������ ����;
	������ λ��;
};

struct ��ͼ����
{
	CHAR* ��ͼ����;
	DWORD ��ͼ���;
	vector<DWORD> ��ͼͨ��;
	������ ��ʼ����;
	������ �յ�����;
	DWORD ��;
	DWORD ��;
	vector<������> ��ͼ�߷�;
	DWORD ����ƣ��;
	DWORD ͨ������;
	ULONG64 ��ʱ����;
};

struct ��Ϸ��ͼ
{
	������ ��ͼ����;
	BOOL ��ͼ���;
	BOOL ��ͼ�ұ�;
	BOOL ��ͼ�ϱ�;
	BOOL ��ͼ�±�;
	DWORD ��ͼͨ��;
	DWORD ������ɫ;
};

struct ��ͼ�ڵ�
{
	DWORD ��ͼF��;
	DWORD ��ͼG��;
	DWORD ��ͼH��;
	������ ��ǰ����;
	������ ��������;
};
