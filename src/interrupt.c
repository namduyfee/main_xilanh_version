
#include "interrupt.h"


extern uint16_t tay_ps; 
extern FEE_struct_def FEE_struct; 
extern uint8_t mode_tem; 

int check = 0; 

int check_td1 = 0; 

uint8_t check_td2_tay1 = 0; 
uint8_t check_td2_tay2 = 0; 

// home = 0 : di va home , = 1 : dua vao luoc 
// trang_thai = 0 di xuong : -- , trang_thai = 1 di len : ++
 

void EXTI15_10_IRQHandler (void) {
	
	if(EXTI->PR & 1<<15) {
		
		FEE_struct.TuDong.vi_tri_nang_ha = 0; 
		if( 0 == FEE_struct.TrangThai.home)
			FEE_struct.TrangThai.home = 1; 
			
		khoa_dc_tay(3);
		
		if(2 == FEE_struct.TrangThai.mode_run ) {
			if(0 == FEE_struct.TrangThai.vi_tri_kep_lua) {
				khoi_tao_kep_lua(); 
				FEE_struct.TrangThai.vi_tri_kep_lua = 1; 
			}
	
		}
		delayUs(50000); 
		EXTI->PR = 1<<15;
	}
	
}

void EXTI4_IRQHandler (void) {
	
	if(EXTI->PR & 1<<4) {
		// tu dong 
		if(FEE_struct.TrangThai.mode_run == 1) {
			if(check == 0) {
				
					if(check_xoay_tay((float)0.4) == 0) {
						delayUs(50000);
						EXTI->PR = 1<<4;
						return; 
					}
				
//				if(2 == FEE_struct.TuDong.tu_dong_number) {
//					if(check_xoay_tay((float)1.3) == 0) {
//						delayUs(50000);
//						EXTI->PR = 1<<4;
//						return; 
//					}
//				}
//				else {
//					if(check_xoay_tay((float)0.7) == 0) {
//						delayUs(50000);
//						EXTI->PR = 1<<4;
//						return; 
//					}
//				}
					
				if(2 == FEE_struct.TuDong.tu_dong_number) {
					if(0 == check_td2_tay2) {
						check_td2_tay2++;
						delayUs(50000); 
						EXTI->PR = 1<<4;
						return; 
					}
					check_td2_tay1++; 
				}
				
//				tinh_vi_tri_tay_xoay(2); 
//				
//				if(FEE_struct.TrangThai.vi_tri_tay_2_hien_tai != FEE_struct.TrangThai.vi_tri_tay_2_mong_muon) {
//					delayUs(50000);
//					EXTI->PR = 1<<4;
//					return; 
//				}
				
				khoa_dc_tay(2); 
				while((GPIOB->IDR & 1<<5) == 0);
//				tinh_vi_tri_tay_xoay(1); 
				khoa_dc_tay(1); 
				check = 1; 
				delayUs(50000);
								 
				if(FEE_struct.TuDong.tu_dong_number == 1) { 
					if(check_td1 == 0) 
						check_td1 = 1; 
					else {
						
						check_td1 = 0;
						FEE_struct.TuDong.tu_dong_number = 2; 
						FEE_struct.TrangThai.done[2] = 0; 			
					}
					EXTI->PR = 1<<4;		
					return; 
				}
				
				if(FEE_struct.TuDong.tu_dong_number  == 2) {
					FEE_struct.TuDong.tu_dong_number = 3; 
					FEE_struct.TrangThai.done[3] = 0;
					EXTI->PR = 1<<4;			// xoa co ngat 
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
		
		// mode khoi tao canh tay 
		else if(FEE_struct.TrangThai.mode_run == 2) {
			
			khoa_dc_tay(2); 
			delayUs(20000); 
			EXTI->PR = 1<<4;
		}
		// lai tay 
		else {
			EXTI->PR = 1<<4;
		}
			
	}
}


void EXTI9_5_IRQHandler (void) {
		
	if(EXTI->PR & 1<<5) {
			// tu dong 
			if(FEE_struct.TrangThai.mode_run == 1) {
				if(check == 0) {
					
					if(check_xoay_tay((float)0.4) == 0) {
						delayUs(50000);
						EXTI->PR = 1<<5;
						return; 
					}
					
					if(2 == FEE_struct.TuDong.tu_dong_number) {
						if(0 == check_td2_tay1) {
							check_td2_tay1++;
							delayUs(50000); 
							EXTI->PR = 1<<5;
							return; 
						}
						check_td2_tay2++; 
					}
					
//				if(2 == FEE_struct.TuDong.tu_dong_number) {
//					if(check_xoay_tay((float)1.2) == 0) {
//						delayUs(50000);
//						EXTI->PR = 1<<5;	
//						return; 
//					}
//				}
//				else {
//					if(check_xoay_tay((float)0.7) == 0) {
//						delayUs(50000);
//						EXTI->PR = 1<<5;
//						return; 
//					}
//				}
					
//					tinh_vi_tri_tay_xoay(1); 
//					if(FEE_struct.TrangThai.vi_tri_tay_1_hien_tai != FEE_struct.TrangThai.vi_tri_tay_1_mong_muon)  {
//						delayUs(50000); 
//						EXTI->PR = 1<<5;
//						return; 
//					}
					khoa_dc_tay(1); 
					while((GPIOB->IDR  & 1<<4) == 0);
//					tinh_vi_tri_tay_xoay(2); 
					khoa_dc_tay(2);
					check = 1;
					delayUs(50000); 
					
					if(FEE_struct.TuDong.tu_dong_number == 1) { 
						if(check_td1 == 0) 
							check_td1 = 1;
				 
						else {
							check_td1 = 0;
							FEE_struct.TuDong.tu_dong_number = 2; 
							FEE_struct.TrangThai.done[2] = 0; 
						}
						EXTI->PR = 1<<5;
						return; 
					}
				
					else if(FEE_struct.TuDong.tu_dong_number  == 2) {
						FEE_struct.TuDong.tu_dong_number = 3; 
						FEE_struct.TrangThai.done[3] = 0;
						EXTI->PR = 1<<5;			// xoa co ngat 
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
			// lai tay 
			
		else if(FEE_struct.TrangThai.mode_run == 2) {
			
			khoa_dc_tay(1); 
			delayUs(20000); 
			EXTI->PR = 1<<5;
		}
		
			else {
				EXTI->PR = 1<<5;
			}
				
	}
}

void EXTI3_IRQHandler (void) {
	if(EXTI->PR & 1<<3) {
		
	
		if(FEE_struct.TrangThai.home) {
			
			if(0 == FEE_struct.TrangThai.len_xuong) 
				FEE_struct.TuDong.vi_tri_nang_ha--; 
			else 
				FEE_struct.TuDong.vi_tri_nang_ha++; 
			
			if(2 == FEE_struct.TrangThai.mode_run) {
				if(FEE_struct.TuDong.stop_nang_ha == FEE_struct.TuDong.vi_tri_nang_ha) {
					khoa_dc_tay(3);
					FEE_struct.TrangThai.mode_run = mode_tem; 
				}
			}
			
			else if(1 == FEE_struct.TrangThai.mode_run) {
				
				if(1 == FEE_struct.TuDong.tu_dong_number && FEE_struct.TuDong.vi_tri_nang_ha == FEE_struct.TuDong.gap_lua_len) 
					FEE_struct.TuDong.keo_xilanh_an_toan[1] = 1; 
				
				if(4 == FEE_struct.TuDong.tu_dong_number && FEE_struct.TuDong.vi_tri_nang_ha == FEE_struct.TuDong.gap_lua_len) 
					FEE_struct.TuDong.keo_xilanh_an_toan[4] = 1; 
			
				if(FEE_struct.TuDong.stop_nang_ha == FEE_struct.TuDong.vi_tri_nang_ha) {
				
					khoa_dc_tay(3);
				
					if(1 == FEE_struct.TuDong.tu_dong_number) {
						if(check_td1 == 0) 
							check_td1 = 1; 
						else { 
							check_td1 = 0; 
							FEE_struct.TuDong.tu_dong_number = 2; 
							FEE_struct.TrangThai.done[2] = 0;
						}
					}		
				
//				else if(4 == FEE_struct.TuDong.tu_dong_number)
//					send_to_main('B'); 
					else if(5 == FEE_struct.TuDong.tu_dong_number) {
						FEE_struct.TuDong.tu_dong_number = 6; 
						FEE_struct.TrangThai.done[6] = 0; 
					}
				}
			}
		}
		delayUs(50000); 
		EXTI->PR = 1<<3;
	
	}
	
}


void USART1_IRQHandler (void) {
	
	if(USART1->SR & (1<<5)) {
		tay_ps = USART1->DR;
		
		if(1 == FEE_struct.TrangThai.mode_run ) {
			
			// khoi tao canh tay de chay tu dong : ki tu ' @ ' 
			khoi_tao_tu_dong(); 
			
			if(tay_ps == 'a') { 
				if(0 == FEE_struct.TrangThai.comple_reciver[1]) {
					FEE_struct.TrangThai.comple_reciver[1] = 1; 
					FEE_struct.TuDong.tu_dong_number = 1; 
					FEE_struct.TrangThai.done[1] = 0;
				}
			}
			else 
				FEE_struct.TrangThai.comple_reciver[1] = 0; 
			
			if(tay_ps == 'b') {
				if(0 == FEE_struct.TrangThai.comple_reciver[4]) {
					FEE_struct.TrangThai.comple_reciver[4] = 1; 
					FEE_struct.TuDong.tu_dong_number = 4; 
					FEE_struct.TrangThai.done[4] = 0;
				}
			}
			else 
				FEE_struct.TrangThai.comple_reciver[4] = 0; 
		
			if(tay_ps == 'c') {
				if(0 == FEE_struct.TrangThai.comple_reciver[5]) {
					FEE_struct.TrangThai.comple_reciver[5] = 1; 
					FEE_struct.TuDong.tu_dong_number = 5; 
					FEE_struct.TrangThai.done[5] = 0;
				}
			}
			else 
				FEE_struct.TrangThai.comple_reciver[5] = 0; 
			
			if(tay_ps == 'd') {

			}
			
			
			// chuyen mode 
			if(tay_ps == 'z') {
				if(0 == FEE_struct.TrangThai.check_sw_mode) {
					FEE_struct.TrangThai.mode_run = 0; 
					FEE_struct.TrangThai.check_sw_mode = 1; 
				}
			}
			else 
				FEE_struct.TrangThai.check_sw_mode = 0;  
			
		}
		else {
			
			nut_lai_tay(); 
			
		}
		USART1->CR1 |= 1<<7; 
	}
	if(USART1->SR & (1<<7)) {
		USART1->CR1 &= (~(1<<7));
	}
	
}

