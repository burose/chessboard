#include "stm32f10x.h"                  // Device header


//��ִ����(1)���У�װ������ȷ���ð�����(-1)�Ա��ֲ����塣

extern int16_t data[10];	//������������
extern int pass;	//������Ҫ�µ�λ��

int full(){		//����0��ʾ��ǰ�����Ѿ�����
	int num = 0;
	int flag = 0;
	for(int i=1;i<10;i++){
		if(data[i] == 0){	//�п�λ��
			flag = 1;
			num+=1;
		}
	}
	if(flag == 1) return num;
	else return 0;
}
int check_lose(){	//����1��ʾ�Է�����ȡʤ��pass��ʾ���Դ�ȡ��λ�����
	int temp=0;
	for(int i=1;i<9;i++){ 	//���У����У�������
		if(i == 1){
			temp=data[1]+data[2]+data[3];
			if(temp == 2){
				if(data[1] == 0) pass=1;
				if(data[2] == 0) pass=2;
				if(data[3] == 0) pass=3;
				return 1;	//��ʾ���弴��ȡʤ����ʱ��Ҫ�����������µ�ֵΪ0��λ��
			}
		}
		if(i == 2){
			temp=data[4]+data[5]+data[6];
			if(temp == 2){
				if(data[4] == 0) pass=4;
				if(data[5] == 0) pass=5;
				if(data[6] == 0) pass=6;
				return 1;
			}
		}
		if(i == 3){
			temp=data[7]+data[8]+data[9];
			if(temp == 2){
				if(data[7] == 0) pass=7;
				if(data[8] == 0) pass=8;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}
		
		if(i == 4){
			temp=data[1]+data[4]+data[7];
			if(temp == 2){
				if(data[1] == 0) pass=1;
				if(data[4] == 0) pass=4;
				if(data[7] == 0) pass=7;
				return 1;
			}
		}
		if(i == 5){
			temp=data[2]+data[5]+data[8];
			if(temp == 2){
				if(data[2] == 0) pass=2;
				if(data[5] == 0) pass=5;
				if(data[8] == 0) pass=8;
				return 1;
			}
		}
		if(i == 6){
			temp=data[3]+data[6]+data[9];
			if(temp == 2){
				if(data[3] == 0) pass=3;
				if(data[6] == 0) pass=6;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}

		if(i == 7){
			temp=data[1]+data[5]+data[9];
			if(temp == 2){
				if(data[1] == 0) pass=1;
				if(data[5] == 0) pass=5;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}
		if(i == 8){
			temp=data[3]+data[5]+data[7];
			if(temp == 2){
				if(data[3] == 0) pass=3;
				if(data[5] == 0) pass=5;
				if(data[7] == 0) pass=7;
				return 1;
			}
		}
	}
	return 0;
}
int check_win(){	//����1��ʾ�Է�����ȡʤ��pass��ʾ���Դ�ȡ��λ�����
	int temp=0;
	for(int i=1;i<9;i++){ 	//���У����У�������
		if(i == 1){
			temp=data[1]+data[2]+data[3];
			if(temp == -2){
				if(data[1] == 0) pass=1;
				if(data[2] == 0) pass=2;
				if(data[3] == 0) pass=3;
				return 1;	//��ʾ���弴��ȡʤ����ʱ��Ҫ�����������µ�ֵΪ0��λ��
			}
		}
		if(i == 2){
			temp=data[4]+data[5]+data[6];
			if(temp == -2){
				if(data[4] == 0) pass=4;
				if(data[5] == 0) pass=5;
				if(data[6] == 0) pass=6;
				return 1;
			}
		}
		if(i == 3){
			temp=data[7]+data[8]+data[9];
			if(temp == -2){
				if(data[7] == 0) pass=7;
				if(data[8] == 0) pass=8;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}
		
		if(i == 4){
			temp=data[1]+data[4]+data[7];
			if(temp == -2){
				if(data[1] == 0) pass=1;
				if(data[4] == 0) pass=4;
				if(data[7] == 0) pass=7;
				return 1;
			}
		}
		if(i == 5){
			temp=data[2]+data[5]+data[8];
			if(temp == -2){
				if(data[2] == 0) pass=2;
				if(data[5] == 0) pass=5;
				if(data[8] == 0) pass=8;
				return 1;
			}
		}
		if(i == 6){
			temp=data[3]+data[6]+data[9];
			if(temp == -2){
				if(data[3] == 0) pass=3;
				if(data[6] == 0) pass=6;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}

		if(i == 7){
			temp=data[1]+data[5]+data[9];
			if(temp == -2){
				if(data[1] == 0) pass=1;
				if(data[5] == 0) pass=5;
				if(data[9] == 0) pass=9;
				return 1;
			}
		}
		if(i == 8){
			temp=data[3]+data[5]+data[7];
			if(temp == -2){
				if(data[3] == 0) pass=3;
				if(data[5] == 0) pass=5;
				if(data[7] == 0) pass=7;
				return 1;
			}
		}
	}
	return 0;
}
int play(){
	int sum=0,temp=0;
	if(full() == 0){	//��ʾ�Ѿ�������
		return 0;
	}
	else if(full() == 8){	//�������ֻ����һ������ʱ�������ڱ���(8����λ��)
		if(data[1] != 0){
			pass = 5;
		}
		else if(data[3] != 0){
			pass = 5;
		}
		else if(data[5] != 0){
			pass = 3;
		}
		else if(data[7] != 0){
			pass = 5;
		}
		else if(data[9] != 0){
			pass = 5;
		}
		return 0;
	}
	if(check_lose()){
		return pass;
	}
	else if(check_win()){
		return pass;
	}
	else{
		for(int i=0;i<8;i++){
		if(i == 0){
			if(data[1] == 0 || data[2]== 0 || data[3]==0){	//����һ����λ
				temp=data[1]+data[2]+data[3];
				if(temp<=sum){	//��ʾ��������û�취Ӯ�����ҵ�ǰ���е�ֵ����
					sum=temp;
					if(data[1] == 0) pass=1;	//�ҵ���ǰ���е�Ϊ���λ������
					else if(data[2] == 0) pass=2;
					else if(data[3] == 0) pass=3;
				}
			}
		}
		if(i == 1){
			if(data[4] != 0 || data[5] != 0 ||data[6] != 0){
				temp=data[4]+data[5]+data[6];
				if(temp<=sum){
					sum=temp;
					if(data[4] == 0) pass=4;
					else if(data[5] == 0) pass=5;
					else if(data[6] == 0) pass=6;
				}
			}
		}
		if(i == 2){
			if(data[7] != 0 || data[8] != 0 ||data[9] != 0){
				temp=data[7]+data[8]+data[9];
				if(temp<=sum){
					sum=temp;
					if(data[7] == 0) pass=7;
					else if(data[8] == 0) pass=8;
					else if(data[9] == 0) pass=9;
				}
			}
		}
		if(i == 3){
			if(data[1] != 0 || data[4] != 0 ||data[7] != 0){
				temp=data[1]+data[4]+data[7];
				if(temp<=sum){
					sum=temp;
					if(data[1] == 0) pass=1;
					else if(data[4] == 0) pass=4;
					else if(data[7] == 0) pass=7;
				}
			}
		}
		if(i == 4){
			if(data[2] != 0 || data[5] != 0 ||data[8] != 0){
				temp=data[2]+data[5]+data[8];
				if(temp<=sum){
					sum=temp;
					if(data[2] == 0) pass=2;
					else if(data[5] == 0) pass=5;
					else if(data[8] == 0) pass=8;
				}
			}
		}
		if(i == 5){
			if(data[3] != 0 || data[6] != 0 ||data[9] != 0){
				temp=data[3]+data[6]+data[9];
				if(temp<=sum){
					sum=temp;
					if(data[3] == 0) pass=3;
					else if(data[6] == 0) pass=6;
					else if(data[9] == 0) pass=9;
				}
			}
		}
		if(i == 6){
			if(data[1] != 0 || data[5] != 0 ||data[9] != 0){
				temp=data[1]+data[5]+data[9];
				if(temp<=sum){
					sum=temp;
					if(data[1] == 0) pass=1;
					else if(data[5] == 0) pass=5;
					else if(data[9] == 0) pass=9;
				}
			}
			
		}
		if(i == 7){
			if(data[1] != 0 || data[5] != 0 ||data[9] != 0){
				temp=data[3]+data[5]+data[7];
				if(temp<=sum){
					sum=temp;
					if(data[3] == 0) pass=3;
					else if(data[5] == 0) pass=5;
					else if(data[7] == 0) pass=7;
				}
			}
		}
		}
	}
	return pass;
}