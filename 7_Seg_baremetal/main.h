#include <stdint.h>
#include "stm32f7xx.h"

#define SegA_Port GPIOC 
#define SegA_Pin  0x00000080

#define SegB_Port GPIOC 
#define SegB_Pin  0x00000040

#define SegC_Port GPIOG 
#define SegC_Pin  0x00000040

#define SegD_Port GPIOB
#define SegD_Pin  0x00000010

#define SegE_Port GPIOG
#define SegE_Pin  0x00000080

#define SegF_Port GPIOI 
#define SegF_Pin  0x00000008

#define SegG_Port GPIOH
#define SegG_Pin  0x00000040


void SegmentInit( void );
void delayms(int n);
void Display(int Digit);
void Clear (void);