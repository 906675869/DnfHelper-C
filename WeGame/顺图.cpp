#include "pch.h"
#include "文件.h"
#include "引用.h"
#include "Address.h"
#include "游戏CALL.h"
#include "数组.h"
#include "组包.h"
#include "判断.h"
#include "寻路.h"
#include "配置.h"
#include "功能.h"
#include "公告.h"

void 漂移过图(int 方向编号)
{
	ULONG64 一级偏移, 临时数据, 坐标结构;
	一级偏移 = *(ULONG64*)人物基址;
	临时数据 = *(ULONG64*)房间编号;
	临时数据 = *(ULONG64*)(临时数据 + 时间基址);
	临时数据 = *(ULONG64*)(临时数据 + 顺图偏移);
	坐标结构 = 临时数据 + 方向编号 * 方向ID + 坐标顺图;


	//神话公告(L"指针：" + to_wstring(坐标结构));

	int 计算结构[6];
	计算结构[0] = *(ULONG*)(坐标结构 + 0);
	计算结构[1] = *(ULONG*)(坐标结构 + 4);
	计算结构[2] = *(ULONG*)(坐标结构 + 8);
	计算结构[3] = *(ULONG*)(坐标结构 + 12);
	if (方向编号 == 0)
	{
		计算结构[4] = 计算结构[0] + 计算结构[2] + 20;
		计算结构[5] = 计算结构[1] + 计算结构[3] / 2;
	}
	else if (方向编号 == 1)
	{
		计算结构[4] = 计算结构[0] - 20;
		计算结构[5] = 计算结构[1] + 计算结构[3] / 2;
	}
	else if (方向编号 == 2)
	{
		计算结构[4] = 计算结构[0] + 计算结构[2] / 2;
		计算结构[5] = 计算结构[1] + 计算结构[3] + 20;
	}
	else if (方向编号 == 3)
	{
		计算结构[4] = 计算结构[0] + 计算结构[2] / 2;
		计算结构[5] = 计算结构[1] - 20;
	}
	if (读配置(配置.顺图方式) == 1)
	{
		坐标Call(一级偏移, 计算结构[4], 计算结构[5], 0);
	}
	if (读配置(配置.顺图方式) == 2)
	{
		漂移Call(计算结构[4], 计算结构[5], 0, 1);
	}
	Sleep(300);
	if (读配置(配置.顺图方式) == 1)
	{
		坐标Call(一级偏移, 计算结构[0] + 计算结构[2] / 2, 计算结构[1], 0);
	}
	if (读配置(配置.顺图方式) == 2)
	{
		漂移Call(计算结构[0] + 计算结构[2] / 2, 计算结构[1], 0);
	}
}

void 组包强顺(int 过图方向)
{
	if (过图方向 == 0)
	{
		强制过图(收包.参_当前坐标.x - 1, 收包.参_当前坐标.y);
	}
	if (过图方向 == 1)
	{
		强制过图(收包.参_当前坐标.x + 1, 收包.参_当前坐标.y);
	}
	if (过图方向 == 2)
	{
		强制过图(收包.参_当前坐标.x, 收包.参_当前坐标.y - 1);
	}
	if (过图方向 == 3)
	{
		强制过图(收包.参_当前坐标.x, 收包.参_当前坐标.y + 1);
	}
}

void 过图调用(int 过图方向, int 过图方式)
{
	神话公告(L" 过图调用", 1);
	if (过图方向 < 0 || 过图方向 > 3)
	{
		return;
	}
	神话公告(L" 过图调用-执行", 1);
	if (过图方式 == NULL)
	{
		if (读配置(配置.顺图方式) == 1 || 读配置(配置.顺图方式) == 2)
		{
			++全局.顺图计次;
			if (全局.顺图计次 < 5)
			{
				漂移过图(过图方向);
			}
			else
			{
				组包强顺(过图方向);
			}
		}
		if (读配置(配置.顺图方式) == 3)
		{
			组包强顺(过图方向);
		}
	}
	else
	{
		组包强顺(过图方向);
	}
}

