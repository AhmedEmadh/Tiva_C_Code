#ifndef __interrupt_H__
#define __interrupt_H__
#define PD0 (*((volatile uint32_t *)0x40007004))
void edge_counter_init(void);
void GPIOF_Handler(void);
void SW_PORTE(void);
void GPIOPortE_Handler(void);
#endif
