#include "pch.h"
#include "MapTraversal.h"
#include "Common.h"
#include "ReadWrite.h"
#include "GetGameData.h"
#include "GameBulletin.h"
#include "GameCall.h"

vector<__int64> ��������()
{
	vector<__int64> ȫ_����;

	if (ȡ��Ϸ״̬() != 3)
	{
		return ȫ_����;
	}
	__int64 �׵�ַ_ = _ReadLong(_ReadLong(_ReadLong(_ReadLong(GetPersonAddr()) + ��ͼƫ��) + 16) + ��ͼ��ʼ2);
	__int64 β��ַ_ = _ReadLong(_ReadLong(_ReadLong(_ReadLong(GetPersonAddr()) + ��ͼƫ��) + 16) + ��ͼ����2);
	int �������� = (int)(β��ַ_ - �׵�ַ_) / 16;
	for (int i = 1; i <= ��������; i++)
	{
		__int64 �����ַ = _ReadLong(_ReadLong(�׵�ַ_ + i * 16) + 16) - 32;
		int �������� = _ReadInt(�����ַ + ����ƫ��);
		int ������Ӫ = _ReadInt(�����ַ + ��Ӫƫ��);
		int ������� = _ReadInt(�����ַ + ����ƫ��);
		int ����Ѫ��_ = _ReadInt(�����ַ + ����Ѫ��);
		if (�������� == 529 || �������� == 273)
		{
			if (�����ַ == _ReadLong(GetPersonAddr()))
			{
				continue;
			}
			if (������Ӫ != 0 && ������� != 0 && ����Ѫ��_ != 0)
			{
				ȫ_����.push_back(�����ַ);
			}
		}
	}
	return ȫ_����;
}

VOID ȫ������() {
	while (true)
	{
		// ����ȫ��();
		Sleep(_ReadConfig(L"ȫ������",L"����Ƶ��"));
		����Call(0, 39002, 0, 0, 0, 0, 0);
	}
}

������ ������(__int64 ��ȡָ��)
{
	������ ����;
	__int64 ָ��;

	int ���� = _ReadInt(��ȡָ�� + ����ƫ��);
	if (���� == 273)
	{
		ָ�� = _ReadLong(��ȡָ�� + ��ȡ����);
		����.x = _ReadInt(ָ�� + 0);
		����.y = _ReadInt(��ȡָ�� + ��ȡ����);
		����.z = _ReadInt(��ȡָ�� + ��ȡ����);
		return ����;
	}
	ָ�� = _ReadLong(��ȡָ�� + ��������);
	����.x = _ReadInt(ָ�� + 32);
	����.y = _ReadInt(ָ�� + 36);
	����.z = _ReadInt(ָ�� + 40);
	return ����;
}

VOID ����ȫ��()
{
	//������ ��������;

	vector<__int64> �������� = ��������();
	for (int i = 1; i <= ��������.size(); i++)
	{
		��������.pop_back();
		//�������� = ������();
	}
}