//**************************************************************************
//
// IoDefs.h
//
// This file defines the GPIO.
//
//***************************************************************************

#ifndef IO_DEFS_H_
#define IO_DEFS_H_

enum eGPIO_STATE
{
    GPIO_LOW    = 0,
    GPIO_HIGH   = 1
};

#define BUTTON_ON                               (GPIO_LOW)
#define BUTTON_OFF                              (GPIO_HIGH)

// I2C interfaces pin configuration
#define I2C_SDA_PORT                            GPIOA
#define I2C_SDA_PIN                             GPIO_PIN_10

#define I2C_SCL_PORT                            GPIOB
#define I2C_SCL_PIN                             GPIO_PIN_8

// BTN1 click, spec name: SW1
#define GPIO_FRONT_BTN_SW1_PORT                 GPIOA
#define GPIO_FRONT_BTN_SW1_PIN                  GPIO_PIN_2

// BTN2 click, spec name: SW2
#define GPIO_FRONT_BTN_SW2_PORT                 GPIOC
#define GPIO_FRONT_BTN_SW2_PIN                  GPIO_PIN_5

// SPI MISO interfaces pin configuration
#define GPIO_T7_SPI_MISO_PORT                   GPIOC
#define GPIO_T7_SPI_MISO_PIN                    GPIO_PIN_2

// SPI MOSI interfaces pin configuration
#define GPIO_T7_SPI_MOSI_PORT                   GPIOC
#define GPIO_T7_SPI_MOSI_PIN                    GPIO_PIN_3

// SPI CS interfaces pin configuration
#define GPIO_T7_SPI_CS_PORT                     GPIOB
#define GPIO_T7_SPI_CS_PIN                      GPIO_PIN_9

// SPI CLK interfaces pin configuration
#define GPIO_T7_SPI_CLK_PORT                    GPIOB
#define GPIO_T7_SPI_CLK_PIN                     GPIO_PIN_13

#endif /* IO_DEFS_H_ */
