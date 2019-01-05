// todo: don't use Arduino libraries, they are very slow.
// todo: use registers directly.
#include <Arduino.h>

#include "encoders.h"
#include "pins.h"

volatile ticks_t left_ticks = 0;
volatile ticks_t right_ticks = 0;

ticks_t get_left_ticks() {
  return left_ticks;
}
ticks_t get_right_ticks() {
  return right_ticks;
}

void left_interrupt() {
  if (digitalRead(encoder_pin_LB)) left_ticks++;
  else                             left_ticks--;
}

void right_interrupt() {
  if (digitalRead(encoder_pin_RB)) right_ticks++;
  else                             right_ticks--;
}

void encoder_setup() {
  attachInterrupt(digitalPinToInterrupt(encoder_pin_LA), left_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_pin_RA), right_interrupt, RISING);
}
