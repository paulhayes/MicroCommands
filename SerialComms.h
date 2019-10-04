#include <Arduino.h>
#include <Commands.h>
#include <Settings.h>

#pragma once

#ifdef CORE_TEENSY
#define Serial_ Stream  
#endif

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


