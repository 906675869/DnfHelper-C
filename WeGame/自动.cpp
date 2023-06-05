#include "pch.h"
#include "自动.h"

#include "公用.h"
#include "读写.h"
#include "公告.h"
#include "判断.h"
#include "游戏Call.h"
#include "组包.h"
#include "寻路.h"
#include "配置.h"
#include "游戏Call.cpp"
#include "功能.h"
#include "剧情.h"
#include "未央.h"
#include "顺图.h"

// 自动开关
static bool automaticSwitch;
// 自动线程句柄
HANDLE threadHandle = NULL;

VOID 自动开关() {
	automaticSwitch = !automaticSwitch;
	if (automaticSwitch == true)
	{
		threadHandle = ::_CreateThread(&自动线程);
		游戏公告("自动刷图 - 启动", 2);
		return;
	}

	if (automaticSwitch == false && threadHandle != NULL)
	{
		_DeleteThread(threadHandle);
		游戏公告("自动刷图 - 关闭", 2);
	}
}

VOID 自动线程() {
	static bool 首次进图 = false;

	while (true)
	{
		Sleep(200);
		if (取游戏状态() == 0)
		{
			Sleep(200);
			进入城镇();
			continue;
		}
		if (取游戏状态() == 1 && 取是否城镇() == true)
		{
			城镇处理();
			continue;
		}

		if (取游戏状态() == 2)
		{
			进入副本(_ReadConfig(L"自动配置", L"副本编号"), 0);
			continue;
		}

		if (取游戏状态() == 3)
		{
			if (首次进图 == false)
			{
				透明Call(_ReadInt(取人物基质()));
				首次进图 = true;
			}

			if (取是否开门() == true && 取是否BOSS房() == false)
			{
				// 物品入包();
				模拟顺图();
				continue;
			}
			if (取是否BOSS房() == true)
			{
				if (取是否通关() == true || 取是否通关() == true)
				{
					退出副本();
					首次进图 = false;
				}
			}
		}
	}
}

VOID 进入城镇() {
	static int 全_已刷角色;
	if (全_已刷角色 + 1 > 32) {
		监控(L"指定角色完成所有角色");
		_DeleteThread(threadHandle);
		游戏公告("自动线程 - 关闭", 1);
		return;
	}

	全_已刷角色++;
	组包选择角色(全_已刷角色);
	监控(L"进入角色[" + _IntToCString(全_已刷角色) + L"]");
	监控(L"开始第[" + _IntToCString(全_已刷角色) + L"] 个角色, 剩余疲劳[" + _IntToCString(取疲劳值()) + L"]");
	Sleep(200);
	do
	{
		if (取游戏状态() == 1) {
			break;
		}
		Sleep(500);
	} while (取游戏状态() == 0);
}

VOID 城镇处理() {
	if (取疲劳值() < 8)
	{
		返回角色();
		return;
	}
	区域Call(_ReadConfig(L"自动配置", L"副本编号"));
	Sleep(200);
	进入选图();
}

VOID 进入选图()
{
	do
	{
		Sleep(200);
		组包选图();
		for (int i = 1; i <= 10; i++)
		{
			Sleep(500);
			if (取游戏状态() == 2) {
				return;
			}
		}
	} while (取游戏状态() == 1);
}

VOID 返回角色() {
	监控(L"疲劳值不足 · 即将切换角色");
	Sleep(100);
	组包返回角色();
	Sleep(500);
	do
	{
		if (取游戏状态() == 0) {
			break;
		}
		Sleep(500);
	} while (取游戏状态() == 1);
}

VOID 进入副本(int 副本编号, int 副本难度) {
	if (副本难度 == 5)
	{
		if (副本编号 < 10 || 副本编号 == 1000)
		{
			组包进图(副本编号, 副本难度, 0, 0);
		}
		else
		{
			组包进图(副本编号, 4, 0, 0);
			组包进图(副本编号, 3, 0, 0);
			组包进图(副本编号, 2, 0, 0);
			组包进图(副本编号, 1, 0, 0);
			组包进图(副本编号, 0, 0, 0);
		}
	}
	else
	{
		组包进图(副本编号, 副本难度, 0, 0);
	}
	do
	{
		Sleep(200);
		for (int i = 1; i <= 10; i++)
		{
			Sleep(500);
			if (取游戏状态() == 3) break;
		}
	} while (取游戏状态() == 2);
}

VOID 模拟顺图()
{
	if (取是否开门() == false || 取是否BOSS房() == true)
	{
		return;
	}
	地图数据 局_地图数据 = 寻路_地图数据();
	if (sizeof(局_地图数据.地图走法) >= 2)
	{
		int 过图方向 = 寻路_计算方向(局_地图数据.地图走法[0], 局_地图数据.地图走法[1]);
		int 顺图方式 = _ReadConfig(L"自动配置", L"顺图方式");
		if (顺图方式 == 1)
		{
			组包_顺图(过图方向);
		}
		if (顺图方式 == 2) {
			坐标_顺图(过图方向);
		}
	}
}

