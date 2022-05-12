#include "key.h"
#include "IO.h"
int main(void)
{
unsigned char key;
keypad_init();
LCD_init();
 
while(1)
{
LCD_command(0x80); /* LCD cursor location */
 
key = keypad_getkey(); /* read the keypad */
if (key != 0)
{ /* if a key is pressed */
LCD_data(key); /* display the key label */
}
else
LCD_data(' ');
 
delayMs(20); /* wait for a while */
}
}
 

 
/* this function initializes the ports connected to the keypad */
void keypad_init(void)
{
SYSCTL_RCGCGPIO_R |= 0x04; /* enable clock to GPIOC */
SYSCTL_RCGCGPIO_R |= 0x10; /* enable clock to GPIOE */
 //GPIO_PORTC_
GPIO_PORTE_DIR_R|= 0x0F; /* set row pins 3-0 as output */
GPIO_PORTE_DEN_R |= 0x0F; /* set row pins 3-0 as digital pins */
GPIO_PORTE_ODR_R |= 0x0F; /* set row pins 3-0 as open drain */
 
GPIO_PORTC_DIR_R &= ~0xF0; /* set column pin 7-4 as input */
GPIO_PORTC_DEN_R |= 0xF0; /* set column pin 7-4 as digital pins */
GPIO_PORTC_PUR_R |= 0xF0; /* enable pull-ups for pin 7-4 */
}
 
/* This is a non-blocking function to read the keypad. */
/* If a key is pressed, it returns the key label in ASCII encoding. Otherwise, it returns a 0 (not ASCII 0). */
unsigned char keypad_getkey(void)
{
const unsigned char keymap[4][4] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};
 
int row, col;
 
/* check to see any key pressed first */
GPIO_PORTE_DATA_R = 0; /* enable all rows */
col = GPIO_PORTC_DATA_R & 0xF0; /* read all columns */
if (col == 0xF0) return 0; /* no key pressed */
 
/* If a key is pressed, it gets here to find out which key. */
/* Although it is written as an infinite loop, it will take one of the breaks or return in one pass.*/
while (1)
{
row = 0;
GPIO_PORTE_DATA_R = 0x0E; /* enable row 0 */
delayUs(2); /* wait for signal to settle */
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
 
row = 1;
GPIO_PORTE_DATA_R = 0x0D; /* enable row 1 */
delayUs(2); /* wait for signal to settle */
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
 
row = 2;
GPIO_PORTE_DATA_R = 0x0B; /* enable row 2 */
delayUs(2); /* wait for signal to settle */
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
 
row = 3;
GPIO_PORTE_DATA_R = 0x07; /* enable row 3 */
delayUs(2); /* wait for signal to settle */
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
 
return 0; /* if no key is pressed */
}
 
/* gets here when one of the rows has key pressed */
if (col == 0xE0) return keymap[row][0]; /* key in column 0 */
if (col == 0xD0) return keymap[row][1]; /* key in column 1 */
if (col == 0xB0) return keymap[row][2]; /* key in column 2 */
if (col == 0x70) return keymap[row][3]; /* key in column 3 */
return 0; /* just to be safe */
}
unsigned char keypad_kbhit(void)
{
int col;
 
/* check to see any key pressed */
GPIO_PORTE_DATA_R = 0; /* enable all rows */
col = GPIO_PORTC_DATA_R & 0xF0; /* read all columns */
if (col == 0xF0)
return 0; /* no key pressed */
else
return 1; /* a key is pressed */
}
void LCD_init(void)
{
SYSCTL->RCGCGPIO |= 0x01; /* enable clock to GPIOA */
SYSCTL->RCGCGPIO |= 0x02; /* enable clock to GPIOB */
 
LCD_CTRL->DIR |= 0xE0; /* set PORTA pin 7-5 as output for control */
LCD_CTRL->DEN |= 0xE0; /* set PORTA pin 7-5 as digital pins */
LCD_DATA->DIR = 0xFF; /* set all PORTB pins as output for data */
LCD_DATA->DEN = 0xFF; /* set all PORTB pins as digital pins */
 
delayMs(20); /* initialization sequence */
LCD_command(0x30);
delayMs(5);
LCD_command(0x30);
delayUs(100);
LCD_command(0x30);
 
LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}
 
void LCD_command(unsigned char command)
{
LCD_CTRL->DATA = 0; /* RS = 0, R/W = 0 */
LCD_DATA->DATA = command;
LCD_CTRL->DATA = EN; /* pulse E */
delayUs(0);
LCD_CTRL->DATA = 0;
if (command < 4) delayMs(2); /* command 1 and 2 needs up to 1.64ms */ else delayUs(40); /* all others 40 us */ } void LCD_data(unsigned char data) { LCD_CTRL->DATA = RS; /* RS = 1, R/W = 0 */
LCD_DATA->DATA = data;
LCD_CTRL->DATA = EN | RS; /* pulse E */
delayUs(0);
LCD_CTRL->DATA = 0;
delayUs(40);
}
 /*delay*/
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


