#ifndef __KEYPAD_H__
#define __KEYPAD_H__
#include "D:\UV4\tm4c123gh6pm.h"
#include "D:\EE319Kware\InputOutput_4C123\project\Delay.h"
#define  padRows  4
#define  padCols  4

void keypad_Init       (void);
char keypad_getkey     (void);

#endif
