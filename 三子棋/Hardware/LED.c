#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_14 | GPIO_Pin_15);
}

void LED1_ON(void)	//作为下完的信号
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_14);
}

void LED1_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_14) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_14);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_15);
}

void LED2_Turn(void)	//提供背景光
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_15) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_15);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
	}
}
