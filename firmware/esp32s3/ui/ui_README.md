
# UI – User Interface Module

This module manages the high-level user interface states and transitions on the ESP32-S3 device. It coordinates the display output, touch input (if available), and button responses to navigate between screens and provide feedback.

---

## Purpose

- Maintain a state machine for UI navigation
- Render key screens:
  - Boot screen
  - Message received
  - Menu with options
  - Mini-game (during boot delay)
- Handle button/touch events
- Interface with display module and system state

---

## UI States (Proposed)

| State ID     | Description                       |
|--------------|-----------------------------------|
| UI_BOOT      | Boot screen animation             |
| UI_MENU      | Simple menu: options, status      |
| UI_MESSAGE   | Message view (incoming/outgoing)  |
| UI_MINIGAME  | Wire-connection mini-game         |
| UI_IDLE      | Low-power or standby screen       |

---

## Functions

### `initUI()`
Initializes UI state and any related resources.

### `updateUI()`
Main loop function that updates UI based on state and input.

### `setUIState(uint8_t state)`
Transitions to a new UI state and resets necessary elements.

---

## Dependencies

- Requires `display.h` for rendering
- May use `powerman.h`, `picom.h`, or `gps.h` for context-sensitive UI

---

## Future Enhancements

- Touch screen input support
- Animation system for transitions
- Icon library for low-resolution UI

