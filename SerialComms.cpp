#include <SerialComms.h>
#include <Arduino.h>

SerialComms::SerialComms(Serial_ *serial,int bufLen)
{
  this->serial = serial;
  this->buffer = new char[bufLen];  
}

void SerialComms::update()
{
  int address = 0;
    int value = 0;
    if( this->settings.parseAllGetLine(this->buffer) ){
      int i=0;
      while(this->settings.nextProp(i)){
        this->serial->print("$");
        this->serial->print(i);
        this->serial->print("=");
        this->serial->println(this->settings.getValue(i));
        i++;
      }
    }    
    else if( this->settings.parseSetLine(this->buffer,address,value) >= 0 ){
      Serial.println("set ok");
    }
    else if( settings.parseGetLine(buffer,address,value) >= 0 ){
      this->serial->print("$");
      this->serial->print(address);
      this->serial->print("=");
      this->serial->println(value);
    }    
    else if( commands.parseCommands(buffer) ){
      this->serial->println("ok");
    }
}