#include "tm4c123gh6pm.h"
#include "digital_input_output.h"
//PORT D ROW 0,1,2,3  C COLUM 4,5,6,7
void key_pad_init(void);
unsigned char keypad_read(void)
{

const unsigned char keymap[4][4] = 
{
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};
int Col,Row;
digital_input_output_VWite_port('D',0);
Col=(GPIO_PORTC_DATA_R&0xf0);
if(Col == 0xf0) return 0; //NO PRESSED
while(1){
	Row=0;
	digital_input_output_VWite_port('D',0x0E);
	delay_us(4);
	Col=(GPIO_PORTC_DATA_R&0xf0);
	if(Col != 0xf0)break;
		Row=1;
	digital_input_output_VWite_port('D',0x0D);
		delay_us(4);
	Col=(GPIO_PORTC_DATA_R&0xf0);
	if(Col != 0xf0)break;
		Row=2;
	digital_input_output_VWite_port('D',0x0B);
		delay_us(4);
	Col=(GPIO_PORTC_DATA_R&0xf0);
	if(Col != 0xf0)break;
		Row=3;
	digital_input_output_VWite_port('D',0x07);
		delay_us(4);
	Col=(GPIO_PORTC_DATA_R&0xf0);
	if(Col != 0xf0)break;
	return 0;
}
if(Col==0xE0)
{
	return keymap[Row][0];
}
else if(Col==0xD0)
{
		return keymap[Row][1];
}
else if(Col==0xB0)
{
		return keymap[Row][2];
}
else if(Col==0x70)
{
		return keymap[Row][3];
}
else
{
	return 0;
}
}
unsigned char key_pad_pressed(void)
{
int Col;
digital_input_output_VWite_port('D',0);
Col=(GPIO_PORTC_DATA_R&0xf0);
if(Col == 0xf0) return 0;//not pressed
else return 1; //key pressed
}	
void key_pad_init(void)
{
	// ROW FOR PORTD
	port_init('d');
	GPIO_PORTD_DIR_R=0x0f;
	GPIO_PORTD_ODR_R=0X0F;
	//colum
	port_init('C');
	GPIO_PORTC_DIR_R=0XF0;
	//do PUP GPIOB pin 4,5,6,7 col 1,2,3,4
	digital_input_output_VEnablePUR('C',4); 
	digital_input_output_VEnablePUR('C',5);
	digital_input_output_VEnablePUR('C',6);
	digital_input_output_VEnablePUR('C',7);

}
unsigned char Keypad_Read()
{
			key_pad_init();
		return	keypad_read()	;
}

