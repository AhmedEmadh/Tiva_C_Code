#include "tm4c123gh6pm.h"
#include "digital_input_output.h"
#include <stdint.h>
void port_init(unsigned char port_name){ //init port
 switch(port_name)
 {
	case 'a':
	case 'A':
	{
			set_bit( SYSCTL_RCGCGPIO_R,0);
			while ((read_bit(SYSCTL_PRGPIO_R,0))==0 );
			GPIO_PORTA_LOCK_R=0X4C4F434B;
	    GPIO_PORTA_CR_R=0XFF;
	    GPIO_PORTA_DEN_R =0XFF;
	}
	break;
	case 'B':
	case 'b':
	{
			set_bit( SYSCTL_RCGCGPIO_R,1);
			while ((read_bit(SYSCTL_PRGPIO_R,1))==0 );
			GPIO_PORTB_LOCK_R=0X4C4F434B;
	    GPIO_PORTB_CR_R=0XFF;
	    GPIO_PORTB_DEN_R =0XFF;
	}
	break;
	case 'C':
	case 'c':
	{
			set_bit( SYSCTL_RCGCGPIO_R,2);
			while ((read_bit(SYSCTL_PRGPIO_R,2))==0 );
			GPIO_PORTC_LOCK_R=0X4C4F434B;
	    GPIO_PORTC_CR_R=0XFF;
	    GPIO_PORTC_DEN_R =0XFF;
	}
	break;
	case 'D':
	case 'd':
	{
			set_bit( SYSCTL_RCGCGPIO_R,3);
			while ((read_bit(SYSCTL_PRGPIO_R,3))==0 );
			GPIO_PORTD_LOCK_R=0X4C4F434B;
	    GPIO_PORTD_CR_R=0XFF;
	    GPIO_PORTD_DEN_R =0XFF;
	}
	break;
	case 'e':
	case 'E':
	{
			set_bit( SYSCTL_RCGCGPIO_R,4);
			while ((read_bit(SYSCTL_PRGPIO_R,4))==0 );
			GPIO_PORTE_LOCK_R=0X4C4F434B;
	    GPIO_PORTE_CR_R=0XFF;
	    GPIO_PORTE_DEN_R =0XFF;
	}
	break;
	case 'f':
	case 'F':
	{
			set_bit( SYSCTL_RCGCGPIO_R,5);
			while ((read_bit(SYSCTL_PRGPIO_R,5))==0 );
			GPIO_PORTF_LOCK_R=0X4C4F434B;
	    GPIO_PORTF_CR_R=0XFF;
	    GPIO_PORTF_DEN_R =0X1F;		
	}		
	break;
 }
}
void digital_input_output_setpin_direction(unsigned char port_name,unsigned char pin_number, unsigned char direction ){//set direction
switch(port_name)
{
	case 'a':
	case 'A':
	{
	  if(direction==1)//I want set direction 
			set_bit(GPIO_PORTA_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTA_DIR_R,pin_number);
			
	}
	break;
	case 'b':
	case 'B':
	{
	  if(direction==1)//I want set data 
			set_bit(GPIO_PORTB_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTB_DIR_R,pin_number);
	}	
	break;
	case 'C':
	case 'c':
	{
	  if(direction==1)//I want set data 
			set_bit(GPIO_PORTC_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTC_DIR_R,pin_number);
			
	}	
	break;
	case 'd':
	case 'D':
	{
	  if(direction==1)//I want set data 
			set_bit(GPIO_PORTD_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTD_DIR_R,pin_number);
			
	}	
	break;
	case 'E':
	case 'e':
	{
	  if(direction==1)//I want set data 
			set_bit(GPIO_PORTE_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTE_DIR_R,pin_number);
			
	}	
	break;
	case 'F':
	case 'f':
	{
	  if(direction==1)//I want set data 
			set_bit(GPIO_PORTF_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTF_DIR_R,pin_number);		
	}
	break;
}
}

