#ifndef		__KEYBOARD_H__
#define		__KEYBOARD_H__

#define K1 	8
#define K5 	9
#define K9 	10
#define K13 11

extern int KeyCode_1;	
extern int KeyCode_5;
extern int KeyCode_9;
extern int KeyCode_13;


//4个键位的状态转换机
int KeyPro_K1(void);
int KeyPro_K5(void);
int KeyPro_K9(void);
int KeyPro_K13(void);




#endif