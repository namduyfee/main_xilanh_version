
#include "gpio.h"
// B : output alter,  8 : input , 3 : output 

void configGPIOA(void) {
	
	// enable clock Port A
	RCC->APB2ENR |= 1<<2; 
	
// CRL = 0
	GPIOA->CRL &= 0; 
	// config pin 
	// output : 0,1,4,5
	GPIOA->CRL |= 0x330033; 
	// output alter : PA2_TX_U2, pin 2
	GPIOA->CRL |= (0xB<<8); 
	// input PA3_RX_U2, pin 3 
	GPIOA->CRL |= (0x8<<12);
	GPIOA->ODR |= 1<<3; 
	// pin 6, 7 ADC 
	GPIOA->CRL &= 0xFFFFFF; 
	
// CRH = 0 
	GPIOA->CRH &= 0; 
	// ouput : 8, 11, 12
	GPIOA->CRH |= 0x33003;
//	GPIOA->ODR |= 1<<8; 
	GPIOA->ODR &= (~(1<<8)); 
	GPIOA->ODR &= (~(1<<11));
	GPIOA->ODR &= (~(1<<12));
	
	// ouput alter : PA9_TX_U1
	GPIOA->CRH |= 0xB0; 
	// input PA10_RX_U1
	GPIOA->CRH |= 0x800; 
	GPIOA->ODR |= 1<<10; 
	
	// PA15_input 
	GPIOA->CRH |= (0x8<<28); 
	GPIOA->ODR |= 1<<15; 
}

void configGPIOB(void) {
// config Port B 
	// enable clock Port B 
	RCC->APB2ENR |= 1<<3;
	// CRL = 0
	GPIOB->CRL &= 0; 
	// pin 3, 4, 5 input 
	GPIOB->CRL |= 0x888000;
	GPIOB->ODR |= 1<<3; 
	GPIOB->ODR |= 1<<4; 
	GPIOB->ODR |= 1<<5; 
	
	// pin 6, 7 out opendrain 
	GPIOB->CRL |= (0xF<<24); 
	GPIOB->CRL |= (0xF<<28); 
	
	// CRH = 0
	GPIOB->CRH &= 0; 
	// pin 8 out 
	GPIOB->CRH |= 0x3; 
	// pin 9 buzzer 
	
	// PB10_Tx_U3 out alter 
	GPIOB->CRH |= 0xB00; 
	
	// PB11_Rx_U3 in 
	GPIOB->CRH |= (0x8<<12); 
	GPIOB->ODR |= 1<<11; 
	
	// 12, 13, 14, 15 output  
	
	GPIOB->CRH |= (0x3<<16); 
	GPIOB->CRH |= (0x3<<20);
	GPIOB->CRH |= (0x3<<24);
	GPIOB->CRH |= (0x3<<28);
	
	GPIOB->ODR &= (~(1<<12)); 
	GPIOB->ODR &= (~(1<<13));
	GPIOB->ODR &= (~(1<<14));
	GPIOB->ODR &= (~(1<<15));
}

void configGPIOC(void) {
	// enable clock 
	RCC->APB2ENR |= 1<<4;
	
	// CRH = 0
	GPIOC->CRH &= 0; 
	// 14 15 output 
	GPIOC->CRH |= (0x3<<24); 
	GPIOC->CRH |= (0x3<<28); 
	
}
void configAFIO(void) {
	
	RCC->APB2ENR |= 1; 
	AFIO->EXTICR[0] |= 0x1000; 
	AFIO->EXTICR[1] |= 0x11; 
	AFIO->EXTICR[3] &= 0x0FFF; 
	
	AFIO->MAPR |= 	1<<25; 
	
}
