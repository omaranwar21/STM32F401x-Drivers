/*
 * ====================================================================================================================================
 *  * Lab - 08
 * 	ExtI.h
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

#ifndef EXTI_H_
#define EXTI_H_

/*---------------------- Includes ----------------------*/
#include "ExtI_Private.h"
#include "Bit_Operations.h"
/*------------------------------------------------------*/

/*----------------- Defined types ----------------------*/
typedef enum{
	EXTI_GPIOA, EXTI_GPIOB, EXTI_GPIOC,
	EXTI_GPIOD, EXTI_GPIOE, EXTI_GPIOH = 7
}EXTI_PORT;

typedef enum{
	EXTI_FALLING_EDGE, EXTI_RISING_EDGE,
	EXTI_FALLING_RISING_EDGES
}EXTI_Edge;
/*------------------------------------------------------*/


/*---------------------- Functions Prototype ----------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> PortID:	 Port needed to be initialized as external interrupt.
 * 		--> ExtiPin: The pin needed to be selected from the port or
 * 		 the External Line.
 * 		--> edge: the edge that is triggering the interrupt event.
 * 		--> CallbackFunctionPtr: Function needed to be handled whenever the
 * 		 interrupt event occurs.
 * 	Function to initialize the External interrupt line.
 */
void Exti_Init(EXTI_PORT portID,
		uint8 ExtiPin,
		EXTI_Edge edge,
		void(*callbackFunctionPtr)(void));

/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to enable the External interrupt line.
 */
void Exti_Enable(uint8 ExtiPin);

/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to disable the External interrupt line.
 */
void Exti_Disable(uint8 ExtiPin);

/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to clear pending flag when external interrupt occurs by set
 * 	the bit to 1.
 */
void Exti_HandlerPendingFlag(uint8 ExtiPin);
/*--------------------------------------------------------------------*/

#endif /* EXTI_H_ */
