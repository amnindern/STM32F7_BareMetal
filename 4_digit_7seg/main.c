#include "main.h"








int main(void)
{
	uint8_t Digit1 = 0;
	uint8_t Digit2 = 0;
	uint8_t Digit3 = 0;
	uint8_t Digit4 = 0;
	RCC->AHB1ENR |=  0X000001C7;					//setting clock for PORTA
	
	SegmentInit();
	
	Sel1_Port->BSRR = Sel1_Pin << 16 ;
	Sel2_Port->BSRR = Sel2_Pin << 16 ;
	Sel3_Port->BSRR = Sel3_Pin << 16 ;
	Sel4_Port->BSRR = Sel4_Pin << 16 ;
	while(1)
	{
		
		for(Digit1=0; Digit1 < 10; Digit1++)
		{
			for(Digit2 = 0; Digit2 < 10; Digit2++)
			{
				for(Digit3 = 0; Digit3 < 10; Digit3++)
				{
					for(Digit4 = 0; Digit4 < 10;Digit4++)
					{
						for(int i=0 ; i<20 ; i++)
						{
							Sel1_Port->BSRR = Sel1_Pin ;
							Display(Digit4);
							delayms(1);
							Clear();
							Sel1_Port->BSRR = Sel1_Pin << 16 ;
							Sel2_Port->BSRR = Sel2_Pin ;
							Display(Digit3);
							delayms(1);
							Clear();
							Sel2_Port->BSRR = Sel2_Pin << 16 ;
							Sel3_Port->BSRR = Sel3_Pin ;
							Display(Digit2);
							delayms(1);
							Clear();
							Sel3_Port->BSRR = Sel3_Pin << 16 ;
							Sel4_Port->BSRR = Sel4_Pin ;
							Display(Digit1);
							delayms(1);
							Clear();
							Sel4_Port->BSRR = Sel4_Pin << 16 ;
						}
					}
				}
			}
		}
	}
		
}








void SegmentInit()
{
	
	GPIOA->MODER &= ~0xC0000000;						
	GPIOA->MODER |=  0x40000000;					
	GPIOB->MODER &= ~0xF0000300;    		  
	GPIOB->MODER |=  0x50000100;				
	GPIOC->MODER &= ~0x0000F000;
	GPIOC->MODER |=  0x00005000;
	GPIOG->MODER &= ~0x0000F000;
	GPIOG->MODER |=  0x00005000;
	GPIOH->MODER &= ~0x00003000;
	GPIOH->MODER |=  0x00001000;
	GPIOI->MODER &= ~0x000000F0;
	GPIOI->MODER |=  0x00000050;
	
	
}
	
void Display(volatile int Digit)
{
	switch(Digit)
	{
		case 0:
		{ 
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegE_Port->BSRR = SegE_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			break ;
		}
		case 1:
		{
			
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			break ;
			
		}
		case 2:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegE_Port->BSRR = SegE_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 3:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 4:
		{
			
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 5:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 6:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegE_Port->BSRR = SegE_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 7:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			break;
		}
		case 8:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegD_Port->BSRR = SegD_Pin ;
			SegE_Port->BSRR = SegE_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
		case 9:
		{
			SegA_Port->BSRR = SegA_Pin ;
			SegB_Port->BSRR = SegB_Pin ;
			SegC_Port->BSRR = SegC_Pin ;
			SegF_Port->BSRR = SegF_Pin ;
			SegG_Port->BSRR = SegG_Pin ;
			break;
		}
	}
	
}

void Clear (void )
{
	SegA_Port->BSRR = SegA_Pin << 16 ;
	SegB_Port->BSRR = SegB_Pin << 16 ;
	SegC_Port->BSRR = SegC_Pin << 16 ;
	SegD_Port->BSRR = SegD_Pin << 16 ;
	SegE_Port->BSRR = SegE_Pin << 16 ;
	SegF_Port->BSRR = SegF_Pin << 16 ;
	SegG_Port->BSRR = SegG_Pin << 16 ;
}


void delayms(int n)
{
	
	int i=0;
	SysTick->LOAD = 16000;
	SysTick->VAL  = 0;
	SysTick->CTRL = 0x5;
	
	
	for (i = 0; i < n; i++)
		{
			while( (SysTick->CTRL & 0x10000) == 0)
			{}
		}
	SysTick->CTRL = 0;
}

