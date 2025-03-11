#include "stm32f10x.h"                  // Device header
#include "ID.h"
#include "play.h"
#include "find.h"
#include "MatrixKey.h"
#include "Delay.h"
#include "OLED.h"
#include "dong.h"
#include "openmv.h"
#include "LED.h"
#include <math.h>
int angle = 0;

void scratch(int num){	//取棋子（棋盘外）
	ID_1(num,1);	//机械臂测斜到达棋子位置
	Delay_ms(800);	//等待到达位置
	ID_1(num,0);	//机械臂回归水平位置
	Delay_s(1);	
    //执行吸棋子的代码
	qibeng_xi();
    Delay_ms(500);
	ID_1(num,1);	//机械臂再次测斜
	qibeng_ting();
}
void scratch_2(int num){	//取棋子（棋盘内）
	ID_2(num,1,angle);	//机械臂测斜到达棋子位置
	Delay_ms(800);	//等待到达位置
	ID_2(num,0,angle);	//机械臂回归水平位置
	Delay_s(1);	
    //执行吸棋子的代码
	qibeng_xi();
    Delay_ms(500);
	ID_2(num,1,angle);	//机械臂再次测斜
	qibeng_ting();
}
void put(int num){	//放置在棋盘里面
	ID_2(num,1,angle);
	Delay_ms(500);
	ID_2(num,1,angle);
    //执行放棋子的代码
	Delay_ms(800);
	ID_2(num,0,angle);
	Delay_s(1);
	qibeng_fang();		//放置棋子
	Delay_ms(500);
	ID_2(num,1,angle);	//机械臂抬起
	Delay_ms(500);
}

void no_1_1(){        //传入棋子的序号以及棋盘坐标
	angle=0;
	int n1=0,n2=0;
//	n1 = check_pass();
    scratch(5);
	
	//回到标准位置
	guiwei();
	Delay_ms(500);
	
//	n2=check_pass();
    put(5);
	
	//回到标准位置
	guiwei();
	Delay_ms(500);
}

void no_1(){        //传入棋子的序号以及棋盘坐标
	int n1=0,n2=0;
	OLED_ShowString(3,5,"chess");
	n1 = check_pass();
    scratch(n1);
	
	//回到标准位置
	guiwei();
	Delay_ms(500);
	
	OLED_ShowString(3,5,"bord");
	n2=check_pass();
    put(n2);
	
	//回到标准位置
	guiwei();
	Delay_ms(500);
	OLED_ShowString(4,5,"finish");
	Delay_ms(500);
	OLED_Clear();
}
void no_2(){
    for(int i=1;i<=4;i++) {
		OLED_ShowString(1,1,"Num:");
		OLED_ShowNum(1,5,i,1);
		no_1();
	}   
}
void no_3(){
	OLED_ShowString(1,1,"Angle:");
	OLED_ShowNum(1,7,angle,2);
	angle=findClosestValue(check_pass());
	Delay_ms(500);
	OLED_Clear();
	//使用对应角度的系统
	no_2();
	OLED_Clear();
}
void no_4(){
	OLED_ShowString(1,1,"YOU TURN");
	no_1();
	int key=1;	//按键通知装置，启动计时
	while(key){
		OLED_ShowString(1,1,"CHECK");
		key = check_pass();
		if(key == 3){		//有效数值为3的时候退出循环
			if(must_lose_step()){	//表示对方已经输了
				OLED_ShowString(4,1,"I WIN!");
				Delay_ms(500);
			}
			else{
				OLED_ShowString(4,1,"YOU LOSE!");
				Delay_ms(500);
			}
			//执行亮灯
			LED1_ON();
			Delay_ms(500);
			LED1_OFF();
			break;
		}
		else key = 1;
	}
	OLED_Clear();
}
void no_5(){
	angle=0;
	if(full() == 0){		//棋盘下满结束
		OLED_ShowString(4,1,"Full !");
		Delay_s(1);
	}
	else{
		for(int i=10;i>=6;i--){
			Delay_s(4);		//等待对方下棋
			
			scratch(i);
			//执行吸棋子的代码
			Delay_s(1);
			
			put(play());
			//执行放棋子的代码
			Delay_s(1);
			//亮灯
			LED1_ON();
			Delay_ms(500);
			LED1_OFF();
			
			if(i == 6){
				OLED_ShowString(4,1,"PEACE!");
				Delay_s(1);
			}
			else {
				OLED_ShowString(4,1,"YOU WIN!");
				Delay_s(1);
			}
		}
	}
	OLED_Clear();
}
void no_6(){
	chessboard_init();
	if(check_weigui()){		//存在违规现象
		//在棋盘里面执行吸棋
		//执行吸棋子的代码
		scratch_2(now());
		
		//回到标准位置
		guiwei();
		Delay_ms(500);
		
		//在棋盘里面执行放棋
		//执行放棋子的代码
		put(last());
	}
	else{
		OLED_ShowString(4,1,"No Violations");	//表示不存在违规现象
		Delay_s(1);
	}
}