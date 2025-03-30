# Orange Pi Zero 2W Firmware

This directory contains the software that runs on the Orange Pi Zero 2W, which is powered on only when advanced functionality is needed. It provides a high-level interface and access to a local language model.

---

## Responsibilities

- Load and run a lightweight LLM (e.g. TinyLlama, DistilGPT)
- Interface with the user via touchscreen (full message input, history review, AI suggestions)
- Communicate with the ESP32-S3 over UART or I2C
- Handle advanced GPS tools (live location tracking, mapping tools)
- (Optional) Provide text-to-speech (TTS) and speech-to-text (STT) features
- Manage local logs or message history using SD card or internal storage

---

## Startup Behavior

1. System is powered on via signal from ESP32-S3
2. Loads required services or Python scripts
3. Displays the full user interface and processes user input
4. Powers down after inactivity timeout or shutdown signal

---

## Tools / Frameworks

- **Python 3**
- Optional LLM engine: `llama.cpp`, `GPT4All`, or `ggml`-based runner
- Touch UI framework: `Tkinter`, `PyQT`, or custom framebuffer-based display
- GPS parsing: `gpsd`, `pynmea2`
- Messaging bridge: Custom UART protocol to ESP32

---

## Future Expansion: ESP32 Auto-Flasher

A future feature will allow the Orange Pi to **automatically flash the ESP32-S3 firmware** when an updated binary is placed on the SD card. This would enable rapid field updates or hands-free provisioning of new hardware.

### Proposed Flow:
1. On boot, Orange Pi looks for `/firmware/esp32s3/flash/firmware.bin`
2. Uses `esptool.py` to flash firmware over UART/USB
3. Logs result and optionally reboots ESP32-S3

This will be implemented during Orange Pi software development and is not part of the MVP.
