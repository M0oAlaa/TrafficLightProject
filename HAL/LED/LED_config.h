/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : HAL **************************/
/******************** Driver : LED *************************/
/***********************************************************/
/***********************************************************/
#ifndef _LED_CONFIG_H_
#define _LED_CONFIG_H_

/*Insert all Ports of the Leds*/
#define LED_PORT	DIO_PORTB

/*Insert any leds you want and select its pin location from:
															1-DIO_PIN0
															2-DIO_PIN1
															3-DIO_PIN2
															4-DIO_PIN3
															5-DIO_PIN4
															6-DIO_PIN5
															7-DIO_PIN6
															8-DIO_PIN7*/
#define LED0_PIN	DIO_PIN4
#define LED1_PIN	DIO_PIN5
#define LED2_PIN	DIO_PIN6
#define LED3_PIN	DIO_PIN7

#endif
