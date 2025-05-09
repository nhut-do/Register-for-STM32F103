#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "USART.h"
#include <stdint.h>
#include <string.h>
//#include "stm32f10x.h"                  // Device header

char RXbuffer[32];
char data = 'A';
volatile unsigned char RXindex = 0;
void ResetBuffer(char str[]);
int FindString(char str[], char strx[]);
int main()
{
	
	USART_Configure(USART_CH1, 115200, 8, 1, No);
	USART1_EnableInterrupt();
	while(1)
	{
		/* Recieve data */
		//while ((USART1->SR & (1 << 5)) == 0) 				// Check if RXNE bit is set
		//{};	
		//data = USART1->DR;
		//for (unsigned long i =0; i < 50000; i++);
		/* Transmit Data */
		USART1_SendString(RXbuffer);
		if (RXbuffer[0] != '\0')
		{
			if (FindString(RXbuffer, "h"))
			{
				USART1_SendString(" Respons ");
			}
		}
//		memset(RXbuffer, '\0', strlen(RXbuffer));       // Reset string
//		RXindex = 0;
		ResetBuffer(RXbuffer);
		for (unsigned long i =0; i < 500; i++){};
	}
}

void USART1_IRQHandler()
{
	USART1->SR &= ~(1 << 5);													// Clear flag
	RXbuffer[RXindex++] = USART1->DR;									// Read data from DR register
}
void USART2_IRQHandler()
{
	USART2->SR &= ~(1 << 5);													// Clear flag
	RXbuffer[RXindex++] = USART2->DR;									// Read data from DR register
}
void USART3_IRQHandler()
{
	USART3->SR &= ~(1 << 5);													// Clear flag
	RXbuffer[RXindex++] = USART3->DR;									// Read data from DR register	
}

void ResetBuffer(char str[])
{
	memset(str, '\0', strlen(str));  
	RXindex = 0;
}

int FindString(char str[], char strx[])
{
	for (unsigned int i=0; i <= strlen(str); i++)
	{
		if (str[i] == strx[0])
		{
			unsigned int test = 1;
			for (unsigned int j=1; j<= (strlen(strx)-1); j++)
			{
				if (str[i+j] != strx[j])
				{test = 0; break;}
			}
			if (test) return 1;
		}
	}
	return 0;
}
	