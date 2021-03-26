//TOGLING LED USING USER BUTTON WITH INTERUPT




#include "stm32f7xx.h"                  // Device header
#include <stdint.h>

#define LedPort GPIOI

void delayms(int n);

int main(void)
{
	__disable_irq();
	RCC->AHB1ENR   |=  0X00000100;			//ENABLE CLOCK FOR PORTI
	
	LedPort->MODER &= ~0x0000000C;			// CLEAR PI1 USER LED PIN
	LedPort->MODER |=  0x00000004;			// SETTING PI1 TO OUTPUT USER LED PIN
	LedPort->MODER &= ~0x00C00000;			// SETING PI11 TO INPUT USER BUTTON PIN
	RCC->APB2ENR   |=  0x00004000;			// ENABLE SYSCFG
	
	SYSCFG->EXTICR[2] |= 0X00008000;			//SELECT PORTI FOR EXTI11
	EXTI->IMR		|= 0X00000800;			//MASK INTERUPT FOR EXTI11
	EXTI->FTSR	|= 0X00000800;			//FALLING EDGE TRIGER ON
	
	NVIC_EnableIRQ(EXTI15_10_IRQn);			//ENABLE EXTERNAL INTERUPT THROUGH 10-15
	__enable_irq();
	while(1){
		delayms(100);
	}
}

/* INTERRUPT ROUTINE
*
*
*/
void EXTI15_10_IRQ_Handler(void)
{
	LedPort->ODR ^= 0x00000002;
	delayms(1);	
	EXTI->PR |= 0X00000800 ;
	
}
/*
*
*
*/


void delayms(int n)
{
	
	uint32_t i=0;
	SysTick->LOAD = 16000;			//Number of clock per millisecond with 16MHz sys clock
	SysTick->VAL  = 0;			//clear current value register 
	SysTick->CTRL = 0x5;			//enable timer
	
	
	for (i = 0; i < n; i++)
		{
			while( (SysTick->CTRL & 0x10000) == 0)			//wait until COUNTFLAG is set
			{}
		}
	SysTick->CTRL = 0;			//stop the timer
}

