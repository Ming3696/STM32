#ifndef		__MUSIC_H__
#define		__MUSIC_H__

#include "main.h"
#include "tim.h"

#define		Table_NUM		2048
#define		OFFSET 			500
#define		AMP				498
#define   SMOOTH
#define		SOUND
#define 	CO3			1297
#define 	FO3			918
#define   doi     647
#define   re      578
#define   mi      515
#define   fa      487
#define		shengfa	458
#define   so      433
#define		shengso 409
#define   la      385
#define		shengla	364
#define   ci      343
#define 	Doi			324
#define		Re			291
#define		ShengRe	272
#define		Mi			258
#define 	Fa			242
#define		ShengFa	229
#define		So			216	
#define   La			192
#define		Ci			171
#define 	DOI			161
#define 	stop    __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,1000)
#define		start		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,500)




extern uint16_t scale[25] ;
extern uint8_t music[130];
extern int  cishu;


void Music_Clock(void);



#endif