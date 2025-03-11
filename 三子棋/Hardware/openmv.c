#include "openmv.h"
#include "Serial.h"
#include "OLED.h"
extern int openmv[12];//stm32接收数据数组

extern int16_t data[10];

int i=0;
 
void Openmv_Receive_Data(int16_t data)//接收Openmv传过来的数据
{
	static u8 state = 0;
	if(state==0&&data==0x2C)
	{
		state=1;
		openmv[0]=data;
	}
	else if(state==1&&data==0x12)
	{
		state=2;
		openmv[1]=data;
	}
	else if(state==2)
	{
		state=3;
		openmv[2]=data;
	}
	else if(state==3)
	{
		state = 4;
		openmv[3]=data;
	}
	else if(state==4)
	{
        state = 5;
        openmv[4]=data;
	}
	else if(state==5)
	{
        state = 6;
        openmv[5]=data;
	}
	else if(state==6)
	{
        state = 7;
        openmv[6]=data;
	}
	else if(state==7)
	{
        state = 8;
        openmv[7]=data;
	}
	else if(state==8)
	{
        state = 9;
        openmv[8]=data;
	}
	else if(state==9)
	{
        state = 10;
        openmv[9]=data;
	}
	else if(state==10)
	{
        state = 11;
        openmv[10]=data;
	}
	else if(state==11)		//检测是否接受到结束标志
	{
        if(data == 0x5B)
        {
            state = 0;
            openmv[11]=data;
            Openmv_Data();
        }
        else if(data != 0x5B)	//接收验证信息错误
        {
            state = 0;
            for(i=0;i<12;i++)
            {
                openmv[i]=0x00;
            }           
        }
	}    
	else	//接收信息不足
		{
			state = 0;
            for(i=0;i<12;i++)
            {
                openmv[i]=0x00;
            }
		}
}
 
void Openmv_Data(void)	//接收到的有效数据
{
    data[1]=openmv[2]-1;
    data[2]=openmv[3]-1;
    data[3]=openmv[4]-1;
    data[4]=openmv[5]-1;
	data[5]=openmv[6]-1;
    data[6]=openmv[7]-1;
    data[7]=openmv[8]-1;
    data[8]=openmv[9]-1;
	data[9]=openmv[10]-1;
}
void show(){
	OLED_ShowNum(1,1,data[1]+1,2);
	OLED_ShowNum(1,4,data[2]+1,2);
	OLED_ShowNum(1,7,data[3]+1,2);
	OLED_ShowNum(2,1,data[4]+1,2);
	OLED_ShowNum(2,4,data[5]+1,2);
	OLED_ShowNum(2,7,data[6]+1,2);
	OLED_ShowNum(3,1,data[7]+1,2);
	OLED_ShowNum(3,4,data[8]+1,2);
	OLED_ShowNum(3,7,data[9]+1,2);
}