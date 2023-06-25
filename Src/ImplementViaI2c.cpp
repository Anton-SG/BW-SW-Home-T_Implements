//**************************************************************************
// ImplementViaI2c Implementation file
//**************************************************************************

#include <iostream>
#include "..\Inc\ImplementViaI2c.h"

using namespace std;

/********************************************************************
*@method		: CTOR
********************************************************************/
ImplementViaI2c::ImplementViaI2c() : ImplementBaseInterface()
{
    mpI2cInstance = I2C::Instance();
}

/********************************************************************
*@Method		: Init
********************************************************************/
void ImplementViaI2c::Init(FUEL_TYPE aFuelType, uint8_t aLevel)
{
    mpI2cInstance->Init(0);
    mFuel.Init(aFuelType, aLevel);
}

/********************************************************************
*@method		: SetWorkingState
********************************************************************/
void ImplementViaI2c::SetWorkingState(ENABLE_STATUS aState)
{
    ENABLE_STATUS lastState = GetImplementState();
    
    //Check Fuel Level
    uint8_t fuelLevel = mFuel.CheckAndUpdateFuelLevel();

    //Generate I2c Buffer
    I2cTransfer transfer;
    transfer.Length = 1;
    
    // Exit of there is enough fuel and the same state
    if ((eSTATE_DISABLE == aState) || (!mFuel.IsEnoughFuel()))
    {
        //Stop implement
        transfer.Buffer[0] = eSTATE_DISABLE;
        mpI2cInstance->I2cMasterWrite(transfer);
        
        //Update telemetry
        mTelemetry.UpdateTelemetry(eSTATE_DISABLE, fuelLevel);
    }    
    else if (lastState != aState)
    {
        //Start implement
        transfer.Buffer[0] = eSTATE_ENABLE;
        mpI2cInstance->I2cMasterWrite(transfer);

        //Update telemetry
        mTelemetry.UpdateTelemetry(eSTATE_ENABLE, fuelLevel);
    }
}

/********************************************************************
*@method		: UpdateStatusAndGetTelemetry
********************************************************************/
TelemetryData ImplementViaI2c::UpdateStatusAndGetTelemetry()
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
