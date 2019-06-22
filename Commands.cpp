#include <EEPROM.h>
#include <string.h>
#include "Commands.h"
#include <stdio.h>

Commands::Commands()
{
  //memset( this->ptr,0, sizeof(this->ptr));
  
}

void Commands::registerCommand(const char *commandStr,callback callbackRef, int argFlags )
{
  this->commandStr[length] = commandStr;
  this->callbacks[length] = callbackRef;
  this->argFlags[length] = argFlags;
  length++;

}

bool Commands::parseCommands(char *buffer)
{
  for(int i=0;i<this->length;i++){
    if(this->argFlags[i]==Commands::INT){
      if( this->parseIntCommand(i,buffer) )
        return true;
    }

  }
  return false;
}

bool Commands::parseIntCommand(int commandIndex, char *buffer)
{
  int val;
  int matched = sscanf(buffer,this->commandStr[commandIndex],&val);
  if( matched == EOF ){
    return false;
  }
  else if(matched==1){
    this->callbacks[commandIndex](&val);
    return true;
    
  }
  return false;
}