#ifndef Commands_h
#define Commands_h

typedef void (*callback)(void *arg1);

class Commands 
{
public:
  Commands();
  void registerCommand(const char *scanStr, callback, int argFlags = 1 );
  bool parseCommands(char *buffer);
  
  static const int numAddresses = 128;
  static const int INT = 1;

private:
  int length = 0;
  //int *ptr[numAddresses];
  callback callbacks[numAddresses];
  char const *commandStr[numAddresses];
  int argFlags[numAddresses];
  bool parseIntCommand(int commandIndex, char *buffer);

};

#endif