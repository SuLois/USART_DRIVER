/*
 * GPIO.c
 *
 *  Created on: Mar 28, 2024
 *      Author: louis
 */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "GPIO.h"

/*----------------------------------------------------------------------------*/


void delay(uint32_t nb){

	uint32_t i;

	for(i=0; i<nb; i++){}
}

void blink_LED4(void){

	volatile uint32_t *GPIO_K_register = (volatile uint32_t *)GPIO_K_address;
	volatile uint32_t *GPIO_K_ODR_register = (volatile uint32_t *)GPIO_K_ODR_address;
	volatile uint32_t *GPIO_K_BSRR_register = (volatile uint32_t *)GPIO_K_BSRR_address;
	volatile uint32_t *RCC_AHB4ENR_register = (volatile uint32_t *)RCC_AHB4ENR_address;

	//Activation de la clock sur GPIO K
	*RCC_AHB4ENR_register |= AHB4ENR_K;

	//Configuration de PK6 en OUPTUT
	*GPIO_K_register |= GPIO_PK6_0;
	*GPIO_K_register &= ~ GPIO_PK6_1;

	/*
	 * LED4 allumée
	 *
	 * Configuration du mode des GPIO PA9 (TX) et PA10 (RX)
	 *  BSRR[15:0] =  ‘0’: Nothing
	 *	BSRR[15:0] =  ‘1’: Set
	 *	BSRR[31:15] = ‘0’: Nothing
	 *	BSRR[31:15] = ‘1’: Reset
	*/
	//Bit mis à 1
	*GPIO_K_BSRR_register |= GPIO_BSRR_PK6;
	delay(1000000);
	*GPIO_K_BSRR_register |= GPIO_BSRR_PK6_RESET;
	delay(1000000);
}

void usart_gpio(void){

	volatile uint32_t *GPIO_A_register = (volatile uint32_t *)GPIO_A_address;
	volatile uint32_t *GPIO_B_register = (volatile uint32_t *)GPIO_B_address;

	/*
	 * Configuration du mode des GPIO PA9 (TX) et PA10 (RX)
	 *  MODER[15:0][1:0] = ‘00’: Input mode
	 *	MODER[15:0][1:0] = ‘01’: General purpose output mode
	 *	MODER[15:0][1:0] = ‘10’: Alternate function mode
	 *	MODER[15:0][1:0] = ‘11’: Analog mode (reset state)
	*/

	*GPIO_A_register &= ~GPIO_PA9_0;
	*GPIO_A_register |= GPIO_PA9_1;

	*GPIO_A_register &= ~GPIO_PA10_0;
	*GPIO_A_register |= GPIO_PA10_1;


	*GPIO_B_register &= ~GPIO_PB14_0;
	*GPIO_B_register |= GPIO_PB14_1;

	*GPIO_B_register &= ~GPIO_PB15_0;
	*GPIO_B_register |= GPIO_PB15_1;
}
