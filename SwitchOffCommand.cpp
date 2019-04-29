/*
 * SwitchOffCommand.cpp
 *
 *  Created on: 6 Jun 2012
 *      Author: fletcherb
 */

#include "SwitchOffCommand.h"

SwitchOffCommand::SwitchOffCommand() {
  instruction = "switchOff";

}

SwitchOffCommand::~SwitchOffCommand() {
}

void SwitchOffCommand::execute(String parameter){
  int pinNo = parameter.toInt();
  pinMode(pinNo, OUTPUT);
  digitalWrite(pinNo,LOW);
  Serial.print("Pin ");
  Serial.print(pinNo);
  Serial.println(" switched off");
}
