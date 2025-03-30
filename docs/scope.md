# Project Scope – Mesh in a Shell

## Overview

**Mesh in a Shell** is a low-power, off-grid communication device that uses LoRa mesh networking to send and receive messages. It is designed to operate independently or alongside mobile devices running the MeshCore app. The system combines lightweight always-on hardware with an optional AI-assisted interface powered by an embedded Linux computer, providing both instant responses and deeper functionality on demand.

---

## Goals

- Enable mesh-based communication without internet or cellular connectivity
- Provide fast, ultra-low-power interaction using physical buttons
- Offer advanced messaging features (LLM-based replies, message history, full keyboard input) via a boot-on-demand Linux system
- Integrate seamlessly with **MeshCore**, allowing communication with phones and other mesh devices
- Periodically broadcast GPS location for tracking and coordination
- Keep the device highly efficient, rugged, and expandable

---

## Hardware Components

### **XIAO ESP32-S3**
- Always-on controller for:
  - LoRa messaging
  - GPS (once per hour location broadcast)
  - Button input
  - Touchscreen mini-game
  - Power management (controls power to Orange Pi and peripherals)
- Handles simple “yes” / “no” replies directly

### **Orange Pi Zero 2W**
- Boots only on demand (triggered by Button 3)
- Provides:
  - Local LLM (e.g., TinyLlama) for generating context-aware replies
  - Full message composition via touchscreen
  - Message history review
  - Optional text-to-speech (TTS) and speech-to-text (STT)
  - Advanced GPS tools

### **Wio SX1262**
- LoRa radio module
- Handles communication using the **MeshCore protocol**
- Enables interoperability with MeshCore devices and apps

### **NEO-6M GPS**
- Activated once per hour by ESP32
- Location included in outgoing messages or heartbeat pings

### **2.9" Waveshare Touch E-Paper**
- Used for message display, menu navigation, and mini-game
- Controlled by both ESP32 and Orange Pi as needed

### **3 Physical Buttons**
- Button 1: Send predicted “Yes” response
- Button 2: Send predicted “No” response
- Button 3: Boot Orange Pi and enter full interaction mode

---

## Software Scope

### **ESP32-S3**
- Handle all LoRa message receiving/sending
- Listen for and respond to MeshCore-formatted messages
- Predict and send canned replies based on message content
- Power on the Orange Pi when advanced interaction is needed
- Refresh e-paper display with mini-game during boot
- Track time and trigger GPS ping once per hour
- Communicate with Orange Pi via UART or I2C

### **Orange Pi Zero 2W**
- Boot Linux and load LLM model
- Display interactive UI for full message input and review
- Interface with user via touchscreen
- Communicate with ESP32 for message sync
- Shut down after timeout or user action

---

## Communication Protocol

- Mesh in a Shell will support **MeshCore-compatible packets**
- Messages can be sent between:
  - Other Mesh in a Shell devices
  - Phones running the MeshCore app
- All messages may include:
  - Device ID
  - Message content
  - Optional GPS location and timestamp

---

## Out of Scope (for MVP)

- Real-time voice or audio messaging
- Internet or Wi-Fi-based messaging
- Automatic over-the-air updates
- Secure encryption and authentication (planned for future)

---

## Stretch Goals

- TTS and STT integration on Orange Pi
- BLE pairing or configuration via phone
- Configurable response sets via QR code or file
- Optional solar-powered version for extended field deployment
