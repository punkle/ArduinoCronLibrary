/*
 * SwitchOnCommand.cpp
 *
 *  Created on: 5 Jun 2012
 *      Author: fletcherb
 */

#include "SwitchOnCommand.h"

SwitchOnCommand::SwitchOnCommand() {
  instruction = "switchOn";
}

SwitchOnCommand::~SwitchOnCommand() {
}

void SwitchOnCommand::execute(String parameter){
  int pinNo = parameter.toInt();
  pinMode(pinNo, OUTPUT);
  digitalWrite(pinNo,HIGH);
  Serial.print("Pin ");
  Serial.print(pinNo);
  Serial.println(" switched on");
}
