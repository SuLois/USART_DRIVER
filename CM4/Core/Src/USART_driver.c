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

	/*
	 *  Activation et choix de la clock sur USART1
	 */
	RCC -> D2CCIP2R |= RCC_D2CCIP2R_USART16SEL_0;
	RCC -> D2CCIP2R |= RCC_D2CCIP2R_USART16SEL_1;
	RCC -> D2CCIP2R &= ~RCC_D2CCIP2R_USART16SEL_2;
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;

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

	// Interruptions
	USART1 -> CR1 &= ~USART_CR1_MME;						// Disable mode Mute
	USART1 -> CR1 |= USART_CR1_RXNEIE;						// Interruption sur RXNE flag
	NVIC_EnableIRQ(USART1_IRQn);


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
	/*
	*  Envoi d'une idle frame, bit TE CR1
	*  CR1[3] = ‘0’		Transmetteur OFF
	*	CR1[3] = ‘1’ 		Transmetteur ON
	*/
	USART1 -> CR1 |= USART_CR1_TE;				// Transmetteur activé
	USART1 -> CR1 |= USART_CR1_RE;

	/*
	*  Enabling USART with UE bit
	*  CR1[0] = ‘0’		USART prescaler et outputs off low-power mode,
	*	CR1[0] = ‘1’ 		USART on
	*/

	USART1 -> CR1 |= USART_CR1_UE;

}


#define USART1_BUFFER_SIZE 100

volatile char data_buffer[USART1_BUFFER_SIZE] = {0};
volatile uint8_t data_index = 0;
volatile uint8_t usart1_ready = 0;


// Transmission des données
void usart_transmit(char *data){


	while(*data != '\0'){
		while(((USART1 -> ISR >> USART_ISR_TXE_TXFNF_Pos) & 0x1) != 1);
		USART1 -> TDR = *data++;
	}
	// Attendre TC (fin transmission)
	while(((USART1 -> ISR >> USART_ISR_TC_Pos) & 0x1) != 1);
}

void USART1_IRQHandler(void) {
    if((USART1->ISR & USART_ISR_RXNE_RXFNE) != 0){
        // Read received data
        char data = (char)USART1 -> RDR;

        if(data_index < USART1_BUFFER_SIZE){
            data_buffer[data_index++] = data;
            if(data == '\n') {
                usart1_ready = 1;
                data_index = 0;
            }
        }
        else{
            data_index = 0;
        }
    }
}

void rx_data(void) {
    if(usart1_ready){
        usart_transmit(data_buffer);
        usart1_ready = 0;
    }
}







