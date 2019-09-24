#include <Arduino.h>
#include <Commands.h>
#include <Settings.h>

#pragma once

class SerialComms 
{
  
  public:
  SerialComms(Serial_ *serial, int bufLen);
  void update();
  Commands commands;
  Settings settings;

  private:
  Serial_ * serial;
  char * buffer;
  int bufLen;
};


