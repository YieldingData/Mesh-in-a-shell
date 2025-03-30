
# Hardware List – Mesh in a Shell

This document provides a complete list of hardware components used in the Mesh in a Shell project, including reference links to datasheets, product pages, or GitHub repositories where applicable.

---

## Core Components

### 1. **XIAO ESP32-S3**
- Role: Always-on microcontroller for power management, LoRa communication, GPS, and button input.
- Specs: Dual-core, USB-C, 3.3V logic, supports deep sleep.
- Docs: [https://wiki.seeedstudio.com/XIAO_ESP32S3_Getting_Started/](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/)

---

### 2. **Orange Pi Zero 2W**
- Role: Powers full user interface, local LLM, and advanced tools.
- Specs: Quad-core Cortex-A53, 512MB–1GB RAM, runs Linux.
- GitHub: https://github.com/orangepi-xunlong
- Docs: [https://www.orangepi.org/html/hardWare/computerAndMicrocontrollers/details/Orange-Pi-Zero-2W.html](http://www.orangepi.org/orangepiwiki/index.php/Orange_Pi_Zero_2W)

---

### 3. **Wio-E5 SX1262 LoRa Module**
- Role: Handles mesh networking using LoRa communication.
- Specs: Semtech SX1262, long-range low-power radio.
- GitHub: https://github.com/Seeed-Studio/Wio-E5-LoRa-Module

---

### 4. **Waveshare 2.9" Touch E-Paper Display HAT**
- Role: User interface display, used by both ESP32 and Orange Pi.
- Specs: 296x128 resolution, capacitive touch, SPI + I2C.
- GitHub: https://github.com/waveshare/2.9inch-e-Paper

---

### 5. **HiLetgo GY-NEO6MV2 (NEO-6M GPS Module)**
- Role: Provides periodic GPS location data for pings and message tagging.
- Specs: 9600 baud UART, NMEA sentences, 3.3V/5V input.
- Product Page: https://www.hiletgo.com/products/gy-neo6mv2-gps-module

---

### 6. **Physical Buttons (x3)**
- Role: Quick reply and feature control interface.
  - Button 1 – Send predicted "Yes"
  - Button 2 – Send predicted "No"
  - Button 3 – Trigger full feature mode (wake Orange Pi)

---

### 7. **Power Supply & Regulation**
- Role: Manages system voltage (3.3V & 5V), powers modules.
- Includes:
  - Battery input
  - Voltage regulators or buck converters
  - Optional power switches/MOSFETs

---

## Optional / Future Add-ons

- MicroSD card for data logging or firmware updates
- USB sound card or I2S audio module for TTS/STT
- External LoRa antenna
- Small speaker/mic (future voice features)
- Solar panel input for off-grid charging

---

## Notes

- All modules communicate using low-level interfaces (UART, SPI, I2C).
- ESP32-S3 runs minimal firmware and selectively powers modules.
- Orange Pi handles everything that requires Linux or higher compute resources.
