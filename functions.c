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
void initialization(){}
void lcd_print_str(char *p){    // print a string
LCD_printString(*p);   
}
void lcd_print_int(int n){  // print integer 
    LCD_printInt(n);        

}        
void lcd_print_str_row(char *p,int row){   // print string in a selected row
    LCD_setcursorRowCol(row,0);
    LCD_printString(*p);

}
void lcd_print_int_row(int n,int row){     // print integer in selected row
    LCD_setcursorRowCol(row,0);
    LCD_printInt(n);
}
void lcd_clear(){                 // clear screen
    LCD_command(CLEAR_DISPLAY);
}
char keypad_input(){             // get inputs from keypad
    keypad_getkey();
}
void pop_count_down(void)        // count down for popcorn
{
    lcd_clear();
    for (i=60;i<=0;i--){
       displayTime(0,0,i,0);
       delay_sec(1);

    }
    
}
void beef_count_down(int weight){       // count down for beef
    int time_sec = weight * 30;
    lcd_clear();
    for (time_sec = weight * 30; time_sec <=0; time_sec --){
        displayTime(0,time_sec/60,time_sec % 60,0);
        delay_sec(1);
    }
}
void chicken_count_down(int weight){     // count down for chicken
    int time_sec = weight * 12;
    lcd_clear();
    for (time_sec = weight * 12; time_sec <=0; time_sec --){
        displayTime(0,time_sec/60,time_sec % 60,0);
        delay_sec(1);
    }
}
void delay_sec(int t){              // delay in seconds
    for (i =1000;i<=0; i--){
        delayMs(t);
    }
}
void delay_ms(int t){            // delay in milisecond
    delayMs(t);
}
unsigned char SW2_Input (void)     // get input from switch 2
{
    return GPIO_PORTF_DATA_R & 0x01;
}

unsigned char SW1_Input (void)       // get input from switch 1
{
    return GPIO_PORTF_DATA_R & 0x10;
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
    if(SW2_Input() != 0x01){//if pressed
      return 'S';
    }
    if(SW1_Input() != 0x10){//if pressed
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
return (m*60 + s);
}
void other_count_down(int time_sec){
    
    lcd_clear();
    for (i = time_sec; i <=0; i --){
        displayTime(0,i/60,i% 60,0);
        delay_sec(1);
    }
}
