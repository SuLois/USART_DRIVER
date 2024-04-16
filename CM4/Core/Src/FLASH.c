/*
 * FLASH.c
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#include "FLASH.h"

static FLASH_TypeDef FLASH_offset = {
        .ACR = ACR_offset,
        .KEYR1 = KEYR1_offset,
        .OPTKEYR = OPTKEYR_offset,
        .CR1 = CR1_offset,
        .SR1 = SR1_offset,
        .CCR1 = CCR1_offset,
        .OPTCR = OPTCR_offset,
        .OPTSR_CUR = OPTSR_CUR_offset,
        .OPTSR_PRG = OPTSR_PRG_offset,
        .OPTCCR = OPTCCR_offset,
        .PRAR_CUR1 = PRAR_CUR1_offset,
        .PRAR_PRG1 = PRAR_PRG1_offset,
        .SCAR_CUR1 = SCAR_CUR1_offset,
        .SCAR_PRG1 = SCAR_PRG1_offset,
        .WPSN_CUR1 = WPSN_CUR1_offset,
        .WPSN_PRG1 = WPSN_PRG1_offset,
        .BOOT7_CUR = BOOT7_CUR_offset,
        .BOOT7_PRG = BOOT7_PRG_offset,
        .BOOT4_CUR = BOOT4_CUR_offset,
        .BOOT4_PRG = BOOT4_PRG_offset,
        .CRCCR1 = CRCCR1_offset,
        .CRCSADD1 = CRCSADD1_offset,
        .CRCEADD1 = CRCEADD1_offset,
        .CRCDATA = CRCDATA_offset,
        .ECC_FA1 = ECC_FA1_offset,
        .KEYR2 = KEYR2_offset,
        .CR2 = CR2_offset,
        .SR2 = SR2_offset,
        .CCR2 = CCR2_offset,
        .PRAR_CUR2 = PRAR_CUR2_offset,
        .PRAR_PRG2 = PRAR_PRG2_offset,
        .SCAR_CUR2 = SCAR_CUR2_offset,
        .SCAR_PRG2 = SCAR_PRG2_offset,
        .WPSN_CUR2 = WPSN_CUR2_offset,
        .WPSN_PRG2 = WPSN_PRG2_offset,
        .CRCCR2 = CRCCR2_offset,
        .CRCSADD2 = CRCSADD2_offset,
        .CRCEADD2 = CRCEADD2_offset,
        .CRCDATA2 = CRCDATA2_offset,
        .ECC_FA2 = ECC_FA2_offset
};

void flash_config(){

	// Configuration du nombre d'état d'attente en fonction de la fréquence Système

    volatile uint32_t *FLASH_ACR_register = (volatile uint32_t *)((uint32_t)FLASH_R_BASE + FLASH_offset.ACR);

	/* Configuration du nombre d'état d'attente en fonction de la fréquence Système
	 * Voir Table 16 dans la doc pour détail sur le choix des bits
	 * Ici : Sys_clk = 96 MHz donc 55 < 96 < 110
	 * Soit VS02 pour 1WS
	*/
    *FLASH_ACR_register |= FLASH_ACR_WRHIGHFREQ_0;
    *FLASH_ACR_register &= ~FLASH_ACR_WRHIGHFREQ_1;

    *FLASH_ACR_register &= FLASH_ACR_LATENCY_0WS;	// RAZ du registre afin configuration
    *FLASH_ACR_register |= FLASH_ACR_LATENCY_1WS;	// 1WS soit 2 FLASH clock cycle
}
