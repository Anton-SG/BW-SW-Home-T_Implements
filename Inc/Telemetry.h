//*****************************************************************************
//
// Telemetry.h
//
// Manages the telemetry in the FW .
//
//*****************************************************************************
#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_

#include "TelemetryDefs.h"

class Telemetry
{
public:
	/********************************************************************
	*@method		: Constructor/Destructor
	********************************************************************/
	Telemetry() {};

	/********************************************************************
	*@method		: TelemetryInit
	*@Description	: Telemetry initialization 
	*@Inputs		: aModuleId	
	********************************************************************/
    void TelemetryInit(uint8_t aModuleId);

	/****************************************************************************************************
	*@method		: EnableDisableTelemetry
	*@Description	: Enable/Disable Telemetry Transmission
	*@Inputs		: aEnabled - true/false	
	*@Outputs		: None
	*@Returns		: None 
	****************************************************************************************************/
	void EnableDisableTelemetry(bool aEnabled);

	/******************************************************************************************
	*@method		: UpdateTelemetry
	*@Description	: Set Call the entire Telemetry
	*@Inputs		: aState - Implement state
	*@				: aFuelLevel - Implement Fuel Level
	*******************************************************************************************/
	void UpdateTelemetry(uint8_t aState, uint8_t aFuelLevel);

	/******************************************************************************************
	*@method		: GetTelemetry
	*@Description	: get the entire Telemetry data 
	*@Outputs		: TelemetryData 
	*******************************************************************************************/
	TelemetryData GetTelemetry();


private:
    TelemetryData mTelemetryData;
};

#endif // _TELEMETRY_H_
