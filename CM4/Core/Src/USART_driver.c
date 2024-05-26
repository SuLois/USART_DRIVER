/* ---------- DEVELOPPEMENT D'UN DRIVER USART ------------------------------- */
/*
   Fichier : USART_driver.c
   Auteur : LOUIS LAGRANGE

   Version 1.0
   Date de création : 08/03/2024
   	   	   	   	   	   	   	   	   	   	   	   	   	   	  	  	  	  	  	  */
/* -------------------------------------------------------------------------- */

#include "USART_driver.h"
#include "string.h"

void usart_init(const USART_Config_t *config){

	// Configuration des pins associées
	usart_gpio();

	NVIC_EnableIRQ(USART1_IRQn);

	/*
	 *  Activation et choix de la clock sur USART1
	 */
	RCC -> D2CCIP2R |= RCC_D2CCIP2R_USART16SEL_0;
	RCC -> D2CCIP2R |= RCC_D2CCIP2R_USART16SEL_1;
	RCC -> D2CCIP2R &= ~RCC_D2CCIP2R_USART16SEL_2;
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;

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
		USART1 -> CR1 &= ~USART_CR1_M1;
		USART1 -> CR1 &= ~USART_CR1_M0;
	}
	else if(config->USART_WordLenght == 9){
		USART1 -> CR1 &= ~USART_CR1_M1;
		USART1 -> CR1 |= USART_CR1_M0;
	}
	else if(config->USART_WordLenght == 7){
		USART1 -> CR1 |= USART_CR1_M1;
		USART1 -> CR1 &= ~USART_CR1_M0;
	}

	/*
	 *  OVER SAMPLING by 8
	 *  CR1[15] = 1
	 *
	 *  Configuration du baud rate - BRR Register
	 *  BRR[15:4] = USARTDIV[15:4]
	 *	BRR[3] = CLEAR
	 *	BRR[2:0] = USARTDIV[3:0] 	shifted from one bit to the right (>> 1)
	 *
	 *	Resulat équation : 0d1667 ou 0x683
	 *	BRR[15:4] = 0b00000011010000011
	 *	BRR[3:0] = 0b0001
	*/

	USART1 -> CR1 |= USART_CR1_OVER8;						// OVER SAMPLING
	USART1 -> CR1 &= ~USART_CR1_MME;						// Disable mode Mute


	USART1 -> BRR &= ~(USART_BRR_DIV_FRACTION_Msk | USART_BRR_DIV_MANTISSA_Msk);		// Configuration BRR 9600 bauds
	USART1 -> BRR |= (0b0001 << USART_BRR_DIV_FRACTION_Pos);
	USART1 -> BRR |= (0b000001101000 << USART_BRR_DIV_MANTISSA_Pos);

	/*
	 *  Nombre de bits de stop
	 *  STOP[1:0] = ‘00’: 1 	Stop bit
	 *	STOP[1:0] = ‘01’: 0.5 	Stop bit
	 *	STOP[1:0] = ‘10’: 2 	Stop bit
	 *	STOP[1:0] = ‘11’: 1.5 	Stop bit
	*/
	switch (config->USART_NoOfStopBits){
		case 1 :
			USART1 -> CR2 &= ~USART_CR2_STOP_1;
			USART1 -> CR2 &= ~USART_CR2_STOP_0;
			break;
		case 5 :
			USART1 -> CR2 &= ~USART_CR2_STOP_1;
			USART1 -> CR2 |= USART_CR2_STOP_0;

			break;
		case 2 :
			USART1 -> CR2 |= USART_CR2_STOP_1;
			USART1 -> CR2 &= ~USART_CR2_STOP_0;
			break;
		case 15 :
			USART1 -> CR2 |= USART_CR2_STOP_1;
			USART1 -> CR2 |= USART_CR2_STOP_0;
			break;
	}


	/* TODO
	 * usartdiv = 2 * USART_KER_PRES / config->USART_Baud;		// BRR Register calcul
	*/

	USART1 -> CR1 |= USART_CR1_RE;
	//USART1 -> CR1 |= USART_CR1_TE;

	/*
		 *  Enabling USART with UE bit
		 *  CR1[0] = ‘0’		USART prescaler et outputs off low-power mode,
		 *	CR1[0] = ‘1’ 		USART on
		*/

	USART1 -> CR1 |= USART_CR1_UE;

}

// Transmission des données
void usart_transmit(char *data){
	/*
	 *  Envoi d'une idle frame, bit TE CR1
	 *  CR1[3] = ‘0’		Transmetteur OFF
	 *	CR1[3] = ‘1’ 		Transmetteur ON
	*/
	USART1 -> CR1 |= USART_CR1_TE;				// Transmetteur activé


/*
	for(int i = 0; i < strlen(data); i++){
		// Attendre flag TXE à 1 avant remplissage TDR
		while(((USART1 -> ISR >> USART_ISR_TXE_TXFNF_Pos) & 0x1) != 1);
		// Remplissage registre TDR
		USART1 -> TDR |= data[i];
	}
*/
	while(*data != '\0'){
		while(((USART1 -> ISR >> USART_ISR_TXE_TXFNF_Pos) & 0x1) != 1);
		USART1 -> TDR = *data;
		data++;
	}
	// Attendre TC (fin transmission)
	while(((USART1 -> ISR >> USART_ISR_TC_Pos) & 0x1) != 1);

	//USART1 -> ICR |= USART_ICR_TCCF;			// Clear TC flag
	USART1 -> CR1 &= ~USART_CR1_TE;				// Transmetteur OFF

}


void USART1_IRQHandler(void){

	char data_r;

	// Attendre flag RXNE à 1 avant lecture TDR
	if(((USART1 -> ISR >> USART_ISR_RXNE_RXFNE) & 0x1) == 1){

		data_r = (USART1 -> RDR);					// Lecture RDR
		GPIOK -> ODR ^= GPIO_ODR_OD6;		// Inverse l'état de la LED
	}
}







