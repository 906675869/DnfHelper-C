#include "pch.h"
#include "GetGameData.h"
#include "ReadWrite.h"

int ����(__int64 ����ָ��)
{
	int temp = _ReadInt(����ָ��);
	temp = temp ^ 0x1F2A025C;
	temp -= 4;
	return temp;
}

VOID ����(__int64 ����ָ��, int �޸���ֵ)
{
	����ָ�� += 4;
	����ָ�� = ����ָ�� ^ 0x1F2A025C;
	_WriteLong(����ָ��, ����ָ��);
}

int ȡ��Ϸ״̬()
{
	return  _ReadInt(��Ϸ״̬);
}

bool ȡ�Ƿ����()
{
	if (_ReadLong(_ReadLong( +�����ַ) + ��ͼƫ��) == 0)
	{
		return true;
	}
	return false;
}

bool ȡ�Ƿ���()
{
	if (����(_ReadLong(_ReadLong(_ReadLong(�����ַ) + ��ͼƫ��) + 16) + �Ƿ���) == 0) 
	{
		return true;
	}
	return false;
}

bool ȡ�Ƿ�BOSS��()
{
	������ ��ǰ = ȡ��ǰ����();
	������ BOSS = ȡBOSS����();
	if (��ǰ.x == BOSS.x && ��ǰ.y == BOSS.y)
	{
		return true;
	}
	return false;
}

bool ȡ�Ƿ�ͨ��()
{
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	int �ж���ֵ = _ReadInt(�������� + �����ж�);
	if(�ж���ֵ == 2 || �ж���ֵ == 0) 
	{
		return true;
	}
	return false;
}
������ ȡBOSS����()
{
	������ ��������;
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	��������.x = ����(�������� + BOSS����X);
	��������.y = ����(�������� + BOSS����Y);
	return ��������;
}

������ ȡ��ǰ����() 
{
	������ ��������;
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	��������.x = _ReadInt(�������� + ��ǰ����X);
	��������.y = _ReadInt(�������� + ��ǰ����Y);
	return ��������;
}

int ȡ��ͼ���() 
{
	return _ReadInt(�������);
}

__int64 ȡ��ɫƣ��()
{
	return ����(���ƣ��) - ����(��ǰƣ��);
}

int ȡ��ɫ�ȼ�(){
	return _ReadInt(��ɫ�ȼ�);
}