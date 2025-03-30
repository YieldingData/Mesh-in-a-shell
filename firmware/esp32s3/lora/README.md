# LoRa Module – Wio SX1262

This module handles LoRa mesh communication for Mesh in a Shell using the Wio SX1262 module. It is responsible for sending and receiving messages, formatting them into structured packets, and enabling compatibility with MeshCore-based mesh networks.

---

## Module Overview

- **Device:** Wio SX1262 (Semtech SX1262)
- **Interface:** SPI
- **Library:** [RadioLib](https://github.com/jgromes/RadioLib)
- **Primary Controller:** ESP32-S3
- **Purpose:**
  - Send structured messages with GPS + timestamp data
  - Receive incoming messages and forward to the display or LLM
  - Maintain compatibility with MeshCore protocol where possible

---

## Default Wiring (ESP32-S3)

| SX1262 Pin | ESP32-S3 | Notes                |
|------------|----------|----------------------|
| NSS (CS)   | D10      | SPI chip select      |
| SCK        | D11      | SPI clock            |
| MISO       | D12      | SPI MISO             |
| MOSI       | D13      | SPI MOSI             |
| RESET      | D8       | Hardware reset       |
| BUSY       | D2       | Radio busy pin       |
| DIO1       | D9       | Interrupt pin        |
| GND        | GND      | Ground               |
| VCC        | 3.3V     | Not 5V tolerant!     |

> **Note:** Adjust pin assignments to match your wiring. SX1262 operates at 3.3V logic and power only.

---

## Message Format (JSON)

Example message payload sent over LoRa:

```json
{
  "id": "MESH1234",
  "msg": "Yes, copy that.",
  "lat": 37.7749,
  "lon": -122.4194,
  "timestamp": "2025-03-30T14:23:00Z"
}
