#ifndef Settings_h
#define Settings_h


class Settings 
{
public:
  Settings();
  void registerProperty(int address,int& prop);
  int parseSetLine(char *buffer, int& address, int& value);
  int parseGetLine(char *buffer, int& address, int& value);
  bool parseAllGetLine(char *buffer);
  bool parseInfo(char *buffer);
  bool nextProp(int& index);
  int getValue(int address);
  char *buildInfoString = NULL;
  static const int numAddresses = 128;
  
private:
  int *ptr[numAddresses];
  
};

#endif