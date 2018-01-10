#ifndef __ad7792_H
#define __ad7792_H

#include "stm32f1xx_hal.h"
#include "main.h"
#include "gpio.h"

#define  CLK_1  HAL_GPIO_WritePin(SPI_DIN_GPIO_Port,SPI_DIN_Pin,GPIO_PIN_RESET)
#define  CLK_0  HAL_GPIO_WritePin(SPI_DIN_GPIO_Port,SPI_DIN_Pin,GPIO_PIN_SET)

#define  MOSI_1  HAL_GPIO_WritePin(SPI_DOUT_GPIO_Port,SPI_DOUT_Pin,GPIO_PIN_RESET)
#define  MOSI_0  HAL_GPIO_WritePin(SPI_DOUT_GPIO_Port,SPI_DOUT_Pin,GPIO_PIN_SET)

#define  AD7792_CS_1  HAL_GPIO_WritePin(ADC_CSB_GPIO_Port,ADC_CSB_Pin,GPIO_PIN_RESET)
#define  AD7792_CS_0  HAL_GPIO_WritePin(ADC_CSB_GPIO_Port,ADC_CSB_Pin,GPIO_PIN_SET)

#define	R0			(100.0)
#define	RTD_A		(3.908E-3)
#define	RTD_B		(-5.8019E-7)
#define	RTD_C		(-4.2735E-12)

#endif
