#include "pch.h"
#include "GamePackage.h"
#include "Common.h"
#include "ReadWrite.h"
#include "GameCall.h"

static ByteArr packData;

VOID ����Call(_int64 �������)
{
	packData = _AppendToBytes(packData, ByteArr{ 72, 131, 236, 96 });

	packData = _AppendToBytes(packData, ByteArr{ 186 });
	packData = _AppendToBytes(packData, _IntToBytes(�������, 4));

	packData = _AppendToBytes(packData, ByteArr{ 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(������ַ, 8));

	packData = _AppendToBytes(packData, ByteArr{ 72, 139, 9 });

	packData = _AppendToBytes(packData, ByteArr{ 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, ByteArr{ 255, 208 });
}

VOID ����Call(__int64 ���ܲ���, int  ���ܳ���)
{
	packData = _AppendToBytes(packData, ByteArr{ 73, 199, 192 });
	packData = _AppendToBytes(packData, _IntToBytes(���ܳ���, 4));

	packData = _AppendToBytes(packData, ByteArr{ 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(���ܲ���, 8));

	packData = _AppendToBytes(packData, ByteArr{ 72, 137, 68, 36, 32 });
	packData = _AppendToBytes(packData, ByteArr{ 72, 141, 84, 36, 32 });

	packData = _AppendToBytes(packData, ByteArr{ 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(������ַ, 8));

	packData = _AppendToBytes(packData, ByteArr{ 72, 139, 9 });

	packData = _AppendToBytes(packData, ByteArr{ 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, ByteArr{ 255, 208 });
}

VOID ����Call()
{
	packData = _AppendToBytes(packData, ByteArr{ 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(����CALL, 8));

	packData = _AppendToBytes(packData, ByteArr{ 255, 208 });
	packData = _AppendToBytes(packData, ByteArr{ 72, 131, 196, 96 });
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