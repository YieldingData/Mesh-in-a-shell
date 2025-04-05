
#ifndef UI_H
#define UI_H

#include <Arduino.h>

enum UIState {
  UI_BOOT,
  UI_MENU,
  UI_MESSAGE,
  UI_MINIGAME,
  UI_IDLE
};

void initUI();
void updateUI();
void setUIState(uint8_t state);

#endif
