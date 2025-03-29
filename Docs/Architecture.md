# Mesh in a Shell – Architecture Overview

## Overview

This system is divided into two intelligent layers:

### 1. ESP32-S3 (XIAO)
- Always-on low-power controller
- Handles:
  - LoRa communication (Wio SX1262)
  - Hourly GPS ping (HiLetgo NEO-6M)
  - Button input
  - Touchscreen mini-game
  - Power control for Orange Pi
  - Predicted yes/no reply selection
- Draws <1mA in idle, suitable for extended battery use

### 2. Orange Pi Zero 2W
- Booted only when user needs:
  - Full message history
  - Touch input for composing messages
  - Onboard LLM for predicted responses
  - Advanced GPS tools
  - Optional STT/TTS support

---

## Button Inputs

| Button | Function |
|--------|----------|
| 1      | Send predicted "Yes" response |
| 2      | Send predicted "No" response |
| 3      | Boot Orange Pi and enter full feature mode |

---

## Communication Flow

- All message I/O is managed through the LoRa module
- ESP handles incoming messages and responds immediately with canned replies if possible
- ESP powers on Orange Pi if complex handling is needed
- Messages include metadata like GPS location and timestamps

---

## Power Management Strategy

- ESP32-S3 handles GPS, LoRa, and inputs at all times
- GPS is powered on once per hour for location updates
- Orange Pi is kept powered off and booted on demand
- All peripherals can be selectively powered down via MOSFETs

---

## Mini-Game: "Connect the Wires"

During Orange Pi boot, ESP runs a mini-game to engage the user and mask boot time. The player must connect virtual wires to terminals to "activate the AI core."
