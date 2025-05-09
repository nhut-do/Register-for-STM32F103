#include "USART.h"
#include "RCC.h"
#include "GPIO.h"



void USART_Configure(int CHANNEL, unsigned long BRR, int bit_data, float stop, int parity)
{
	int mantissa = 0, DIV = 0;
	double fraction = 0.0;
	if (CHANNEL == 1)
	{
		mantissa = 72000000/16/BRR;
		fraction = ((((72000000/16)%BRR)/(double)BRR)*16);
		if (fraction > 15) {fraction = 15;}
		DIV |= (mantissa << 4);
		DIV |= ((int)fraction << 0);
  	AFIO_Init;
  	USART1_Init;
  	GPIOA_Init;
  	GPIO_Mode(GPIOA,  9, OUTPUT50 , AF_PushPull);
  	GPIO_Mode(GPIOA, 10, INPUT		, PULL_UP    );
		USART1->BRR = DIV;
		if (bit_data == 9)
			{USART1->CR1 |= (1 << 12);}
		if (parity == 0)
			{USART1->CR1 |= (0 << 10);}
		else if (parity == Even)
			{
			USART1->CR1 |= (1 << 10);
			USART1->CR1 |= (0 << 9);
			}
		else if (parity == Odd)
			{
			USART1->CR1 |= (1 << 10);
			USART1->CR1 |= (1 << 9);
			}
		if (stop == 1)
			{USART1->CR2 |= (0 << 12);}
		else if (stop == 0.5)
			{USART1->CR2 |= (1 << 12);}
		else if (stop == 2)
			{USART1->CR2 |= (2 << 12);}
		else if (stop == 1.5)
			{USART1->CR2 |= (3 << 12);}
  	USART1->CR1 |= (1 << 2);												// Enable TX
  	USART1->CR1 |= (1 << 3);												// Enable RX
  	USART1->CR1 |= (1 << 13);												// Enable USART
	}
	else if (CHANNEL == 2)
	{
		mantissa = 36000000/16/BRR;
		fraction = ((((36000000/16)%BRR)/(double)BRR)*16);
		if (fraction > 15) {fraction = 15;}
		DIV |= (mantissa << 4);
		DIV |= ((int)fraction << 0);
  	AFIO_Init;
  	USART2_Init;
  	GPIOA_Init;
  	GPIO_Mode(GPIOA, 2, OUTPUT50, AF_PushPull);
  	GPIO_Mode(GPIOA, 3, INPUT		, PULL_UP);
		USART2->BRR = DIV;
		if (bit_data == 9)
			{USART2->CR1 |= (1 << 12);}
		if (parity == 0)
			{USART2->CR1 |= (0 << 10);}
		else if (parity == Even)
			{
			USART2->CR1 |= (1 << 10);
			USART2->CR1 |= (0 << 9);
			}
		else if (parity == Odd)
			{
			USART2->CR1 |= (1 << 10);
			USART2->CR1 |= (1 << 9);
			}
		if (stop == 1)
			{USART2->CR2 |= (0 << 12);}
		else if (stop == 0.5)
			{USART2->CR2 |= (1 << 12);}
		else if (stop == 2)
			{USART2->CR2 |= (2 << 12);}
		else if (stop == 1.5)
			{USART2->CR2 |= (3 << 12);}
  	USART2->CR1 |= (1 << 2);												// Enable TX
  	USART2->CR1 |= (1 << 3);												// Enable RX
  	USART2->CR1 |= (1 << 13);												// Enable USART
	}
	else if (CHANNEL == 3)
	{
		mantissa = 36000000/16/BRR;
		fraction = ((((36000000/16)%BRR)/(double)BRR)*16);
		if (fraction > 15) {fraction = 15;}
		DIV |= (mantissa << 4);
		DIV |= ((int)fraction << 0);
  	AFIO_Init;
  	USART3_Init;
  	GPIOB_Init;
  	GPIO_Mode(GPIOB, 10, OUTPUT50, AF_PushPull);
  	GPIO_Mode(GPIOB, 11, INPUT		, PULL_UP);
		USART3->BRR = DIV;
		if (bit_data == 9)
			{USART3->CR1 |= (1 << 12);}
		if (parity == 0)
			{USART3->CR1 |= (0 << 10);}
		else if (parity == Even)
			{
			USART3->CR1 |= (1 << 10);
			USART3->CR1 |= (0 << 9);
			}
		else if (parity == Odd)
			{
			USART3->CR1 |= (1 << 10);
			USART3->CR1 |= (1 << 9);
			}
		if (stop == 1)
			{USART3->CR2 |= (0 << 12);}
		else if (stop == 0.5)
			{USART3->CR2 |= (1 << 12);}
		else if (stop == 2)
			{USART3->CR2 |= (2 << 12);}
		else if (stop == 1.5)
			{USART3->CR2 |= (3 << 12);}
  	USART3->CR1 |= (1 << 2);												// Enable TX
  	USART3->CR1 |= (1 << 3);												// Enable RX
  	USART3->CR1 |= (1 << 13);												// Enable USART
	}
}

void USART1_Sendchar(char *data)
{
		while ((USART1->SR & (1 << 6)) == 1) 						// Check if TC bit is set
		{};
		USART1->DR = *data;
}

void USART2_Sendchar(char *data)
{
		while ((USART2->SR & (1 << 6)) == 1) 						// Check if TC bit is set
		{};
		USART2->DR = *data;
}

void USART3_Sendchar(char *data)
{
		while ((USART3->SR & (1 << 6)) == 1) 						// Check if TC bit is set
		{};
		USART3->DR = *data;
}

void USART1_SendString(char *data_String)
{
	while (*data_String != '\0') 										// Check if end string
	{
		USART1_Sendchar(data_String);
		data_String++;
		for (unsigned int i =0; i < 300; i++);
	}
}

void USART2_SendString(char *data_String)
{
	while (*data_String != '\0') 										// Check if end string
	{
		USART2_Sendchar(data_String);
		data_String++;
		for (unsigned int i =0; i < 300; i++);
	}
}

void USART3_SendString(char *data_String)
{
	while (*data_String != '\0') 										// Check if end string
	{
		USART3_Sendchar(data_String);
		data_String++;
		for (unsigned int i =0; i < 300; i++);
	}
}
