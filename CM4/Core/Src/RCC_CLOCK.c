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


	/*Configuration intiale PLL1

	//Configuration des prescaler internes PLL1
	RCC -> PLL1DIVR &= ~RCC_PLL1DIVR_N1;				// RAZ
	RCC -> PLL1DIVR |= 0xB << RCC_PLL1DIVR_N1_Pos; 		// Prescaler DIVN1 a 12 /!\ correspond à 0xB et non 0xC !!
	RCC -> PLL1DIVR &= ~RCC_PLL1DIVR_P1;				// RAZ
	RCC -> PLL1DIVR |= 0x1 << RCC_PLL1DIVR_P1_Pos; 		// Prescaler DIVP1 a 2 par défaut
	RCC -> PLL1DIVR &= ~RCC_PLL1DIVR_Q1;				// RAZ
	RCC -> PLL1DIVR |= 0x0 << RCC_PLL1DIVR_Q1_Pos; 		// Prescaler DIVQ1 a 1
	RCC -> PLL1DIVR |= 0x1 << RCC_PLL1DIVR_R1_Pos; 		// Prescaler DIVQ1 a 1

	RCC -> PLLCKSELR &= RCC_PLLCKSELR_PLLSRC_HSI; 		// PLL1 source : HSI
	RCC -> PLLCKSELR &= 0xFC0C0C0F; 					// mask DIVM* prescaler 1111 1100 0000 1100 0000 1100 0000 1111
	RCC -> PLLCKSELR |= RCC_PLLCKSELR_DIVM1_2; 			// DIVM1 PRESCALER /4
	//DIVM3 PRESCALER DISABLED

	*RCC_CIER_register |= RCC_CIER_PLL1RDYIE; 				// Activer les interruptions sur flag PLL1 READY
	*RCC_CICR_register |= RCC_CICR_PLLRDYC; 				// reset interruptions sur flag PLL1 READY
	*/

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
	RCC -> CFGR &= ~RCC_CFGR_MCO1PRE_0;
	RCC -> CFGR |= RCC_CFGR_MCO1PRE_1;
	RCC -> CFGR &= ~RCC_CFGR_MCO1PRE_2;
	RCC -> CFGR |= RCC_CFGR_MCO1PRE_3;

	RCC -> CR |= RCC_CR_HSION; 							// Clock HSI on
	while(((RCC -> CR >> 2) & 0x1) != 1) ; 				// Attente HSI stable

	RCC -> CR &= ~RCC_CR_HSEON; 						// Clock HSE off


	while(((RCC -> CR >> 14) & 0x1) != 1) ; 			// Clock domain stable D1
	while(((RCC -> CR >> 15) & 0x1) != 1) ;				// -				   D2

	/* Configuration finale PLL1
	RCC -> CR |= RCC_CR_PLL1ON; // PLL1 OFF
	while(((RCC -> CR >> 25) & 0x1) != 1) ; 			// PLL1 clock ready
	RCC -> CR |= RCC_CFGR_SW_PLL1; 						// Sys CLK sur PLL1
	*/

	RCC -> D1CFGR &= ~RCC_D1CFGR_HPRE_DIV1; 			// HPRE PRESCALER /0
	RCC -> D1CFGR &= ~RCC_D1CFGR_D1PPRE_DIV1; 			// D1PPRE PRESCALER /0
	RCC -> D1CFGR &= ~RCC_D1CFGR_D1CPRE_DIV1; 			// D1CPRE PRESCALER /0


	/*
	 * Mise à ON des clock périphériques
	*/

	RCC -> AHB4ENR |= RCC_AHB4ENR_GPIOAEN;

	RCC -> APB1LENR |= RCC_APB1LENR_TIM2EN;

}
