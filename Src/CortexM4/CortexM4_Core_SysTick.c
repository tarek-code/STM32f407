/*
 * CortexM4_Core_SysTick.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Unlimited
 */


#include "CortexM4/CortexM4_Core_SysTick.h"

static volatile void (*SysTick_FN_Ptr)(void)=NULL;

static volatile uint8_t systick_mode=SYSTICK_SINGLE_INTERVAL_MODE;

void SysTick_Int(systick_int *ptr){
if(NULL!=ptr){

	// disable systick timer
	SYSTICK_DISABLE();

	// set reload register
	WRITE_REG(SYSTICK->STK_LOAD,ptr->systick_relaodReg_value);

	// reset value register
	WRITE_REG(SYSTICK->STK_VAL,0);

	//select clock
	if(SYSTICK_CLOCK_DIV_1==ptr->systick_clock_sourse){
		SYSTICK_CLOCK_DIV_BY_1();
	}
	else{
		SYSTICK_CLOCK_DIV_BY_8();
	}

	// set interrupt
	if(SYSTICK_INTERRUPT_DISABLE==ptr->systick_interrupt){
		SYSTICK_DISABLE_INT();
		}
		else{
			SYSTICK_ENABLE_INT();
		}

}

}

void SysTick_DeInt(void){
	SYSTICK_DISABLE();

	SYSTICK->STK_LOAD=0;

	SYSTICK->STK_VAL=0;

	SYSTICK_DISABLE_INT();
}

void SysTick_WaitBlocking(uint32_t value){

	SYSTICK->STK_VAL=0;
	SYSTICK->STK_LOAD=value;
	SYSTICK_ENABLE();
	while(!SYSTICK_READ_FLAG());
	SYSTICK_DISABLE();
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
}

void SysTick_SingleInterval(void (*Ptr)(void),uint32_t value){
	if(NULL!=Ptr){
		SYSTICK->STK_LOAD=value;
		SysTick_FN_Ptr=Ptr;
		systick_mode=SYSTICK_SINGLE_INTERVAL_MODE;
		SYSTICK_ENABLE_INT();
		SYSTICK_ENABLE();
	}


}

void SysTick_PeriodicInterval(void (*Ptr)(void),uint32_t value){
	if(NULL!=Ptr){
			SYSTICK->STK_LOAD=value;
			SysTick_FN_Ptr=Ptr;
			systick_mode=SYSTICK_PERIODIC_INTERVAL_MODE;
			SYSTICK_ENABLE_INT();
			SYSTICK_ENABLE();
		}
}

uint32_t SysTick_GetRemainingTicks(void){
return (SYSTICK->STK_VAL);
}


/* systick handler */
void SysTick_Handler(void){
	if(SYSTICK_SINGLE_INTERVAL_MODE==systick_mode){
		SYSTICK_DISABLE_INT();
		if(SysTick_FN_Ptr){
				SYSTICK_CLEAR_FLAG();
				SysTick_FN_Ptr();
			}
	}
	else{
		if(SysTick_FN_Ptr){
				SYSTICK_CLEAR_FLAG();
				SysTick_FN_Ptr();
			}
	}

}
