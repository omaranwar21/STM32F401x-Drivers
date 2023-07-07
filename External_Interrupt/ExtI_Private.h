/*
 * ====================================================================================================================================
 *  * Lab - 08
 * 	ExtI_Private.h
 *	Name : Omar Ahmed Anwar Mansour
 *  Section: 2
 *  B.N: 2
 *  ===================================================================================================================================
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*---------------------- Includes ----------------------*/
#include "Std_Types.h" // to use standard types such as (uint32)
/*------------------------------------------------------*/

/*--------------------- Definitions -------------------- */

// define the base address for each component(peripheral) is being used.
#define EXTI_BASE_ADDRESS 		0x40013C00		//Base address for external interrupt
#define SYSCFG_BASE_ADDRESS 	0x40013800      //Base address for System configure
#define NVIC_ISERx_BASE_ADDRESS 0xE000E100		//Base address for NVIC ISERx Registers

// define pointer to each struct to access its registers.
#define EXTI ((EXTI_REG *)EXTI_BASE_ADDRESS)
#define SYSCFG ((SYSCFG_REG *)SYSCFG_BASE_ADDRESS)
#define NVIC_ISER ((NVIC_ISER_Index *)NVIC_ISERx_BASE_ADDRESS)
/*------------------------------------------------------*/

/*---------------------- defined data types --------------- */
typedef struct {
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
}EXTI_REG;

typedef struct {
	uint32 MEMRMP;
	uint32 PMC;
	uint32 EXTICR1;
	uint32 EXTICR2;
	uint32 EXTICR3;
	uint32 EXTICR4;
	uint32 CMPCR;
}SYSCFG_REG;

typedef struct{
	uint32 ISER0;
	uint32 ISER1;
	uint32 ISER2;
}NVIC_ISER_Index;

typedef enum{
	NVIC_EXTI_Line_16 = 1,
	NVIC_EXTI_Line_21,
	NVIC_EXTI_Line_22,
	NVIC_EXTI_Line_0 = 6,
	NVIC_EXTI_Line_1,
	NVIC_EXTI_Line_2,
	NVIC_EXTI_Line_3,
	NVIC_EXTI_Line_4,
	NVIC_EXTI_Line_9_5 = 23,
	NVIC_EXTI_Line_15_10 = 40,
	NVIC_EXTI_Line_17,
	NVIC_EXTI_Line_18,
}NVIC_EXTI_Lines;
/*-------------------------------------------------------------*/

#endif /* EXTI_PRIVATE_H_ */
