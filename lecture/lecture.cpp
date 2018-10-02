// lecture.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//欢迎界面
void welcome()
{
	//输出屏幕提示
	cleardevice();
	setcolor(YELLOW);
	setfont(64,0,"黑体");
	outtextxy(160,50,"打字母游戏");
	setcolor(WHITE);
	setfont(16,0,"宋体");
	outtextxy(100,200,"就是很传统的掉字母然后按相应键就消失的游戏");
	outtextxy(100,240,"只是做了一个很简单的实现");
	outtextxy(100,280,"功能并不是很完善,比如生命数、分数等都没有写");
	outtextxy(100,320,"感兴趣的自己加进去吧");
	
	//实现闪烁的"按任意键继续"
	int c=255;

	while(!kbhit())
	{
		setcolor(RGB(c,0,0));
		outtextxy(280,400,"按任意键继续");
		c -=8;
		if(c<0)
				c=255;
		
		Sleep(20);
	
	}
	getch();
	cleardevice();

}

//退出界面
void goodbye()
{
	cleardevice();
	setcolor(YELLOW);
	setfont(48,0,"黑体");
	outtextxy(104,180,"再接再厉,加油！ ");
	getch();

}


//主函数
int main(int argc, char* argv[])
{
	initgraph(640,480);					//初始化屏幕为  640*480

	
	welcome();							//显示字母的字体和大小

	srand(time(NULL));					//设置随机种子
	setfont(16,0,"Arial");				//设置字母的字体和大小
	setfillstyle(BLACK);				//设置清除字母的填充区域颜色


	char target;						//目标字母
	char key;							//用户的按键
	int x,y;							//字母的位置
	int totalBeat=0;					//击落字母数量
	int totalLoss=0;					//漏接字母数量

	//主循环
	while(true)
	{
		target = 65 + rand() % 26;
		x = rand() %620;
		char strWin[80];
		char strLoss[80];
		sprintf(strWin, "击落数量 = %d", totalBeat);
		outtextxy(204,10,strWin);
		
		sprintf(strLoss, "漏接数量 =%d", totalLoss);
		outtextxy(350,10,strLoss);

		for (y=15; y<460; y++)
		{
			setcolor(WHITE);
			Sleep(10);				//slow down the velocity of drop down and see the changes
			outtextxy(x,y,target);

			//以下是判断按键输入的部分
			if(kbhit())
			{
				key = getch();		//获取按键输入

				if((key == target) || (key == target +32))
				{
					//按键正确,"击落"字母
					//outtextxy(x,y,"击落");
					bar(x,y,x+16,y+16);	
					totalBeat++;
					
					outtextxy(204,10,strWin);

					break;			
					
				}else if(key == 27){//退出
				
				
				}else{ //击落与漏接
						if(y==459)
						{
							totalLoss++;
							sprintf(strLoss, "漏接数量 =%d", totalLoss);
							outtextxy(350,10,strLoss);
							if(totalLoss==3)
							{
								goto EXIT;
							}
						
						}
				}
				
			}else{//没有按键的情况
				if(y==459)
				{
					totalLoss++;
					sprintf(strLoss, "漏接数量 =%d", totalLoss);
					outtextxy(350,10,strLoss);
					if(totalLoss==3)
					{
						goto EXIT;
					}
				}
						  
			
			}

		
		}

		//延时,并清除字母
		Sleep(100);
		//setfillstyle(BLACK);
		//setcolor(BLACK);
		setfillcolor(BLACK);	//setfillcolor and bar will make character disappear
		bar(x,y,x+16,y+16);		//comment out see the last moment of drop character
		//fillrectangle(x,y,x+16,y+16);
		//rectangle(x,y,x+16,y+16);

	
	}

EXIT:
	//退出部分
	goodbye();

	//关闭图形界面
	closegraph();


	return 0;
}

