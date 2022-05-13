#include "digital_input_output.h"
#include "tm4c123gh6pm.h"

void key_pad_init(void);
unsigned char keypad_read()
{

const unsigned char keymap[4][4] = 
{
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};
char row ,col ,x;
char return_value=0xff;
for(row=0;row<4;row++){
digital_input_output_Vlowlabel('B', 0xff);
digital_input_output_VWite_pin('B',row,0);
for(col=4;col<8;col++)
{
	x= digital_input_output_U8Read_pin('B',(col));
	if(x==0)
{
	return_value=keymap[row][col];
	break;
}
if(x==0)break;
return return_value;
}
	
}
}
void key_pad_init(void)
{
	port_init('B');
	GPIO_PORTB_DIR_R=0x0f;
	//do PUP GPIOB pin 4,5,6,7 col 1,2,3,4
	digital_input_output_VEnablePUR('B',4); 
	digital_input_output_VEnablePUR('B',5);
	digital_input_output_VEnablePUR('B',6);
	digital_input_output_VEnablePUR('B',7);

}
unsigned char Keypad_Read()
{
			key_pad_init();
		return	keypad_read()	;
}


