/************************************************************************
 Universidad del Valle de Guatemala
 IE2023: Programaci�n de Microcontroladores
 Control de Servomotor con Potenci�metro
 Autor: Juan Ren� Chang Lam
 Descripci�n: Implementa un sistema que lee un potenci�metro y controla
              la posici�n de un servomotor utilizando ADC y PWM.
 * Conexiones:
 * - PC0: Potenci�metro (pin A0 en Arduino Nano)
 * - PB1: Se�al de control del servo (pin 9 en Arduino Nano)
************************************************************************/


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "LBRY1/servo1.h"


void adc_init() {
	// Configurar referencia a AVCC
	ADMUX = (1 << REFS0);
	
	// Habilitar ADC con prescaler a 128
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}


uint16_t adc_read(uint8_t canal) {
	// Seleccionar el canal (0-7)
	ADMUX = (ADMUX & 0xF0) | (canal & 0x0F);
	
	// Iniciar conversi�n
	ADCSRA |= (1 << ADSC);
	
	while (ADCSRA & (1 << ADSC));
	
	return ADC;
}

int main(void) {
	uint16_t pot1;
	
	// Inicializar ADC
	adc_init();
	
	servo_init();
	
	while (1) {
		// Leer valores de los potenci�metros
		pot1 = adc_read(0);  // Potenci�metro en PINC0
		
		// Mapear valores de los potenci�metros (0-1023) a posici�n del servo (0-180)
		
		OCR0A = pot1 * (SERVO_MAX - SERVO_MIN) / 1023 + SERVO_MIN;
		
		// Peque�o retraso para estabilidad
		_delay_ms(5);
	}
	
	return 0;
}