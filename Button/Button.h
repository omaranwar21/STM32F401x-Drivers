/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Button.h
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/*---------------------- Includes ----------------------*/
#include "Gpio.h"
#include "Delay.h"
#include "Bit_Operations.h"
/*
 * Comment (#include "gpt.h") if you want to disable GPT for button
 * driver and avoid debouncing effect by hardware loops for delay 30ms.
 */
#include "gpt.h"
/*------------------------------------------------------*/

/*---------------------- Externs ----------------------*/

#ifdef GPT_H_
/*
 * Extern Time object (From main.c)
 */
extern TIMx_Configue Timer;

#endif
/*------------------------------------------------------*/

/*---------------------- Definitions ----------------------*/
#define BUTTON_DEBOUNCING_TIME_ms	30
#define BUTTON_START_TIME_ms		1000
/*---------------------------------------------------------*/

/*----------------- Defined types -------------------------*/
typedef enum{
	BUTTON_RELEASED = GPIO_DATA_RISING,
	BUTTON_PRESSED = GPIO_DATA_FALLING,
	BUTTON_FLOATING
}BUTTON_States;

typedef enum{
	BUTTON_FirstRead_NotDone, BUTTON_FirstRead_Done
}BUTTON_FirstRead;

typedef enum{
	BUTTON_TimerIsOff, BUTTON_TimerIsOn
}BUTTON_TimerState;
/*-----------------------------------------------------------*/

/*----------------- Functions Prototype ---------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	Button Port.
 * 		--> pinNum: 	Button pin.
 * 	Function to configure Port and pin of the Button.
 */
void BUTTON_Init(uint8 portName, uint8 pinNum);

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	Button Port.
 * 		--> pinNum: 	Button pin.
 * 	Function to read the state of the button whether pressed or not
 * 	after avoiding debouncing effect.
 */
BUTTON_States BUTTON_ReadState(uint8 portName, uint8 pinNum);
/*------------------------------------------------------------*/

#endif /* BUTTON_H_ */
