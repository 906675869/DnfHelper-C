#include "pch.h"
#include "�ļ�.h"
#include "����.h"

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

int ȡ�����(int ��Сֵ, int ���ֵ)
{
	int rNum = 0;
	srand(GetTickCount());
	for (size_t i = 0; i < 31; i++)
		rNum |= (rand() & 1) << i;
	return ��Сֵ + rNum % (���ֵ - ��Сֵ + 1);
}

wstring ���ı�(int ����ֵ)
{
	wchar_t �ı�����[10] = { 0 };

	_itow_s(����ֵ, �ı�����, 10);

	wstring �����ַ(�ı�����);

	return �����ַ;
}

ULONG64 �ڴ�����(size_t size)
{
	return (ULONG64)VirtualAlloc(NULL, size, MEM_COMMIT | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);
}


void д�ֽڼ�(ULONG64 ��_�ڴ��ַ, vector<byte> ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 1))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, ��_д������.size(), 64, &old_protect);//�޸��ڴ�����
	for (size_t i = 0; i < ��_д������.size(); i++)
	{
		*(byte*)��_�ڴ��ַ++ = ��_д������[i];
	}
	VirtualProtect((LPVOID)��_�ڴ��ַ, ��_д������.size(), old_protect, &old_protect);//��ԭ�ڴ�����
}

vector<byte> ���ֽڼ�(ULONG64  i, int λ��)
{
	if (λ�� == 0)
	{
		λ�� = 8;
	}
	ULONG64  adr = (ULONG64)&i;
	std::vector<byte>c;
	for (size_t i = 0; i < λ��; i++) {
		c.push_back(*(byte*)adr++);
	}
	return c;
}

vector<byte> ���ֽڼ�(ULONG64 ��_�ڴ��ַ, DWORD ��_��ȡ����)
{
	vector<byte> ����ֵ;
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, ��_��ȡ����))
	{
		return {};
	}
	for (size_t i = 0; i < ��_��ȡ����; i++)
	{
		����ֵ.insert(����ֵ.end(), *(byte*)��_�ڴ��ַ++);
	}
	return ����ֵ;

}

wstring ȡ�ı��ұ�(wstring �ı�, size_t ��ֵ)
{
	wstring result;

	if (��ֵ > �ı�.size())
	{
		��ֵ = 0;
	}
	else
	{
		��ֵ = �ı�.size() - ��ֵ;
	}

	result = �ı�.substr(��ֵ);

	return result;
}

wstring ȡ�ı����(wstring �ı�, size_t ��ֵ)
{
	wstring result;

	if (��ֵ > �ı�.size())
	{
		��ֵ = �ı�.size();
	}

	result = �ı�.substr(0, ��ֵ);

	return result;
}

wstring ͨ��ʱ��(int ��ַ)
{
	int i1;
	int i2;
	int i3;
	wstring i4;
	wstring i5;

	if (��ַ < 1000)
	{
		i5 = L"0��:" + ���ı�(��ַ / 10);
	}
	else
	{
		i4 = ȡ�ı��ұ�(���ı�(��ַ), 3);
		i4 = ȡ�ı����(i4, 2);

		��ַ = ��ַ / 1000;

		i1 = ��ַ / 3600;
		i2 = (��ַ - i1 * 3600) / 60;
		i3 = (��ַ - i1 * 3600) % 60;

		if (i1 > 0)
		{
			i5 = ���ı�(i1) + L"ʱ:" + ���ı�(i2) + L"��:" + ���ı�(i3) + L"��:" + i4;
		}
		else if (i2 > 0)
		{
			i5 = ���ı�(i2) + L"��:" + ���ı�(i3) + L"��:" + i4;
		}
		else if (i3 > 0)
		{
			i5 = ���ı�(i3) + L"��:" + i4;
		}
	}
	return i5;
}

void �ָ��ı�(const wstring& str, vector<wstring>& tokens, const wstring& delimiters)
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

double ��С����(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return 0;
	}
	return *(double*)��_�ڴ��ַ;
}

DWORD ��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return 0;
	}
	return *(DWORD*)��_�ڴ��ַ;
}

ULONG64 ��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return 0;
	}
	return *(ULONG64*)��_�ڴ��ַ;
}

BYTE ���ֽ���(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 1))
	{
		return 0;
	}
	return *(BYTE*)��_�ڴ��ַ;
}

BYTE ��������(ULONG64 ��_�ڴ��ַ)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 2))
	{
		return 0;
	}
	return *(BYTE*)��_�ڴ��ַ;
}

void д������(ULONG64 ��_�ڴ��ַ, ULONG64 ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 8))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 8, 64, &old_protect);
	*(ULONG64*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 8, old_protect, &old_protect);
}

void д�ֽ���(ULONG64 ��_�ڴ��ַ, BYTE ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 1, 64, &old_protect);
	*(BYTE*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 1, old_protect, &old_protect);
}

void д������(ULONG64 ��_�ڴ��ַ, DWORD ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(DWORD*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}

void дС����(ULONG64 ��_�ڴ��ַ, float ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(float*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}

void д������(ULONG64 ��_�ڴ��ַ, WORD ��_д������)
{
	if (IsBadReadPtr((VOID*)��_�ڴ��ַ, 4))
	{
		return;
	}
	DWORD old_protect;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, 64, &old_protect);
	*(WORD*)��_�ڴ��ַ = ��_д������;
	VirtualProtect((LPVOID)��_�ڴ��ַ, 4, old_protect, &old_protect);
}


ULONG64 ʮ����ʮ(string ʮ������)
{
	ULONG64 retn = 0;

	string Hex = "0123456789ABCDEF";

	for (size_t i = 0; i < ʮ������.size(); i++)
	{
		size_t Index = Hex.find(ʮ������.substr(i, 1));

		if (Index != Hex.npos)
		{
			retn = retn * 16 + Index;
		}
	}
	return retn;
}

string ʮ��ʮ��(long long num)
{
	string str;
	long long temp = num / 16;
	int left = num % 16;
	if (temp > 0)
	{
		str += ʮ��ʮ��(temp);
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