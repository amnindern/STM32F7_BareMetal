#include "stm32f7xx.h"                  // Device header
#define LedPort GPIOI
void delayms(int n);


int main(void)
{
	volatile int result = 0;
	
	RCC->AHB1ENR   |=  0X00000100;			//ENABLE CLOCK FOR PORTI
	
	LedPort->MODER &= ~0x0000000C;			// CLEAR PI1 USER LED PIN
	LedPort->MODER |=  0x00000004;			// SETTING PI1 TO OUTPUT USER LED PIN
	LedPort->MODER &= ~0x00C00000;			// SETING PI11 TO INPUT USER BUTTON PIN
	
	
	RCC->AHB1ENR |=  0x00000001;			//Enable GPIOA Clock 
	GPIOA->MODER |=  0x00000003;			//alternate function for PA0 as ADC
	
	RCC->APB2ENR |=  0x00000100;			//enable clock for ADC1
	
	ADC1->CR2 = 0;			//adc disable software triger
	ADC1->SQR3 = 0;			//conversion sequence start at ch0 as PA0
	ADC1->SQR1 = 0;			//conversion sequence length 1
	ADC1->CR2 |= 1;			//ENABLE ADC1
	
	while (1) 
		{	
			ADC1->CR2 |= 0x40000000;			//start a conversion
			while(! (ADC1->SR & 2))	{}			//wait until conversion finish
			result = ADC1->DR;		
			if(result < 2000)
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
	
	volatile int i=0;
	while( n > 0)
	{
		n--;
		for (i = 0; i < 3195; i++);
	}
}
