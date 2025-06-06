"""Keyboard state handling."""
from dataclasses import dataclass, field


def clamp(value: int, minimum: int, maximum: int) -> int:
    return max(minimum, min(value, maximum))


@dataclass
class KeyboardState:
    """Represents current keyboard state and input buffer."""

    layout: str = "abc"
    buffer: str = ""
    cursor: int = 0

    entered: bool = False

    def insert(self, char: str) -> None:
        self.buffer = self.buffer[: self.cursor] + char + self.buffer[self.cursor :]
        self.cursor += len(char)

    def backspace(self) -> None:
        if self.cursor > 0:
            self.buffer = self.buffer[: self.cursor - 1] + self.buffer[self.cursor :]
            self.cursor -= 1

    def move_cursor(self, offset: int) -> None:
        self.cursor = clamp(self.cursor + offset, 0, len(self.buffer))

    def clear(self) -> None:
        self.buffer = ""
        self.cursor = 0
        self.entered = False
