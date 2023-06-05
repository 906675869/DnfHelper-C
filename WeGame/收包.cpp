#include "pch.h"
#include "文件.h"
#include "引用.h"
#include "Address.h"
#include "数组.h"
#include "配置.h"
#include "公告.h"
#include "收包.h"
#include "游戏CALL.h"
#include "加密.h"
#include "功能.h"
#include "组包.h"
#include "顺图.h"
#include "自动.h"
#include "剧情.h"
#include "未央.h"
#include "判断.h"

收包数据 收包;

void 收包事件(ULONG64 _包指针)
{
	int _包头部 = *(USHORT*)(_包指针 + 1);
	收包指引(_包头部, _包指针);
}

ULONG64 收包HOOK_Call(ULONG64 Rcx, ULONG64 Rdx, ULONG64 R8)
{
	ULONG64 rcx{}, rdx{}, r8{}, r9d{};
	ULONG64 Ret = NULL;
	rcx = Rcx;
	rdx = Rdx;
	r8 = R8;
	收包事件(r8);
	rcx = Func_CALL(收包CALL, rcx, rdx, r8);
	return rcx;
}

void 收包入口()
{
	读出配置();
	DWORD old_protect = NULL;
	VirtualProtect((LPVOID)独家收包, 8, 64, &old_protect);
	ULONG64 pFunc = (ULONG64)收包HOOK;
	ULONG64 VirtualAdd = 0x000110DB;
	BYTE Cpi[8]{ 0xFF,0x14,0x25, 0x0, 0x0, 0x0, 0x0, 0x0 };
	*(ULONG64*)(Cpi + 3) = (ULONG64)VirtualAdd;
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)VirtualAdd, &pFunc, sizeof(ULONG64), 0);
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)独家收包, Cpi, 7, 0);
	VirtualProtect((LPVOID)独家收包, 8, old_protect, &old_protect);
}

LRESULT CALLBACK 窗口进程(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYUP)
	{
		if (wParam == VK_END)
		{
			自动开关();
		}
		if (wParam == VK_F1)
		{
			全屏开关();
			//怪物Call(59172);
			//神话公告(L"怪物");
		}
		if (wParam == VK_F2)
		{

			//人偶Call(4998);
			//神话公告(L"人偶");
		}
		if (wParam == VK_F3)
		{

		}
		if (wParam == VK_F4)
		{
			//玉荣穿戴();
			//神话公告(L"玉荣穿戴成功");
		}
		if (wParam == 192)
		{


		}

	}
	if (uMsg == WM_SYSKEYDOWN)//按下ALT
	{

		if (wParam == VK_F1)
		{

		}

		if (wParam == VK_F2)
		{

		}

		if (wParam == VK_F3)
		{

		}

		if (wParam == VK_F4)
		{
			keybd_event(88, MapVirtualKey(88, 0), 0, 0);//按下
			Sleep(50);
			keybd_event(88, MapVirtualKey(88, 0), KEYEVENTF_KEYUP, 0);//松开
		}

		if (wParam == VK_UP)//左0右1上2下3
		{
			组包强顺(2);
		}
		if (wParam == VK_DOWN)
		{
			组包强顺(3);
		}
		if (wParam == VK_LEFT)
		{
			组包强顺(0);
		}
		if (wParam == VK_RIGHT)
		{
			组包强顺(1);
		}
	}
	return CallWindowProc(收包.窗口消息, hWnd, uMsg, wParam, lParam);
}

