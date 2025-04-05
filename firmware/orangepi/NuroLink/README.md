<p align="center">
  <img src="../../../../assets/nurolink_logo.png" alt="PowerMan Logo" width="400">
</p>
# NuroLink is a Web Flasher Interface (Planned Feature)

This is a proposed feature to make flashing firmware onto Mesh in a Shell devices simple, user-friendly, and accessible without needing development tools or coding knowledge.

---

## Purpose

To allow users to select their hardware configuration from a browser and flash the appropriate firmware with a single click—no Arduino IDE or PlatformIO setup required.

---

## Features (Planned)

- Web-based UI using [esp-web-tools](https://github.com/esphome/esp-web-tools)
- Dropdown menus to select:
  - Device type (ESP32 + Waveshare, T5, etc.)
  - Optional features (GPS, LLM, Orange Pi interface)
- Automatic download and flashing of precompiled `.bin` firmware
- Writes a `config.json` file to internal flash, SPIFFS, or SD card

---

## Configuration Source

The dropdowns and flash options will be populated from a JSON manifest like this:

```json
{
  "devices": [
    {
      "name": "ESP32 + Waveshare 2.9"",
      "id": "waveshare29",
      "bin_url": "https://yourdomain.com/firmware/waveshare29.bin"
    },
    {
      "name": "ESP32 + LilyGo T5 4.7"",
      "id": "t5_47",
      "bin_url": "https://yourdomain.com/firmware/t5_47.bin"
    }
  ]
}
```

This allows new hardware types to be added by editing a single JSON file—no code changes needed.

---

## Hosting Options

- GitHub Pages (recommended)
- Any static file host (Netlify, Vercel, etc.)

---

## Status

This feature is not part of the MVP and will be implemented after initial hardware and firmware development is complete.

- [ ] HTML UI template
- [ ] Flash manifest format
- [ ] JSON-based config file writer
- [ ] Firmware variants with standard naming
