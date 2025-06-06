"""Touch input processing for the on-screen keyboard."""

from typing import Optional

from . import layout
from .state import KeyboardState


def process_touch(x: int, y: int, state: KeyboardState, width: int = layout.SCREEN_WIDTH, height: int = layout.SCREEN_HEIGHT) -> Optional[str]:
    """Process a touch at the given coordinates.

    Returns the character inserted into the buffer or ``None`` if no key
    was pressed.
    """
    keys = layout.build_layout(state.layout, width, height)
    for key in keys:
        if key.contains(x, y):
            return _handle_key_press(key.value, state)
    return None


def _handle_key_press(value: str, state: KeyboardState) -> Optional[str]:
    if value == "shift":
        # Toggle between abc and ABC layouts
        state.layout = "ABC" if state.layout == "abc" else "abc"
        return None
    elif value in ("abc", "ABC", "123"):
        state.layout = value
        return None
    elif value == "space":
        state.insert(" ")
        return " "
    elif value == "enter":
        state.insert("\n")
        state.entered = True
        return "\n"
    elif value == "backspace":
        state.backspace()
        return None
    else:
        state.insert(value)
        return value
