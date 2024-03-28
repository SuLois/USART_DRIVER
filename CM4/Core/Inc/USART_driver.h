/* ---------- DEVELOPPEMENT D'UN DRIVER USART ------------------------------- */
/*
   Fichier : USART_driver.h
   Auteur : LOUIS LAGRANGE

   Version 1.0
   Date de création : 08/03/2024
   	   	   	   	   	   	   	   	   	   	   	   	   	   	  	  	  	  	  	  */
/* -------------------------------------------------------------------------- */
#ifndef INC_USART_DRIVER_H_
#define INC_USART_DRIVER_H_


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/*----------------------------------------------------------------------------*/
/*
 * API de contrôle : ponts entre le hardware et software
 * - Clock du periphérique
 * - Contrôle du periphérique
 * - Contrôle des flags
 * - Clear des flags
 * - Configuration des interruptions
 * - Management des priorités des interruptions
*/

//void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t En0rDi);

/* Fréquence CLOCK USART -----------------------------------------------------*/

#define USART_KER_PRES 96000000 //MHz

/*----------------------------------------------------------------------------*/
/*
 * CONFIGURATION DES REGISTRES
*/

/*
 ***************** Control Register 1 - USART_CR1 *****************
*/
#define USART_CR1_address 0x040011000

#define USART_CR1_RXFFIE_Pos  		31
#define USART_CR1_RXFFIE_Msk  		(1 << USART_CR1_RXFFIE_Pos);
#define USART_CR1_RXFFIE 	  		USART_CR1_RXFFIE_Msk			// RXFIFO full interrupt ON

#define USART_CR1_TXFEIE_Pos  		30
#define USART_CR1_TXFEIE_Msk  		(1 << USART_CR1_TXFEIE_Pos);
#define USART_CR1_TXFEIE 	  		USART_CR1_TXFEIE_Msk			// TXFIFO empty interrupt ON

#define USART_CR1_FIFOEN_Pos  		15
#define USART_CR1_FIFOEN_Msk  		(0x1UL << USART_CR1_FIFOEN_Pos);
#define USART_CR1_FIFOEN 	  		USART_CR1_FIFOEN_Msk			// FIFO mode enabled

#define USART_CR1_M1_Pos  			28							// Position du bit M1 dans le registre USART_CR1
#define USART_CR1_M1_Msk  			(1 << USART_CR1_M1_Pos); 	// Masque pour modification unique du bit M1, position dans le premier Octet (poids fort) 0x00010000
#define USART_CR1_M1 	  			USART_CR1_M1_Msk				// Word Length bit 1

#define USART_CR1_M0_Pos  			12
#define USART_CR1_M0_Msk  			(1 << USART_CR1_M0_Pos);
#define USART_CR1_M0 	  			USART_CR1_M0_Msk				// Word Length bit 0

#define USART_CR1_UE_Pos  			0U
#define USART_CR1_UE_Msk  			(1 << USART_CR1_UE_Pos);
#define USART_CR1_UE 	  			USART_CR1_UE_Msk				// USART enable

#define USART_CR1_TE_Pos  			3U
#define USART_CR1_TE_Msk  			(1 << USART_CR1_TE_Pos);
#define USART_CR1_TE 	  			USART_CR1_TE_Msk				// Transmitter enable

#define USART_CR1_OVER8_Pos  		15
#define USART_CR1_OVER8_Msk  		(1 << USART_CR1_OVER8_Pos);
#define USART_CR1_OVER8 	  		USART_CR1_OVER8_Msk				// OVERSAMPLING

/*
 ***************** Control Register 2 - USART_CR2 *****************
*/
#define USART_CR2_address 0x040011004

#define USART_CR2_STOP0_Pos  		12
#define USART_CR2_STOP0_Msk  		(1 << USART_CR2_STOP0_Pos);
#define USART_CR2_STOP0 	  		USART_CR2_STOP0_Msk				// stop bit 0

#define USART_CR2_STOP1_Pos  		13
#define USART_CR2_STOP1_Msk  		(1 << USART_CR2_STOP1_Pos);
#define USART_CR2_STOP1 	  		USART_CR2_STOP1_Msk				// stop bit 1

/*
 ***************** Baud Rate Register - USART_BRR *****************
*/
#define USART_BRR_address 0x04001100C

#define USART_BRR_BRR_Pos  			0
#define USART_BRR_BRR_Msk  			(1 << USART_BRR_BRR_Pos);
#define USART_BRR_BRR 	  			USART_BRR_BRR_Msk				// BRR

#define USART_BRR_USARTDIV_Pos  	4
#define USART_BRR_USARTDIV_Msk  	(1 << USART_BRR_USARTDIV_Pos);
#define USART_BRR_USARTDIV 	  		USART_BRR_USARTDIV_Msk				// USARTDIV

/*
 ***************** Transmit Data Register - USART_TDR *************
*/

#define USART_TDR_address 0x040011028

#define USART_TDR_Pos               0
#define USART_TDR_Msk               (1 << USART_TDR_Pos)
#define USART_TDR                   USART_TDR_Msk                    // !< TDR[8:0] bits (Transmit Data value)






/*
 * Structure de données nécessaire à la configuration de la lisaison série
 * Utilisation pour tous les périphériques USARTx
 *
 *
*/
typedef struct // alignement des variables en mémoire (modulo 32)
{
	uint32_t USART_Baud;
	uint8_t USART_Mode;
	uint8_t USART_NoOfStopBits;
	uint8_t USART_WordLenght;
	uint8_t USART_ParityControl;
	uint8_t USART_HWFlowControl;
}USART_Config_t;

void usart_init(const USART_Config_t *config);

#endif /* INC_USART_DRIVER_H_ */

