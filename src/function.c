
#include "function.h"

extern FEE_struct_def FEE_struct; 
extern uint16_t tay_ps; 

uint8_t mode_tem; 

// A12 : 1
// A11 : 2 
// A8 : 3
// B8 : 4

// B12 : 5 <=> 1 
// B13  : 6 <=> 2 
// B14 : 7  <=> 3
// B15 : 8 <=> 4


void control_xilanh(uint8_t xilanh_number, uint8_t trang_thai_xilanh) {
	
	// kep vao
	if(trang_thai_xilanh == 1) {
		
		if(xilanh_number == 1) 
			GPIOA->ODR |= 1<<12; 
		if(xilanh_number == 2)  
			GPIOA->ODR |= 1<<11; 
		if(xilanh_number == 3) 
			GPIOA->ODR |= 1<<8;
		if(xilanh_number == 4) 
			 GPIOB->ODR |= 1<<8;
		
		// tay 2 
		
		if(xilanh_number == 5) 
				GPIOB->ODR |= 1<<12; 
		if(xilanh_number == 6) 
			GPIOB->ODR |= 1<<13; 
		if(xilanh_number == 7) 
			GPIOB->ODR |= 1<<14; 
		if(xilanh_number == 8) 
			GPIOB->ODR |= 1<<15; 
		
	}
	//mo ra  
	if(trang_thai_xilanh == 0) {
		
		if(xilanh_number == 1) 
			GPIOA->ODR &= (~(1<<12)); 
		if(xilanh_number == 2)  
			GPIOA->ODR &= (~(1<<11)); 
		if(xilanh_number == 3) 
			GPIOA->ODR &= (~(1<<8)); 
		if(xilanh_number == 4) 
			 GPIOB->ODR &= (~(1<<8)); 
		
		// tay 2 
		
		if(xilanh_number == 5) 
				GPIOB->ODR &= (~(1<<12)); 
		if(xilanh_number == 6) 
			GPIOB->ODR &= (~(1<<13)); 
		if(xilanh_number == 7) 
			GPIOB->ODR &= (~(1<<14)); 
		if(xilanh_number == 8) 
			GPIOB->ODR &= (~(1<<15));  		
		
	}
	

	
}


void nang_canh_tay(uint8_t toc_do) {
	FEE_struct.CanhTay.diachi_keo = 0x83; 		// dung la 0x03
	FEE_struct.CanhTay.tocdo_keo = toc_do; 
}


void ha_canh_tay(uint8_t toc_do) {
	FEE_struct.CanhTay.diachi_keo = 0x03; 		// dung la 0x83
	FEE_struct.CanhTay.tocdo_keo = toc_do; 
}


void xoay_phai(uint8_t tay_number, uint8_t toc_do) {
	if(tay_number ==1) {
		FEE_struct.CanhTay.diachi_trai = 0x81; 						// chieu dung la 81 
		FEE_struct.CanhTay.tocdo_trai = toc_do;
		FEE_struct.TrangThai.chieu_xoay_1 = 1; 
	}
	
	if(tay_number ==2) {
		FEE_struct.CanhTay.diachi_phai = 0x82; 
		FEE_struct.CanhTay.tocdo_phai = toc_do;
		FEE_struct.TrangThai.chieu_xoay_2 = 1; 
	}
	
}

void xoay_trai(uint8_t tay_number, uint8_t toc_do) {
	if(tay_number ==1) {
		FEE_struct.CanhTay.diachi_trai = 0x01; 					// chieu dung la 01 
		FEE_struct.CanhTay.tocdo_trai = toc_do;
		FEE_struct.TrangThai.chieu_xoay_1 = 0; 
	}
	
	if(tay_number ==2) {
		FEE_struct.CanhTay.diachi_phai = 0x02; 
		FEE_struct.CanhTay.tocdo_phai = toc_do;
		FEE_struct.TrangThai.chieu_xoay_2 = 0; 
	}
	
}

void khoa_dc_tay(uint8_t dc_number) {
	
	if(dc_number == 1) 
		FEE_struct.CanhTay.tocdo_trai = 1; 
	if(dc_number ==2)
		FEE_struct.CanhTay.tocdo_phai = 1; 
	if(dc_number == 3) 
		FEE_struct.CanhTay.tocdo_keo = 1; 
	
}

void kep(uint8_t chan_le) {
	
	if(chan_le == 1) {
		control_xilanh(1, 1); 
		control_xilanh(3, 1); 
		control_xilanh(5, 1); 
		control_xilanh(7, 1); 
	}
	if(chan_le == 2) {
		control_xilanh(2, 1); 
		control_xilanh(4, 1); 
		control_xilanh(6, 1); 
		control_xilanh(8, 1); 
	}
}

