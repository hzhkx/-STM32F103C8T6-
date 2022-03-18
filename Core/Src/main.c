/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stdio.h"
#include "DS18B20.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define user_main_printf(format, ...) printf( format "\r\n", ##__VA_ARGS__)
#define shidu_max 100.00
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t kRxBuffer[100];
uint8_t akRxBuffer = 0;
uint8_t kTxBuffer[]={"Welcome\r\n"};
uint8_t ErrorBuffer[]={"error input\r\n"};
uint8_t test01[] ={'0','1'};
uint32_t sum=0;
uint16_t shidu_value[8] = {0};
float real_shiduvalue =0;
float  inital_shiduvalue =0;
float  conversion_shiduvalue =0;
float temperature;
int Move_Flag =0;
int Duoji_Flag1 = 0;
int Duoji_Flag2 =0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
uint8_t DS18B20_Init(void);
short DS18B20_Get_Temperature(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  MX_DMA_Init();
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	move_enable();
	/*
	ռ�ձ� = t / T ��ز������£�
t = 0.5ms������������-�����ת�� 0 ��
t = 1.0ms������������-�����ת�� 45��
t = 1.5ms������������-�����ת�� 90��
t = 2.0ms������������-�����ת�� 135��
t = 2.5ms������������-�����ת��180��
		TIM_SetCompare1(TIM3, 195);//0��
		delay_ms(100);
		TIM_SetCompare1(TIM3, 190);//45��
		delay_ms(100);
		TIM_SetCompare1(TIM3, 185);//90��
		delay_ms(100);
		TIM_SetCompare1(TIM3, 180);//135��
		delay_ms(100);
		TIM_SetCompare1(TIM3, 175);//180��
	*/
	HAL_UART_Receive_IT(&huart2,(uint8_t*)kRxBuffer,1);
	HAL_Delay(200);
	HAL_UART_Transmit(&huart2,(uint8_t*)kTxBuffer,9,0XFFFF);
//	HAL_UART_Transmit(&huart2,(uint8_t*)test01,9,0XFFFF);
	HAL_Delay(100);	
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)shidu_value, 8);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		if(Duoji_Flag1>=5|Duoji_Flag1<0)
		{
			Duoji_Flag1 =0;
		
		}
		else
	 {
			if(Duoji_Flag1==0)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,5);
				HAL_Delay(100);
			}
			if(Duoji_Flag1==1)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,10);
					HAL_Delay(100);
			}
			if(Duoji_Flag1==2)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,15);
				HAL_Delay(100);
			}
			if(Duoji_Flag1==3)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,20);
				HAL_Delay(100);
			}
			if(Duoji_Flag1==4)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,25);
			HAL_Delay(100);
			}
		}
		if(Duoji_Flag2>=5|Duoji_Flag2<0)
		{
			Duoji_Flag2 =0;
		
		}
		else
	{
			if(Duoji_Flag2==0)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,5);
				HAL_Delay(100);
			}
			if(Duoji_Flag2==1)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,10);
					HAL_Delay(100);
			}
			if(Duoji_Flag2==2)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,15);
				HAL_Delay(100);
			}
			if(Duoji_Flag2==3)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,20);
				HAL_Delay(100);
			}
			if(Duoji_Flag2==4)
			{
				__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_4,25);
			HAL_Delay(100);
			}
		}
		
		
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,350);   //��ʱ��Ԥ��Ƶ 72Mhz/(71+1)/(499+1)=2Khz  Fpwm =Tclk / ((arr+1)*(psc+1))(��λ��Hz)
		__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,350);
		//duty circle = TIM3->CCR1 / arr(��λ��%)
//TIM3->CCR1  �û��趨ֵ ��ʱ��Ƶ��Tclk = 72Mhz  arr=499   psc=71     ��ôPWMƵ�ʾ���720000/500/72=  2000Hz����2KHz

