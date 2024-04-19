/*
 * TIM.c
 *
 *  Created on: Apr 18, 2024
 *      Author: louis
 */

#include <stdint.h>
#include "TIM.h"

static TIM_TypeDef TIM_offset = {
		.CR1 = CR1_offset,
		.CR2 = CR2_offset,
		.SMCR = SMCR_offset,
		.CCMR1 = CCMR1_offset
};


void tim2_config(){

	volatile uint32_t *TIM2_CR1_register = (volatile uint32_t *)((uint32_t)TIM2_BASE + TIM_offset.CR1);

	*TIM2_CR1_register |=  TIM_CR1_CEN; 		// Counter activé
	*TIM2_CR1_register &=  ~TIM_CR1_UDIS; 		// UEV flag activé
	*TIM2_CR1_register |=  TIM_CR1_URS; 		// UEV flag event uniquement sur over/underflow counter ou DMA request
	*TIM2_CR1_register &=  ~TIM_CR1_OPM;		// One Pulse mode désactivé
	*TIM2_CR1_register &=  ~TIM_CR1_DIR; 		// Direction upcounter

	*TIM2_CR1_register &=  ~TIM_CR1_CMS;
	*TIM2_CR1_register &=  ~TIM_CR1_CMS_1;		// Dependance DIR mode

	*TIM2_CR1_register &=  ~TIM_CR1_ARPE;		// Auto-reaload preload désactivé (no buffer)

	*TIM2_CR1_register &=  ~TIM_CR1_CKD_0;		//T_ck_int division /4
	*TIM2_CR1_register |=  TIM_CR1_CKD_1;		//

	*TIM2_CR1_register |=  TIM_CR1_UIFREMAP;	// Remapping ** A VERIF **


	volatile uint32_t *TIM2_CR2_register = (volatile uint32_t *)((uint32_t)TIM2_BASE + TIM_offset.CR2);

	/* Pas de configuration pour master / slaves TIMERS */
	*TIM2_CR2_register &= ~TIM_CR2_TI1S;		// TIM2_CH1 pin connecté TI1 input


	volatile uint32_t *TIM2_SMCR_register = (volatile uint32_t *)((uint32_t)TIM2_BASE + TIM_offset.SMCR);

	*TIM2_SMCR_register &= ~TIM_SMCR_SMS_0; 	//  Slave mode désactivé
	*TIM2_SMCR_register &= ~TIM_SMCR_SMS_1;
	*TIM2_SMCR_register &= ~TIM_SMCR_SMS_2;
	*TIM2_SMCR_register &= ~TIM_SMCR_SMS_3;



	volatile uint32_t *TIM2_CCER_register = (volatile uint32_t *)((uint32_t)TIM2_BASE + TIM_offset.CCER);

	*TIM2_CCER_register &= ~TIM_CCER_CC1NP; 	// CC1 OUTPUT
	*TIM2_CCER_register &= ~TIM_CCER_CC1P; 		// CC1 OUTPUT

	*TIM2_CCER_register &= ~TIM_CCER_CC1E;		// OC1 désactivé pour configuration bit CC1S de CCMR1


	volatile uint32_t *TIM2_CCMR1_register = (volatile uint32_t *)((uint32_t)TIM2_BASE + TIM_offset.CCMR1);

	*TIM2_CCMR1_register |= TIM_CCMR1_OC2M_0;	// Comparaison COUNTER et CCR1 (overflow)
	*TIM2_CCMR1_register |= TIM_CCMR1_OC2M_1;
	*TIM2_CCMR1_register &= ~TIM_CCMR1_OC2M_2;
	*TIM2_CCMR1_register &= ~TIM_CCMR1_OC2M_3;

	*TIM2_CCMR1_register &= ~TIM_CCMR1_CC1S_0;	// CC1 configuré en OUTPUT
	*TIM2_CCMR1_register &= ~TIM_CCMR1_CC1S_1;

	*TIM2_CCER_register |= TIM_CCER_CC1E;		// OC1 activé
}
