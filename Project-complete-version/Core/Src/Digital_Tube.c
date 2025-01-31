#include "stm32g4xx.h"                  // Device header
#include "Digital_Tube.h"
#include "Keyboard.h"
#include "Draw_Clock.h"
#include "tim.h"

char Table[17] = {	 DIG_0, DIG_1,DIG_2,DIG_3,DIG_4,DIG_5,DIG_6,
	DIG_7,DIG_8,DIG_9,DIG_A,DIG_B,DIG_C,DIG_D,DIG_E,DIG_F,STR_H
};

int n1 = 7 ;	//显示 正常时间 数码管的位选变量
int n2 = 7; //显示 按键计数 数码管的位选变量 
int n3 = 7; //显示 计时器 数码管的位选变量													
int n4 = 7; //显示 闹钟倒计时 数码管的位选变量

int Mode_1 = 0;
int Mode_2 = 0;
int Mode_3 = 0;
int Mode_0 = 0;		//归零

char DisBuff_0[8] = {0};	//显示时间
char DisBuff_1[8] = {0};	//按键计数
char DisBuff_2[8]	= {0};	//计时器
char DisBuff_3[8]	= {0};	//闹钟倒计时

int Counter = 0; //计数器

int shi_ = 0;
int fen_ = 0;
int miao_ = 0;
int haomiao_ = 0;
int flag = 0;

int minutes = 5;
int second = 10;
int hao_second = 0;

int naozhong = 0;
int flag_music = 0;
int pin_1ms = 0; 


extern volatile char flag10msOk;
extern volatile char flag1msOk;
extern int kk;

//判断模式的函数
void Mode_X(void)
{
								if(	KeyCode_13 == 1 ) //模式0：显示正常的时间
									{
										Mode_0 = 1;
										Mode_1 = 0;
										Mode_2 = 0;
										Mode_3 = 0;
										KeyCode_13 = 0;
									}
		
									if(KeyCode_1 == 1)	//模式1：按键计数模式
									{
										Mode_1 = 1;
										Mode_2 = 0;
										Mode_3 = 0;
										Mode_0 = 0;
										KeyCode_1 = 0;
									}
									
									if(KeyCode_5 == 1)	//模式2：计时模式
									{
										Mode_2 = 1;
										Mode_1 = 0;
										Mode_3 = 0;
										Mode_0 = 0;
										KeyCode_5 = 0;
									}
									
									if(	KeyCode_9 == 1)	//模式3：倒计时闹钟模式
									{
										Mode_3 = 1;
										Mode_1 = 0;
										Mode_2 = 0;
										Mode_0 = 0;
										KeyCode_9 = 0;
									}
}

//显示时间的数码管 Mode_0
void Mode_0_Show_Time(void)
{
									if( Mode_0 == 1	)
									{	
										
										DisBuff_0[0] = miao%10;
										DisBuff_0[1] = miao/10;
										DisBuff_0[2] = fen %10;
										DisBuff_0[3] = fen /10;
										if( shi  == 0)
										{ shi_temp = 12;}
										else
											shi_temp = shi;
										DisBuff_0[4] = shi_temp%10;
										DisBuff_0[5] = shi_temp/10;
										
										if( n1 == 5 | n1 == 3 )
										{
												GPIOB->ODR = Table[ DisBuff_0[7-n1] ] + SEG_DP ;
										}
										else if( n1 == 7 | n1 == 6 |n1 == 4 | n1 == 2)
										{
												GPIOB->ODR = Table[ DisBuff_0[7-n1] ];
										}
										GPIOC->ODR = n1;
										n1--;
						
										if( n1 == 0)
										{
												GPIOC->ODR = 0;
												if(flagshi == 1)
												{		GPIOB->ODR = DIG_A + SEG_DP ;		}
												else
												{		GPIOB->ODR = DIG_P + SEG_DP;		}
												n1 = 7;
										}
									}
}

