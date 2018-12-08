#ifndef __PCA9557_H__
#define __PCA9557_H__


#include "gpio.h"


#define KEY_LED(x) KEY_LED##x
#define PCA9557_KEY_LED_U5_ADDRESS         0x1c
#define PCA9557_KEY_LED_U4_ADDRESS         0x1e
#define PCA9557_KEY_LED_U3_ADDRESS         0x1f

#define PCA9557_INPUT_PORT_REGISTER         0x00
#define PCA9557_OUTPUT_PORT_REGISTER        0x01
#define PCA9557_POLARITY_INVERSION_REGISTER 0x02
#define PCA9557_CONFIGURATION_REGISTER      0x03

#define IIC_SCK_OUT()   {IIC_SCL_GPIO_Port->CRL &= ~(0x0f000000);IIC_SCL_GPIO_Port->CRL|=0x07000000;}
#define IIC_SCK_HIGH()  {IIC_SCL_GPIO_Port->BSRR = IIC_SCL_Pin;}
#define IIC_SCK_LOW()   {IIC_SCL_GPIO_Port->BRR = IIC_SCL_Pin;}

#define IIC_SDA_OUT()   {IIC_SDA_GPIO_Port->CRL &= ~(0xf0000000);IIC_SDA_GPIO_Port->CRL|=0x70000000;}
#define IIC_SDA_IN()    {IIC_SDA_GPIO_Port->CRL &= ~(0xf0000000);IIC_SDA_GPIO_Port->CRL|=0x40000000;}
#define IIC_SDA_HIGH()  {IIC_SDA_GPIO_Port->BSRR = IIC_SDA_Pin;}
#define IIC_SDA_LOW()   {IIC_SDA_GPIO_Port->BRR = IIC_SDA_Pin;}
#define IIC_SDA_GET()   ((IIC_SDA_GPIO_Port->IDR & IIC_SDA_Pin) != (uint32_t)GPIO_PIN_RESET)

typedef union
{
	unsigned char buf[4];
	unsigned int gpio;
}PCA9557_GPIO_t;

extern PCA9557_GPIO_t key_led;

void PCA9557_Init(void);
void PCA9557_WRITE(PCA9557_GPIO_t key_gpio);
#endif
