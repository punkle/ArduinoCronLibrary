/*
 * SwitchOnCommand.cpp
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#include "Command.h"

Command::Command() {
  instruction = "default";
}

Command::~Command() {
}

String Command::getInstruction(){
  return instruction;
}

void Command::execute(String parameter){
  Serial.println("test");
};

