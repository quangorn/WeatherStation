#include <avr/io.h>
//#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include <avr/eeprom.h>

#include "i2c/i2c.h"
#include "bme280/bme280_user.h"
#include "spi/spi.h"
#include "lcd/lcd.h"

//#include <avr/pgmspace.h>
//#include <common/definitions.h>
//#include <string.h>
//#include <stdbool.h>

#define LED_PORT_DDR        DDRD
#define LED_PORT_OUTPUT     PORTD
#define LED_BIT             6

void ledOn() {
	LED_PORT_OUTPUT |= 1 << LED_BIT;
}

void ledOff() {
	LED_PORT_OUTPUT &= ~(1 << LED_BIT);
}

void ledToggle() {
	LED_PORT_OUTPUT ^= 1 << LED_BIT;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "EndlessLoop"
int main(void) {
	//i2cInit();
	spiInit();
	
	
	DDRB |= 1 << 2;
	//sei();
	_delay_ms(50);
	
	lcdInit();
	
	//_delay_ms(255); /* fake USB disconnect for > 250 ms */

	LED_PORT_DDR |= 1 << LED_BIT;   /* make the LED bit an output */
	//bmeInit();
	//bmeStartInNormalMode();
	uint16_t iteration = 1;
	for (;;) {                /* main event loop */
		if ((iteration & 0x1FFF) == 0) { //every 8192 tick
			//adcReadNextSample();
		}
		if (iteration == 0) { //every 65536 tick (4 Hz)			
			//bmeGetCurrentData(&runtimeInfo);
		}
		ledToggle();
		iteration++;
		_delay_ms(1000);
	}
	return 0;
}
#pragma clang diagnostic pop
