//**************************************************************************
//
// Fuel.h
//
// This file defines the main implement APIs.
//
//***************************************************************************
#ifndef __FUEL_H__
#define __FUEL_H__


#include <stdint.h>

// Declarations
#define MAX_FUEL_LEVEL      100
#define LOW_FUEL_LEVEL      0

constexpr uint8_t MINIMAL_FUEL_LEVEL_TO_FORCE_STOP = 10;

enum FUEL_TYPE
{
    eFUEL_ELECTRICAL = 0,
    eFUEL_GAS = 1,
    eFUEL_NOT_SUPPORTED
};


// Declaration of Base class
class Fuel
{
protected:
    FUEL_TYPE   mFuelType;
    uint8_t     mFuelLevel;
    uint8_t     mMunimalLEvelToStop;
    

public:

	/********************************************************************
	*@method		: constructor
	********************************************************************/
	Fuel()
    	{ 
		mFuelType = eFUEL_NOT_SUPPORTED;
		mFuelLevel = 0; 
		mMunimalLEvelToStop = MINIMAL_FUEL_LEVEL_TO_FORCE_STOP;
    	}

	/********************************************************************
	*@method		: constructor
	********************************************************************/
	~Fuel() {}

	/********************************************************************
	*@method		: Set Implement State
	********************************************************************/
	bool UpdateLevel(uint8_t aLevel) 
    	{ 
        	mFuelLevel = aLevel; //Check level correctness must be added

        	//return if the level is ok
        	return (mFuelLevel >= mMunimalLEvelToStop);
    	}

	/********************************************************************
	*@method		: Init
	********************************************************************/
	void Init(FUEL_TYPE aType, uint8_t aLevel, uint8_t aMinLevel = MINIMAL_FUEL_LEVEL_TO_FORCE_STOP) 
    	{
        	//Check input correctness if needed
		mFuelType = aType;
        	mFuelLevel = aLevel; 
        	mMunimalLEvelToStop = aMinLevel;
    	}

	/********************************************************************
	*@method		: GetFuelLevel
	********************************************************************/
	uint8_t GetFuelLevel() { return mFuelLevel; }

    	/********************************************************************
	*@method		: SetFuelType
	********************************************************************/
	void SetFuelType(FUEL_TYPE aType) { mFuelType = aType; }

    	/********************************************************************
	*@method		: CheckAndUpdateFuelType
	********************************************************************/
	uint8_t CheckAndUpdateFuelLevel() 
	{ 
		mFuelLevel = (mFuelLevel > 0) ? --mFuelLevel : 0;
		return mFuelLevel;
	}

    	/********************************************************************
	*@method		: GetFuelType
	********************************************************************/
	FUEL_TYPE GetFuelType() { return mFuelType; }

    	/********************************************************************
	*@method		: IsEnoughFuel
	********************************************************************/
	bool IsEnoughFuel() { return (mFuelLevel >= mMunimalLEvelToStop); }
};

#endif //__FUEL_H__
