#pragma once
#include "公用.h"

VOID 汇编执行(ByteArr 汇编代码);

VOID 技能Call(__int64 触发指针, int 技能代码, int 技能伤害, int x, int y, int z, int 大小);
VOID 透明Call(__int64 对象指针);
VOID 评分Call(int Value);

VOID 区域Call(int 地图编号);
VOID 坐标Call(int 对象横轴, int 对象纵轴, int 对象竖轴);

void 坐标Call(ULONG64 触发指针, int X, int Y, int Z);

int 顺图Call(int 顺图方向);

__int64 取人物指针Call(__int64 globleRwAddr);
__int64 取人物基质();


void 漂移Call(int X, int Y, int Z, int 移动速度 = NULL);

int 取坐标Call(ULONG64 触发指针, int 方向);

ULONG64 地图Call(int 地图编号);


int 难度Call(int 地图编号);

int 标识Call();

void 怪物Call(int 代码);

void 人偶Call(int 代码);

void 特效Call(int type);


void 角色翻页Call(int 角色页位);

void 进入角色Call(int 角色位置);

void 选择角色Call(int 角色位置);

void 退出角色Call();

void 放弃Call(int 任务编号);

void 提交Call(int 任务编号);

void 接受Call(int 任务编号);

void 完成Call(int 任务编号, int 任务次数 = NULL);

void 状态Call(int 数值, int 时间 = NULL);//1049 小金人 1134 霸体 1203 霸体 1202 无敌 1212 人物变大（无法攻击）

void 玉荣Call(ULONG 新位置, ULONG 原位置);