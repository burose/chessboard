#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
uint8_t MatrixKey_determine();

void MatrixKey_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_12 | GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t MatrixKey_GetValue()
{
	uint8_t Key;
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	GPIO_SetBits(GPIOA, GPIO_Pin_7);

	Key =  MatrixKey_determine();
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_5); 
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
	
	if(MatrixKey_determine())
	{
		
		Key = MatrixKey_determine() + 4;
		Delay_ms(10);
	}
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_SetBits(GPIOA, GPIO_Pin_7);
	

	if(MatrixKey_determine())
	{
		
		Key = MatrixKey_determine() + 8;
		Delay_ms(30);
	}
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
	
	
	if(MatrixKey_determine())
	{
		
		Key = MatrixKey_determine() + 12;
		Delay_ms(100);
	}
	
	return Key;
}

uint8_t MatrixKey_determine()
{
	uint8_t Key = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
	{
		Delay_ms(150);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){Key = 4;}
	}
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		Delay_ms(200);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0){Key = 3;}

	}
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0)
	{
		Delay_ms(200);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 0){Key = 2;}
	}
	
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 0)
	{
		Delay_ms(200);
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13) == 0){Key = 1;}
	}
	return Key;
}

int check_pass(){    //判断已经按下对应的按键,最终返回值为确认按键（4）前的值
    int num=0,num_last=0;
    while(1){
        num=MatrixKey_GetValue();
        if(num != 4)    
		{
			num_last+=num;
			OLED_ShowString(2,1,"chioce:");
			OLED_ShowNum(2,8,num_last,2);
		}
        else{
			OLED_ShowString(2,12,"ok");
			Delay_ms(500);
			OLED_Clear();
			break;
		}
    }
    return num_last;
}