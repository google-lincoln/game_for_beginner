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
	outtextxy(104,180,"�ٽ�����,���ͣ� ");
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
	int totalBeat=0;					//������ĸ����
	int totalLoss=0;					//©����ĸ����

	//��ѭ��
	while(true)
	{
		target = 65 + rand() % 26;
		x = rand() %620;
		char strWin[80];
		char strLoss[80];
		sprintf(strWin, "�������� = %d", totalBeat);
		outtextxy(204,10,strWin);
		
		sprintf(strLoss, "©������ =%d", totalLoss);
		outtextxy(350,10,strLoss);

		for (y=15; y<460; y++)
		{
			setcolor(WHITE);
			Sleep(10);				//slow down the velocity of drop down and see the changes
			outtextxy(x,y,target);

			//�������жϰ�������Ĳ���
			if(kbhit())
			{
				key = getch();		//��ȡ��������

				if((key == target) || (key == target +32))
				{
					//������ȷ,"����"��ĸ
					//outtextxy(x,y,"����");
					bar(x,y,x+16,y+16);	
					totalBeat++;
					
					outtextxy(204,10,strWin);

					break;			
					
				}else if(key == 27){//�˳�
				
				
				}else{ //������©��
						if(y==459)
						{
							totalLoss++;
							sprintf(strLoss, "©������ =%d", totalLoss);
							outtextxy(350,10,strLoss);
							if(totalLoss==3)
							{
								goto EXIT;
							}
						
						}
				}
				
			}else{//û�а��������
				if(y==459)
				{
					totalLoss++;
					sprintf(strLoss, "©������ =%d", totalLoss);
					outtextxy(350,10,strLoss);
					if(totalLoss==3)
					{
						goto EXIT;
					}
				}
						  
			
			}

		
		}

		//��ʱ,�������ĸ
		Sleep(100);
		//setfillstyle(BLACK);
		//setcolor(BLACK);
		setfillcolor(BLACK);	//setfillcolor and bar will make character disappear
		bar(x,y,x+16,y+16);		//comment out see the last moment of drop character
		//fillrectangle(x,y,x+16,y+16);
		//rectangle(x,y,x+16,y+16);

	
	}

EXIT:
	//�˳�����
	goodbye();

	//�ر�ͼ�ν���
	closegraph();


	return 0;
}

