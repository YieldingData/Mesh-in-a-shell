
#include "picom.h"
#include "../lora/lora.h"

static Stream* piSerial = nullptr;
static String incomingBuffer = "";

void initPiCom(Stream &serial) {
    piSerial = &serial;
}

void processIncomingPiData() {
    if (!piSerial) return;

    while (piSerial->available()) {
        char c = piSerial->read();
        if (c == '\n') {
            StaticJsonDocument<256> doc;
            DeserializationError err = deserializeJson(doc, incomingBuffer);
            if (!err) {
                const char* type = doc["type"];
                if (strcmp(type, "send_message") == 0) {
                    const char* text = doc["msg"] | "";
                    const char* dest = doc["to"] | "FFFF";
                    sendMeshText(dest, text);
                }
                // Add more commands as needed
            }
            incomingBuffer = "";
        } else {
            incomingBuffer += c;
        }
    }
}

void sendToPi(JsonDocument &doc) {
    if (!piSerial) return;
    serializeJson(doc, *piSerial);
    *piSerial << '\n';
}

void signalPiShutdown() {
    // Optional: send shutdown signal or low-level GPIO toggle
    StaticJsonDocument<64> doc;
    doc["type"] = "shutdown";
    sendToPi(doc);
}
