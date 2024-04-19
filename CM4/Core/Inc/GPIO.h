/*
 * GPIO.h
 *
 *  Created on: Mar 28, 2024
 *      Author: louis
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stm32h757xx.h>


/*
 * Offset des registres
*/
#define GPIO_MODER_offset			0x00
#define GPIO_OTYPER_offset          0x04
#define GPIO_OSPEEDR_offset         0x08
#define GPIO_PUPDR_offset           0x0C
#define GPIO_IDR_offset             0x10
#define GPIO_ODR_offset             0x14
#define GPIO_BSRR_offset            0x18
#define GPIO_LCKR_offset            0x1C
#define GPIO_AFR_offset_0           0x00
#define GPIO_AFR_offset_1           0x24

/*
 * Activation de la clock sur GPIO  p492
*/
#define RCC_AHB4ENR_address 0x580244e0

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


void gpio_check_freq();
void blink_LED4();
void usart_gpio(void);

#endif /* INC_GPIO_H_ */
