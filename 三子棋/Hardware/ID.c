#include "stm32f10x.h"  
#include "dong.h"
#include "Delay.h"
#include <math.h>
//9个格子的位置
int chess_x[11]={0,12,20,27,31,36,0,6,13,20,28};
int chess_y[11]={0,102,89,77,65,53,48,43,35,26,13};

int board_0_x[10]={0,21,18,17,13,9,8,3,0,0};
int board_0_y[10]={0,63,55,46,75,68,58,86,78,66};

int board_15_x[10]={0,25,21,19,17,13,12,9,5,2};
int board_15_y[10]={0,50,46,38,65,60,50,78,72,64};
int board_30_x[10]={0,25,20,16,20,13,8,14,5,0};
int board_30_y[10]={0,47,47,42,61,60,58,76,75,72};
int board_45_x[10]={0,26,20,15,21,14,9,16,8,1};
int board_45_y[10]={0,45,46,44,65,60,58,75,76,72};

int board_f15_x[10]={0,9,17,25,5,13,21,2,12,19};
int board_f15_y[10]={0,78,65,50,72,60,46,64,50,38};
int board_f30_x[10]={0,14,20,25,5,13,20,0,8,16};
int board_f30_y[10]={0,76,61,47,75,60,47,72,58,42};
int board_f45_x[10]={0,16,21,26,8,14,20,1,9,15};
int board_f45_y[10]={0,75,65,45,76,60,46,72,58,44};

void ID_1(int x,int y)	//对应棋子位置
{
	dong(chess_x[x],y,chess_y[x]);	//机械臂弯曲到达棋子位置
}

int findClosestValue(double value) {
    // 目标值数组
    int targets[7] = {-45, -30, -15, 0, 15, 30, 45};
    int closest = targets[0];
    int minDifference = fabs(value - targets[0]);

    // 遍历目标值，找到最接近的
    for (int i = 0; i < 7; i++) {
        double difference = fabs(value - targets[i]);
        if (difference < minDifference) {
            minDifference = difference;
            closest = targets[i];
        }
    }
    return closest;
}

void ID_2(int x,int z,int y)	//对应棋盘位置
{
	y=findClosestValue(y);
	if(y == 0){
		dong(board_0_x[x],z,board_0_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == 15){
		dong(board_15_x[x],z,board_15_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == 30){
		dong(board_30_x[x],z,board_30_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == 45){
		dong(board_45_x[x],z,board_45_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == -15){
		dong(board_f15_x[x],z,board_f15_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == -30){
		dong(board_f30_x[x],z,board_f30_y[x]);	//机械臂弯曲到达棋子位置
	}
	else if(y == -45){
		dong(board_f45_x[x],z,board_f45_y[x]);	//机械臂弯曲到达棋子位置
	}
}

void guiwei(){
	dong(chess_x[6],1,chess_y[6]);
}	

