/***********************************************************/
/***********************************************************/
/******************** Author : Mohamed Alaa ****************/
/******************** Layer : HAL **************************/
/******************** Driver : LED *************************/
/***********************************************************/
/***********************************************************/
#ifndef _LED_H_
#define _LED_H_

/*Insert LEDS you want and give it number*/
#define LED0	0
#define LED1	1
#define LED2	2
#define LED3	3

/*Set Leds Direction*/
void LED_init(void);

/*Declaration of Turn led on function*/
void TurnLedON(uint8_t u8_LED);

/*Declaration of Turn led off function*/
void TurnLedOFF(uint8_t u8_LED);

/*Declaration of blinking led function*/
void BlinkLed(uint8_t u8_LED,uf32_t time_ms);

/*Declaration of toggling led state function*/
void ToggleLED(uint8_t u8_LED);

#endif
