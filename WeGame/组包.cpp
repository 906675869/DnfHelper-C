#include "pch.h"
#include "组包.h"

#include "读写.h"
#include "游戏Call.h"
#include "引用.h"
#include "结构.h"

static ByteArr packData;

VOID 缓冲Call(_int64 缓冲参数)
{
	packData = _AppendToBytes(packData, { 72, 131, 236, 96 });

	packData = _AppendToBytes(packData, { 186 });
	packData = _AppendToBytes(packData, _IntToBytes(缓冲参数, 4));

	packData = _AppendToBytes(packData, { 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(发包基址, 8));

	packData = _AppendToBytes(packData, { 72, 139, 9 });

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(缓冲CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
}

VOID 加密Call(__int64 加密参数, int  加密长度)
{
	packData = _AppendToBytes(packData, { 73, 199, 192 });
	packData = _AppendToBytes(packData, _IntToBytes(加密长度, 4));

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(加密参数, 8));

	packData = _AppendToBytes(packData, { 72, 137, 68, 36, 32 });
	packData = _AppendToBytes(packData, { 72, 141, 84, 36, 32 });

	packData = _AppendToBytes(packData, { 72, 185 });
	packData = _AppendToBytes(packData, _IntToBytes(发包基址, 8));

	packData = _AppendToBytes(packData, { 72, 139, 9 });

	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(加密CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
}

VOID 发包Call()
{
	packData = _AppendToBytes(packData, { 72, 184 });
	packData = _AppendToBytes(packData, _IntToBytes(发包CALL, 8));

	packData = _AppendToBytes(packData, { 255, 208 });
	packData = _AppendToBytes(packData, { 72, 131, 196, 96 });
	汇编执行(packData);
	packData.clear();
}

// 位置 0角色1 位置1角色2
VOID 组包选择角色(int 位置)
{
	if (位置 < 0) {
		return;
	}
	缓冲Call(4);
	加密Call(位置, 2);
	发包Call();
}

VOID 组包分解(int 装备位置)
{
	if (装备位置 < 0)
	{
		return;
	}
	缓冲Call(26);
	加密Call(0, 1);
	加密Call(65535, 2);
	加密Call(317, 4);
	加密Call(1, 1);
	加密Call(装备位置, 2);
	发包Call();
}

VOID 组包拾取(int 物品地址)
{
	if (物品地址 < 0) {
		return;
	}
	缓冲Call(43);
	加密Call(物品地址, 4);
	加密Call(0, 1);
	加密Call(1, 1);
	加密Call(566, 2);
	加密Call(291, 2);
	加密Call(9961, 2);
	加密Call(553, 2);
	加密Call(285, 2);
	加密Call(18802, 2);
	加密Call(24743, 2);
	发包Call();
}

VOID 组包返回角色()
{
	缓冲Call(7);
	发包Call();
}

VOID 组包选图()
{
	缓冲Call(15);
	加密Call(0, 4);
	发包Call();
}

VOID 组包进图(int 编号, int 难度, int 深渊, int 练习)
{
	缓冲Call(16);
	加密Call(编号, 4);
	加密Call(难度, 1);
	加密Call(0, 2);
	加密Call(深渊, 1);//  ' 0正常 1深渊
	加密Call(练习, 1);//  ' 0正常 1练习
	加密Call(65535, 2);
	加密Call(0, 4);
	加密Call(0, 1);
	加密Call(0, 4);//  ' 任务
	加密Call(0, 1);
	加密Call(0, 4);
	发包Call();
}

VOID 组包翻牌(int 行, int 列)
{
	缓冲Call(69);
	发包Call();
	缓冲Call(70);
	发包Call();
	缓冲Call(71);
	加密Call(行, 1);
	加密Call(列, 1);
	发包Call();
	缓冲Call(1426);
	发包Call();
}

VOID 组包出图()
{
	缓冲Call(42);
	发包Call();
}

VOID 组包过图(int X, int Y)
{
	缓冲Call(45);
	加密Call(X, 1);
	加密Call(Y, 1);
	加密Call(0, 4);
	加密Call(0, 4);
	加密Call(0, 1);
	for (int i = 1; i <= 9; i++)
	{
		加密Call(0, 2);
	}
	for (int i = 1; i <= 8; i++)
	{
		加密Call(0, 4);
	}
	for (int i = 1; i <= 7; i++)
	{
		加密Call(0, 2);
	}
	加密Call(0, 4);
	for (int i = 1; i <= 3; i++)
	{
		加密Call(0, 2);
	}
	for (int i = 1; i <= 3; i++)
	{
		加密Call(0, 4);
	}
	加密Call(0, 2);
	加密Call(0, 1);
	发包Call();
}

VOID 组包移动(int 大地图ID, int 小地图ID, int 城镇X坐标, int 城镇Y坐标)
{
	缓冲Call(36);
	加密Call(大地图ID, 4);
	加密Call(小地图ID, 1);
	加密Call(城镇X坐标, 2);
	加密Call(城镇Y坐标, 2);
	加密Call(5, 1);
	加密Call(38, 4);
	加密Call(2, 2);
	加密Call(0, 4);
	加密Call(0, 1);
	发包Call();
}


void 组包卖物(int 物品位置, int 物品数量)
{
	int 商店编号, 校验数值;
	商店编号 = 317;
	校验数值 = 物品位置 + 物品数量;
	校验数值 = 校验数值 * 2 + 1;
	if (物品数量 == NULL)
	{
		物品数量 = 1;
	}
	缓冲Call(22);
	数值Call(0, 1);
	数值Call(物品位置, 2);
	数值Call(物品数量, 4);
	数值Call(商店编号, 4);
	数值Call(校验数值, 4);
	数值Call(27, 4);
	发包Call();
}


void 数值Call(LONGLONG 地址, int 长度)
{
	LONGLONG* pSendvalue = &地址;
	秘钥Call((LONGLONG)pSendvalue, 长度);
}

void 秘钥Call(ULONG64 包头, int 长度)
{
	Func_CALL(秘钥CALL, *(ULONG*)发包基址, 包头, 长度);
}


void 强制过图(int 房间横轴, int 房间纵轴)
{
	缓冲Call(45);
	数值Call(房间横轴, 1);
	数值Call(房间纵轴, 1);
	数值Call(1465, 4);
	数值Call(214, 4);
	数值Call(0, 1);
	数值Call(35812, 2);
	数值Call(7, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(247, 2);
	数值Call(30, 2);
	数值Call(0, 2);
	数值Call(0, 2);
	数值Call(30, 2);
	数值Call(11, 2);
	数值Call(0, 2);
	数值Call(0, 4);
	数值Call(30, 2);
	数值Call(41, 2);
	数值Call(3, 2);
	数值Call(250184, 8);
	数值Call(24189, 4);
	数值Call(0, 2);
	数值Call(0, 1);
	发包Call();
}


void 组包跳过()
{
	缓冲Call(1449);
	发包Call();
}

void 组包回城()
{
	缓冲Call(42);
	发包Call();
}

void 通关翻牌()
{
	缓冲Call(69);
	发包Call();
	缓冲Call(70);
	发包Call();
	缓冲Call(71);
	数值Call(0, 1);
	数值Call(0, 1);
	发包Call();
}


void 领取奖励()
{
	缓冲Call(1426);
	发包Call();
}




void 移动到云上长安门口()
{
	缓冲Call(36);
	数值Call(126, 4);
	数值Call(2, 1);
	数值Call(26, 2);
	数值Call(335, 2);

	数值Call(5, 1);
	数值Call(38, 4);
	数值Call(2, 2);
	数值Call(0, 4);
	数值Call(0, 1);
	发包Call();
}

void 云上进图(ULONG 思南位置)
{

	缓冲Call(1782);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 1);
	数值Call(0, 1);
	数值Call(思南位置, 4);
	发包Call();

	缓冲Call(1782);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(0, 4);
	数值Call(1, 1);
	数值Call(2, 1);
	数值Call(思南位置, 4);
	发包Call();

}

void 司南分解组包(ULONG 位置)
{
	缓冲Call(26);
	数值Call(47, 1);
	数值Call(-1, 2);
	数值Call(400001144, 4);
	数值Call(1, 1);
	数值Call(位置, 2);
	发包Call();
}


void 组包_城镇移动(区域型 副本编号)
{
	缓冲Call(36);
	数值Call(副本编号.区域.x, 4);
	数值Call(副本编号.区域.y, 1);
	数值Call(副本编号.位置.x, 2);
	数值Call(副本编号.位置.y, 2);
	数值Call(5, 1);
	数值Call(38, 4);
	数值Call(2, 2);
	数值Call(0, 4);
	数值Call(0, 1);
	发包Call();
}