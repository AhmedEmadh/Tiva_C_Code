#include "functions.h"
#include "IO.h"
#include "LCD.h"
#include "DMC1610A.h"
#include "keypad.h"
#include <stdint.h>
#include "SYSTICK.h"
unsigned const char mysymbol[padRows][padCols] = {{ '1', '2',  '3', 'A'},      
                                                { '4', '5',  '6', 'B'},      
                                                { '7', '8',  '9', 'C'},      
                                                { '*', '0',  '#', 'D'}};
int i = 0 ; //global iterator
void initialization(){
	// init port F
   SYSCTL_RCGCGPIO_R |= 0x20;            //enable clc for port f
  while ((SYSCTL_RCGCGPIO_R&0x20)==0){};
    GPIO_PORTF_LOCK_R=0X4C4F434B;
		GPIO_PORTF_PUR_R|=0X11;
    GPIO_PORTF_CR_R|=0XFF;
		GPIO_PORTF_DIR_R|=0X0E;
    GPIO_PORTF_DEN_R |=0X1F;	
	  GPIO_PORTF_DATA_R|=0x11;
	// end port f init
    keypad_Init();
    LCD_Init();
}
void lcd_print_str(char *p){    // print a string
    LCD_printString(&*p);   
}
void lcd_print_int(int n){  // print integer 
    LCD_printInt(n);        
}        
void lcd_print_str_row(char *p,int row){   // print string in a selected row
    LCD_setcursorRowCol(row,0);
    LCD_printString(&*p);
}
void lcd_print_int_row(int n,int row){     // print integer in selected row
    LCD_setcursorRowCol(row,0);
    LCD_printInt(n);
}
void lcd_clear(){                 // clear screen
    LCD_command(CLEAR_DISPLAY);
}
char keypad_input(){             // get inputs from keypad
   return keypad_getkey();
}
void pop_count_down(int weight)        // count down for popcorn
{
    int time_sec = 0;
    lcd_clear();
	time_sec = weight*60;
	while(time_sec>=0)
	{
	displayTime(0,time_sec/60,time_sec%60,0);
    delayMs(1000);
		time_sec --;
	}
    }
void beef_count_down(int weight){       // count down for beef
    int time_sec = 0;
    lcd_clear();
	time_sec = weight*30;
	while(time_sec>=0)
	{
	displayTime(0,time_sec/60,time_sec%60,0);
    delayMs(1000);
    time_sec --;
	}
}
void chicken_count_down(int weight){     // count down while chicken
    int time_sec = 0;
    lcd_clear();
	time_sec = weight*12;
	while(time_sec>=0)
	{
    	displayTime(0,time_sec/60,time_sec%60,0);
        delayMs(1000);
        time_sec --;
	}
}
void delay_sec(int t){              // delay in seconds
    for (i =1000;i<=0; i--){
        delayMs(t);
    }
}
void delay_Ms(int t){            // delay in milisecond
    delayMs(t);
}
unsigned char SW2_Input (void)     // get input from switch 2
{//returns 1 if pressed and 0 if not
    return ((GPIO_PORTF_DATA_R & 0x01)==1)?0:1;
}
unsigned char SW1_Input (void)       // get input from switch 1
{//return 1 if pressed and 0 if not
    return (((GPIO_PORTF_DATA_R & 0x10)>>4) == 1)?0:1;
}
char keypad_switch_input(){            // get input from keypad and switches
    int i=0,j=0;
    while(1)
    {
        for(i = 0; i < 4; i++)                        //columns traverse
        {
            GPIO_PORTC_DATA_R = (1U << (i+4));
            delay_us(2);
            for(j = 0; j < 4; j++)                     //raws traverse
                {
                    if((GPIO_PORTE_DATA_R & 0x1E) & (1U << (j+1)))
                        return mysymbol[j][i];
                }
        }
    /////////////Ahmed Emad Added here
        if(SW2_Input() == 1){//if pressed
            return 'S';
        }
        if(SW1_Input() == 1){//if pressed
            return 'H';
        }
        /////////////End
    }
}
int char_to_int(char c){      // convert char to integer
    int intg = c - '0';
    return intg;
}
void displaytime_char(char mc1,char mc0,char sc1,char sc0){     // convert char to integer and display time 
    int m1,m0,s1,s0,m,s;
	  m1 = char_to_int(mc1);
    m0 = char_to_int(mc0);
    s1 = char_to_int(sc1);
    s0 = char_to_int(sc0);
    m = m1 * 10 + m0;
    s = s1 * 10 + s0;
	if(m>30){

               		lcd_clear();
	                lcd_print_str("Error In Timer");
		                delay_ms(2000);
                   lcd_clear();

	
	}
    m = m1 * 10 + m0;
    s = s1 * 10 + s0;
    displayTime(0,m,s,0);
}
int inputs_to_seconds (char mc1,char mc0,char sc1,char sc0){
    int m1,m0,s1,s0,m,s;
    m1 = char_to_int(mc1);
    m0 = char_to_int(mc0);
    s1 = char_to_int(sc1);
    s0 = char_to_int(sc0);
    m = m1 * 10 + m0;
    s = s1 * 10 + s0;
	if(m>30){

               		lcd_clear();
	                lcd_print_str("Error In Timer");
		                delay_ms(2000);
                   lcd_clear();

	
	}
    return (m*60 + s);
}
void other_count_down(int time_sec){    
 int x=0;  
	x=time_sec;
	lcd_clear();
while(x>=0)
	{
	displayTime(0,x/60,x%60,0);
		delay_ms(1000);		  
		x --;
	}
}

void led(void){
					   GPIO_PORTF_DATA_R=0X0E;
				    delay_ms(2000);
				    GPIO_PORTF_DATA_R=0X11;				    
            lcd_clear();
					  delay_ms(2000);
}
 void sound(void)
 {
   SYSCTL_RCGCGPIO_R |= 0x08;            //enable clc for port D
  while ((SYSCTL_RCGCGPIO_R&0x08)==0){};
    GPIO_PORTD_LOCK_R=0X4C4F434B;
		GPIO_PORTD_PUR_R|=0X01;
    GPIO_PORTD_CR_R|=0XFF;
		GPIO_PORTD_DIR_R|=0X0E;
    GPIO_PORTD_DEN_R |=0X1F;	

	    
 }
