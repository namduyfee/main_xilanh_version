
#include "config.h"

uint16_t tay_ps; 

FEE_struct_def FEE_struct; 


void config(void) {
	
	configGPIOA(); 
	configGPIOB(); 
	configGPIOC(); 
	configAFIO();

	configEXTI(); 

	configNVIC(); 
 
	configTIM4();
	configTIM2();
	configTIM3();
	
	configDMA1(); 
	
	configUART1(); 
	configUART2(); 
	configUART3(); 
	
//	configI2c(); 

//	configTIM1(); 


// ============= INIT FUNCTION =========== // 

	trang_thai_init (); 
	
	canh_tay_init(); 
	
	lai_tay_init(); 

	tu_dong_init(); 
	
	initDMA1Channel7(&(FEE_struct.CanhTay.diachi_trai), &(USART2->DR), 9); 
	
//	initDMA1Channel2(&(FEE_struct.CanhTay.diachi_trai), &(USART3->DR), 9); 
}

void lai_tay_init(void) {
	
	for(int i = 0; i < 8; i++) {
		FEE_struct.LaiTay.flag_xilanh[i] = 0; 
		FEE_struct.LaiTay.chong_nhieu_xilanh[i] = 0; 
	}
	FEE_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
	FEE_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
	FEE_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
	FEE_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
	FEE_struct.LaiTay.flag_nang = 0; 
	FEE_struct.LaiTay.flag_ha = 0;
	FEE_struct.LaiTay.check_start_nang_ha = 0;
	FEE_struct.LaiTay.check_start_tay_1 = 0;
	FEE_struct.LaiTay.check_start_tay_2 = 0;
	
}


void tu_dong_init(void) {
	
	FEE_struct.TuDong.tu_dong_number = 45; 		// so dep <3 
	FEE_struct.TuDong.stop_nang_ha = 0; 
	FEE_struct.TuDong.vi_tri_nang_ha = 0; 
	FEE_struct.TuDong.tha_lua = 40; 																									// tha lua vao kho 
	FEE_struct.TuDong.gap_lua_len = 20; 																						// vi tri tren lo lua 
	FEE_struct.TuDong.di_tha_lua = 10; 																							// di tha lua 
	FEE_struct.TuDong.tranh_cam_bien = 38; 																			// tranh cham sw, cam bien 
//	FEE_struct.TuDong.tranh_cham_lua = 26; 
	FEE_struct.TuDong.kep_lua = 5; 
	for(int i = 0 ; i < 20; i++) {
		FEE_struct.TuDong.day_keo_xilanh_an_toan[i] = 0; 
		FEE_struct.TuDong.check_cam_bien_td[i] = 0; 
	}
}

void canh_tay_init(void) {
	

	FEE_struct.CanhTay.diachi_trai = 0x01; 
	FEE_struct.CanhTay.tocdo_trai = 0; 
	FEE_struct.CanhTay.end_trai = 0xFF;
	
	FEE_struct.CanhTay.diachi_phai = 0x02; 
	FEE_struct.CanhTay.tocdo_phai = 0;
	FEE_struct.CanhTay.end_phai = 0xFF;
	
	FEE_struct.CanhTay.diachi_keo = 0x83; 
	FEE_struct.CanhTay.tocdo_keo = 0;
	FEE_struct.CanhTay.end_keo = 0xFF;
	
}

void trang_thai_init(void) {
	
	FEE_struct.TrangThai.mode_run = 0; 
	FEE_struct.TrangThai.len_xuong = 0; 
	
	for(int i = 0; i < 20; i++)
		FEE_struct.TrangThai.done[i] = 0; 
	
	FEE_struct.TrangThai.home = 0; 
	FEE_struct.TrangThai.khoi_tao_tu_dong = 0; 
	FEE_struct.TrangThai.check_sw_mode = 0; 
	FEE_struct.TrangThai.vi_tri_kep_lua = 0;
	
	FEE_struct.TrangThai.vi_tri_tay_1_hien_tai = 100;
	FEE_struct.TrangThai.vi_tri_tay_2_hien_tai = 100;
	
	FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = 100; 
	FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = 100;
	
	FEE_struct.TrangThai.chieu_xoay_1 = 0; 
	FEE_struct.TrangThai.chieu_xoay_2 = 0; 
	
	for(int i = 0; i < 20; i++) 
		FEE_struct.TrangThai.comple_reciver[i] = 0; 
		
	FEE_struct.TrangThai.troi_tay_1 = 0; 
	FEE_struct.TrangThai.troi_tay_2 = 0; 
}





