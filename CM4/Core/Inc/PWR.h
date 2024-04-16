/*
 * PWR.h
 *
 *  Created on: Apr 16, 2024
 *      Author: louis
 */

#ifndef INC_PWR_H_
#define INC_PWR_H_

#include <stm32h757xx.h>

#define CR1_offset                   0x00
#define CSR1_offset                  0x04
#define CR2_offset                   0x08
#define CR3_offset                   0x0C
#define CPUCR_offset                 0x10
#define CPU2CR_offset                0x14
#define D3CR_offset                  0x18
#define RESERVED1_offset             0x1C
#define WKUPCR_offset                0x20
#define WKUPFR_offset                0x24
#define WKUPEPR_offset               0x28

void power_clock_config();

#endif /* INC_PWR_H_ */
