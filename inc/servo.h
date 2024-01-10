


#ifndef		__MOTOR__

#define	__MOTOR__


#include <stm32f10x.h> 

void servo1(int goc1); 
void servo2(int goc2); 
void dc1(int chieu, uint16_t sped); 
void khoaDC(void); 

#endif

