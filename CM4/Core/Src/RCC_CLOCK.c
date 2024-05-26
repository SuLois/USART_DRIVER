/*
 * RCC_CLOCK.c
 *
 *  Created on: Apr 4, 2024
 *      Author: louis
 */

#include <stdint.h>
#include "RCC_CLOCK.h"

void clock_config(){


	RCC -> RSR |= RCC_RSR_SFT2RSTF; 					// Reset des registres du CPU2


	RCC -> CR |= RCC_CR_HSEON; 							// Clock HSE on
	RCC -> CFGR |= RCC_CFGR_SW_HSE; 					// Sys CLK sur HSE

	RCC -> CR &= ~RCC_CR_HSION; 						// Clock HSI off
	RCC -> CR &= RCC_CR_HSIDIV_1; 						// RAZ prescaler HSI
	RCC -> CR |= RCC_CR_HSIDIV_8; 						// Prescaler HSI /8

	/* ------------ MUX MCO1 sur HSI [0, 0, 0] ------------ */
	RCC -> CFGR &= ~RCC_CFGR_MCO1_0;
	RCC -> CFGR &= ~RCC_CFGR_MCO1_1;
	RCC -> CFGR &= ~RCC_CFGR_MCO1_2;

	RCC -> CFGR &= RCC_CFGR_SW_HSI; 						// Sys CLK sur HSI

	/* ------- Division par 10 à la sortie sur MCO1 ------- */
	/*
	RCC -> CFGR &= ~RCC_CFGR_MCO1PRE_0;
	RCC -> CFGR |= RCC_CFGR_MCO1PRE_1;
	RCC -> CFGR &= ~RCC_CFGR_MCO1PRE_2;
	RCC -> CFGR |= RCC_CFGR_MCO1PRE_3;
	*/

	RCC -> CR |= RCC_CR_HSION; 							// Clock HSI on
	while(((RCC -> CR >> 2) & 0x1) != 1) ; 				// Attente HSI stable

	RCC -> CR &= ~RCC_CR_HSEON; 						// Clock HSE off


	while(((RCC -> CR >> 14) & 0x1) != 1) ; 			// Clock domain stable D1
	while(((RCC -> CR >> 15) & 0x1) != 1) ;				// -				   D2

	RCC -> D1CFGR &= ~RCC_D1CFGR_HPRE_DIV1; 			// HPRE PRESCALER /0
	RCC -> D1CFGR &= ~RCC_D1CFGR_D1PPRE_DIV1; 			// D1PPRE PRESCALER /0
	RCC -> D1CFGR &= ~RCC_D1CFGR_D1CPRE_DIV1; 			// D1CPRE PRESCALER /0


	/*
	 * Mise à ON des clock périphériques
	*/

	RCC -> AHB4ENR |= RCC_AHB4ENR_GPIOAEN;

}
