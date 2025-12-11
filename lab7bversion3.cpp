/* 
 * Project Lab 7b version 3
 * Author: Paulina Noulas
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler(LOG_LEVEL_INFO);

typedef union {
  int16_t intVal;
  uint8_t txBuff[2]; //2 bytes = 16 bits
} MyData_t; 

MyData_t myData;

void setup() {
  Serial1.begin(9600, SERIAL_8E1);

  myData.intVal = 27099;
}

void loop() {
  Serial1.write(myData.txBuff[0]);
  Serial1.write(myData.txBuff[1]);

  delay(200);
}
