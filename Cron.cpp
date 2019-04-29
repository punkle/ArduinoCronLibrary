/*
 * Cron.cpp
 *
 *  Created on: 7 Jun 2012
 *      Author: fletcherb
 */

#include "Cron.h"

RTC_DS1307 RTC;

Cron::Cron(TimedCommand **iTimedCommands, int iTimedCommandsSize) {
  timedCommands = iTimedCommands;
  timedCommandsSize = iTimedCommandsSize;

  Wire.begin();
    RTC.begin();
}

Cron::~Cron() {
}



void Cron::loop(){
  bool match = false;
  for (int i = 0; i< timedCommandsSize; i++){
    if (matchCron(timedCommands[i]->getCronString(),getTime())){
      Command *command = timedCommands[i]->getCommand();
      command->execute(timedCommands[i]->getParameters());
      match = true;
    }
  }
  if (match){
    delay(1000);
  }
}

DateTime Cron::getTime(){
    DateTime now = RTC.now();
    return now;
}

boolean Cron::matchCron(String cronString, DateTime time){
    boolean secMatch,minMatch,hourMatch,dayMatch,monMatch,yearMatch;
    String tempTimeString;
    String commandString;
    int cronTime[6];
    cronString.trim();
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[0] = -1;
    } else {
      cronTime[0] = tempTimeString.toInt();
    }
    cronString.trim();
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[1] = -1;
    } else {
      cronTime[1] = tempTimeString.toInt();
    }
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[2] = -1;
    } else {
      cronTime[2] = tempTimeString.toInt();
    }
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[3] = -1;
    } else {
      cronTime[3] = tempTimeString.toInt();
    }
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[4] = -1;
    } else {
      cronTime[4] = tempTimeString.toInt();
    }
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    tempTimeString = cronString.substring(0,cronString.indexOf('.'));
    if (tempTimeString.equals("*")) {
      cronTime[5] = -1;
    } else {
      cronTime[5] = tempTimeString.toInt();
    }
    cronString = cronString.substring(cronString.indexOf('.') + 1);
    commandString = cronString.substring(0,cronString.indexOf('.'));

    cronString = "";

    if (cronTime[5] == -1){
      yearMatch = true;
    } else

      if (time.year() == cronTime[5]){
        yearMatch = true;
      } else{
        yearMatch = false;
      }

    if (cronTime[4] == -1){
      monMatch = true;
    } else

      if (time.month() == cronTime[4]){
        monMatch = true;
      } else{
        monMatch = false;
      }

    if (cronTime[3] == -1){
      dayMatch = true;
    } else

      if (time.day() == cronTime[3]){
        dayMatch = true;
      } else{
        dayMatch = false;
      }

    if (cronTime[2] == -1){
      hourMatch = true;
    } else

      if (time.hour() == cronTime[2]){
        hourMatch = true;
      } else{
        hourMatch = false;
      }

    if (cronTime[1] == -1){
      minMatch = true;
    } else

      if (time.minute() == cronTime[1]){
        minMatch = true;
      } else{
        minMatch = false;
      }

    if (cronTime[0] == -1){
      secMatch = true;
    } else

      if (time.second() == cronTime[0]){
        secMatch = true;
      } else{
        secMatch = false;
      }
    if (secMatch && minMatch && hourMatch && dayMatch && monMatch && yearMatch){
      return true;
    } else {
      return false;
    }
}

void Cron::printTime(){
  DateTime time = getTime();
    Serial.print(time.year(), DEC);
    Serial.print('/');
    Serial.print(time.month(), DEC);
    Serial.print('/');
    Serial.print(time.day(), DEC);
    Serial.print(' ');
    Serial.print(time.hour(), DEC);
    Serial.print(':');
    Serial.print(time.minute(), DEC);
    Serial.print(':');
    Serial.print(time.second(), DEC);
    Serial.println();
}

void Cron::setTime(DateTime time){
  RTC.adjust(time);
}
