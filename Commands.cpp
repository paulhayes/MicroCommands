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
    switch(this->argFlags[i]){
      case Commands::INT:
        if( this->parseIntCommand(i,buffer) )
          return true;
      break;
      case Commands::NONE:
        if( this->parseCommand(i,buffer) )
        return true;
      default:

      break;
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

bool Commands::parseCommand(int commandIndex, char *buffer)
{
  int len = strlen(this->commandStr[commandIndex]);
  int matched = strncasecmp(buffer,this->commandStr[commandIndex],len);
  if( matched==0 ){
    this->callbacks[commandIndex](NULL);
    return true;
  }    
  
  return false;
}