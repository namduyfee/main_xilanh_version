
#include "tu_dong.h"

extern FEE_struct_def FEE_struct; 

void tu_dong_1(void) {
	
	delayUs(1500000); // time day xilanh ra 
	kep(1); 
	delayUs(800000); // time kep 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.tha_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.tha_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(100);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.tha_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(100);
	}
}

void tu_dong_2(void) {
	
	control_xilanh(7, 0); 
	control_xilanh(1, 0); 
	delayUs(1000000); 
	
	xoay_trai(1, 70); 
	FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 2; 
	
	delayUs(5000);
	xoay_phai(2, 70);
	FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai - 2; 
	reset_check_xoay_tay(); 
	
}

void tu_dong_3(void) {
	
	control_xilanh(5, 0); 
	control_xilanh(3, 0); 
	delayUs(1000000); 		// time xilanh nha 
	
//	xoay_phai(1, 40);
//	delayUs(5000);
//	xoay_trai(2, 40); 
//	reset_check_xoay_tay(); 
	
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

void tu_dong_4(void) {
	
	delayUs(1500000);			// time day xilanh 
	kep(2); 
	delayUs(1000000); 			// time kep xilanh 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.gap_lua_len; 
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.gap_lua_len) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(90);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.gap_lua_len) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(90);
	}
}

void tu_dong_5(void) {
	
	delayUs(600000); 				// day xilanh ra tranh viec quay va mac lua vao robot 
	
	xoay_trai(1, 70);
	FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 1; 
	delayUs(5000);
	xoay_phai(2, 70); 
	FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai  - 1; 
	reset_check_xoay_tay(); 
	
	delayUs(700000); 					//thoi gian tranh lua dap vao bac de lua
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.kep_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(80);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(80);
	}

}

void tu_dong_6(void) {
	
	kep(1); 
	delayUs(1000000); 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.di_tha_lua; 
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.di_tha_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(80);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.di_tha_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(80);
	}
	
	delayUs(700000); 

}

