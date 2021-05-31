#ifndef BTTP_LED
#define BTTP_LED

#ifdef LEDS

#include <Arduino.h>
#include <FastLED.h>
#include "config.h"

CRGBArray<NUM_LEDS> leds;
uint64_t currentMillis = 0;

// Get the LED offset for a given pad index
uint8_t getLEDStartForPad(uint8_t padIndex) {
  for (int i = 0; i < NUM_STEPS; i++) {
    if (PAD_LED_ORDER[i] == padIndex) {
      return i * NUM_LEDS_PER_STEP;
    }
  }
}

// defaunt rainbow-y sorta effect
void gamerIdle(uint8_t padIndex, double rate) {
  uint32_t colorOffset = currentMillis * rate;
  uint8_t ledStartIndex = getLEDStartForPad(padIndex);

  for (int i = 0; i < NUM_LEDS_PER_STEP; i++) {
    leds[i + ledStartIndex] =
        CHSV(((i * 255) / NUM_LEDS_PER_STEP) + colorOffset, 255,
             255 * LED_IDLE_BRIGHTNESS);
  }
  FastLED.show();
}

// handle showing the non-pressed pad lights
void showIdle(uint8_t padIndex) { gamerIdle(padIndex, 0.05); }

// handle showing the pressed pad light
void showActive(uint8_t padIndex) {
  CRGB color = CRGB(LED_ACTIVE_COLOR * LED_ACTIVE_BRIGHTNESS);
  leds(getLEDStartForPad(padIndex), getLEDStartForPad(padIndex) + NUM_LEDS_PER_STEP - 1).fill_solid(color);
  FastLED.show();
}

void setupLights() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, LED_COLOR_ORDER>(leds, NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
}

void tickLights() {
  currentMillis = millis();
  for (uint8_t i = 0; i < NUM_STEPS; i++) {
    if (padPressed[i]) {
      showActive(i);
    } else {
      showIdle(i);
    }
  }
}

#else
// LEDs disabled
void setupLights() {}
void tickLights() {}
#endif

#endif
