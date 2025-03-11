#include "stm32f10x.h"      // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Serial.h"
#include "play.h"
#include "find.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "Serial.h"
#include <stdio.h>
#include <stdint.h>
#include "dong.h"
#include "duoji.h"
#include "ID.h"
#include "PWM.h"
#include "Servo.h"
#include "MatrixKey.h"
#include "topic.h"
#include "openmv.h"
#include "LED.h"
uint8_t RxData;			//定义用于接收串口数据的变量
int openmv[12];			//stm32接收数据数组

int16_t data[10];	//保存棋盘数据
int pass=0;	


int main(void)
{
    /* 模块初始化 */
    OLED_Init();    // OLED 初始化
    PWM_Init();
	MatrixKey_Init();	//按键初始化
	uart_init(115200);	//串口初始化
	LED_Init();
	
	int choice=0;
    while (1)
    {
		choice=check_pass();
		if(choice == 1)	no_1();		//题目一
		else if(choice == 2)	no_2();	//题目二
		else if(choice == 3)	no_3();	//题目三
		else if(choice == 4)	no_4();	//题目四
		else if(choice == 5)	no_5();	//题目五
		else if(choice == 6)	no_6();	//题目六
		else if(choice == 7){
			show();	//显示棋盘信息
			Delay_s(2);
		}
		else{
			OLED_ShowString(2,1,"wrong!");
		}	
    }
}