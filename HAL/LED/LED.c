/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : HAL **************************/
/******************** Driver : LED *************************/
/***********************************************************/
/***********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "LED.h"
#include "LED_config.h"
//#include <util/delay.h>

void LED_init(void)
{
	/*Set the directions of all leds' pins as OUTPUT*/
	DIO_SETpinDir(LED_PORT,LED0_PIN,DIO_OUTPUT);
	DIO_SETpinDir(LED_PORT,LED1_PIN,DIO_OUTPUT);
	DIO_SETpinDir(LED_PORT,LED2_PIN,DIO_OUTPUT);
	DIO_SETpinDir(LED_PORT,LED3_PIN,DIO_OUTPUT);
}

/*Implementation of Turn led on function*/
void TurnLedON(uint8_t u8_LED)
{
	/*Turn the selected led ON*/
	switch(u8_LED)
	{
	case LED0:DIO_SETpinVal(LED_PORT,LED0_PIN,DIO_HIGH);break;
	case LED1:DIO_SETpinVal(LED_PORT,LED1_PIN,DIO_HIGH);break;
	case LED2:DIO_SETpinVal(LED_PORT,LED2_PIN,DIO_HIGH);break;
	case LED3:DIO_SETpinVal(LED_PORT,LED3_PIN,DIO_HIGH);break;
	}
}

/*Implementation of Turn led off function*/
void TurnLedOFF(uint8_t u8_LED)
{
	/*Turn the selected led OFF*/
	switch(u8_LED)
	{
	case LED0:DIO_SETpinVal(LED_PORT,LED0_PIN,DIO_LOW);break;
	case LED1:DIO_SETpinVal(LED_PORT,LED1_PIN,DIO_LOW);break;
	case LED2:DIO_SETpinVal(LED_PORT,LED2_PIN,DIO_LOW);break;
	case LED3:DIO_SETpinVal(LED_PORT,LED3_PIN,DIO_LOW);break;
	}
}

/*Implementation of blinking led function*/
/*void BlinkLed(uint8_t u8_LED,uf32_t time_ms)
{*/
	/*Blink the selected led by the time entered*/
	/*switch(u8_LED)
	{
	case LED0:	DIO_SETpinVal(LED_PORT,LED0_PIN,DIO_HIGH);
			_delay_ms(time_ms);
			DIO_SETpinVal(LED_PORT,LED0_PIN,DIO_LOW);
			_delay_ms(time_ms);break;
	case LED1:DIO_SETpinVal(LED_PORT,LED1_PIN,DIO_HIGH);
			_delay_ms(time_ms);
			DIO_SETpinVal(LED_PORT,LED1_PIN,DIO_LOW);
			_delay_ms(time_ms);break;
	case LED2:DIO_SETpinVal(LED_PORT,LED2_PIN,DIO_HIGH);
			_delay_ms(time_ms);
			DIO_SETpinVal(LED_PORT,LED2_PIN,DIO_LOW);
			_delay_ms(time_ms);break;
	case LED3:DIO_SETpinVal(LED_PORT,LED3_PIN,DIO_HIGH);
			_delay_ms(time_ms);
			DIO_SETpinVal(LED_PORT,LED3_PIN,DIO_LOW);
			_delay_ms(time_ms);break;
	}

}*/

/*Implementation of toggling led function*/
void ToggleLED(uint8_t u8_LED)
{
	static uint8_t u8_state; //local variable to get the pin state
	/*Get the state of the selected led*/
	switch(u8_LED)
	{
	case LED0:DIO_GETpinVal(LED_PORT,LED0_PIN,&u8_state);break;
	case LED1:DIO_GETpinVal(LED_PORT,LED1_PIN,&u8_state);break;
	case LED2:DIO_GETpinVal(LED_PORT,LED2_PIN,&u8_state);break;
	case LED3:DIO_GETpinVal(LED_PORT,LED3_PIN,&u8_state);break;
	}

	/*Check if the led on or off & toggle the state*/
	if(u8_state==DIO_LOW)
	{
		u8_state=DIO_HIGH;
	}
	else if(u8_state==DIO_HIGH)
	{
		u8_state=DIO_LOW;
	}
	/*Give the selected led the current state*/
	switch(u8_LED)
	{
	case LED0:DIO_SETpinVal(LED_PORT,LED0_PIN,u8_state);break;
	case LED1:DIO_SETpinVal(LED_PORT,LED1_PIN,u8_state);break;
	case LED2:DIO_SETpinVal(LED_PORT,LED2_PIN,u8_state);break;
	case LED3:DIO_SETpinVal(LED_PORT,LED3_PIN,u8_state);break;
	}
}
