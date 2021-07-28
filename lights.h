#ifndef BTTP_LIGHTS
#define BTTP_LIGHTS

#include "FastLED.h"
#include "config.h"

void setupLights() {
  FastLED.addLeds<LED_TYPE,LED_DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void solidColor(int index, CRGB color) {
 leds(index, index + NUM_LEDS_PER_STEP - 1).fill_solid(color);
}

void gamer(int index, int interval) {
  int colorOffset = millis() / interval;
  for (int i = 0; i < NUM_LEDS_PER_STEP; i++) {
    leds[i + index] = CHSV(((i * 255) / NUM_LEDS_PER_STEP) + colorOffset, 255, 255);
  }
}

void carnival(int index, CRGB color, int interval) {
  bool odd = true;
  if ((millis() / interval) % 2 == 0) {
    odd = !odd;
  }
  for (int i = 0; i < NUM_LEDS_PER_STEP; i++) {
    if ((i % 2 == 0) == odd){
      leds[i + index] = color;
    } else {
      leds[i + index] = CRGB::Black;
    }
  }
}

void swirl(int index, CRGB color, int interval) {
  int offset = (millis() / interval) % NUM_LEDS_PER_STEP;
  for (int i = 0; i < NUM_LEDS_PER_STEP; i++) {
    if (i == offset) {
      leds[index + i] = color;
    } else {
      leds[index + i] = CRGB::Black;
    }
  }
}

void rainbowSwirl(int index, int colorInterval, int movementInterval) {
  int colorOffset = millis() / colorInterval;
  int ledOffset = (millis() / movementInterval) % NUM_LEDS_PER_STEP;
  for (int i = 0; i < NUM_LEDS_PER_STEP; i++) {
    if (i == ledOffset) {
      leds[index + i] = CHSV(((i * 255) / NUM_LEDS_PER_STEP) + colorOffset, 255, 255);
    } else {
      leds[index + i] = CRGB::Black;
    }
  }
}

void tickLights() {
  for (int step = 0; step < NUM_STEPS; step++) {
    if (stepPressed[step]) {
      solidColor(led_indices[step], CRGB::White);
    } else {
      gamer(led_indices[step], 10);
    }
  }
  FastLED.show();
}

#endif
