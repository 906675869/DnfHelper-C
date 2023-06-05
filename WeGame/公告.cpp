#include "pch.h"
#include "公告.h"

#include "读写.h"
#include "公用.h"
#include "游戏Call.h"
#include "配置.cpp"
#include "引用.h"

static CEdit* windowPEdit;

VOID SetWindowPEdit(CEdit* pEdit)
{
	windowPEdit = pEdit;
}

CEdit* GetWindowPEdit() 
{
	return windowPEdit;
}

VOID 监控(CString message)
{
	CString data;
	data = data + "\r\n" + message;
	GetWindowPEdit()->ReplaceSel(data);
}

VOID 神话公告(wstring 内容, int 类型) {
	LPCWSTR TempStr;
	内容 = 配置.辅助名字 + L" " + 内容 + L" ";
	TempStr = 内容.c_str();
	ULONG64 公告数组[100] = { NULL };
	*(ULONG64*)((ULONG64)公告数组 + 8) = (ULONG64)TempStr;
	*(ULONG*)((ULONG64)公告数组 + 28) = -1;
	*(ULONG*)((ULONG64)公告数组 + 32) = 淡绿色基址;  //颜色A
	if (类型 == NULL)
	{
		*(ULONG*)((ULONG64)公告数组 + 36) = 38;  //普通
	}
	else
	{
		*(ULONG*)((ULONG64)公告数组 + 36) = 17;  //系统
	}
	*(ULONG*)((ULONG64)公告数组 + 108) = 55512;//颜色B
	Func_CALL(神话CALL, (ULONG64)公告数组);
}

VOID 游戏公告(string message,int type) {
	__int64 static 局_空白地址;
	if (局_空白地址 == 0)
	{
		局_空白地址 = (__int64)_ApplyMemory(1024);
	}
	__int64 公告基址 = 公告参数;
	__int64 公告CALL_1 = 公告CALL;
	__int64 空白地址1 = 局_空白地址 + 800;
	__int64 空白地址2 = 局_空白地址 + 1000;
	_WriteByteArr(空白地址2, _AppendToBytes(AnsiToUnicode("情歌 √  " + message), ByteArr{ 0, 0 }));
	_WriteLong(空白地址1 + 8, 空白地址2);
	_WriteLong(空白地址1 + 24, 0);
	_WriteLong(空白地址1 + 32, RGB(0, 255, 255));
	// 桃红色 RGB(255, 80, 128)
	// 艳青色 RGB(0, 255, 255)
	// 青绿色 RGB(0, 224, 128)
	// 桃红色 RGB(255, 80, 128)
	 // 公告类型 17系统公告 38普通公告
	int 公告类型 = 38;
	if (type == 2)
	{
		公告类型 = 17;
	}
	_WriteLong(空白地址1 + 36, 公告类型); 

	ByteArr 汇编数据 = { 72, 129, 236, 0, 1, 0, 0 };
	汇编数据 = _AppendToBytes(汇编数据, { 72, 186 });
	汇编数据 = _AppendToBytes(汇编数据, _IntToBytes(空白地址1, 8));

	汇编数据 = _AppendToBytes(汇编数据, { 72, 190 });
	汇编数据 = _AppendToBytes(汇编数据, _IntToBytes(公告基址, 8));

	汇编数据 = _AppendToBytes(汇编数据, { 72, 139, 54 });
	汇编数据 = _AppendToBytes(汇编数据, { 72, 137, 241 });
	汇编数据 = _AppendToBytes(汇编数据, { 191, 255, 255, 255, 255 });

	汇编数据 = _AppendToBytes(汇编数据, { 72, 184 });
	汇编数据 = _AppendToBytes(汇编数据, _IntToBytes(公告CALL_1, 8));

	汇编数据 = _AppendToBytes(汇编数据, { 255, 208 });
	汇编数据 = _AppendToBytes(汇编数据, { 72, 129, 196, 0, 1, 0, 0 });
	汇编执行(汇编数据);
	汇编数据.clear();
}