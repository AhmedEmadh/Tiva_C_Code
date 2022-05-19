#include "tm4c123gh6pm.h"
#include "SYSTICK.h"
#include "Io.h"
#include <stdint.h>
void SysTick_wait(unsigned long delay){
	NVIC_ST_CTRL_R=0x00;
	NVIC_ST_RELOAD_R=delay-1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x05;
	while((NVIC_ST_CTRL_R&0x00010000)==0){}//wait for count flag;
}
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int time){
	int i;
	for(i=0;i<time;i++){
		SysTick_wait(16000); //1ms
	}
}
 
/* delay n microseconds (16 MHz CPU clock) */
void delayUs(int n)
{
int i;
	for(i=0;i<n;i++)
{
		SysTick_wait(16000);  /* do nothing for 1 us */
}
}

