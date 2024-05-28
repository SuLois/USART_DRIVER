/*
 * TIM.c
 *
 *  Created on: Apr 18, 2024
 *      Author: louis
 */

#include <stdint.h>
#include "TIM.h"


void tim2_config(){

	NVIC_EnableIRQ(TIM2_IRQn); 				// Interruption 28 pour TIM2, confirmer le placement (après les configs ?)

	RCC -> APB1LENR |= RCC_APB1LENR_TIM2EN;

	TIM2 -> ARR &= 0x0;
	TIM2 -> ARR |= 0x190;			// 0d = 400

	//Configuration du prescaler
	TIM2 -> PSC |= 0x4E20;			// 0xd = 20000


	TIM2 -> DIER |= TIM_DIER_UIE;		// Interruptions activées sur UIE

	TIM2 -> CR1 |= TIM_CR1_CEN;			// Counter activé

}

void TIM2_IRQHandler(void){


	if(((TIM2 -> SR >> TIM_SR_UIF_Pos) & 0x1) == 1){

		GPIOK -> ODR ^= GPIO_ODR_OD6;		// Inverse l'état de la LED
		TIM2 -> SR &= ~TIM_SR_UIF;			// Flag à 0

	}
}


