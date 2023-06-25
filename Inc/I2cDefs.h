//**************************************************************************
//
// I2cDefs.h
//
// This file defines the Registers and Structs needed to control I2C communication.
//
//***************************************************************************
#ifndef __I2C_DEFS_H__
#define __I2C_DEFS_H__

#include <stdint.h>

// Definitions
#define I2C_TIMEOUT		    1000
#define I2C_MAX_BUFF_SIZE   64

#define I2C_WRITE_CMD	0
#define I2C_READ_CMD	1
#define I2C_STOP		1
#define I2C_RESTART		1

constexpr unsigned int DELAY_TIME_FOR_BUFFER_PREP = 5000;

// Working Mode
enum class eI2C_MODE
{
	eI2C_MODE_SLAVE,
	eI2C_MODE_MASTER,
};

//I2c Data structure
struct I2cTransfer
{
	uint32_t	Length;
	uint8_t	    Buffer[I2C_MAX_BUFF_SIZE];
};

//********************************************************************
//       I2C Registers map                                 
//********************************************************************
typedef volatile struct I2cRegStruct
{
   	uint32_t    *pDATA;						//I2C Rx/Tx Data Buffer and Command Register					(0x10)
	uint8_t     IC_ENABLE;					//I2C Enable Register
} DW_I2C_REG, *DW_I2C_REG_PTR;
#endif //__I2C_DEFS_H__