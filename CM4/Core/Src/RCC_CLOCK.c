/*
 * RCC_CLOCK.c
 *
 *  Created on: Apr 4, 2024
 *      Author: louis
 */

#include <stdint.h>
#include "RCC_CLOCK.h"

static RCC_TypeDef RCC_offset = {
	    .CR = CR_offset,
	    .HSICFGR = HSICFGR_offset,
	    .CRRCR = CRRCR_offset,
	    .CSICFGR = CSICFGR_offset,
	    .CFGR = CFGR_offset,
	    .RESERVED1 = RESERVED1_offset,
	    .D1CFGR = D1CFGR_offset,
	    .D2CFGR = D2CFGR_offset,
	    .D3CFGR = D3CFGR_offset,
	    .RESERVED2 = RESERVED2_offset,
	    .PLLCKSELR = PLLCKSELR_offset,
	    .PLLCFGR = PLLCFGR_offset,
	    .PLL1DIVR = PLL1DIVR_offset,
	    .PLL1FRACR = PLL1FRACR_offset,
	    .PLL2DIVR = PLL2DIVR_offset,
	    .PLL2FRACR = PLL2FRACR_offset,
	    .PLL3DIVR = PLL3DIVR_offset,
	    .PLL3FRACR = PLL3FRACR_offset,
	    .RESERVED3 = RESERVED3_offset,
	    .D1CCIPR = D1CCIPR_offset,
	    .D2CCIP1R = D2CCIP1R_offset,
	    .D2CCIP2R = D2CCIP2R_offset,
	    .D3CCIPR = D3CCIPR_offset,
	    .RESERVED4 = RESERVED4_offset,
	    .CIER = CIER_offset,
	    .CIFR = CIFR_offset,
	    .CICR = CICR_offset,
	    .RESERVED5 = RESERVED5_offset,
	    .BDCR = BDCR_offset,
	    .CSR = CSR_offset,
	    .RESERVED6 = RESERVED6_offset,
	    .AHB3RSTR = AHB3RSTR_offset,
	    .AHB1RSTR = AHB1RSTR_offset,
	    .AHB2RSTR = AHB2RSTR_offset,
	    .AHB4RSTR = AHB4RSTR_offset,
	    .APB3RSTR = APB3RSTR_offset,
	    .APB1LRSTR = APB1LRSTR_offset,
	    .APB1HRSTR = APB1HRSTR_offset,
	    .APB2RSTR = APB2RSTR_offset,
	    .APB4RSTR = APB4RSTR_offset,
	    .GCR = GCR_offset,
	    .RESERVED8 = RESERVED8_offset,
	    .D3AMR = D3AMR_offset,
	    .RSR = RSR_offset,
	    .AHB3ENR = AHB3ENR_offset,
	    .AHB1ENR = AHB1ENR_offset,
	    .AHB2ENR = AHB2ENR_offset,
	    .AHB4ENR = AHB4ENR_offset,
	    .APB3ENR = APB3ENR_offset,
	    .APB1LENR = APB1LENR_offset,
	    .APB1HENR = APB1HENR_offset,
	    .APB2ENR = APB2ENR_offset,
	    .APB4ENR = APB4ENR_offset,
	    .RESERVED12 = RESERVED12_offset,
	    .AHB3LPENR = AHB3LPENR_offset,
	    .AHB1LPENR = AHB1LPENR_offset,
	    .AHB2LPENR = AHB2LPENR_offset,
	    .AHB4LPENR = AHB4LPENR_offset,
	    .APB3LPENR = APB3LPENR_offset,
	    .APB1LLPENR = APB1LLPENR_offset,
	    .APB1HLPENR = APB1HLPENR_offset,
	    .APB2LPENR = APB2LPENR_offset,
	    .APB4LPENR = APB4LPENR_offset
};

void clock_config(){


	/* --------- Configuration registre RSR -------- */

	volatile uint32_t *RCC_RSR_register = (volatile uint32_t *)((uint32_t)RCC_BASE + RCC_offset.RSR);

	*RCC_RSR_register |= RCC_RSR_SFT2RSTF; //Reset des registres du CPU2


	/* --------- Configuration registre CR -------- */

	volatile uint32_t *RCC_CR_register = (volatile uint32_t *)((uint32_t)RCC_BASE + RCC_offset.CR);

	*RCC_CR_register |= RCC_CR_HSION; // Clock d'entrée HSI

	while(((*RCC_CR_register >> 2) & 0x1) != 1) ; // Attente HSI stable

	*RCC_CR_register |= RCC_CR_HSIDIV_1; // Prescaler HSI /1

	while(((*RCC_CR_register >> 14) & 0x1) != 1) ; // Clock domain stable D1
	while(((*RCC_CR_register >> 15) & 0x1) != 1) ; // -					  D2

	*RCC_CR_register |= RCC_CR_PLL1ON; // PLL1 ON
	while(((*RCC_CR_register >> 25) & 0x1) != 1) ; // PLL1 clock ready


	/* --------- Configuration registre CFGR -------- */

	volatile uint32_t *RCC_CFGR_register = (volatile uint32_t *)((uint32_t)RCC_BASE + RCC_offset.CFGR);

	*RCC_CFGR_register |= RCC_CFGR_SW_2; // System Clock définie sur PLL1


	/* --------- Configuration registre D1CFGR -------- */

	volatile uint32_t *RCC_D1CFGR_register = (volatile uint32_t *)((uint32_t)RCC_BASE + RCC_offset.D1CFGR);

	*RCC_D1CFGR_register &= ~RCC_D1CFGR_HPRE_DIV1; //HPRE PRESCALER /0

	*RCC_D1CFGR_register &= ~RCC_D1CFGR_D1PPRE_DIV; //D1PPRE PRESCALER /0

	*RCC_D1CFGR_register &= ~RCC_D1CFGR_D1CPRE_DIV1; //D1CPRE PRESCALER /0


	/* --------- Configuration registre PLLCKSELR -------- */

	volatile uint32_t *RCC_PLLCKSELR_register = (volatile uint32_t *)((uint32_t)RCC_BASE + RCC_offset.PLLCKSELR);

	*RCC_PLLCKSELR_register &= ~RCC_PLLCKSELR_PLLSRC_HSI; // HSI CLOCK MUX

	*RCC_PLLCKSELR_register &= FC0C0C0F; //mask DIVM* prescaler
	*RCC_PLLCKSELR_register |= RCC_PLLCKSELR_DIVM1_2; //DIVM1 PRESCALER /4
	*RCC_PLLCKSELR_register |= RCC_PLLCKSELR_DIVM2_2; //DIVM2 PRESCALER /4
	//DIVM3 PRESCALER DISABLED






}
