#ifndef __led_H__
#define __led_H__
#include "digital_input_output.h"
void led_init(unsigned char port_name,unsigned char pin_number);
void led_on(unsigned char port_name,unsigned char pin_number);
void led_off(unsigned char port_name,unsigned char pin_number);
void Led_TOG_bit(unsigned char port_name,unsigned char pin_number);
#endif


