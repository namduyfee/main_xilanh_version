
#include "config.h" 
#include "interrupt.h"
// vi tri gap lua len 20 
// vi tri tranh cam bien 38 
int main() {
	
	config(); 

	enable_reciver_to_main();
	
	while(1) {
		if(0 == FEE_struct.TrangThai.mode_run) {
			
			ham_lai_tay(); 
			
		}
		else if(1 == FEE_struct.TrangThai.mode_run) {
			
			if(1 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[1]) {
					tu_dong_1(); 
					FEE_struct.TrangThai.done[1] = 1; 
				}
				
				if(1 == FEE_struct.TuDong.day_keo_xilanh_an_toan[1]) {
					
					send_to_main('a'); 
					
					if(1 == FEE_struct.TrangThai.done[1]) {
						
						delayUs(200000);
					
						xoay_trai(1, 70);  
						FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 1; 
						reset_check_xoay_tay_1(); 
						
						delayUs(5000);
	
						xoay_phai(2, 70);
						FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai - 1; 
						reset_check_xoay_tay_2(); 
					
						FEE_struct.TrangThai.done[1] = 2; 
					}
				}
				if(3 == FEE_struct.TuDong.check_cam_bien_td[1]) {
					FEE_struct.TuDong.tu_dong_number = 2; 
					FEE_struct.TrangThai.done[2] = 0;
				}
			}
			else if(2 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[2]) {
					tu_dong_2(); 
					FEE_struct.TrangThai.done[2] = 1; 
				}
				
				send_to_main(38); 					// '&' nhin khas giong chu A a :vv
				
				if(2 == FEE_struct.TuDong.check_cam_bien_td[2]) {
					
					FEE_struct.TuDong.tu_dong_number = 3; 
					FEE_struct.TrangThai.done[3] = 0; 
//					if((0 == (GPIOB->IDR & 1<<4)) && (0 == (GPIOB->IDR & 1<<5))) {
//						FEE_struct.TuDong.tu_dong_number = 3; 
//						FEE_struct.TrangThai.done[3] = 0; 
//					}
//					else {
//						if( 1 == (GPIOB->IDR & 1<<5) && (0 == FEE_struct.TrangThai.troi_tay_1)) {
//							FEE_struct.TrangThai.troi_tay_1 = 1; 
//							if(1 == FEE_struct.TrangThai.chieu_xoay_1)
//								xoay_trai(1, 50); 
//							else 
//								xoay_phai(1, 50); 
//						}
//						
//						if( 1 == (GPIOB->IDR & 1<<4) && (0 == FEE_struct.TrangThai.troi_tay_2)) {
//							FEE_struct.TrangThai.troi_tay_2 = 1; 
//							if(1 == FEE_struct.TrangThai.chieu_xoay_2)
//								xoay_trai(2, 50); 
//							else 
//								xoay_phai(2, 50); 
//						}
//						
//					}			
				}
			}
			
			else if(3 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[3]) {	
					tu_dong_3(); 
					FEE_struct.TrangThai.done[3] = 1; 
				}
				
				send_to_main('A'); 
			}
			
			else if(4 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[4] && 1 == FEE_struct.TuDong.check_cam_bien_td[3]) {
					tu_dong_4(); 
//				send_to_main('b'); 
					FEE_struct.TrangThai.done[4] = 1; 
				}
				
				if(1 == FEE_struct.TuDong.day_keo_xilanh_an_toan[4]) 
					send_to_main('B'); 
				
			}
			
			else if(5 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[5]) {
					tu_dong_5(); 
					FEE_struct.TrangThai.done[5] = 1; 
				}
				
				if(3 == FEE_struct.TuDong.check_cam_bien_td[5]) {
					
					FEE_struct.TuDong.tu_dong_number = 6; 
					FEE_struct.TrangThai.done[6] = 0; 
//					if((0 == (GPIOB->IDR & 1<<4)) && (0 == (GPIOB->IDR & 1<<5))) {
//						FEE_struct.TuDong.tu_dong_number = 6; 
//						FEE_struct.TrangThai.done[6] = 0; 
//					}
//					else {
//						if( 1 == (GPIOB->IDR & 1<<5) && (0 == FEE_struct.TrangThai.troi_tay_1)) {
//							FEE_struct.TrangThai.troi_tay_1 = 1; 
//							if(1 == FEE_struct.TrangThai.chieu_xoay_1)
//								xoay_trai(1, 50); 
//							else 
//								xoay_phai(1, 50); 
//						}
//						
//						if( 1 == (GPIOB->IDR & 1<<4) && (0 == FEE_struct.TrangThai.troi_tay_2)) {
//							FEE_struct.TrangThai.troi_tay_2 = 1; 
//							if(1 == FEE_struct.TrangThai.chieu_xoay_2)
//								xoay_trai(2, 50); 
//							else 
//								xoay_phai(2, 50); 
//						}
//					}	
				}
			}
			
			else if(6 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[6]) {
					if(1 == FEE_struct.TuDong.check_cam_bien_td[6]) {
						tu_dong_6();
						FEE_struct.TrangThai.done[6] = 1; 
					}
				}
			}
		}
				
	} 
	
	return 0; 
	
}

