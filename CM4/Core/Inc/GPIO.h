/*
 * GPIO.h
 *
 *  Created on: Mar 28, 2024
 *      Author: louis
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stm32h757xx.h>

void gpio_check_freq();
void gpio_config();
void blink_LED4();
void usart_gpio(void);

#endif /* INC_GPIO_H_ */
