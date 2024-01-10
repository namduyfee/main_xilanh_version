
#include "config.h" 
#include "stdio.h"
#include "function.h"

uint16_t tay_ps; 

uint8_t start = 0; 

uint8_t tem = 0; 

uint8_t stop_nang_ha = 0; 

uint8_t vi_tri_nang_ha = 0; 

// trang_thai = 1 : nang len ; trang_thai = 0 : ha xuong 
uint8_t trang_thai = 0; 

dc canh_tay = {0x01, 60, 0xFF, 0x02, 60, 0xFF, 0x83, 60, 0xFF}; 


int check = 0; 


int main() {
	
	
	config(); 
	test_xilanh(); 
	
	while(1) {
 
	} 
	return 0; 
	
}

