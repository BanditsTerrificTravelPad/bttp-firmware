#ifndef BTTP_PAD
#define BTTP_PAD

#include "config.h"
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, // hidReportId
                   JOYSTICK_TYPE_GAMEPAD,      // joystickType
                   NUM_STEPS,                  // buttonCount
                   0,                          // hatSwitchCount
                   false,                      // includeXAxis
                   false,                      // includeYAxis
                   false,                      // includeZAxis
                   false,                      // includeRxAxis
                   false,                      // includeRyAxis
                   false,                      // includeRzAxis
                   false,                      // includeRudder
                   false,                      // includeThrottle
                   false,                      // includeAccelerator
                   false,                      // includeBrake
                   false                       // includeSteering
);

void tickPads() {
  for (int pad = 0; pad < NUM_STEPS; pad++) {
    padValues[pad] = analogRead(PINS[pad]);
    padPressed[pad] = (padValues[pad] > THRESHOLDS[pad]);

#ifdef JOYSTICK_INPUT
    Joystick.setButton(JOYSTICK_BUTTONS[pad], padPressed[pad]);
#else
    if (padPressed[pad]) {
      Keyboard.press(KEYBOARD_BUTTONS[pad]);
    } else {
      Keyboard.release(KEYBOARD_BUTTONS[pad]);
    }
#endif
  }
}

void setupPads() {
#ifdef JOYSTICK_INPUT
  Joystick.begin();
#endif
}

#endif