#ifndef __FIND_H
#define __FIND_H

extern int16_t data[10];	//������������


static int num_last=0;
static int num_now=0;
void chessboard_init();//��ʼ��
int must_lose_step(); //Ϊ1��ʾ����
int check_weigui();
int now();
int last();

#endif
