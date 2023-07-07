/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Button.c
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

/*------------------------------ Includes ----------------------*/
#include "Button.h"
/*-------------------------------------------------------------*/

/*---------------------- Global Variables ----------------------*/
/*
 * timerIsOn is a flag to know whether the timer is on or not when using GPT
 * for debouncing time calculation.
 */
BUTTON_TimerState timerIsOn = BUTTON_TimerIsOff;

/*
 * BUTTON_firstTime is a variable to hold first time for debouncing time calculations.
 */
uint32 BUTTON_firstTime;

/*
 * g_buttonsFlags is a set of flags for releasing the button pressing.
 */
uint16 g_buttonsFlags = 0;

/*
 * firstRead_flag is a flag to indicate theat the first read has been captured.
 */
BUTTON_FirstRead firstRead_flag = BUTTON_FirstRead_NotDone;
/*-------------------------------------------------------------*/

/*---------------------- Functions Definition ----------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	Button Port.
 * 		--> pinNum: 	Button pin.
 * 	Function to configure Port and pin of the Button.
 */
void BUTTON_Init(uint8 portName, uint8 pinNum){

	SET_BIT(g_buttonsFlags, pinNum);

	Gpio_ConfigPin(portName, pinNum, GPIO_INPUT, GPIO_PUSH_PULL, GPIO_PULL_UP);

}

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	Button Port.
 * 		--> pinNum: 	Button pin.
 * 	Function to read the state of the button whether pressed or not
 * 	after avoiding debouncing effect.
 */
BUTTON_States BUTTON_ReadState(uint8 portName, uint8 pinNum){

#ifdef GPT_H_
	static BUTTON_States first_read = BUTTON_FLOATING;

	uint32 elapsed_time;

	BUTTON_States second_read = BUTTON_FLOATING;

	if (firstRead_flag == BUTTON_FirstRead_NotDone) {

		if (timerIsOn == BUTTON_TimerIsOff) {

			GPT_StartTimer(&Timer, BUTTON_START_TIME_ms);

		}

		first_read = (BUTTON_States)GPIO_ReadPinState(portName, pinNum);

		if (first_read == BUTTON_PRESSED) {

			firstRead_flag = BUTTON_FirstRead_Done;

		}
		else {

			SET_BIT(g_buttonsFlags, pinNum);

			return BUTTON_RELEASED;

		}

		BUTTON_firstTime = GPT_GetElapsedTime(&Timer);

	}
	else{
		elapsed_time = GPT_GetElapsedTime(&Timer);

		if ( ( (elapsed_time - BUTTON_firstTime) >= BUTTON_DEBOUNCING_TIME_ms ) ) {

			second_read = (BUTTON_States)GPIO_ReadPinState(portName, pinNum);

			firstRead_flag = BUTTON_FirstRead_NotDone;

			if (first_read == second_read ) {

				 if (first_read == BUTTON_PRESSED &&  (((g_buttonsFlags >> (pinNum)) & 1) == BUTTON_PRESSED)) {

					 CLEAR_BIT(g_buttonsFlags, pinNum);

					return BUTTON_PRESSED;

				}

			}

		}

	}


#else

	if ((BUTTON_States)GPIO_ReadPinState(portName, pinNum)	== BUTTON_PRESSED ) {

		delay_ms(BUTTON_DEBOUNCING_TIME_ms); 	//Debouncing

		if ( ((BUTTON_States)GPIO_ReadPinState(portName, pinNum) == BUTTON_PRESSED) &&  (READ_BIT(g_buttonsFlags, pinNum) == BUTTON_PRESSED) ) {
			CLEAR_BIT(g_buttonsFlags, pinNum);
			return BUTTON_PRESSED;
		}
	}else {
		SET_BIT(g_buttonsFlags, pinNum);
	}

#endif

	return BUTTON_RELEASED;

}
/*-----------------------------------------------------------------------------*/
