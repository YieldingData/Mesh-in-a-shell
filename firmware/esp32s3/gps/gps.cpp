#include "gps.h"
#include <TinyGPS++.h>

TinyGPSPlus gps;
HardwareSerial* gpsSerial = nullptr;

const int GPS_POWER_PIN = 10;  // Change to your pin if using power control

void initGPS(HardwareSerial &serial) {
  gpsSerial = &serial;
  gpsSerial->begin(9600);  // Default NEO-6M baud rate
  pinMode(GPS_POWER_PIN, OUTPUT);
  digitalWrite(GPS_POWER_PIN, HIGH);  // Turn on GPS if power controlled
}

bool updateGPS(GPSData &data, unsigned long timeout_ms) {
  unsigned long start = millis();
  while (millis() - start < timeout_ms) {
    while (gpsSerial->available()) {
      gps.encode(gpsSerial->read());
    }
  }

  if (gps.location.isValid()) {
    data.latitude = gps.location.lat();
    data.longitude = gps.location.lng();
    data.fix = gps.location.isValid();
    data.timestamp = String(gps.date.year()) + "-" +
                     String(gps.date.month()) + "-" +
                     String(gps.date.day()) + "T" +
                     String(gps.time.hour()) + ":" +
                     String(gps.time.minute()) + ":" +
                     String(gps.time.second()) + "Z";
    return true;
  }

  data.fix = false;
  return false;
}

void powerGPS(bool state) {
  digitalWrite(GPS_POWER_PIN, state ? HIGH : LOW);
}
