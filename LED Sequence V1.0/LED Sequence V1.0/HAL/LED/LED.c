#include "LED-Interface.h"

LED_ERROR_TYPE LED_INIT(uint8_t PIN)
 {
	 uint8_t PIN_NUM;
	 uint8_t PORT;
	 PORT=PIN/8;
	 PIN_NUM=PIN%8;
	 if(PORT>4)
	 {
		 return INVALID_LED_PORT;
	 }
	 else if(PIN_NUM>32)
	 {
		 return INVLAID_LED_PIN_NUMBER;
	 }
	 else
	 {
	 DIO_INITPIN(PIN,OUTPUT);
	 return VALID_LED;
	 }
 }
 LED_ERROR_TYPE LED_ON(uint8_t PIN)
 {
	 uint8_t PIN_NUM;
	 uint8_t PORT;
	 PORT=PIN/8;
	 PIN_NUM=PIN%8;
	 if(PORT>4)
	 {
		 return INVALID_LED_PORT;
	 }
	 else if(PIN_NUM>32)
	 {
		 return INVLAID_LED_PIN_NUMBER;
	 }
	 else
	 {
	 DIO_WRITEPIN(PIN,HIGH);
	 return VALID_LED;
	 }
 }
 LED_ERROR_TYPE LED_OFF(uint8_t PIN)
 {
	 uint8_t PIN_NUM;
	 uint8_t PORT;
	 PORT=PIN/8;
	 PIN_NUM=PIN%8;
	 if(PORT>4)
	 {
		 return INVALID_LED_PORT;
	 }
	 else if(PIN_NUM>32)
	 {
		 return INVLAID_LED_PIN_NUMBER;
	 }
	 else
	 {
	 DIO_WRITEPIN(PIN,LOW);
	 return VALID_LED;
	 }
 }