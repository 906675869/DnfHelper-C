// Dll_通讯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<windows.h>
#include<stdio.h>

 #pragma comment(lib, "D:\\Source\\Repos\\FirstDll\\x64\\Release\\FirstDll")

// extern "C" void ccc();
// 指向导出函数的指针 typedef void (*PMessage_Box)(char *);
 typedef void (*PMessage_Box)();

void Inject(int pid, char* Path) {
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    // 申请一块内存给DLL路径
    LPVOID pAddr = VirtualAllocEx(handle, NULL, strlen(Path) + 1, MEM_COMMIT, PAGE_READWRITE);
    // 写入路径到上一行代码申请的内存中
    WriteProcessMemory(handle, pAddr, Path, strlen(Path) + 1, NULL);
    HMODULE hmodule = LoadLibrary("KERNEL32.DLL");
    // 虚拟地址空间
    LPTHREAD_START_ROUTINE ipStartAddr = (LPTHREAD_START_ROUTINE)GetProcAddress(hmodule, "LoadLibraryA");
    // 创建远程线程并获取线程句柄
    HANDLE hThread = CreateRemoteThread(handle, NULL, 0, ipStartAddr, pAddr, 0, NULL);
    // 等待线程事件 dwMilliseconds 为INFINITE（永久等待） 则发出对象信号才返回该函数
    WaitForSingleObject(hThread, 2000);
    //卸载DLL
    // FreeLibrary(handle)
    CloseHandle(hThread);
    CloseHandle(handle);
}



void UnInjectDLL(int pid) {
    HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    // First.DLL 获取内存

    // 申请一块内存给DLL路径
    LPVOID pAddr = (LPVOID)0x0000;
  
    HMODULE hmodule = LoadLibrary("KERNEL32.DLL");
    // 虚拟地址空间
    LPTHREAD_START_ROUTINE ipStartAddr = (LPTHREAD_START_ROUTINE)GetProcAddress(hmodule, "FreeLibrary");
    // 创建远程线程并获取线程句柄
    HANDLE hThread = CreateRemoteThread(handle, NULL, 0, ipStartAddr, pAddr, 0, NULL);
    // 等待线程事件 dwMilliseconds 为INFINITE（永久等待） 则发出对象信号才返回该函数
    WaitForSingleObject(hThread, 2000);
    //卸载DLL
    // FreeLibrary(handle)
    CloseHandle(hThread);
    CloseHandle(handle);
}

void LocalLoad() {
    HMODULE hmodule = LoadLibraryA("D:\\Source\\Repos\\FirstDll\\x64\\Release\\FirstDll.dll");
    if (hmodule == NULL) {
        MessageBox(NULL, "句柄出错", "标题", MB_OK);
        return;
    }
    //从指定的dll中检索导出函数ccc的地址
    PMessage_Box pMsg = (PMessage_Box)GetProcAddress(hmodule, "ccc");
    // 执行函数
    pMsg();
    //卸载DLL
    FreeLibrary(hmodule);
    getchar();

}

int main()
{
    // ccc(); 
   
    // 
    const char* Path = "D:\\Source\\Repos\\FirstDll\\x64\\Release\\FirstDll.dll";
    Inject(6869, (char*)Path);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单





// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
