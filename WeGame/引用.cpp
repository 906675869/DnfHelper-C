#include "pch.h"
#include "文件.h"
#include "引用.h"

ULONG64 Func_CALL(ULONGLONG ADDR__, ULONGLONG RCX__, ULONGLONG RDX__, ULONGLONG R8__, ULONGLONG R9__, ULONGLONG R10__, ULONGLONG R11__, ULONGLONG R12__, ULONGLONG R13__, ULONGLONG R14__, ULONGLONG R15__)
{
	_Func_Call MyFastCall = (_Func_Call)ADDR__;

	return MyFastCall(RCX__,
		RDX__,
		R8__,
		R9__,
		R10__,
		R11__,
		R12__,
		R13__,
		R14__,
		R15__);
}

int 取随机数(int 最小值, int 最大值)
{
	int rNum = 0;
	srand(GetTickCount());
	for (size_t i = 0; i < 31; i++)
		rNum |= (rand() & 1) << i;
	return 最小值 + rNum % (最大值 - 最小值 + 1);
}

wstring 到文本(int 欲用值)
{
	wchar_t 文本数组[10] = { 0 };

	_itow_s(欲用值, 文本数组, 10);

	wstring 数组地址(文本数组);

	return 数组地址;
}

ULONG64 内存申请(size_t size)
{
	return (ULONG64)VirtualAlloc(NULL, size, MEM_COMMIT | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);
}


void 写字节集(ULONG64 参_内存地址, vector<byte> 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 1))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 参_写入数据.size(), 64, &old_protect);//修改内存属性
	for (size_t i = 0; i < 参_写入数据.size(); i++)
	{
		*(byte*)参_内存地址++ = 参_写入数据[i];
	}
	VirtualProtect((LPVOID)参_内存地址, 参_写入数据.size(), old_protect, &old_protect);//还原内存属性
}

vector<byte> 到字节集(ULONG64  i, int 位数)
{
	if (位数 == 0)
	{
		位数 = 8;
	}
	ULONG64  adr = (ULONG64)&i;
	std::vector<byte>c;
	for (size_t i = 0; i < 位数; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

vector<byte> 读字节集(ULONG64 参_内存地址, DWORD 参_读取长度)
{
	vector<byte> 返回值;
	if (IsBadReadPtr((VOID*)参_内存地址, 参_读取长度))
	{
		return {};
	}
	for (size_t i = 0; i < 参_读取长度; i++)
	{
		返回值.insert(返回值.end(), *(byte*)参_内存地址++);
	}
	return 返回值;

}

wstring 取文本右边(wstring 文本, size_t 数值)
{
	wstring result;

	if (数值 > 文本.size())
	{
		数值 = 0;
	}
	else
	{
		数值 = 文本.size() - 数值;
	}

	result = 文本.substr(数值);

	return result;
}

wstring 取文本左边(wstring 文本, size_t 数值)
{
	wstring result;

	if (数值 > 文本.size())
	{
		数值 = 文本.size();
	}

	result = 文本.substr(0, 数值);

	return result;
}

wstring 通关时间(int 地址)
{
	int i1;
	int i2;
	int i3;
	wstring i4;
	wstring i5;

	if (地址 < 1000)
	{
		i5 = L"0秒:" + 到文本(地址 / 10);
	}
	else
	{
		i4 = 取文本右边(到文本(地址), 3);
		i4 = 取文本左边(i4, 2);

		地址 = 地址 / 1000;

		i1 = 地址 / 3600;
		i2 = (地址 - i1 * 3600) / 60;
		i3 = (地址 - i1 * 3600) % 60;

		if (i1 > 0)
		{
			i5 = 到文本(i1) + L"时:" + 到文本(i2) + L"分:" + 到文本(i3) + L"秒:" + i4;
		}
		else if (i2 > 0)
		{
			i5 = 到文本(i2) + L"分:" + 到文本(i3) + L"秒:" + i4;
		}
		else if (i3 > 0)
		{
			i5 = 到文本(i3) + L"秒:" + i4;
		}
	}
	return i5;
}

void 分割文本(const wstring& str, vector<wstring>& tokens, const wstring& delimiters)
{
	// Skip delimiters at beginning.
	wstring::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	wstring::size_type pos = str.find_first_of(delimiters, lastPos);
	while (wstring::npos != pos || wstring::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}

double 读小数型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return 0;
	}
	return *(double*)参_内存地址;
}

DWORD 读整数型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return 0;
	}
	return *(DWORD*)参_内存地址;
}

ULONG64 读长整数(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return 0;
	}
	return *(ULONG64*)参_内存地址;
}

BYTE 读字节型(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 1))
	{
		return 0;
	}
	return *(BYTE*)参_内存地址;
}

BYTE 读短整数(ULONG64 参_内存地址)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 2))
	{
		return 0;
	}
	return *(BYTE*)参_内存地址;
}

void 写长整数(ULONG64 参_内存地址, ULONG64 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 8))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 8, 64, &old_protect);
	*(ULONG64*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 8, old_protect, &old_protect);
}

void 写字节型(ULONG64 参_内存地址, BYTE 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 1, 64, &old_protect);
	*(BYTE*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 1, old_protect, &old_protect);
}

void 写整数型(ULONG64 参_内存地址, DWORD 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(DWORD*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}

void 写小数型(ULONG64 参_内存地址, float 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(float*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}

void 写短整数(ULONG64 参_内存地址, WORD 参_写入数据)
{
	if (IsBadReadPtr((VOID*)参_内存地址, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)参_内存地址, 4, 64, &old_protect);
	*(WORD*)参_内存地址 = 参_写入数据;
	VirtualProtect((LPVOID)参_内存地址, 4, old_protect, &old_protect);
}


ULONG64 十六到十(string 十六进制)
{
	ULONG64 retn = 0;

	string Hex = "0123456789ABCDEF";

	for (size_t i = 0; i < 十六进制.size(); i++)
	{
		size_t Index = Hex.find(十六进制.substr(i, 1));

		if (Index != Hex.npos)
		{
			retn = retn * 16 + Index;
		}
	}
	return retn;
}

string 十到十六(long long num)
{
	string str;
	long long temp = num / 16;
	int left = num % 16;
	if (temp > 0)
	{
		str += 十到十六(temp);
	}
	if (left < 10)
	{
		str += (left + '0');
	}
	else
	{
		str += ('A' + left - 10);
	}
	return str;
}