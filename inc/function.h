

#ifndef		__FUNCTION__

#define	__FUNCTION__

#include "config.h"

void control_xilanh(uint8_t xilanh_number, uint8_t trang_thai_xilanh); 
void nang_canh_tay(uint8_t toc_do); 
void ha_canh_tay(uint8_t toc_do); 
void xoay_phai(uint8_t tay_number, uint8_t toc_do); 
void xoay_trai(uint8_t tay_number, uint8_t toc_do); 

void khoa_dc_tay(uint8_t dc_number); 

void kep(uint8_t chan_le); 

void nha(uint8_t chan_le); 

void test_xilanh(void); 

void send_to_main(char data); 

void enable_reciver_to_main(void); 

void nut_lai_tay(void); 

void ham_lai_tay (void); 

void reset_check_xoay_tay_1(void); 
void reset_check_xoay_tay_2(void); 

int check_xoay_tay_1(float second_limit); 
int check_xoay_tay_2(float second_limit); 


void khoi_tao_tu_dong(void); 

void khoi_tao_kep_lua(void); 

void tinh_vi_tri_tay_xoay(uint8_t tay_number); 
#endif

