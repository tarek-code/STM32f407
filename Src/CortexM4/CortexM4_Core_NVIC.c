/*
 * CortexM4_Core_NVIC.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Unlimited
 */

#include "CortexM4/CortexM4_Core_NVIC.h"


void NVIC_Enable_IRQ(nvic_irq_t irq){
if((uint32_t)irq>=0){
SET_BIT((NVIC->NVIC_ISER[((uint32_t)irq)>>5UL]),(((uint32_t)irq) & 31UL));

}
}

void NVIC_Disable_IRQ(nvic_irq_t irq){
	if((uint32_t)irq>=0){
	SET_BIT((NVIC->NVIC_ICER[((uint32_t)irq)>>5UL]),(((uint32_t)irq) & 31UL));

	}
}

void NVIC_Set_Pending(nvic_irq_t irq){
	if((uint32_t)irq>=0){
	SET_BIT((NVIC->NVIC_ISPR[((uint32_t)irq)>>5UL]),(((uint32_t)irq) & 31UL));

	}
}

void NVIC_Clear_Pending(nvic_irq_t irq){
	if((uint32_t)irq>=0){
	SET_BIT((NVIC->NVIC_ICPR[((uint32_t)irq)>>5UL]),(((uint32_t)irq) & 31UL));

	}
}

uint8_t NVIC_Get_Active(nvic_irq_t irq){

	return READ_BIT((NVIC->NVIC_IABR[((uint32_t)irq)>>5UL]),(((uint32_t)irq) & 31UL));;
}


void NVIC_Set_Priority(nvic_irq_t irq,uint8_t priority){
NVIC->NVIC_IPR[irq]=priority<<4;

}
uint8_t NVIC_Get_Priority( nvic_irq_t irq){

return (NVIC->NVIC_IPR[irq]>>4);
}
