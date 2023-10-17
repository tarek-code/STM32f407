/*
 * CortexM4_Core_SCB.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Unlimited
 */
#include "CortexM4/CortexM4_Core_SCB.h"

void SCB_Set_Priority_Grouping(SCB_t scb){
SCB->AIRCR=((uint32_t) KEY_WRITE <<16) | ((uint32_t)scb << 8);
}

uint8_t SCB_Get_Priority_Grouping(void){

return (((uint32_t)SCB->AIRCR & (uint32_t)0x700)>>8);

}

