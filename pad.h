#ifndef BTTP_PAD
#define BTTP_PAD

#include "config.h"
void tickSteps() {
  for (int step = 0; step < NUM_STEPS; step++) {
    stepValues[step] = analogRead(PINS[step]);
    stepPressed[step] = (stepValues[step] > thresholds[step]);
    Joystick.button(JOYSTICK_BUTTONS[step], stepPressed[step]);
  }
}

#endif
