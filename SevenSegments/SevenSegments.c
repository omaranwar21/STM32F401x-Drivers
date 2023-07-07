/*
 * ====================================================================================================================================
 *  * Lab - 05
 * 	SevenSegments.c
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "SevenSegments.h"
/*------------------------------------------------------*/

/*---------------------- Functions Definition ----------------------*/
/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to initialize the port of the Seven Segment.
 */
void SevenSegments_Init(void){
	uint8 i;
	  for (i = SevenSegments_FIRST_PIN; i < (SevenSegments_FIRST_PIN + 7); i++) {
	    Gpio_ConfigPin(SevenSegments_PORT, i, GPIO_OUTPUT, GPIO_PUSH_PULL,GPIO_NO_PULL_UP_DOWN);
	  }
}


/*
 * description:
 * 	Argument(s): value needed to be displayed
 * 	Function to display the value passed.
 */
void SevenSegments_Display(uint8 value){
	switch (value)
			{
			case 0:
			default:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, LOW);
				break;

			case 1:
				GPIO_WritePinValue(SevenSegments_PORT, 0, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 6, LOW);
			break;

			case 2:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 5, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 3:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 4:
				GPIO_WritePinValue(SevenSegments_PORT, 0, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 5:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 6:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 7:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 6, LOW);
			break;

			case 8:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;

			case 9:
				GPIO_WritePinValue(SevenSegments_PORT, 0, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 1, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 2, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 3, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 4, LOW);
				GPIO_WritePinValue(SevenSegments_PORT, 5, HIGH);
				GPIO_WritePinValue(SevenSegments_PORT, 6, HIGH);
			break;
			}
}
/*-----------------------------------------------------------------------------*/

