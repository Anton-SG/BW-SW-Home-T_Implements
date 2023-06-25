//**************************************************************************
//
// I2cDriver.h
//
// This file defines the functions and data needed to control I2C communication.
//
//***************************************************************************
#pragma once
#include "I2cDefs.h"

//=========================================================================================
class I2C
{
public:

	/********************************************************************
	*@method		: Instance
	*@Description	: Get Instance
	*@Inputs		: None
	*@Outputs		: None
	*@Returns		: I2C - this
	********************************************************************/
	static I2C* Instance() { return &mObjInstance; }

	/********************************************************************
	*@Method		: Init
	*@Description	: Initialize the I2C class
	*@Inputs		: aSpeed - I2C Speed needed - 0x1 (STANDARD): Standard Speed mode of operation, 0x2 (FAST): Fast or Fast Plus mode of operation , 0x3 (HIGH): High Speed mode of operation
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	void Init(uint8_t aSpeed);

	/********************************************************************
	*@Method		: I2cMasterWrite
	*@Description	: Master Write transsmition
	*@Inputs		: apTransfer -I2C transfer struct
	*@Outputs		: None
	*@Returns		: uint32_t - length of data that actually been read [unit: bytes]
	********************************************************************/
	uint32_t I2cMasterWrite(I2cTransfer apTransfer);

	/********************************************************************
	*@Method		: I2cMasterRead
	*@Description	: Master Read transsmition
	*@Inputs		: arTransfer -I2C transfer struct
	*@Outputs		: None
	*@Returns		: uint32_t - length of data that actually been read [unit: bytes]
	********************************************************************/
	void I2cMasterRead(I2cTransfer& arTransfer);

	/********************************************************************
	*@Method		: I2cDisable
	*@Description	: Disable I2c
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void I2cDisable();

	/********************************************************************
	*@Method		: I2cEnable
	*@Description	: Enable I2c
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void I2cEnable();

	/********************************************************************
	*@Method		: Default copy constructor/operator=
	********************************************************************/
    I2C(const I2C& obj) = delete;
	I2C &operator=(const I2C& obj) = delete;
	
private:

	/********************************************************************
	*@Method		: Default constructor
	********************************************************************/
	I2C() {};

	/********************************************************************
	*@Method		: I2cReadCmd
	*@Description	: Send Read Command to CMD register
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void I2cReadCmd();

	/********************************************************************
	*@Method		: I2cWriteByte
	*@Description	: Write th CMD register
	*@Inputs		: data - Data to write
	*@Inputs		: cmd - cmd - Read = 1, Write = 0
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void I2cWriteByte(uint8_t data, bool cmd);


	/********************************************************************
	Data Members
	********************************************************************/
	static I2C	mObjInstance;
    
};