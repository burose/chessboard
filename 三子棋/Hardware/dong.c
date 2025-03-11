#include "stm32f10x.h" 
#include "Servo.h"
#include "duoji.h"
#include "Delay.h"
#include "PWM.h"
void dong(int x,int y,int z)
{
	duoji_1(x);
	Delay_ms(600);
	if(y == 1){
		PWM_SetCompare_mondile(600);
	}
	else PWM_SetCompare_mondile(450);
	duoji_3(z);
    Delay_ms(600);
}

void d()
{
	dong(50,1,48);
	Delay_ms(600);
}     

void qibeng_xi()
{
	PWM_SetCompare1(2500);	//A0表示气泵
	PWM_SetCompare3(0);	//A2表示电磁阀
}

void qibeng_ting(){
	PWM_SetCompare1(0);	//A0表示气泵
	PWM_SetCompare3(0);	//A2表示电磁阀
}
void qibeng_fang()
{
	PWM_SetCompare1(0);	//A0表示气泵
	PWM_SetCompare3(2000);	//A2表示电磁阀
}