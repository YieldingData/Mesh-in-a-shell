<p align="center">
  <img src="Mesh-in-a-shell/assets/powerman_logo.png" alt="Power Man Logo" width="400">
</p>
# PowerMan – Power Management Module

**PowerMan** is the power management module for the ESP32-S3 in the Mesh in a Shell system. It is responsible for controlling the power state of connected peripherals, especially the Orange Pi Zero 2W, and monitoring system readiness and shutdown.

---

## Purpose

- Power on/off the Orange Pi on command
- Control other modules (GPS, screen, LoRa) via MOSFETs or digital pins
- Monitor battery status (optional: ADC pin)
- Track system power state for diagnostics

---

## Pin Assignments (example)

| Feature         | Pin   | Description                   |
|----------------|-------|-------------------------------|
| Orange Pi Power | D21   | Controls Pi power MOSFET      |
| GPS Power       | D22   | Powers GPS module             |
| Screen Power    | D23   | Optional control for e-paper  |
| Battery Sense   | A0    | ADC input for battery voltage |

---

## Functions

### `initPowerMan()`
Initializes all power control pins and sets safe default states.

### `powerOrangePi(bool on)`
Turns the Orange Pi ON or OFF using a digital pin.

### `powerGPS(bool on)`
Enables or disables power to the GPS module.

### `readBatteryVoltage()`
Returns battery voltage in volts (optional feature).

---

## Planned Enhancements

- Soft shutdown via GPIO signal from Orange Pi
- Thermal monitoring
- Power sequencing delays
