/*
 * CortexM4_Core_SCB.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Unlimited
 */

#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_

// ----------------Includes-----------------------
#include "Common/std_types.h"
#include "Common/Bit_Math.h"
// ----------------Includes end-----------------------


// ---------------macro---------------------------
#define SCB_BASE	(0xE000ED00UL)
#define SCB		((SCB_type *)SCB_BASE)

#define KEY_READ	(0xFA05)
#define KEY_WRITE	(0x5FA)

// ---------------macro end---------------------------


//---------------macro function-------------------

//---------------macro function end-------------------


//----------------Data type-----------------------

typedef enum{
SCB_GROUP_0 = 0b111,		//0 bits  main group  4 bits supgroup
SCB_GROUP_1 = 0b110,		//1 bits  main group  3 bits supgroup
SCB_GROUP_2 = 0b101,		//2 bits  main group  2 bits supgroup
SCB_GROUP_3 = 0b100,		//3 bits  main group  1 bits supgroup
SCB_GROUP_4 = 0b000			//4 bits  main group  0 bits supgroup
}SCB_t;


typedef struct{
uint32_t CPUID ;
uint32_t ICSR ;
uint32_t VTOR ;
uint32_t AIRCR ;
uint32_t SCR ;
uint32_t CCR ;
uint32_t SHPR1 ;
uint32_t SHPR2 ;
uint32_t SHPR3 ;
uint32_t SHCSR ;
uint32_t CFSR ;
}SCB_type;

//----------------Data type end-----------------------


//----------------Interfaces---------------------

void SCB_Set_Priority_Grouping(SCB_t scb);

uint8_t SCB_Get_Priority_Grouping(void);

//----------------Interfaces end---------------------

#endif /* CORTEXM4_CORE_SCB_H_ */
