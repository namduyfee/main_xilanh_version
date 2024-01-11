
#include "tu_dong.h"

#define tha_lua 16
#define gap_lua_len 8
#define di_tha_lua 7
#define tranh_cham_lua 34 


void tu_dong_1(void) {
	
	kep(1); 
	delayUs(1000000); 
	stop_nang_ha = tha_lua;
	trang_thai = 1;
	nang_canh_tay(70);
	delayUs(500000);
	xoay_trai(1, 50); 
	xoay_phai(2, 70);

}

void tu_dong_2(void) {
	control_xilanh(3, 0); 
	control_xilanh(5, 0); 
	delayUs(500000); 
	xoay_trai(1, 50); 
	xoay_phai(2, 60);
}

void tu_dong_3(void) {
	
	control_xilanh(1, 0); 
	control_xilanh(7, 0); 
	delayUs(500000); 
	xoay_phai(1, 50);
	xoay_trai(2, 60); 
	home = 0;  
	trang_thai = 0; 
	ha_canh_tay(70); 
	
}

void tu_dong_4(void) {
	kep(2); 
	delayUs(50000e0); 
	trang_thai = 1; 
	stop_nang_ha = tranh_cham_lua; 
	nang_canh_tay(70); 

}

void tu_dong_5(void) {
	
	home = 0; 
	ha_canh_tay(70); 
	trang_thai = 0; 
	xoay_phai(1, 60);
	xoay_trai(2, 70); 

}

void tu_dong_6(void) {
	
	kep(1); 
	delayUs(500000); 
	stop_nang_ha = di_tha_lua; 
	nang_canh_tay(70); 
	trang_thai = 1; 
	delayUs(500000);

}

