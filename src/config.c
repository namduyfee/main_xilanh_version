
#include "config.h"


void config(void) {
	
	configGPIOA(); 
	configGPIOB(); 
	configGPIOC(); 
	configAFIO();

	configEXTI(); 

	configNVIC(); 
 
	configTIM4();
	
	configDMA1(); 
	
	configUART1(); 
	configUART2(); 
	configUART3(); 
	
//	configI2c(); 
//	configTIM3();
//	configTIM1(); 

//	initDMA1Channel7(&(canh_tay.diachi_trai), &(USART2->DR), 9); 
//	if((GPIOA->IDR & 1<<15) == 0) {
//		nang_canh_tay(40); 
//		delayUs(1500000); 
//		ha_canh_tay(50); 
//	}
	
}