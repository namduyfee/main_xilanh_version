
#include "config.h" 
#include "interrupt.h"


 

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
				
				if(FEE_struct.TuDong.keo_xilanh_an_toan[1] == 1) 
					send_to_main('a'); 
				
				if(1 == FEE_struct.TrangThai.done[1] && 1 == FEE_struct.TuDong.keo_xilanh_an_toan[1]) {
					
					delayUs(500000);
					
					xoay_trai(1, 90);  
					FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 1; 
	
					delayUs(5000);
	
					xoay_phai(2, 90);
					FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai - 1; 
	
					reset_check_xoay_tay(); 
					
					FEE_struct.TrangThai.done[1] = 2; 
				}
			}
			
			else if(2 == FEE_struct.TuDong.tu_dong_number && 0 == FEE_struct.TrangThai.done[2]) {
				tu_dong_2(); 
				FEE_struct.TrangThai.done[2] = 1; 
			}
			
			else if(3 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[3]) {	
					tu_dong_3(); 
					FEE_struct.TrangThai.done[3] = 1; 
				}
				send_to_main('A'); 
			}
			
			else if(4 == FEE_struct.TuDong.tu_dong_number) {
				if(0 == FEE_struct.TrangThai.done[4]) {
					tu_dong_4(); 
//				send_to_main('b'); 
					FEE_struct.TrangThai.done[4] = 1; 
				}
				
				if(1 == FEE_struct.TuDong.keo_xilanh_an_toan[4]) 
					send_to_main('B'); 
				
			}
			
			else if(5 == FEE_struct.TuDong.tu_dong_number && 0 == FEE_struct.TrangThai.done[5]) {
				
				tu_dong_5(); 
				FEE_struct.TrangThai.done[5] = 1; 
			}
			
			else if(6 == FEE_struct.TuDong.tu_dong_number && 0 == FEE_struct.TrangThai.done[6]) {
				
				tu_dong_6();
				send_to_main('c'); 
				FEE_struct.TrangThai.done[6] = 1; 
			}
			
		}
				
	} 

	
	
	return 0; 
	
}

