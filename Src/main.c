
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "pca9557.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
unsigned char play_video_end_flag = PLAY_VIDEO_COMPELETED;
unsigned char play_video_last_end_flag = PLAY_VIDEO_COMPELETED;
unsigned short int play_video_outtimer = PLAY_VOIDEO_OUTTIME;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
typedef struct
{
	GPIO_TypeDef * Port;
	uint16_t Pin;
}control_gpio_t;

uint8_t key_led_pos[] = {
		 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,
		13,14,15,16,17,18,19,20,21,22,23,12,
};
control_gpio_t KEY_Gpio[] = {
	{PORT_KEY(12), PIN_KEY(12)},
	{PORT_KEY(11), PIN_KEY(11)},
	{PORT_KEY(10), PIN_KEY(10)},
	{PORT_KEY(9), PIN_KEY(9)},
	{PORT_KEY(8), PIN_KEY(8)},
	{PORT_KEY(7), PIN_KEY(7)},
	{PORT_KEY(6), PIN_KEY(6)},
	{PORT_KEY(5), PIN_KEY(5)},
	{PORT_KEY(4), PIN_KEY(4)},
	{PORT_KEY(3),PIN_KEY(3)},
	{PORT_KEY(2),PIN_KEY(2)},
	{PORT_KEY(1),PIN_KEY(1)},
	{PORT_KEY(23),PIN_KEY(23)},
	{PORT_KEY(22),PIN_KEY(22)},
	{PORT_KEY(21),PIN_KEY(21)},
	{PORT_KEY(20),PIN_KEY(20)},
	{PORT_KEY(19),PIN_KEY(19)},
	{PORT_KEY(18),PIN_KEY(18)},
	{PORT_KEY(17),PIN_KEY(17)},
	{PORT_KEY(16),PIN_KEY(16)},
	{PORT_KEY(15),PIN_KEY(15)},
	{PORT_KEY(14),PIN_KEY(14)},
	{PORT_KEY(13),PIN_KEY(13)},
	{PORT_KEY(24),PIN_KEY(24)}
};


control_gpio_t LED_Gpio[] = {
	{PORT_LED(1), PIN_LED(1)}, 
	{PORT_LED(2), PIN_LED(2)},
	{PORT_LED(3), PIN_LED(3)},
	{PORT_LED(4), PIN_LED(4)},
	{PORT_LED(5), PIN_LED(5)},
	{PORT_LED(6), PIN_LED(6)},
	{PORT_LED(7), PIN_LED(7)},
	{PORT_LED(8), PIN_LED(8)},
	{PORT_LED(9), PIN_LED(9)},
	{PORT_LED(10),PIN_LED(10)},
	{PORT_LED(11),PIN_LED(11)},
	{PORT_LED(12),PIN_LED(12)},
	{PORT_LED(14),PIN_LED(14)},
	{PORT_LED(15),PIN_LED(15)},
	{PORT_LED(16),PIN_LED(16)},
	{PORT_LED(17),PIN_LED(17)},
	{PORT_LED(18),PIN_LED(18)},
	{PORT_LED(19),PIN_LED(19)},
	{PORT_LED(20),PIN_LED(20)},
	{PORT_LED(21),PIN_LED(21)},
	{PORT_LED(22),PIN_LED(22)},
	{PORT_LED(23),PIN_LED(23)},
	{PORT_LED(24),PIN_LED(24)},
	{PORT_LED(13),PIN_LED(13)}
};

uint8_t uart_print[] = {
	'a','b','c','d','e','f','g','h','i','j',
	'k','l','m','n','o','p','q','r','s','t',
	'u','v','w','x','y','z'
};
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t i;
  uint8_t cur_key = 0;
  uint8_t last_key = 0;
  uint32_t last_tick = 0;
  uint8_t pulse = 0;
	uint8_t test = 0;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim7);
  PCA9557_Init();
  UART_Receive_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
		if (play_video_end_flag == PLAY_VIDEO_COMPELETED)
		{
			for (cur_key = 0;cur_key < KEY_COUNT;cur_key++)
			{
				if (HAL_GPIO_ReadPin(KEY_Gpio[cur_key].Port,KEY_Gpio[cur_key].Pin) == GPIO_PIN_RESET)
				{
					break;
				}
			}
			if (last_key != cur_key)
			{
				last_key = cur_key;
				last_tick = HAL_GetTick();
			}
			else
			{
				if (HAL_GetTick() > (last_tick + 10))
				{
					if (cur_key < KEY_COUNT)
					{
						if (pulse == 0)
						{
							//打开建筑灯
							HAL_GPIO_WritePin(LED_Gpio[cur_key].Port,LED_Gpio[cur_key].Pin,GPIO_PIN_SET);
							//打开按键灯
							key_led.gpio = (uint32_t )(1 << key_led_pos[cur_key]);
							PCA9557_WRITE(key_led);
							HAL_UART_Transmit(&huart1,&uart_print[cur_key],1,HAL_MAX_DELAY);
							play_video_end_flag = PLAY_VIDEO_ING;
							play_video_outtimer = 0;
							pulse = 1;
						}
					}
					else
					{
						pulse = 0;
					}
				}
			}
		}
		if (play_video_last_end_flag != play_video_end_flag)
		{
			if (play_video_last_end_flag == PLAY_VIDEO_ING)
			{
				//关闭建筑灯
				for ( i = 0 ; i < KEY_COUNT; i++)
					HAL_GPIO_WritePin(LED_Gpio[i].Port,LED_Gpio[i].Pin,GPIO_PIN_RESET);
				//关闭按键灯
				key_led.gpio = 0;
				PCA9557_WRITE(key_led);
			}
			play_video_last_end_flag = play_video_end_flag;
		}
		
//		for (cur_key = 0;cur_key < KEY_COUNT;cur_key++)
//		{
//			if (HAL_GPIO_ReadPin(KEY_Gpio[cur_key].Port,KEY_Gpio[cur_key].Pin) == GPIO_PIN_RESET)
//			{
//				break;
//			}
//		}
//		if (last_key != cur_key)
//		{
//			last_key = cur_key;
//			last_tick = HAL_GetTick();
//		}
//		else
//		{
//			if (HAL_GetTick() > (last_tick + 10))
//			{
//				if (cur_key < KEY_COUNT)
//				{
//					if (pulse == 0)
//					{
//						//打开建筑灯
//						HAL_GPIO_WritePin(LED_Gpio[cur_key].Port,LED_Gpio[cur_key].Pin,GPIO_PIN_SET);
//						//打开按键灯
//						key_led.gpio = (uint32_t )(1 << key_led_pos[cur_key]);
//						PCA9557_WRITE(key_led);
//						HAL_UART_Transmit(&huart1,&uart_print[cur_key],1,HAL_MAX_DELAY);
//						pulse = 1;
//					}
//				}
//				else
//				{
//					pulse = 0;//				
//					//关闭建筑灯
//					for ( i = 0 ; i < KEY_COUNT; i++)
//						HAL_GPIO_WritePin(LED_Gpio[i].Port,LED_Gpio[i].Pin,GPIO_PIN_RESET);
//					//关闭按键灯
//					key_led.gpio = 0;
//					PCA9557_WRITE(key_led);
//				}
//			}
//		}
  }
  
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
