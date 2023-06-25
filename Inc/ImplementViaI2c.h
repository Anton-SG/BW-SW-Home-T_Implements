//**************************************************************************
//
// ImplementViaI2c.h
//
// This file defines the main implement APIs.
//
//***************************************************************************
#ifndef __IMPLEMENT_I2C_H__
#define __IMPLEMENT_I2C_H__

#include "Fuel.h"
#include "I2cDriver.h"
#include "Telemetry.h"
#include "ImplementBase.h"


class ImplementViaI2c : ImplementBaseInterface
{
protected:
    I2C         *mpI2cInstance;
    Telemetry   mTelemetry;
    Fuel        mFuel;

public:
    /********************************************************************
	*@method		: CTOR
	*@Description	: Constructor
	*@Inputs		: aI2cSpeed - speed
	*@Returns		: None
	********************************************************************/
    ImplementViaI2c();

    /********************************************************************
	*@method		: virtual DTOR
	********************************************************************/
    virtual ~ImplementViaI2c(){}

 	/********************************************************************
	*@Method		: Init
	*@Description	: Initialize the I2C class
	*@Inputs		: aLevel - Fuel Level
	*@Inputs		: aFuelType - Fuel Type
	*@Returns		: None
	********************************************************************/
	void Init(FUEL_TYPE aFuelType, uint8_t aLevel);

    /********************************************************************
	*@method		: SetWorkingState
	*@Description	: Update current state and change implement logic
	*@Inputs		: aState - working state
	*@Returns		: None
	********************************************************************/
    void SetWorkingState(ENABLE_STATUS aState);

    /********************************************************************
	*@method		: UpdateStatusAndGetTelemetry
	*@Description	: Check state & return telemetry Data 
	*@Returns		: TelemetryData structure
	********************************************************************/
    TelemetryData UpdateStatusAndGetTelemetry();

};

#endif //__IMPLEMENT_I2C_H__