void nha(uint8_t chan_le) {
		if(chan_le == 2) {
		control_xilanh(2, 0); 
		control_xilanh(4, 0); 
		control_xilanh(6, 0); 
		control_xilanh(8, 0); 
	}
		
	if(chan_le == 1) {
		control_xilanh(1, 0); 
		control_xilanh(3, 0); 
		control_xilanh(5, 0); 
		control_xilanh(7, 0); 
	}

}


void test_xilanh(void) {
	
	control_xilanh(1, 0); 
	control_xilanh(2, 0); 
	control_xilanh(3, 0); 
	control_xilanh(4, 0); 
	control_xilanh(5, 0); 
	control_xilanh(6, 0); 
	control_xilanh(7, 0); 
	control_xilanh(8, 0); 
	
	delayUs(3000000); 
	
	control_xilanh(1, 1); 
	control_xilanh(2, 1); 
	control_xilanh(3, 1); 
	control_xilanh(4, 1); 
	control_xilanh(5, 1); 
	control_xilanh(6, 1); 
	control_xilanh(7, 1); 
	control_xilanh(8, 1); 
	
}

void send_to_main(char data) {
	
	USART1->DR = data; 
	
}

void enable_reciver_to_main(void) {
	USART1->CR1 |= 1<<5;
}



void nut_lai_tay(void) {
	
	// khoi tao canh tay de chay tu dong : ki tu ' @ '
	khoi_tao_tu_dong(); 
	
// nang
	if(tay_ps == 'A') {
		FEE_struct.LaiTay.flag_nang = 1; 
		FEE_struct.TrangThai.len_xuong = 1; 
	}
	else
		FEE_struct.LaiTay.flag_nang = 0;
// ha 	
	if(tay_ps == 'B')  {
		FEE_struct.LaiTay.flag_ha = 1;
		FEE_struct.TrangThai.len_xuong = 0; 
	}			
	else 
		FEE_struct.LaiTay.flag_ha = 0;
// xoay trai tay 1 		
	if(tay_ps == 'C') 
		FEE_struct.LaiTay.flag_tay_1_xoay_trai = 1; 
	else
		FEE_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
// xoay phai tay 1 	
	if(tay_ps == 'D')
		FEE_struct.LaiTay.flag_tay_1_xoay_phai = 1; 
	else
		FEE_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
// xoay trai tay 2 	
	if(tay_ps == 'E')
		FEE_struct.LaiTay.flag_tay_2_xoay_trai = 1; 
	else
		FEE_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
// xoay phai tay 2 	
	if(tay_ps == 'F')
		FEE_struct.LaiTay.flag_tay_2_xoay_phai = 1; 
	else
		FEE_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
	
// xilanh 1
// bat dau tu 'G'  = 71 
	
	for(int i = 0; i < 8; i++) {
		if(tay_ps == (71 + i)) {
			if(FEE_struct.LaiTay.chong_nhieu_xilanh[i] == 0) {
				FEE_struct.LaiTay.flag_xilanh[i] ^=  1; 
				FEE_struct.LaiTay.chong_nhieu_xilanh[i] =  1; 
			}
		}
		else 
			FEE_struct.LaiTay.chong_nhieu_xilanh[i] = 0; 
	}
	
	// chuyen mode 
	if(tay_ps == 'z') {
		if(0 == FEE_struct.TrangThai.check_sw_mode) {
			FEE_struct.TrangThai.mode_run = 1; 
			FEE_struct.TrangThai.check_sw_mode = 1; 
		}
	}
	else 
		FEE_struct.TrangThai.check_sw_mode = 0;  
	
}