void digital_input_output_VWite_pin(unsigned char port_name,unsigned char pin_number, unsigned char data)
{
	switch(port_name){
	case 'a':
	case 'A':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTA_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTA_DIR_R,pin_number);
			
	}
	break;
	case 'b':
	case 'B':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTB_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTB_DIR_R,pin_number);
			
	}	
	break;
	case 'C':
	case 'c':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTC_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTC_DIR_R,pin_number);
			
	}	
	break;
	case 'd':
	case 'D':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTD_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTD_DIR_R,pin_number);
			
	}	
	break;
	case 'E':
	case 'e':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTE_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTE_DIR_R,pin_number);
			
	}	
	break;
	case 'F':
	case 'f':
	{
	  if(data==1)//I want set data 
			set_bit(GPIO_PORTF_DIR_R,pin_number);
		else 
			CLR_bit(GPIO_PORTF_DIR_R,pin_number);
	}
	break;
}
}
void digital_input_output_VToggle_pin(unsigned char port_name,unsigned char pin_number)
{
		switch(port_name){
	case 'a':
	case 'A':
	{ 
			TOG_bit(GPIO_PORTA_DIR_R,pin_number);
	}
	break;
	case 'b':
	case 'B':
	{
			TOG_bit(GPIO_PORTB_DIR_R,pin_number);
	}	
	break;
	case 'C':
	case 'c':
	{
			TOG_bit(GPIO_PORTC_DIR_R,pin_number);
	}	
	break;
	case 'd':
	case 'D':
	{
			TOG_bit(GPIO_PORTD_DIR_R,pin_number);
	}	
	break;
	case 'E':
	case 'e':
	{
			TOG_bit(GPIO_PORTE_DIR_R,pin_number);
	}	
	break;
	case 'F':
	case 'f':
	{
			TOG_bit(GPIO_PORTF_DIR_R,pin_number);
	}
	break;
}
}
void digital_input_output_setPort_direction(unsigned char port_name,unsigned char direction)
{
	switch(port_name)
	{
	case 'a':
	case 'A':
	{
			GPIO_PORTA_DIR_R=direction;
	}
	break;
	case 'B':
	case 'b':
	{
			GPIO_PORTB_DIR_R=direction;
	}
	break;
	case 'C':
	case 'c':
	{
			GPIO_PORTC_DIR_R=direction;
	}
	break;
	case 'D':
	case 'd':
	{
			GPIO_PORTD_DIR_R=direction;
	}
	break;
	case 'E':
	case 'e':
	{
			GPIO_PORTE_DIR_R=direction;
	}
	break;
	case 'f':
	case 'F':
	{
			GPIO_PORTF_DIR_R=direction;
	}
	break;
}
}
void digital_input_output_VWite_port(unsigned char port_name, unsigned char data)
{ // use to show data (lcd)
switch(port_name){
	case 'a':
	case 'A':
	{
			GPIO_PORTA_DATA_R=data;
	}
	break;
	case 'B':
	case 'b':
	{
			GPIO_PORTB_DATA_R=data;
	}
	break;
	case 'C':
	case 'c':
	{
			GPIO_PORTC_DATA_R=data;
	}
	break;
	case 'D':
	case 'd':
	{
			GPIO_PORTD_DATA_R=data;
	}
	break;
	case 'E':
	case 'e':
	{
			GPIO_PORTE_DATA_R=data;
	}
	break;
	break;
	case 'f':
	case 'F':
	{
			GPIO_PORTF_DATA_R=data;
	}
	break;
}
}
unsigned char digital_input_output_U8Read_pin(unsigned char port_name,unsigned char pin_number )
{
		switch(port_name)
{
	case 'a':
	case 'A':
	{
		return	read_bit(	GPIO_PORTA_DATA_R,pin_number);
	}
	break;
	case 'B':
	case 'b':
	{
		return	read_bit(	GPIO_PORTB_DATA_R,pin_number);
	}	
	break;
	case 'C':
	case 'c':
	{
		return	read_bit(	GPIO_PORTC_DATA_R,pin_number);
	}	
	break;
	case 'D':
	case 'd':
	{
		return	read_bit(	GPIO_PORTD_DATA_R,pin_number);
	}	
	break;
	case 'e':
	case 'E':
	{
		return	read_bit(	GPIO_PORTE_DATA_R,pin_number);
	}	
	break;
	case 'F':
	case 'f':
	{
		return	read_bit(	GPIO_PORTF_DATA_R,pin_number);
	}
	break;
}
}
unsigned char digital_input_output_U8Read_port(unsigned char port_name)
{
		switch(port_name)
{
	case 'a':
	case 'A':
	{
	return GPIO_PORTA_DATA_R ;
	}
	break;
	case 'B':
	case 'b':
	{
	return 	GPIO_PORTB_DATA_R;
	}	
	break;
	case 'C':
	case 'c':
	{
		return GPIO_PORTC_DATA_R ;
	}	
	break;
	case 'D':
	case 'd':
	{
		return GPIO_PORTD_DATA_R;
	}	
	break;
	case 'e':
	case 'E':
	{
	return	GPIO_PORTE_DATA_R;
	}	
	break;
	case 'F':
	case 'f':

		return		GPIO_PORTF_DATA_R;
	  break;
}
}
void digital_input_output_VEnablePUR(unsigned char port_name, unsigned char pin_number)
{ //enable pur
		switch(port_name)
		{
			case'a':
			case'A':
			{
							set_bit(GPIO_PORTA_PUR_R,pin_number);
			}
			break;
			
			case'b':
			case'B':
			{
							set_bit(GPIO_PORTB_PUR_R,pin_number);
			}
			break;
		  case'C':
			case'c':
			{
							set_bit(GPIO_PORTC_PUR_R,pin_number);
			}
			break;
			case'D':
			case'd':
			{
							set_bit(GPIO_PORTD_PUR_R,pin_number);
			}
			break;
			case'E':
			case'e':
			{
							set_bit(GPIO_PORTE_PUR_R,pin_number);
			}
			break;
			case'F':
			case'f':
			{
							set_bit(GPIO_PORTF_PUR_R,pin_number);
			}
			break;
		}
}
void digital_input_output_VHighlabel(unsigned char port_name, unsigned char data)
{
	data<<=4;
		switch(port_name)
		{
			case'a':
			case'A':
			{
				GPIO_PORTA_DATA_R&=0x0f;
				GPIO_PORTA_DATA_R|=data;
			}
			break;
			case'B':
			case'b':
			{
				GPIO_PORTB_DATA_R&=0x0f;
				GPIO_PORTB_DATA_R|=data;
			}
			break;
			case'C':
			case'c':
			{
				GPIO_PORTC_DATA_R&=0x0f;
				GPIO_PORTC_DATA_R|=data;
			}
			break;
			case'D':
			case'd':
			{
				GPIO_PORTD_DATA_R&=0x0f;
				GPIO_PORTD_DATA_R|=data;
			}
			break;
			case'E':
			case'e':
			{
				GPIO_PORTE_DATA_R&=0x0f;
				GPIO_PORTE_DATA_R|=data;
			}
			break;
			case'F':
			case'f':
			{
				GPIO_PORTF_DATA_R&=0x0f;
				GPIO_PORTF_DATA_R|=data;
			}
			break;			
		}	
}
void digital_input_output_Vlowlabel(unsigned char port_name, unsigned char data)
{
		switch(port_name)
		{
			case'a':
			case'A':
			{
				GPIO_PORTA_DATA_R&=0xf0;
				GPIO_PORTA_DATA_R|=data;
			}
			break;
			
			case'B':
			case'b':
			{
				GPIO_PORTB_DATA_R&=0xf0;
				GPIO_PORTB_DATA_R|=data;
			}
			break;
			case'C' :
			case'c' :
			{
				GPIO_PORTC_DATA_R&=0xf0;
				GPIO_PORTC_DATA_R|=data;
			}
			break;
			case'D':
			case'd':
			{
				GPIO_PORTD_DATA_R&=0xf0;
				GPIO_PORTD_DATA_R|=data;
			}
			break;
			case'E':
			case'e':
			{
				GPIO_PORTE_DATA_R&=0xf0;
				GPIO_PORTE_DATA_R|=data;
			}
			break;
			case'F':
			case'f':
			{
				GPIO_PORTF_DATA_R&=0xf0;
				GPIO_PORTF_DATA_R|=data;
			}
			break;				
		}	
}