//arr=499,TIM3->CCR1=300     ��pwm��ռ�ձ�Ϊ60%

		if(Move_Flag ==1)
		{
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,200);   //��ʱ��Ԥ��Ƶ 72Mhz/(71+1)/(499+1)=2Khz  Fpwm =Tclk / ((arr+1)*(psc+1))(��λ��Hz)
		  __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,200);
			move_forward();
		}
		if(Move_Flag ==2)
		{
			__HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,200);   //��ʱ��Ԥ��Ƶ 72Mhz/(71+1)/(499+1)=2Khz  Fpwm =Tclk / ((arr+1)*(psc+1))(��λ��Hz)
		  __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,200);
			move_back();
		}
		if(Move_Flag ==3)
		{
			move_left();
			Move_Flag =5;
		}
		if(Move_Flag ==4)
		{
			move_right();
			Move_Flag =5;
		}
		if(Move_Flag ==5)
		{
			move_stop();
		}
		if(Move_Flag ==6)
		
		{
			
			//�ɼ��������ݽ���ƽ�������˲�
			for(uint8_t i =0;i<8;i++)
			{
				sum+=shidu_value[i];
				
			}
			sum/=8;
			//�ɼ���������ת��
			inital_shiduvalue =(float)(sum)/4096*3.3;
			//����У׼
			conversion_shiduvalue=(3.62-inital_shiduvalue)/(3.62-1.81);
			real_shiduvalue =conversion_shiduvalue*100;
			//�����ӡ
			user_main_printf("\n inital humidity  is %lf\r",inital_shiduvalue);
			if(real_shiduvalue>=100)
			{
				user_main_printf("\n inital humidity  is %lf\r",shidu_max);
				
				if(real_shiduvalue>=50) //ʪ�ȴ���50 ����
			 {
				waring();
			 }
			}
			else
			{
				user_main_printf("conversion humidity is %.3lf ",real_shiduvalue);

				if(real_shiduvalue>=50) //ʪ�ȴ���50 ����
			 {
				waring();
			 }
				
			}


			Move_Flag =5;  //�ɼ�ʪ��ʱΪͣ��״̬

		}
		if(Move_Flag ==9)
		{
			DS18B20_Init();

			if(DS18B20_Init()){
			user_main_printf("DS18B20 checked failed!!!\r\n");
			HAL_Delay(500);
			}
			else
			{
			user_main_printf("DS18B20 checked success!!!\r\n");
			temperature = DS18B20_Get_Temperature();
			}
			if(temperature < 0)
			user_main_printf("temperature = -%.2f degree\r\n",temperature/10);
			else
			user_main_printf("temperature = %.2f degree\r\n",temperature/10);
			HAL_Delay(200);
		}

		HAL_Delay(1);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef*huart) 
{
	UNUSED(huart);
	int cnt=0;
	HAL_UART_Transmit(&huart2,(uint8_t*)kRxBuffer,1,0XFFFF);
	akRxBuffer =kRxBuffer[cnt];
	
	if(kRxBuffer[cnt] == 'W') //����move forward
	{
		Move_Flag=1;
	}
	else if(kRxBuffer[cnt] == 'S')// move back
	{
		Move_Flag =2;
	}
	else if(kRxBuffer[cnt] == 'A')//move left
	{
		Move_Flag =3;
	}
	else if(kRxBuffer[cnt] == 'D')//move right
	{
		Move_Flag =4;
	}
	else if(kRxBuffer[cnt] == 'P')//move stop
	{
		Move_Flag =5;
		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3);  //stop ˮ��
		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_4);
	}

	else if(kRxBuffer[cnt] == 'M') //���ܲɼ�ʪ��ָ��
	{
		Move_Flag =6;
	}
	else if(kRxBuffer[cnt] =='F') //����ˮ�ý��� F
	{
		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3); 
		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_4);
		Move_Flag =7;
		HAL_GPIO_WritePin(CP_GPIO_Port,CP_Pin,GPIO_PIN_RESET);  //�򿪼̵���
	}
	else if(kRxBuffer[cnt]== 'N') //ֹͣˮ��
	{

		Move_Flag =8;
		HAL_GPIO_WritePin(CP_GPIO_Port,CP_Pin,GPIO_PIN_SET);  //�رռ̵���
	}
	else if(kRxBuffer[cnt] =='T')
	{
		Move_Flag=9;

	}
	else if(kRxBuffer[cnt] == '8')  //�϶����
	{
		duoji_enable();
		Duoji_Flag1 ++;
	}
	else if(kRxBuffer[cnt] == '2') //�϶����
	{
		duoji_enable();
		Duoji_Flag1 --;
	}
	else if(kRxBuffer[cnt] == '4') //�¶����
	{
		duoji_enable();
		Duoji_Flag2 ++;
	}
	else if(kRxBuffer[cnt] == '6')//�¶����
	{
		duoji_enable();
		Duoji_Flag2 --;
	}

	else //������յ�����ָ�� ���error
	{
		HAL_UART_Transmit(&huart2,(uint8_t*)ErrorBuffer,15,0XFFFF);  
	}
	
		cnt =0;   //������������
		HAL_UART_Receive_IT(&huart2,(uint8_t*)&kRxBuffer,1);  //�������ڽ����ж�
	
}


int fputc(int ch,FILE *f)
{
	uint8_t temp[1] ={ch};
	HAL_UART_Transmit(&huart2,temp,1,0xffff);
	return ch;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
