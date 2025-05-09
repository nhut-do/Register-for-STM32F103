

/** EXTI - Register Layout Typedef */
typedef struct {
  volatile unsigned int IMR;					//offset 0x00
	volatile unsigned int EMR;					//offser 0x04
	volatile unsigned int RTSR;					//offset 0x08
	volatile unsigned int FTSR;					//offset 0x0C
	volatile unsigned int SWIER;				//offset 0x10
	volatile unsigned int PR;						//offset 0x14
} EXTI_Type;
  
/** Peripheral EXTI base address */
#define EXTI_BASE                                 (0x40010400u)
/** Peripheral SCG base pointer */
#define EXTI                                      ((EXTI_Type *)EXTI_BASE)