#include <windows.h>
#include<stdio.h>

int main() {
	char Path_file[] = "C:\\Users\\Administrator\\Desktop\\111.txt";
	int status = DeleteFileA(Path_file);
	printf("����ֵ��%x. ��չ������Ϣ %d\n", status, GetLastError());
	getchar();
	return 0;
}