<p align="center">
  <img src="../../../ssets/Keys.png" alt="Keys Logo" width="400">
</p>
# Keys – Touchscreen Keyboard Module

The `Keys` module provides a lightweight touchscreen keyboard interface for the *Mesh in a Shell* project, designed for use with a 2.9" Waveshare touch e-paper display. It allows users to input text in a compact and power-efficient UI environment.

---

## 📦 Module Overview

The keyboard supports:
- Full QWERTY character input (lowercase/uppercase)
- Layout switching (abc / ABC / 123)
- Touch-to-key mapping
- Shift, backspace, enter, and space functionality
- Cursor tracking and buffer state

---

## 📁 File Structure

```
keys/
├── __init__.py           # Initializes the module
├── layout.py             # Defines keyboard layouts (abc, ABC, 123, etc.)
├── renderer.py           # Draws keyboard UI on e-ink display
├── input_handler.py      # Interprets touch input into keystrokes
└── state.py              # Maintains input buffer and keyboard state
```

---

## 🧠 Core Concepts

### `layout.py`
Defines static key arrangements for different layouts.

### `renderer.py`
Handles rendering the keyboard layout to the e-ink screen. Optimized for partial refresh when possible.

### `input_handler.py`
Maps raw touch coordinates to key regions and handles multi-state logic (e.g., shift, layout switching).

### `state.py`
Tracks:
- Current layout (`abc`, `ABC`, `123`)
- Buffer string and cursor position
- Modifier states like shift and capslock

---

## 🔌 Integration

To integrate the keyboard into the main interface:

```python
from keys import KeyboardState, render_keyboard, process_touch

keyboard = KeyboardState()
render_keyboard(keyboard)
...
def on_touch(x, y):
    process_touch(x, y, keyboard)
```

After pressing "enter", the buffer can be read using:
```python
final_text = keyboard.buffer
```

---

## 📋 Future Features

- Emoji/shortcut layout
- Long-press alternate characters
- Predictive text suggestions
- Visual feedback animations for touch

---

## 🛠 Requirements

- Python 3
- PIL / Pillow (for rendering)
- Touch input driver (compatible with Waveshare 2.9" touch e-paper)

---

## 🧪 Status

**Development stage:** Alpha  
**Tested on:** Orange Pi Zero 2 W + Waveshare 2.9" Touch e-Paper HAT

---

## 📄 License

MIT License © Mesh in a Shell contributors

