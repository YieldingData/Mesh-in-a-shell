# GPS Module – HiLetgo GY-NEO6MV2 (NEO-6M)

This module handles GPS functionality for Mesh in a Shell. It runs on the ESP32-S3 and provides periodic location updates, parses GPS coordinates, and formats them for inclusion in outgoing LoRa messages or system logs.

---

## Module Overview

- **Device:** HiLetgo GY-NEO6MV2 (u-blox NEO-6M)
- **Interface:** UART (default baud: 9600)
- **Data Format:** NMEA sentences
- **Powered by:** ESP32 3.3V or 5V rail (can be power-switched)
- **Controlled by:** ESP32-S3 (always-on controller)

---

## Functional Goals

- Wake GPS once per hour (configurable)
- Wait for a valid fix
- Parse and store current latitude and longitude
- Format the coordinates for use in:
  - LoRa status pings
  - GPS-tagged user messages
- Power down GPS to save battery

---

## Default Wiring (ESP32-S3)

| GPS Pin | ESP32-S3 | Notes             |
|---------|----------|-------------------|
| VCC     | 3.3V/5V  | From regulator or pin |
| GND     | GND      | Shared ground      |
| TX      | D0 (RX)  | GPS → ESP32        |
| RX      | D1 (TX)  | ESP32 → GPS (optional, not required) |

---

## Libraries Used

- [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus) – Lightweight GPS parser
- Arduino `HardwareSerial` – For UART access

---

## Logic Overview

1. ESP32 powers GPS (optionally through MOSFET switch)
2. Reads incoming NMEA data from GPS over UART
3. Waits for valid GPS fix (status "A")
4. Parses coordinates
5. Sends location data to LoRa module or saves to memory
6. Powers off GPS module

---

## Sample Output

```json
{
  "lat": 37.7749,
  "lon": -122.4194,
  "fix": true,
  "timestamp": "2025-03-28T12:45:00Z"
}
