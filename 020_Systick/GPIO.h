#define INPUT												0
#define OUTPUT10 										1
#define OUTPUT2 										2
#define OUTPUT50										3
			
#define OUT_PushPull								0
#define OUT_OpenDrain								1
#define AF_PushPull									2
#define AF_OpenDrain								3
			
#define ANALOG											0
#define FLOATING										1
#define PULL_UP											2
			
#define HIGH												1
#define LOW													0


/* Macro to init GPIO */
#define GPIOA_Init							(RCC->APB2ENR |= (1 << 2))
#define GPIOB_Init							(RCC->APB2ENR |= (1 << 3))
#define GPIOC_Init							(RCC->APB2ENR |= (1 << 4))
#define GPIOD_Init							(RCC->APB2ENR |= (1 << 5))
#define GPIOE_Init							(RCC->APB2ENR |= (1 << 6))
#define GPIOF_Init							(RCC->APB2ENR |= (1 << 7))
#define GPIOG_Init							(RCC->APB2ENR |= (1 << 8))
#define AFIO_Init								(RCC->APB2ENR |= (1 << 0))

/* GPIO memory tydef layout */
typedef struct {
  volatile unsigned int CRL;					//offset 0x00
	volatile unsigned int CRH;					//offser 0x04
	volatile unsigned int IDR;					//offset 0x08
	volatile unsigned int ODR;					//offset 0x0C
	volatile unsigned int BSRR;					//offset 0x10
	volatile unsigned int BRR;					//offset 0x14
	volatile unsigned int	LCKR;					//offset 0x18
}GPIO_Type;

/* GPIOA base adddresss */
#define GPIOA_BASE  (0x40010800u)
/* GPIOA base pointer */
#define GPIOA		((GPIO_Type *)GPIOA_BASE)

/* GPIOB base adddresss */
#define GPIOB_BASE  (0x40010C00u)
/* GPIOB base pointer */
#define GPIOB		((GPIO_Type *)GPIOB_BASE)

/* GPIOC base adddresss */
#define GPIOC_BASE  (0x40011000u)
/* GPIOC base pointer */
#define GPIOC		((GPIO_Type *)GPIOC_BASE)

/* GPIOD base adddresss */
#define GPIOD_BASE  (0x40011400u)
/* GPIOD base pointer */
#define GPIOD		((GPIO_Type *)GPIOD_BASE)

/* GPIOE base adddresss */
#define GPIOE_BASE  (0x40011800u)
/* GPIOE base pointer */
#define GPIOE		((GPIO_Type *)GPIOE_BASE)

/* GPIOF base adddresss */
#define GPIOF_BASE  (0x40011C00u)
/* GPIOF base pointer */
#define GPIOF		((GPIO_Type *)GPIOF_BASE)

/* GPIOG base adddresss */
#define GPIOG_BASE  (0x40012000u)
/* GPIOG base pointer */
#define GPIOG		((GPIO_Type *)GPIOG_BASE)


/* AFIO memory tydef layout */
typedef struct {
  volatile unsigned int EVCR;												//offset 0x00
	volatile unsigned int MAPR;												//offser 0x04
	volatile unsigned int EXTICR1;										//offset 0x08
	volatile unsigned int EXTICR2;										//offset 0x0C
	volatile unsigned int EXTICR3;										//offset 0x10
	volatile unsigned int EXTICR4;										//offset 0x14
	volatile unsigned int	reserced;										
	volatile unsigned int	MAPR2;											//offset 0x1C
}AFIO_Type;

/* AFIO base adddresss */
#define AFIO_BASE  (0x40010000u)
/* AFIO base pointer */
#define AFIO		((AFIO_Type *)AFIO_BASE)

// Function protocol init
//void GPIOA_init();
//void GPIOB_init();
//void GPIOC_init();
//void GPIOD_init();
//void GPIOE_init();
//void GPIOF_init();
//void GPIOG_init();
//void AFIO_init();

void GPIO_Mode(GPIO_Type *PORT, unsigned char index, unsigned char mode, unsigned char cnf);

void GPIO_Write(GPIO_Type *PORT, unsigned char index, unsigned char status);

unsigned char GPIO_Read(GPIO_Type *PORT, unsigned char index);


