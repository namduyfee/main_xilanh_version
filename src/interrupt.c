
#include "interrupt.h"


extern uint16_t tay_ps; 
extern FEE_struct_def FEE_struct; 
extern uint8_t mode_tem; 

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
		if(1 == FEE_struct.TrangThai.mode_run) {
			
			if(0 == check_xoay_tay_2((float)0.5)) {
				delayUs(50000);
				EXTI->PR = 1<<4;
				return; 
			}
					
//			if(1 == FEE_struct.TrangThai.troi_tay_2) {
//				khoa_dc_tay(2);
//				FEE_struct.TrangThai.troi_tay_2 = 0; 
//				delayUs(30000);
//				EXTI->PR = 1<<4;
//			}
			
			tinh_vi_tri_tay_xoay(2); 
					
			if(FEE_struct.TrangThai.vi_tri_tay_2_hien_tai != FEE_struct.TrangThai.vi_tri_tay_2_mong_muon) {
				reset_check_xoay_tay_2(); 
				delayUs(50000);
				EXTI->PR = 1<<4;
				return; 
			}			
				
			khoa_dc_tay(2);
								 
			if(1 == FEE_struct.TuDong.tu_dong_number)
				FEE_struct.TuDong.check_cam_bien_td[1]++; 
			
			else if (2 == FEE_struct.TuDong.tu_dong_number) 
				FEE_struct.TuDong.check_cam_bien_td[2]++; 			
			else if(5 == FEE_struct.TuDong.tu_dong_number)
				FEE_struct.TuDong.check_cam_bien_td[5]++; 			
			delayUs(50000);
			EXTI->PR = 1<<4;
			return; 
		}
		
		// mode khoi tao canh tay 
		else if(FEE_struct.TrangThai.mode_run == 2) {
			
			khoa_dc_tay(2); 
			delayUs(50000); 
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
		if(1 == FEE_struct.TrangThai.mode_run) {
					
			if(0 == check_xoay_tay_1((float)0.5)) {
				delayUs(50000);
				EXTI->PR = 1<<5;
				return; 
			}

//			if(1 == FEE_struct.TrangThai.troi_tay_1) {
//				khoa_dc_tay(1);
//				FEE_struct.TrangThai.troi_tay_1 = 0; 
//				delayUs(30000);
//				EXTI->PR = 1<<5;
//			}
			
			tinh_vi_tri_tay_xoay(1); 
					
			if(FEE_struct.TrangThai.vi_tri_tay_1_hien_tai != FEE_struct.TrangThai.vi_tri_tay_1_mong_muon) {
				
				reset_check_xoay_tay_1(); 
				delayUs(50000);
				EXTI->PR = 1<<5;
				return; 
			}			
				
			khoa_dc_tay(1);
								 
			if(1 == FEE_struct.TuDong.tu_dong_number)
				FEE_struct.TuDong.check_cam_bien_td[1]++; 
				
			else if (2 == FEE_struct.TuDong.tu_dong_number) 
				FEE_struct.TuDong.check_cam_bien_td[2]++; 
			
			else if(5 == FEE_struct.TuDong.tu_dong_number)
				FEE_struct.TuDong.check_cam_bien_td[5]++; 
			
			EXTI->PR = 1<<5;
			return; 
		}
			// lai tay 
		else if(FEE_struct.TrangThai.mode_run == 2) {
			
			khoa_dc_tay(1); 
			delayUs(50000); 
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
				
				if((1 == FEE_struct.TuDong.tu_dong_number) && (FEE_struct.TuDong.vi_tri_nang_ha >= (FEE_struct.TuDong.tranh_cam_bien - 10)) 
					&& (FEE_struct.TrangThai.len_xuong == 1)) {
					FEE_struct.TuDong.day_keo_xilanh_an_toan[1] = 1; 
					send_to_main('a'); 
				}
				
				if((4 == FEE_struct.TuDong.tu_dong_number) && (FEE_struct.TuDong.vi_tri_nang_ha >= (FEE_struct.TuDong.tranh_cam_bien - 10))
					&& (FEE_struct.TrangThai.len_xuong == 1)) {
					FEE_struct.TuDong.day_keo_xilanh_an_toan[4] = 1; 
					send_to_main('B'); 
				}
			
				if(FEE_struct.TuDong.stop_nang_ha == FEE_struct.TuDong.vi_tri_nang_ha) {
				
					khoa_dc_tay(3);
				
					if(1 == FEE_struct.TuDong.tu_dong_number)
						FEE_struct.TuDong.check_cam_bien_td[1]++; 
					
					else if((3 == FEE_struct.TuDong.tu_dong_number) || (4 == FEE_struct.TuDong.tu_dong_number)) {
						if(0 == FEE_struct.TuDong.check_cam_bien_td[3]) 
							FEE_struct.TuDong.check_cam_bien_td[3]++; 
					}
						
					else if(5 == FEE_struct.TuDong.tu_dong_number) 
						FEE_struct.TuDong.check_cam_bien_td[5]++;
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

