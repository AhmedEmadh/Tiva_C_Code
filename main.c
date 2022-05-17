////////////////////the code without interupt or door closed case////////////////////
//includes
#include "functions.h"
#include <stdint.h>
#include "IO.h"
#include "keypad.h"
//variables, enums and definitions
enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error_beef,error_chicken,error_other}; //all states
enum Bool{False,True};//boolean
enum State state = not_cooking;
enum Bool door_closed = False;
int weight;
char input;
int i = 0; //global iterator
//main function
int main() {
    //initialization for board
    initialization();
    while(1){ //loop
        switch (state)
        {
        case not_cooking:
            lcd_clear();
            input = keypad_input(); //take an input value
            if(input == 'A' ) state = popcorn;
            if(input == 'B' ) state = beef;
            if(input == 'C' ) state = chicken;
            if(input == 'D' ) state = other;
            break;
        case popcorn:
            lcd_print_str("popcorn");
            pop_count_down(); //count from 60 s to 0
            lcd_clear();
            state = not_cooking;
            break;
        case beef:
            lcd_print_str("Beef weight?");
            input = keypad_input();
            if ( !(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0') )//changed smalles to Capitals
            {   //Valid number
                weight = input - '0';
                lcd_print_int(weight);
                delay_sec (2);
                lcd_clear();
                beef_count_down(weight); // starts a countdown with a time = 30s * weight
                lcd_clear();
                state = not_cooking;
            }
            else
            {   //not a valid number
                state = error_beef;
            }
            break;
        case chicken:
            lcd_print_str("chicken weight?");
            input = keypad_input();
            if (!(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0'))//changed smalles to Capitals
            {//valid number
            weight = input - '0';
            lcd_print_int(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print_int(weight);
            chicken_count_down(); // starts a countdown with a time = 12s * weight
            lcd_clear();
            state = not_cooking;
            }
            else
            {//not a valid number
            state = error_chicken;
            }
            break;
        case other:
        int time_seconds_other;
            other_start:
            lcd_clear();
            while(SW1_Input() == 0x10){}
            char inputs[] = {'0','0','0','0'};
            char temp [] = {'0','0','0','0'};
            unsigned char SW2_In;
            do{
                lcd_print_str("Cooking Time?");
                delay_sec(2);
                lcd_clear();
                SW2_In = SW2_Input();
                do{
                    input = keypad_switch_input();
                    if(input == 'S'){break;}
                    if (input == 'H'){goto other_start;}
                    temp[3] = input;
                    temp[2] = inputs[3];
                    temp[1] = inputs[2];
                    temp[0] = inputs[1];
                    for(i=0;i<=3;i++){inputs[i] = temp[i];}
                    displaytime_char(inputs[0],inputs[1],inputs[2],inputs[3]);
                }while(SW2_In == 0x01);//while not pressed
            }while((char_to_int(inputs[0]) >= 30) && (char_to_int(inputs[0]) == 0));

            time_seconds_other = inputs_to_seconds (inputs[0],inputs[1],inputs[2],inputs[3]);
            other_countdown(time_seconds_other);
            break;
        case error_beef: //added error beef
            lcd_print_str("Err");
            delay_sec(2);
            state = beef; //previous state
            break;
        case error_chicken: // added error chicken
            lcd_print_str("Err");
            delay_sec(2);
            state = chicken; //previous state
            break;
        case error_other: // added error chicken
            lcd_print_str("Err");
            delay_sec(2);
            state = chicken; //previous state
            break;
        default:
            break;
        }
    }//loop end
}
