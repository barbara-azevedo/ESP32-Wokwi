## ESP32 project made with Wokwi simulator ##

This project can be found on: https://wokwi.com/projects/392885903199803393

**Project description:**

Using serial communication two different actions can be done:

## First action: "set - X/Y" ##
In this case, X represents the digital output pin and Y represents the value 0 or 1 that should be addressed to pin X.


The chosen pins are: 
 - Pin number 0: D12
 - Pin number 1: D13
 - Pin number 2: D14

Example: "set - 2/1" means that pin number 2 (D14) should be set to 1.
Thus, X can be 0, 1 or 2, while Y can be 0 or 1. Any other value will receive "Invalid X" or "Invalid Y" answer by serial. 

Each pin controls one LED that matches pin status - ON or OFF. 

Also, a binary combination is done between the 3 pins: D12 is the least significant bit and D14 is the higher significant bit. With this comination, a decimal value is calculated and printed.

## Second option: "Read ADC" ##

From same serial port, one analog input value can be read. 

The analog value comes from a potenciometer in pin D15. Each time the request is made the analog value will be displayed. 
