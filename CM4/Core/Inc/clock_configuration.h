/*
 * clock_configuration.h
 *
 *  Created on: Mar 29, 2024
 *      Author: louis
 */

#ifndef INC_CLOCK_CONFIGURATION_H_
#define INC_CLOCK_CONFIGURATION_H_

/*
 * Macro substitution
*/
#define bitshift(VAL, POS)          VAL << POS


/*
 * Configuration des entrées de la clock
*/

#define RCC_CR_address 0x58024400

#define CR_PLL1RDY_Pos              25
#define CR_PLL1RDY_Msk              (1 << CR_PLL1RDY_Pos)
#define CR_PLL1RDY                  CR_PLL1RDY_Msk                    // Flag PLL1 ready

#define CR_PLL1ON_Pos               24
#define CR_PLL1ON_Msk               (1 << CR_PLL1ON_Pos)
#define CR_PLL1ON                   CR_PLL1ON_Msk                    // ENABLE PLL1

#define CR_HSIDIV_1_Pos             4
#define CR_HSIDIV_1_Msk             (1 << CR_HSIDIV_1_Pos)
#define CR_HSIDIV_1                 CR_HSIDIV_1_Msk                    // Bit 1 HSI CLOCK DIVIDER

#define CR_HSIDIV_0_Pos             3
#define CR_HSIDIV_0_Msk             (1 << CR_HSIDIV_0_Pos)
#define CR_HSIDIV_0                 CR_HSIDIV_0_Msk                    // Bit 0 HSI CLOCK DIVIDER

#define CR_HSIRDY_Pos               2
#define CR_HSIRDY_Msk               (1 << CR_HSIRDY_Pos)
#define CR_HSIRDY                   CR_HSIRDY_Msk                    // Flag HSI stable

#define CR_HSION_Pos                0
#define CR_HSION_Msk                (1 << CR_HSION_Pos)
#define CR_HSION                    CR_HSION_Msk                    // ENABLE HSI


/*
 * Configuration des MUX
*/

#define RCC_CFGR_address 0x58024410

#define CFGR_TIMPRE_Pos           15
#define CFGR_TIMPRE_Msk           (1 << CFGR_TIMPRE_Pos)
#define CFGR_TIMPRE               CFGR_TIMPRE_Msk              // Timer clocks prescaler

#define CFGR_STOPKERWUCK_Pos      7
#define CFGR_STOPKERWUCK_Msk      (1 << CFGR_STOPKERWUCK_Pos)
#define CFGR_STOPKERWUCK          CFGR_STOPKERWUCK_Msk          // HSI / CSI kernel clock selection after stop state system

#define CFGR_STOPWUCK_Pos         6
#define CFGR_STOPWUCK_Msk         (1 << CFGR_STOPWUCK_Pos)
#define CFGR_STOPWUCK             CFGR_STOPWUCK_Msk            // HSI / CSI selection after stop state system

#define CFGR_SW_2_Pos             2
#define CFGR_SW_2_Msk             (1 << CFGR_SW_2_Pos)
#define CFGR_SW_2                 CFGR_SW_2_Msk                // Bit 2 HSI CLOCK DIVIDER

#define CFGR_SW_1_Pos             1
#define CFGR_SW_1_Msk             (1 << CFGR_SW_1_Pos)
#define CFGR_SW_1                 CFGR_SW_1_Msk                    // Bit 1 System clock switch

#define CFGR_SW_0_Pos             0
#define CFGR_SW_0_Msk             (1 << CFGR_SW_0_Pos)
#define CFGR_SW_0                 CFGR_SW_0_Msk                    // Bit 0 System clock switch


/*
 * Configuration des prescalers D1 domain
*/

#define RCC_D1CFGR_address 0x58024418

#define D1CFGR_D1CPRE_Pos             8
#define D1CFGR_D1CPRE_Msk             (1 << D1CFGR_D1CPRE_Pos)
#define D1CFGR_D1CPRE                 D1CFGR_D1CPRE_Msk				// D1CPRE prescaler

#define D1CFGR_D1PPRE_Pos             4
#define D1CFGR_D1PPRE_Msk             (1 << D1CFGR_D1PPRE_Pos)
#define D1CFGR_D1PPRE                 D1CFGR_D1PPRE_Msk				// D1PPRE prescaler

