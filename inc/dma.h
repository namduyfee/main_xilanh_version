

#ifndef		__DMA__

#define	__DMA__ 

#include <stm32f10x.h> 

void configDMA1(void); 

// U1 : channel 5_RX, 4_TX; 
// U2 : 6_RX, 7_TX; 
// U3 : 3_RX, 2_TX
// mode = 0 : RX , mode = 1 : TX   

void initDMA1Channel1(volatile uint16_t* address_memory, volatile uint8_t* address_periph, uint16_t size); 
void initDMA1Channel5(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size);
void initDMA1Channel6(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size);
void initDMA1Channel3(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size);
void initDMA1Channel2(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size); 
void initDMA1Channel4(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size); 
void initDMA1Channel7(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size); 

void enItDma(uint8_t uart, uint8_t mode); 
void disEnItDma(uint8_t uart, uint8_t mode); 

#endif	
