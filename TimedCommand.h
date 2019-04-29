/*
 * TimedCommand.h
 *
 *  Created on: 7 Jun 2012
 *      Author: fletcherb
 */

#ifndef TIMEDCOMMAND_H_
#define TIMEDCOMMAND_H_
#include "Command.h"

class TimedCommand {
public:
  TimedCommand(String, Command*);
  TimedCommand(String, Command*,String);
  virtual ~TimedCommand();
  void setCronString(String);
  void setCommand(Command*);
  void setParameters(String);
  Command* getCommand();
  String getCronString();
  String getParameters();

private:
  Command *command;
  String cronString;
  String parameters;
};

#endif /* TIMEDCOMMAND_H_ */
