
#include "interrupt.h"


// start = 0 : di va home , = 1 : dua vao luoc 
// trang_thai = 0 di xuong : -- , trang_thai = 1 di len : ++

#define tha_lua 16
#define gap_lua_len 8
#define di_tha_lua 7
#define tranh_cham_lua 34 

void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {
		
		khoa_dc_tay(3); 

		vi_tri_nang_ha = 0; 
		if(start == 0) { 
			start = 1; 
			USART1->CR1 |= 1<<5;
		}
		
		if(tem == 4) {
			kep(1); 
			delayUs(500000); 
			stop_nang_ha = di_tha_lua; 
			nang_canh_tay(70); 
			trang_thai = 1; 
			delayUs(500000);
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
				control_xilanh(3, 0); 
				control_xilanh(5, 0); 
				delayUs(500000); 
				xoay_trai(1, 50); 
				xoay_phai(2, 60);
				tem = 2; 
				EXTI->PR = 1<<4;
				return; 
			}
			
			if(tem == 2) {
				control_xilanh(1, 0); 
				control_xilanh(7, 0); 
				delayUs(500000); 
				xoay_phai(1, 50);
				xoay_trai(2, 60); 
				start = 0;  
				ha_canh_tay(70); 
				trang_thai = 0; 
				tem = 3;
				USART1->DR = 'a'; 
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
					control_xilanh(3, 0); 
					control_xilanh(5, 0); 
					delayUs(500000); 
					xoay_trai(1, 50); 
					xoay_phai(2, 60);
					tem = 2; 
					EXTI->PR = 1<<5;
					return; 
			}
				
			if(tem == 2) {
				control_xilanh(1, 0); 
				control_xilanh(7, 0); 
				delayUs(500000); 
				xoay_phai(1, 50);
				xoay_trai(2, 60); 
				start = 0;  
				ha_canh_tay(70); 
				trang_thai = 0; 
				tem = 3;
				USART1->DR = 'a'; 
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
		if(start) {
			if(trang_thai == 0) 
				vi_tri_nang_ha--; 
			else 
				vi_tri_nang_ha++; 
		
			if(stop_nang_ha == vi_tri_nang_ha) {
				khoa_dc_tay(3);
				
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
			kep(1); 
			delayUs(1000000); 
			stop_nang_ha = tha_lua;
			trang_thai = 1;
			nang_canh_tay(70);
			delayUs(500000);
			USART1->DR = 'a'; 
			xoay_trai(1, 20); 
			xoay_phai(2, 30);
			tem = 1; 
		}
		if(tay_ps == 'b') {
			kep(2); 
			delayUs(500000); 
			trang_thai = 1; 
			stop_nang_ha = tranh_cham_lua; 
			nang_canh_tay(70); 
			USART1->DR = 'b'; 
		}
		
		if(tay_ps == 'c') {
			start = 0; 
			ha_canh_tay(70); 
			trang_thai = 0; 
			xoay_phai(1, 60);
			xoay_trai(2, 70); 
			tem = 4; 
		}
		if(tay_ps == 'd') {

		}
		USART1->CR1 |= 1<<7; 
	}
	if(USART1->SR & (1<<7)) {
		
		USART1->CR1 &= (~(1<<7));
	}
	
}

