


#include "dma.h"

void configDMA1(void) {
	
	// enable clock DMA1
	RCC->AHBENR |= 1; 
	
	// channel 1 = ADC1
	// enable TC, HT, TE
	// read from peripheral , circular mode , dich pointer memory, size 16 bits , high priority 
//	DMA1_Channel1->CCR = 0x25AE; 
	
	// channel = uart
	// enable TE
	// read from peripheral , circular mode , dich pointer memory, size 8 bits 
	
	// enable interrupt last hex 0->8 
	// channel 5 : rx_usart 1
//	DMA1_Channel5->CCR = 0x10A8; // high priority 
	// channel 6 : rx_usart 2
	DMA1_Channel6->CCR = 0x10A0; // medium
	// channel 3 : rx_usart3
	DMA1_Channel3->CCR = 0x10A0; // medium
	//	channel 4 : U1_TX
//	DMA1_Channel4->CCR = 0x10B0; // medium
	//	channel 7 : U2_Tx	
	DMA1_Channel7->CCR = 0x10B0; // medium
	//	channel 2 : U3_Tx
	DMA1_Channel2->CCR = 0x10B0; // medium
	// enable dma cr1 |= 1<<1; 
	
}

//void initDMA1Channel1(volatile uint16_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
//	
//	DMA1_Channel1->CNDTR = size; 
//	DMA1_Channel1->CMAR = address_memory; 
//	DMA1_Channel1->CPAR = address_periph; 
//	// enable DMA1 channel 1 
//	DMA1_Channel1->CCR |= 1; 
//}

void initDMA1Channel5(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel5->CNDTR = size; 
	DMA1_Channel5->CMAR = address_memory; 
	DMA1_Channel5->CPAR = address_periph; 
	// enable DMA1 channel 1 
	DMA1_Channel5->CCR |= 1; 
}

void initDMA1Channel6(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel6->CNDTR = size; 
	DMA1_Channel6->CMAR = address_memory; 
	DMA1_Channel6->CPAR = address_periph; 
	// enable DMA1 channel 1 
	DMA1_Channel6->CCR |= 1; 
}

void initDMA1Channel3(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel3->CNDTR = size; 
	DMA1_Channel3->CMAR = address_memory; 
	DMA1_Channel3->CPAR = address_periph; 
	// enable DMA1 channel 1 
	DMA1_Channel3->CCR |= 1; 
}


void initDMA1Channel4(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel4->CNDTR = size; 
	DMA1_Channel4->CMAR = address_memory; 
	DMA1_Channel4->CPAR = address_periph; 
	// enable DMA1 channel 7
	DMA1_Channel4->CCR |= 1; 
}

void initDMA1Channel7(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel7->CNDTR = size; 
	DMA1_Channel7->CMAR = address_memory; 
	DMA1_Channel7->CPAR = address_periph; 
	// enable DMA1 channel 7
	DMA1_Channel7->CCR |= 1; 
}

void initDMA1Channel2(volatile uint8_t* address_memory, volatile uint16_t* address_periph, uint16_t size) {
	
	DMA1_Channel2->CNDTR = size; 
	DMA1_Channel2->CMAR = address_memory; 
	DMA1_Channel2->CPAR = address_periph; 
	// enable DMA1 channel 7
	DMA1_Channel2->CCR |= 1; 
	
}


// mode = 0 : RX , mode = 1 : TX   

void enItDma(uint8_t uart, uint8_t mode) {
	if(mode == 0) {
		if(uart == 1 ) 
			DMA1_Channel5->CCR |= 1<<1; 
		if(uart == 2)
			DMA1_Channel6->CCR |= 1<<1; 
		if(uart == 3)
			DMA1_Channel3->CCR |= 1<<1; 
	}
	if(mode == 1) {
		if(uart == 1)
			DMA1_Channel4->CCR |= 1<<1; 
		if(uart == 2)
			DMA1_Channel7->CCR |= 1<<1; 
		if(uart == 3)
			DMA1_Channel2->CCR |= 1<<1; 
	}
}
	
void disEnItDma(uint8_t uart, uint8_t mode) {
	
	if(mode == 0) {
		if(uart == 1) 
			DMA1_Channel5->CCR &= (~(1<<1)); 
	
		if(uart == 2) 
			DMA1_Channel6->CCR &= (~(1<<1));
	
		if(uart == 3) 
			DMA1_Channel3->CCR &= (~(1<<1));
	}
	
	if(mode == 1) {
		if(uart == 1)
			DMA1_Channel4->CCR &= (~(1<<1));
		if(uart == 2)
			DMA1_Channel7->CCR &= (~(1<<1));
		if(uart == 3)
			DMA1_Channel2->CCR &= (~(1<<1));
	}
}

