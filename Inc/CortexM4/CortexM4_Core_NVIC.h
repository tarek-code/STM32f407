/*
 * CortexM4_Core_NVIC.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Unlimited
 */

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_

// ----------------Includes-----------------------
#include "Common/std_types.h"
#include "Common/Bit_Math.h"
// ----------------Includes end-----------------------


// ---------------macro---------------------------
#define NVIC_BASE	(0xE000E100UL)
#define NVIC		((NVIC_type *)NVIC_BASE)

// ---------------macro end---------------------------


//---------------macro function-------------------

//---------------macro function end-------------------


//----------------Data type-----------------------

typedef enum{
	NMI = -14,   /* Non maskable interrupt. The RCC Clock Security System (CSS) is linked to the NMI vector. */

	MEM_MANAGE = -12, /* Memory management. */

	BUS_FAULT, /* Bus fault, specific details not provided. */

	USAGE_FAULT, /* Usage fault, specific details not provided. */

	SVCALL = -5, /* System service call via SWI instruction. */

	DEBUG_MONITOR, /* Debug Monitor, specific details not provided. */

	PEND_SV = -2, /* Pendable request for system service. */

	SYS_TICK, /* System tick timer interrupt. */
		WWDG=0,   /* Window Watchdog interrupt */
		    PVD, /* PVD through EXTI line detection interrupt */
		    TAMP_STAMP, /* Tamper and TimeStamp interrupts through EXTI line */
		    RTC_WAKEUP, /* RTC Wakeup interrupt through EXTI line */
		    FLASH, /* Flash global interrupt */
		    RCC, /* RCC global interrupt */
		    EXTI0, /* EXTI Line0 interrupt */
		    EXTI1, /* EXTI Line1 interrupt */
		    EXTI2, /* EXTI Line2 interrupt */
		    EXTI3, /* EXTI Line3 interrupt */
		    EXTI4, /* EXTI Line4 interrupt */
		    DMA1_STREAM0, /* DMA1 Stream0 global interrupt */
		    DMA1_STREAM1, /* DMA1 Stream1 global interrupt */
		    DMA1_STREAM2, /* DMA1 Stream2 global interrupt */
		    DMA1_STREAM3, /* DMA1 Stream3 global interrupt */
		    DMA1_STREAM4, /* DMA1 Stream4 global interrupt */
		    DMA1_STREAM5, /* DMA1 Stream5 global interrupt */
		    DMA1_STREAM6, /* DMA1 Stream6 global interrupt */
		    ADC, /* ADC1, ADC2 and ADC3 global interrupts */
		    CAN1_TX, /* CAN1 TX interrupts */
		    CAN1_RX0, /* CAN1 RX0 interrupts */
		    CAN1_RX1, /* CAN1 RX1 interrupt */
		    CAN1_SCE, /* CAN1 SCE interrupt */
		    EXTI9_5, /* EXTI Line[9:5] interrupts */
		    TIM1_BRK_TIM9, /* TIM1 Break interrupt and TIM9 global interrupt */
		    TIM1_UP_TIM10, /* TIM1 Update interrupt and TIM10 global interrupt */
		    TIM1_TRG_COM_TIM11, /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
		    TIM1_CC, /* TIM1 Capture Compare interrupt */
		    TIM2, /* TIM2 global interrupt */
		    TIM3, /* TIM3 global interrupt */
		    TIM4, /* TIM4 global interrupt */
		    I2C1_EV, /* I2C1 event interrupt */
		    I2C1_ER, /* I2C1 error interrupt */
		    I2C2_EV, /* I2C2 event interrupt */
		    I2C2_ER, /* I2C2 error interrupt */
		    SPI1, /* SPI1 global interrupt */
		    SPI2, /* SPI2 global interrupt */
		    USART1, /* USART1 global interrupt */
		    USART2, /* USART2 global interrupt */
		    USART3, /* USART3 global interrupt */
		    EXTI15_10, /* EXTI Line[15:10] interrupts */
		    RTC_ALARM, /* RTC Alarms (A and B) through EXTI line interrupt */
		    OTG_FS_WKUP, /* USB On-The-Go FS Wakeup through EXTI line interrupt */
		    TIM8_BRK_TIM12, /* TIM8 Break interrupt and TIM12 global interrupt */
		    TIM8_UP_TIM13, /* TIM8 Update interrupt and TIM13 global interrupt */
		    TIM8_TRG_COM_TIM14, /* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
		    TIM8_CC, /* TIM8 Capture Compare interrupt */
		    DMA1_STREAM7, /* DMA1 Stream7 global interrupt */
		    FSMC, /* FSMC global interrupt */
		    SDIO, /* SDIO global interrupt */
		    TIM5, /* TIM5 global interrupt */
		    SPI3, /* SPI3 global interrupt */
		    UART4, /* UART4 global interrupt */
		    UART5, /* UART5 global interrupt */
		    TIM6_DAC_TIM6, /* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts */
		    TIM7, /* TIM7 global interrupt */
		    DMA2_STREAM0, /* DMA2 Stream0 global interrupt */
		    DMA2_STREAM1, /* DMA2 Stream1 global interrupt */
		    DMA2_STREAM2, /* DMA2 Stream2 global interrupt */
		    DMA2_STREAM3, /* DMA2 Stream3 global interrupt */
		    DMA2_STREAM4, /* DMA2 Stream4 global interrupt */
		    ETH, /* Ethernet global interrupt */
		    ETH_WKUP, /* Ethernet Wakeup through EXTI line interrupt */
		    CAN2_TX, /* CAN2 TX interrupts */
		    CAN2_RX0, /* CAN2 RX0 interrupts */
		    CAN2_RX1, /* CAN2 RX1 interrupt */
		    CAN2_SCE, /* CAN2 SCE interrupt */
		    OTG_FS, /* USB On The Go FS global interrupt */
		    DMA2_STREAM5, /* DMA2 Stream5 global interrupt */
		    DMA2_STREAM6, /* DMA2 Stream6 global interrupt */
		    DMA2_STREAM7, /* DMA2 Stream7 global interrupt */
		    USART6, /* USART6 global interrupt */
		    I2C3_EV, /* I2C3 event interrupt */
		    I2C3_ER, /* I2C3 error interrupt */
		    OTG_HS_EP1_OUT, /* USB On The Go HS End Point 1 Out global interrupt */
		    OTG_HS_EP1_IN, /* USB On The Go HS End Point 1 In global interrupt */
		    OTG_HS_WKUP, /* USB On The Go HS Wakeup through EXTI interrupt */
		    OTG_HS, /* USB On The Go HS global interrupt */
		    DCMI, /* DCMI global interrupt */
		    CRYP, /* CRYP crypto global interrupt */
		    HASH_RNG, /* Hash and Rng global interrupt */
		    FPU   /* FPU global interrupt */

}nvic_irq_t;




