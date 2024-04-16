/*
 * FLASH.h
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include <stm32h757xx.h>

#define ACR_offset              0x00
#define KEYR1_offset            0x04
#define OPTKEYR_offset          0x08
#define CR1_offset              0x0C
#define SR1_offset              0x10
#define CCR1_offset             0x14
#define OPTCR_offset            0x18
#define OPTSR_CUR_offset        0x1C
#define OPTSR_PRG_offset        0x20
#define OPTCCR_offset           0x24
#define PRAR_CUR1_offset        0x28
#define PRAR_PRG1_offset        0x2C
#define SCAR_CUR1_offset        0x30
#define SCAR_PRG1_offset        0x34
#define WPSN_CUR1_offset        0x38
#define WPSN_PRG1_offset        0x3C
#define BOOT7_CUR_offset        0x40
#define BOOT7_PRG_offset        0x44
#define BOOT4_CUR_offset        0x48
#define BOOT4_PRG_offset        0x4C
#define CRCCR1_offset           0x50
#define CRCSADD1_offset         0x54
#define CRCEADD1_offset         0x58
#define CRCDATA_offset          0x5C
#define ECC_FA1_offset          0x60
#define KEYR2_offset            0x104
#define CR2_offset              0x10C
#define SR2_offset              0x110
#define CCR2_offset             0x114
#define PRAR_CUR2_offset        0x128
#define PRAR_PRG2_offset        0x12C
#define SCAR_CUR2_offset        0x130
#define SCAR_PRG2_offset        0x134
#define WPSN_CUR2_offset        0x138
#define WPSN_PRG2_offset        0x13C
#define CRCCR2_offset           0x150
#define CRCSADD2_offset         0x154
#define CRCEADD2_offset         0x158
#define CRCDATA2_offset         0x15C
#define ECC_FA2_offset          0x160

void flash_config();

#endif /* INC_FLASH_H_ */
