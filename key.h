//#include "D:\UV4\tm4c123gh6pm.h" dont include your own path here
//#include "TM4C123.h" // Device header --------- where is this file???
#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
#include <stdint.h>
//#include "D:\io.h" dont include your own path here
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void keypad_init(void);
unsigned char keypad_kbhit(void);
void keypad_init(void);
unsigned char keypad_getkey(void);