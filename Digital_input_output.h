#ifndef __Digital_input_output_H__
#define __Digital_input_output_H__
#include "tm4c123gh6pm.h"
#define 	set_bit(name_register,pin_bit)  name_register |=(1<<pin_bit)
#define 	CLR_bit(name_register,pin_bit)  name_register &= ~(1<<pin_bit)
#define 	TOG_bit(name_register,pin_bit)  name_register ^=(1<<pin_bit)
#define 	read_bit(name_register,pin_bit)  (name_register &(1<<pin_bit))>>pin_bit 
void port_init(unsigned char port_name);
void digital_input_output_setpin_direction(unsigned char port_name,unsigned char pin_number, unsigned char direction );//set direction
void digital_input_output_VWite_pin(unsigned char port_name,unsigned char pin_number, unsigned char data);
void digital_input_output_VToggle_pin(unsigned char port_name,unsigned char pin_number);
void digital_input_output_setPort_direction(unsigned char port_name,unsigned char direction);
void digital_input_output_VEnablePUR(unsigned char port_name, unsigned char pin_number);//enable PUR
unsigned char digital_input_output_U8Read_port(unsigned char port_name);
unsigned char digital_input_output_U8Read_pin(unsigned char port_name,unsigned char pin_number );
void digital_input_output_VWite_port(unsigned char port_name, unsigned char data);// use to show data (lcd)
void digital_input_output_VHighlabel(unsigned char port_name, unsigned char data); /*data=10001010		data=10100000		GPIO_PORTA_DATA_R=000000000		GPIO_PORTA_DATA_R=data=10100000		*/
void digital_input_output_Vlowlabel(unsigned char port_name, unsigned char data);//oppasite for above
void SysTick_wait(unsigned long delay);
void delay_ms(unsigned long n);
void delay_us(unsigned long n);
#endif

