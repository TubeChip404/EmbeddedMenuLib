#ifndef __MENU_H__
#define __MENU_H__

//#include "sys.h"
#include "uc1701x_12864.h"
#include "string.h"

#define SHOWTITLE		1               //是否显示菜单标题
#define SHOWLINES		6               //一页显示菜单项数量
#define SHOWBOTTOMBAR		1           //是否显示底部导航栏
#define SHOWSCOLLBAR	1               //是否显示滚动条

typedef struct MenuStruct{
	uint8_t StartNum;							//显示起始菜单项
	uint8_t TotalNum;							//当前菜单总项目数
	uint8_t SelectedNum;					    //当前选中菜单项序号
	char *TitleString;						    //菜单标题
	char *ItemString;							//菜单项标题
	uint8_t isShowBackItem;                     //是否显示返回上级菜单按钮
	struct MenuStruct *ParentsMenu;             //上级菜单地址
	struct MenuStruct **SonMenu;	            //子菜单地址
	void **Function;							//调用过程地址
	
}MenuStruct;

void Menu_Keys_Scan(void);                  //按键扫描函数
void Screen_Clear(void);                    //屏幕清楚函数
void Menu_Next(void);                       //选择菜单下一项，若已经是最后一项则不动
void Menu_Forward(void);                    //选择菜单上一项，若已经是最前一项则不动
void Menu_Entry(void);                      //进入选中菜单，若选中菜单有子菜单则进入子菜单，若选中菜单有函数过程则执行该过程
void Menu_Close(void);                      //关闭菜单
void Menu_Open(MenuStruct *menu);           //打开菜单 参数为要打开的菜单的结构体地址
void Menu_ShowString(MenuStruct *menu);     //内部函数

#endif
