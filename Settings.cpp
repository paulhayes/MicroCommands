#include <EEPROM.h>
#include <string.h>
#include "Settings.h"
#include <stdio.h>

Settings::Settings()
{
  memset( this->ptr,0, sizeof(this->ptr));
  
}

void Settings::registerProperty(int address,int& prop)
{
  this->ptr[address] = &prop;
  int val = EEPROM.read(address);
  if( val == 0xff ){
    EEPROM.write(address,prop);
  }
  else {
    prop = val;
  }

}

int Settings::parseSetLine(char *buffer, int& address, int& value)
{
  address = -1;
  uint8_t val = 0;
  int matched = sscanf(buffer,"$%d=%hhu",&address,&val);
  if(matched==2){
    if(address>=1024 || address<0){
      return -2;
    }
    else if( this->ptr[address] == 0 ){
      return -3;
    }

    EEPROM.write(address,val);
    *(this->ptr[address]) = val;
    value = val;
    return address;
  }
  return -1;
}

int Settings::parseGetLine(char *buffer, int& address, int& value)
{
  address = -1;
  int matched = sscanf(buffer,"$%d",&address);
  if(matched==1){
    if(address>=numAddresses || address<0){
      return -2;
    }
    else if( this->ptr[address] == 0 ){
      return -3;
    }
        
    value = *(this->ptr[address]);
  }
  return address;
}


bool Settings::parseInfo(char *buffer){
  return (strcmp(buffer,"$I") == 0) || (strcmp(buffer,"$i") == 0 );
}

bool Settings::parseAllGetLine(char *buffer)
{
  int matched = strcmp(buffer,"$$");
  return (matched==0);
}

bool Settings::nextProp(int& address)
{
  while(true) {
    if(address>=numAddresses || address<0){
      return false;
    }  
    if(this->ptr[address] != 0){
      break;
    }  
    ++address;
  }
  return true;
}

int Settings::getValue(int address)
{  
  return *(this->ptr[address]);
}


