/*
 * ====================================================================================================================================
 *  * Lab - 05
 * 	SevenSegments.h
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

#ifndef SEVENSEGMENTS_H_
#define SEVENSEGMENTS_H_

/*---------------------- Includes ----------------------*/
#include "Gpio.h"			//Implemented Gpio Drive
/*------------------------------------------------------*/

/*---------------------- Columns Configurations ----------------------*/
#define SevenSegments_PORT			GPIO_A
#define SevenSegments_FIRST_PIN		0
/*--------------------------------------------------------------------*/



/*---------------------- Functions Prototype ----------------------*/
/*
 * description:
 * 	Argument(s): No arguments
 * 	Function to initialize the port of the Seven Segment.
 */
void SevenSegments_Init(void);

/*
 * description:
 * 	Argument(s): value needed to be displayed
 * 	Function to diplay the value passed.
 */
void SevenSegments_Display(uint8);
/*--------------------------------------------------------------------*/


#endif /* SEVENSEGMENTS_H_ */
