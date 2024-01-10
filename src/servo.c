
#include "servo.h"

void servo1(int goc1) {
	// 0 <= goc <= 180 
	
	// servo 0.5ms -> 2.5 ms
	TIM3->CCR1 = 250 + (6 * goc1); 
	
	// servo 1ms -> 2ms 
//	TIM2->CCR2 = 500 + (3 * goc1);
	
	TIM3->CCER |= 1; 
	
}

void servo2(int goc2) {
	// 0 <= goc <= 180 
	// servo 0.5ms -> 2.5 ms
	TIM3->CCR2 = 250 + (6 * goc2); 
	/* 
	// servo 1ms -> 2ms 
	TIM3->CCR2 = 500 + (3 * goc2);
	*/
	TIM3->CCER |= 1<<4; 
}


void dc1(int chieu, uint16_t sped) {
	// PB1 PB5
	
	if(chieu == 0) {
		GPIOB->ODR |= 1<<1; 
		GPIOB->ODR &= (~(1<<5));
	}
	if(chieu == 1) {
		GPIOB->ODR &= (~(1<<1)); 
		GPIOB->ODR |= 1<<5;
	}
	TIM1->CCR1 = sped; 
	TIM1->CCER |= 1; 
	
}

void khoaDC(void) {

	GPIOB->ODR &= (~(1<<1)); 
	GPIOB->ODR &= (~(1<<5));
}

