#pragma once

typedef ULONG64(__fastcall* _Func_Call)(
	ULONGLONG RCX__,
	ULONGLONG RDX__,
	ULONGLONG R8__,
	ULONGLONG R9__,
	ULONGLONG R10__,
	ULONGLONG R11__,
	ULONGLONG R12__,
	ULONGLONG R13__,
	ULONGLONG R14__,
	ULONGLONG R15__
	);

ULONG64 Func_CALL(ULONGLONG ADDR__, ULONGLONG RCX__ = 0, ULONGLONG RDX__ = 0, ULONGLONG R8__ = 0, ULONGLONG R9__ = 0, ULONGLONG R10__ = 0, ULONGLONG R11__ = 0, ULONGLONG R12__ = 0, ULONGLONG R13__ = 0, ULONGLONG R14__ = 0, ULONGLONG R15__ = 0);

int 取随机数(int 最小值, int 最大值);

wstring 到文本(int 欲用值);

ULONG64 内存申请(size_t size);

void 写字节集(ULONG64 参_内存地址, vector<byte> 参_写入数据);

vector<byte> 到字节集(ULONG64  i, int 位数 = NULL);

vector<byte> 读字节集(ULONG64 参_内存地址, DWORD 参_读取长度);

wstring 取文本右边(wstring 文本, size_t 数值);

wstring 取文本左边(wstring 文本, size_t 数值);

wstring 通关时间(int 地址);

void 分割文本(const wstring& str, vector<wstring>& tokens, const wstring& delimiters);

double 读小数型(ULONG64 参_内存地址);

DWORD 读整数型(ULONG64 参_内存地址);

ULONG64 读长整数(ULONG64 参_内存地址);

BYTE 读字节型(ULONG64 参_内存地址);

BYTE 读短整数(ULONG64 参_内存地址);

void 写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据);

void 写字节型(ULONG64 参_内存地址, BYTE 参_写入数据);

void 写整数型(ULONG64 参_内存地址, DWORD 参_写入数据);

void 写小数型(ULONG64 参_内存地址, float 参_写入数据);

void 写短整数(ULONG64 参_内存地址, WORD 参_写入数据);