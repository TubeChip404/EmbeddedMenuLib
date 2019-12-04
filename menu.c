#include "menu.h"

MenuStruct *CurrentMenu;
uint8_t MenuState;//bit0:Open(1) or Close(0)
char MenuStringTemp[21]={0};


void Screen_Clear(void){
    //屏幕清除函数（可选）
}

void Screen_DispString(char*mystr,uint16_t offset_x,uint8_t lines,uint8_t fontsize,uint8_t anticolor){
    //字符串显示函数
    /*
        mystr 字符串指针
        offset_x 横向偏移量（单位：像素）
        lines 纵向坐标（单位：行）
        fontsize 字体大小
        anticolor 是否反色（菜单项选中时该值为1，未选中时该值为0）
    */
}

void Screen_Refresh(void){
	//屏幕刷新函数（可选）
}

void Menu_Keys_Scan(void){
    //按键扫描函数
    /*
	if((GPIOA->IDR&GPIO_Pin_8)==0){
		delay_ms(50);
		if((GPIOA->IDR&GPIO_Pin_8)==0){
			Menu_Forward();
		}
	}
	if((GPIOA->IDR&GPIO_Pin_9)==0){
		delay_ms(50);
		if((GPIOA->IDR&GPIO_Pin_9)==0){
			Menu_Entry();
		}
	}
	if((GPIOA->IDR&GPIO_Pin_10)==0){
		delay_ms(50);
		if((GPIOA->IDR&GPIO_Pin_10)==0){
			Menu_Next();
		}
	}*/
}

void Menu_ProgressBar(void){
    //滚动条显示函数，该函数由于不同屏幕之间操作差异较大，故没有统一的实现过程
    /*
	uint8_t i,t,m;
	uint64_t bar=0;
	if(CurrentMenu->TotalNum<=6)return;
	for(i=1;i<7;i++)UC1701X_Gram[i][125]=0xff;
	t=288/CurrentMenu->TotalNum+1;
	for(i=0;i<t;i++)bar|=0x01<<i;
	m=CurrentMenu->StartNum*(48-t)/(CurrentMenu->TotalNum-6);
	bar<<=m;
	for(i=0;i<6;i++){
		t=bar>>(i*8);
		UC1701X_Gram[i+1][124]=t;
		UC1701X_Gram[i+1][126]=t;
	}*/
}

void StringSplit(char *instr,uint8_t index){
	uint16_t i=0,t=0,last=0,now=0,flag=1;
	while(flag){
		if(instr[i]=='|'||instr[i]==0){
			t++;
			last=now;
			now=i;
			if(t==index+1)break;
		}
		if(instr[i]==0)flag=0;
		i++;
	}
	t=0;
	for(i=last==0?0:last+1;i<now;i++)MenuStringTemp[t++]=instr[i];
	MenuStringTemp[t]=0;
}

void Menu_ShowString(MenuStruct *menu){
	uint8_t i,t,m=0;
	Screen_Clear();
	if(SHOWTITLE)Screen_DispString(menu->TitleString,0,0,0,0);
	m=(menu->TotalNum)+(menu->isShowBackItem?1:0);
	t=(m-menu->StartNum)>SHOWLINES?menu->StartNum+SHOWLINES:m;
	for(i=menu->StartNum;i<t;i++){
		if(menu->isShowBackItem)if(i==m-1){
			Screen_DispString("<-- Back ",0,i-menu->StartNum+1,0,i==menu->SelectedNum?1:0);
			continue;
		}
		StringSplit(menu->ItemString,i);
		Screen_DispString(MenuStringTemp,0,i-menu->StartNum+1,0,i==menu->SelectedNum?1:0);
		if(CurrentMenu->SonMenu[i]!=NULL)Screen_DispString("->",110,i-menu->StartNum+1,0,0);
	}
	if(SHOWBOTTOMBAR)Screen_DispString("   Up     OK    Down  ",0,SHOWTITLE+SHOWBOTTOMBAR+SHOWLINES,0,0);
	if(SHOWSCOLLBAR)Menu_ProgressBar();
	Screen_Refresh();
}

void Menu_Next(void){
	uint8_t m=(CurrentMenu->TotalNum)+(CurrentMenu->isShowBackItem?1:0);
	if((CurrentMenu->SelectedNum+1)<m)CurrentMenu->SelectedNum++;
	else return;
	if(CurrentMenu->SelectedNum>CurrentMenu->StartNum+5)CurrentMenu->StartNum++;
	Menu_ShowString(CurrentMenu);
}
void Menu_Forward(void){
	if((CurrentMenu->SelectedNum-1)>=0)CurrentMenu->SelectedNum--;
	else return;
	if(CurrentMenu->SelectedNum<CurrentMenu->StartNum)CurrentMenu->StartNum--;
	Menu_ShowString(CurrentMenu);
}
void Menu_Entry(void){
	void (*myfunc)(void);
	if((CurrentMenu->isShowBackItem)&&(CurrentMenu->SelectedNum==CurrentMenu->TotalNum)){
		CurrentMenu=CurrentMenu->ParentsMenu;
		CurrentMenu->StartNum=0;
		CurrentMenu->SelectedNum=0;
	}else if(CurrentMenu->SonMenu[CurrentMenu->SelectedNum]!=NULL){
		CurrentMenu=CurrentMenu->SonMenu[CurrentMenu->SelectedNum];
		CurrentMenu->StartNum=0;
		CurrentMenu->SelectedNum=0;
	}else if(CurrentMenu->Function[CurrentMenu->SelectedNum]!=NULL){
		myfunc=((CurrentMenu->Function[CurrentMenu->SelectedNum]));
		myfunc();
	}
	Menu_ShowString(CurrentMenu);
}
void Menu_Close(void){
	Screen_Clear();
	MenuState&=~0x01;
}
void Menu_Open(MenuStruct *menu){
	CurrentMenu=menu;
	CurrentMenu->StartNum=0;
	CurrentMenu->SelectedNum=0;
	Menu_ShowString(CurrentMenu);
	MenuState|=0x01;
}
