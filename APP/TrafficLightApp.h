/**********************************************************************/
/**********************************************************************/
/*****************		Author: Mohamed Alaa	***********************/
/*****************		Layer:	APP				***********************/
/*****************		Project:Traffic light	***********************/
/**********************************************************************/
/**********************************************************************/
#ifndef _APP_H_
#define _APP_H_

#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"

#include "../HAL/LED/LED.h"

uint8_t Check_sentData(uint8_t* data,uint8_t* Order);

uint8_t local_u8Str[255];//An array which holds the received data
uint8_t Start[]="START";//START order
uint8_t Stop[]="STOP";//STOP order
uint8_t AT[]="AT";//AT order
uint8_t Wait[]="WAIT";//WAIT order

void App_init(void)
{
	/*Led initialization*/
	LED_init();
	/*UART initialization*/
	UART_init();
	/*Receive data from user*/
	UART_AsynchReceiveStr(&local_u8Str);
	/*Send what I received*/
	UART_AsynchSendStr(&local_u8Str);
}

void App_program(void)
{
	/*Check if received data is START*/
	if(Check_sentData(&local_u8Str,&Start)==TRUE)
	{
		TurnLedON(LED0);//Turn on green led
		TurnLedOFF(LED1);//Turn off yellow red
		TurnLedOFF(LED2);//Turn off red led
		/*Send Green Led ON*/
		UART_AsynchSendStr("\n\rGreen Led ON");
	}
	/*Check if received data is WAIT*/
	else if(Check_sentData(&local_u8Str,&Wait)==TRUE)
	{
		TurnLedOFF(LED0);//Turn off green led
		TurnLedON(LED1);//Turn on yellow led
		TurnLedOFF(LED2);//Turn off red led
		/*Send Yellow Led ON*/
		UART_AsynchSendStr("\n\rYellow Red ON");
	}
	/*Check if received data is STOP*/
	else if(Check_sentData(&local_u8Str,&Stop)==TRUE)
	{
		TurnLedOFF(LED1);//Turn off green led
		TurnLedOFF(LED0);//Turn off yellow led
		TurnLedON(LED2);//Turn on green led
		/*Send Red Led ON*/
		UART_AsynchSendStr("\n\rRed Led ON");
	}
	/*Check if received data is AT*/
	else if(Check_sentData(&local_u8Str,&AT)==TRUE)
	{
		/*Send OK*/
		UART_AsynchSendStr("\n\rOK");
	}
	/*if wrong data*/
	else
	{
		UART_AsynchSendStr("\n\rError");
	}
	/*Receive data from user*/
	UART_AsynchReceiveStr(&local_u8Str);
	/*New line*/
	UART_AsynchSendStr("\n\r");
	/*Send what I received*/
	UART_AsynchSendStr(&local_u8Str);
}

uint8_t Check_sentData(uint8_t* data,uint8_t* Order)
{
	uint8_t local_u8Return=NOK;
	uint8_t local_u8counter=Init_BY_ZERO;
	while(*(Order+local_u8counter) != '\0')
	{
		if(*(Order+local_u8counter) == *(data+local_u8counter))
		{
			local_u8Return=OK;
		}
		else
		{
			local_u8Return=NOK;
			break;
		}
		local_u8counter++;
	}
	return local_u8Return;
}

#endif
