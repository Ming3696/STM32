#include "stm32g4xx.h"                  // Device header
#include "Keyboard.h"

int KeyCode_1;	
int KeyCode_5;
int KeyCode_9;
int KeyCode_13;

//����״̬ת����
int KeyPro_K1(void)								//K1��λ��״̬ת����
{
	static int State = 0;
	static int TimeCounter = 0;
	int result = 0;
	switch(State)
	{
		case 0:			
			if( (GPIOA->IDR & (1<<K1)) == 0 )	
			{		State = 1;	}
			else
			{								}				
			break;
		case 1:
			if( (GPIOA->IDR & (1<<K1)) == 0 )	
			{		
				State = 2;	
				result = 1; 
			}
			else																
			{		State = 0;	}
			break;
		case 2:			
			if( (GPIOA->IDR & (1<<K1)) == 0 )  
			{	
//				time1 = HAL_GetTick();
//				time2 = time1 - time2;
//				time2 = HAL_GetTick();
				TimeCounter++;
				if( TimeCounter >= 1000)
				{	
						TimeCounter = 0;
				
						State = 3;
						result = 2;
					}
			}
			else												
			{	
				TimeCounter = 0;
				State = 0;		
			}
			break;
		case 3:	
			if( ( GPIOA->IDR & (1<<K1)) == 0 )	
			{		 
					 result = 2 ; 		
			}
			else																	
			{	
				State = 0;
			}
			break;	
	}
	return result;
}

int KeyPro_K5(void)								//K5��λ��״̬ת����
{
	static int State = 0;
	static int TimeCounter = 0;
	int result = 0;
	switch(State)
	{
		case 0:			
			if( (GPIOA->IDR & (1<<K5)) == 0 )	
			{		State = 1;	}
			else
			{								}				
			break;
		case 1:
			if( (GPIOA->IDR & (1<<K5)) == 0 )	
			{		
				State = 2;	
				result = 1; 
			}
			else																
			{		State = 0;	}
			break;
		case 2:			
			if( (GPIOA->IDR & (1<<K5)) == 0 )  
			{	
//				time1 = HAL_GetTick();
//				time2 = time1 - time2;
//				time2 = HAL_GetTick();
				TimeCounter++;
				if( TimeCounter >= 1000)
				{	
						TimeCounter = 0;
				
						State = 3;
						result = 2;
					}
			}
			else												
			{	
				TimeCounter = 0;
				State = 0;		
			}
			break;
		case 3:	
			if( ( GPIOA->IDR & (1<<K5)) == 0 )	
			{		 
					 result = 2 ; 		
			}
			else																	
			{	
				State = 0;
			}
			break;	
	}
	return result;
}

int KeyPro_K9(void)								//K9��λ��״̬ת����
{
	static int State = 0;
	static int TimeCounter = 0;
	int result = 0;
	switch(State)
	{
		case 0:			
			if( (GPIOA->IDR & (1<<K9)) == 0 )	
			{		State = 1;	}
			else
			{								}				
			break;
		case 1:
			if( (GPIOA->IDR & (1<<K9)) == 0 )	
			{		
				State = 2;	
				result = 1; 
			}
			else																
			{		State = 0;	}
			break;
		case 2:			
			if( (GPIOA->IDR & (1<<K9)) == 0 )  
			{	
//				time1 = HAL_GetTick();
//				time2 = time1 - time2;
//				time2 = HAL_GetTick();
				TimeCounter++;
				if( TimeCounter >= 1000)
				{	
						TimeCounter = 0;
				
						State = 3;
						result = 2;
					}
			}
			else												
			{	
				TimeCounter = 0;
				State = 0;		
			}
			break;
		case 3:	
			if( ( GPIOA->IDR & (1<<K9)) == 0 )	
			{		 
					 result = 2 ; 		
			}
			else																	
			{	
				State = 0;
			}
			break;	
	}
	return result;
}

int KeyPro_K13(void)							//K13��λ��״̬ת����
{
	static int State = 0;
	static int TimeCounter = 0;
	int result = 0;
	switch(State)
	{
		case 0:			
			if( (GPIOA->IDR & (1<<K13)) == 0 )	
			{		State = 1;	}
			else
			{								}				
			break;
		case 1:
			if( (GPIOA->IDR & (1<<K13)) == 0 )	
			{		
				State = 2;	
				result = 1; 
			}
			else																
			{		State = 0;	}
			break;
		case 2:			
			if( (GPIOA->IDR & (1<<K13)) == 0 )  
			{	
//				time1 = HAL_GetTick();
//				time2 = time1 - time2;
//				time2 = HAL_GetTick();
				TimeCounter++;
				if( TimeCounter >= 1000)
				{	
						TimeCounter = 0;
				
						State = 3;
						result = 2;
					}
			}
			else												
			{	
				TimeCounter = 0;
				State = 0;		
			}
			break;
		case 3:	
			if( ( GPIOA->IDR & (1<<K13)) == 0 )	
			{		 
					 result = 2 ; 		
			}
			else																	
			{	
				State = 0;
			}
			break;	
	}
	return result;
}
