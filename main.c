////////////////////the code without interupt or door closed case////////////////////
//includes
#include "functions.h"
#include <stdint.h>
#include "IO.h"
//#include "key.h"
//variables, enums and definitions
enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error_beef,error_chicken,error_other}; //all states
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
                lcd_print_int(weight);
                beef_count_down(); // starts a countdown with a time = 30s * weight
                lcd_clear();
                state = not_cooking;
            }
            else
            {   //not a valid number
                state = error_beef;
            }
            break;
        case chicken:
            lcd_print_str("Beef weight?");
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
            lcd_print_str("Cooking Time?");
            input = keypad_input();
            char inputs[] = {'0','0','0','0'};
            int n;
            unsigned char SW2_Input (void)
            {
                return GPIO_PORTF_DATA_R & 0x01;
            }
            unsigned char switch2_In;
            switch2_In = SW2_Input();
            while (SW2_Input = 0x01 && n<4) // while SW2 is not pressed
            {
               inputs[3-n] = keypad_input();
               n++
            }

            //delay_sec(inputs[0]*10*60+inputs[1]*60+inputs[2]*10+inputs[3]*1) // wrong parameter type
            //not completed
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
