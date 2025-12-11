/* 
 * Project Lab 7b version 1
 * Author: Paulina Noulas
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

void setup() {
  Serial1.begin(9600, SERIAL_8E1);
}

void loop() {
  Serial1.print("VU");

  delay(200);
}
