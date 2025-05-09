#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "USART.h"


char data = 'a';
int main()
{
//  	AFIO_Init;
//  	USART2_Init;
//  	GPIOA_Init;
//  	GPIO_Mode(GPIOA, 2, OUTPUT50, AF_PushPull);
//  	GPIO_Mode(GPIOA, 3, INPUT		, PULL_UP);
//  	USART2->BRR = 0xEA6;														// Set baurate is 9600 (SysCLK = 36Mhz)
//		//USART2->BRR |= (mantissa << 4);
//		//USART2->BRR |= ((int)fraction << 0);
//  	USART2->CR1 |= (1 << 2);												// Enable TX
//  	USART2->CR1 |= (1 << 3);												// Enable RX
//  	USART2->CR1 |= (1 << 13);												// Enable USART
	USART_Configure(USART_CH3, 115200, 8, 1, No);
	while(1)
	{
		/* Recieve data */
		//while ((USART1->SR & (1 << 5)) == 0) 				// Check if RXNE bit is set
		//{};	
		//data = USART1->DR;
		//for (unsigned long i =0; i < 50000; i++);
		/* Transmit Data */
		USART3_SendString("hello Cong Chua Bong Bong <3 !                        ");
		for (unsigned long i =0; i < 500000; i++){};
	}
}