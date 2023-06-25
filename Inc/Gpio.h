//**************************************************************************
//
// GPIO.h
//
// This file defines the GPIOs.
//
//***************************************************************************
#ifndef __GPIO_H__
#define __GPIO_H__

enum EXTERNAL_TRIGGER
{
    EXTERNAL_TRIGGER_I2C_ON  = 0,
    EXTERNAL_TRIGGER_I2C_OFF = 1,
    EXTERNAL_TRIGGER_SPI_ON  = 2,
    EXTERNAL_TRIGGER_SPI_OFF = 3,
    EXTERNAL_MAX_TRIGGER
} ;

enum CPIO_STATE
{
    GPIO_LOW    = 0,
    GPIO_HIGH   = 1
} ;

#define BUTTON_ON                           (GPIO_LOW)
#define BUTTON_OFF                          (GPIO_HIGH)

// I2C interfaces pin configuration
#define I2C_SDA_PORT                            GPIOA
#define I2C_SDA_PIN                             GPIO_PIN_10

#define I2C_SCL_PORT                            GPIOB
#define I2C_SCL_PIN                             GPIO_PIN_8

// click-1, spec name: BARREL_SW1
#define GPIO_BARREL_SW1_PORT                    GPIOA
#define GPIO_BARREL_SW1_PIN                     GPIO_PIN_2

// click-2, spec name: BARREL_SW2
#define GPIO_BARREL_SW2_PORT                    GPIOC
#define GPIO_BARREL_SW2_PIN                     GPIO_PIN_5

// SPI MISO
#define GPIO_T7_SPI_MISO_PORT                   GPIOC
#define GPIO_T7_SPI_MISO_PIN                    GPIO_PIN_2

// SPI MOSI
#define GPIO_T7_SPI_MOSI_PORT                   GPIOC
#define GPIO_T7_SPI_MOSI_PIN                    GPIO_PIN_3

// SPI CS
#define GPIO_T7_SPI_CS_PORT                     GPIOB
#define GPIO_T7_SPI_CS_PIN                      GPIO_PIN_9

// SPI CLK
#define GPIO_T7_SPI_CLK_PORT                    GPIOB
#define GPIO_T7_SPI_CLK_PIN                     GPIO_PIN_13

#endif
