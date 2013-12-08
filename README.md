Arduino Cron Library
====================

The Arduino Cron Library is a library which allows an Arduino sketch define a set of commands which may be executed at a specified time.

The library makes use of a cron like syntax to schedule commands to be executed. It makes use of the RTC DS1307 chip to read the time. To communicate with the chip the library uses the RTClib library from adafruit.

Installation
------------

To get started you need to do the following:

- Download the RTClib library from https://github.com/adafruit/RTClib and unzip the file in the usual Arduino/libraries folder
- Open the RTClib.h file in a text editor
- Add the following to the top of the file
```
#ifndef RTClib_h
#define RTClib_h
```
- Add the following to the bottom of the file
```
#endif
```
- Unzip the ArduinoCronLibrary folder into the Arduino/libraries folder


To use
------

- Open the arduino ide and open the ArduinoCronLibraryExample
- Compile and run the program

The following commands are currently available:

- SwitchOnCommand
- SwitchOffCommand


Creating New Commands
---------------------

If you would like to create your own commands, simply 

- extend the Command class
- implement the Command::execute(String) funtion (The execute function is what is called when the cron string matches.)
