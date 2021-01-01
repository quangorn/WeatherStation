#include "lcd.h"
#include "spi/spi.h"
#include <avr/io.h>
#include <util/delay.h>

#define RS_PORT_DDR        DDRB
#define RS_PORT_OUTPUT     PORTB
#define RS_BIT             2
#define CS_PORT_DDR        DDRB
#define CS_PORT_OUTPUT     PORTB
#define CS_BIT             1

void lcdRsLow() {
	RS_PORT_OUTPUT &= ~(1 << RS_BIT);
}

void lcdRsHigh() {
	RS_PORT_OUTPUT |= 1 << RS_BIT;
}

void lcdCsLow() {
	CS_PORT_OUTPUT &= ~(1 << CS_BIT);
}

void lcdCsHigh() {
	CS_PORT_OUTPUT |= 1 << CS_BIT;
}

void sendCmd(uint8_t dat) {
	lcdRsLow();
	lcdCsLow();
	
	spiWrite(dat);
	
	lcdCsHigh();
}

void sendDat(uint8_t dat) {
	lcdRsHigh();
	lcdCsLow();
	
	spiWrite(dat);
	
	lcdCsHigh();
}

void sendDat16(uint16_t dat) {
	lcdRsHigh();
	lcdCsLow();
	
	uint8_t* buf = (uint8_t*)&dat;
	spiWrite(buf[1]);
	spiWrite(buf[0]);
	
	lcdCsHigh();
}

void lcdInit() {
	RS_PORT_DDR |= 1 << RS_BIT;
	CS_PORT_DDR |= 1 << CS_BIT;
	
	lcdRsLow();
	_delay_ms(10);
	
	lcdRsHigh();
	_delay_ms(10);
	
	sendCmd(0x01);
	_delay_ms(12);

	sendCmd(0x11);
	_delay_ms(12);
	
	sendCmd(0x3A);	

	sendDat(0x05);		
	
	sendCmd(0x36);
	sendDat(0xA0); 
	
	sendCmd(0xB1);	
	sendDat16(0x000F); 
	sendDat16(0x000F); 
	sendDat16(0x000F); 
	
	sendCmd(0x29);	
}

