#include "pch.h"

#include <thread>
#include "Automatic.h"
#include "Common.h"


VOID Automatic::AutomaticSwitch() {
	MessageBoxW(NULL, L"Automatic�߳�", L"Automatic", MB_OK);
}

VOID Automatic::AutomaticThread() {
	while (true)
	{
		Sleep(1000);
		MessageBoxW(NULL, L"Automatic�߳�", L"Automatic", MB_OK);
	}
}

VOID Automatic::�������() {
}

VOID Automatic::������() {
}

VOID Automatic::����ѡͼ() {
}

VOID Automatic::���ؽ�ɫ() {
}

VOID Automatic::���븱��() {
}

VOID Automatic::ģ��˳ͼ() {
}

VOID Automatic::�˳�����() {
}