#include "Delay.h"
void delay_ms(int time)
{
int i, j;
for(i = 0 ; i < time; i++)
  for(j = 0; j < 3180; j++){}
}
 


void delay_us(int time)
{
int i, j;
for(i = 0 ; i < time; i++)
  for(j = 0; j < 3; j++){}
}
