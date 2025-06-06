<p align="center">
  <img src="../../../assets/picom_logo.png" alt="PiCom Logo" width="400">
</p>

# PiCom – ESP32 ↔ Orange Pi Communication Module

This module, named **PiCom**, handles all communication between the ESP32-S3 and the Orange Pi Zero 2W within the Mesh in a Shell project. It enables data exchange, command signaling, and power coordination between the always-on microcontroller and the on-demand Linux system.

---

## Purpose

- Send structured messages to the Orange Pi (e.g., received LoRa data, GPS fix, button events)
- Receive commands or replies from the Orange Pi (e.g., user-composed messages, shutdown signal)
- Handle wake and ready signaling between ESP32-S3 and Orange Pi
- Maintain reliable and low-latency UART communication

---

## Communication Protocol

- **Physical Layer:** UART
- **Baud Rate:** 115200 (configurable)
- **Format:** JSON strings, newline-delimited

### Example Packet (ESP32 → Orange Pi):
```json
{
  "type": "message_received",
  "msg": "Incoming from MeshCore",
  "from": "MESH4321",
  "lat": 37.7749,
  "lon": -122.4194,
  "timestamp": "2025-03-30T16:45:00Z"
}
```

### Example Packet (Orange Pi → ESP32):
```json
{
  "type": "send_message",
  "msg": "Roger that.",
  "to": "FFFF",
  "include_gps": false
}
```

Packets of this type are converted to a MeshCore/Meshtastic packet and sent over
LoRa via `sendMeshText()`.

---

## Functions

### `initPiCom(Stream &serial)`
Initializes the serial communication and buffers.

### `processIncomingPiData()`
Reads and parses incoming messages from Orange Pi. Dispatches to appropriate handlers.

### `sendToPi(JsonDocument &doc)`
Serializes and transmits a JSON message to the Orange Pi.

### `signalPiShutdown()`
Sends a shutdown command or trigger signal to Orange Pi (optional).

---

## Dependencies

- `ArduinoJson` for encoding/decoding messages
- `HardwareSerial` or `SoftwareSerial` depending on UART wiring

---

## Planned Enhancements

- Add CRC or hash to packets for integrity checking
- Add retry logic on transmission errors
- Extend to support I2C as an alternative channel
- Allow binary mode for low-latency control signals
