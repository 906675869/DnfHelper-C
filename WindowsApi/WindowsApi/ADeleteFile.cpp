#include <windows.h>
#include<stdio.h>

int main() {
	char Path_file[] = "C:\\Users\\Administrator\\Desktop\\111.txt";
	int status = DeleteFileA(Path_file);
	printf("返回值：%x. 拓展脱误信息 %d\n", status, GetLastError());
	getchar();
	return 0;
}