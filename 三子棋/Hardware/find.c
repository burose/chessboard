#include "stm32f10x.h"                  // Device header

extern int16_t data[10];	//保存棋盘数据
int16_t last_data[10];	//保存上次棋盘数据

static int num_last=0;
static int num_now=0;

int must_lose_step(){
	int change = 0,key_1=0,key_2=0;
	for(int i=1;i<=9;i++){
		if(data[i] != 0){
			change+=1;
			if(i == 1 ||i == 3 ||i == 5 ||i == 7 || i == 9) key_1+=1;
			if(i == 2 ||i == 4 ||i == 6 ||i == 8) key_2+=1;
		}
	}
	if(change == 2){
		if( key_1 == 1 && key_2 == 1) return 1;
	}
	return 0;
}

void chessboard_init(){	//初始化复制
	for(int i=1;i<=9;i++){
		last_data[i]= data[i];
	}
}
int check_weigui(){
	int change=0; //表示变化的棋子的数目
	int sum_now=0,sum_last=0;
	for(int i=1;i<=9;i++){
		sum_last+=last_data[i];
		sum_now+=data[i];
	}
	if(sum_last == sum_now){	//棋盘数值总和未发生变化
		for(int i=1;i<=9;i++){
			if(last_data[i] != data[i]){
				change+=1; 
				if(last_data[i] != 0) num_last=i; //之前违规棋子所在的位置
				if(data[i] != 0) num_now=i;	//当前违规棋子所在的位置
				//结果应该是将当期数据内对应的棋子放到上一次发生变化的棋盘内
			}
		}
		if(change == 1){
			return 0;	//只有一个棋子发生变化，表示正常下棋
		}
		else return 1;	//多个棋子发生变化，表示有棋子违规移动
	
	}
	else{		//棋盘数值总和发生变化（必然发生违规移动）
		for(int i=1;i<=9;i++){
			if(last_data[i] != data[i]){
				change+=1; 
				if(last_data[i] != 0 && data[i] != 0) num_now=i; //当前违规棋子所在的位置
				else num_last=i;	//之前违规棋子所在的位置
				//结果应该是将当期数据内对应的棋子放到上一次发生变化的棋盘内
			}
		}

		return 1;	//多个棋子发生变化，表示有棋子违规移动
	}
	
}

int now()	{return num_now;}	//返回当前违规棋子所在的位置
int last() 	{return num_last;}	//返回之前违规棋子所在的位置

