#include <iostream>
#include "..\Inc\ImplementMngr.h"

using namespace std;

void Splash()
{
    cout << R"(
                *******************************************************
                **********                                   **********
                **********        BW Home Assignment         **********
                **********                                   **********
                **********            Anton G                **********
                **********                                   **********
                *******************************************************
                )"
         << endl;
}

int main()
{
    Splash();

    // Create main manager of all implements
    ImplementMngr mngr;
    
    // Inin implements
    mngr.Init();

    // Run implements
    mngr.ExternalTriggerNotification(EXTERNAL_TRIGGER_I2C_ON);
    mngr.ExternalTriggerNotification(EXTERNAL_TRIGGER_SPI_ON);

    //Run
    mngr.MainRun();

    return 0;
}
