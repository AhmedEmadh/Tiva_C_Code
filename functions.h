#ifndef __function_H__
#define __function_H__
//macros help to edit registers
#define set_bit(reg,bit)   reg=reg|(1<<bit)
#define clr_bit(reg,bit)   reg=(~(1<<bit))&reg
#define read_bit(reg,bit)   ((reg>>bit)&1)
#define tog_bit(reg,bit)   (reg=reg^(1<<bit))
//functions serve main.c
void initialization();//code running at beginning
void lcd_print_str(char *p);//takes string first element address and print it on LCD
void lcd_print_int(int n);//taking integer and print it at LCD
void lcd_print_str_row(char *p,int row);//takes string first element address and row number (0 or 1) to print it on LCD
void lcd_print_int_row(int n,int row);//takes integer and row number (0 or 1) to print it on LCD
void lcd_clear();//cleares LCD
char keypad_input();//takes input from keypad and return it as character
int pushed_key();//not used
void pop_count_down();//counts pop for 1 minite
void beef_count_down();//counts beef
void chicken_count_down();//counts chicken
void start_cooking();//cook all types
void stop_cooking();//stop cooking all types
void delay_sec(int t);//makes the board wait for t secounds
//void delay_ms(int t);//makes the board wait for t millisecounds
char keypad_switch_input();
void other_count_down(int time_sec);
unsigned char SW2_Input (void);
unsigned char SW1_Input (void);
void displaytime_char(char m1,char m0,char s1,char s0);
int char_to_int(char c);//char to int converter
int inputs_to_seconds (char mc1,char mc0,char sc1,char sc0);
void led(void);
#endif

