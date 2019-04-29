/*
 * Command.h
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include "Arduino.h"

class Command {
public:
  Command();
  virtual ~Command();
  virtual void execute (String parameter) = 0;
  String getInstruction();
protected:
  String instruction;
};

#endif /* COMMAND_H_ */
