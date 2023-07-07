/*
 * ====================================================================================================================================
 *  * Lab - 05
 * 	Keypad.h
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*---------------------- Includes ----------------------*/
#include "Delay.h"			//For delay
#include "Gpio.h"			//Implemented Gpio Drive
/*------------------------------------------------------*/

/*---------------------- Columns Configurations ----------------------*/
#define KEYPAD_COLS_PORT			GPIO_B
#define KEYPAD_COLS_START_PIN		0
#define KEYPAD_COLS_END_PIN			2
/*--------------------------------------------------------------------*/

/*---------------------- Rows Configurations ----------------------*/
#define KEYPAD_ROWS_PORT			GPIO_B
#define KEYPAD_ROWS_START_PIN		5
#define KEYPAD_ROWS_END_PIN			8
/*-----------------------------------------------------------------*/

/*---------------------- Buttons Configurations ----------------------*/
#define KEYPAD_BUTTON_PRESSED		0
#define KEYPAD_BUTTON_RELEASED		1
/*-----------------------------------------------------------------*/

/*---------------------- Key Configurations ----------------------*/
#define KEYPAD_KEY_STORED			0
#define KEYPAD_KEY_RELEASED			1
/*-----------------------------------------------------------------*/

/*---------------------- Keypad Configurations ----------------------*/
#define KEYPAD_NUM_COLS             3
#define KEYPAD_NUM_ROWS             4
/*-----------------------------------------------------------------*/


/*---------------------- Functions Prototype ----------------------*/
/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to initialize the port of the keypad and specify the
 * 	colums as input and the rows as an output
 */
void Keypad_init(void);

/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to loop on the matrix of the keypad to specify
 * 	which button has been pressed and drive the callout
 * 	function if the stored key has been released.
 */
void Keypad_manage(void);

/*
 * description:
 * 	Argument(s): No arguments
 * 	Return: the global key Value
 * 	Function to rest the state of releasing the key
 * 	and return the stored key.
 */
uint8 Keypad_GetKey(void);

/*
 * description:
 * 	Argument(s): No arguments
 * 	Function is required to be implemented depends on
 * 	the application when the button and the key
 * 	have been called correctly.
 */
void KeypadCallouts_KeyPressNotificaton(void);
/*------------------------------------------------------------------*/


#endif /* KEYPAD_H_ */
