/*
 * SwitchOnCommand.h
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#ifndef SWITCHONCOMMAND_H_
#define SWITCHONCOMMAND_H_

#include "Command.h"
#include "Arduino.h"


class SwitchOnCommand: public Command {
public:
  SwitchOnCommand();
  virtual ~SwitchOnCommand();
  void execute(String parameter);
};

#endif /* SWITCHONCOMMAND_H_ */