//计数器的数码管	Mode_1
void Mode_1_Show_Counter(void)
{
										 if(Mode_1 == 1)
										{
											KeyCode_1 = KeyPro_K1();
				
											if( KeyCode_1 == 1 )
											{
												Counter++;
											}
											else if(KeyCode_1 == 2)
											{
												Counter = 0;
											}
											KeyCode_1 = 0;
											
											
											DisBuff_1[0] = Counter%10;
											DisBuff_1[1] = Counter/10%10;
											DisBuff_1[2] = Counter/100;

											GPIOB->ODR = Table[ DisBuff_1[7-n2] ];
											GPIOC->ODR = n2;
											n2--;
										
											if(Counter < 10)
											{
													if( n2 < 7)
													{	 n2 =7; }
											}
											else if(	Counter >= 10 && Counter < 100)
											{
												if( n2 < 6)
												{	n2 = 7; }
											}
											else if(	Counter >= 100 && Counter < 1000)
											{
												if( n2 < 5)
												{	n2 = 7; }
											}
										}
}

//计时器的数码管 Mode_2
void Mode_2_Show_TimerMode(void)
{
										if(Mode_2 == 1)
										{
											KeyCode_5 = KeyPro_K5();
											int static state_s = 0;
											int static state_min = 0;
											int static state_h = 0;
											
											if( KeyCode_5 == 1)
											{
												if(flag == 2 | flag ==0 )
												{	flag = 1;}
												else
												{flag = 0;}
												KeyCode_5  = 0;
											}
											if(KeyCode_5 == 2)
											{
												flag = 2;
												KeyCode_5 = 0;
											}
//											if(flag == 1)
//											{												
//												if(flag10msOk == 1)
//												{
//													flag10msOk = 0;
//													haomiao_++;
//												}
//												if(haomiao_ == 100)
//												{
//													haomiao_ = 0;
//													miao_++;
//												}
//												if(miao_ == 60)
//												{
//													fen_++;
//													miao_ = 0;
//												}
//												if(fen_ == 60)
//												{
//													fen_ = 0 ;
//													shi_++;
//												}
//												if(shi_ == 100)
//												{
//													haomiao_ = miao_ = fen_ = shi_ = 0;
//													flag = 2;
//												}
//												
//											}
											if(flag == 2)
											{
												haomiao_ = miao_ = fen_ = shi_ = 0;
												
											}
												
													DisBuff_2[0] = haomiao_%10;
													DisBuff_2[1] = haomiao_/10;
													DisBuff_2[2] = miao_%10;
													DisBuff_2[3] = miao_/10;
													DisBuff_2[4] = fen_%10;
													DisBuff_2[5] = fen_/10;
													DisBuff_2[6] = shi_%10;
													DisBuff_2[7] = shi_/10;
													
													if( n3 == 1 | n3 == 3 | n3 == 5)
													{
															GPIOB->ODR = Table[ DisBuff_2[7-n3] ] + SEG_DP ;
													}
													else 
													{	
														GPIOB->ODR = Table[ DisBuff_2[7-n3] ];
													}
														GPIOC->ODR = n3;
														n3--;
													if(n3 < 0 )
													{ n3 =7;}
													
													if(shi_==0 && fen_==0 && miao_<10)
													{
														if( n3 < 5)
														{	n3 = 7;}
													}
													else if(shi_==0 && fen_==0 && miao_>9)
													{
														if(n3 < 4)
														{	n3 = 7;}
													}
													else if(shi_==0 && fen_<10)
													{
														if(n3 <3)
														{	n3 = 7;}
													}
													else if(shi_ == 0 && fen_>9)
													{
														if(n3< 2)
														{	n3 = 7;}
													}			
													else if(shi_<10)
													{
														if(n3 < 1)
														{ n3 = 7;}
													}
													else 
													{
														if(n3 < 0)
														{	n3 = 7;}
													}
										
													
						
										} //Mode_2括号
}

