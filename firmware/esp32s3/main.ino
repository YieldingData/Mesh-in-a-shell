#include "gps/gps.h"

GPSData currentGPS;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600); // GPS is connected to Serial1
  initGPS(Serial1);
}

void loop() {
  powerGPS(true);
  delay(500); // Wait for module to boot

  if (updateGPS(currentGPS)) {
    Serial.println("GPS Fix:");
    Serial.println("Lat: " + String(currentGPS.latitude));
    Serial.println("Lon: " + String(currentGPS.longitude));
    Serial.println("Timestamp: " + currentGPS.timestamp);
  } else {
    Serial.println("No GPS fix.");
  }

  powerGPS(false);
  delay(3600000); // Wait 1 hour before next fix
}
