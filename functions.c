#include "functions.h"
#include "IO.h"
#include "delay.h"
#include "SYSTICK.h" 
int i=0 ;
void initialization(){}
void lcd_print_str(char *p){}
void lcd_print_int(int n){}
void lcd_print_str_row(char *p,int row){}
void lcd_print_int_row(int n,int row){}
void lcd_clear(){}
char keypad_input(){}
int pushed_key(){} //not used
void pop_count_down(){}
void beef_count_down(){}
void chicken_count_down(){}
void start_cooking(){}
void stop_cooking(){}
void delay_sec(int t)
{
    for( i = 0 ; i<1000 ; i++  ){
        delayMs(t);
    }
}
void delay_ms(int t)
{
 
}
unsigned char SW2_Input (void)
            {
                return GPIO_PORTF_DATA_R & 0x01;
            }