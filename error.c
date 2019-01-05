#include <core_pins.h>
#include "pins.h"

void enter_error_state() {
  digitalWrite(error_pin, HIGH);
}
void exit_error_state() {
  digitalWrite(error_pin, LOW);
}

void error_setup() {
  pinMode(error_pin, HIGH);
}
