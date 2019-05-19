#include <Arduino.h>

bool lineMatches(char *buffer,const char *comp, int len){
  return len>0 && strcmp(buffer,comp)==0;
}

bool lineStarts(char *buffer,const char *comp, int len){
  if(len==0){
    return false;
  }
  int compLen = sizeof(comp);
  return strncmp(buffer,comp,compLen)==0;
}

bool lineCharIntValue(char *buffer,const char comp, int& value){  
  if(buffer[0]==comp){
    char* p = buffer;
    p++;
    value = atoi(p);
    return true;
  }
  return false;
}

int readline(char *buffer, int len) {
    static int pos = 0;
    int rpos;
    
    while (Serial.available()) {
        int readch = Serial.read();
        switch (readch) {
            case '\r': // Ignore CR
                break;
            case '\n': // Return on new-line
                rpos = pos;
                pos = 0;  // Reset position index ready for next time
                return rpos;
            default:
                if (pos < len-1) {
                    buffer[pos++] = readch;
                    buffer[pos] = 0;
                }
        }
    }
    return 0;
}