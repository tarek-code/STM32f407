/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Tarek Adel Ali
 * @brief          : Main program body
 ******************************************************************************

 */

#include <stdint.h>
#include "CortexM4/CortexM4_Core_NVIC.h"
#include "CortexM4/CortexM4_Core_SCB.h"

uint8_t var_adc;
uint8_t var_DMA1_Stream0;
uint8_t var_ETH;

uint8_t var_adc_check_active;
uint8_t var_DMA1_Stream0_check_active;
uint8_t var_ETH_check_active;

 uint8_t read_1;
 uint8_t read_2;

int main(void)
{

	SCB_Set_Priority_Grouping(SCB_GROUP_2);


	NVIC_Enable_IRQ(ADC);
	NVIC_Enable_IRQ(DMA1_STREAM0);
	NVIC_Enable_IRQ(ETH);

	NVIC_Set_Priority(ADC,2);
	NVIC_Set_Priority(DMA1_STREAM0,0);
	NVIC_Set_Priority(ETH,1);

	NVIC_Set_Pending(ADC);
	//NVIC_Set_Pending(DMA1_STREAM0);
	//NVIC_Set_Pending(ETH);


    /* Loop forever */
	while(1){

	}
}

void ADC_IRQHandler(void){
	var_adc++;
	NVIC_Set_Pending(DMA1_STREAM0);
	NVIC_Set_Pending(ETH);
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
