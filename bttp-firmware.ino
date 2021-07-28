#include "config.h"

uint32_t stepValues[NUM_STEPS];
bool stepPressed[NUM_STEPS];

#include "Lights.h"
#include "serial.h"
#include "pad.h"

void setup() {
  setupSerial();
  setupLights();
}

void loop() {
  tickSteps();
  tickSerial();
  tickLights();
}
