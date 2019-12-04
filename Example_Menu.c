#include "menu.h"

void Beep_ON(void);
void Beep_OFF(void);
void Unit_Sv(void);
void Unit_R(void);
void Unit_CPM(void);
void Unit_CPS(void);
void BKL_Level(void);
void BKL_Auto_OFF(void);
void BKL_Auto_30s(void);
void BKL_Auto_1min(void);
void BKL_Auto_5min(void);
void Alarm_OFF(void);
void Alarm_1uSv(void);
void Alarm_10uSv(void);
void Alarm_100uSv(void);
void Beep_ON(void);
void Beep_OFF(void);
void Unit_Sv(void);
void Unit_R(void);
void Unit_CPM(void);
void Unit_CPS(void);
void BKL_Level(void);
void BKL_Auto_OFF(void);
void BKL_Auto_30s(void);
void BKL_Auto_1min(void);
void BKL_Auto_5min(void);
void Alarm_OFF(void);
void Alarm_1uSv(void);
void Alarm_10uSv(void);
void Alarm_100uSv(void);
void Dose_ON(void);
void Dose_OFF(void);
MenuStruct *beepmenu_menupoint[]={NULL,NULL};
void *beepmenu_voidpoint[]={Beep_ON,Beep_OFF};
MenuStruct beepmenu;
MenuStruct *unitmenu_menupoint[]={NULL,NULL,NULL,NULL};
void *unitmenu_voidpoint[]={Unit_Sv,Unit_R,Unit_CPM,Unit_CPS};
MenuStruct unitmenu;
MenuStruct *bklautomenu_menupoint[]={NULL,NULL,NULL,NULL};
void *bklautomenu_voidpoint[]={BKL_Auto_OFF,BKL_Auto_30s,BKL_Auto_1min,BKL_Auto_5min};
MenuStruct bklautomenu;
MenuStruct *bklmenu_menupoint[]={NULL,&bklautomenu};
void *bklmenu_voidpoint[]={BKL_Level,NULL};
MenuStruct bklmenu;
MenuStruct *alarmmenu_menupoint[]={NULL,NULL,NULL,NULL};
void *alarmmenu_voidpoint[]={Alarm_OFF,Alarm_1uSv,Alarm_10uSv,Alarm_100uSv};
MenuStruct alarmmenu;
MenuStruct *dosemenu_menupoint[]={NULL,NULL};
void *dosemenu_voidpoint[]={Dose_ON,Dose_OFF};
MenuStruct dosemenu;
MenuStruct *MainMenu_menupoint[]={&beepmenu,&unitmenu,&bklmenu,&alarmmenu,&dosemenu};
void *MainMenu_voidpoint[]={NULL,NULL,NULL,NULL,NULL};
MenuStruct MainMenu;



void Menu_Init(void){
	beepmenu.TotalNum=2;
	beepmenu.ItemString="1.ON|2.OFF";
	beepmenu.SonMenu=beepmenu_menupoint;
	beepmenu.TitleString="Set Beep State";
	beepmenu.Function=beepmenu_voidpoint;
	beepmenu.ParentsMenu=&MainMenu;
	beepmenu.isShowBackItem=1;

	unitmenu.TotalNum=4;
	unitmenu.ItemString="1.Sv/h|2.R/h|3.CPM|4.CPS";
	unitmenu.SonMenu=unitmenu_menupoint;
	unitmenu.TitleString="Set Unit State";
	unitmenu.Function=unitmenu_voidpoint;
	unitmenu.ParentsMenu=&MainMenu;
	unitmenu.isShowBackItem=1;

	bklautomenu.TotalNum=4;
	bklautomenu.ItemString="1.OFF|2. 30s|3. 1min|4. 5min";
	bklautomenu.SonMenu=bklautomenu_menupoint;
	bklautomenu.TitleString="Set Auto OFF";
	bklautomenu.Function=bklautomenu_voidpoint;
	bklautomenu.ParentsMenu=&bklmenu;
	bklautomenu.isShowBackItem=1;

	bklmenu.TotalNum=2;
	bklmenu.ItemString="1.Level|2.Auto OFF";
	bklmenu.SonMenu=bklmenu_menupoint;
	bklmenu.TitleString="Set Backlight";
	bklmenu.Function=bklmenu_voidpoint;
	bklmenu.ParentsMenu=&MainMenu;
	bklmenu.isShowBackItem=1;

	alarmmenu.TotalNum=4;
	alarmmenu.ItemString="1.OFF|2.1uSv/h|3.10uSv/h|4.100uSv/h";
	alarmmenu.SonMenu=alarmmenu_menupoint;
	alarmmenu.TitleString="Set Alarm State";
	alarmmenu.Function=alarmmenu_voidpoint;
	alarmmenu.ParentsMenu=&MainMenu;
	alarmmenu.isShowBackItem=1;

	dosemenu.TotalNum=2;
	dosemenu.ItemString="1.ON|2.OFF";
	dosemenu.SonMenu=dosemenu_menupoint;
	dosemenu.TitleString="Set Dose Param";
	dosemenu.Function=dosemenu_voidpoint;
	dosemenu.ParentsMenu=&MainMenu;
	dosemenu.isShowBackItem=1;

	MainMenu.TotalNum=5;
	MainMenu.ItemString="1.Beep|2.Unit|3.Backlight|4.Alarm|5.Dose";
	MainMenu.SonMenu=MainMenu_menupoint;
	MainMenu.TitleString="MainMenu";
	MainMenu.Function=MainMenu_voidpoint;
	MainMenu.ParentsMenu=&MainMenu;
	MainMenu.isShowBackItem=0;


}

void Beep_ON(void){

}
void Beep_OFF(void){

}
void Unit_Sv(void){

}
void Unit_R(void){

}
void Unit_CPM(void){

}
void Unit_CPS(void){

}
void BKL_Level(void){

}
void BKL_Auto_OFF(void){

}
void BKL_Auto_30s(void){

}
void BKL_Auto_1min(void){

}
void BKL_Auto_5min(void){

}
void Alarm_OFF(void){

}
void Alarm_1uSv(void){

}
void Alarm_10uSv(void){

}
void Alarm_100uSv(void){

}
void Beep_ON(void){

}
void Beep_OFF(void){

}
void Unit_Sv(void){

}
void Unit_R(void){

}
void Unit_CPM(void){

}
void Unit_CPS(void){

}
void BKL_Level(void){

}
void BKL_Auto_OFF(void){

}
void BKL_Auto_30s(void){

}
void BKL_Auto_1min(void){

}
void BKL_Auto_5min(void){

}
void Alarm_OFF(void){

}
void Alarm_1uSv(void){

}
void Alarm_10uSv(void){

}
void Alarm_100uSv(void){

}
void Dose_ON(void){

}
void Dose_OFF(void){

}
