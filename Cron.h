/*
 * Cron.h
 *
 *  Created on: 7 Jun 2012
 *      Author: fletcherb
 */

#ifndef CRON_H_
#define CRON_H_
#include <Wire.h>
#include <RTClib.h>
#include <Arduino.h>
#include "TimedCommand.h"

class Cron {
public:
  Cron(TimedCommand **,int); // Get pointer to array of pointers
  virtual ~Cron();
  void loop();
  void printTime();
  void setTime(DateTime);
  boolean matchCron(String,DateTime);
private:
  TimedCommand **timedCommands;
  int timedCommandsSize;
  DateTime getTime();
};

#endif /* CRON_H_ */
