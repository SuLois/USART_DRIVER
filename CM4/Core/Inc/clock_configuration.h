/*
 * clock_configuration.h
 *
 *  Created on: Mar 29, 2024
 *      Author: louis
 */

#ifndef INC_CLOCK_CONFIGURATION_H_
#define INC_CLOCK_CONFIGURATION_H_

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



#endif /* INC_CLOCK_CONFIGURATION_H_ */
