#ifndef __MENU_H__
#define __MENU_H__

//#include "sys.h"
#include "uc1701x_12864.h"
#include "string.h"

#define SHOWTITLE		1               //�Ƿ���ʾ�˵�����
#define SHOWLINES		6               //һҳ��ʾ�˵�������
#define SHOWBOTTOMBAR		1           //�Ƿ���ʾ�ײ�������
#define SHOWSCOLLBAR	1               //�Ƿ���ʾ������

typedef struct MenuStruct{
	uint8_t StartNum;							//��ʾ��ʼ�˵���
	uint8_t TotalNum;							//��ǰ�˵�����Ŀ��
	uint8_t SelectedNum;					    //��ǰѡ�в˵������
	char *TitleString;						    //�˵�����
	char *ItemString;							//�˵������
	uint8_t isShowBackItem;                     //�Ƿ���ʾ�����ϼ��˵���ť
	struct MenuStruct *ParentsMenu;             //�ϼ��˵���ַ
	struct MenuStruct **SonMenu;	            //�Ӳ˵���ַ
	void **Function;							//���ù��̵�ַ
	
}MenuStruct;

void Menu_Keys_Scan(void);                  //����ɨ�躯��
void Screen_Clear(void);                    //��Ļ�������
void Menu_Next(void);                       //ѡ��˵���һ����Ѿ������һ���򲻶�
void Menu_Forward(void);                    //ѡ��˵���һ����Ѿ�����ǰһ���򲻶�
void Menu_Entry(void);                      //����ѡ�в˵�����ѡ�в˵����Ӳ˵�������Ӳ˵�����ѡ�в˵��к���������ִ�иù���
void Menu_Close(void);                      //�رղ˵�
void Menu_Open(MenuStruct *menu);           //�򿪲˵� ����ΪҪ�򿪵Ĳ˵��Ľṹ���ַ
void Menu_ShowString(MenuStruct *menu);     //�ڲ�����

#endif
