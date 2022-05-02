void initialization(){}
void lcd_print(char *p){}
void lcd_clear(){}
int pushed_key(){}
void start_cooking(){}
void stop_cooking(){}
void delay_sec(int t){}
void delay_ms(int t){}
enum {A,B,C,D}; //all buttons
enum {not_cooking,popcorn,beef,chicken,time_select}; //all states

int state = not_cooking;

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
            
            break;
        
        case chicken:
            
            break;
        case time_select:
            
            break;
        default:
            break;
        }
    }
}