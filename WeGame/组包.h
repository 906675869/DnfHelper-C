#pragma once

VOID 缓冲Call(__int64 缓冲参数);

VOID 加密Call(__int64 加密参数, int 加密长度);

VOID 发包Call();

VOID 组包选择角色(int 位置);

VOID 组包分解(int 装备位置);

VOID 组包拾取(int 物品地址);

VOID 组包返回角色();

VOID 组包选图();

void 组包进图(int 地图编号, int 地图难度, int 深渊模式 = NULL, int 任务编号 = NULL);

VOID 组包翻牌(int 行, int 列);

VOID 组包出图();

VOID 组包过图(int X, int Y);

VOID 组包移动(int 大地图ID, int 小地图ID, int 城镇X坐标, int 城镇Y坐标);

void 组包卖物(int 物品位置, int 物品数量 = NULL);

void 强制过图(int 房间横轴, int 房间纵轴);

void 数值Call(LONGLONG 地址, int 长度);

void 组包跳过();

void 组包回城();

void 通关翻牌();

void 领取奖励();

void 秘钥Call(ULONG64 包头, int 长度);


void 移动到云上长安门口();

void 云上进图(ULONG 思南位置);

void 司南分解组包(ULONG 位置);


void 组包_城镇移动(区域型 副本编号);