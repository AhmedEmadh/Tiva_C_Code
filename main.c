////////////////////the code without interupt or door closed case////////////////////
//includes
#include "functions.h"
#include <stdint.h>
#include "LCD.h"
#include "keypad.h"
//variables, enums and definitions
enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error_beef,error_chicken,error_other}; //all states
enum Bool{False,True};//boolean
enum State state = not_cooking;
enum Bool door_closed = False;
int weight;
char input;
int j = 0; //global iterator
//main function
int main() {
    unsigned char SW2_In;
    int i;
    int time_seconds_other;
    char inputs[] = {'0','0','0','0'};
    char temp [] = {'0','0','0','0'};

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
            delay_ms(2000);
            pop_count_down(1); //count from 60 s to 0
            lcd_clear();
            lcd_print_str("End popcorn");
            delay_ms(2000);
            lcd_clear();
					  delay_ms(2000);
            state = not_cooking;
        break;
        case beef:
            lcd_print_str("Beef weight?");
            delay_ms(2000);
            input = keypad_input();
            if ( !(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0') )//changed smalles to Capitals
            {   //Valid number
                weight = input - '0';
                lcd_print_int(weight);
                delay_sec (2);
                lcd_clear();
                beef_count_down(weight); // starts a countdown with a time = 30s * weight
                lcd_clear();
                lcd_print_str("End Beef weight");
                delay_ms(2000);
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
            delay_ms(2000);
            input = keypad_input();
            if (!(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0'))//changed smalles to Capitals
            {//valid number
            weight = input - '0';
            lcd_print_int(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print_int(weight);
            chicken_count_down(weight); // starts a countdown with a time = 12s * weight
            lcd_clear();
            lcd_print_str("End Beef weight");
            delay_ms(2000);
            lcd_clear();
            state = not_cooking;
            }
            else
            {//not a valid number
            state = error_chicken;
            }
            break;
        case other:
            other_start:
            lcd_clear();
            while(SW1_is_pressed() == 1){}//wait if sw1 is pressed (come from goto case)
           
            do{
                lcd_print_str("Cooking Time?");
                delay_ms(2000);
                lcd_clear();
                while(1){
                    input = keypad_switch_input();
				            delay_ms(2000);		  
                    if(input == 'S'){break;}//if SW2 pressed give ok to the number
                    if (input == 'H'){goto other_start;}//if SW1 pressed clear the LCD and start the case again
                    temp[3] = input;//if other button pressed start the putting it in the screen by converting it into integer
                    temp[2] = inputs[3];
                    temp[1] = inputs[2];
                    temp[0] = inputs[1];//temp here is ready to be cloned by input
                    for(i=0;i<=3;i++){inputs[i] = temp[i];}//put inputs[] = temp[] (cloning)
                    displaytime_char(inputs[0],inputs[1],inputs[2],inputs[3]);
				            delay_ms(2000);
										SW2_In = SW2_is_pressed();										
										if(SW2_In==0x01){goto x;}
                }//while SW2 not pressed
            }while(1);

						x:
            time_seconds_other = inputs_to_seconds (inputs[0],inputs[1],inputs[2],inputs[3]);
            other_count_down(time_seconds_other);
            state = not_cooking;
            break;
        case error_beef: //added error beef
            lcd_print_str("Err");
	          delay_ms(2000);		  
            state = beef; //previous state
            break;
        case error_chicken: // added error chicken
            lcd_print_str("Err");
	          delay_ms(2000);		  
            state = chicken; //previous state
            break;
        case error_other: // added error chicken
            lcd_print_str("Err");
	          delay_ms(2000);		  
            state = chicken; //previous state
            break;
        default:
            break;
        }
    }//loop end
}

