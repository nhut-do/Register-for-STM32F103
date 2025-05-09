#include "GPIO.h"
#include "RCC.h" 
#include "EXTI.h" 
#include "NVIC.h"
//#include "stm32f10x.h"                  // Device header



int count;
void delay(int a);
int main()
{
	GPIOA_Init;
	GPIOC_Init;
	AFIO_Init;
	RCC->APB2ENR |= (1 << 14);
	
	/* Set Mode for GPIO */
	GPIO_Mode( GPIOC, 13, OUTPUT50, OUT_PushPull);
	GPIO_Mode( GPIOA, 0, INPUT, PULL_UP);
	
	/* Select sorce for EXTI */
	AFIO->EXTICR1 &= ~(0xf << 0);								// Select source Input A0 for EXTI0
	
	/* configure EXTI */
	EXTI->IMR  |= (1 << 0);											// Clear masked interrupt from line 0
	EXTI->FTSR |= (1 << 0);											// Enable failing trigger 
	EXTI->RTSR &= ~(1 << 0);										// Disable rising trigger 
	
	/* Enable IRQ */
	NVIC->ISER[0] |=  (1 << 6);									// Enable IRQ6 is EXTI0
	while(1)
	{
		if ((count % 2) == 0)
		{
		GPIO_Write(GPIOC, 13, HIGH);
		}
		else GPIO_Write(GPIOC, 13, LOW);
	}
}

void delay(int a)
{
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < 100000; j++)
		{}
	}
}

void EXTI0_IRQHandler()
{
	if (EXTI->PR & (1 << 0)) 
	{
		delay(1);
		EXTI->PR |= (1 << 0);
		count++;
	}
}