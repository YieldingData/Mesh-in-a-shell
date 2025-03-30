
#ifndef POWERMAN_H
#define POWERMAN_H

#include <Arduino.h>

void initPowerMan();

void powerOrangePi(bool on);
void powerGPS(bool on);
void powerScreen(bool on); // optional
float readBatteryVoltage();

#endif
