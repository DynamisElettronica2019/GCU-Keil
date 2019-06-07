/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "can.h"
#include "dma.h"
//#include "gfxsimulator.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/*Includere il codice generato.
	La chiamata delle funzioni step va fatta in can.c, tim.c, usart.c e adc.c dove indicato dai commenti*/
#include "GCU_Model_genCode.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern uint8_t rxData[];
uint8_t tempMsg[UART_SENT_DATA_WIDTH + 4];
uint8_t tempEepromUartMsg[UART_SENT_EEPROM_DATA_WIDTH+3];
uint8_t tempEepromMsg[I2C_SENT_EEPROM_DATA_WIDTH];
extern uint32_t adc_buffer[];
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
	
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_CAN2_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_UART4_Init();
  MX_TIM6_Init();
  MX_TIM5_Init();
  //MX_GFXSIMULATOR_Init();
  /* USER CODE BEGIN 2 */
	/*
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_UART_Receive_IT(&huart3, rxData, 1);
	HAL_ADC_Start_DMA(&hadc1, rtU.adc_buffer, ADC_DATA_SIZE);
	*/
	/*
	HAL_GPIO_WritePin(LED_1_GIALLO_GPIO_Port, LED_1_GIALLO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_2_GIALLO_GPIO_Port, LED_2_GIALLO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_3_GIALLO_GPIO_Port, LED_3_GIALLO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_4_GIALLO_GPIO_Port, LED_4_GIALLO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_5_ROSSO_GPIO_Port, LED_5_ROSSO_Pin, GPIO_PIN_SET);
	*/
	/*Qui bisogna inserire la funzione che inizializza il modello,
	lo step per l'interpretazione del messaggio (per entrare nel primo stato della macchina a stati
	ed essere pronto a ricevere) e va selezionata su rtU.SelectMode la periferica da cui leggere i messaggi*/
	GCU_Model_genCode_initialize();	
	rtU.SelectMode = CAN_READ_MODE;
	GCU_Model_genCode_step2();
	GCU_Model_genCode_step6();
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		//HAL_GPIO_TogglePin(EFI_COM_1_GPIO_Port,EFI_COM_1_Pin);
		/*uint8_T map=0;
		Efi_setMap_Outputs_wrapper(&map);
		//HAL_GPIO_TogglePin(EFI_MAP_GPIO_Port,EFI_MAP_Pin);
		//HAL_GPIO_TogglePin(EFI_COM_3_GPIO_Port,EFI_COM_3_Pin);
		//HAL_GPIO_TogglePin(EFI_COM_4_GPIO_Port,EFI_COM_4_Pin);
		HAL_Delay(500);
		map = 1;
		Efi_setMap_Outputs_wrapper(&map);
		HAL_Delay(500);*/
    /* USER CODE BEGIN 3 */
		//CAN1_Send_Nucleo_F7_Packet();
		//HAL_Delay(500);
		if(rtU.SelectMode == DEMO_READ_MODE)
		{
			GCU_Model_genCode_step2();
			HAL_Delay(100);
		}
		

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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_UART4|RCC_PERIPHCLK_I2C1;
  PeriphClkInitStruct.Uart4ClockSelection = RCC_UART4CLKSOURCE_PCLK1;
  PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
