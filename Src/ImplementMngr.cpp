//**************************************************************************
// ImplementMngr Implementation file
//**************************************************************************

#include <iostream>
#include <chrono>
#include "..\Inc\ImplementMngr.h"


/********************************************************************
*@Method		: Init
********************************************************************/
void ImplementMngr::Init()
{
    // Implement1
    mImplementI2c.Init(eFUEL_GAS, 100);
    mImplementI2c.SetWorkingState(eSTATE_ENABLE);

    // Implement1
    mImplementSpi.Init(eFUEL_ELECTRICAL, 100);
    mImplementSpi.SetWorkingState(eSTATE_ENABLE);
}

/********************************************************************
*@method		: MainRun
********************************************************************/
void ImplementMngr::MainRun()
{
    while(1)
    {
        TimerSimulation(10);

        //Implement check
        mImplementSpi.UpdateStatusAndGetTelemetry();
        mImplementI2c.UpdateStatusAndGetTelemetry();

        // if((eSTATE_DISABLE == mImplementSpi.GetImplementState()) &&
        //    (eSTATE_DISABLE == mImplementI2c.GetImplementState()))
        //    break;
    }
}

/********************************************************************
*@method		: ExternalTriggerNotification
********************************************************************/
void ImplementMngr::ExternalTriggerNotification(EXTERNAL_TRIGGER aTrigger)
{
    switch (aTrigger)
    {
    case EXTERNAL_TRIGGER_I2C_ON:
        mImplementSpi.SetWorkingState(eSTATE_ENABLE);
        break;
    case EXTERNAL_TRIGGER_I2C_OFF:
        mImplementSpi.SetWorkingState(eSTATE_DISABLE);
        break;
    case EXTERNAL_TRIGGER_SPI_ON:
        mImplementSpi.SetWorkingState(eSTATE_ENABLE);
        break;
    case EXTERNAL_TRIGGER_SPI_OFF:
        mImplementSpi.SetWorkingState(eSTATE_DISABLE);
        break;
    }
}

/********************************************************************
*@method		: TimerSimulation
********************************************************************/
void ImplementMngr::TimerSimulation(uint32_t aTimeOutInSec)
{
    _sleep(aTimeOutInSec * 1000); // pauses for 10 seconds
}
