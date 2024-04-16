/*
 * PWR.c
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#include "PWR.h"


static PWR_TypeDef PWR_offset = {
  .CR1 = CR1_offset,
  .CSR1 = CSR1_offset,
  .CR2 = CR2_offset,
  .CR3 = CR3_offset,
  .CPUCR = CPUCR_offset,
  .CPU2CR = CPU2CR_offset,
  .D3CR = D3CR_offset,
  .RESERVED1 = RESERVED1_offset,
  .WKUPCR = WKUPCR_offset,
  .WKUPFR = WKUPFR_offset,
  .WKUPEPR = WKUPEPR_offset
};

void power_clock_config(){

	// Configuration de l'alimentation en fonction de la fréquence Système

	volatile uint32_t *PWR_D3CR_register = (volatile uint32_t *)((uint32_t)PWR_BASE + PWR_offset.D3CR);

	/* Programmation de l'alimentation sur Scale 2
	 * Mise à 1 en premier du bit 1 car valeur VOS[0:1] = 00 interdite
	*/
	*PWR_D3CR_register |= PWR_CSR1_ACTVOS_1;
	*PWR_D3CR_register &= ~PWR_CSR1_ACTVOS_0;


	while(((*PWR_D3CR_register >> 13) & 0x1) != 1) ;		// Attente niveau de tension Scale 2

}
