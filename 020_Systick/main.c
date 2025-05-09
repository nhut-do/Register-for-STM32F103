#include "GPIO.h"
#include "RCC.h" 
#include "EXTI.h" 
#include "NVIC.h"
#include "SysTick.h"
//#include "stm32f10x.h"                  // Device header



int count, SysTickCount;
void DelayMillis();
void DelayMs(unsigned long t);
int main()
{
	GPIOA_Init;
	GPIOC_Init;
	AFIO_Init;
	SysTick_Init();
	SysTick_InitEvent();
	RCC->APB2ENR |= (1 << 14);
	
	/* Set Mode for GPIO */
	GPIO_Mode( GPIOC, 13, OUTPUT50, OUT_PushPull);
	GPIO_Mode( GPIOA,  0, INPUT		, PULL_UP			);
	
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
		DelayMs(1000);
		GPIO_Write(GPIOC, 13, LOW);
		DelayMs(1000);
		}
		else {GPIO_Write(GPIOC, 13, LOW); GPIO_Write(GPIOC, 13, LOW);}
	}
}

void DelayMillis()
{
	SysTick->RVR = 71999;												// Set Reload value for one cycle
	SysTick->CVR = 0;														// Set current value is 0
	while ((SysTick->CSR & (1 << 16)) == 0); 		// Wait unstil countdow to zero and flag ON
}
void DelayMs(unsigned long t)
{
	for ( ;t > 0; t--)
	{DelayMillis();}
}

void EXTI0_IRQHandler()
{
	
	if (EXTI->PR & (1 << 0)) 										// Check if Pending bits is set
	{
		DelayMs(2);
		EXTI->PR |= (1 << 0);											// Clear Pending bits
		count++;
	}
}
void SysTick_Handler(void)
{
	SysTickCount++;
}