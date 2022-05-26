#include "timersapi.hpp"  //inluding library

/*
    Timer
  Explain how to create and manage timers
    Components
  Arduino compatible boards;
  
    24.05.2022
    Created by WolodiaM.
*/


timers tmr(1000); // initialize timer with delay 1000 ms

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(tmr.getTick()){
    Serial.println("tick");  
  }
}
