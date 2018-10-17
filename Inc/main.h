/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOE
#define DEBUG_TX_Pin GPIO_PIN_2
#define DEBUG_TX_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_3
#define DEBUG_RX_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_4
#define KEY1_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_5
#define KEY2_GPIO_Port GPIOA
#define KEY3_Pin GPIO_PIN_6
#define KEY3_GPIO_Port GPIOA
#define KEY4_Pin GPIO_PIN_7
#define KEY4_GPIO_Port GPIOA
#define KEY5_Pin GPIO_PIN_4
#define KEY5_GPIO_Port GPIOC
#define KEY6_Pin GPIO_PIN_5
#define KEY6_GPIO_Port GPIOC
#define KEY7_Pin GPIO_PIN_0
#define KEY7_GPIO_Port GPIOB
#define KEY8_Pin GPIO_PIN_1
#define KEY8_GPIO_Port GPIOB
#define KEY9_Pin GPIO_PIN_7
#define KEY9_GPIO_Port GPIOE
#define KEY10_Pin GPIO_PIN_8
#define KEY10_GPIO_Port GPIOE
#define KEY11_Pin GPIO_PIN_9
#define KEY11_GPIO_Port GPIOE
#define KEY12_Pin GPIO_PIN_10
#define KEY12_GPIO_Port GPIOE
#define KEY13_Pin GPIO_PIN_11
#define KEY13_GPIO_Port GPIOE
#define KEY14_Pin GPIO_PIN_12
#define KEY14_GPIO_Port GPIOE
#define KEY15_Pin GPIO_PIN_13
#define KEY15_GPIO_Port GPIOE
#define KEY16_Pin GPIO_PIN_14
#define KEY16_GPIO_Port GPIOE
#define KEY17_Pin GPIO_PIN_15
#define KEY17_GPIO_Port GPIOE
#define KEY18_Pin GPIO_PIN_10
#define KEY18_GPIO_Port GPIOB
#define KEY19_Pin GPIO_PIN_11
#define KEY19_GPIO_Port GPIOB
#define KEY20_Pin GPIO_PIN_12
#define KEY20_GPIO_Port GPIOB
#define KEY21_Pin GPIO_PIN_13
#define KEY21_GPIO_Port GPIOB
#define KEY22_Pin GPIO_PIN_14
#define KEY22_GPIO_Port GPIOB
#define KEY23_Pin GPIO_PIN_15
#define KEY23_GPIO_Port GPIOB
#define KEY24_Pin GPIO_PIN_8
#define KEY24_GPIO_Port GPIOD
#define LED_Pin GPIO_PIN_9
#define LED_GPIO_Port GPIOD
#define IIC_SDA_Pin GPIO_PIN_15
#define IIC_SDA_GPIO_Port GPIOD
#define IIC_SCL_Pin GPIO_PIN_6
#define IIC_SCL_GPIO_Port GPIOC
#define RS232_TX_Pin GPIO_PIN_9
#define RS232_TX_GPIO_Port GPIOA
#define RS232_RX_Pin GPIO_PIN_10
#define RS232_RX_GPIO_Port GPIOA
#define LED24_Pin GPIO_PIN_15
#define LED24_GPIO_Port GPIOA
#define LED23_Pin GPIO_PIN_10
#define LED23_GPIO_Port GPIOC
#define LED22_Pin GPIO_PIN_11
#define LED22_GPIO_Port GPIOC
#define LED21_Pin GPIO_PIN_12
#define LED21_GPIO_Port GPIOC
#define LED20_Pin GPIO_PIN_0
#define LED20_GPIO_Port GPIOD
#define LED19_Pin GPIO_PIN_1
#define LED19_GPIO_Port GPIOD
#define LED18_Pin GPIO_PIN_2
#define LED18_GPIO_Port GPIOD
#define LED17_Pin GPIO_PIN_3
#define LED17_GPIO_Port GPIOD
#define LED16_Pin GPIO_PIN_4
#define LED16_GPIO_Port GPIOD
#define LED15_Pin GPIO_PIN_5
#define LED15_GPIO_Port GPIOD
#define LED14_Pin GPIO_PIN_6
#define LED14_GPIO_Port GPIOD
#define LED13_Pin GPIO_PIN_7
#define LED13_GPIO_Port GPIOD
#define LED12_Pin GPIO_PIN_3
#define LED12_GPIO_Port GPIOB
#define LED11_Pin GPIO_PIN_4
#define LED11_GPIO_Port GPIOB
#define LED10_Pin GPIO_PIN_5
#define LED10_GPIO_Port GPIOB
#define LED9_Pin GPIO_PIN_6
#define LED9_GPIO_Port GPIOB
#define LED8_Pin GPIO_PIN_7
#define LED8_GPIO_Port GPIOB
#define LED7_Pin GPIO_PIN_8
#define LED7_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_9
#define LED6_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_0
#define LED5_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_1
#define LED4_GPIO_Port GPIOE

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
#define PORT_KEY(x)   KEY##x##_GPIO_Port
#define PIN_KEY(x)    KEY##x##_Pin

#define PORT_LED(x)   LED##x##_GPIO_Port
#define PIN_LED(x)    LED##x##_Pin

#define KEY_COUNT     23

#define PLAY_VIDEO_COMPELETED       1
#define PLAY_VIDEO_ING              0

#define PLAY_VOIDEO_OUTTIME         600  /*超时时间单位:s*/

extern unsigned char play_video_end_flag;
extern unsigned short int play_video_outtimer;
/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
