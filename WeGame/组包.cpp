#include "pch.h"
#include "���.h"

#include "��д.h"
#include "��ϷCall.h"
#include "����.h"
#include "�ṹ.h"

static ByteArr packData;

VOID ����Call(_int64 �������)
{
	packData = _AppendToBytes(packData, { 72, 131, 236, 96 });

	packData = _AppendToBytes(packData, { 186 });
	packData = _AppendToBytes(packData, _IntToBytes(�������, 4));

	packData = _AppendToBytes(packData, { 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(������ַ, 8));

	packData = _AppendToBytes(packData, { 72, 139, 9 });

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
}

VOID ����Call(__int64 ���ܲ���, int  ���ܳ���)
{
	packData = _AppendToBytes(packData, { 73, 199, 192 });
	packData = _AppendToBytes(packData, _IntToBytes(���ܳ���, 4));

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(���ܲ���, 8));

	packData = _AppendToBytes(packData, { 72, 137, 68, 36, 32 });
	packData = _AppendToBytes(packData, { 72, 141, 84, 36, 32 });

	packData = _AppendToBytes(packData, { 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(������ַ, 8));

	packData = _AppendToBytes(packData, { 72, 139, 9 });

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
}

VOID ����Call()
{
	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
	packData = _AppendToBytes(packData, { 72, 131, 196, 96 });
	���ִ��(packData);
	packData.clear();
}

// λ�� 0��ɫ1 λ��1��ɫ2
VOID ���ѡ���ɫ(int λ��)
{
	if (λ�� < 0) {
		return;
	}
	����Call(4);
	����Call(λ��, 2);
	����Call();
}

VOID ����ֽ�(int װ��λ��)
{
	if (װ��λ�� < 0)
	{
		return;
	}
	����Call(26);
	����Call(0, 1);
	����Call(65535, 2);
	����Call(317, 4);
	����Call(1, 1);
	����Call(װ��λ��, 2);
	����Call();
}

VOID ���ʰȡ(int ��Ʒ��ַ)
{
	if (��Ʒ��ַ < 0) {
		return;
	}
	����Call(43);
	����Call(��Ʒ��ַ, 4);
	����Call(0, 1);
	����Call(1, 1);
	����Call(566, 2);
	����Call(291, 2);
	����Call(9961, 2);
	����Call(553, 2);
	����Call(285, 2);
	����Call(18802, 2);
	����Call(24743, 2);
	����Call();
}

VOID ������ؽ�ɫ()
{
	����Call(7);
	����Call();
}

VOID ���ѡͼ()
{
	����Call(15);
	����Call(0, 4);
	����Call();
}

VOID �����ͼ(int ���, int �Ѷ�, int ��Ԩ, int ��ϰ)
{
	����Call(16);
	����Call(���, 4);
	����Call(�Ѷ�, 1);
	����Call(0, 2);
	����Call(��Ԩ, 1);//  ' 0���� 1��Ԩ
	����Call(��ϰ, 1);//  ' 0���� 1��ϰ
	����Call(65535, 2);
	����Call(0, 4);
	����Call(0, 1);
	����Call(0, 4);//  ' ����
	����Call(0, 1);
	����Call(0, 4);
	����Call();
}

VOID �������(int ��, int ��)
{
	����Call(69);
	����Call();
	����Call(70);
	����Call();
	����Call(71);
	����Call(��, 1);
	����Call(��, 1);
	����Call();
	����Call(1426);
	����Call();
}

VOID �����ͼ()
{
	����Call(42);
	����Call();
}

VOID �����ͼ(int X, int Y)
{
	����Call(45);
	����Call(X, 1);
	����Call(Y, 1);
	����Call(0, 4);
	����Call(0, 4);
	����Call(0, 1);
	for (int i = 1; i <= 9; i++)
	{
		����Call(0, 2);
	}
	for (int i = 1; i <= 8; i++)
	{
		����Call(0, 4);
	}
	for (int i = 1; i <= 7; i++)
	{
		����Call(0, 2);
	}
	����Call(0, 4);
	for (int i = 1; i <= 3; i++)
	{
		����Call(0, 2);
	}
	for (int i = 1; i <= 3; i++)
	{
		����Call(0, 4);
	}
	����Call(0, 2);
	����Call(0, 1);
	����Call();
}

VOID ����ƶ�(int ���ͼID, int С��ͼID, int ����X����, int ����Y����)
{
	����Call(36);
	����Call(���ͼID, 4);
	����Call(С��ͼID, 1);
	����Call(����X����, 2);
	����Call(����Y����, 2);
	����Call(5, 1);
	����Call(38, 4);
	����Call(2, 2);
	����Call(0, 4);
	����Call(0, 1);
	����Call();
}


void �������(int ��Ʒλ��, int ��Ʒ����)
{
	int �̵���, У����ֵ;
	�̵��� = 317;
	У����ֵ = ��Ʒλ�� + ��Ʒ����;
	У����ֵ = У����ֵ * 2 + 1;
	if (��Ʒ���� == NULL)
	{
		��Ʒ���� = 1;
	}
	����Call(22);
	��ֵCall(0, 1);
	��ֵCall(��Ʒλ��, 2);
	��ֵCall(��Ʒ����, 4);
	��ֵCall(�̵���, 4);
	��ֵCall(У����ֵ, 4);
	��ֵCall(27, 4);
	����Call();
}


void ��ֵCall(LONGLONG ��ַ, int ����)
{
	LONGLONG* pSendvalue = &��ַ;
	��ԿCall((LONGLONG)pSendvalue, ����);
}

void ��ԿCall(ULONG64 ��ͷ, int ����)
{
	Func_CALL(��ԿCALL, *(ULONG*)������ַ, ��ͷ, ����);
}


void ǿ�ƹ�ͼ(int �������, int ��������)
{
	����Call(45);
	��ֵCall(�������, 1);
	��ֵCall(��������, 1);
	��ֵCall(1465, 4);
	��ֵCall(214, 4);
	��ֵCall(0, 1);
	��ֵCall(35812, 2);
	��ֵCall(7, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(247, 2);
	��ֵCall(30, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 2);
	��ֵCall(30, 2);
	��ֵCall(11, 2);
	��ֵCall(0, 2);
	��ֵCall(0, 4);
	��ֵCall(30, 2);
	��ֵCall(41, 2);
	��ֵCall(3, 2);
	��ֵCall(250184, 8);
	��ֵCall(24189, 4);
	��ֵCall(0, 2);
	��ֵCall(0, 1);
	����Call();
}


void �������()
{
	����Call(1449);
	����Call();
}

void ����س�()
{
	����Call(42);
	����Call();
}

void ͨ�ط���()
{
	����Call(69);
	����Call();
	����Call(70);
	����Call();
	����Call(71);
	��ֵCall(0, 1);
	��ֵCall(0, 1);
	����Call();
}


void ��ȡ����()
{
	����Call(1426);
	����Call();
}




void �ƶ������ϳ����ſ�()
{
	����Call(36);
	��ֵCall(126, 4);
	��ֵCall(2, 1);
	��ֵCall(26, 2);
	��ֵCall(335, 2);

	��ֵCall(5, 1);
	��ֵCall(38, 4);
	��ֵCall(2, 2);
	��ֵCall(0, 4);
	��ֵCall(0, 1);
	����Call();
}

void ���Ͻ�ͼ(ULONG ˼��λ��)
{

	����Call(1782);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 1);
	��ֵCall(0, 1);
	��ֵCall(˼��λ��, 4);
	����Call();

	����Call(1782);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(0, 4);
	��ֵCall(1, 1);
	��ֵCall(2, 1);
	��ֵCall(˼��λ��, 4);
	����Call();

}

void ˾�Ϸֽ����(ULONG λ��)
{
	����Call(26);
	��ֵCall(47, 1);
	��ֵCall(-1, 2);
	��ֵCall(400001144, 4);
	��ֵCall(1, 1);
	��ֵCall(λ��, 2);
	����Call();
}


void ���_�����ƶ�(������ �������)
{
	����Call(36);
	��ֵCall(�������.����.x, 4);
	��ֵCall(�������.����.y, 1);
	��ֵCall(�������.λ��.x, 2);
	��ֵCall(�������.λ��.y, 2);
	��ֵCall(5, 1);
	��ֵCall(38, 4);
	��ֵCall(2, 2);
	��ֵCall(0, 4);
	��ֵCall(0, 1);
	����Call();
}