//闹钟倒计时的数码管 Mode_3
void Mode_3_Show_AlarmClock(void)
{
									if(Mode_3 == 1)
									{
										KeyCode_9 = KeyPro_K9();
										int static set_miao = 0;
										int static set_fen = 0;
										int static set_v = 0;
										
										int static num = 0;
										if(KeyCode_9 == 2)
										{
											minutes = 5;
											second = 10;
											num = hao_second = kk = 0;
											set_v = set_miao = set_fen = 0;
											naozhong = 0;
											flag_music = 0;
										}
										else if(KeyCode_9 == 1)
										{	
											if(naozhong == 0)
												num++;	
										}
										
										if(num == 0)
										{	set_v = 0;}
										
										if(num == 1)
										{
											set_miao = 1;
											set_fen = set_v = 0;
										}
										if(num == 2)
										{	second = Counter; }
										
										if( num == 3)
										{
											set_fen = 1;
											set_miao = set_v = 0;
										}
										if( num == 4)
										{	minutes = Counter;}
										
										if(num == 5)
										{
											set_fen = set_miao = 0;
											set_v = 1;
										}
										
										if(num == 6)
										{
												num = 0;
												set_v = 0;
												naozhong = 1;
										}
										
//										if(naozhong == 1)
//										{
//												if(flag1msOk == 1)
//												{
//														flag1msOk = 0;
//														pin_1ms++;
//												}
//												
//												if(	pin_1ms == 10)
//												{
//														pin_1ms = 0;
//														hao_second--;
//												}
//												if(hao_second == -1)
//												{
//													hao_second = 99;
//													second--;
//												}
//												
//												if(second == -1)
//												{
//													minutes --;
//													second = 59 ;
//												}
//										}

										if(	second == 0 && minutes == 0 && hao_second == 0 && naozhong == 1)
										{		
											second = 10;
											minutes = 5;
											naozhong = 0;
											set_v  = 0;
											flag_music = 1;
										}	
											
										if(naozhong == 0)
										{
											DisBuff_3[0] = second % 10;
											DisBuff_3[1] = second / 10;
											DisBuff_3[2] = minutes % 10;
											DisBuff_3[3] = minutes / 10;
										
											GPIOC->ODR = n4;
											if(n4 == 5)
											{		GPIOB->ODR = Table[DisBuff_3[7-n4]] + SEG_DP;	}
										  else if( n4 == 7 | n4 == 6 | n4 == 4 )
											{		GPIOB->ODR = Table[DisBuff_3[7-n4]];	}
										  else if( n4 == 0)
											{	
												if(set_miao == 1)
													GPIOB->ODR = DIG_5 + SEG_DP  ;		
												else if(set_fen == 1)
													GPIOB->ODR = DIG_F + SEG_DP ;
												else if(set_v == 1)
													GPIOB->ODR = DIG_C + SEG_DP;
											}
											n4--;
											
											 if(set_fen == 1 | set_miao == 1 | set_v == 1)
											{
											
												if( n4 < 0)
												{	n4 = 7;	} 
												else if( n4 < 4)
												{	n4 = 0;}
												
											}
											
											else if(set_v == 0)
											{
												if(n4 < 4)
												{	n4 = 7;}
											}
										}
										
										else if(naozhong == 1)
										{
											DisBuff_3[0] = hao_second %10;
											DisBuff_3[1] = hao_second / 10;
											DisBuff_3[2] = second % 10;
											DisBuff_3[3] = second / 10;
											DisBuff_3[4] = minutes % 10;
											DisBuff_3[5] = minutes / 10;
										
											GPIOC->ODR = n4;
											if(n4 == 5 | 	n4 == 3)
											{		GPIOB->ODR = Table[DisBuff_3[7-n4]] + SEG_DP;	}
										  else if( n4 == 7 | n4 == 6 | n4 == 4 | n4 == 2)
											{		GPIOB->ODR = Table[DisBuff_3[7-n4]];	}
											n4--;
												if(n4 < 2)
												{	n4 = 7;}
										}
									}//mode3括号
}

void Mode_2_Counter(void)																								//不随模式的改变而打断
{
											if(flag == 1)
											{												
												if(flag10msOk == 1)
												{
													flag10msOk = 0;
													haomiao_++;
												}
												if(haomiao_ == 100)
												{
													haomiao_ = 0;
													miao_++;
												}
												if(miao_ == 60)
												{
													fen_++;
													miao_ = 0;
												}
												if(fen_ == 60)
												{
													fen_ = 0 ;
													shi_++;
												}
												if(shi_ == 100)
												{
													haomiao_ = miao_ = fen_ = shi_ = 0;
													flag = 2;
												}
												
											}
}

void Mode_3_Counter(void)
{
										if(naozhong == 1)
										{
												if(flag1msOk == 1)
												{
														flag1msOk = 0;
														pin_1ms++;
												}
												
												if(	pin_1ms == 10)
												{
														pin_1ms = 0;
														hao_second--;
												}
												if(hao_second == -1)
												{
													hao_second = 99;
													second--;
												}
												
												if(second == -1)
												{
													minutes --;
													second = 59 ;
												}
										}
}