void 智能寻路(int 副本编号, int 任务编号)
{
	神话公告(L" 智能寻路", 1);
	神话公告(L"收包.参_当前坐标.x: " + 到文本(收包.参_当前坐标.x), 1);
	神话公告(L"收包.参_当前坐标.y: " + 到文本(收包.参_当前坐标.y), 1);
	神话公告(L"收包.参_参_领主坐标.x: " + 到文本(收包.参_领主坐标.x), 1);
	神话公告(L"收包.参_参_领主坐标.y: " + 到文本(收包.参_领主坐标.y), 1);
	if (判断_坐标相等(收包.参_当前坐标, 收包.参_领主坐标))
	{
		return;
	}

	int 过图方式 = 0;
	if (任务编号 == 3191 || 任务编号 == 3529 || 任务编号 == 3530 || 任务编号 == 3533 || 任务编号 == 3772 || 任务编号 == 3834 || 任务编号 == 3836 || 任务编号 == 4831 || 任务编号 == 5933 || 任务编号 == 5934 || 任务编号 == 5941 || 任务编号 == 3600 || 任务编号 == 6348 || 任务编号 == 3228 || 任务编号 == 6365 || 任务编号 == 12163 || 任务编号 == 3247 || 任务编号 == 3506 || 副本编号 == 33)
	{
		过图方式 = 1;
	}

	地图型 局_地图数据 = 获取数据();
	int 方向 = 计算方向(局_地图数据.走法[0], 局_地图数据.走法[1]);
	神话公告(L" 智能寻路-方向: " + 到文本(方向), 1);

	过图调用(方向, 过图方式);
}

int 钢铁全图()
{
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
	{
		return 0;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
	{
		return 0;
	}
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 3)
	{
		return 2;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}

	return -1;
}

int 格蓝迪全图()
{
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
	{
		return 0;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
	{
		return 2;
	}

	return -1;
}

int 记忆之地顺图()
{
	if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
	{
		return 3;
	}
	if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 2)
	{
		return 2;
	}
	if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
	{
		return 1;
	}
	if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 1)
	{
		return 2;
	}

	return -1;
}

int 荆棘乐园()
{
	if (收包.参_领主坐标.x == 6 && 收包.参_领主坐标.y == 1)
	{
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
	}

	return -1;
}

int 德鲁斯矿山外围()
{
	if (收包.参_领主坐标.x == 6 && 收包.参_领主坐标.y == 0)
	{
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
	}

	return -1;
}

int 远古墓地()
{
	if (收包.参_领主坐标.x == 6 && 收包.参_领主坐标.y == 1)
	{
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
	}
	return -1;
}

int 绝望摇篮()
{
	if (收包.参_领主坐标.x == 7 && 收包.参_领主坐标.y == 0)
	{
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 5 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 6 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
	}
	return -1;
}

int 皇宫全图()
{
	if (收包.参_领主坐标.x == 1 && 收包.参_领主坐标.y == 0)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 3) //这里有问题 漏房间 3个 
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 3)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3)
		{
			全局.经过2 = 1;
			全局.经过3 = 1;
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			全局.经过1 = 1;
			return 3;//下
		}

		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1 && 全局.经过1 == 0)  //左0 右1 上2 下3
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1 && 全局.经过1 == 1)
		{
			return 0;//左
		}

		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.经过2 == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.经过2 == 1)
		{
			return 2;//上
		}

		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2 && 全局.经过3 == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2 && 全局.经过3 == 1)
		{
			return 2;//上
		}

	}
	if (收包.参_领主坐标.x == 1 && 收包.参_领主坐标.y == 3)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 3)
		{
			全局.经过1 = 1;
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			全局.经过2 = 1;
			全局.经过3 = 1;
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3)
		{
			return 1;//右
		}

		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2 && 全局.经过1 == 0)  //左0 右1 上2 下3
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2 && 全局.经过1 == 1)
		{
			return 0;//左
		}

		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2 && 全局.经过2 == 0)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2 && 全局.经过2 == 1)
		{
			return 3;//下
		}

		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.经过3 == 0)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.经过3 == 1)
		{
			return 3;//下
		}


	}
	if (收包.参_领主坐标.x == 3 && 收包.参_领主坐标.y == 2)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}

	}
	if (收包.参_领主坐标.x == 0 && 收包.参_领主坐标.y == 0)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 0;//左
		}
	}

	return -1;
}

