
#include "timer.h"


void configTIM1(void) {
// config TIM1 
	// enable clock TIM1
	RCC->APB2ENR |= 1<<11; 
	TIM1->ARR = 1000-1; 
	TIM1->PSC = 72-1; 
	// center-aligned 
	TIM1->CR1 |= 1<<5; 
	TIM1->CR1 |= 1<<6; 
	// set bit MOE
	TIM1->BDTR |= 1<<15; 							
	
	// channel 1 PWM mode 1 
	TIM1->CCMR1 &= 0xFFF0; 
	TIM1->CCMR1 |= 0x60; 
	// channel 2 PWM mode 1 
	TIM1->CCMR1 &= 0xF0FF; 
	TIM1->CCMR1 |= 0x6000; 
	// channel 3 PWM mode 1 
	TIM1->CCMR2 &= 0xFFF0; 
	TIM1->CCMR2 |= 0x60; 
	// channel 4 PWM mode 1  
	TIM1->CCMR2 &= 0xF0FF;  
	TIM1->CCMR2 |= 0x6000; 
	
	
	// set bit UG 
	TIM1->EGR |= 1; 			
	// enable counter 
	TIM1->CR1 |= 1; 												
}

void configTIM2(void) {
// config TIM2
// enable clock TIM2
	
	RCC->APB1ENR |= 1<<0;	 
	TIM2->ARR = 65535-1; 
	TIM2->PSC = 14400-1; 
	TIM2->EGR |= 1; 
	TIM2->CR1 |= 1; 
	
}


//void configTIM3(void) {
//// config TIM3
//	// enable clock TIM3 
//	RCC->APB1ENR |= 1<<1; 
//	TIM3->ARR = 10000-1; 
//	TIM3->PSC = 144-1; 
//	// channel 2 PWM mode 1 
//	TIM3->CCMR1 &= 0xF0F0; 
//	TIM3->CCMR1 |= 0x6060; 
//	
//	// CCxR = 250 + 6* (goc quay mong muon : 0->180)
//	// set bit UG
//	TIM3->EGR |= 1; 
//	// enable counter 
//	TIM3->CR1 |= 1; 
//}



void configTIM3(void) {
// config TIM3
// enable clock TIM3
	
	RCC->APB1ENR |= 1<<1;	 
	TIM3->ARR = 65535-1; 
	TIM3->PSC = 14400-1; 
	TIM3->EGR |= 1; 
	TIM3->CR1 |= 1; 
	
}





void configTIM4(void) {
// config TIM4
// enable clock TIM4
	
	RCC->APB1ENR |= 1<<2;	 
	TIM4->ARR = 2000-1; 
	TIM4->PSC = 72-1; 
	TIM4->EGR |= 1; 
	TIM4->CR1 |= 1; 
	
}


void delayUs(uint32_t us) {

	while(us) {
		TIM4->CNT = 0; 
		while(TIM4->CNT == 0); 
		us--; 
	}
}



