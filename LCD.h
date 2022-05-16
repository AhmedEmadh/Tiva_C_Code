#ifndef __LCD_H__
#define __LCD_H__
#include <stdio.h>          // printf, scanf, NULL 
#include <stdlib.h>         // malloc, free, rand 
#include "tm4c123gh6pm.h"
#include "Delay.h"
#include "DMC1610A.h"
#define  time  500
void LCD_Init              (void);
void LCD_command           (unsigned int);
void LCD_data              (unsigned char);
void LCD_printInt          (int);
void LCD_printFloat        (float);
void LCD_printString       (char*);
void LCD_errormsg          (void);
void LCD_setcursorRowCol   (unsigned int, unsigned int);
void displayTime           (int, int, int, int);
void loading               (void);

#endif
