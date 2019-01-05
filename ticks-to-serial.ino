extern "C" {
#include "protocol.h"
#include "encoders.h"
#include "error.h"
}

void setup() { // called by arduino main
  error_setup();
  Serial.begin(115200);
  encoder_setup();
}

ticks_t last_left_ticks = 0;
ticks_t last_right_ticks = 0;

void loop() { // called by arduino main
  ticks_t left_copy = get_left_ticks();
  ticks_t right_copy = get_right_ticks();

  int8_t dleft = left_copy - last_left_ticks;
  int8_t dright = right_copy - last_right_ticks;

  last_left_ticks = left_copy;
  last_right_ticks = right_copy;

  if (dleft == 0 && dright == 0) {
    Serial.send_now();
  } else {
    Serial.write(encode(dleft, dright));
  }
}
