#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM3_Init();
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetCompare2(uint16_t Compare);
void PWM_SetCompare3(uint16_t Compare);
void PWM_SetCompare4(uint16_t Compare);
void PWM_SetCompare_mondile(uint16_t Compare);

#endif

