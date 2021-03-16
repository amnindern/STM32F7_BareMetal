#include <stdint.h>
#include "stm32f7xx.h"


#define LedPort GPIOI


void delayms(int n);

int main(void)
{
	RCC->AHB1ENR   |=  0X00000100;			//ENABLE CLOCK FOR PORTI
	
	LedPort->MODER &= ~0x0000000C;			// CLEAR PI1 USER LED PIN
	LedPort->MODER |=  0x00000004;			// SETTING PI1 TO OUTPUT USER LED PIN
	LedPort->MODER &= ~0x00C00000;			// SETING PI11 TO INPUT USER BUTTON PIN
	
	
	while(1)
	{
		
		if(LedPort->IDR & 0x00000800)
			{
				LedPort->BSRR = 0x00000002;
				delayms(5);
			}
		else
			{
				LedPort->BSRR = (0x00000002 << 16);
				delayms(5);
			}
		
	}

}



void delayms(int n)
{
	
	int i=0;
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


