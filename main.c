//variables and enums
enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken}; //all states
enum Bool{False,True};
enum State state = not_cooking;
enum Bool door_closed = False;
int weight;
//functions
void initialization(){}
void lcd_print(char *p){}
void lcd_print(int n){}
void lcd_clear(){}
int lcd_input(){}
int pushed_key(){}
void start_cooking(){}
void stop_cooking(){}
void delay_sec(int t){}
void delay_ms(int t){}

//main function
void main() {
    //initialization for board
    initialization();

    while(1){ //loop
        switch (state)
        {
        case not_cooking:
            if(pushed_key() == A ) state = popcorn;
            if(pushed_key() == B ) state = beef;
            if(pushed_key() == C ) state = chicken;
            if(pushed_key() == D ) state = time_select;

            break;
        
        case popcorn:
            lcd_print("popcorn");
            delay_sec(60);
            lcd_clear();
            state = not_cooking;
            break;
        
        case beef:
            
            lcd_print("Beef weight?");
            weight = lcd_input();
            lcd_clear();
            lcd_print(weight);
            delay_sec(2);
            lcd_clear();
            start_cooking();
            delay(30 * weight);//0.5min * weight
            stop_cooking();
            break;
        
        case chicken:
            
            lcd_print("chicken weight?");
            weight = lcd_input();
            lcd_clear();
            lcd_print(weight);
            delay_sec(2);
            lcd_clear();
            start_cooking();
            delay(12 * weight);//0.2min * weight
            stop_cooking();
            break;
        default:
            break;
        }
    }//loop end
}