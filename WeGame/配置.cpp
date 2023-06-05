#include "文件.h"
#include "数组.h"

配置数据 配置;

wstring 三世获取桌面路径()
{
	LPWSTR path[255];
	ZeroMemory(path, 255);
	SHGetSpecialFolderPath(0, (LPWSTR)path, CSIDL_DESKTOPDIRECTORY, 0);
	wstring 局_路径 = ((LPWSTR)path);
	wstring 局_斜线 = L"\\";
	局_路径 = 局_路径 + 局_斜线;
	return 	局_路径;
}

void 写配置(wstring 项名称, wstring 数据)
{
	wstring 文件路径 = 三世获取桌面路径() + L"\\" + 配置.辅助名字 + L".ini";
	wstring 节名称 = 配置.辅助名字 + L"配置";
	WritePrivateProfileStringW(节名称.c_str(), 项名称.c_str(), 数据.c_str(), 文件路径.c_str());
}

int 读配置(wstring 项名称)
{
	wstring 文件路径 = 三世获取桌面路径() + L"\\" + 配置.辅助名字 + L".ini";
	wstring 节名称 = 配置.辅助名字 + L"配置";
	return GetPrivateProfileIntW(节名称.c_str(), 项名称.c_str(), 0, 文件路径.c_str());
}

bool 文件是否存在()
{
	wstring 文件路径 = 三世获取桌面路径() + L"\\" + 配置.辅助名字 + L".ini";
	if (GetFileAttributesW(文件路径.c_str()) == INVALID_FILE_ATTRIBUTES)return false;
	else return true;
}

LPWSTR 读文本配置(LPCWSTR config_item)
{
	LPWSTR lpPath = (LPWSTR)(new WCHAR[MAX_PATH]);
	static WCHAR read_result[4096] = { NULL };
	SHGetSpecialFolderPath(0, lpPath, 16, 0);//20font
	WCHAR ming[] = L"\\饕餮.ini";
	size_t len2 = wcslen(lpPath) + wcslen(ming) + 1;
	wcscat_s(lpPath, len2, ming);
	GetPrivateProfileString(L"饕餮配置", config_item, 0, read_result, sizeof(read_result) / 2, lpPath);
	delete[] lpPath;
	return read_result;
}

void 读出配置()
{
	配置.辅助名字 = L"饕餮";


	配置.技能代码 = L"技能代码";
	配置.技能伤害 = L"技能伤害";
	配置.技能频率 = L"技能频率";
	配置.技能个数 = L"技能个数";
	配置.技能大小 = L"技能大小";

	配置.自动模式 = L"自动模式";
	配置.副本编号 = L"副本编号";
	配置.副本难度 = L"副本难度";

	配置.预留疲劳 = L"预留疲劳";

	配置.跟随方式 = L"跟随方式";
	配置.拾取方式 = L"拾取方式";
	配置.顺图方式 = L"顺图方式";

	配置.白色装备 = L"白色装备";
	配置.蓝色装备 = L"蓝色装备";
	配置.紫色装备 = L"紫色装备";
	配置.粉色装备 = L"粉色装备";
	配置.史诗装备 = L"史诗装备";
	配置.勇者装备 = L"勇者装备";
	配置.传说装备 = L"传说装备";

	配置.未央全图 = L"未央全图";

}

void 写出配置()
{
	写配置(配置.技能代码, L"9880");
	写配置(配置.技能伤害, L"85000000");
	写配置(配置.技能频率, L"300");
	写配置(配置.技能个数, L"2");
	写配置(配置.技能大小, L"5\n");

	写配置(配置.自动模式, L"2		={1}指定地图 ={2}剧情升级 ={3}适应等级地图 ={4}暂无 ={5}云上未央");
	写配置(配置.副本编号, L"100000002");
	写配置(配置.副本难度, L"5		={0}普通级 ={1}冒险级 ={2}勇士级 ={3}王者级 ={4}噩梦级 ={5}取最高\n");

	写配置(配置.预留疲劳, L"0");

	写配置(配置.跟随方式, L"1		={0}不执行 ={1}坐标跟随 ={2}漂移跟随");
	写配置(配置.拾取方式, L"3		={0}不执行 ={1}按键入包 ={2}落地入包 ={3}空中入包");
	写配置(配置.顺图方式, L"2		={0}不执行 ={1}坐标顺图 ={2}漂移顺图 ={3}强制顺图");

	写配置(配置.未央全图, L"1		={0}否 ={1}是\n");

	写配置(配置.白色装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.蓝色装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.紫色装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.粉色装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.史诗装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.勇者装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃");
	写配置(配置.传说装备, L"0		={0}不执行 ={1}出售 ={2}分解 ={3}丢弃\n");
}