#include "pch.h"
#include "GetGameData.h"
#include "ReadWrite.h"

int GetGameData::����(__int64 ����ָ��)
{
	// ������� = λ���(_ReadLong(����ָ��), 0x1F2A025C);
	// ������� = ������� - 4;
	// ����((����)�������);
	return 0;
}

VOID GetGameData::����(__int64 ����ָ��, int �޸���ֵ)
{
	// �������� = �޸���ֵ + 4
	// �������� = λ��� (0x1F2A025C, ��������)
	// _WriteLong(����ָ��, ��������)
}

int GetGameData::ȡ��Ϸ״̬()
{
	return  _ReadInt(��Ϸ״̬);
}

bool GetGameData::ȡ�Ƿ���()
{
	if (����(_ReadLong(_ReadLong(_ReadLong(�����ַ) + ��ͼƫ��) + 16) + �Ƿ���) == 0) {
		return true;
	}
	return false;
}

bool GetGameData::ȡ�Ƿ�ͨ��()
{
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	int �ж���ֵ = _ReadInt(�������� + �����ж�);
	if(�ж���ֵ == 2 || �ж���ֵ == 0) {
		return true;
	}
	return false;
}
������ GetGameData::ȡBOSS����()
{
	������ ��������;
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	��������.x = ����(�������� + BOSS����X);
	��������.y = ����(�������� + BOSS����Y);
	return ��������;
}

������ GetGameData::ȡ��ǰ����() 
{
	������ ��������;
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	��������.x = _ReadInt(�������� + ��ǰ����X);
	��������.y = _ReadInt(�������� + ��ǰ����Y);
	return ��������;
}

int GetGameData::ȡ��ͼ���() 
{
	return _ReadInt(�������);
}

int GetGameData::ȡ��ɫƣ��() 
{
	return ����(���ƣ��) - ����(��ǰƣ��);
}

int GetGameData::ȡ��ɫ�ȼ�(){
	return _ReadInt(��ɫ�ȼ�);
}