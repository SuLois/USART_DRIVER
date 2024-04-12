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

static GPIO_TypeDef GPIO_offset = {
	.MODER = GPIO_MODER_offset,
	.OTYPER = GPIO_OTYPER_offset,
	.OSPEEDR = GPIO_OSPEEDR_offset,
	.PUPDR = GPIO_PUPDR_offset,
	.IDR = GPIO_IDR_offset,
	.ODR = GPIO_ODR_offset,
	.BSRR = GPIO_BSRR_offset,
	.LCKR = GPIO_LCKR_offset,
	.AFR = {GPIO_AFR_offset_0, GPIO_AFR_offset_1}
};


void gpio_check_freq(void){

	/* TODO : Créer une fonction pour la déclaration des registres en tant que pointer */
	volatile uint32_t *GPIO_A_MODER_register = (volatile uint32_t *)((uint32_t)GPIOA + GPIO_offset.MODER);

	*GPIO_A_MODER_register &= ~GPIO_MODER_MODE8_0;
	*GPIO_A_MODER_register |= GPIO_MODER_MODE8_1;


	// Choix de la fonction alternative --> MCO1 sur PA8 --> AF0 --> 0000
	volatile uint32_t *GPIO_A_AFRH_register = (volatile uint32_t *)((uint32_t)GPIOA + GPIO_offset.AFR[GPIO_AFR_offset_1]);

	*GPIO_A_AFRH_register &= ~GPIO_AFRH_AFSEL8_0;
	*GPIO_A_AFRH_register &= ~GPIO_AFRH_AFSEL8_1;
	*GPIO_A_AFRH_register &= ~GPIO_AFRH_AFSEL8_2;
	*GPIO_A_AFRH_register &= ~GPIO_AFRH_AFSEL8_3;



}

void delay(uint32_t nb){

	uint32_t i;

	for(i=0; i<nb; i++){}
}

void blink_LED4(void){

	volatile uint32_t *GPIO_K_MODER_register = (volatile uint32_t *)((uint32_t)GPIOK + GPIO_offset.MODER);
	volatile uint32_t *GPIO_K_BSRR_register = (volatile uint32_t *)((uint32_t)GPIOK + GPIO_offset.BSRR);

	volatile uint32_t *RCC_AHB4ENR_register = (volatile uint32_t *)RCC_AHB4ENR_address;

	//Activation de la clock sur GPIO K
	*RCC_AHB4ENR_register |= AHB4ENR_K;

	//Configuration de PK6 en OUPTUT
	*GPIO_K_MODER_register |= GPIO_MODER_MODE6_0;
	*GPIO_K_MODER_register &= ~ GPIO_MODER_MODE6_1;

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
	*GPIO_K_BSRR_register |= GPIO_BSRR_BS6;
	delay(100000);
	*GPIO_K_BSRR_register |= GPIO_BSRR_BR6;
	delay(100000);
}
/*
void usart_gpio(void){

	volatile uint32_t *GPIO_A_register = (volatile uint32_t *)GPIO_A_address;
	volatile uint32_t *GPIO_B_register = (volatile uint32_t *)GPIO_B_address;
*/
	/*
	 * Configuration du mode des GPIO PA9 (TX) et PA10 (RX)
	 *  MODER[15:0][1:0] = ‘00’: Input mode
	 *	MODER[15:0][1:0] = ‘01’: General purpose output mode
	 *	MODER[15:0][1:0] = ‘10’: Alternate function mode
	 *	MODER[15:0][1:0] = ‘11’: Analog mode (reset state)
	*/
/*
	*GPIO_A_register &= ~GPIO_PA9_0;
	*GPIO_A_register |= GPIO_PA9_1;

	*GPIO_A_register &= ~GPIO_PA10_0;
	*GPIO_A_register |= GPIO_PA10_1;


	*GPIO_B_register &= ~GPIO_PB14_0;
	*GPIO_B_register |= GPIO_PB14_1;

	*GPIO_B_register &= ~GPIO_PB15_0;
	*GPIO_B_register |= GPIO_PB15_1;
}*/
