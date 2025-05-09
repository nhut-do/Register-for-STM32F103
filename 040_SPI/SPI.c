#include "SPI.h"
#include "GPIO.h"

void SPI1_Transmit(char *data, unsigned int size)
{
	unsigned int i = 0;
	while (i < size)
	{
		GPIO_Write(GPIOA, 4, LOW);
		while (!((SPI1->SR) & (1 << 1))) {}
		SPI1->DR = data[i];
		GPIO_Write(GPIOA, 4, HIGH);
		i++;
	}
	/* Wait TXE flag is set */
	while (!((SPI1->SR) & (1 << 1))) {}
	/* Wait busy flag to reset */
	while ((SPI1->SR) & (1 << 7)) {}
}

void SPI1_Recieve(char *data, unsigned int size)
{
	while (size)
	{
		while (!((SPI1->SR) & (1 << 0))) {}
		*data++ = SPI1->DR ;
		size--;
	}
	/* Wait TXE flag is set */
	while (!((SPI1->SR) & (1 << 0))) {}
	/* Wait busy flag to reset */
	while ((SPI1->SR) & (1 << 7)) {}
}
