#include "lora.h"

// RadioLib SX1262 instance using default SPI
SX1262 lora = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);

// Buffer for received packets
static String rxBuffer;

void initLoRa() {
    // initialize SPI and radio
    SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_CS);

    int state = lora.begin();
    if(state == RADIOLIB_ERR_NONE) {
        Serial.println("[LoRa] init success");
    } else {
        Serial.print("[LoRa] init failed, code ");
        Serial.println(state);
    }
}

bool sendLoRaJson(JsonDocument &doc) {
    String payload;
    serializeJson(doc, payload);
    int state = lora.transmit(payload);
    return state == RADIOLIB_ERR_NONE;
}

bool sendMeshText(const char* to, const char* text,
                  float lat, float lon,
                  const char* timestamp) {
    StaticJsonDocument<256> packet;
    packet["to"] = to;
    packet["from"] = DEVICE_ID;
    packet["port"] = 1; // text message port used by Meshtastic

    packet["id"] = (uint32_t)millis();

    JsonObject payload = packet.createNestedObject("payload");
    payload["text"] = text;
    if (lat != 0.0f || lon != 0.0f) {
        payload["lat"] = lat;
        payload["lon"] = lon;
    }
    if (timestamp) {
        payload["timestamp"] = timestamp;
    }

    return sendLoRaJson(packet);
}

bool receiveLoRaMessage(JsonDocument &doc) {
    int state = lora.receive(rxBuffer);
    if(state == RADIOLIB_ERR_NONE) {
        DeserializationError err = deserializeJson(doc, rxBuffer);
        rxBuffer = "";
        return !err;
    }
    return false;
}
