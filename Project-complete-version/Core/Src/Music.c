#include "stm32g4xx.h"                  // Device header
#include "Music.h"


uint32_t aCCValue_Buffer[Table_NUM];
uint16_t scale[25] = {0,doi,re,mi,fa,so,la,ci,Doi,Re,Mi,Fa,So,La,Ci,DOI,shengla,ShengFa,ShengRe,CO3,FO3,shengso};
//uint8_t music[100] = {1,0,1,0,5,0,5,0,6,0,6,0,5,0,0,0,4,0,4,0,3,0,3,0,2,0,2,0,1,0,0,0};
uint8_t music[130] = {10,10,0,10,10,0,0,0,10,10,10,0,0,8,8,0,10,10,0,0,12,12,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,
	
											8,8,0,0,0,0,0,5,5,0,0,0,0,3,3,0,0,0,0,6,6,0,0,0,7,7,0,0,16,0,6,6,0,0,0,5,5,0,10,10,0,0,12,12,0,
											13,13,0,0,11,11,0,12,12,0,0,10,10,0,0,8,8,0,9,9,0,7,7,0,0,0,0,0,};
	
int  cishu = 0;
int kk = 0;	
	
void Music_Clock(void)
{	
			if(scale[music[kk]] == 0)
			{
				stop;
			}
			else
			{
				start;
				__HAL_TIM_SET_PRESCALER(&htim3,scale[music[kk]]);
			}
			if(kk > 112)
			{
				kk = -1;
				cishu++;
			}
			kk++;
}