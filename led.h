#ifndef __LED_H
#define __LED_H

#include <stdint.h>


#define GPIOA                   (uint32_t*)0x40020000
#define GPIOB                   (uint32_t*)0x40020400
#define GPIOC                   (uint32_t*)0x40020800
#define GPIOD                   (uint32_t*)0x40020c00

#define PIN0                    0u
#define PIN1                    1u
#define PIN2                    2u
#define PIN3                    3u
#define PIN4                    4u
#define PIN5                    5u
#define PIN6                    6u
#define PIN7                    7u
#define PIN8                    8u
#define PIN9                    9u
#define PIN10                   10u
#define PIN11                   11u
#define PIN12                   12u
#define PIN13                   13u
#define PIN14                   14u
#define PIN15                   15u

#define INPUT                   0x0u
#define OUTPUT                  0x1u
#define ALTERNATE               0x2u
#define ANALOG_INPUT            0x3u

#define SET                     1u
#define RESET                   0u

void InputOtputConfig(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode);
void ButtonToggleLed(uint32_t *GPIOx, uint8_t Pin, uint8_t LedPinValue);



#endif
