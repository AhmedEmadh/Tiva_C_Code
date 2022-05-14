#include "file .h fore all.h"
#include "LCD_FOR_TIVE.h"
void lcd_init(void)
{
	digital_input_output_setPort_direction(data_port,0xff);
	// contrl port
	digital_input_output_setpin_direction(ctrl_port,EN,1);// E
	digital_input_output_setpin_direction(ctrl_port,RS,1);//RS
	digital_input_output_setpin_direction(ctrl_port,RW,1);//RW
	digital_input_output_VWite_pin(ctrl_port,RW,0);
	LCD_VSEND_COMMEND(Function_set_8bit);
	delay_ms(1);
	LCD_VSEND_COMMEND(cursorOff);
	delay_ms(1);
	LCD_VSEND_COMMEND(clear_display);
	delay_ms(10);
	LCD_VSEND_COMMEND(Entry_mode);
	delay_ms(1);
}
static void send_pluse(void)
{
	digital_input_output_VWite_pin(ctrl_port,EN,1);
	delay_ms(2);
	digital_input_output_VWite_pin(ctrl_port,EN,0);
	delay_ms(2);
}
void LCD_VSEND_COMMEND(char commend)
{
	digital_input_output_VWite_port(data_port,commend);
	digital_input_output_VWite_pin(ctrl_port,RS,0);
	send_pluse();
	delay_ms(2);
}
void LCD_VSEND_Char(char Char)//send char
{
	digital_input_output_VWite_port(data_port,Char);
	digital_input_output_VWite_pin(ctrl_port,RS,1);
	send_pluse();
	delay_ms(2);
}
void LCD_VSEND_String(char *data) //send string
{
	while((*data!='\0'))
	{
		LCD_VSEND_Char((*data));
		data++;
	}
}
void lcd_clear_screen(void)//clear screen
{
		LCD_VSEND_COMMEND(clear_display);
		delay_ms(10);
}
void lcd_move_cursorOff(char row,char colum)//used in position 
{
	char position=0;
	if(row==1)
	{
		position=FirstRow+colum-1;
	}
	else if(row==2)
	{
		position=SecondRow+colum-1;
	}
	else
	{
		position=FirstRow;
	}
	LCD_VSEND_COMMEND(position);
	delay_ms(1);
}
