/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Tarek Adel Ali
 * @brief          : Main program body
 ******************************************************************************

 */

#include "main.h"

uint8_t var_adc;
uint8_t var_DMA1_Stream0;
uint8_t var_ETH;

uint8_t var_adc_check_active;
uint8_t var_DMA1_Stream0_check_active;
uint8_t var_ETH_check_active;

 uint8_t read_1;
 uint8_t read_2;

 void rcc_oscillator_cfg(void){
	 rcc_oscillatio_cfg oscillator_cfg={0};
	 oscillator_cfg.oscillatio_type=RCC_HSE;
	 oscillator_cfg.rcc_hse=RCC_ON;
	 oscillator_cfg.osci_prescaller_cfg.AHP_prescaller=AHP_SYSTEM_CLOCK_DIVIDED_BY_128;
	 oscillator_cfg.osci_prescaller_cfg.APB1_prescaller=APB1_clock_divided_by_16;
	 oscillator_cfg.osci_prescaller_cfg.APB2_prescaller=APB2_CLOCK_DIVIDED_BY_2;
	 rcc_oscillatior_cfg(&oscillator_cfg);
 }

int main(void)
{
	rcc_oscillator_cfg();
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

    /* Loop forever */
	while(1){

	}
}

void ADC_IRQHandler(void){
	var_adc++;
	NVIC_Set_Pending(ETH);
	NVIC_Set_Pending(DMA1_STREAM0);

	var_adc_check_active=NVIC_Get_Active(ADC);
	read_1=NVIC_Get_Priority(ADC);
}


void DMA1_Stream0_IRQHandler(void){
	var_DMA1_Stream0++;
	NVIC_Set_Pending(ETH);
	var_DMA1_Stream0_check_active=NVIC_Get_Active(DMA1_STREAM0);
	read_2=NVIC_Get_Priority(DMA1_STREAM0);
}


void ETH_IRQHandler(void){
	var_ETH++;
	var_ETH_check_active=NVIC_Get_Active(ETH);

}
