/**
  ******************************************************************************
  * File Name          : main.hpp
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define S2B_Pin GPIO_PIN_2
#define S2B_GPIO_Port GPIOE
#define S1B_Pin GPIO_PIN_3
#define S1B_GPIO_Port GPIOE
#define S3B_Pin GPIO_PIN_4
#define S3B_GPIO_Port GPIOE
#define S4B_Pin GPIO_PIN_5
#define S4B_GPIO_Port GPIOE
#define ADC_CSB_Pin GPIO_PIN_6
#define ADC_CSB_GPIO_Port GPIOE
#define SPI_DIN_Pin GPIO_PIN_0
#define SPI_DIN_GPIO_Port GPIOC
#define SPI_DOUT_Pin GPIO_PIN_1
#define SPI_DOUT_GPIO_Port GPIOC
#define SPI_DCLK_Pin GPIO_PIN_2
#define SPI_DCLK_GPIO_Port GPIOC
#define PH_ORP_CS_Pin GPIO_PIN_3
#define PH_ORP_CS_GPIO_Port GPIOC
#define SW_12V_Pin GPIO_PIN_0
#define SW_12V_GPIO_Port GPIOA
#define PWM_3435_Pin GPIO_PIN_1
#define PWM_3435_GPIO_Port GPIOA
#define BatTest_Pin GPIO_PIN_3
#define BatTest_GPIO_Port GPIOA
#define AD1_Pin GPIO_PIN_6
#define AD1_GPIO_Port GPIOA
#define AD2_Pin GPIO_PIN_7
#define AD2_GPIO_Port GPIOA
#define PWM_Buzzer_Pin GPIO_PIN_1
#define PWM_Buzzer_GPIO_Port GPIOB
#define LED_DIO_Pin GPIO_PIN_8
#define LED_DIO_GPIO_Port GPIOE
#define LED_CLK_Pin GPIO_PIN_9
#define LED_CLK_GPIO_Port GPIOE
#define LED_CS_Pin GPIO_PIN_10
#define LED_CS_GPIO_Port GPIOE
#define PH_LED_Pin GPIO_PIN_11
#define PH_LED_GPIO_Port GPIOE
#define ORP_LED_Pin GPIO_PIN_12
#define ORP_LED_GPIO_Port GPIOE
#define DEEP_LED_Pin GPIO_PIN_13
#define DEEP_LED_GPIO_Port GPIOE
#define COND_LED_Pin GPIO_PIN_14
#define COND_LED_GPIO_Port GPIOE
#define SCL_MS_Pin GPIO_PIN_10
#define SCL_MS_GPIO_Port GPIOB
#define SDA_MS_Pin GPIO_PIN_11
#define SDA_MS_GPIO_Port GPIOB
#define offControl_Pin GPIO_PIN_14
#define offControl_GPIO_Port GPIOB
#define BLE_WAKE_HW_Pin GPIO_PIN_8
#define BLE_WAKE_HW_GPIO_Port GPIOC
#define BLE_WAKE_SW_Pin GPIO_PIN_9
#define BLE_WAKE_SW_GPIO_Port GPIOC
#define BLE_CMD_MLDP_Pin GPIO_PIN_8
#define BLE_CMD_MLDP_GPIO_Port GPIOA
#define rPC10_Pin GPIO_PIN_10
#define rPC10_GPIO_Port GPIOC
#define rPC11_Pin GPIO_PIN_11
#define rPC11_GPIO_Port GPIOC
#define rPC12_Pin GPIO_PIN_12
#define rPC12_GPIO_Port GPIOC
#define rPD0_Pin GPIO_PIN_0
#define rPD0_GPIO_Port GPIOD
#define rPD1_Pin GPIO_PIN_1
#define rPD1_GPIO_Port GPIOD
#define rPD2_Pin GPIO_PIN_2
#define rPD2_GPIO_Port GPIOD
#define rPD3_Pin GPIO_PIN_3
#define rPD3_GPIO_Port GPIOD
#define rPD4_Pin GPIO_PIN_4
#define rPD4_GPIO_Port GPIOD
#define pumpEnable_Pin GPIO_PIN_5
#define pumpEnable_GPIO_Port GPIOD
#define pump_2_Pin GPIO_PIN_6
#define pump_2_GPIO_Port GPIOD
#define pump_1_Pin GPIO_PIN_7
#define pump_1_GPIO_Port GPIOD
#define SCL_Pin GPIO_PIN_6
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOB
#define KEY1_Pin GPIO_PIN_8
#define KEY1_GPIO_Port GPIOB
#define KEY3_Pin GPIO_PIN_9
#define KEY3_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
