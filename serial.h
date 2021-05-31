#ifndef BTTP_SERIAL
#define BTTP_SERIAL

#include <Arduino.h>

#define BUFFER_SIZE 64
char buffer[BUFFER_SIZE];

void setupSerial() {
  Serial.begin(BAUD_RATE);
}

void printValues() {
  for (int i = 0; i < NUM_STEPS; ++i) {
    Serial.print(" ");
    Serial.print(padValues[i]);
  }
  Serial.print("\n");
}

void printThresholds() {
  for (int i = 0; i < NUM_STEPS; ++i) {
    Serial.print(" ");
    Serial.print(THRESHOLDS[i]);
  }
  Serial.print("\n");
}

void updateThresholds(size_t bytes_read) {
  if (bytes_read < 2 || bytes_read > 5) {
    return;
  }

  size_t step_index = buffer[0] - '0';
  if (step_index < 0 || step_index >= NUM_STEPS) {
    return;
  }

  THRESHOLDS[step_index] = atoi(buffer + 1);
  printThresholds();
}

void tickSerial() {
  while (Serial.available() > 0) {
    size_t bytes_read = Serial.readBytesUntil('\n', buffer, BUFFER_SIZE - 1);
    buffer[bytes_read] = '\0';

    if (bytes_read == 0) {
      return;
    }

    switch (buffer[0]) {
    case 'v':
    case 'V':
      printValues();
      break;
    case 't':
    case 'T':
      printThresholds();
      break;
    default:
      updateThresholds(bytes_read);
      break;
    }
  }
}

#endif
