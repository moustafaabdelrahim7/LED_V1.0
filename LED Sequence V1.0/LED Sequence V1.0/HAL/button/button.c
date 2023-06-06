#include "button.h"

BUTTON_ERROR_TYPE Button_INIT(uint8_t PIN)
{
	uint8_t PIN_NUM;
	uint8_t PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
	DIO_INITPIN(PIN,INPLUP);
	return VALID_BUTTON;
	}
}
BUTTON_ERROR_TYPE Button_read(uint8_t PIN,DIO_VOLTAGE_TYPE*VOLT)
{
	uint8_t PIN_NUM;
	uint8_t PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_BUTTON_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVALID_BUTTON_PIN_NUMBER;
	}
	else
	{
	DIO_READPIN(PIN,VOLT);
	return VALID_BUTTON;
	}
}