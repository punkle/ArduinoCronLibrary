/*
 * TimedCommand.cpp
 *
 *  Created on: 7 Jun 2012
 *      Author: fletcherb
 */

#include "TimedCommand.h"

TimedCommand::TimedCommand(String iCronString, Command *iCommand) {
  cronString = iCronString;
  command = iCommand;
}

TimedCommand::TimedCommand(String iCronString, Command *iCommand,String iParameters) {
  cronString = iCronString;
  command = iCommand;
  parameters = iParameters;
}



TimedCommand::~TimedCommand() {
}

void TimedCommand::setCronString(String iCronString){
  cronString = iCronString;
}

void TimedCommand::setCommand(Command *iCommand){
  command = iCommand;
}

String TimedCommand::getCronString(){
  return cronString;
}

Command* TimedCommand::getCommand(){
  return command;
}

String TimedCommand::getParameters(){
  return parameters;
}

void TimedCommand::setParameters(String iParameters){
  parameters = iParameters;
}
