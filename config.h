#ifndef BTTP_CONFIG
#define BTTP_CONFIG

#define NUM_STEPS 4
const uint8_t PINS[NUM_STEPS] = {A6, A7, A8, A9};
const uint8_t JOYSTICK_BUTTONS[NUM_STEPS] = {1, 2, 3, 4};
uint32_t thresholds[NUM_STEPS] = {300, 300, 300, 300};

#define BAUD_RATE 115200

#endif
