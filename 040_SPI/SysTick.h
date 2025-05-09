//#include "RCC.h"

/* SysTick memory tydef layout */
typedef struct {
	volatile unsigned int CSR;						// SysTick control and status register address 0xE000E010
	volatile unsigned int RVR;						// SysTick reload value register address 0xE000E014
	volatile unsigned int CVR;						// SysTick current value register address 0xE000E018
	volatile unsigned int CALIB;					// SysTick calibration value register address 0xE000E01C
} SysTick_Type;

/* SysTick Base address */
#define SysTick_Base					(0xE000E010u)
/* SysTick Base pointer */
#define SysTick 							((SysTick_Type *)SysTick_Base)

void SysTick_Init();
void SysTick_InitEvent();