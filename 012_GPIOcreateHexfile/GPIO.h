
/* GPIO memory tydef layout */
typedef struct {
  volatile unsigned int CRL;					//offset 00
	volatile unsigned int CRH;					//offser 04
	volatile unsigned int IDR;					//offset 08
	volatile unsigned int ODR;					//offset 0C
	volatile unsigned int BSRR;					//offset 10
	volatile unsigned int BRR;					//offset 14
	volatile unsigned int	LCKR;					//offset 18
}GPIO_Type;

/* GPIOA base adddresss */
#define GPIOA_BASE  (0x40010800u)
/* GPIOA base pointer */
#define GPIOA		((GPIO_Type *)GPIOA_BASE)

/* GPIOC base adddresss */
#define GPIOC_BASE  (0x40011000u)
/* GPIOC base pointer */
#define GPIOC		((GPIO_Type *)GPIOC_BASE)


