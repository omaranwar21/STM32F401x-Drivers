/*
 * ====================================================================================================================================
 *  * Lab - 05
 * 	Keypad.c
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "Keypad.h"
/*--------------------------------------------------------------------*/


/*---------------------- Global Variables ----------------------*/
uint8 key = 0; // Global variable to get the index of the key pressed
boolean key_state = KEYPAD_KEY_RELEASED; // Flag to saves the releasing of the key condition.
/*--------------------------------------------------------------------*/


/*---------------------- Functions Definition ----------------------*/
/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to initialize the port of the keypad and specify the colums as input
 * 	and the rows as an output
 */
void Keypad_init(void){
	uint8 loop;
	for (loop = KEYPAD_COLS_START_PIN; loop <= KEYPAD_COLS_END_PIN; ++loop) {
		Gpio_ConfigPin(KEYPAD_COLS_PORT, loop, GPIO_INPUT, GPIO_NO_PULL_UP_DOWN, GPIO_PULL_UP);
	}

	for (loop = KEYPAD_ROWS_START_PIN; loop <= KEYPAD_ROWS_END_PIN; ++loop) {
		Gpio_ConfigPin(KEYPAD_COLS_PORT, loop, GPIO_OUTPUT, GPIO_NO_PULL_UP_DOWN, GPIO_PULL_DOWN);
		Gpio_WritePin(KEYPAD_ROWS_PORT, loop, KEYPAD_BUTTON_RELEASED);
	}
}


/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to loop on the matrix of the keypad to specify which button
 * 	has been pressed and drive the callout function if the stored key has been released.
 */
void Keypad_manage(void){
	uint8 rows_loop;
	uint8 cols_loop;

	for (rows_loop = KEYPAD_ROWS_START_PIN; rows_loop <= KEYPAD_ROWS_END_PIN; ++rows_loop) {

		Gpio_WritePin(KEYPAD_ROWS_PORT, rows_loop, KEYPAD_BUTTON_PRESSED);

		for (cols_loop = KEYPAD_COLS_START_PIN; cols_loop <= KEYPAD_COLS_END_PIN; ++cols_loop) {

			if (Gpio_ReadPin(KEYPAD_COLS_PORT, cols_loop) == KEYPAD_BUTTON_PRESSED) {
				delay_ms(30);
				if (Gpio_ReadPin(KEYPAD_COLS_PORT, cols_loop) == KEYPAD_BUTTON_PRESSED) {

					if (key_state) {

						key = ((rows_loop-KEYPAD_ROWS_START_PIN)*KEYPAD_NUM_COLS)+(cols_loop-KEYPAD_COLS_START_PIN);
						key_state = KEYPAD_KEY_STORED;
						KeypadCallouts_KeyPressNotificaton();
					}

				}
			}
		}

		Gpio_WritePin(KEYPAD_ROWS_PORT, rows_loop, KEYPAD_BUTTON_RELEASED);
	}
}

/*
 * description:
 * 	Argument(s): No arguments
 * 	Return: the global key Value
 * 	Function to rest the state of releasing the key and return the stored key.
 */
uint8 Keypad_GetKey(void){
	key_state = KEYPAD_KEY_RELEASED;
	return key;
}
/*--------------------------------------------------------------------*/





