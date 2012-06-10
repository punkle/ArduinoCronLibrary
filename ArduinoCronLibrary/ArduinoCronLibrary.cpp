// Do not remove the include below

#include "Wire.h"
#include "RTClib.h"
#include "ArduinoCronLibrary.h"
#include "Command.h"
#include "SwitchOnCommand.h"
#include "TimedCommand.h"
#include "Cron.h"
#include "SwitchOffCommand.h"

SwitchOnCommand sonCommand;
SwitchOffCommand sOffCommand;
TimedCommand command1("0.*.*.*.*.*",&sonCommand,"13");
TimedCommand command2("5.*.*.*.*.*",&sOffCommand,"13");

extern HardwareSerial Serial;

TimedCommand *tCommands[] = {
		&command1,
		&command2
};

Cron cron(tCommands[0],2);

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	Serial.println("Starting ArduinoCronLibrary Example");
	cron.setTime(DateTime(__DATE__, __TIME__));
	cron.printTime();
}

// The loop function is called in an endless loop
void loop()
{
	cron.loop();
	//cron.printTime();
}
