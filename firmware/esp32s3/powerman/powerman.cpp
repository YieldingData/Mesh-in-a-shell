
#include "powerman.h"

// Example pin definitions (adjust as needed)
const int PIN_PI_POWER = 21;
const int PIN_GPS_POWER = 22;
const int PIN_SCREEN_POWER = 23;
const int PIN_BATTERY_VOLTAGE = A0;

void initPowerMan() {
    pinMode(PIN_PI_POWER, OUTPUT);
    pinMode(PIN_GPS_POWER, OUTPUT);
    pinMode(PIN_SCREEN_POWER, OUTPUT);
    digitalWrite(PIN_PI_POWER, LOW);
    digitalWrite(PIN_GPS_POWER, LOW);
    digitalWrite(PIN_SCREEN_POWER, LOW);
}

void powerOrangePi(bool on) {
    digitalWrite(PIN_PI_POWER, on ? HIGH : LOW);
}

void powerGPS(bool on) {
    digitalWrite(PIN_GPS_POWER, on ? HIGH : LOW);
}

void powerScreen(bool on) {
    digitalWrite(PIN_SCREEN_POWER, on ? HIGH : LOW);
}

float readBatteryVoltage() {
    int raw = analogRead(PIN_BATTERY_VOLTAGE);
    float voltage = raw * (3.3 / 4095.0); // ADC scaling
    return voltage * 2.0; // Assuming voltage divider
}
