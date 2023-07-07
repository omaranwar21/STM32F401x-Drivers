/*
 * ====================================================================================================================================
 *  * Lab - 08
 * 	ExtI.c
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "ExtI.h"
/*------------------------------------------------------*/

/*--------------- Global variables --------------------*/

// Array of pointers to function to  interrupt function passed to the initializing function.
void(*handlerPointer[22])(void) = {((void*)(0))};

// Index array to represent each line index corresponding to its bit order.
NVIC_EXTI_Lines line[]={
		NVIC_EXTI_Line_0,
		NVIC_EXTI_Line_1,
		NVIC_EXTI_Line_2,
		NVIC_EXTI_Line_3,
		NVIC_EXTI_Line_4,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_9_5,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_15_10,
		NVIC_EXTI_Line_16,
		NVIC_EXTI_Line_17,
		NVIC_EXTI_Line_18,
		0,
		0,
		NVIC_EXTI_Line_21,
		NVIC_EXTI_Line_22
};


/*---------------------- Functions Definition ----------------------*/

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
		uint8 ExtiPin,EXTI_Edge edge,
		void(*callbackFunctionPtr)(void)){

	/*
	 * EXTICR1 --> bits {0, 1, 2 ,3}
	 * EXTICR2 --> bits {4, 5, 6 ,7}
	 * EXTICR3 --> bits {8, 9, 10 ,11}
	 * EXTICR4 --> bits {12, 13, 14 ,15}
	 */
	if (ExtiPin < 4) {
		SYSCFG->EXTICR1 &= ~(portID << (ExtiPin%4 * 4));
		SYSCFG->EXTICR1 |=  (portID << (ExtiPin%4 * 4));
	}
	else if (ExtiPin >= 4 && ExtiPin < 8){
		SYSCFG->EXTICR2 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR2 |=  (portID << ( (ExtiPin%4) * 4));
	}
	else if (ExtiPin >= 8 && ExtiPin < 12){
		SYSCFG->EXTICR3 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR3 |=  (portID << ( (ExtiPin%4) * 4));
	}
	else if (ExtiPin >= 12 && ExtiPin < 16){
		SYSCFG->EXTICR4 &= ~(portID << ( (ExtiPin%4) * 4));
		SYSCFG->EXTICR4 |=  (portID << ( (ExtiPin%4) * 4));
	}

	/*
	 * SelectNVIC Line from line array.
	 */
	NVIC_EXTI_Lines NvicLine = line[ExtiPin];

	/*
	 * Add function passed to its corresponding index in handler array.
	 */
	handlerPointer[ExtiPin] = *callbackFunctionPtr;

	/*
	 * Mapping Vector table of NVIC to service external interrupts
	 * ISER0: 0 --> 31
	 * ISER1: 32 --> 63
	 * ISER2: 64 --> 80
	 */
	if (NvicLine < 32) {
		SET_BIT(NVIC_ISER->ISER0, NvicLine%32);
	}
	else if (NvicLine >= 32 && NvicLine < 64) {
		SET_BIT(NVIC_ISER->ISER1, NvicLine%32);
	}
	else {
		SET_BIT(NVIC_ISER->ISER2, NvicLine%32);
	}

	/*
	 * Select the edge
	 * 	case :: falling edge
	 * 	case :: rising edge
	 * 	case :: both edges
	 */
	switch (edge) {
	case EXTI_FALLING_EDGE:
		SET_BIT(EXTI->FTSR, ExtiPin);
		break;
	case EXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR, ExtiPin);
		break;
	case EXTI_FALLING_RISING_EDGES:
		SET_BIT(EXTI->FTSR, ExtiPin);
		SET_BIT(EXTI->RTSR, ExtiPin);
		break;
	}
}


/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to enable the External interrupt line.
 */
void Exti_Enable(uint8 ExtiPin){
	SET_BIT(EXTI->IMR, ExtiPin);
}


/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to disable the External interrupt line.
 */
void Exti_Disable(uint8 ExtiPin){
	CLEAR_BIT(EXTI->IMR, ExtiPin);
}

/*
 * description:
 * 	Argument(s):
 * 		--> ExtiPin: Pin of the external interrupt line.
 * 	Function to clear pending flag when external interrupt occurs by set
 * 	the bit to 1.
 */
void Exti_HandlerPendingFlag(uint8 ExtiPin){
	SET_BIT(EXTI->PR, ExtiPin);
}
/*-----------------------------------------------------------------------*/

/*--------------------- IQR Handlers ------------------------------------- */
void EXTI0_IRQHandler(void){
	(*(handlerPointer[0]))();
}

void EXTI1_IRQHandler(void){
	(*(handlerPointer[1]))();
}

void EXTI2_IRQHandler(void){
	(*(handlerPointer[2]))();
}

void EXTI3_IRQHandler(void){
	(*(handlerPointer[3]))();
}

void EXTI4_IRQHandler(void){
	(*(handlerPointer[4]))();
}

void EXTI9_5_IRQHandler(void){
	if (READ_BIT(EXTI->FTSR, 5) || READ_BIT(EXTI->RTSR, 5)) {
		(*(handlerPointer[5]))();
	}
	else if (READ_BIT(EXTI->FTSR, 6) || READ_BIT(EXTI->RTSR, 6)) {
		(*(handlerPointer[6]))();
	}
	else if (READ_BIT(EXTI->FTSR, 7) || READ_BIT(EXTI->RTSR, 7)) {
		(*(handlerPointer[7]))();
	}
	else if (READ_BIT(EXTI->FTSR, 8) || READ_BIT(EXTI->RTSR, 8)) {
		(*(handlerPointer[8]))();
	}
	else {
		(*(handlerPointer[9]))();
	}
}

void EXTI15_10_IRQHandler(void){
	if (READ_BIT(EXTI->FTSR, 10) || READ_BIT(EXTI->RTSR, 10)) {
		(*(handlerPointer[10]))();
	}
	else if (READ_BIT(EXTI->FTSR, 11) || READ_BIT(EXTI->RTSR, 11)) {
		(*(handlerPointer[11]))();
	}
	else if (READ_BIT(EXTI->FTSR, 12) || READ_BIT(EXTI->RTSR, 12)) {
		(*(handlerPointer[12]))();
	}
	else if (READ_BIT(EXTI->FTSR, 13) || READ_BIT(EXTI->RTSR, 13)) {
		(*(handlerPointer[13]))();
	}
	else if (READ_BIT(EXTI->FTSR, 14) || READ_BIT(EXTI->RTSR, 14)){
		(*(handlerPointer[14]))();
	}
	else {
		(*(handlerPointer[15]))();
	}
}

void PVD_IRQHandler(void){
	(*(handlerPointer[16]))();
}

void RTC_Alarm_IRQHandler(void){
	(*(handlerPointer[17]))();
}

void OTG_FS_WKUP_IRQHandler(void){
	(*(handlerPointer[18]))();
}

void TAMP_STAMP_IRQHandler(void){
	(*(handlerPointer[21]))();
}

void RTC_WKUP_IRQHandler(void){
	(*(handlerPointer[22]))();
}
/*-----------------------------------------------------------------------------*/


