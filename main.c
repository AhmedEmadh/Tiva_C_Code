//includes
#include "functions.h"
#include <stdint.h>
//variables, enums and definitions
#define set_bit(reg,bit)   reg=reg|(1<<bit)
#define clr_bit(reg,bit)   reg=(~(1<<bit))&reg
#define read_bit(reg,bit)   ((reg>>bit)&1)
#define tog_bit(reg,bit)   (reg=reg^(1<<bit))

enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error}; //all states
enum Bool{False,True};//boolean
enum State state = not_cooking;
enum Bool door_closed = False;
int weight;
char input;
//main function
int main() {
    //initialization for board
    initialization();

    while(1){ //loop
        switch (state)
        {
        case not_cooking:
            lcd_clear();
            if(pushed_key() == A ) state = popcorn;
            if(pushed_key() == B ) state = beef;
            if(pushed_key() == C ) state = chicken;
            if(pushed_key() == D ) state = other;

            break;

        case popcorn:
            lcd_print_char_row("popcorn",0);
            pop_count_down(); //count form 60 s to 0
            lcd_clear();
            state = not_cooking;
            break;

        case beef:

            lcd_print_char("Beef weight?");
             input = keypad_input();
            if (input == 'a' || 'b' || 'c' || 'd' || '*' || '#' || '0'){
                state = error;}
            else
            {weight = input;}
            lcd_print_int(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print_int(weight);
            beef_count_down(); // starts a countdown with a time = 30s * weight
            lcd_clear();
            state = not_cooking;
            break;

        case chicken:

           lcd_print_char("Beef weight?");
             input = keypad_input();
            if (input == 'a' || 'b' || 'c' || 'd' || '*' || '#' || '0')
            {state = error;}
            else
            {weight = input;}
            lcd_print_int(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print_int(weight);
            chicken_count_down(); // starts a countdown with a time = 12s * weight
            lcd_clear();
            state = not_cooking;
            break;
        case error:
        lcd_print_char("Err");
        delay_sec(2);
        //previous state

            break;
        default:
            break;
        }
    }//loop end
}