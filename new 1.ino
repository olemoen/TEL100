#include <DHT.h>
#include "thingProperties.h"
// DHT sensor library - Version: Latest 
#include <EduIntro.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  dht.begin();
  
  // Defined in thingProperties.h
  initProperties();
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  /*
  The following function allows you to obtain more information
  related to the state of network and IoT Cloud connection and errors
  the higher number the more granular information you’ll get.
  The default is 0 (only errors).
  Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
void loop() {
  ArduinoCloud.update();
  // Your code here
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  Serial.print("humidity: ");
  Serial.println(humidity);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("Celsius");
  delay(5000);
}