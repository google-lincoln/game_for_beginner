// lecture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//��ӭ����
void welcome()
{
	//�����Ļ��ʾ
	cleardevice();
	setcolor(YELLOW);
	setfont(64,0,"����");
	outtextxy(160,50,"����ĸ��Ϸ");
	setcolor(WHITE);
	setfont(16,0,"����");
	outtextxy(100,200,"���Ǻܴ�ͳ�ĵ���ĸȻ����Ӧ������ʧ����Ϸ");
	outtextxy(100,240,"ֻ������һ���ܼ򵥵�ʵ��");
	outtextxy(100,280,"���ܲ����Ǻ�����,�����������������ȶ�û��д");
	outtextxy(100,320,"����Ȥ���Լ��ӽ�ȥ��");
	
	//ʵ����˸��"�����������"
	int c=255;

	while(!kbhit())
	{
		setcolor(RGB(c,0,0));
		outtextxy(280,400,"�����������");
		c -=8;
		if(c<0)
				c=255;
		
		Sleep(20);
	
	}
	getch();
	cleardevice();

}

//�˳�����
void goodbye()
{
	cleardevice();
	setcolor(YELLOW);
	setfont(48,0,"����");
	outtextxy(104,180,"��д����  ��������");
	getch();

}


//������
int main(int argc, char* argv[])
{
	initgraph(640,480);					//��ʼ����ĻΪ  640*480

	
	welcome();							//��ʾ��ĸ������ʹ�С

	srand(time(NULL));					//�����������
	setfont(16,0,"Arial");				//������ĸ������ʹ�С
	setfillstyle(BLACK);				//���������ĸ�����������ɫ


	char target;						//Ŀ����ĸ
	char key;							//�û��İ���
	int x,y;							//��ĸ��λ��

	//��ѭ��
	while(true)
	{
		target = 65 + rand() % 26;
		x = rand() %620;

		for (y=0; y<460; y++)
		{
			setcolor(WHITE);
			Sleep(10);
			outtextxy(x,y,target);

		
		}

		//��ʱ,�������ĸ
		Sleep(100);
		bar(x,y,x+16,y+16);

	
	}

	printf("Hello World!\n");
	return 0;
}

