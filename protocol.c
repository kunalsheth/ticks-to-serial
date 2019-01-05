#include <inttypes.h>

uint8_t encode(int8_t l, int8_t r) {
  if (l < 0) l = -l & 0b0111;
  else       l =  l & 0b0111 | 0b1000;

  if (r < 0) r = -r & 0b0111;
  else       r =  r & 0b0111 | 0b1000;

  return (l << 4) | (r << 0);
}
