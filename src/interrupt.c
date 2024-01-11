
#include "interrupt.h"


// home = 0 : di va home , = 1 : dua vao luoc 
// trang_thai = 0 di xuong : -- , trang_thai = 1 di len : ++

// done = 0 : de ngat sau lam task 
// done = 1 : lam task 

#define tha_lua 16
#define gap_lua_len 8
#define di_tha_lua 7
#define tranh_cham_lua 34 

void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {
		
		khoa_dc_tay(3); 

		vi_tri_nang_ha = 0; 
		if(home == 0) { 
			home = 1; 
			USART1->CR1 |= 1<<5;
		}
		
		if(tem == 4) {
			
			tu_dong_6(); 
			USART1->DR = 'c'; 
		}
		
		EXTI->PR = 1<<15;
	}
	
}

void EXTI4_IRQHandler (void) {
	if(EXTI->PR & 1<<4) {
		
		if(check == 0) {
			khoa_dc_tay(2); 
			while((EXTI->PR & 1<<5) == 0);
			khoa_dc_tay(1); 
			check = 1; 
			delayUs(50000);
			
			if(tem == 1) { 
				if(done == 0) 
					done = 1; 
				else {
					tu_dong_2(); 
					tem = 2; 
					done = 0; 
					EXTI->PR = 1<<4;
					return; 
				}
			}
			
			if(tem == 2) {
				
				tu_dong_3(); 
				tem = 3; 
				USART1->DR = 'A'; 
				EXTI->PR = 1<<4;
				return; 
			}
			EXTI->PR = 1<<4;
			return; 
		}
		
		if(check == 1) {
			delayUs(50000);
			check = 0; 
			EXTI->PR = 1<<4;
		}
		
	}
}

void EXTI9_5_IRQHandler (void) {
		
	if(EXTI->PR & 1<<5) {
			
			if(check == 0) {

				khoa_dc_tay(1); 
				while((EXTI->PR & 1<<4) == 0);
				khoa_dc_tay(2);
				check = 1;
				delayUs(50000); 
				
				if(tem == 1) { 
					
					tu_dong_2(); 
					tem = 2; 
					EXTI->PR = 1<<5;
					return; 
			}
				
			if(tem == 2) {
				tu_dong_3(); 
				tem = 3; 
				USART1->DR = 'A';
				EXTI->PR = 1<<5;
				return; 
			}
			EXTI->PR = 1<<5;
			return; 
		}
			
			if(check == 1) { 
			delayUs(50000);
			check = 0; 
			EXTI->PR = 1<<5;
			}
		}
}


void EXTI3_IRQHandler (void) {
	if(EXTI->PR & 1<<3) {
		if(home) {
			if(trang_thai == 0) 
				vi_tri_nang_ha--; 
			else 
				vi_tri_nang_ha++; 
		
			if(stop_nang_ha == vi_tri_nang_ha) {
				khoa_dc_tay(3);
				if(tem == 1) {
					if(done == 0) 
						done = 1; 
					else {
						tu_dong_2(); 
						tem = 2; 
						done = 0; 
					}
				}		
			}
 
			delayUs(50000); 
		}
		EXTI->PR = 1<<3;
	
	}
	
}


void USART1_IRQHandler (void) {
	
	if(USART1->SR & (1<<5)) {
		tay_ps = USART1->DR; 
		if(tay_ps == 'a') { 
			
			tem = 1; 
			tu_dong_1();
			USART1->DR = 'a'; 
		}
		if(tay_ps == 'b') {
			
			tu_dong_4(); 
			USART1->DR = 'b'; 
		}
		
		if(tay_ps == 'c') {
			tem = 4;
			tu_dong_5();  
		}
		if(tay_ps == 'd') {

		}
		USART1->CR1 |= 1<<7; 
	}
	if(USART1->SR & (1<<7)) {
		
		USART1->CR1 &= (~(1<<7));
	}
	
}

