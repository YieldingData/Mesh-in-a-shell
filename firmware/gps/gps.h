#ifndef GPS_H
#define GPS_H

#include <Arduino.h>

// Structure to hold parsed GPS data
struct GPSData {
  double latitude;
  double longitude;
  bool fix;
  String timestamp;
};

// Initializes the GPS module
void initGPS(HardwareSerial &serial);

// Attempts to read a GPS fix and fill in GPSData
bool updateGPS(GPSData &data, unsigned long timeout_ms = 3000);

// Optional: power control for GPS module (if using a MOSFET switch)
void powerGPS(bool state);

#endif
