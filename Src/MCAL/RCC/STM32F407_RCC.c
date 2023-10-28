/*
 * RCC.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Unlimited
 */


#include <MCAL/RCC/STM32F407_RCC.h>



void RCC_Enable(rcc_register_name_t reg_name,uint8_t sup_reg_name){
	switch(reg_name){
	case RCC_CR:
		SET_BIT(RCC->RCC_CR,sup_reg_name);
		break;
	case RCC_PLLCFGR:
		SET_BIT(RCC->RCC_PLLCFGR,sup_reg_name);
			break;
	case RCC_CFGR:
		SET_BIT(RCC->RCC_CFGR,sup_reg_name);
			break;
	case RCC_CIR:
		SET_BIT(RCC->RCC_CIR,sup_reg_name);
			break;
	case RCC_AHB1RSTR:
		SET_BIT(RCC->RCC_AHB1RSTR,sup_reg_name);
			break;
	case RCC_AHB2RSTR:
		SET_BIT(RCC->RCC_AHB2RSTR,sup_reg_name);
			break;
	case RCC_AHB3RSTR:
		SET_BIT(RCC->RCC_AHB3RSTR,sup_reg_name);
			break;
	case RCC_APB1RSTR:
		SET_BIT(RCC->RCC_APB1RSTR,sup_reg_name);
			break;
	case RCC_APB2RSTR:
		SET_BIT(RCC->RCC_APB2RSTR,sup_reg_name);
			break;
	case RCC_AHB1ENR:
		SET_BIT(RCC->RCC_AHB1ENR,sup_reg_name);
			break;
	case RCC_AHB2ENR:
		SET_BIT(RCC->RCC_AHB2ENR,sup_reg_name);
			break;
	case RCC_AHB3ENR:
		SET_BIT(RCC->RCC_AHB3ENR,sup_reg_name);
			break;
	case RCC_APB1ENR:
		SET_BIT(RCC->RCC_APB1ENR,sup_reg_name);
			break;
	case RCC_APB2ENR:
		SET_BIT(RCC->RCC_APB2ENR,sup_reg_name);
			break;
	case RCC_AHB1LPENR:
		SET_BIT(RCC->RCC_AHB1LPENR,sup_reg_name);
			break;
	case RCC_AHB2LPENR:
		SET_BIT(RCC->RCC_AHB2LPENR,sup_reg_name);
			break;
	case RCC_AHB3LPENR:
		SET_BIT(RCC->RCC_AHB3LPENR,sup_reg_name);
			break;
	case RCC_APB1LPENR:
		SET_BIT(RCC->RCC_APB1LPENR,sup_reg_name);
			break;
	case RCC_APB2LPENR:
		SET_BIT(RCC->RCC_APB2LPENR,sup_reg_name);
			break;
	case RCC_BDCR:
		SET_BIT(RCC->RCC_BDCR,sup_reg_name);
			break;
	case RCC_CSR:
		SET_BIT(RCC->RCC_CSR,sup_reg_name);
			break;
	case RCC_SSCGR:
		SET_BIT(RCC->RCC_SSCGR,sup_reg_name);
			break;
	case RCC_PLLI2SCFGR:
		SET_BIT(RCC->RCC_PLLI2SCFGR,sup_reg_name);
			break;
	default :
		//nothing
		break;

	}


}

