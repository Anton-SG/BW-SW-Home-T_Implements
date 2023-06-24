# Embedded Software Engineer - Home Assignment
## Introduction
In this assignment we will require to engineer and implement a short piece of software, that will be responsible for interacting with various tractor implements (the tools they carry to execute different jobs).

The **Implement Module** must accept **multiple types of implements**, under the assumption that each implement is **communicating with a different, however, known to the industry, communication protocols**.

Each implement will have the ability to Trigger the **commands** that will be **turning on or off** and **receive telemetry** that will give information about **is the implement turned on or off** and what is the **fuel level** (like gasoline or pesticide). 
Implement module will accept the commands with an external trigger (such as Serial, or any other way).

## Definitions and Technical Details
### Required:
- Used language must be C or C++ (C++11 or above)
- Multiple implements (more than one), each one of them is communicating in a different communication protocol (RS232, RS485, CAN, SPI, etc.)
- Each Implement must have both commands turning on or off, and can be triggered by external command transmitting to the software (In case using an Arduino, use Serial)
- Telemetry for each implement informing rather implement turned on or off, and what is the fuel level
- In case Implement’s fuel level is critically low, Implement must be turned off
- Source code should be uploaded to an accessible repository (GitHub, Bitbucket etc.)

### Elective:
- It is highly recommended to use OOP paradigms, Design patterns and structured Architecture
- Implements communication protocols is up to the engineer’s choice, however, there must be difference between the multiple implements
- API to trigger the commands of the Implement module to the correct Implement, will be designed by the engineer
- API to receive telemetry will be designed by the engineer
- Multiple active and controllable implement is optional
- Provide instructions to compile and run (or burn the firmware in case of using an Arduino) the software, from the source code that was provided

## Recommendations
This assignment combines architecture solution as well as implementation – in case the engineer finds a good solution for a problem that occurs and requirement does not align with the solution, please provide a detailed explanation.

It is not necessary to provide a schematic of the software’s architecture with the submission of the assignment, however, you will be asked in person for a schematic drawing on a white board, to show your train of thoughts.
