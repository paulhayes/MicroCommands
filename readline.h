
#ifndef readline_h
#define readlin_h

bool lineMatches(char *buffer,const char *comp, int len);
bool lineStarts(char *buffer,const char *comp, int len);
bool lineCharIntValue(char *buffer,const char comp, int& value);
int readline(char *buffer, int len);


#endif