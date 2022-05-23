#include "tm4c123gh6pm.h"
#include "functions.h"
#include "stdint.h"
#include "interrupt.h"
#include "SYSTICK.h"
#include "Delay.h"

void edge_counter_init(void)
{
   SYSCTL_RCGCGPIO_R |= 0x20;            //enable clc for port f
  while ((SYSCTL_RCGCGPIO_R&0x20)==0){};
	GPIO_PORTF_DIR_R&=~0X10;
  GPIO_PORTF_DEN_R |=0X10;
	GPIO_PORTF_PUR_R|=0X10;
	GPIO_PORTF_IS_R&=~0X10;
	GPIO_PORTF_IBE_R&=~0X10;
	GPIO_PORTF_IEV_R&=~0X10;
	//GPIO_PORTF_ICR_R=0X10;
	GPIO_PORTF_IM_R|=0X10;
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
	NVIC_EN0_R = 0x40000000; 
		__enable_irq();
}

void SW_PORTE(void){
		SYSCTL_RCGCGPIO_R |= 0x10; // activate port E
	while ((SYSCTL_RCGCGPIO_R&0x10)==0){};
	GPIO_PORTE_DIR_R&=~0X01;
  GPIO_PORTE_DEN_R |=0X01;
	GPIO_PORTE_PUR_R|=0X01;
	GPIO_PORTE_IS_R&=~0X01;
	GPIO_PORTE_IBE_R&=~0X01;
	GPIO_PORTE_IEV_R&=~0X01;
	GPIO_PORTE_IM_R|=0X01;
	NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF00)|0x00000040; // priority 2
	NVIC_EN0_R = 0x00000010; // enable interrupt 4 in NVIC
		__enable_irq();
}

void GPIOF_Handler(void)
{
  GPIO_PORTF_ICR_R = 0x10;
	        delayMs(6000);
	while(GPIO_PORTF_DATA_R==0X01){
		    lcd_clear();
		    lcd_print_str("please press rest");
        delayMs(4000);
        lcd_clear();
	}
	while(GPIO_PORTF_DATA_R==0X10)//sw2 pressed 
  {
		break;
	}
	
	

}
void GPIOE_Handler(void){

	  GPIO_PORTF_ICR_R = 0x01;
	  lcd_clear();
    lcd_print_str("pleaseCLOSEDoor ");
	        delayMs(4000);
	while(((GPIO_PORTE_DATA_R<<7)>>7)==0X01)
		{
      break;
	}

}
