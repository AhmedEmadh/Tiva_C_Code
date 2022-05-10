//variables and enums
#define SET_BIT(reg,bit)   reg=reg|(1<<bit)
#define CLR_BIT(reg,bit)   reg=(~(1<<bit))&reg
#define READ_BIT(reg,bit)   ((reg>>bit)&1)
#define TOG_BIT(reg,bit)   (reg=reg^(1<<bit))

enum Button{A,B,C,D}; //all buttons
enum State{not_cooking,popcorn,beef,chicken,other,error}; //all states
enum Bool{False,True};
enum State state = not_cooking;
enum Bool door_closed = False;
int weight;
//functions
void initialization(){}
void lcd_print(char *p){}
void lcd_print(int n){}
void lcd_print(char *p,int row){}
void lcd_print(int n,int row){}
void lcd_clear(){}
int keypad_input(){}
int pushed_key(){}
void beef_count_down(){}
void chicken_count_down(){}
void start_cooking(){}
void stop_cooking(){}
void delay_sec(int t){}
void delay_ms(int t){}

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
            lcd_print("popcorn",0);
            pop_count_down(); //count form 60 s to 0
            lcd_clear();
            state = not_cooking;
            break;

        case beef:

            lcd_print("Beef weight?");
             input = keypad_input();
            if (input == 'a' || 'b' || 'c' || 'd' || '*' || '#' || '0'){
                state = error;}
            else
            {weight = input;}
            lcd_print(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print(weight);
            beef_count_down(); // starts a countdown with a time = 30s * weight
            lcd_clear();
            state = not_cooking;
            break;

        case chicken:

           lcd_print("Beef weight?");
             input = keypad_input();
            if (input == 'a' || 'b' || 'c' || 'd' || '*' || '#' || '0')
            {state = error;}
            else
            {weight = input;}
            lcd_print(weight);
            delay_sec (2);
            lcd_clear();
            lcd_print(weight);
            chicken_count_down(); // starts a countdown with a time = 12s * weight
            lcd_clear();
            state = not_cooking;
            break;
        case error:
        lcd_print("Err");
        delay_sec(2);
        //previous state

            break;
        default:
            break;
        }
    }//loop end
}
