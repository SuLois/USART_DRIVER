/*
 * RCC_CLOCK.h
 *
 *  Created on: Apr 4, 2024
 *      Author: louis
 */

#ifndef INC_RCC_CLOCK_H_
#define INC_RCC_CLOCK_H_

#include <stm32h757xx.h>


/*
 * Offset des registres
*/

#define CR_offset                      0x00
#define HSICFGR_offset                 0x04
#define CRRCR_offset                   0x08
#define CSICFGR_offset                 0x0C
#define CFGR_offset                    0x10
#define RESERVED1_offset               0x14
#define D1CFGR_offset                  0x18
#define D2CFGR_offset                  0x1C
#define D3CFGR_offset                  0x20
#define RESERVED2_offset               0x24
#define PLLCKSELR_offset               0x28
#define PLLCFGR_offset                 0x2C
#define PLL1DIVR_offset                0x30
#define PLL1FRACR_offset               0x34
#define PLL2DIVR_offset                0x38
#define PLL2FRACR_offset               0x3C
#define PLL3DIVR_offset                0x40
#define PLL3FRACR_offset               0x44
#define RESERVED3_offset               0x48
#define D1CCIPR_offset                 0x4C
#define D2CCIP1R_offset                0x50
#define D2CCIP2R_offset                0x54
#define D3CCIPR_offset                 0x58
#define RESERVED4_offset               0x5C
#define CIER_offset                    0x60
#define CIFR_offset                    0x64
#define CICR_offset                    0x68
#define RESERVED5_offset               0x6C
#define BDCR_offset                    0x70
#define CSR_offset                     0x74
#define RESERVED6_offset               0x78
#define AHB3RSTR_offset                0x7C
#define AHB1RSTR_offset                0x80
#define AHB2RSTR_offset                0x84
#define AHB4RSTR_offset                0x88
#define APB3RSTR_offset                0x8C
#define APB1LRSTR_offset               0x90
#define APB1HRSTR_offset               0x94
#define APB2RSTR_offset                0x98
#define APB4RSTR_offset                0x9C
#define GCR_offset                     0xA0
#define RESERVED8_offset               0xA4
#define D3AMR_offset                   0xA8
#define RSR_offset                     0xD0 /* Reset visible par les 2 CPU, pour CPU2 uniquement --> 0x190 */
#define AHB3ENR_offset                 0xD4
#define AHB1ENR_offset                 0xD8
#define AHB2ENR_offset                 0xDC
#define AHB4ENR_offset                 0xE0
#define APB3ENR_offset                 0xE4
#define APB1LENR_offset                0xE8
#define APB1HENR_offset                0xEC
#define APB2ENR_offset                 0xF0
#define APB4ENR_offset                 0xF4
#define RESERVED12_offset              0xF8
#define AHB3LPENR_offset               0xFC
#define AHB1LPENR_offset               0x100
#define AHB2LPENR_offset               0x104
#define AHB4LPENR_offset               0x108
#define APB3LPENR_offset               0x10C
#define APB1LLPENR_offset              0x110
#define APB1HLPENR_offset              0x114
#define APB2LPENR_offset               0x118
#define APB4LPENR_offset               0x11C

#endif /* INC_RCC_CLOCK_H_ */