void ham_lai_tay(void) {
	// nang_ha 			
	if(FEE_struct.LaiTay.flag_nang == 1) {
		nang_canh_tay(40);
		FEE_struct.LaiTay.check_start_nang_ha = 1; 
	}

	else if(FEE_struct.LaiTay.flag_ha == 1) {
		if(GPIOA->IDR & 1<<15)  {
			ha_canh_tay(40);
			FEE_struct.LaiTay.check_start_nang_ha = 1; 
		}
		else {
			if(FEE_struct.LaiTay.check_start_nang_ha == 0)
				ha_canh_tay(0); 
			else 
				khoa_dc_tay(3); 
		}
			
	}
	else {
		if(FEE_struct.LaiTay.check_start_tay_1 == 0)
			ha_canh_tay(0);
		else 
			khoa_dc_tay(3); 
	}
			

	// cau 1 			
	if(FEE_struct.LaiTay.flag_tay_1_xoay_trai == 1) {
		xoay_trai(1, 80); 
		FEE_struct.LaiTay.check_start_tay_1 = 1;
	}

	else if(FEE_struct.LaiTay.flag_tay_1_xoay_phai == 1) {
		xoay_phai(1, 80); 
		FEE_struct.LaiTay.check_start_tay_1 = 1;
	}
		
	else {
		if(FEE_struct.LaiTay.check_start_tay_1 == 0)
			xoay_trai(1, 0); 
		else 
			khoa_dc_tay(1); 
	}
	// cau 2 
	if(FEE_struct.LaiTay.flag_tay_2_xoay_trai == 1) {
		xoay_trai(2, 80); 
		FEE_struct.LaiTay.check_start_tay_2 = 1;
	}

	else if(FEE_struct.LaiTay.flag_tay_2_xoay_phai == 1) {
		xoay_phai(2, 80); 
		FEE_struct.LaiTay.check_start_tay_2 = 1;
	}
		
	else {
		if(FEE_struct.LaiTay.check_start_tay_2 == 0)
			xoay_trai(2, 0); 
		else 
			khoa_dc_tay(2); 
	}

	// xilanh tay kep 			
	for(uint8_t i = 0; i < 8;  i++) {

		if(FEE_struct.LaiTay.flag_xilanh[i] == 1) 
			control_xilanh(i + 1, 1); 
		else 
			control_xilanh(i + 1, 0); 
	}
	
}

void reset_check_xoay_tay_1(void) {
	TIM2->CNT = 0; 
}

void reset_check_xoay_tay_2(void) {
	TIM3->CNT = 0; 
}

int check_xoay_tay_1(float second_limit) {
	float tem1 =  5000 * second_limit; 
	int tem2 = (int)tem1; 
	if(TIM2->CNT > tem2) 
		return 1; 
	else 
		return 0; 
	
}

int check_xoay_tay_2(float second_limit) {
	float tem1 = 5000 * second_limit; 
	int tem2 = (int)tem1; 
	if(TIM3->CNT > tem2) 
		return 1; 
	else 
		return 0; 
	
}

void khoi_tao_tu_dong(void) {
	
	// khoi tao canh tay de chay tu dong : ki tu ' @ ' 
	if(40 == tay_ps) {
		if(0 == FEE_struct.TrangThai.khoi_tao_tu_dong) {
			
			FEE_struct.TrangThai.vi_tri_kep_lua = 0; 
			mode_tem = FEE_struct.TrangThai.mode_run; 
			FEE_struct.TrangThai.mode_run = 2; 
			
			if(GPIOB->IDR & 1<<5)
				xoay_trai(1, 0);
			else 
				xoay_trai(1, 50);
			
			delayUs(5000); 
			
			if(GPIOB->IDR & 1<<4)
				xoay_trai(2, 0); 
			else
				xoay_trai(2, 50); 
			
			delayUs(5000);
			
			if(GPIOA->IDR & 1<<15) {
				FEE_struct.TrangThai.home = 0; 
				ha_canh_tay(50); 
			}
			else 
				ha_canh_tay(0); 
			
			if(GPIOA->IDR & 1<<15) {}
				
			else {
				khoi_tao_kep_lua(); 
				FEE_struct.TrangThai.vi_tri_kep_lua = 1; 
			}
			FEE_struct.TrangThai.khoi_tao_tu_dong = 1; 		
		}
	}
	else 
		FEE_struct.TrangThai.khoi_tao_tu_dong = 0; 
	
}


void khoi_tao_kep_lua(void) {
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.kep_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(70);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(70);
	}
	
}

void tinh_vi_tri_tay_xoay(uint8_t tay_number) {
	
	if(1 == tay_number) {
		if(0 == FEE_struct.TrangThai.chieu_xoay_1) 
			FEE_struct.TrangThai.vi_tri_tay_1_hien_tai++; 
		else 
			FEE_struct.TrangThai.vi_tri_tay_1_hien_tai--; 
	}
	else if(2 == tay_number) {
		if(0 == FEE_struct.TrangThai.chieu_xoay_2) 
			FEE_struct.TrangThai.vi_tri_tay_2_hien_tai++; 
		else 
			FEE_struct.TrangThai.vi_tri_tay_2_hien_tai--; 		
		
	}
	
	
}

