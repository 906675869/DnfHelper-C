#include "pch.h"
#include "�ж�.h"

#include "��д.h"
#include "��ϷCall.h"

int ����(__int64 ����ָ��)
{
	__int64 temp = _ReadLong(����ָ��);
	temp = temp ^ 0x1F2A025C;
	temp -= 4;
	return (int)temp;
}

VOID ����(__int64 ����ָ��, int �޸���ֵ)
{
	����ָ�� += 4;
	����ָ�� = ����ָ�� ^ 0x1F2A025C;
	_WriteLong(����ָ��, ����ָ��);
}

// 0ѡ�� 1���� 2ѡͼ 3ͼ�� 5ѡ��Ƶ��
int ȡ��Ϸ״̬()
{
	return  _ReadInt(��Ϸ״̬);
}

bool ȡ�Ƿ����()
{
	if (_ReadLong(_ReadLong(ȡ�������()) + ��ͼƫ��) == 0)
	{
		return true;
	}
	return false;
}

bool ȡ�Ƿ���()
{
	if (����(_ReadLong(_ReadLong(_ReadLong(ȡ�������()) + ��ͼƫ��) + 16) + �Ƿ���) == 0)
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

int ȡƣ��ֵ()
{
	return ����(���ƣ��) - ����(��ǰƣ��);
}

int ȡ��ɫ�ȼ�(){
	return _ReadInt(��ɫ�ȼ�);
}

CString ȡ��ͼ����()
{
	__int64 �������� = _ReadLong(_ReadLong(_ReadLong(������) + ʱ���ַ) + ����ƫ��);
	return _UnicodeToAnsi(_ReadByteArr(_ReadLong(�������� + ��ͼ����), 52));
}