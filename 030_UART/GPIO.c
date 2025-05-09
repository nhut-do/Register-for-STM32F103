#include "GPIO.h"
#include "RCC.h"



void GPIO_Mode(GPIO_Type *PORT, unsigned char index, unsigned char mode, unsigned char cnf) {
		if (index <= 7) {
			PORT->CRL |= (mode << (4*index));
			PORT->CRL &= ~(3  << (4*index + 2));										// reset bits for CNF
			PORT->CRL |= (cnf  << (4*index + 2));
		}
		else {
			index -= 8;
			PORT->CRH |= (mode << (4*index));
			PORT->CRH &= ~(3  << (4*index + 2));										// reset bits for CNF
			PORT->CRH |= (cnf  << (4*index + 2));
		}
}

void GPIO_Write(GPIO_Type *PORT, unsigned char index, unsigned char status) {
	if (index <= 7) {
		if ((PORT->CRL & (3 << index*4)) == 0) {									// Check if status of pin is INPUT
			return; }																								// Out function
	}
	else {
		if ((PORT->CRH & (3 << (index-8)*4)) == 0) {							// Check if status of pin is INPUT
			return; }																								// Out function
	}	
	if (status == 0) {
		PORT->ODR |= (1 << index);																// Set bits for pin(index) to HIGH
	}
	else {
		PORT->ODR &= ~(1 << index);																// Clear bit for pin(index) to LOW 
	}
}

unsigned char GPIO_Read(GPIO_Type *PORT, unsigned char index) {
	return (PORT->IDR & (1 << index));													// Read data from register IDR
}
