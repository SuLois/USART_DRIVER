/*
 * TIM.h
 *
 *  Created on: Apr 18, 2024
 *      Author: louis
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include <stm32h757xx.h>

#define CR1_offset            0x00
#define CR2_offset            0x04
#define SMCR_offset           0x08
#define DIER_offset           0x0C
#define SR_offset             0x10
#define EGR_offset            0x14
#define CCMR1_offset          0x18
#define CCMR2_offset          0x1C
#define CCER_offset           0x20
#define CNT_offset            0x24
#define PSC_offset            0x28
#define ARR_offset            0x2C
#define RCR_offset            0x30
#define CCR1_offset           0x34
#define CCR2_offset           0x38
#define CCR3_offset           0x3C
#define CCR4_offset           0x40
#define BDTR_offset           0x44
#define DCR_offset            0x48
#define DMAR_offset           0x4C
#define RESERVED1_offset      0x50
#define CCMR3_offset          0x54
#define CCR5_offset           0x58
#define CCR6_offset           0x5C
#define AF1_offset            0x60
#define AF2_offset            0x64
#define TISEL_offset          0x68

void tim2_config();

#endif /* INC_TIM_H_ */
