
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void initDisplay();
void showBootAnimation();
void showMessage(const String &msg);
void showMenu(String options[], int count);

#endif
