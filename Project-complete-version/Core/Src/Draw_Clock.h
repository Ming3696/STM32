#ifndef 	__DRAW_CLOCK_H__
#define 	__DRAW_CLOCK_H__

#define PI 3.1415926
#define X0 (140)
#define Y0 (120)

extern int shi;	
extern int shi_temp;
extern int fen;
extern int miao;
extern int flagshi;

void LCD_Clock_zhen(int x0, int y0, int Rs, float cita, int color);//TFT���뺯��
void Draw_Three_zhen(void);//TFT��3����
void Draw_Large_Scale(void);//�����̵Ĵ�̶�	
void Draw_Small_Scale(void);//�����̵�С�̶�	
void Draw_Dial_Numbers(void);//����������
void Draw_Dynamic_3hands(void);//����̬��3����

void LCD_DrawSin(double x0 , double y0, double A, double T, int n);//TFT�����Һ���



#endif