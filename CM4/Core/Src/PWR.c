/*
 * PWR.c
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#include "PWR.h"

void power_clock_config(){

	// Configuration de l'alimentation en fonction de la fréquence Système

	/* Programmation de l'alimentation sur Scale 2
	 * Mise à 1 en premier du bit 1 car valeur VOS[0:1] = 00 interdite
	*/
	PWR -> D3CR |= PWR_CSR1_ACTVOS_1;
	PWR -> D3CR &= ~PWR_CSR1_ACTVOS_0;


	while(((PWR -> D3CR >> 13) & 0x1) != 1) ;		// Attente niveau de tension Scale 2

}
