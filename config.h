#ifndef BTTP_CONFIG
#define BTTP_CONFIG

#include <Arduino.h>
#include <Keyboard.h>

// Number of pads
#define NUM_STEPS 4

#define JOYSTICK_INPUT // comment out to use Keyboard instead

// Pins attached to each pad...
const uint8_t PINS[NUM_STEPS] = {A0, A1, A2, A3};

#ifdef JOYSTICK_INPUT
// Joystick buttons are simply numbered
const uint8_t JOYSTICK_BUTTONS[NUM_STEPS] = {0, 1, 2, 3};
#else
// ...and what those pins correspond to
const uint8_t KEYBOARD_BUTTONS[NUM_STEPS] = {KEY_LEFT_ARROW, KEY_DOWN_ARROW,
                                             KEY_UP_ARROW, KEY_RIGHT_ARROW};
#endif

// These can be modified at runtime but these are the initial values:
uint32_t THRESHOLDS[NUM_STEPS] = {500, 500, 400, 500};

// LED setup
#define LEDS // comment out to disable

#ifdef LEDS
#include <FastLED.h>

// the order of the above-defined pins that the LEDs correspond to
const int PAD_LED_ORDER[NUM_STEPS] = {3, 1, 0, 2};
#define LED_IDLE_BRIGHTNESS 0.5
#define LED_ACTIVE_BRIGHTNESS 0.5
#define LED_ACTIVE_COLOR 0x0099FF

#define LED_TYPE WS2811
#define LED_COLOR_ORDER BRG
#define NUM_LEDS_PER_STEP 12
#define NUM_LEDS NUM_LEDS_PER_STEP * NUM_STEPS
#define DATA_PIN 5
#endif

// Serial baud rate
#define BAUD_RATE 9600

#endif