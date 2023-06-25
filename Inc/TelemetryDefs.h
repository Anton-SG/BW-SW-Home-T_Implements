//*****************************************************************************
//
// TelemetryDefs.h
//
// Defs of the telemetry in the FW .
//
//*****************************************************************************
#ifndef _TELEMETRY_DEFS_H_
#define _TELEMETRY_DEFS_H_

#include <cstdint>

// Telemetry data structure
struct TelemetryData 
{
    uint8_t     ModuleId;         // Module ID == Defined by Implement
    uint8_t     ModuleState;      // Current State of the implement (turned on/off)
    uint8_t     FuelLevel;        // Fuel Level can be from 100% to 0%
    uint8_t     Enable;           // Enable/Disable status

    void Reset()
    {
        ModuleId = 0;
        ModuleState = 0;
        FuelLevel = 0;
        Enable = 0;
    }
}; 

#endif //_TELEMETRY_DEFS_H_