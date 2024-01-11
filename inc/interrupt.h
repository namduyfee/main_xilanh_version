


#ifndef		__INTERRUPT__

#define	__INTERRUPT__

#include <stm32f10x.h> 

#include "timer.h" 
#include "servo.h"
#include "function.h" 


typedef struct {
	uint8_t diachi_trai; 
	uint8_t tocdo_trai; 
	uint8_t end_trai; 
	uint8_t diachi_phai; 
	uint8_t tocdo_phai; 
	uint8_t end_phai;
	uint8_t diachi_keo; 
	uint8_t tocdo_keo; 
	uint8_t end_keo;
} dc; 
 
extern uint8_t home; 
extern uint16_t tay_ps; 
extern int check; 
extern dc canh_tay; 
extern uint8_t tem;  
extern uint8_t stop_nang_ha; 
extern uint8_t vi_tri_nang_ha; 
extern uint8_t trang_thai; 
extern uint8_t done; 


 void EXTI3_IRQHandler (void); 
 
 void EXTI4_IRQHandler (void); 
 
 void EXTI9_5_IRQHandler (void); 
	
	void EXTI15_10_IRQHandler (void); 


	void USART1_IRQHandler (void); 

#endif
