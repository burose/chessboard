#include "stm32f10x.h"                  // Device header

extern int16_t data[10];	//������������
int16_t last_data[10];	//�����ϴ���������

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

void chessboard_init(){	//��ʼ������
	for(int i=1;i<=9;i++){
		last_data[i]= data[i];
	}
}
int check_weigui(){
	int change=0; //��ʾ�仯�����ӵ���Ŀ
	int sum_now=0,sum_last=0;
	for(int i=1;i<=9;i++){
		sum_last+=last_data[i];
		sum_now+=data[i];
	}
	if(sum_last == sum_now){	//������ֵ�ܺ�δ�����仯
		for(int i=1;i<=9;i++){
			if(last_data[i] != data[i]){
				change+=1; 
				if(last_data[i] != 0) num_last=i; //֮ǰΥ���������ڵ�λ��
				if(data[i] != 0) num_now=i;	//��ǰΥ���������ڵ�λ��
				//���Ӧ���ǽ����������ڶ�Ӧ�����ӷŵ���һ�η����仯��������
			}
		}
		if(change == 1){
			return 0;	//ֻ��һ�����ӷ����仯����ʾ��������
		}
		else return 1;	//������ӷ����仯����ʾ������Υ���ƶ�
	
	}
	else{		//������ֵ�ܺͷ����仯����Ȼ����Υ���ƶ���
		for(int i=1;i<=9;i++){
			if(last_data[i] != data[i]){
				change+=1; 
				if(last_data[i] != 0 && data[i] != 0) num_now=i; //��ǰΥ���������ڵ�λ��
				else num_last=i;	//֮ǰΥ���������ڵ�λ��
				//���Ӧ���ǽ����������ڶ�Ӧ�����ӷŵ���һ�η����仯��������
			}
		}

		return 1;	//������ӷ����仯����ʾ������Υ���ƶ�
	}
	
}

int now()	{return num_now;}	//���ص�ǰΥ���������ڵ�λ��
int last() 	{return num_last;}	//����֮ǰΥ���������ڵ�λ��

