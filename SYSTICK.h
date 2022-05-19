#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include "tm4c123gh6pm.h"
#define  NVIC_ST_CTRL_R        (*((volatile unsigned long *)0xE000E010))
#define  NVIC_ST_RELOAD_R      (*((volatile unsigned long *)0xE000E014))
#define  NVIC_ST_CURRENT_R     (*((volatile unsigned long *)0xE000E018))
void SysTick_wait(unsigned long delay); // delay more than mile second
void delayMs(int n); // delay in  mile second
void delayUs(int n); // delay in  micro second
#endif

