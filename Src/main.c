/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Tarek Adel Ali
 * @brief          : Main program body
 ******************************************************************************

 */

#include "main.h"



 volatile uint32_t number_counteing;
 volatile uint32_t number2_counteing;
 volatile uint32_t systick_return_value;

 void int_cfg(void){
	 rcc_oscillatio_cfg oscillator_cfg={0};
	 systick_int systickInt={0};
	 oscillator_cfg.oscillatio_type=RCC_HSE;
	 oscillator_cfg.rcc_hse=RCC_ON;
	 oscillator_cfg.osci_prescaller_cfg.AHP_prescaller=AHP_SYSTEM_CLOCK_NOT_DIVIDED;
	 oscillator_cfg.osci_prescaller_cfg.APB1_prescaller=APB1_clock_NOT_DIVIDED;
	 oscillator_cfg.osci_prescaller_cfg.APB2_prescaller=APB2_CLOCK_NOT_DIVIDED;
	 rcc_oscillatior_cfg(&oscillator_cfg);

	 systickInt.systick_clock_sourse=SYSTICK_CLOCK_DIV_1;
	 systickInt.systick_interrupt=SYSTICK_INTERRUPT_DISABLE;
	 systickInt.systick_relaodReg_value=1000;
	 SysTick_Int(&systickInt);
 }
void systick(void){
	number2_counteing++;
}


int main(void)
{
	int_cfg();
/*
	SCB_Set_Priority_Grouping(SCB_GROUP_2);


	NVIC_Enable_IRQ(ADC);
	NVIC_Enable_IRQ(DMA1_STREAM0);
	NVIC_Enable_IRQ(ETH);

	NVIC_Set_Priority(ADC,10);
	NVIC_Set_Priority(DMA1_STREAM0,0);
	NVIC_Set_Priority(ETH,1);

	NVIC_Set_Pending(ADC);
	*/
	//NVIC_Set_Pending(DMA1_STREAM0);
	//NVIC_Set_Pending(ETH);
	RCC_Enable(RCC_AHB1ENR,GPIOA);
	RCC_Enable(RCC_AHB1ENR,GPIOC);
	RCC_Enable(RCC_AHB1ENR,GPIOI);

	RCC_Disable(RCC_AHB1ENR,GPIOC);
	SysTick_PeriodicInterval(systick,1000000);
    /* Loop forever */
	while(1){


		number_counteing++;
		systick_return_value=SysTick_GetRemainingTicks();
	}
}

void ADC_IRQHandler(void){

	NVIC_Set_Pending(ETH);
	NVIC_Set_Pending(DMA1_STREAM0);

	NVIC_Get_Active(ADC);
	NVIC_Get_Priority(ADC);
}


void DMA1_Stream0_IRQHandler(void){

	NVIC_Set_Pending(ETH);
	NVIC_Get_Active(DMA1_STREAM0);
	NVIC_Get_Priority(DMA1_STREAM0);
}


void ETH_IRQHandler(void){

	NVIC_Get_Active(ETH);

}