#define D1CFGR_HPRE_Pos               0
#define D1CFGR_HPRE_Msk               (1 << D1CFGR_HPRE_Pos)
#define D1CFGR_HPRE                   D1CFGR_HPRE_Msk					// HPRE prescaler


/*
 * Configuration des prescalers D2 domain
*/

#define RCC_D2CFGR_address 0x5802441C

#define D2CFGR_D2PPRE1_Pos             8
#define D2CFGR_D2PPRE1_Msk             (1 << D2CFGR_D2PPRE1_Pos)
#define D2CFGR_D2PPRE1                 D2CFGR_D2PPRE1_Msk				// D2PPRE1 prescaler

#define D2CFGR_D2PPRE2_Pos             4
#define D2CFGR_D2PPRE2_Msk             (1 << D2CFGR_D2PPRE2_Pos)
#define D2CFGR_D2PPRE2                 D2CFGR_D2PPRE2_Msk				// D2PPRE2 prescaler


/*
 * Configuration des prescalers D3 domain
*/

#define RCC_D3CFGR_address 0x58024420

#define D3CFGR_D3PPRE_Pos             4
#define D3CFGR_D3PPRE_Msk             (1 << D3CFGR_D3PPRE_Pos)
#define D3CFGR_D3PPRE                 D3CFGR_D3PPRE_Msk					// D3PPRE prescaler


/*
 * Configuration des PLL clock source
*/

#define RCC_PLLCKSELR_address 0x58024428

#define PLLCKSELR_DIVM1_Pos             4
#define PLLCKSELR_DIVM1_Msk             (1 << PLLCKSELR_DIVM1_Pos)
#define PLLCKSELR_DIVM1                 PLLCKSELR_DIVM1_Msk				// DIVM1 prescaler

#define PLLCKSELR_PLLSRC_Pos            0
#define PLLCKSELR_PLLSRC_Msk            (1 << PLLCKSELR_PLLSRC_Pos)
#define PLLCKSELR_PLLSRC                PLLCKSELR_PLLSRC_Msk		 	// PLLSRC prescaler


/*
 * Configuration des prescaler des PLL
*/

#define RCC_PLLCFGR_address 0x5802442C

#define PLLCFGR_DIVP1EN_Pos            16
#define PLLCFGR_DIVP1EN_Msk            (1 << PLLCFGR_DIVP1EN_Pos)
#define PLLCFGR_DIVP1EN                PLLCFGR_DIVP1EN_Msk				// DIVP1EN divider enable

#define PLLCFGR_PLL1RGE_Pos            2
#define PLLCFGR_PLL1RGE_Msk            (1 << PLLCFGR_PLL1RGE_Pos)
#define PLLCFGR_PLL1RGE                PLLCFGR_PLL1RGE_Msk		 	// PLL1RGE clock frequency range


/*
 * Configuration des divider de la PLL1
*/

#define RCC_PLL1DIVR_address 0x58024430

#define PLL1DIVR_DIVR1_Pos            24
#define PLL1DIVR_DIVR1_Msk            (1 << PLL1DIVR_DIVR1_Pos)
#define PLL1DIVR_DIVR1                PLL1DIVR_DIVR1_Msk				// DIVR1 prescaler

#define PLL1DIVR_DIVQ1_Pos            16
#define PLL1DIVR_DIVQ1_Msk            (1 << PLL1DIVR_DIVQ1_Pos)
#define PLL1DIVR_DIVQ1                PLL1DIVR_DIVQ1_Msk		 	// DIVQ1 prescaler

#define PLL1DIVR_c_Pos                9
#define PLL1DIVR_DIVP1_Msk            (1 << PLL1DIVR_DIVP1_Pos)
#define PLL1DIVR_DIVP1                PLL1DIVR_DIVP1_Msk				// DIVP1 prescaler

#define PLL1DIVR_DIVN1_Pos            0
#define PLL1DIVR_DIVN1_Msk            (1 << PLL1DIVR_DIVN1_Pos)
#define PLL1DIVR_DIVN1                PLL1DIVR_DIVN1_Msk		 	// DIVN1 prescaler





#endif /* INC_CLOCK_CONFIGURATION_H_ */
