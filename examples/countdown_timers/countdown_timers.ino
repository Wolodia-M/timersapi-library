#include "timersapi.hpp"  //inluding library

/*
    Countdownm timer
  Explain how to create and manage countdown timers
    Components
  Arduino compatible boards;
  
    24.05.2022
    Created by WolodiaM.
*/


countdowns cndt(1000, 0); // initialize timer with delay 1000 ms

void setup() {
  Serial.begin(115200);
  cndt.start();
}

void loop() {
  if(cndt.counted()){
    Serial.println("tick");  
  }
}
