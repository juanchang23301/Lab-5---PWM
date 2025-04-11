#ifndef servo1_H
#define servo1_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

// Definiciones de pines de Timer 0 
#define SERVO_PIN_OC0A PIND6 
#define SERVO_PIN_OC0B PIND5 

// Valores límite para el servo (para un ciclo de 20ms)
#define SERVO_MIN 8.0   
#define SERVO_MAX 37.0  


void servo_init(void);                      // Inicializar el Timer 0 para control de servos
void servo_positionA(uint8_t pos);  // Establecer posición del servo en OC0A (0-180)
void servo_positionB(uint8_t pos);  // Establecer posición del servo en OC0B (0-180)
void servo_disable(void);                   // Desactivar la salida PWM

#endif 