#include "stm32f7xx.h"                  // Device header

#include "i2c.h"


#define SLAVE_ADDR 0x68			//1101000   ds1337

int main(void)
{
	

I2C1_init();




	
	
}

void I2C1_init(void)
{
	
	RCC->AHB1ENR |=  0x00000002;			//Enable clock for PORTB
	RCC->APB1ENR |=  0x00200000;			//Enable Clock for I2C1
	
	GPIOB->AFR[1]	&= ~0x000000FF;			//Alternate function for PB8 ,PB9
	GPIOB->AFR[1]	|=  0x00000044;
	GPIOB->MODER	&= ~0x000F0000;
	GPIOB->MODER	|=  0x000A0000;
	GPIOB->OTYPER	|=  0x00000300;			//Open Drain output
	GPIOB->PUPDR	&= ~0x000F0000;			//Pull Up registers
	GPIOB->PUPDR	|=  0x00050000;
	
	
	
	
	
	I2C1->CR1	&= ~0x00000001;			//DIsable i2c1  using PE pin
	I2C1->CR1 |=  0x00001000;			//DISABLE Analog filter with ANFOFF 1
	I2C1->TIMINGR = 0x00503D5B;			//Timming calculated with tool with 16MHz
	I2C1->CR1 |=  0x00020000;			//nostreach disable 
	I2C1->CR1	|=  0x00000001;			//ENABLE i2c1 module
	
	
}

int I2C1_byteWrite(char saddr, char maddr, char data)
{
	
	volatile int tmp;
	
	
			
	
		
}



