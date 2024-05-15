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


void gpio_check_freq(void){

	/*
	 * Configuration de la sortie de la clock systeme sur GPIO PA8
	*/

	// Alternante function sur PA8
	GPIOA -> MODER &= ~GPIO_MODER_MODE8_0;
	GPIOA -> MODER |= GPIO_MODER_MODE8_1;


	// Choix de la fonction alternative --> MCO1 sur PA8 --> AF0 --> 0000

	GPIOA -> AFR[1] &= ~GPIO_AFRH_AFSEL8_0;
	GPIOA -> AFR[1] &= ~GPIO_AFRH_AFSEL8_1;
	GPIOA -> AFR[1] &= ~GPIO_AFRH_AFSEL8_2;
	GPIOA -> AFR[1] &= ~GPIO_AFRH_AFSEL8_3;


	/*
	 * Configuration de la sortie du TIM2 sur GPIO PA0
	*/

	// Alternate function sur PA0
	GPIOA -> MODER &= ~GPIO_MODER_MODE0_0;
	GPIOA -> MODER |= GPIO_MODER_MODE0_1;

	// Choix de la fonction alternative --> TIM2_CH1 sur PA0 --> AF1 --> 0001

	GPIOA -> AFR[0] |= GPIO_AFRL_AFSEL0_0;
	GPIOA -> AFR[0] &= ~GPIO_AFRL_AFSEL0_1;
	GPIOA -> AFR[0] &= ~GPIO_AFRL_AFSEL0_2;
	GPIOA -> AFR[0] &= ~GPIO_AFRL_AFSEL0_3;





}

void delay(uint32_t nb){

	uint32_t i;

	for(i=0; i<nb; i++){}
}

void gpio_config(void){

	//Activation de la clock sur GPIO K
	RCC -> AHB4ENR |= RCC_AHB4ENR_GPIOKEN;

	//Configuration de PK6 en OUPTUT
	GPIOK -> MODER |= GPIO_MODER_MODE6_0;
	GPIOK -> MODER &= ~ GPIO_MODER_MODE6_1;
}

void blink_LED4(void){

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
	GPIOK -> BSRR |= GPIO_BSRR_BS6;
	delay(100000);
	GPIOK -> BSRR |= GPIO_BSRR_BR6;
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
