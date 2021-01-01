#include "spi.h"
#include <avr/io.h>

#define DDR_SPI    DDRB
#define DD_SCK     PINB5
#define DD_MOSI    PINB3

void spiInit() {
	//Настройка MOSI и SCK как выход, все остальные сигналы как вход
	DDR_SPI |= (1 << DD_MOSI)|(1 << DD_SCK);
	//Разрешить работу SPI, режим Master, установить скорость тактов fck/2
	SPCR = (1 << SPE)|(1 << MSTR);
	SPSR = (1 << SPI2X);
}

void spiWrite(uint8_t data) {
	//Запуск передачи данных
	SPDR = data;
	//Ожидание завершения передачи
	while (!(SPSR & (1 << SPIF)));
}
