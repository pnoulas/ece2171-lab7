/* 
 * Project Lab 7b version 2
 * Author: Paulina Noulas
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

int16_t x = 27099;

void setup() {
  Serial1.begin(9600, SERIAL_8E1);
}

void loop() {
  Serial1.println(x);

  delay(200);
}
