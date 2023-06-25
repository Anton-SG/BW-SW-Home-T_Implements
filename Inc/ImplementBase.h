//**************************************************************************
//
// ImplementBase.h
//
// This file defines the main implement APIs.
//
//***************************************************************************
#pragma once

#include <iostream>

// Declaration of Base class
enum ENABLE_STATUS
{
    eSTATE_DISABLE = 0,
    eSTATE_ENABLE = 1
};

// Declaration of Base class
class ImplementBaseInterface
{
protected:
    ENABLE_STATUS mCurrentState;

public:
	/********************************************************************
	*@method		: CTOR
	********************************************************************/
	ImplementBaseInterface() : mCurrentState(eSTATE_DISABLE) {}

	/********************************************************************
	*@method		: virtual destructor
	********************************************************************/
	~ImplementBaseInterface() { std::cout << "ImplementBase Destuctor Call\n"; }

	/********************************************************************
	*@method		: Set Implement State
	********************************************************************/
	void SetImplementState(ENABLE_STATUS aState) { mCurrentState = aState; }

	/********************************************************************
	*@method		: Get Implement State 
	********************************************************************/
	ENABLE_STATUS GetImplementState() { return mCurrentState; }
};


