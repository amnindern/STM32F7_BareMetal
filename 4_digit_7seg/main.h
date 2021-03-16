#include <stdint.h>
#include "stm32f7xx.h"


#define Sel1_Port GPIOI
#define Sel1_Pin  0x00000004

#define Sel2_Port GPIOA
#define Sel2_Pin  0x00008000

#define Sel3_Port GPIOB
#define Sel3_Pin  0x00008000

#define Sel4_Port GPIOB
#define Sel4_Pin  0x00004000

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
void Display(volatile int Digit);
void Clear (void);