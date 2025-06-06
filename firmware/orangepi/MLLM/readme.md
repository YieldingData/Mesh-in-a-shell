<p align="center">
  <img src="../../../assets/MLLM.png" alt="MLLM Logo" width="400">
</p>
# MLLM – Mesh Local Language Model

**MLLM** (Mesh Local Language Model) is the embedded AI module within the *Mesh in a Shell* system. It provides local, offline language processing for composing messages, parsing commands, and rephrasing input using a small quantized LLM running directly on the Orange Pi Zero 2 W.

---

## 🧠 Purpose

MLLM brings basic language assistance features to constrained hardware without relying on cloud APIs. It supports:

- ✍️ Text autocompletion for messages
- 🔄 Rephrasing and simplification of input
- 📜 Natural language command parsing
- 🧭 Local assistant functionality for user queries (planned)

---

## 📁 Directory Structure

```
mllm/
├── __init__.py           # Entry point and high-level interface
├── model_runner.py       # Loads and runs the LLM (TinyLlama)
├── completion.py         # Handles autocomplete prompts
├── rephrase.py           # Rewrites user input in different styles
├── command_parser.py     # Parses structured commands from user text
└── utils.py              # Shared tools for formatting and token control
```

---

## 🛠 Requirements

- `llama.cpp` compiled for ARM64
- GGUF model (default: TinyLlama 1.1B Q4_K_M)
- Python 3.8+
- Optional: `pyllamacpp` or subprocess wrapper to interact with compiled binary

---

## 📦 Default Model

| Model       | TinyLlama 1.1B Chat |
|-------------|---------------------|
| Format      | GGUF (Q4_K_M)       |
| Size        | ~140MB              |
| RAM Usage   | ~450MB              |
| Token Rate  | ~5–10 tokens/sec    |
| License     | Apache 2.0          |

---

## 🧩 Integration Points

MLLM is designed to interface with:

- `keys/` → Accepts typed input from the on-screen keyboard
- `messages/` → Suggests completions and cleans up outgoing text
- `config/` → Accepts natural language configuration updates (via parser)

---

## 🧪 Usage

Example call:

```python
from mllm import complete_text

response = complete_text("Let's meet at the")
print(response)
```

---

## 🔐 Privacy

All inference runs locally. No text is sent to the cloud. MLLM does not retain any messages or user history.

---

## 🧭 Roadmap

- [x] Integrate TinyLlama GGUF runner
- [ ] Add UI toggle for "LLM Assist" mode
- [ ] Introduce caching for recent completions
- [ ] Add whisper-to-LLM bridge for voice commands
- [ ] Expand assistant capabilities for offline help

---

## 📄 License

MIT License © Mesh in a Shell contributors
