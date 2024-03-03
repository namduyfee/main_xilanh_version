
#include "tu_dong.h"

#define thoi_gian_tranh_lua_cham_robot_4_lua_cuoi 400000
#define thoi_gian_tranh_lua_cham_sw_cb_4_lua_cuoi 200000
#define thoi_gian_xilanh_day 800000
#define thoi_gian_kep_mo_xilanh 500000
#define toc_do_nang_ha 120
extern FEE_struct_def FEE_struct; 

void tu_dong_1(void) {
	
	delayUs(thoi_gian_xilanh_day); // time day xilanh ra 
	kep(1); 
	delayUs(thoi_gian_kep_mo_xilanh); // time kep 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.tha_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.tha_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.tha_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
}

void tu_dong_2(void) {
	
	delayUs(400000);				// on dinh xoay tay 
	control_xilanh(7, 0); 
	control_xilanh(1, 0); 
	delayUs(500000); 
	
	xoay_trai(1, 90); 
	FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 2; 
	reset_check_xoay_tay_1(); 
	
	
	delayUs(5000);
	
	xoay_phai(2, 90);
	FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai - 2; 
	reset_check_xoay_tay_2(); 
	
}

void tu_dong_3(void) {
	
	delayUs(400000);				// on dinh xoay tay 
	control_xilanh(5, 0); 
	control_xilanh(3, 0); 
	delayUs(500000); 		// time xilanh nha 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.kep_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
	
}

void tu_dong_4(void) {
	
	delayUs(thoi_gian_xilanh_day);			// time day xilanh 
	kep(2); 
	delayUs(thoi_gian_kep_mo_xilanh); 			// time kep xilanh 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.tranh_cam_bien; 
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.tranh_cam_bien) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.tranh_cam_bien) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
}

void tu_dong_5(void) {
	
//	delayUs(thoi_gian_tranh_lua_cham_robot_4_lua_cuoi); 				// day xilanh ra tranh viec quay va mac lua vao robot 
	
	xoay_trai(1, 90);
	FEE_struct.TrangThai.vi_tri_tay_1_mong_muon = FEE_struct.TrangThai.vi_tri_tay_1_hien_tai + 1; 
	reset_check_xoay_tay_2(); 
	
	delayUs(5000);

	xoay_phai(2, 90); 
	FEE_struct.TrangThai.vi_tri_tay_2_mong_muon = FEE_struct.TrangThai.vi_tri_tay_2_hien_tai  - 1; 
	reset_check_xoay_tay_2(); 
	
	delayUs(thoi_gian_tranh_lua_cham_sw_cb_4_lua_cuoi); 					//thoi gian tranh lua dap vao bac de lua
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.kep_lua;
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.kep_lua) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}

}

void tu_dong_6(void) {
	
	kep(1); 
	delayUs(thoi_gian_kep_mo_xilanh); 
	
	FEE_struct.TuDong.stop_nang_ha = FEE_struct.TuDong.gap_lua_len; 
	
	if(FEE_struct.TuDong.vi_tri_nang_ha < FEE_struct.TuDong.gap_lua_len) {
		FEE_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_struct.TuDong.vi_tri_nang_ha > FEE_struct.TuDong.gap_lua_len) {
		FEE_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
	
	delayUs(700000); 

}

void chong_troi(void) {

					if((0 == (GPIOB->IDR & 1<<4)) && (0 == (GPIOB->IDR & 1<<5))) {
						FEE_struct.TuDong.tu_dong_number = 2; 
						FEE_struct.TrangThai.done[2] = 0; 
					}
					else {
						if( 1 == (GPIOB->IDR & 1<<5) && (0 == FEE_struct.TrangThai.troi_tay_1)) {
							FEE_struct.TrangThai.troi_tay_1 = 1; 
							if(1 == FEE_struct.TrangThai.chieu_xoay_1)
								xoay_trai(1, 50); 
							else 
								xoay_phai(1, 50); 
						}
						
						if( 1 == (GPIOB->IDR & 1<<4) && (0 == FEE_struct.TrangThai.troi_tay_2)) {
							FEE_struct.TrangThai.troi_tay_2 = 1; 
							if(1 == FEE_struct.TrangThai.chieu_xoay_2)
								xoay_trai(2, 50); 
							else 
								xoay_phai(2, 50); 
						}
						
					}


}




