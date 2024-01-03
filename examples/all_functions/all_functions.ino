#include "timersapi.hpp"  // Including library

/*
    All functions
  Explain all functions of  the library
  This can have some errors on compilations and really does nothing, this is simple API showwcase
    Components
  Arduino compatible boards;
  
    23.05.2022
    Created by WolodiaM.
*/
unsigned int del;
int counter;
bool timer;

timers tmr(1000); // initialize timer with delay 1000 ms
countdowns cndt(1000, 0); // initialize countdown timer for delay 1000 ms and without runing
counts cnt(1000, 100); // initialize counter with delay 1000 ms and maximum value 100
//counts cnt(1000, 100, 46); // initialize counter with delay 1000 ms, maximum value 100 and starting value 46

void setup() {
  Serial.begin(115200);
  tmr.setDel(500); // change timer delay to 500ms
  cndt.setDel(1500); // change countdown timer delay to 1500ms
  cnt.setDel(7463); // change counter timer delay to 7463ms
  tmr.stop(); // stop timer
  tmr.start(); // start timer
  cndt.stop(); // stop countdown
  cndt.start(); // start countdown
  cnt.stop(); // stop counter
  cnt.start(); // start counter
  cnt.setMode(UP_COUNT, TO_ZERO); // set counter mode to COUNT_UP/COUNT_DOWN, TO_ZERO/BACK
  // UP_COUNT - count from zero to max, DOWN_COUNT - count from max to zero
  // TO_ZERO - after counted to max/zero - reset to another end value
  // BACK - after counted to max/zero - change counting direction
  cnt.setMax(50); // Set max counter value to 50
  timer = cndt.counted(); // save if countdown is ended
  cnt.setCounter(50); // set counter to 50
  counter = cnt.getCounter(); // save counter value
  timer = tmr.getOverflow(); // save if timer is owerflowed
  timer = tmr.getTick(); // save if timer is ticked
  del = tmr.getDel(); //save delay for timer
  del = cndt.getDel(); //save delay for countdown
  del = cnt.getDel(); // save delay for counter
}

void loop() {}
