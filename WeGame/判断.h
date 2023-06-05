#pragma once
#include "结构.h"

// 取游戏数据
int 解密(__int64 数据指针);
VOID 加密(__int64 数据指针, int 修改数值);

int 取游戏状态();
bool 取是否城镇();
bool 取是否开门();
bool 取是否BOSS房();
bool 取是否通关();
坐标型 取BOSS房间();
坐标型 取当前房间();
int 取地图编号();

CString 取地图名称();
int 取疲劳值();

bool 判断_过滤拾取(wstring 物品名称);


bool 判断_过滤拾取(wstring 物品名称);

bool 是否有物品();

bool 判断_坐标相等(坐标型 索引_1, 坐标型 索引_2);

bool 是否怪物();

bool 取是否翻牌();

int 取角色等级();

int 取角色数量();

int 取角色位置();

bool 取是否对话框();

bool 取是否制裁();

坐标型 读取类型坐标(ULONG64 参_指针);

int 判断地图(int 副本编号);

void 跳过对话();

ULONG 取负重数值();

int 等级地图();
