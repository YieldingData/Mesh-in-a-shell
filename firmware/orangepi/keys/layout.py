"""Keyboard layout definitions for the Keys module.

This module describes several simple keyboard layouts used by the
on-screen keyboard. Layouts are defined as lists of rows, where each
row is a list of key labels. All keys in a single row occupy equal
width when rendered.
"""

from dataclasses import dataclass
from typing import List, Tuple

# Default screen dimensions for the Waveshare 2.9" touch e-paper.
SCREEN_WIDTH = 296
SCREEN_HEIGHT = 128

@dataclass
class Key:
    label: str
    value: str
    bounds: Tuple[int, int, int, int]  # (x0, y0, x1, y1)

    def contains(self, x: int, y: int) -> bool:
        x0, y0, x1, y1 = self.bounds
        return x0 <= x < x1 and y0 <= y < y1


# Raw layouts expressed as rows of labels. Special keys use
# lowercase names so they can be distinguished from printable
# characters.
RAW_LAYOUTS = {
    "abc": [
        list("qwertyuiop"),
        list("asdfghjkl"),
        ["shift", "z", "x", "c", "v", "b", "n", "m", "backspace"],
        ["123", "space", "enter"],
    ],
    "ABC": [
        list("QWERTYUIOP"),
        list("ASDFGHJKL"),
        ["shift", "Z", "X", "C", "V", "B", "N", "M", "backspace"],
        ["123", "space", "enter"],
    ],
    "123": [
        list("1234567890"),
        ["-", "/", ":", ";", "(", ")", "@", "&", "?"],
        ["abc", ".", ",", "'", "\"", "!", "#", "backspace"],
        ["ABC", "space", "enter"],
    ],
}


def build_layout(name: str, width: int = SCREEN_WIDTH, height: int = SCREEN_HEIGHT) -> List[Key]:
    """Return a list of :class:`Key` objects for the given layout name."""
    rows = RAW_LAYOUTS.get(name)
    if not rows:
        raise ValueError(f"Unknown layout: {name}")

    row_height = height // len(rows)
    keys: List[Key] = []

    for r, row in enumerate(rows):
        col_width = width // len(row)
        for c, label in enumerate(row):
            x0 = c * col_width
            y0 = r * row_height
            x1 = x0 + col_width
            y1 = y0 + row_height
            keys.append(Key(label=label, value=label, bounds=(x0, y0, x1, y1)))
    return keys