void 收包指引(int _包头部, ULONG64 _包指针)
{

	if (_包头部 == 53)
	{
		if (收包.游戏句柄 == NULL)
		{
			收包.游戏句柄 = FindWindowW(L"地下城与勇士", L"地下城与勇士");
			收包.窗口消息 = (WNDPROC)SetWindowLongPtr(收包.游戏句柄, GWLP_WNDPROC, (ULONG64)窗口进程);
			神话公告(L" { 程序挂钩成功 } ",1);
			//检测处理();
			if (文件是否存在() == false)
			{
				写出配置();
			}
		}
	}

	if (_包头部 == 1089)
	{
		超级加密(*(ULONG64*)评分基址 + 272, 取随机数(666666, 999999));
		//状态Call(1202);
	}

	if (_包头部 == 27)
	{
		if (全局.自动开关 == true)
		{
			if (读配置(配置.自动模式) == 1)
			{
				if (全局.副本难度 == 5)
				{
					if (全局.副本编号 == 100000214 || 全局.副本编号 == 100000212 || 全局.副本编号 == 100000215 || 全局.副本编号 == 100000199 || 全局.副本编号 == 100000209)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号), 6);
					}
					if (全局.副本编号 == 100000002)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000177 || 全局.副本编号 == 100000176)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000178 || 全局.副本编号 == 100000179)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 9700)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000003)
					{
						组包进图(全局.副本编号, 4);
					}
					if (全局.副本编号 == 100000151)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号), 1);
					}
					else
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
				}
				else
				{
					if (全局.副本编号 == 100000214 || 全局.副本编号 == 100000212 || 全局.副本编号 == 100000215 || 全局.副本编号 == 100000199 || 全局.副本编号 == 100000209)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号), 6);
					}
					if (全局.副本编号 == 100000002)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000177 || 全局.副本编号 == 100000176)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000178 || 全局.副本编号 == 100000179)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 9700)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号));
					}
					if (全局.副本编号 == 100000003)
					{
						组包进图(全局.副本编号, 4);
					}
					if (全局.副本编号 == 100000151)
					{
						组包进图(全局.副本编号, 难度Call(全局.副本编号), 1);
					}
					else
					{
						组包进图(全局.副本编号, 全局.副本难度);
					}
				}
			}
			if (读配置(配置.自动模式) == 2)
			{

				if (是否有主线任务() == true)
				{
					组包进图(全局.副本编号, 全局.副本难度);
				}
				else
				{
					组包进图(全局.副本编号, 难度Call(全局.副本编号));
				}


			}
			if (读配置(配置.自动模式) == 3)
			{
				组包进图(全局.副本编号, 难度Call(全局.副本编号));
			}
		}
	}

	if (_包头部 == 28)
	{
		收包.参_地图编号 = *(ULONG*)(_包指针 + 16);
		收包.参_地图难度 = *(UCHAR*)(_包指针 + 20);
		收包.参_地图序号 = *(UCHAR*)(_包指针 + 23);
		收包.参_领主坐标.x = *(UCHAR*)(_包指针 + 24);
		收包.参_领主坐标.y = *(UCHAR*)(_包指针 + 25);
		收包.参_副本名称 = (wchar_t*)*(ULONG64*)(地图Call(收包.参_地图编号) + 地图名称);
		神话公告(L"地图编号: " + 到文本(收包.参_地图编号), 1);
		神话公告(L"地图难度: " + 到文本(收包.参_地图难度), 1);
		神话公告(L"收包.参_领主坐标.x: " + 到文本(收包.参_领主坐标.x), 1);
		神话公告(L"收包.参_领主坐标.y: " + 到文本(收包.参_领主坐标.y), 1);
		神话公告(L"进入副本 { " + 收包.参_副本名称 + L" }", 1);
	}

	if (_包头部 == 29)
	{
		if (收包.参_地图编号 == 7145 || 收包.参_地图编号 == 7125 || 收包.参_地图编号 == 10005 || 收包.参_地图编号 == 7115 || 收包.参_地图编号 == 7118 || 收包.参_地图编号 == 7110 || 收包.参_地图编号 == 7116 || 收包.参_地图编号 == 7117 || 收包.参_地图编号 == 7111 || 收包.参_地图编号 == 7124 || 收包.参_地图编号 == 7112 || 收包.参_地图编号 == 7114 || 收包.参_地图编号 == 7113 || 收包.参_地图编号 == 7119)
		{
			组包回城();
		}
		全局.可以顺图 = false;
		全局.顺图计次 = NULL;
		全局.拾取次数 = NULL;
		收包.参_当前坐标.x = *(UCHAR*)(_包指针 + 16);
		收包.参_当前坐标.y = *(UCHAR*)(_包指针 + 17);
		收包.参_怪物数量 = *(UCHAR*)(_包指针 + 34);
		神话公告(L"收包.参_当前坐标.x: " + 到文本(收包.参_当前坐标.x), 1);
		神话公告(L"收包.参_当前坐标.: " + 到文本(收包.参_当前坐标.y), 1);
		if (读配置(配置.拾取方式) == 3)
		{
			收包.参_创建数量 = *(UCHAR*)(_包指针 + 34);
			收包.参_拾取变量 = (收包.参_创建数量 - 1) * 22;
			收包.参_拾取数量 = *(UCHAR*)(_包指针 + 57 + 收包.参_拾取变量);
			if (收包.参_拾取数量 > 20)
			{
				收包.参_拾取数量 = 0;
			}
			for (收包.参_收包计次 = 0; 收包.参_收包计次 < 收包.参_拾取数量; ++收包.参_收包计次)
			{
				收包.参_物品编号 = *(ULONG*)(_包指针 + 收包.参_拾取变量 + 59 + 收包.参_收包计次 * 21);
				组包拾取(收包.参_物品编号);
			}
			if (收包.参_拾取数量)
			{
				神话公告(L" 提取 { " + 到文本(收包.参_拾取数量) + L" }个建筑物品   ", 1);
			}
		}
	}

	if (_包头部 == 30)
	{
		全局.可以顺图 = true;
		//神话公告(L" 可以顺图",1);
		/*

			if (收包.怪物ID.size() > 0)
			{
				for (收包.参_收包计次 = 0; 收包.参_收包计次 < 收包.怪物ID.size(); 收包.参_收包计次++)
				{
					组包_怪物死亡(收包.怪物ID[收包.参_收包计次], 1);

				}
				收包.怪物ID.clear();
			}

		*/
	}

	if (_包头部 == 38)
	{
		if (读配置(配置.拾取方式) == 3)
		{
			for (收包.参_收包计次 = 0; 收包.参_收包计次 < *(UCHAR*)(_包指针 + 18); 收包.参_收包计次++)
			{
				组包拾取(*(ULONG*)(_包指针 + 20) + 收包.参_收包计次);
			}
		}
	}

	if (_包头部 == 31)
	{

	}

	if (_包头部 == 34)
	{

		if (全局.自动开关 == true)
		{

			通关翻牌();

			if (读配置(配置.自动模式) == 5)
			{
				神话公告(L"{ 云上未央 -> 通关 }", 1);
				组包回城();
				神话公告(L"{ 云上未央 -> 出图 }", 1);
			}
		}
		收包.参_通关计次++;
		神话公告(L"通关 -> { " + 到文本(收包.参_通关计次) + L" } 次",1);
		神话公告(L"通关 -> { " + 收包.参_副本名称 + L" } - 用时 { " + 通关时间(*(ULONG*)(_包指针 + 17)) + L" }", 1);
	}

	if (_包头部 == 35)
	{
		if (全局.自动开关 == true)
		{
			领取奖励();
		}
	}

	if (_包头部 == 261)
	{
		if (全局.自动开关 == true)
		{
			if (读配置(配置.自动模式) == 2)
			{
				if (全局.任务编号 == 3449 || 全局.任务编号 == 3649 || 全局.任务编号 == 3753 || 全局.任务编号 == 6209) // 奇怪的兵器 绝密区域的悲剧 开路 夜之摩天楼
				{
					提交Call(全局.任务编号);
				}
				else
				{
					完成Call(全局.任务编号);

					提交Call(全局.任务编号);
				}
			}

			组包回城();
		}
	}

	if (_包头部 == 1737)
	{
		if (全局.自动开关 == true)
		{
			if (收包.参_副本名称 == L"红玉的诅咒地下60层")
			{
				神话公告(L"通关 -> { " + 收包.参_副本名称 + L" } - 用时 { " + 通关时间(*(ULONG*)(_包指针 + 17)) + L" }", 1);
				组包回城();
				神话公告(L"当前账号所有角色 -> 已完成执行", 1);
				神话公告(L"{ 自动 -> Close }", 1);
				全局.自动开关 = false;
				KillTimer(收包.游戏句柄, 2000);
			}
			else
			{
				神话公告(L"通关 -> { " + 收包.参_副本名称 + L" } - 用时 { " + 通关时间(*(ULONG*)(_包指针 + 17)) + L" }", 1);
				组包回城();
			}
		}
	}

	if (_包头部 == 1103)
	{
		if (全局.自动开关 == true)
		{
			if (全局.技能开关 == false)
			{
				全屏开关();
			}
		}
	}

	if (_包头部 == 31)
	{
		if (全局.自动开关 == true)
		{
			if (全局.技能开关 == true)
			{
				全屏开关();
			}
		}
	}

	if (_包头部 == 1333)
	{
		if (全局.自动开关 == true)
		{
			if (全局.角色更换 == true)
			{
				选择角色Call(全局.当前位置);
			}
		}
	}

	if (_包头部 == 1488)
	{
		if (全局.自动开关 == true)
		{
			if (全局.角色更换 == true)
			{
				全局.角色更换 = false;
			}
		}
	}
}

