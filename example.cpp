#include <Arduino.h>
#include <Settings.h>
#include <Commands.h>
#include <readline.h>

const int dirPin1 = 8;
const int dirPin2 = 7;
const int pwmPin = 6;

int speed = 0;


Commands commands;

void mCommand(void *data){
    int val = * (int *) data; 
    
}

void setSpeed(void *data){
    speed = * (int *) data; 
    
}

void _setup(){
    while(!Serial)
        delay(500);

    Serial.begin(115200);

    commands.registerCommand("M%d",mCommand);
    commands.registerCommand("S%d",setSpeed);
}

void _loop(){
    
}

