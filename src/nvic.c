

#include "nvic.h"



void configNVIC(void) {
	
	NVIC_SetPriorityGrouping(NVIC_PriorityGroup_4); 
	
	NVIC_SetPriority(EXTI3_IRQn, 2); 

	NVIC_EnableIRQ(EXTI3_IRQn); 

	NVIC_SetPriority(EXTI4_IRQn, 4); 

	NVIC_EnableIRQ(EXTI4_IRQn); 

 NVIC_SetPriority(EXTI9_5_IRQn, 4); 

	NVIC_EnableIRQ(EXTI9_5_IRQn); 
//	
	NVIC_SetPriority(EXTI15_10_IRQn, 3); 

	NVIC_EnableIRQ(EXTI15_10_IRQn); 
	
	NVIC_SetPriority( USART1_IRQn, 1); 
	NVIC_EnableIRQ( USART1_IRQn); 
	
}
