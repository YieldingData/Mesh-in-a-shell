
# Orange Pi Zero 2W Firmware

This directory contains the firmware and scripts for the Orange Pi Zero 2W, a secondary processor used in the Mesh in a Shell device. The Orange Pi provides advanced features only when needed and is powered on by the ESP32-S3 to reduce idle power consumption.

---

## Responsibilities

The Orange Pi is responsible for running high-power, high-level operations that cannot be handled by the ESP32-S3. These include:

- Running a lightweight local language model (LLM) for contextual message prediction and interaction
- Providing a full touchscreen interface for composing messages and reviewing message history
- Interfacing with the GPS module for advanced mapping and live tracking
- Supporting optional text-to-speech (TTS) and speech-to-text (STT)
- Managing message logs, configurations, and temporary files on SD card or internal storage
- Communicating with the ESP32-S3 via UART or I2C for data exchange and power signaling

---

## Startup Behavior

1. The ESP32-S3 powers on the Orange Pi only when needed (e.g., Button 3 pressed).
2. The Orange Pi loads the LLM service and UI software.
3. It reads the system configuration file and sets parameters.
4. It displays the user interface and allows user interaction.
5. After a period of inactivity or user command, it cleanly shuts down and signals the ESP32-S3.

---

## Configuration File

User-configurable settings for the Orange Pi are stored in a JSON file.

### Location:
/home/pi/mesh-in-a-shell/config/mesh_config.json

### Sample:
```json
{
  "device_id": "MESH1234",
  "include_gps": true,
  "gps_ping_interval_minutes": 60,
  "max_message_length": 160,
  "auto_shutdown_minutes": 2,
  "enable_llm": true
}
```

### Description of Fields:

| Field                   | Description                                                  |
|-------------------------|--------------------------------------------------------------|
| `device_id`             | Unique ID for this node in the mesh network                  |
| `include_gps`           | Whether to include GPS location in outgoing messages         |
| `gps_ping_interval_minutes` | Frequency of automatic GPS updates                        |
| `max_message_length`    | Maximum number of characters a user can input                |
| `auto_shutdown_minutes` | Minutes of inactivity before auto shutdown                   |
| `enable_llm`            | Enables or disables the local LLM entirely                   |

These values are loaded at boot and used throughout operation.

---

## Tools / Frameworks

The Orange Pi software stack is built around Python and minimal OS services.

- **Python 3** – Main scripting language
- **llama.cpp**, **GPT4All**, or similar – Runs the local LLM model
- **Tkinter** / **PyQT** / **fbcp** – Touchscreen-based UI frameworks
- **pynmea2**, **gpsd** – GPS input parsing
- **Custom serial/UART handlers** – Communication with ESP32-S3

---

## Future Expansion: ESP32 Auto-Flasher

A future feature will allow the Orange Pi to automatically flash the ESP32-S3 firmware during startup.

### Proposed Flow:
1. Orange Pi checks for `/firmware/esp32s3/flash/firmware.bin` on boot.
2. It uses `esptool.py` to flash the ESP32-S3 over UART.
3. It logs the update result and optionally reboots the ESP32.

This will allow field updates and hands-free provisioning using only an SD card.

---

## Status

- [x] Configurable settings support
- [x] Startup/shutdown logic defined
- [ ] Full UI framework (in development)
- [ ] LLM integration (in development)
- [ ] Auto-flasher (planned)
