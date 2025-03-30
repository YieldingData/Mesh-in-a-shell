
#include "picom.h"

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
                    // Handle message from Pi
                    String msg = doc["msg"];
                    bool include_gps = doc["include_gps"] | false;
                    // TODO: forward msg to LoRa module, attach GPS if needed
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
