
#ifndef		__CONF__

#define	__CONF__

#include <stm32f10x.h>

#include "gpio.h"
#include "timer.h"
#include "servo.h" 
#include "nvic.h"
#include "exti.h" 
#include "dma.h"
#include "uart.h"
#include "i2c.h"
#include "function.h" 
#include "tu_dong.h" 


// ===================== STRUCT ================== // 
 
typedef struct {
	uint8_t diachi_trai; 
	uint8_t tocdo_trai; 
	uint8_t end_trai; 
	uint8_t diachi_phai; 
	uint8_t tocdo_phai; 
	uint8_t end_phai;
	uint8_t diachi_keo; 
	uint8_t tocdo_keo; 
	uint8_t end_keo;
} canh_tay; 


typedef struct {
	// 0 : 0 làm , 1 : lam 
	uint8_t flag_xilanh[8];  
	uint8_t chong_nhieu_xilanh[8];  
	uint8_t flag_nang; 
	uint8_t flag_ha; 
	uint8_t flag_tay_1_xoay_trai; 
	uint8_t flag_tay_1_xoay_phai;
	uint8_t flag_tay_2_xoay_trai; 
	uint8_t flag_tay_2_xoay_phai;
	uint8_t check_start_nang_ha; 
	uint8_t check_start_tay_1; 
	uint8_t check_start_tay_2; 
} lai_tay; 


typedef struct {
	
	uint8_t stop_nang_ha; 
	uint8_t vi_tri_nang_ha; 
	uint8_t tha_lua; 
	uint8_t di_tha_lua;
	uint8_t gap_lua_len; 
	uint8_t kep_lua; 
	uint8_t tranh_cam_bien; 
//	uint8_t tranh_cham_lua; 	
	uint8_t tu_dong_number; 
	uint8_t day_keo_xilanh_an_toan[20]; 
	uint8_t check_cam_bien_td[20]; 
} tu_dong; 


typedef struct {
	
	uint8_t mode_run; 									// 0 : lai tay , 1 : tu dong
	uint8_t len_xuong;   							// 1 : nang , 0 : ha 
	uint8_t done[20]; 
	uint8_t home; 												// 0 : ve home và ko dem , 1 : co dem 
	uint8_t comple_reciver[20]; 		
	uint8_t khoi_tao_tu_dong; 			// tranh khoi tao nhieu lan 
	uint8_t check_sw_mode; 				// tranh chuyen mode nhieu lan 
	uint8_t vi_tri_kep_lua; 						// tranh di chuyen den vi tri kep lua khoi tao nhieu lan 
	
	uint8_t vi_tri_tay_1_hien_tai; 				// vi tri hien tai tay 1 
	uint8_t vi_tri_tay_2_hien_tai; 				// vi tri hien tai tay 2 
	uint8_t vi_tri_tay_1_mong_muon; 	// vi tri mong muon khi cho xoay trai hoac phai 
	uint8_t vi_tri_tay_2_mong_muon; 	
	
	uint8_t chieu_xoay_1; 						// chieu xoay = 0 : xoay trai ; = 1 : xoay phai 
	uint8_t chieu_xoay_2; 						// xoay trai thi vi tri tay +  , xoay phai thi vi tri tay 

	uint8_t troi_tay_1; 
	uint8_t troi_tay_2; 
	
} trang_thai; 




typedef struct {
	
	canh_tay CanhTay; 
	tu_dong TuDong; 
	lai_tay LaiTay; 
	trang_thai TrangThai; 

} FEE_struct_def; 



// ====================== FUNCTION============= //

void config(void); 
void lai_tay_init(void); 
void tu_dong_init(void); 
void canh_tay_init(void); 
void trang_thai_init(void); 

#endif

