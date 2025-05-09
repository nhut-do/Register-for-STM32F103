#define USART_CH1					1
#define USART_CH2					2
#define USART_CH3 				3

#define No								0
#define Even							1
#define Odd								2

/* USART struct memory */
typedef struct {
		volatile unsigned int SR;								// Status register offset 0x00 
		volatile unsigned int DR;								// Data register offset 0x04
		volatile unsigned int BRR;							// Baud rate register offset 0x08
		volatile unsigned int CR1;							// Control register 1 offset 0x0C
		volatile unsigned int CR2;							// Control register 2 offset 0x10
		volatile unsigned int CR3;							// Control register 3 offset 0x14
		volatile unsigned int GTPR;							// Guard time and prescaler registeroffset 0x18
}UART_Type;

/* USART Base address */
#define USART1_Base		(0x40013800u)
/* USART Base pointer */
#define USART1 				((UART_Type *)USART1_Base)

/* USART Base address */
#define USART2_Base		(0x40004400u)
/* USART Base pointer */
#define USART2 				((UART_Type *)USART2_Base)

/* USART Base address */
#define USART3_Base		(0x40004800u)
/* USART Base pointer */
#define USART3 				((UART_Type *)USART3_Base)

/* UART Base address */
#define UART4_Base		(0x40004C00u)
/* UART Base pointer */
#define UART4 				((UART_Type *)UART4_Base)

/* UART Base address */
#define UART5_Base		(0x40005000u)
/* UART Base pointer */
#define UART5 				((UART_Type *)UART5_Base)

void USART_Configure(int CHANNEL, unsigned long BRR, int bit_data, float stop, int parity);
void USART1_Sendchar(char *data);
void USART2_Sendchar(char *data);
void USART3_Sendchar(char *data);
void USART1_SendString(char *data_String);
void USART2_SendString(char *data_String);
void USART3_SendString(char *data_String);
void USART1_EnableInterrupt(void);
void USART2_EnableInterrupt(void);
void USART3_EnableInterrupt(void);