#include "GPIO.h"
#include "RCC.h"

void GPIOA_init()
{
	RCC->APB2ENR |= 0x00000004;
}

void GPIOB_init()
{
	RCC->APB2ENR |= 0x00000008;
}

void GPIOC_init()
{
	RCC->APB2ENR |= 0x00000010;
}

void GPIOD_init()
{
	RCC->APB2ENR |= 0x00000020;
}

void GPIOE_init()
{
	RCC->APB2ENR |= 0x00000040;
}

void GPIOF_init()
{
	RCC->APB2ENR |= 0x00000080;
}

void GPIOG_init()
{
	RCC->APB2ENR |= 0x00000100;
}


