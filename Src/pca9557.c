#include "main.h"
#include "pca9557.h"
#include <stdint.h>
PCA9557_GPIO_t key_led;

static void DelayUs(uint16_t us)
{
    uint8_t i = 0;
	for(;us>0;us--)
        for(i=0;i<100;i++);
}


static void DelayMs_IIS(uint16_t ms)
{
    
    for(; ms>0; ms--)
    {
        DelayUs(1000);
    }
}

void Start(void) 
{ 
	IIC_SDA_OUT();
	/* Prepare the bus */
	IIC_SDA_HIGH();
	IIC_SCK_HIGH();
	DelayUs(5); 
	/* Generate the START condition */
	IIC_SDA_LOW();
	DelayUs(5); 
	IIC_SCK_LOW();
} 

void Stop(void) 
{
	IIC_SDA_OUT();
	IIC_SDA_LOW();
	DelayUs(5);
	IIC_SCK_HIGH();
	DelayUs(5);
	IIC_SDA_HIGH();
	DelayUs(5);                        
} 


void Ack(void) 
{   
	IIC_SDA_OUT();
	IIC_SDA_HIGH();
	IIC_SCK_HIGH(); 
	DelayUs(5); 
	IIC_SCK_LOW();
	DelayUs(5);   
} 


void   NoAck(void) 
{
  IIC_SDA_HIGH();  
  DelayUs(5);
  IIC_SCK_HIGH(); 
  DelayUs(5);
  IIC_SCK_LOW(); 
  DelayUs(5);    
} 


uint8_t RecAck(void)
{
	unsigned char ack;
	IIC_SDA_IN();
	IIC_SCK_HIGH();
	DelayUs(5); 
	ack = IIC_SDA_GET();
	IIC_SCK_LOW();
	DelayUs(5); 
	
    return(ack);  
}

void WriteI2C(uint8_t   date) 
{ 
	unsigned char i;
	IIC_SDA_OUT();
	DelayUs(5); 
	/* Sending data one bit at a time (MS bit first)  */
	for (i=0; i<8; i++)
	{
		if(date & 0x80)
		{
			IIC_SDA_HIGH();
		}
		else
		{
			IIC_SDA_LOW();
		}
		/* Prepare to send next bit */
		date <<= 1;    
		
		DelayUs(1); 
		/* Generate a clock cycle */
		IIC_SCK_HIGH();
		DelayUs(5); 
		IIC_SCK_LOW();
		DelayUs(5); 
	}
	
	/* Make sure the slave acknowledges */
	RecAck();
} 


uint8_t ReadI2C(void) 
{ 
  uint8_t   byte=0;
	unsigned char i;
	
	IIC_SDA_IN();
	for (i=0; i<8; i++)
	{
		/* Shift left the result */
		byte <<= 1;
		IIC_SCK_HIGH();
		DelayUs(5); 
		/* Set actual SDA state to LSB */
		byte |= IIC_SDA_GET();
		IIC_SCK_LOW();
		DelayUs(5);
	}
  return(byte);
} 

void WriteByte(uint8_t dev_addr,uint8_t startAddress,uint8_t datum) 
{
	Start();
	WriteI2C(dev_addr << 1);
	WriteI2C(startAddress);
	WriteI2C(datum); 
	Stop();
	DelayMs_IIS(5);				     //sent the stop
} 
void PCA9557_Init(void)
{
	WriteByte(PCA9557_KEY_LED_U5_ADDRESS,PCA9557_POLARITY_INVERSION_REGISTER,0x00);
	WriteByte(PCA9557_KEY_LED_U4_ADDRESS,PCA9557_POLARITY_INVERSION_REGISTER,0x00);
	WriteByte(PCA9557_KEY_LED_U3_ADDRESS,PCA9557_POLARITY_INVERSION_REGISTER,0x00);
	//ÉèÖÃpcaÎªÊä³ö
	WriteByte(PCA9557_KEY_LED_U5_ADDRESS,PCA9557_CONFIGURATION_REGISTER,0x00);
	WriteByte(PCA9557_KEY_LED_U4_ADDRESS,PCA9557_CONFIGURATION_REGISTER,0x00);
	WriteByte(PCA9557_KEY_LED_U3_ADDRESS,PCA9557_CONFIGURATION_REGISTER,0x00);
}

void PCA9557_WRITE(PCA9557_GPIO_t key_gpio)
{
	WriteByte(PCA9557_KEY_LED_U5_ADDRESS,PCA9557_OUTPUT_PORT_REGISTER,key_gpio.buf[0]);
	WriteByte(PCA9557_KEY_LED_U4_ADDRESS,PCA9557_OUTPUT_PORT_REGISTER,key_gpio.buf[1]);
	WriteByte(PCA9557_KEY_LED_U3_ADDRESS,PCA9557_OUTPUT_PORT_REGISTER,key_gpio.buf[2]);
}

