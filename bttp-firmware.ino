#include "config.h"

uint32_t padValues[NUM_STEPS];
bool padPressed[NUM_STEPS];

#include "serial.h"
#include "led.h"
#include "pad.h"


void setup() {
  setupPads();
  setupLights();
  setupSerial();
}

void loop() {
  tickPads();
  tickLights();
  tickSerial();
}
