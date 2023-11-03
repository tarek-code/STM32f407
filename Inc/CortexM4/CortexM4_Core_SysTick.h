/*
 * CortexM4_Core_SysTick.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Unlimited
 */

#ifndef CORTEXM4_CORTEXM4_CORE_SYSTICK_H_
#define CORTEXM4_CORTEXM4_CORE_SYSTICK_H_

// ----------------Includes-----------------------
#include "Common/std_types.h"
#include "Common/Bit_Math.h"
// ----------------Includes end-----------------------


// ---------------macro---------------------------
#define SYSTICK_BASE	(0xE000E010UL)
#define SYSTICK		((SYSTICK_type *)SYSTICK_BASE)

#define SYSTICK_CLOCK_DIV_1	(0)
#define SYSTICK_CLOCK_DIV_8	(1)

#define SYSTICK_INTERRUPT_ENABLE	(0)
#define SYSTICK_INTERRUPT_DISABLE	(1)

#define SYSTICK_SINGLE_INTERVAL_MODE	(0)
#define SYSTICK_PERIODIC_INTERVAL_MODE	(1)

/* SysTick control and status register */
#define SysTick_CTRL_COUNTFLAG_POS	(16)
#define SysTick_CTRL_CLKSOURCE_POS	(2)
#define SysTick_CTRL_TICKINT_POS	(1)
#define SysTick_CTRL_ENABLE_POS	(0)

/* SysTick calibration value register */
#define SysTick_CALIB_NOREF_POS	(31)
#define SysTick_CALIB_SKEW_POS	(30)

/* SysTick reload value register */
#define SysTick_LOAD_RELOAD_POS	(0)
#define SysTick_LOAD_RELOAD_MSK	(0xFFFFFFUL << SysTick_LOAD_RELOAD_POS)


// ---------------macro end---------------------------


//---------------macro function-------------------
#define SYSTICK_READ_FLAG()			(READ_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_COUNTFLAG_POS))
#define SYSTICK_CLEAR_FLAG()		(CLEAR_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_COUNTFLAG_POS))

#define SYSTICK_CLOCK_DIV_BY_1()	(SET_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_CLKSOURCE_POS))
#define SYSTICK_CLOCK_DIV_BY_8()	(CLEAR_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_CLKSOURCE_POS))

#define SYSTICK_ENABLE_INT()	(SET_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_TICKINT_POS))
#define SYSTICK_DISABLE_INT()	(CLEAR_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_TICKINT_POS))

#define SYSTICK_ENABLE()	(SET_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_ENABLE_POS))
#define SYSTICK_DISABLE()	(CLEAR_BIT(SYSTICK->STK_CTRL,SysTick_CTRL_ENABLE_POS))
//---------------macro function end-------------------


//----------------Data type-----------------------
typedef struct {
volatile uint32_t STK_CTRL;
volatile uint32_t STK_LOAD;
volatile uint32_t STK_VAL;
volatile uint32_t STK_CALIB;

}SYSTICK_type;


/* element_int to int the systick_int */
typedef struct{
uint32_t systick_relaodReg_value;
uint8_t systick_clock_sourse:1;
uint8_t systick_interrupt:1;

}systick_int;

//----------------Data type end-----------------------


//----------------Interfaces---------------------

/*
 * @ref: element_int
 * */
void SysTick_Int(systick_int *ptr);
void SysTick_DeInt(void);
void SysTick_WaitBlocking(uint32_t value);
void SysTick_SingleInterval(void (*Ptr)(void),uint32_t value);
void SysTick_PeriodicInterval(void (*Ptr)(void),uint32_t value);
uint32_t SysTick_GetRemainingTicks(void);

//----------------Interfaces end---------------------

#endif /* CORTEXM4_CORTEXM4_CORE_SYSTICK_H_ */
