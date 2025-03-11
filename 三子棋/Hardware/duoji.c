#include "stm32f10x.h"                  // Device header
#include "Servo.h"

//设置角度
void duoji_1(float angle)
{
	Servo_SetAngle1(angle);	
   
}
void duoji_2(float angle)
{
	Servo_SetAngle2(angle);	
 
}
void duoji_3(float angle)
{
	//设置舵机的角度为角度变量
	Servo_SetAngle3(angle);
}
