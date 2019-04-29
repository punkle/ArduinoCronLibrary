/*
 * SwitchOffCommand.h
 *
 *  Created on: 6 Jun 2012
 *      Author: fletcherb
 */

#ifndef SWITCHOFFCOMMAND_H_
#define SWITCHOFFCOMMAND_H_

#include "Command.h"
#include "Arduino.h"

class SwitchOffCommand: public Command {
public:
  SwitchOffCommand();
  virtual ~SwitchOffCommand();
  void execute(String parameter);
};

#endif /* SWITCHOFFCOMMAND_H_ */
