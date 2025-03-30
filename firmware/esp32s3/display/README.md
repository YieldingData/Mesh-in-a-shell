
# Display – E-Paper Touch Display Module

This module manages the 2.9" Waveshare Touch E-Paper Display used in the Mesh in a Shell project. It provides core functions for displaying messages, menu options, boot animations, and optional mini-games on the ESP32-S3 side.

---

## Purpose

- Display incoming and outgoing messages
- Show simple menus and UI feedback
- Render a boot-time mini-game to occupy the user during Orange Pi startup
- Provide touch feedback (if handled by ESP32-S3)

---

## Display Specs

- Model: Waveshare 2.9" Touch E-Paper HAT
- Resolution: 296×128 pixels
- Interface: SPI for e-paper, I2C for touch
- Libraries: GxEPD2, Adafruit_FT6206

---

## Functions

### `initDisplay()`
Initializes the e-paper display and clears the screen.

### `showBootAnimation()`
Shows a visual sequence (or mini-game) while the Orange Pi is booting.

### `showMessage(const String &msg)`
Displays a message using large, readable text.

### `showMenu(String options[], int count)`
Renders a simple vertical list of options (basic UI mode).

---

## Touch Support (optional)

If the touch controller is connected to the ESP32-S3, touch input functions may be added in the future to detect taps or swipe gestures.

---

## Planned Enhancements

- Interactive mini-game (e.g., connect wires or match icons)
- Touch support for menu selection
- Screen refresh optimization
