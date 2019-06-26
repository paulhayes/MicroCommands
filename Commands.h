#ifndef Commands_h
#define Commands_h

typedef void (*callback)(void *arg1);

class Commands 
{
public:
  Commands();
  void registerCommand(const char *scanStr, callback, int argFlags = 0 );
  bool parseCommands(char *buffer);
  
  static const int numAddresses = 128;
  static const int INT = 1;
  static const int NONE = 0;
private:
  int length = 0;
  //int *ptr[numAddresses];
  callback callbacks[numAddresses];
  char const *commandStr[numAddresses];
  int argFlags[numAddresses];
  bool parseIntCommand(int commandIndex, char *buffer);
  bool parseCommand(int commandIndex, char *buffer);
};

#endif