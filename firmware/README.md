
# Firmware – Mesh in a Shell

This directory contains all the firmware for the Mesh in a Shell device. It is split into two main subsystems:

---

## Structure

```
/firmware/
├── esp32s3/       # Always-on controller (XIAO ESP32-S3)
├── orangepi/      # On-demand AI interface (Orange Pi Zero 2W)
```

---

## Overview

### 🧠 ESP32-S3

The ESP32-S3 is the low-power microcontroller that is **always on**. It handles:

- LoRa mesh communication
- Power management
- GPS polling
- Message prediction ("Yes", "No")
- Button handling
- E-paper screen display
- Communicating with the Orange Pi via UART (PiCom)

Each subsystem is modularized in folders:

| Folder      | Function                             |
|-------------|--------------------------------------|
| `gps/`      | Reads and parses NEO-6M GPS data     |
| `lora/`     | Sends and receives LoRa messages     |
| `picom/`    | Handles UART communication with Pi   |
| `powerman/` | Controls system power to modules     |
| `display/`  | Manages the e-paper screen UI        |

---

### 🖥️ Orange Pi Zero 2W

The Orange Pi is powered on only when advanced features are needed. It runs:

- A local LLM for generating replies
- A touch interface for full message input
- Message history and advanced tools
- (Optional) text-to-speech and speech-to-text

See `/orangepi/README.md` for full details.

---

## Build System

- ESP32-S3: Arduino / PlatformIO (recommended)
- Orange Pi: Python 3 (for all runtime components)

---

## Notes

- Configuration files are stored in the `config/` folder on the Orange Pi SD card
- Auto-flashing ESP32 from Orange Pi is planned (see `/orangepi/README.md`)
