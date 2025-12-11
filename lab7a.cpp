/* 
 * Project Lab7a
 * Author: Paulina Noulas
 * Description: Push button input 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(MANUAL);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

String usbInMessage = ""; //message typed on the PC USB
String uartInMessage = ""; //message coming from the friend

// setup() runs once, when the device is first turned on
void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected, 10000); 

  Serial1.begin(9600, SERIAL_8E1);
}

void loop() {
  if (Serial.isConnected()) {
    while (Serial.available () > 0) {
      char inByte = Serial.read();
      if (inByte == '\r' || inByte == '\n') {
        if (usbInMessage.length() > 0) {
          Serial.println(usbInMessage);
          Serial1.println(usbInMessage);
          delay (200); 
          usbInMessage = "";
        }
      } else {
        usbInMessage += inByte; 
      }
    }
  }

  while (Serial1.available() > 0) {
    char inByte = Serial1.read();

    if (inByte == '\r' || inByte =='\n') {
      if (uartInMessage.length() > 0) {
        Serial.print("> ");
        Serial.println(uartInMessage);

        delay (200);
        uartInMessage = "";
      }
    } else {
      uartInMessage += inByte;
    }
  }

  delay(200);
}
  
