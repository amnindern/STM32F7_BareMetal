#include <stdint.h>
#include "stm32f7xx.h"


#define LedPort GPIOI


void delayms(int n);

int main(void)
{
	RCC->AHB1ENR |= 0X00000100;
	
	LedPort->MODER &= ~0x0000000C;
	LedPort->MODER |=  0x00000004;			// SETTING PI1 TO OUTPUT
	LedPort->MODER &= ~0x00C00000;     // SETING PI11 TO INPUT
	
	
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



void delayms(int n){
	
	volatile int i=0;
	while( n > 0)
	{
		n--;
		for (i = 0; i < 3195; i++);
	}
}



