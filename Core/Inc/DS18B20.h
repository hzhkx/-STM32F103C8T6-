#include "stm32f1xx_hal.h"
#include "main.h"
#define  DS18B20_DQ_OUT_HIGH       HAL_GPIO_WritePin(hm2_GPIO_Port, hm2_Pin, GPIO_PIN_SET)
#define  DS18B20_DQ_OUT_LOW        HAL_GPIO_WritePin(hm2_GPIO_Port, hm2_Pin, GPIO_PIN_RESET)
#define  DS18B20_DQ_IN             HAL_GPIO_ReadPin(hm2_GPIO_Port, hm2_Pin)
