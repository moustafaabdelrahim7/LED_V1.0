﻿#include "dio.h"

//*********************************APIS IMPLEMENTATION****************************************/

/*/**DESCRIPTION:-
it intiallizes a PIN with a certain status
   */
DIO_ERROR_TYPE DIO_INITPIN(uint8_t PIN,DIO_PINSTATUS_TYPE STATUS)
{
	uint8_t PIN_NUM;
	uint8_t PORT;
	DIO_ERROR_TYPE	Status=VALID_DIO;
	PORT=PIN/8;                                  //to determine which port i'm using
	PIN_NUM=PIN%8;                               //to determine which pin in the port i'm using 
	if(PORT>4)
	{
		Status= INVALID_PORT;
	}
	else if(PIN_NUM>32)
	{
		Status= INVALID_PIN_NUMBER;
	}
	else
	 {
		switch(STATUS)
		{
			case INFREE:
				switch(PORT)
				{
					case PA:
					{
						clear_bit(DDRA,PIN_NUM);
						clear_bit(PORTA,PIN_NUM);       /*to make sure that the port register  is cleared in case of reuse*/
					}
					break;
				
					case PB:
					{
						clear_bit(DDRB,PIN_NUM);	
						clear_bit(PORTB,PIN_NUM);
					}
					break;

					case PC:
					{
						clear_bit(DDRC,PIN_NUM);
						clear_bit(PORTC,PIN_NUM);
					}
					break;

					case PD:
					{
						clear_bit(DDRD,PIN_NUM);
						clear_bit(PORTD,PIN_NUM);
					}
					break;
					
					default:
					{
						Status=INVALID_PORT;
					}
					break;
					
				}
				break;
		
			case INPLUP:
			
				switch(PORT)
				{
					case PA:
					{
						clear_bit(DDRA,PIN_NUM);
						set_bit(PORTA,PIN_NUM);
					}
					break;
			
					case PB:
					{
						clear_bit(DDRB,PIN_NUM);
						set_bit(PORTB,PIN_NUM);
					}
					break;


					case PC:
					{
						clear_bit(DDRC,PIN_NUM);
						set_bit(PORTC,PIN_NUM);
					}
					break;

					case PD:
					{
						clear_bit(DDRD,PIN_NUM);
						set_bit(PORTD,PIN_NUM);
					}
					break;
					
					default:
					{
						Status=INVALID_PORT;
					}
					break;	
				}
				break;
		
		
			case OUTPUT:
				switch(PORT)
				{
					case PA:
					{
						clear_bit(PORTA,PIN_NUM);
						set_bit(DDRA,PIN_NUM);
					}
					break;
			
					case PB:
					{
						clear_bit(PORTB,PIN_NUM);
						set_bit(DDRB,PIN_NUM);
					}
					break;

					case PC:
					{
						clear_bit(PORTC,PIN_NUM);
						set_bit(DDRC,PIN_NUM);
					}
					break;

					case PD:
					{
						clear_bit(PORTD,PIN_NUM);
						set_bit(DDRD,PIN_NUM);	
					}
					break;
					
					default:
					{
						Status=INVALID_PORT;
					}
					break;
				}
				break;

		}
	}
	return Status;
}
/**********************************************************************************************/		

/**DESCRIPTION:-
this is used to set a pin into active high/low state
**/
DIO_ERROR_TYPE DIO_WRITEPIN(uint8_t PIN,DIO_VOLTAGE_TYPE VOLTAGE)
{
	
	uint8_t PIN_NUM;
	uint8_t PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	DIO_ERROR_TYPE	Status=VALID_DIO;
	if(PORT>4)
	{
		Status= INVALID_PORT;
	}
	else if(PIN_NUM>32)
	{
		Status= INVALID_PIN_NUMBER;
	}
	else if(VOLTAGE>1)
	{
		Status= INVALID_VOLTAGE;
	}
	else 
	{
	
		if(VOLTAGE==HIGH)
		{
			switch(PORT)
			{
				case PA:
				{
					set_bit(PORTA,PIN_NUM);	
				}
				break;
				
				case PB:
				{
					set_bit(PORTB,PIN_NUM);
				}
				break;
				
				case PC:
				{
					set_bit(PORTC,PIN_NUM);
				}				
				break;
				
				case PD:
				{
					set_bit(PORTD,PIN_NUM);
				}		
				break;
				
				default:
				{
					Status=INVALID_PORT;
				}
				break;
			}
		}


		else if(VOLTAGE==LOW)
		{
			switch(PORT)
			{
				case PA:
				{
					clear_bit(PORTA,PIN_NUM);
				}				
				break;
				
				case PB:
				{
					clear_bit(PORTB,PIN_NUM);
				}				
				break;
				
				case PC:
				{
					clear_bit(PORTC,PIN_NUM);
				}				
				break;
				
				case PD:
				{
					clear_bit(PORTD,PIN_NUM);
				}				
				break;
				
				default:
				{
					Status=INVALID_PORT;
				}
				break;

			}
		}
	}
	return Status;
}