typedef struct {
volatile uint32_t NVIC_ISER[8U];
uint32_t reserved_0[24U];
volatile uint32_t NVIC_ICER[8U];
uint32_t reserved_1[24U];
volatile uint32_t NVIC_ISPR[8U];
uint32_t reserved_2[24U];
volatile uint32_t NVIC_ICPR[8U];
uint32_t reserved_3[24U];
volatile uint32_t NVIC_IABR[8U];
uint32_t reserved_4[56U];
volatile uint8_t NVIC_IPR[240U];
uint32_t reserved_5[644U];
volatile uint32_t STIR;
}NVIC_type;
//----------------Data type end-----------------------


//----------------Interfaces---------------------

void NVIC_Enable_IRQ(nvic_irq_t irq);
void NVIC_Disable_IRQ(nvic_irq_t irq);

void NVIC_Set_Pending(nvic_irq_t irq);
void NVIC_Clear_Pending(nvic_irq_t irq);

uint8_t NVIC_Get_Active(nvic_irq_t irq);

void NVIC_Set_Priority(nvic_irq_t irq,uint8_t priority);
uint8_t NVIC_Get_Priority( nvic_irq_t irq);


//----------------Interfaces end---------------------



#endif /* CORTEXM4_CORE_NVIC_H_ */
