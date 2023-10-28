/*
 * RCC.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Unlimited
 */

#ifndef MCAL_RCC_STM32F407_RCC_H_
#define MCAL_RCC_STM32F407_RCC_H_

// ----------------Includes-----------------------
#include "Common/std_types.h"
#include "Common/Bit_Math.h"
#include "Common/statuse_fun.h"
// ----------------Includes end-----------------------


// ---------------macro---------------------------
#define RCC_BASE	(0x40023800UL)
#define RCC		((stm32f407_rcc_t *)RCC_BASE)

// ---------------macro end---------------------------


//---------------macro function-------------------

//---------------macro function end-------------------


//----------------Data type-----------------------

typedef enum{
GPIOA =0,
GPIOB,
GPIOC,
GPIOD,
GPIOE,
GPIOF,
GPIOG,
GPIOH,
GPIOI
}rcc_preferal_t;

typedef enum{
		RCC_CR ,		//RCC clock control register
	 	RCC_PLLCFGR ,	//RCC PLL configuration register
	  	RCC_CFGR ,		//RCC clock configuration register
	  	RCC_CIR ,		//RCC clock interrupt register
	  	RCC_AHB1RSTR ,	//RCC AHB1 peripheral reset register
	  	RCC_AHB2RSTR ,	//RCC AHB2 peripheral reset register
	  	RCC_AHB3RSTR ,	//RCC AHB3 peripheral reset register
	  	RCC_APB1RSTR ,	//RCC APB1 peripheral reset register
	  	RCC_APB2RSTR ,	//RCC APB2 peripheral reset register
		RCC_AHB1ENR ,	//RCC AHB1 peripheral clock enable register
	  	RCC_AHB2ENR ,	//RCC AHB2 peripheral clock enable register
	  	RCC_AHB3ENR ,	//RCC AHB3 peripheral clock enable register
	  	RCC_APB1ENR ,	//RCC APB2 peripheral clock enable register
	  	RCC_APB2ENR ,	//RCC AHB1 peripheral clock enable in low power mode register
	  	RCC_AHB1LPENR ,	//RCC AHB2 peripheral clock enable in low power mode register
	  	RCC_AHB2LPENR ,	//RCC AHB3 peripheral clock enable in low power mode register
	  	RCC_AHB3LPENR ,	//RCC APB1 peripheral clock enable in low power mode register
	  	RCC_APB1LPENR ,	//RCC APB2 peripheral clock enabled in low power mode register
	  	RCC_APB2LPENR ,	//RCC Backup domain control register
	  	RCC_BDCR ,		//RCC Backup domain control register
	  	RCC_CSR ,		//RCC clock control & status register
	  	RCC_SSCGR ,		//RCC spread spectrum clock generation register
	  	RCC_PLLI2SCFGR ,//RCC PLLI2S configuration register
}rcc_register_name_t;


typedef struct {
 volatile uint32_t	RCC_CR ;
 volatile uint32_t	RCC_PLLCFGR ;
 volatile uint32_t	RCC_CFGR ;
 volatile uint32_t	RCC_CIR ;
 volatile uint32_t	RCC_AHB1RSTR ;
 volatile uint32_t	RCC_AHB2RSTR ;
 volatile uint32_t	RCC_AHB3RSTR ;
  uint32_t	Reserved0 ;
 volatile uint32_t	RCC_APB1RSTR ;
 volatile uint32_t	RCC_APB2RSTR ;
  uint32_t	Reserved1[2] ;
 volatile uint32_t	RCC_AHB1ENR ;
 volatile uint32_t	RCC_AHB2ENR ;
 volatile uint32_t	RCC_AHB3ENR ;
  uint32_t	Reserved2 ;
 volatile uint32_t	RCC_APB1ENR ;
 volatile uint32_t	RCC_APB2ENR ;
  uint32_t	Reserved3[2] ;
 volatile uint32_t	RCC_AHB1LPENR ;
 volatile uint32_t	RCC_AHB2LPENR ;
 volatile uint32_t	RCC_AHB3LPENR ;
  uint32_t	Reserved4 ;
 volatile uint32_t	RCC_APB1LPENR ;
 volatile uint32_t	RCC_APB2LPENR ;
  uint32_t	Reserved5[2] ;
 volatile uint32_t	RCC_BDCR ;
 volatile uint32_t	RCC_CSR ;
  uint32_t	Reserved6[2] ;
 volatile uint32_t	RCC_SSCGR ;
 volatile uint32_t	RCC_PLLI2SCFGR ;
}stm32f407_rcc_t;


typedef enum{
	RCC_NONE=0,
	RCC_HSE,
	RCC_HSI,
	RCC_LSE,
	RCC_LSI
}rcc_oscillatior_type;


typedef enum{
	RCC_OFF=0,
	RCC_ON,
}rcc_oscillatior_state;




typedef enum{
	APB2_CLOCK_NOT_DIVIDED=0,
	APB2_CLOCK_DIVIDED_BY_2=4,
	APB2_CLOCK_DIVIDED_BY_4,
	APB2_CLOCK_DIVIDED_BY_8,
	APB2_CLOCK_DIVIDED_BY_16,
}RCC_APB2_prescaller;

typedef enum{
	APB1_clock_not_divided=0,
	APB1_clock_divided_by_2=4,
	APB1_clock_divided_by_4,
	APB1_clock_divided_by_8,
	APB1_clock_divided_by_16,
}RCC_APB1_prescaller;

typedef enum{
	 AHP_SYSTEM_CLOCK_NOT_DIVIDED =0,
	AHP_SYSTEM_CLOCK_DIVIDED_BY_2 =8,
	 AHP_SYSTEM_CLOCK_DIVIDED_BY_4,
	AHP_SYSTEM_CLOCK_DIVIDED_BY_8,
	 AHP_SYSTEM_CLOCK_DIVIDED_BY_16,
	 AHP_SYSTEM_CLOCK_DIVIDED_BY_64,
	 AHP_SYSTEM_CLOCK_DIVIDED_BY_128,
	 AHP_SYSTEM_CLOCK_DIVIDED_BY_256,
	AHP_SYSTEM_CLOCK_DIVIDED_BY_512,
}RCC_AHP_prescaller;

typedef struct{

	RCC_AHP_prescaller APB2_prescaller;
	RCC_APB1_prescaller APB1_prescaller;
	RCC_APB2_prescaller AHP_prescaller;


}rcc_oscillator_divider_cfg;


typedef struct{
	rcc_oscillatior_type oscillatio_type;
	rcc_oscillatior_state rcc_hse;
	rcc_oscillatior_state rcc_hsi;
	rcc_oscillatior_state rcc_lse;
	rcc_oscillatior_state rcc_lsi;
	rcc_oscillator_divider_cfg osci_prescaller_cfg;
}rcc_oscillatio_cfg;

//----------------Data type end-----------------------


//----------------Interfaces---------------------

ret_statuse_t rcc_oscillatior_cfg(rcc_oscillatio_cfg *ptr);

void RCC_Enable(rcc_register_name_t reg_name,uint8_t sup_reg_name);
void RCC_Disable(rcc_register_name_t reg_name,uint8_t sup_reg_name);

//----------------Interfaces end---------------------

#endif /* MCAL_RCC_STM32F407_RCC_H_ */
