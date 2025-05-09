#include "GPIO.h"
#include "RCC.h"                



void delay(int a);
void GPIOA_init();
void GPIOC_init();
int main()
{
	//RCC->APB2ENR |= 0x00000014 ; // Enable port A, C
	//RCC->APB2ENR |= 0x00000014 ;
	GPIOA_init();
	GPIOC_init();
	GPIOC->CRH &= 0xFF0FFFFF; // Reset bits for GPIOC Pin 13
	GPIOC->CRH |= 0x00300000; // Set Output, Push-pull, Max speed 50MHz
	GPIOA->CRL &= 0xFFFFFFF0;
	GPIOA->CRL |= 0x00000008;
	while(1)
	{
		if (GPIOA->IDR & 0x1)
			{
			GPIOC->ODR &= ~0x2000;
			delay(1);
			}
		else
			{
			GPIOC->ODR |= 0x2000;
			delay(1);
			}
	}
}

void delay(int a)
{
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < 100000; j++)
		{}
	}
}