void 检测处理()
{
	INT64 dnf = (INT64)(GetModuleHandleA("dnf.exe"));
	INT64 Kernel32 = (INT64)(GetModuleHandleA("Kernel32.dll"));
	INT64 DNFBase = (INT64)(GetModuleHandleA("DNFBase.dll"));
	INT64 TerSafe = (INT64)(GetModuleHandleA("TerSafe.dll"));
	INT64 cross_core64 = (INT64)(GetModuleHandleA("cross_core64.dll"));
	INT64 ATS64 = (INT64)(GetModuleHandleA("ACE-ATS64.dll"));
	INT64 Game64 = (INT64)(GetModuleHandleA("ACE-PBC-Game64.dll"));
	INT64 Drv64 = (INT64)(GetModuleHandleA("ACE-DRV64.dll"));
	INT64 Base64 = (INT64)(GetModuleHandleA("ACE-Base64.dll"));
	INT64 GDP64 = (INT64)(GetModuleHandleA("ACE-GDP64.dll"));
	INT64 Tips64 = (INT64)(GetModuleHandleA("ACE-Tips64.dll"));
	INT64 Captcha = (INT64)(GetModuleHandleA("ACE-Captcha64.dll"));
	//Memory::WriteBytes(Game64 + 0x1CD10, { 0x40,0x56,0x48,0x83,0xEC,0x30 });
	//写字节集(Base64 + 0x2199E0, { 0xC3,0x90,0x90,0x90,0x90 });
	//写字节集(Kernel32 + 0x1000, { 0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC });
	//写字节集(DNFBase + 0xA06000, { 0x48,0x60,0xA0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 });
	///写字节集(Drv64 + 0x9EB168, { 0x74,0x32,0x84,0x00,0x00,0x00,0x00,0x00,0x98,0x22,0xA0,0x00,0x00,0x00 });
	//写字节集(Kernel32 + 0x1E5C0, { 0x48,0xFF,0x25,0x39,0x93,0x05,0x00 });
}