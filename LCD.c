#include <TM4C123.h>
#include "LCD.h"
#include "Delay.h"


int x=0;
void LCD_Init(void)
{
// LCD ports' Initialization:
SYSCTL_RCGCGPIO_R |= 0x03;              // enable clock to port A & B
while ((SYSCTL_RCGCGPIO_R&0x03)==0);    //wait for clock to be enabled
GPIO_PORTA_CR_R  |= 0xE0;               // allow changes to all the bits in port A
GPIO_PORTA_DIR_R |= 0xE0;               // set PORTA pin 7-5 as output for control
GPIO_PORTA_DEN_R |= 0xE0;               // set PORTA pin 7-5 as digital pins 
GPIO_PORTB_CR_R  |= 0xFF;                // allow changes to all the bits in port B
GPIO_PORTB_DIR_R |= 0xFF;               // set all PORTB pins as output for data
GPIO_PORTB_DEN_R |= 0xFF;               // set all PORTB pins as digital pins

// LCD Initialization Commands:
delay_ms(20);
LCD_command(FUNC_SET_8BIT_2LINE);
delay_ms(5);
LCD_command(FUNC_SET_8BIT_2LINE);
delay_us(100);
LCD_command(FUNC_SET_8BIT_2LINE);
LCD_command(DISPLAY_OFF_CURSOR_OFF); 
LCD_command(CLEAR_DISPLAY);            
LCD_command(SHIFT_CURSOR_RIGHT) ;   
LCD_command(DISPLAY_ON_CURSOR_ON);         
}



void LCD_command(unsigned int command)
{
  GPIO_PORTA_DATA_R = 0x20;               //set RS to 1 to enable Command Register and RW to low to write to the LCD
  GPIO_PORTB_DATA_R = command;
  GPIO_PORTA_DATA_R = 0x80;
  delay_us(1);
  GPIO_PORTA_DATA_R = 0x00;                  //High to Low pulse to push the command to the LCD
  if (command < 4) 
    delay_ms(2);                          // command 1 and 2 needs up to 1.64ms 
  else             
    delay_us(40);                         // all others 40 us
}



void LCD_data(unsigned char data)
{ 
  GPIO_PORTA_DATA_R = 0x20;               //set RS to 1 to enable Data Register and RW to low to write to the LCD
  GPIO_PORTB_DATA_R = data;
  GPIO_PORTA_DATA_R = 0x80 | 0x20;
  delay_us(1);
  GPIO_PORTA_DATA_R = 0;                  //High to Low pulse to push the data to the LCD
  delay_us(40);
}


void LCD_printInt(int no)
{
	int i = 0;
  char toprint[4] = {0};
  sprintf(toprint, "%d", no);
 
  while(toprint[i] != '\0')
  {
    LCD_data(toprint[i]);
    i++;
  }
}


void LCD_printFloat(float no)
{
	  int j = 0;
//  char toprint[10];
//  sprintf(toprint, "%f", no);
//  itoa(no, toprint);
  
  int len = snprintf('\0', 0, "%f", no);
  char* toprint = (char *)malloc(len + 1);
  snprintf(toprint, len + 1, "%f", no);
  while (j < len - 3 )
  {
    LCD_data(toprint[j]);
    j++;
  }
  free(toprint);
}


void LCD_printString(char* str)
{
	  int i = 0;
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  while (str[i] != '\0')
  {
    LCD_data(str[i]);
    i++;
  }
}


void LCD_errormsg(void)
{
  LCD_command(CURSOR_START_3RD_LINE);
  LCD_printString("Math ERROR");
}


//void LCD_cursorblink(void)
//{
//  LCD_command(CURSOR_START_1ST_LINE );
//  LCD_command(DISPLAY_ON_CURSOR_BLINK);
//}


void LCD_setcursorRowCol(unsigned int row, unsigned int col)
{
  int command = 0x00;
  if( row == 0)
  {
    command = 0x80;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 1)
  {
    command = 0xC0;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }

}


void displayTime(int h,int m,int s,int ss)
{
  //LCD_command(CLEAR_DISPLAY);
  LCD_setcursorRowCol(0, 3);
  LCD_printInt(h);
  LCD_setcursorRowCol(0, 4);
  LCD_data(':');
  LCD_setcursorRowCol(0, 5);
  LCD_printInt(m);
  LCD_setcursorRowCol(0, 7);
  LCD_data(':');
  LCD_setcursorRowCol(0, 8);
	if(s<10){
		  LCD_setcursorRowCol(0, 8);
		LCD_printInt(x);
	  LCD_setcursorRowCol(0, 9);  
		  LCD_printInt(s);
	}
  LCD_printInt(s);
  LCD_setcursorRowCol(0, 10);
  LCD_data(':');
  LCD_setcursorRowCol(0, 11);
  LCD_printInt(ss);
}
void loading(void)
{
	int i = 9;
  LCD_command(DISPLAY_ON_CURSOR_OFF);
  for(i = 9; i < 12; i++)
  {
    LCD_command(CLEAR_DISPLAY);
    LCD_setcursorRowCol(1,2);
    LCD_printString("Loading");
    LCD_setcursorRowCol(1,i);
    LCD_data('.');
    delay_ms(time);
  }
  LCD_command(CLEAR_DISPLAY);
}
