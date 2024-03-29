/*
 * GPIO.h
 *
 *  Created on: Mar 28, 2024
 *      Author: louis
 */

/*
 * ---------------------------------------------------------------------------------------------
 * Definition des registres GPIO
 * ---------------------------------------------------------------------------------------------
*/

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

/*
 * Activation de la clock sur GPIO
*/
#define RCC_AHB4ENR_address 0x580244e0

#define AHB4ENR_A_Pos               0
#define AHB4ENR_A_Msk               (1 << AHB4ENR_A_Pos)
#define AHB4ENR_A                   AHB4ENR_A_Msk                    // Clock enabled on GPIO A

#define AHB4ENR_B_Pos               2
#define AHB4ENR_B_Msk               (1 << AHB4ENR_B_Pos)
#define AHB4ENR_B                   AHB4ENR_B_Msk                    // Clock enabled on GPIO B

#define AHB4ENR_K_Pos               10
#define AHB4ENR_K_Msk               (1 << AHB4ENR_K_Pos)
#define AHB4ENR_K                   AHB4ENR_K_Msk                    // Clock enabled on GPIO K

/*
 * Configuration des GPIO associées /!\ TODO : A DEPLACER
*/

#define GPIO_A_address 0x58020000

#define GPIO_PA9_0_Pos               18
#define GPIO_PA9_0_Msk               (1 << GPIO_PA9_0_Pos)
#define GPIO_PA9_0                   GPIO_PA9_0_Msk                    // GPIO PA9 bit 0 mode

#define GPIO_PA9_1_Pos               19
#define GPIO_PA9_1_Msk               (1 << GPIO_PA9_1_Pos)
#define GPIO_PA9_1                   GPIO_PA9_1_Msk                    // GPIO PA9 bit 1 mode

#define GPIO_PA10_0_Pos              20
#define GPIO_PA10_0_Msk              (1 << GPIO_PA10_0_Pos)
#define GPIO_PA10_0                  GPIO_PA10_0_Msk                   // GPIO PA10 bit 0 mode

#define GPIO_PA10_1_Pos              21
#define GPIO_PA10_1_Msk              (1 << GPIO_PA10_1_Pos)
#define GPIO_PA10_1                  GPIO_PA10_1_Msk                   // GPIO PA10 bit 1 mode


#define GPIO_B_address 0x58020400

#define GPIO_PB14_0_Pos              28
#define GPIO_PB14_0_Msk              (1 << GPIO_PB14_0_Pos)
#define GPIO_PB14_0                  GPIO_PB14_0_Msk                   // GPIO PB14 bit 0 mode

#define GPIO_PB14_1_Pos              29
#define GPIO_PB14_1_Msk              (1 << GPIO_PB14_1_Pos)
#define GPIO_PB14_1                  GPIO_PB14_1_Msk                   // GPIO PB14 bit 1 mode

#define GPIO_PB15_0_Pos              30
#define GPIO_PB15_0_Msk              (1 << GPIO_PB15_0_Pos)
#define GPIO_PB15_0                  GPIO_PB15_0_Msk                   // GPIO PB15 bit 0 mode

#define GPIO_PB15_1_Pos              31
#define GPIO_PB15_1_Msk              (1 << GPIO_PB15_1_Pos)
#define GPIO_PB15_1                  GPIO_PB15_1_Msk                   // GPIO PB15 bit 1 mode


#define GPIO_K_address 0x58022800

#define GPIO_PK6_0_Pos               12
#define GPIO_PK6_0_Msk               (1 << GPIO_PK6_0_Pos)
#define GPIO_PK6_0                   GPIO_PK6_0_Msk                    // GPIO PK6 bit 0 mode

#define GPIO_PK6_1_Pos               13
#define GPIO_PK6_1_Msk               (1 << GPIO_PK6_1_Pos)
#define GPIO_PK6_1                   GPIO_PK6_1_Msk                    // GPIO PK6 bit 1 mode


// GPIO port output data register ODR --> connaitre l'état de la GPIO en sortie

#define GPIO_K_ODR_address 0x58022814

#define GPIO_ODR_PK6_Pos             6
#define GPIO_ODR_PK6_Msk             (1 << GPIO_ODR_PK6_Pos)
#define GPIO_ODR_PK6                 GPIO_ODR_PK6_Msk                  // GPIO output state


// GPIO port bit set/reset BSRR --> SET ou RESET la GPIO

#define GPIO_K_BSRR_address 0x58022818

#define GPIO_BSRR_PK6_Pos             6
#define GPIO_BSRR_PK6_Msk             (1 << GPIO_BSRR_PK6_Pos)
#define GPIO_BSRR_PK6                 GPIO_BSRR_PK6_Msk                  // GPIO set

#define GPIO_BSRR_PK6_RESET_Pos       22
#define GPIO_BSRR_PK6_RESET_Msk       (1 << GPIO_BSRR_PK6_RESET_Pos)
#define GPIO_BSRR_PK6_RESET           GPIO_BSRR_PK6_RESET_Msk            // GPIO set/reset

void blink_LED4();
void usart_gpio(void);

#endif /* INC_GPIO_H_ */
