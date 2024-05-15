/*
 * TIM.c
 *
 *  Created on: Apr 18, 2024
 *      Author: louis
 */

#include <stdint.h>
#include "TIM.h"


void tim2_config(){

	//TIM2 -> CR1 &=  ~TIM_CR1_UDIS; 		// UEV flag activé
	//TIM2 -> CR1 |=  TIM_CR1_URS; 		// UEV flag event uniquement sur over/underflow counter ou DMA request
	//TIM2 -> CR1 &=  ~TIM_CR1_OPM;		// One Pulse mode désactivé
	//TIM2 -> CR1 &=  ~TIM_CR1_DIR; 		// Direction upcounter - bit lu si CMS =/= 00

	//TIM2 -> CR1r &=  ~TIM_CR1_CMS;
	//TIM2 -> CR1 &=  ~TIM_CR1_CMS_1;		// Dependance DIR mode

	//TIM2 -> CR1 &=  ~TIM_CR1_ARPE;		// Auto-reaload preload désactivé (no buffer)

	/*
	TIM2 -> CR1 &=  ~TIM_CR1_CKD_0;		// T_ck_int division /4
	TIM2 -> CR1 |=  TIM_CR1_CKD_1;		//

	TIM2 -> CR1 |=  TIM_CR1_UIFREMAP;	// Remapping ** A VERIF **

	// Pas de configuration pour master / slaves TIMERS
	TIM2 -> CR2 &= ~TIM_CR2_TI1S;		// TIM2_CH1 pin connecté TI1 input
	*/

	//TIM2 -> SMCR &= ~TIM_SMCR_SMS_0; 	//  Slave mode désactivé
	//TIM2 -> SMCR &= ~TIM_SMCR_SMS_1;
	//TIM2 -> SMCR &= ~TIM_SMCR_SMS_2;
	//TIM2 -> SMCR &= ~TIM_SMCR_SMS_3;

	//TIM2 -> CCER &= ~TIM_CCER_CC1NP; 	// CC1 OUTPUT
	//TIM2 -> CCER &= ~TIM_CCER_CC1P; 	// CC1 OUTPUT

	//TIM2 -> CCER &= ~TIM_CCER_CC1E;	// OC1 désactivé pour configuration bit CC1S de CCMR1



	//TIM2 -> CCMR1 &= ~TIM_CCMR1_CC1S_0;	// CC1 configuré en OUTPUT, défini comportement du registre
	//TIM2 -> CCMR1 &= ~TIM_CCMR1_CC1S_1;

	//TIM2 -> CCMR1 |= TIM_CCMR1_OC1M_0;	// Comparaison COUNTER et CCR1 (overflow)
	//TIM2 -> CCMR1 |= TIM_CCMR1_OC1M_1;
	//TIM2 -> CCMR1 &= ~TIM_CCMR1_OC1M_2;
	//TIM2 -> CCMR1 &= ~TIM_CCMR1_OC1M_3;



	//TIM2 -> CCR1 |= 500; 			// Valeur comparaison avec CNT
	TIM2 -> ARR &= 0x0;
	TIM2 -> ARR |= 0x190;			// 0d = 400

	//Configuration du prescaler
	TIM2 -> PSC |= 0x4E20;			// 0xd = 20000



	//TIM2 -> DIER |= TIM_DIER_CC1IE;		// Interruptions activées sur CC1IE
	//TIM2 -> DIER |= TIM_DIER_UIE;		// Interruptions activées sur UIE

	//TIM2 -> DIER |= TIM_CCER_CC1E;		// OC1 activé

	//TIM2 -> EGR = TIM_EGR_CC1G;		// Génère flag
	//TIM2 -> EGR = TIM_EGR_UG;

	TIM2 -> CR1 |= TIM_CR1_CEN;			// Counter activé

}
/*
void TIM2_IRQHandler(void){

	if(((TIM2 -> SR >> TIM_SR_UIF_Pos) & 0x1) == 1){

		TIM2 -> SR &= ~TIM_SR_UIF;
	}

}
*/

