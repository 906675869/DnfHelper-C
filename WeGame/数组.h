#pragma once
#include "文件.h"
#include "结构.h"

struct 收包数据
{
	wstring 参_副本名称;
	HWND 游戏句柄;
	WNDPROC 窗口消息;
	坐标型 参_当前坐标;
	坐标型 参_领主坐标;
	int 参_地图编号;
	int 参_地图难度;
	int 参_地图序号;
	int 参_怪物数量;
	int 参_创建数量;
	int 参_拾取变量;
	int 参_拾取数量;
	int 参_收包计次;
	int 参_物品编号;
	int 参_通关计次;

	vector<short>怪物ID;

};

extern 收包数据 收包;

struct 配置数据
{
	wstring 辅助名字;

	wstring 技能代码;
	wstring 技能伤害;
	wstring 技能频率;
	wstring 技能个数;
	wstring 技能大小;

	wstring 自动模式;
	wstring 副本编号;
	wstring 副本难度;

	wstring 预留疲劳;
	wstring 跟随方式;
	wstring 拾取方式;
	wstring 顺图方式;



	wstring 白色装备;
	wstring 蓝色装备;
	wstring 紫色装备;
	wstring 粉色装备;
	wstring 史诗装备;
	wstring 勇者装备;
	wstring 传说装备;

	wstring 未央全图;

};

extern 配置数据 配置;

struct 全局数据
{
	bool 技能开关;
	bool 钩子开关;
	bool 自动开关;
	HANDLE 线程句柄;
	bool 可以顺图;
	int 任务编号;
	int 顺图计次;
	int 拾取次数;
	int 副本编号;
	int 副本难度;

	int 当前位置;
	int 角色总数;
	bool 角色更换;

	int 经过1 = NULL;
	int 经过2 = NULL;
	int 经过3 = NULL;
	int 重复 = NULL;

	int 顺图方向;

	int 柱子次数;

	bool 到下面的房间;
	bool 最近顺图;
};

extern 全局数据 全局;

struct 遍历数据
{
	ULONG64 人物指针;
	ULONG64 地图指针;
	ULONG64 遍历指针;
	ULONG64 遍历血量;

	ULONG64 首地址;
	ULONG64 尾地址;

	int 遍历数量;
	int 遍历类型;
	int 遍历阵营;

	ULONG64 物品指针;

	size_t 遍历次数;
	int 遍历代码;

	int 技能个数 = NULL;

	wstring 遍历名称;

	wstring 物品名称;

	int 物品数量;
	int 物品代码;
	坐标型 遍历位置;
};

struct 任务结构
{
	ULONG64 任务地址;
	ULONG64 首地址;
	ULONG64 尾地址;
	int 任务数量;
	int 任务次数;
	ULONG64 任务指针;
	int 任务类型;
	ULONG 任务等级;
	int 局部编号;
	int 任务长度;
	LPCWSTR 任务名称;
	LPCWSTR 任务条件;
	int 任务副本;
	int 局部解密;
};

extern 任务结构 任务;

struct 背包遍历
{
	ULONG64 背包地址;
	ULONG64 首地址;
	int 物品次数;
	ULONG64 装备指针;
	int 装备属性;
	int 装备代码;
	LPCTSTR 装备名称;

	int 白色件数 = NULL;
	int 蓝色件数 = NULL;
	int 紫色件数 = NULL;
	int 粉色件数 = NULL;
	int 史诗件数 = NULL;
	int 勇者件数 = NULL;
	int 传说件数 = NULL;

};

struct  未央结构
{
	ULONG64 背包指针;
	ULONG64 首地址;
	ULONG64 物品地址;
	ULONG64 物品指针;

	ULONG 物品数量;

	ULONG 次数;

	ULONG 司南类型;
	ULONG 交易类型;

	ULONG 物品数值;
	ULONG 物品代码;


	ULONG 物品位置;

	LPCTSTR 物品名称;

};

struct 地图型
{
	vector<int> 通道;
	坐标型 起始;
	坐标型 终点;
	int 宽度;
	int 高度;
	vector<坐标型> 走法;
	int 消耗;
};

struct 路线型
{
	坐标型 坐标;
	bool 左边 = false;
	bool 右边 = false;
	bool 上边 = false;
	bool 下边 = false;
	int 通道;
	int 颜色;
};

struct 节点型
{
	int F_点;
	int G_点;
	int H_点;
	坐标型 当前;
	坐标型 最终;
};