/* ---------- DEVELOPPEMENT D'UN DRIVER USART ------------------------------- */
/*
   Fichier : USART_driver.c
   Auteur : LOUIS LAGRANGE

   Version 1.0
   Date de création : 08/03/2024
   	   	   	   	   	   	   	   	   	   	   	   	   	   	  	  	  	  	  	  */
/* -------------------------------------------------------------------------- */

#include "USART_driver.h"

void usart_init(const USART_Config_t *config){

	//Déclarations des registres à utiliser
	volatile uint32_t *control_register1 = (volatile uint32_t *)USART_CR1_address;
	volatile uint32_t *control_register2 = (volatile uint32_t *)USART_CR2_address;
	volatile uint32_t *BRR_register = (volatile uint32_t *)USART_BRR_address;




	//Variables de configuration
	// TODO
	//uint32_t usartdiv; //Configuration du registre BRR - MISE EN ATTENTE

	/* Configuration des bits de registres en fonction des configurations données par l'utilisateur */
	/*
	 *  WordLenght
	 *  M[1:0] = ‘00’: 1 start bit, 8 Data bits, n Stop bit
	 *	M[1:0] = ‘01’: 1 start bit, 9 Data bits, n Stop bit
	 *	M[1:0] = ‘10’: 1 start bit, 7 Data bits, n Stop bit
	*/
	if(config->USART_WordLenght == 8){
		*control_register1 &= ~USART_CR1_M1;
		*control_register1 &= ~USART_CR1_M0;
	}
	else if(config->USART_WordLenght == 9){
		*control_register1 &= ~USART_CR1_M1;
		*control_register1 |= USART_CR1_M0;
	}
	else if(config->USART_WordLenght == 7){
		*control_register1 |= USART_CR1_M1;
		*control_register1 &= ~USART_CR1_M0;
	}

	/*
	 *  Nombre de bits de stop
	 *  STOP[1:0] = ‘00’: 1 	Stop bit
	 *	STOP[1:0] = ‘01’: 0.5 	Stop bit
	 *	STOP[1:0] = ‘10’: 2 	Stop bit
	 *	STOP[1:0] = ‘11’: 1.5 	Stop bit
	*/
	switch (config->USART_NoOfStopBits){
		case 1 :
			*control_register2 &= ~USART_CR2_STOP1;
			*control_register2 &= ~USART_CR2_STOP0;
			break;
		case 5 :
			*control_register2 &= ~USART_CR2_STOP1;
			*control_register2 |= USART_CR2_STOP0;
			break;
		case 2 :
			*control_register2 |= USART_CR2_STOP1;
			*control_register2 &= ~USART_CR2_STOP0;
			break;
		case 15 :
			*control_register2 |= USART_CR2_STOP1;
			*control_register2 |= USART_CR2_STOP0;
			break;
	}

	/*
	 *  Mode FIFO
	 *  CR1[31] = ‘0’		RXFIFO OFF
	 *	CR1[31] = ‘1’ 		RXFIFO ON
	 *
	 *  CR1[30] = ‘0’		TXFIFO OFF
	 *	CR1[30] = ‘1’ 		TXFIFO ON
	 *
	 *  CR1[29] = ‘0’		FIFO OFF
	 *	CR1[29] = ‘1’ 		FIFO ON
	*/

	*control_register1 &= ~USART_CR1_RXFFIE; 					// RXFIFO mode OFF
	*control_register1 &= ~USART_CR1_TXFEIE; 					// TXFIFO mode OFF
	*control_register1 &= ~USART_CR1_FIFOEN; 					// FIFO mode OFF


	/*
	 *  OVER SAMPLING by 8
	 *  CR1[15] = 1
	 *
	 *  Configuration du baud rate - BRR Register
	 *  BRR[15:4] = USARTDIV[15:4]
	 *	BRR[3] = CLEAR
	 *	BRR[2:0] = USARTDIV[3:0] 	shifted from one bit to the right (>> 1)
	 *
	 *	Resulat équation : 0d20000 ou 0x4E20 ou 0b0100111000100000
	 *	BRR[15:4] = 0b010011100010
	 *	BRR[3:0] = 0b0000
	*/

	*control_register1 |= USART_CR1_OVER8;						// OVER SAMPLING

	*BRR_register |= 0100111000100000;

	/* TODO
	 * usartdiv = 2 * USART_KER_PRES / config->USART_Baud;		// BRR Register calcul
	*/

	/*
	 *  Enabling USART with UE bit
	 *  CR1[0] = ‘0’		USART prescaler et outputs off low-power mode,
	 *	CR1[0] = ‘1’ 		USART on
	*/

	*control_register1	|= USART_CR1_UE;

	/*
	 *  Envoi d'une idle frame, bit TE CR1, ne doit pas être mis à 1 directement
	 *  CR1[3] = ‘0’		Transmetteur OFF
	 *	CR1[3] = ‘1’ 		Transmetteur ON
	*/

	*control_register1	&= ~USART_CR1_TE;
	*control_register1	|= USART_CR1_TE;


}








