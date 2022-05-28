
//includes
#include "interrupt.h"
#include "functions.h"
#include <stdint.h>
#include "LCD.h"
#include "keypad.h"
#include "led.h"
//variables, enums and definitions
enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error_beef,error_chicken,error_other}; //all states
enum Bool{False,True};//boolean
enum State state = not_cooking; //initial state
enum Bool door_closed = False;
int weight;
char input;
int j = 0; //global iterator
//main function
int main() {
    unsigned char SW2_In; //variable to store input of SW2
    int i; //iterator
    int time_seconds_other; //variable to store no. of seconds in case D
    char inputs[] = {'0','0','0','0'}; //for case D keypad input
    char temp [] = {'0','0','0','0'};  //for case D keypad input
    edge_counter_init();
    SW_PORTE(); //sw extra
    sound(); //for end of any case
    //initialization for board
    initialization();//all init
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
            lcd_print_str("popcorn");//print sting popcorn
            delay_ms(2000);//delay for 2 s
	    while(1){
	    	lcd_clear();//clear lcd
           	lcd_print_str("please press sw2");//string to start
            	delay_ms(2000);//delay
         	if(GPIO_PORTF_DATA_R==0x10){break;}
		}
		lcd_clear();//clear lcd
    		pop_count_down(1); //count from 60 s to 0
            	lcd_clear();
            	lcd_print_str("End popcorn");//print string
            	delay_ms(2000);//delay
		led(); // blink the LEDs
		GPIO_PORTD_DATA_R|=0X01;//sound on
                delay_ms(2000);//delay
		GPIO_PORTD_DATA_R|=0X00;//sound off
		state = not_cooking;
        break;
        case beef:
            lcd_print_str("Beef weight?");//print string
            delay_ms(2000);//delay
            input = keypad_input();//take form keypad
				
            if ( !(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0') )//changed smalles to Capitals
            {   //Valid number
                weight = input - '0';
                lcd_print_int(weight);//print
                delay_sec (2);//delay 2 s
                lcd_clear();//clear lcd
		while(1){
	    	     lcd_clear();//clear lcd
            	     lcd_print_str("please press sw2");//print string
                     delay_ms(2000);//delay
         	     if(GPIO_PORTF_DATA_R==0x10){break;}
		}
                beef_count_down(weight); // starts a countdown with a time = 30s * weight
                lcd_clear();//clear lcd
                lcd_print_str("End Beef weight");//print String 
                delay_ms(2000);//delay
                lcd_clear();//clear lcd
		GPIO_PORTD_DATA_R|=0X01;//start sound
                delay_ms(2000);//delay
		GPIO_PORTD_DATA_R|=0X00;//stop sound
		led();
                state = not_cooking;
            }
            else
            {   //not a valid number
                state = error_beef;
            }
            break;
        case chicken:
            lcd_print_str("chicken weight?");//print string
            delay_ms(2000);//delay
            input = keypad_input();// take for keybad
            if (!(input == 'A' || input =='B' || input =='C' || input =='D' || input =='*' || input =='#' || input =='0'))//changed smalles to Capitals
            {//valid number
            weight = input - '0';
            lcd_print_int(weight);//print string
            delay_sec (2);//delay
            lcd_clear();//clear lcd
            lcd_print_int(weight);//print string
	    while(1){
		lcd_clear();//clear lcd
            	lcd_print_str("please press sw2");//print string
            	delay_ms(2000);//delay
         	if(GPIO_PORTF_DATA_R==0x10){break;}
	   }
            chicken_count_down(weight); // starts a countdown with a time = 12s * weight
            lcd_clear();//clear lcd
            lcd_print_str("End Beef weight");//print String
            delay_ms(2000);//delay
            lcd_clear();// clear lcd
	    led();// led in port f
	    GPIO_PORTD_DATA_R|=0X01;//for sound
            delay_ms(2000);//delay
	    GPIO_PORTD_DATA_R|=0X00;//stop sound
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
            while(SW1_Input() == 1){}//wait if sw1 is pressed (come from goto case)
           
            do{
                lcd_print_str("Cooking Time?");//print string
                delay_ms(2000);//delay 
                lcd_clear();//clear lcd
                while(1){
                    input = keypad_input();
		    delay_ms(2000);		  
                    if (GPIO_PORTF_DATA_R == 0X01){goto other_start;}//if SW1 pressed clear the LCD and start the case again
                    temp[3] = input;//if other button pressed start the putting it in the screen by converting it into integer
                    temp[2] = inputs[3];
                    temp[1] = inputs[2];
                    temp[0] = inputs[1];//temp here is ready to be cloned by input
                    for(i=0;i<=3;i++){inputs[i] = temp[i];}//put inputs[] = temp[] (cloning)
                    displaytime_char(inputs[0],inputs[1],inputs[2],inputs[3]);
		    delay_ms(5000);	
		    if(GPIO_PORTF_DATA_R==0x10){goto x;}//SW2 PRESSED
                }//while SW2 not pressed
            	}while(1);
		x:
            	time_seconds_other = inputs_to_seconds (inputs[0],inputs[1],inputs[2],inputs[3]);
            	other_count_down(time_seconds_other);
		lcd_print_str("End Cooking Time");
		led();
           	state = not_cooking;
            break;
        case error_beef: //added error beef
            lcd_print_str("Err");
	    delay_ms(2000);//delay 		  
            state = beef; //get back to beef state
            break;
        case error_chicken: // added error chicken
            lcd_print_str("Err");
	    delay_ms(2000);	//delay 	  
            state = chicken; //get back to chicken state
            break;
        case error_other: // added error chicken
            lcd_print_str("Err");
	    delay_ms(2000);	//delay 	  
            state = chicken; //get back to other state
            break;
        default:
            break;
        }
    }//loop end
}
