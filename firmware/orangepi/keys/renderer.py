"""Simple keyboard renderer using Pillow."""

from PIL import Image, ImageDraw, ImageFont
from . import layout
from .state import KeyboardState

# Try to load a default font. Pillow will fall back to a simple bitmap
# font if truetype fonts are not available.
try:
    DEFAULT_FONT = ImageFont.truetype("DejaVuSans.ttf", 14)
except Exception:  # pragma: no cover - font availability may vary
    DEFAULT_FONT = ImageFont.load_default()


def render_keyboard(state: KeyboardState, width: int = layout.SCREEN_WIDTH, height: int = layout.SCREEN_HEIGHT) -> Image.Image:
    """Render the keyboard to a Pillow :class:`Image`."""
    img = Image.new("1", (width, height), 1)  # 1-bit image, white background
    draw = ImageDraw.Draw(img)

    keys = layout.build_layout(state.layout, width, height)
    for key in keys:
        x0, y0, x1, y1 = key.bounds
        draw.rectangle(key.bounds, outline=0, fill=1)
        text = key.label
        tw, th = draw.textsize(text, font=DEFAULT_FONT)
        tx = x0 + (x1 - x0 - tw) // 2
        ty = y0 + (y1 - y0 - th) // 2
        draw.text((tx, ty), text, font=DEFAULT_FONT, fill=0)

    return img
