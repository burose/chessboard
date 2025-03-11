#ifndef __PLAY_H
#define __PLAY_H

extern int16_t data[10];	//保存棋盘数据
extern int pass;	//机器将要下的位置

int check_lose();
int check_win();
int full();
int play(); //返回将要下的位置序号，为零表示和棋

#endif