VOID 通关计次()
{
	int 通关计次 = _ReadConfig(L"计次", L"次数");
	通关计次++;
	_WriteConfig(L"计次", L"次数", _IntToCString(通关计次));

	监控(L"当前副本 [ " + 取地图名称() + L" ]");
	监控(L"自动刷图 [" + _IntToCString(通关计次) + L" ]" + L"剩余疲劳 [" + _IntToCString(取疲劳值()) + L" ]");
}

VOID 退出副本()
{
	通关计次();
	Sleep(200);
	//物品入包();
	do
	{
		组包翻牌(0, _Rand(0, 3));
		Sleep(200);
		组包出图();
		Sleep(200);
	} while (取游戏状态() == 3 || 取是否城镇() == false);
}




void 获取角色处理(int 副本编号)
{
	if (取疲劳值() <= 读配置(配置.预留疲劳))
	{
		更换角色();
	}
	else
	{

		区域型 地方区域 = 获取区域(副本编号);

		组包_城镇移动(地方区域);

		组包选图();

	}
}

void 更换角色()
{
	全局.当前位置 = 取角色位置() + 1;
	全局.角色总数 = 取角色数量();
	if (全局.当前位置 >= 全局.角色总数)
	{
		全局.自动开关 = false;
		神话公告(L"当前账号所有角色 -> 已完成执行", 1);
		神话公告(L"{ 自动 -> Close }", 1);
		KillTimer(收包.游戏句柄, 2000);
		return;

	}
	神话公告(L"{ 切换角色 -> ( " + 到文本(全局.当前位置) + L" / " + 到文本(全局.角色总数) + L" ) }", 1);

	全局.角色更换 = true;

	退出角色Call();

}

void 自动地图()
{
	if (全局.自动开关 == true)
	{
		if (读整数型(游戏状态) == 1)
		{
			if (读配置(配置.自动模式) == 1)
			{
				全局.副本编号 = 读配置(配置.副本编号);

				全局.副本难度 = 读配置(配置.副本难度);

				if (判断地图(全局.副本编号) == 3)
				{
					更换角色();

					return;
				}

				处理装备();

				获取角色处理(全局.副本编号);

				return;
			}
			if (读配置(配置.自动模式) == 2)
			{
				if (是否有主线任务() == true)
				{
					if (返回隐藏() > 0)
					{
						if (获取处理结果(返回隐藏()) == true)
						{
							处理装备();

							获取角色处理(全局.副本编号);

							return;
						}

					}

					if (返回主线() > 0)
					{
						if (获取处理结果(返回主线()) == true)
						{
							处理装备();

							获取角色处理(全局.副本编号);

							return;
						}
					}
				}
				else
				{
					全局.副本编号 = 等级地图();

					if (判断地图(全局.副本编号) == 3)
					{
						更换角色();

						return;
					}

					处理装备();

					获取角色处理(全局.副本编号);

					return;
				}
			}
			if (读配置(配置.自动模式) == 3)
			{
				if (跳过数据() == true)
				{
					神话公告(L"{ 可以跳过 }", 1);

					组包跳过();

					return;
				}
				else
				{

					全局.副本编号 = 等级地图();

					if (判断地图(全局.副本编号) == 3)
					{
						更换角色();

						return;
					}

					处理装备();

					获取角色处理(全局.副本编号);

					return;
				}
			}

			if (读配置(配置.自动模式) == 5)
			{

				全局.到下面的房间 = false;

				全局.最近顺图 = false;


				处理装备();

				移动到云上长安门口();

				ULONG 门票位置 = 玉荣力匹配司南(自身玉荣力());

				if (取疲劳值() <= 读配置(配置.预留疲劳))
				{
					更换角色();
				}
				else
				{
					云上进图(门票位置);
				}
				return;
			}
		}
		if (读整数型(游戏状态) >= 3)
		{

			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)跳过对话, NULL, NULL, NULL);


			if (取是否BOSS房() == false)
			{
				神话公告(L" 不在boss-3", 1);
				*(ULONG*)(*(ULONG64*)动画基址 + 动画偏移) = 1;

				if (取是否开门() == true)
				{
					神话公告(L" 已开门", 1);
					/*if (读配置(配置.未央全图) == 1)
					{
						if (是否未央柱子() == false)
						{
							CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)未央顺图, NULL, NULL, NULL);
						}
					}
					else
					{
						if (是否未央柱子() == false)
						{
							CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)顺图寻路, NULL, NULL, NULL);
						}
					}*/
					顺图寻路();
					return;
				}
				else
				{
					神话公告(L" 未开门", 1);
					跟随遍历();
				}
			}
			else
			{

				*(ULONG*)(*(ULONG64*)动画基址 + 动画偏移) = 1;

				if (取是否开门() == true)
				{
					if (取是否制裁() == false)
					{
						if (读配置(配置.拾取方式) == 1 || 读配置(配置.拾取方式) == 2)
						{
							if (是否有物品() == true)
							{
								拾取遍历();
								return;
							}
						}
					}
				}
				else
				{
					跟随遍历();
				}
				return;
			}
		}
	}
}