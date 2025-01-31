#ifndef		__DIGTAL_TUBE_H__
#define 	__DIGTAL_TUBE_H__


#define SEG_A 	 ( 1<<0 )
#define SEG_B 	 ( 1<<1 )
#define SEG_C 	 ( 1<<2 )
#define SEG_D 	 ( 1<<3 )
#define SEG_E 	 ( 1<<4 )
#define SEG_F 	 ( 1<<5 )
#define SEG_G 	 ( 1<<6 )
#define SEG_DP 	 ( 1<<7 )
#define DIG_0 	 ( SEG_A + SEG_B + SEG_C +SEG_D + SEG_E + SEG_F)
#define DIG_1		 ( SEG_B + SEG_C )	
#define DIG_2		 ( SEG_A + SEG_B + SEG_D + SEG_E + SEG_G)
#define DIG_3		 ( SEG_A + SEG_B + SEG_G + SEG_C + SEG_D	)
#define DIG_4		 ( SEG_B + SEG_C + SEG_F + SEG_G	)
#define DIG_5		 ( SEG_A + SEG_F + SEG_G + SEG_C + SEG_D )
#define DIG_6		 ( SEG_A + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G	)
#define DIG_7		 ( SEG_A + SEG_B + SEG_C	)
#define DIG_8		 ( SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G	)
#define DIG_9    ( SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G)
#define DIG_A    ( SEG_A+SEG_B+SEG_C+SEG_E+SEG_F+SEG_G )
#define DIG_B		 ( SEG_C+SEG_D+SEG_E+SEG_F+SEG_G )
#define DIG_C	   ( SEG_A + SEG_D + SEG_E + SEG_F )
#define DIG_D		 ( SEG_B+SEG_C+SEG_D+SEG_E+SEG_G )
#define DIG_E		 ( SEG_A+SEG_D+SEG_E+SEG_F+SEG_G )
#define DIG_F    ( SEG_A + SEG_E + SEG_F + SEG_G )

#define STR_H		 ( SEG_C + SEG_E + SEG_F + SEG_G )
#define DIG_P			( SEG_A + SEG_F + SEG_B + SEG_E + SEG_G)

extern char Table[17];
extern int flag_music;


void Mode_X(void);//判断模式
void Mode_0_Show_Time(void);//显示时间的数码管 Mode_0
void Mode_1_Show_Counter(void);//计数器的数码管	Mode_1
void Mode_2_Show_TimerMode(void);//计时器的数码管 Mode_2
void Mode_3_Show_AlarmClock(void);//闹钟倒计时的数码管 Mode_3



void Mode_2_Counter(void)	;																						//不随模式的改变而打断计时
void Mode_3_Counter(void);
#endif