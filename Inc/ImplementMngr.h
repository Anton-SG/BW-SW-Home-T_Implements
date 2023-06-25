//**************************************************************************
//
// ImplementMngr.h
//
// This file defines the main implement APIs.
//
//***************************************************************************
#ifndef __IMPLEMENT_MNGR_H__
#define __IMPLEMENT_MNGR_H__

#include "..\Inc\ImplementViaI2c.h"
#include "..\Inc\ImplementViaSpi.h"
#include "..\Inc\Gpio.h"


class ImplementMngr
{
public:
    // /********************************************************************
	// *@method		: CTOR
	// ********************************************************************/
    // ImplementMngr();

    // /********************************************************************
	// *@method		: virtual DTOR
	// ********************************************************************/
    // ~ImplementMngr(){}

 	/********************************************************************
	*@Method		: Init
	*@Description	: Initialize all implements
	********************************************************************/
	void Init();

    /********************************************************************
	*@method		: MainRun
	*@Description	: Run Main logic
	********************************************************************/
    void MainRun();

    /********************************************************************
	*@method		: ExternalTriggerNotification
	*@Description	: Notification from external INT/GPIO 
	********************************************************************/
    void ExternalTriggerNotification(EXTERNAL_TRIGGER aTrigger);

protected:


    /********************************************************************
	*@method		: TimerSimulation
	*@Input     	: aTimeout 
	*@Returns		: TelemetryData structure
	********************************************************************/
    void TimerSimulation(uint32_t aTimeout);


    //********************************************************************
    ImplementViaI2c mImplementI2c;
    ImplementViaSpi mImplementSpi;

};


#endif //#define __IMPLEMENT_MNGR_H__
