// Do not remove the include below

#include "Wire.h"
#include "RTClib.h"
#include "SwitchOnCommand.h"
#include "TimedCommand.h"
#include "Cron.h"
#include "SwitchOffCommand.h"

// create objects for each command
SwitchOnCommand sonCommand;
SwitchOffCommand sOffCommand;

// create timed command objects for each timed command
//                     s.m.h.d.M.y,comand,parameters for command
TimedCommand command1("0.*.*.*.*.*",&sonCommand,"13");
TimedCommand command2("5.*.*.*.*.*",&sOffCommand,"13");

// create an array of timed commands
TimedCommand *tCommands[] = {
		&command1,
		&command2
};

// create a cron object and pass it the array of timed commands
// and the count of timed commands
Cron cron(tCommands[0],2);

void setup()
{
	Serial.begin(9600);
	Serial.println("Starting ArduinoCronLibrary Example");
	
	// sets the time to be the date and time of the compilation
	cron.setTime(DateTime(__DATE__, __TIME__));
    // prints the current time
    cron.printTime();
}

// The loop function is called in an endless loop
void loop()
{
	// the loop funtion checks if a timed command 
	// is due to be executed and executes if it is
	cron.loop();
}
