#ifndef __FIND_H
#define __FIND_H

extern int16_t data[10];	//保存棋盘数据


static int num_last=0;
static int num_now=0;
void chessboard_init();//初始化
int must_lose_step(); //为1表示必输
int check_weigui();
int now();
int last();

#endif
