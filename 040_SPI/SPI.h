//#include "RCC.h"

typedef struct {
	volatile unsigned int CR1;								/* off set 0x00 SPI control register 1 */
	volatile unsigned int CR2;								/* off set 0x04 SPI control register 2 */
	volatile unsigned int SR;									/* off set 0x08 SPI status register 2 */
	volatile unsigned int DR;									/* off set 0x0C SPI data register 2 */
	volatile unsigned int CRCPR;							/* off set 0x10 SPI CRC polynomial register */
	volatile unsigned int RXCRCR;							/* off set 0x14 SPI RX CRC register */
	volatile unsigned int TXCRCR;							/* off set 0x18 SPI TX CRC register */ 
	volatile unsigned int I2SCFGR;						/* off set 0x1C SPI_I2S configuration register */
	volatile unsigned int I2SPR;							/* off set 0x20 SPI_I2S prescaler register */
	
}SPI_Type;

/* SPI1 Base address */
#define SPI1_Base					0x40013000u
/* SPI1 Base pointer */
#define SPI1							((SPI_Type *)SPI1_Base)

/* SPI2 Base address */
#define SPI2_Base					0x40003800u
/* SPI2 Base pointer */
#define SPI2							((SPI_Type *)SPI2_Base)

/* SPI3 Base address */
#define SPI3_Base					0x40003C00u
/* SPI3 Base pointer */
#define SPI3							((SPI_Type *)SPI3_Base)

void SPI1_Transmit(char *data, unsigned int size);
