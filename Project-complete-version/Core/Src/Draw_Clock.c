#include "stm32g4xx.h"                  // Device header
#include "Draw_Clock.h"
#include <math.h>
#include "lcd.h"
				


float x1,y1,x2,y2;
float X1, X2, Y1, Y2;	

int i = 0;	//秒针
int j = 0;	//分针
int k = 0;	//时针
int m = 0;	//画刻度的循环变量
int l = 1;	//画表盘数字的循环变量

int shi = 0;	
int shi_temp;
int fen = 0;
int miao = 0;
int flagshi = 0;

extern volatile char flag1sOk ;		


//TFT画针函数
void LCD_Clock_zhen(int x0, int y0, int Rs, float cita, int color)
{
	float x1,y1,x2,y2;
	float CITA = cita/180*PI;
	x1 = Rs*sin(CITA);
	y1 = Rs*cos(CITA);
	x2 = x0 + x1;
	y2 = y0 - y1;
	LCD_DrawLine(X0,Y0, x2,y2,color);
}

//TFT画3根针
void Draw_Three_zhen(void)
		{
			LCD_Clock_zhen(X0, Y0, 95, 0,LIGHTGREEN );
			LCD_Clock_zhen(X0, Y0, 75, 0,RED);
			LCD_Clock_zhen(X0, Y0, 55, 0,WHITE);
		}

//画表盘的大刻度	
void Draw_Large_Scale(void)
{
		for(int i = 0; i<12; i++)
		{
			x1 = X0 + (114)*sin(i*PI/6);
			y1 = Y0 - (114)*cos(i*PI/6);
			x2 = X0 + (105)*sin(i*PI/6);
			y2 = Y0 - (105)*cos(i*PI/6);	
			LCD_DrawLine(x1,y1,x2,y2,YELLOW);
		}
}

//画表盘的小刻度	
void Draw_Small_Scale(void)
{
			while(m < 60)
			{
				m++;
				X1 = X0 + (113)*sin(m*PI/30);
				Y1 = Y0 - (113)*cos(m*PI/30);
				X2 = X0 + (110)*sin(m*PI/30);
				Y2 = Y0 - (110)*cos(m*PI/30);	
				LCD_DrawLine(X1,Y1,X2,Y2,YELLOW);
			}
}

//画表盘数字
void Draw_Dial_Numbers(void)
{
	while( l <13)
		{
			
			X1 = X0 + (100)*sin(l*PI/6);
			Y1 = Y0 - (100)*cos(l*PI/6);
			if(l <= 9)
			{
				LCD_ShowIntNum(X1,Y1,l,1,YELLOW,BLACK,12);
			}
			else
			{
				LCD_ShowIntNum(X1,Y1,l,2,YELLOW,BLACK,12);
			}
			l++;
		}
}

//动态的三根针
void Draw_Dynamic_3hands(void)
{

			if( j==12  )
			{
				j = 0;
				k++;
				if( k % 5 == 0 && k != 0 )
				{
					if ( k == 60 )
					{ k = 1;}
					shi++;
					if( shi >= 13 )
					{	
						shi = 1;
					}
					if( shi == 12 )
					{
						flagshi = 1- flagshi;
					}
				}
				LCD_Clock_zhen(	X0, Y0, 55, (k-1)*6, BLACK );
				LCD_Clock_zhen(	X0, Y0, 55,  k *6, WHITE );
				
				LCD_Clock_zhen(	X0, Y0, 75, 6*(k%5*12+j), RED );
				LCD_Clock_zhen(	X0, Y0, 95, 6*i, LIGHTGREEN );
			}
		
		if( i == 60 )
		{
			i = 0;
			LCD_Clock_zhen(	X0, Y0, 75, (k%5*12+j)*6, BLACK );
			LCD_Clock_zhen(	X0, Y0, 75, 6*(k%5*12+j+1), RED );
			
			LCD_Clock_zhen(	X0, Y0, 55, k*6, WHITE);
			LCD_Clock_zhen(	X0, Y0, 95, 6*i, LIGHTGREEN );
			j++;
			fen = k%5*12 + j;
			if(fen == 60)
			{	fen = 0;	}
		}
		
		if(	flag1sOk == 1	)
		{
			flag1sOk = 0;
			LCD_Clock_zhen(	X0, Y0, 95, i*6, BLACK );
			LCD_Clock_zhen(	X0, Y0, 95, 6*(i+1), LIGHTGREEN );
			
			LCD_Clock_zhen(	X0, Y0, 75, 6*(k%5*12+j), RED );
			LCD_Clock_zhen(	X0, Y0, 55, k*6, WHITE );
			i++;
			miao = i;
			if(miao == 60)
			{miao = 0;}
		}
}



//TFT画正弦函数
void LCD_DrawSin(double x0 , double y0, double A, double T, int n)
{
	double y = 0;
	double x = 0;
	double u = T/3600;
	for(int j= 0 ;j <n;j++)
	{
		for(int i = 0; i < 3600; i++)
		{
			x = j*T+x0 + i*u;
			y = y0 - A*sin(x/T*2*PI);
			LCD_DrawPoint(x,y,WHITE);
		}
	}
}