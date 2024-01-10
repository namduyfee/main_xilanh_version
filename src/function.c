
#include "function.h"

// A12 : 1
// A11 : 2 
// A8 : 3
// B8 : 4

// B12 : 5 <=> 1 
// B13  : 6 <=> 2 
// B14 : 7  <=> 3
// B15 : 8 <=> 4


void control_xilanh(uint8_t xilanh_number, uint8_t trang_thai) {
	
	// kep vao
	if(trang_thai == 1) {
		
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
	if(trang_thai == 0) {
		
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
	canh_tay.diachi_keo = 0x03; 
	canh_tay.tocdo_keo = toc_do; 
}


void ha_canh_tay(uint8_t toc_do) {
	canh_tay.diachi_keo = 0x83; 
	canh_tay.tocdo_keo = toc_do; 
}


void xoay_phai(uint8_t tay_number, uint8_t toc_do) {
	if(tay_number ==1) {
		canh_tay.diachi_trai = 0x81; 
		canh_tay.tocdo_trai = toc_do;
	}
	
	if(tay_number ==2) {
		canh_tay.diachi_phai = 0x82; 
		canh_tay.tocdo_phai = toc_do;
	}
	
}

void xoay_trai(uint8_t tay_number, uint8_t toc_do) {
	if(tay_number ==1) {
		canh_tay.diachi_trai = 0x01; 
		canh_tay.tocdo_trai = toc_do;
	}
	
	if(tay_number ==2) {
		canh_tay.diachi_phai = 0x02; 
		canh_tay.tocdo_phai = toc_do;
	}
	
}

void khoa_dc_tay(uint8_t dc_number) {
	
	if(dc_number == 1) 
		canh_tay.tocdo_trai = 1; 
	if(dc_number ==2)
		canh_tay.tocdo_phai = 1; 
	if(dc_number == 3) 
		canh_tay.tocdo_keo = 1; 
	
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



