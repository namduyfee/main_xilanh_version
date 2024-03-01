


#ifndef		__INTERRUPT__

#define	__INTERRUPT__

#include <stm32f10x.h> 

#include "config.h" 

extern uint16_t tay_ps; 

extern FEE_struct_def FEE_struct; 


 void EXTI3_IRQHandler (void); 
 
 void EXTI4_IRQHandler (void); 
 
 void EXTI9_5_IRQHandler (void); 
	
	void EXTI15_10_IRQHandler (void); 


	void USART1_IRQHandler (void); 

#endif