int 挑战皇宫()
{
	if (收包.参_领主坐标.x == 4 && 收包.参_领主坐标.y == 2)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
	}
	if (收包.参_领主坐标.x == 0 && 收包.参_领主坐标.y == 0)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 0)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 4 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 0;//左
		}
	}
	if (收包.参_领主坐标.x == 1 && 收包.参_领主坐标.y == 4)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.重复 == 0)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			全局.重复 = 1;
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1 && 全局.重复 == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2)
		{
			全局.重复 = 0;
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 3 && 全局.重复 == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 4)
		{
			全局.重复 = 1;
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 3 && 全局.重复 == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 3)
		{
			全局.重复 = 0;
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 4)
		{
			return 1;//右
		}

	}
	if (收包.参_领主坐标.x == 1 && 收包.参_领主坐标.y == 0)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 4)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 4)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 3)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 3)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3 && 全局.重复 == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 4)
		{
			全局.重复 = 1;
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 3 && 全局.重复 == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 2)
		{
			全局.重复 = 0;
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1 && 全局.重复 == 0)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			全局.重复 = 1;
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1 && 全局.重复 == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			全局.重复 = 0;
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}


	}
	if (收包.参_领主坐标.x == 3 && 收包.参_领主坐标.y == 2)//左0 右1 上2 下3
	{
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 2)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 1)
		{
			return 0;//左
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 1)
		{
			return 2;//上
		}
		if (收包.参_当前坐标.x == 0 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 1 && 收包.参_当前坐标.y == 0)
		{
			return 1;//右
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 0)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			return 3;//下
		}
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 2)
		{
			return 1;//右
		}
	}

	return -1;
}

void 顺图调用(int 调用)
{

	if (调用 == 1)
	{
		全局.顺图方向 = 2;
	}
	if (调用 == 2)
	{
		全局.顺图方向 = 3;
	}
	if (调用 == 3)
	{
		全局.顺图方向 = 0;
	}
	if (调用 == 4)
	{
		全局.顺图方向 = 1;
	}
	++全局.顺图计次;
	if (全局.顺图计次 >= 2)//这里是防止随机门的
	{
		全局.顺图计次 = NULL;
		组包强顺(全局.顺图方向);
	}
	else
	{
		漂移过图(全局.顺图方向);
	}
}

void 顺图方向(int 方向)
{
	if (方向 == 2)
	{
		顺图调用(1);
	}
	else if (方向 == 3)
	{
		顺图调用(2);
	}
	else if (方向 == 0)
	{
		顺图调用(3);
	}
	else if (方向 == 1)
	{
		顺图调用(4);
	}
}

void 顺图寻路()
{
	神话公告(L" 顺图寻路", 1);
	if (全局.可以顺图 == false)
	{
		return;
	}
	if (取是否制裁() == false)
	{
		if (读配置(配置.拾取方式) == 1 || 读配置(配置.拾取方式) == 2)
		{
			++全局.拾取次数;
			if (全局.拾取次数 < 10)
			{
				if (是否有物品() == true)
				{
					拾取遍历();
					return;
				}
			}
		}
	}
	/*
	地图型 局_地图数据;
	局_地图数据 = 获取数据();
	if (局_地图数据.走法.size() >= 2)
	{
		顺图方向(计算方向(局_地图数据.走法[1], 局_地图数据.走法[2]));
	}
	*/

	if (收包.参_地图编号 == 100000177)
	{
		if (收包.参_当前坐标.x == 2 && 收包.参_当前坐标.y == 1)
		{
			过图调用(3, 0);
			return;
		}
		else if (收包.参_当前坐标.x == 3 && 收包.参_当前坐标.y == 1)
		{
			过图调用(0, 0);
			return;
		}
	}

	if (读配置(配置.自动模式) == 1 || 读配置(配置.自动模式) == 3 || 读配置(配置.自动模式) == 4)
	{
		if (收包.参_地图编号 == 100000212 || 收包.参_地图编号 == 100000177)
		{
			过图调用(记忆之地顺图(), 0);
			return;
		}
		if (收包.参_地图编号 == 192)
		{
			过图调用(钢铁全图(), 0);
			return;
		}
		if (收包.参_地图编号 == 104)
		{
			过图调用(格蓝迪全图(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000522)
		{
			过图调用(荆棘乐园(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000523)
		{
			过图调用(德鲁斯矿山外围(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000524)
		{
			过图调用(远古墓地(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000525)
		{
			过图调用(绝望摇篮(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000002)
		{
			过图调用(皇宫全图(), 0);
			return;
		}
		if (收包.参_地图编号 == 100000214)
		{
			过图调用(挑战皇宫(), 0);
			return;
		}
	}

	智能寻路(收包.参_地图编号, 全局.任务编号);

}