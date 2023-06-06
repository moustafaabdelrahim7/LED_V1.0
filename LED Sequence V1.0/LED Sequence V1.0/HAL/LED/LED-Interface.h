

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../MCAL/DIO/dio.h"





typedef enum {
	VALID_LED,
	INVALID_LED_PORT,
	INVLAID_LED_PIN_NUMBER
}LED_ERROR_TYPE;
 LED_ERROR_TYPE LED_INIT(uint8_t PIN);
 LED_ERROR_TYPE LED_ON(uint8_t PIN);
 LED_ERROR_TYPE LED_OFF(uint8_t PIN);





#endif /* LED-INTERFACE_H_ */