void RCC_Disable(rcc_register_name_t reg_name,uint8_t sup_reg_name){
	switch(reg_name){
		case RCC_CR:
			CLEAR_BIT(RCC->RCC_CR,sup_reg_name);
			break;
		case RCC_PLLCFGR:
			CLEAR_BIT(RCC->RCC_PLLCFGR,sup_reg_name);
				break;
		case RCC_CFGR:
			CLEAR_BIT(RCC->RCC_CFGR,sup_reg_name);
				break;
		case RCC_CIR:
			CLEAR_BIT(RCC->RCC_CIR,sup_reg_name);
				break;
		case RCC_AHB1RSTR:
			CLEAR_BIT(RCC->RCC_AHB1RSTR,sup_reg_name);
				break;
		case RCC_AHB2RSTR:
			CLEAR_BIT(RCC->RCC_AHB2RSTR,sup_reg_name);
				break;
		case RCC_AHB3RSTR:
			CLEAR_BIT(RCC->RCC_AHB3RSTR,sup_reg_name);
				break;
		case RCC_APB1RSTR:
			CLEAR_BIT(RCC->RCC_APB1RSTR,sup_reg_name);
				break;
		case RCC_APB2RSTR:
			CLEAR_BIT(RCC->RCC_APB2RSTR,sup_reg_name);
				break;
		case RCC_AHB1ENR:
			CLEAR_BIT(RCC->RCC_AHB1ENR,sup_reg_name);
				break;
		case RCC_AHB2ENR:
			CLEAR_BIT(RCC->RCC_AHB2ENR,sup_reg_name);
				break;
		case RCC_AHB3ENR:
			CLEAR_BIT(RCC->RCC_AHB3ENR,sup_reg_name);
				break;
		case RCC_APB1ENR:
			CLEAR_BIT(RCC->RCC_APB1ENR,sup_reg_name);
				break;
		case RCC_APB2ENR:
			CLEAR_BIT(RCC->RCC_APB2ENR,sup_reg_name);
				break;
		case RCC_AHB1LPENR:
			CLEAR_BIT(RCC->RCC_AHB1LPENR,sup_reg_name);
				break;
		case RCC_AHB2LPENR:
			CLEAR_BIT(RCC->RCC_AHB2LPENR,sup_reg_name);
				break;
		case RCC_AHB3LPENR:
			CLEAR_BIT(RCC->RCC_AHB3LPENR,sup_reg_name);
				break;
		case RCC_APB1LPENR:
			CLEAR_BIT(RCC->RCC_APB1LPENR,sup_reg_name);
				break;
		case RCC_APB2LPENR:
			CLEAR_BIT(RCC->RCC_APB2LPENR,sup_reg_name);
				break;
		case RCC_BDCR:
			CLEAR_BIT(RCC->RCC_BDCR,sup_reg_name);
				break;
		case RCC_CSR:
			CLEAR_BIT(RCC->RCC_CSR,sup_reg_name);
				break;
		case RCC_SSCGR:
			CLEAR_BIT(RCC->RCC_SSCGR,sup_reg_name);
				break;
		case RCC_PLLI2SCFGR:
			CLEAR_BIT(RCC->RCC_PLLI2SCFGR,sup_reg_name);
				break;
		default :
			//nothing
			break;

		}

}


ret_statuse_t rcc_oscillatior_cfg(rcc_oscillatio_cfg *ptr){
	ret_statuse_t statuse=FUNCTION_NOK;
	uint32_t l_prescaller=0;
		if(NULL!=ptr){

			switch(ptr->oscillatio_type){
			case RCC_NONE:

				break;
			case RCC_HSE:
				if(ptr->rcc_hse==RCC_ON){
					RCC_Enable(RCC_CR,16);
				}
				else{
					RCC_Disable(RCC_CR,16);
				}
							break;
			case RCC_HSI:
				if(ptr->rcc_hse==RCC_ON){
									RCC_Enable(RCC_CR,16);
								}
								else{
									RCC_Disable(RCC_CR,16);
								}
							break;
			case RCC_LSE:
				if(ptr->rcc_hse==RCC_ON){
									RCC_Enable(RCC_CR,16);
								}
								else{
									RCC_Disable(RCC_CR,16);
								}
							break;
			case RCC_LSI:
				if(ptr->rcc_hse==RCC_ON){
									RCC_Enable(RCC_CR,16);
								}
								else{
									RCC_Disable(RCC_CR,16);
								}
										break;
			default:
				// nothing
				break;
			}


				l_prescaller|=(uint32_t)((((uint32_t)(ptr->osci_prescaller_cfg.AHP_prescaller))<<4) | (((uint32_t)(ptr->osci_prescaller_cfg.APB1_prescaller))<<10) | (((uint32_t)(ptr->osci_prescaller_cfg.APB2_prescaller))<<13));
				RCC->RCC_CFGR|=l_prescaller;
		statuse=FUNCTION_OK;
	}

	return statuse;
}
