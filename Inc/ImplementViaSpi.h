//**************************************************************************
//
// ImplementViaSpi.h
//
// This file defines the main implement APIs.
//
//***************************************************************************
#ifndef __IMPLEMENT_SPI_H__
#define __IMPLEMENT_SPI_H__

#include "Fuel.h"
#include "Telemetry.h"
#include "ImplementBase.h"

#define SPI_MAX_BUFF_SIZE   32

//Spi Data structure
struct SpiTransfer
{
	uint32_t	Length;
	uint8_t	    Buffer[SPI_MAX_BUFF_SIZE];
};

class SpiDriver
{
public:
	/********************************************************************
	*@Method		: Init
	*@Description	: Initialize the Spi class
	*@Inputs		: aSpeed
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	void Init(uint8_t aSpeed);

	/********************************************************************
	*@Method		: SpiMasterWrite
	*@Description	: Master Write transsmition
	*@Inputs		: apTransfer -Spi transfer struct
	*@Outputs		: None
	********************************************************************/
	void SpiWrite(SpiTransfer apTransfer);

	/********************************************************************
	*@Method		: SpiRead
	*@Description	: Master Read transsmition
	*@Inputs		: arTransfer -Spi transfer struct
	*@Outputs		: None
	********************************************************************/
	void SpiRead(SpiTransfer& arTransfer);

	/********************************************************************
	*@Method		: SpiDisable
	*@Description	: Disable Spi
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void SpiDisable();

	/********************************************************************
	*@Method		: SpiEnable
	*@Description	: Enable Spi
	*@Outputs		: None
	*@Returns		: void
	********************************************************************/
	inline void SpiEnable();

};


class ImplementViaSpi : ImplementBaseInterface
{
protected:
    Fuel        mFuel;
    Telemetry   mTelemetry;
	SpiDriver	mSpiDriver;

public:
    /********************************************************************
	*@method		: CTOR
	*@Description	: Constructor
	*@Inputs		: aSpiSpeed - speed
	*@Returns		: None
	********************************************************************/
    ImplementViaSpi();

    /********************************************************************
	*@method		: virtual DTOR
	********************************************************************/
    virtual ~ImplementViaSpi(){}

 	/********************************************************************
	*@Method		: Init
	*@Description	: Initialize the Spi class
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

#endif //__IMPLEMENT_SPI_H__
