#include "stm32f10x.h"                  // Device header
#include "Servo.h"

//���ýǶ�
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
	//���ö���ĽǶ�Ϊ�Ƕȱ���
	Servo_SetAngle3(angle);
}
