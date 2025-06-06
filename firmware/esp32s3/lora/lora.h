#ifndef LORA_H
#define LORA_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <RadioLib.h>

// Default pin mapping for the Wio SX1262 module
#define LORA_CS   10
#define LORA_DIO1 9
#define LORA_RST  8
#define LORA_BUSY 2
#define LORA_SCK  11
#define LORA_MISO 12

#define LORA_MOSI 13

// Device/node identifier used in mesh packets
#ifndef DEVICE_ID
#define DEVICE_ID "MESH1234"
#endif

// Initialize the LoRa radio
void initLoRa();

// Send a raw JSON document over LoRa.
// Returns true on success.
bool sendLoRaJson(JsonDocument &doc);

// Build and send a Meshtastic/MeshCore-compatible text packet
bool sendMeshText(const char* to, const char* text,
                  float lat = 0.0f, float lon = 0.0f,
                  const char* timestamp = nullptr);

// Check for an incoming LoRa message. If one is available it will be
// placed in `doc` and the function returns true.
bool receiveLoRaMessage(JsonDocument &doc);

#endif // LORA_H
