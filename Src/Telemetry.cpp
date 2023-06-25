//**************************************************************************
//
// Telemetry.cpp
//
// Telemetry class implementation.
//
//**************************************************************************
#include "..\inc\Telemetry.h"

/********************************************************************
*@method		: TelemetryInit
********************************************************************/
void Telemetry::TelemetryInit(uint8_t aModuleId)
{
    mTelemetryData.Reset();
    mTelemetryData.ModuleId = aModuleId;
}

/****************************************************************************************************
*@method		: EnableDisableTelemetry
****************************************************************************************************/
void Telemetry::EnableDisableTelemetry(bool aEnable)
{
    mTelemetryData.Enable = aEnable;
}

/******************************************************************************************
*@method		: TelemetryReport
*******************************************************************************************/
void Telemetry::UpdateTelemetry(uint8_t aState, uint8_t aFuelLevel)
{
    mTelemetryData.ModuleState = aState;
    mTelemetryData.FuelLevel = aFuelLevel;
}

/******************************************************************************************
*@method		: GetTelemetry
*******************************************************************************************/
TelemetryData Telemetry::GetTelemetry()
{
    return mTelemetryData;
}
