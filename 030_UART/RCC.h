/* Macro to init peripherals */
#define GPIOA_Init							(RCC->APB2ENR |= (1 << 2))
#define GPIOB_Init							(RCC->APB2ENR |= (1 << 3))
#define GPIOC_Init							(RCC->APB2ENR |= (1 << 4))
#define GPIOD_Init							(RCC->APB2ENR |= (1 << 5))
#define GPIOE_Init							(RCC->APB2ENR |= (1 << 6))
//#define GPIOF_Init							(RCC->APB2ENR |= (1 << 7))
//#define GPIOG_Init							(RCC->APB2ENR |= (1 << 8))
#define AFIO_Init								(RCC->APB2ENR |= (1 << 0))
#define ADC1_Init								(RCC->APB2ENR |= (1 << 9))
#define ADC2_Init								(RCC->APB2ENR |= (1 << 10))
#define TIM1_Init								(RCC->APB2ENR |= (1 << 11))
#define SPI1_Init								(RCC->APB2ENR |= (1 << 12))
#define USART1_Init							(RCC->APB2ENR |= (1 << 14))

#define TIM2_Init								(RCC->APB1ENR |= (1 << 0))
#define TIM3_Init								(RCC->APB1ENR |= (1 << 1))
#define TIM4_Init								(RCC->APB1ENR |= (1 << 2))
#define TIM5_Init								(RCC->APB1ENR |= (1 << 3))
#define TIM6_Init								(RCC->APB1ENR |= (1 << 4))
#define TIM7_Init								(RCC->APB1ENR |= (1 << 5))
#define WWDG_Init								(RCC->APB1ENR |= (1 << 11))
#define SPI2_Init								(RCC->APB1ENR |= (1 << 14))
#define SPI3_Init								(RCC->APB1ENR |= (1 << 15))
#define USART2_Init							(RCC->APB1ENR |= (1 << 17))
#define USART3_Init							(RCC->APB1ENR |= (1 << 18))
#define UART4_Init							(RCC->APB1ENR |= (1 << 19))
#define UART5_Init							(RCC->APB1ENR |= (1 << 20))
#define I2C1_Init								(RCC->APB1ENR |= (1 << 21))
#define I2C2_Init								(RCC->APB1ENR |= (1 << 22))
#define CAN1_Init								(RCC->APB1ENR |= (1 << 25))
#define CAN2_Init								(RCC->APB1ENR |= (1 << 26))
#define BKP_Init								(RCC->APB1ENR |= (1 << 27))
#define PWR_Init								(RCC->APB1ENR |= (1 << 28))
#define DAC_Init								(RCC->APB1ENR |= (1 << 29))

/** RCC - Register Layout Typedef */
typedef struct {
  volatile unsigned int CR;					//offset 00
	volatile unsigned int CFGR;				//offser 04
	volatile unsigned int CIR;				//offset 08
	volatile unsigned int APB2RSTR;		//offset 0C
	volatile unsigned int APB1RSTR;		//offset 10
	volatile unsigned int AHBENR;			//offset 14
	volatile unsigned int	APB2ENR;		//offset 18
	volatile unsigned int APB1ENR; 		//offset 1C
	volatile unsigned int BDCR;				//offset 20
	volatile unsigned int CSR;				//offset 24
} RCC_Type;
  
/** Peripheral SCG base address */
#define RCC_BASE                                 (0x40021000u)
/** Peripheral SCG base pointer */
#define RCC                                      ((RCC_Type *)RCC_BASE)