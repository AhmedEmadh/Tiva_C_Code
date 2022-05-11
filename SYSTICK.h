#include "D:\UV4\tm4c123gh6pm.h"
#define  NVIC_ST_CTRL_R        (*((volatile unsigned long *)0xE000E010))
#define  NVIC_ST_RELOAD_R      (*((volatile unsigned long *)0xE000E014))
#define  NVIC_ST_CURRENT_R     (*((volatile unsigned long *)0xE000E018))
void SysTick_wait(unsigned long delay);
void delayMs(int n);
void delayUs(int n);