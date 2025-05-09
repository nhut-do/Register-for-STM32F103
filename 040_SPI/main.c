#include "RCC.h"
#include "SPI.h"
#include "GPIO.h"

char a[] = "he";
int main(void)
{
	GPIOA_Init;
	SPI1_Init;
	GPIO_Mode(GPIOA, 4, OUTPUT50, OUT_PushPull);							// Configure A4 for Output (NSS)
	GPIO_Mode(GPIOA, 5, OUTPUT50, AF_PushPull);								// Configure A5 for Output50 Alternate function	(CLK)
	GPIO_Mode(GPIOA, 6, INPUT		, PULL_UP);										// Configure A6 for Input (MISO)
	GPIO_Mode(GPIOA, 7, OUTPUT50, AF_PushPull);								// Configure A7 for Output50 Alternate function (MOSI)
	SPI1->CR1 |= (7 << 3);																		// Setting Baud rate for SPI = fPCLK/4
	SPI1->CR1 |= (1 << 0);																		// Setting CPHA = 1
	SPI1->CR1 |= (1 << 1);																		// Setting CPOL = 1
	SPI1->CR1 &= ~(1 << 7);																		// Set MSP First
	SPI1->CR1 &= ~(1 << 10);																	// Enable Full duplex
	SPI1->CR1 &= ~(1 << 11);																	// 8-bit data frame format is selected for transmission/reception
	SPI1->CR1 |= (1 << 2);																		// Chosen Master configure
	SPI1->CR1 |= (1 << 9);																		// Software slave management enabled
	SPI1->CR1 |= (1 << 8);																		// Internal slave select
	//SPI1->CR2 |= (1 << 2);
	SPI1->CR1 |= (1 << 6);																		// Enable SPI
	GPIO_Write(GPIOA, 4, HIGH);
	while(1)
	{
		for (int i = 0; i < 500000; i++) {}
		//GPIO_Write(GPIOA, 4, LOW);
		SPI1_Transmit(a, 1);
		//GPIO_Write(GPIOA, 4, HIGH);
		//while (!((SPI1->SR) & (1 << 1))) {}
		/* Wait busy flag to reset */
		//while ((SPI1->SR) & (1 << 7)) {}
		
	}
}

