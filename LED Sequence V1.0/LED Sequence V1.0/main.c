
#include "MCAL/DIO/dio.h"
#include "HAL/button/button.h"
#include "HAL/LED/LED-Interface.h"
#include "util/delay.h"
#define   F_CPU 8000000UL

int main(void)
{
	/**********intializing hal*************/
	LED_INIT(pina0);
	LED_INIT(pina1);
	LED_INIT(pina2);
	LED_INIT(pina3);
	Button_INIT(pinc1);
	/*****************variables***********/
	uint8_t VOLT=0;
	uint8_t FLAG=0;
	
	while(1)
	{
		Button_read(pinc1,&VOLT);
		if(!VOLT)
		{
			if(FLAG==0)
			{
				LED_ON(pina0);
				FLAG++;
				_delay_ms(300);
			}
			else if(FLAG==1)
			{
				LED_ON(pina1);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==2)
			{
				LED_ON(pina2);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==3)
			{
				LED_ON(pina3);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==4)
			{
				LED_OFF(pina0);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==5)
			{
				LED_OFF(pina1);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==6)
			{
				LED_OFF(pina2);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==7)
			{
				LED_OFF(pina3);
				_delay_ms(300);
				FLAG=0;
			}
			
		}

	}
	}
	

