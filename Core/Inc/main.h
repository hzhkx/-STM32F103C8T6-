/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FM_Pin GPIO_PIN_13
#define FM_GPIO_Port GPIOC
#define hm4_Pin GPIO_PIN_0
#define hm4_GPIO_Port GPIOA
#define hm3_Pin GPIO_PIN_1
#define hm3_GPIO_Port GPIOA
#define temperature1_Pin GPIO_PIN_4
#define temperature1_GPIO_Port GPIOA
#define temperature2_Pin GPIO_PIN_5
#define temperature2_GPIO_Port GPIOA
#define hm1_Pin GPIO_PIN_6
#define hm1_GPIO_Port GPIOA
#define hm2_Pin GPIO_PIN_7
#define hm2_GPIO_Port GPIOA
#define CP_Pin GPIO_PIN_0
#define CP_GPIO_Port GPIOB
#define duoji1_Pin GPIO_PIN_1
#define duoji1_GPIO_Port GPIOB
#define duoji2_Pin GPIO_PIN_10
#define duoji2_GPIO_Port GPIOB
#define duoji3_Pin GPIO_PIN_11
#define duoji3_GPIO_Port GPIOB
#define IN2_Pin GPIO_PIN_12
#define IN2_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_13
#define IN1_GPIO_Port GPIOB
#define IN4_Pin GPIO_PIN_14
#define IN4_GPIO_Port GPIOB
#define IN3_Pin GPIO_PIN_15
#define IN3_GPIO_Port GPIOB
#define ENB_Pin GPIO_PIN_8
#define ENB_GPIO_Port GPIOA
#define ENA_Pin GPIO_PIN_9
#define ENA_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
