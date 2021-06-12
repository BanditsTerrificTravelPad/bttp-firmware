#include "config.h"

uint32_t stepValues[NUM_STEPS];
bool stepPressed[NUM_STEPS];

#include "serial.h"
#include "pad.h"

void setup() {
  setupSerial();
}

void loop() {
  tickSteps();
  tickSerial();
}
