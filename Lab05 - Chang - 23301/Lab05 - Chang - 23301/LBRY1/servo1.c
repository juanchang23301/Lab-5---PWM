#define F_CPU 16000000
#include "servo1.h"

void servo_init(void) {
	// Configurar los pines OC0A y OC0B como salidas
	DDRD |= (1 << SERVO_PIN_OC0A) | (1 << SERVO_PIN_OC0B);
	
	// Configurar el timer en modo Fast PWM
	TCCR0A = (1 << WGM01) | (1 << WGM00);               
	
	// Configurar OC0A y OC0B en modo no invertido
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
	
	// Configurar prescaler a 1024
	TCCR0B |= (1 << CS02) | (1 << CS00);
	
	// iniciar servo en 0 grados
	OCR0A = SERVO_MIN;
	OCR0B = SERVO_MIN;
}

void servo_positionA(uint8_t pos) {
	// Limitar a 180 grados el potenciometro
	if (pos > 180) pos = 180;
	
	uint8_t duty = SERVO_MIN + (((SERVO_MAX - SERVO_MIN) * (uint16_t)pos) / 180);
	
	OCR0A = duty;
}

void servo_positionB(uint8_t pos) {
	// Limitar a 180 grados el potenciometro
	if (pos > 180) pos = 180;
	
	uint8_t duty = SERVO_MIN + (((SERVO_MAX - SERVO_MIN) * (uint16_t)pos) / 180);
	
	OCR0B = duty; 
	}