/********************************************************************************************/

/**DESCRIPTION:-
it reads a pin and return it's voltage state
*/
DIO_ERROR_TYPE DIO_READPIN(uint8_t PIN,DIO_VOLTAGE_TYPE* VOLT)
{
	uint8_t PIN_NUM;
	uint8_t PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	DIO_ERROR_TYPE	Status=VALID_DIO;
	if(PORT>4)
	{
		Status= INVALID_PORT;
	}
	else if(PIN_NUM>32)
	{
		Status= INVALID_PIN_NUMBER;
	}
	else
	{
		
		switch(PORT)
		{
			case PA:
			{
				*VOLT=read_bit(PINA,PIN_NUM);
			}
			break;
			
			case PB:
			{
				*VOLT=read_bit(PINB,PIN_NUM);
			}			
			break;
			
			case PC:
			{
				*VOLT=read_bit(PINC,PIN_NUM);
			}			
			break;
			
			case PD:
			{
				*VOLT=read_bit(PIND,PIN_NUM);
			}		
			break;
			
			default:
			{
				Status=INVALID_PORT;
			}
			break;
			
		}
	}
	return Status;
}
/********************************************************************************************************************/
/**DESCRIPTION:-
this function toggels the pin from high to low or vise versa 
**/

void DIO_TogglePin(uint8_t pin)
{
	uint8_t pin_num =pin%8;
	uint8_t  port= pin/8;
	DIO_ERROR_TYPE	Status=VALID_DIO;
	switch (port)
	{
		case PA:
		{
			toggel_bit(PORTA,pin_num);	
		} 
		 break;
		 
		case PB:
		{
			toggel_bit(PORTB,pin_num);
		} 
		 break;
		 
		case PC:
		 {
			toggel_bit(PORTC,pin_num);
		 }
		 break;
		 
		case PD:
		{
			 toggel_bit(PORTD,pin_num); 
		}
		break;
		
		default:
		{
			Status=INVALID_PORT;
		}
		break;
	}
	
	return Status;
	
}

/*************************************************************************************************************************/
void DIO_WritePort(DIO_PORT_TYPE port ,uint8_t data)
{
	DIO_ERROR_TYPE	Status=VALID_DIO;
	switch(port)
	{
		case PA: 
		 {
		 	PORTA=data;
		 }  
			break;
			
		case PB:
		 {
			 PORTB=data;
		 }
		   break;
		case PC:
		 {
			 PORTC=data;
		 }
		  break;
		case PD:
		 {
			 PORTD=data;
		 } 
		  break;
		  
		  default:
		  {
			  Status=INVALID_PORT;
		  }
		  break;
		
	}
}


/***************************/
/*it intializes the whole MCU based on the PinStatusArray In the DIO_lcfg*/
void DIO_Init_MCU(void)
{
	uint8_t i;
	for(i=0; i<TOTAL_PINS ;i++)
	{
		DIO_INITPIN(i,PinsStatusArray[i]);
	}
}
/******************************************************************************************************************************************************************************/
/*it intializes a certain amount of pins based on the PINS_total in the dio.h and the type of config in the dio_arr*/

void DIO_Init(void)
{
	uint8_t i;
	for(i=0; i<Pins_Total ;i++)
	{
		DIO_INITPIN(dio_arr[i].pin,dio_arr[i].status);
	}
}
//************************************************************************************************
