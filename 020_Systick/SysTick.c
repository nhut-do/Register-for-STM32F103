#include "SysTick.h"

void SysTick_Init()
{
	SysTick->CSR = 0;
	SysTick->CVR = 0;
	SysTick->RVR = 0x00ffffff;
	SysTick->CSR = 5;
}
void SysTick_InitEvent()
{
	SysTick->CSR |= (1 << 1);
}
