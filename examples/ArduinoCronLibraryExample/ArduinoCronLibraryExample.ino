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
// create timed command objects for each timed command
//                     s.m.h.d.M.y,comand,parameters for command
TimedCommand command1("0.*.*.*.*.*",&sonCommand,"13");
TimedCommand command2("5.*.*.*.*.*",&sOffCommand,"13");

TimedCommand command3("10.*.*.*.*.*",&sonCommand,"13");
TimedCommand command4("15.*.*.*.*.*",&sOffCommand,"13");

TimedCommand command5("20.*.*.*.*.*",&sonCommand,"13");
TimedCommand command6("25.*.*.*.*.*",&sOffCommand,"13");

TimedCommand command7("30.*.*.*.*.*",&sonCommand,"13");
TimedCommand command8("35.*.*.*.*.*",&sOffCommand,"13");

TimedCommand command9("40.*.*.*.*.*",&sonCommand,"13");
TimedCommand command10("45.*.*.*.*.*",&sOffCommand,"13");


TimedCommand command11("50.*.*.*.*.*",&sonCommand,"13");
TimedCommand command12("55.*.*.*.*.*",&sOffCommand,"13");

// create an array of timed commands
TimedCommand *tCommands[] = {
    &command1,
    &command2,

    &command3,
    &command4,

    &command5,
    &command6,

    &command7,
    &command8,

    &command9,
    &command10,

    &command11,
    &command12


};

// create a cron object and pass it the array of timed commands
// and the count of timed commands
Cron cron(tCommands,12 );

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
