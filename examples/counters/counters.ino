#include "timersapi.hpp"  //inluding library

/*
    Counter
  Explain how to create and manage counters
    Components
  Arduino compatible boards;
  
    24.05.2022
    Created by WolodiaM.
*/


counts cnt(10, 10, 5); // initialize counte with delay 10 ms, max value 10 and starting value 5

void setup() {
  Serial.begin(9600); // Begin Serial monitor
  cnt.setMode(DOWN_COUNT, BACK); // Try to comment this line and uncoment one of next lines
  //cnt.setMode(UP_COUNT, BACK);
  //cnt.setMode(DOWN_COUNT, TO_ZERO);
  //cnt.setMode(UP_COUNT, TO_ZERO);
}

void loop() {
  // Open Serial plotter
  Serial.println(cnt.getCounter());
}
