/*
 * FLASH.c
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#include "FLASH.h"

void flash_config(){

	// Configuration du nombre d'état d'attente en fonction de la fréquence Système

	/* Configuration du nombre d'état d'attente en fonction de la fréquence Système
	 * Voir Table 16 dans la doc pour détail sur le choix des bits
	 * Ici : Sys_clk = 96 MHz donc 55 < 96 < 110
	 * Soit VS02 pour 1WS
	*/
    FLASH -> ACR |= FLASH_ACR_WRHIGHFREQ_0;
    FLASH -> ACR &= ~FLASH_ACR_WRHIGHFREQ_1;

    FLASH -> ACR &= FLASH_ACR_LATENCY_0WS;	// RAZ du registre afin configuration
    FLASH -> ACR |= FLASH_ACR_LATENCY_1WS;	// 1WS soit 2 FLASH clock cycle
}
