//**************************************************************************
// ImplementViaSpi Implementation file
//**************************************************************************

#include <iostream>
#include "..\Inc\ImplementViaSpi.h"

using namespace std;

/********************************************************************
*@method		: SpiDisable
********************************************************************/
inline void SpiDriver::SpiDisable()
{
	//Disable by writing the IC_ENABLE register
	cout << "Spi::Disable" << endl;
}

/********************************************************************
*@method		: SpiEnable
********************************************************************/
inline void SpiDriver::SpiEnable()
{
	//Enable by writing the IC_ENABLE register
	cout << "Spi::Enable" << endl;
}



/********************************************************************
*@method		: Init
********************************************************************/
void SpiDriver::Init(uint8_t aSpeed)
{
    //Inializate Spi bus
	cout << "Spi::Init()" << endl;
}

/********************************************************************
*@method		: SpiWrite
********************************************************************/
void SpiDriver::SpiWrite(SpiTransfer apTransfer)
{
    // Write data
	cout << "Spi::Write()" << endl;
}


/********************************************************************
*@method		: SpiRead
********************************************************************/
void SpiDriver::SpiRead(SpiTransfer& arTransfer)
{
    // Read data
	cout << "Spi::Write()" << endl;
}




/********************************************************************
*@method		: CTOR
********************************************************************/
ImplementViaSpi::ImplementViaSpi() : ImplementBaseInterface()
{
    
}

/********************************************************************
*@Method		: Init
********************************************************************/
void ImplementViaSpi::Init(FUEL_TYPE aFuelType, uint8_t aLevel)
{
    mSpiDriver.Init(0);
    mFuel.Init(aFuelType, aLevel);
}

/********************************************************************
*@method		: SetWorkingState
********************************************************************/
void ImplementViaSpi::SetWorkingState(ENABLE_STATUS aState)
{
    ENABLE_STATUS lastState = GetImplementState();
    
    //Check Fuel Level
    uint8_t fuelLevel = mFuel.CheckAndUpdateFuelLevel();

    //Generate Spi Buffer
    SpiTransfer transfer;
    transfer.Length = 1;
    
    // Exit of there is enough fuel and the same state
    if ((eSTATE_DISABLE == aState) || (!mFuel.IsEnoughFuel()))
    {
        //Stop implement
        transfer.Buffer[0] = eSTATE_DISABLE;
        mSpiDriver.SpiWrite(transfer);
        
        //Update telemetry
        mTelemetry.UpdateTelemetry(eSTATE_DISABLE, fuelLevel);
    }    
    else if (lastState != aState)
    {
        //Start implement
        transfer.Buffer[0] = eSTATE_ENABLE;
        mSpiDriver.SpiWrite(transfer);

        //Update telemetry
        mTelemetry.UpdateTelemetry(eSTATE_ENABLE, fuelLevel);
    }
}

/********************************************************************
*@method		: UpdateStatusAndGetTelemetry
********************************************************************/
TelemetryData ImplementViaSpi::UpdateStatusAndGetTelemetry()
{
    //Check Fuel Level
    uint8_t fuelLevel = mFuel.CheckAndUpdateFuelLevel();

    //Check Fuel level
    if(!mFuel.IsEnoughFuel())
    {
        SetWorkingState(mCurrentState);
    }
    
    //Update telemetry
    mTelemetry.UpdateTelemetry(mCurrentState, fuelLevel);

    return mTelemetry.GetTelemetry();
}
