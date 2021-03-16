#include "main.h"










int main(void)
{
	int i=0;
	RCC->AHB1ENR |=  0X000001C7;					//setting clock for PORTA
	
	SegmentInit();
	
	
	while(1)
	{
		
		for(i=0; i<10; i++)
		{
			
				Display(i);
				delayms(200);
		
				Clear();
				delayms(200);
		}
		
	}

}






void SegmentInit()
{
	
	GPIOA->MODER &= ~0x00030000;
	GPIOA->MODER |=  0x00010000;					
	GPIOB->MODER &= ~0x00000300;    		  
	GPIOB->MODER |=  0x00000100;				
	GPIOC->MODER &= ~0x0000F000;
	GPIOC->MODER |=  0x00005000;
	GPIOG->MODER &= ~0x0000F000;
	GPIOG->MODER |=  0x00005000;
	GPIOH->MODER &= ~0x00003000;
	GPIOH->MODER |=  0x00001000;
	GPIOI->MODER &= ~0x000000C0;
	GPIOI->MODER |=  0x00000040;
	
	
}
	
void Display(int Digit)
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
	
	volatile int i=0;
	while( n > 0)
	{
		n--;
		for (i = 0; i < 3195; i++);
	}
}



