#include "D:\EE319Kware\InputOutput_4C123\key\digital_input_output.h"
#include "D:\EE319Kware\InputOutput_4C123\key\led.h"
void led_init(unsigned char port_name,unsigned char pin_number)
{
		void port_init(unsigned char port_name)
		void digital_input_output_setpin_direction(port_name,pin_number, 0 )
}
void led_on(unsigned char port_name,unsigned char pin_number)
{
	void digital_input_output_VWite_pin(port_name,pin_number,1 )
}

void led_off(unsigned char port_name,unsigned char pin_number)
{
	void digital_input_output_VWite_pin(port_name,pin_number,0 )
}
void Led_TOG_bit(unsigned char port_name,unsigned char pin_number)
{
	void digital_input_output_VToggle_pin( port_name,pin_number);
}