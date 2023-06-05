// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

extern "C" __declspec(dllexport) void ccc();

void ccc() {
    MessageBox(NULL,"导出函数被调用成功","信息：",MB_YESNO);
}


// 用作导出的函数
void add() {

}


void release() {
}

// hModule dll 模块句柄 ul_reason_for_call 被调用的原因  lpReserved 保留参数，windows不想让我们知道作用的参数
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // DLL被进程加载
        add();
    case DLL_THREAD_ATTACH:
        // 线程创建
    case DLL_THREAD_DETACH:
        // 线程结束
    case DLL_PROCESS_DETACH:
        // 被进程卸载
        release();
        break;
    }
    return TRUE;
}

