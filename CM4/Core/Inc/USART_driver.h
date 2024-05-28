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
#include <stm32h757xx.h>

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

#define USART_KER_PRES 8000000 //MHz


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
void usart_transmit(char *data);
void rx_data(void);

#endif /* INC_USART_DRIVER_H_ */

