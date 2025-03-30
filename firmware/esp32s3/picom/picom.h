
#ifndef PICOM_H
#define PICOM_H

#include <Arduino.h>
#include <ArduinoJson.h>

void initPiCom(Stream &serial);
void processIncomingPiData();
void sendToPi(JsonDocument &doc);
void signalPiShutdown();

#endif
