#ifndef __OPENMV_H
#define __OPENMV_H
#include "stm32f10x.h" 
extern int openmv[12];//stm32接收数据数组
extern int16_t data[10];
 
void Openmv_Receive_Data(int16_t data);
void Openmv_Data(void);
void show();

#endif