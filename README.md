# MicroSerialCommands

These instructions are currently written for platformio rather than Arduino IDE. However you can download, and copy and paste these files into your arduino project.

## Installation:

Add the following to your platformio.ini file
```
lib_deps = 
    EEPROM 
    https://github.com/paulhayes/MicroSerialCommands.git
```

Then include the following to your main file
```
#include <Settings.h>
#include <readline.h>
```
