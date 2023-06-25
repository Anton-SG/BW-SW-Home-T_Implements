//**************************************************************************
//
// I2cDriver.cpp
//
// I2C class implementation.
// This file defines the functions and data needed to control I2c communication.
//
//**************************************************************************
#include <iostream>
#include "..\Inc\I2cDriver.h"
#include "..\Inc\Gpio.h"

using namespace std;

extern I2cRegStruct I2C_REG_BA;

//class I2C;
I2C	I2C::mObjInstance;

inline void I2C::I2cDisable()
{
	//Disable by writing the IC_ENABLE register
	cout << "I2C::Disable" << endl;
}

inline void I2C::I2cEnable()
{
	//Enable by writing the IC_ENABLE register
	cout << "I2C::Enable" << endl;
}

inline void I2C::I2cReadCmd()
{
	//send read cmd
	cout << "I2C::Read cmd" << endl;
}

inline void I2C::I2cWriteByte(uint8_t data, bool cmd)
{
    if (I2C_WRITE_CMD == cmd)
    {
        //write byte
        cout << "I2C::Write byte" << endl;

        return;
    }
           
    //read byte
    cout << "I2C::Read byte" << endl;
 
}

void I2C::Init(uint8_t aSpeed)
{
    //Inializate I2c bus
	cout << "I2C::Init()" << endl;
}

uint32_t I2C::I2cMasterWrite(I2cTransfer apTransfer)
{
	//Enable 
	I2cEnable();

    // Write data
    I2cWriteByte(1, I2C_WRITE_CMD);

	//Disable
    I2cDisable();
	
    return 0;
}


void I2C::I2cMasterRead(I2cTransfer& arTransfer)
{
	//Enable 
	I2cEnable();

    // Read data
    I2cWriteByte(1, I2C_READ_CMD);

	//Disable
    I2cDisable();
}



// int main()
// {
//     I2C *pI2c = I2C::Instance();
//     pI2c->Init(40);

//     I2cTransfer data;
//     data.Length = 1;
//     data.Buffer[0] = 11;
//     pI2c->I2cMasterWrite(data);

//     return 0;

// }