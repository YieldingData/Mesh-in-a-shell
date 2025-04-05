
#include "ui.h"
#include "../display/display.h"

static UIState currentState = UI_BOOT;

void initUI() {
    currentState = UI_BOOT;
    showBootAnimation();
}

void updateUI() {
    switch (currentState) {
        case UI_BOOT:
            // Boot already handled in init
            break;
        case UI_MENU: {
            String opts[] = {"Send Message", "View History", "Shutdown"};
            showMenu(opts, 3);
            break;
        }
        case UI_MESSAGE:
            showMessage("Message here...");
            break;
        case UI_MINIGAME:
            showMessage("Game loading...");
            // TODO: trigger mini-game logic
            break;
        case UI_IDLE:
            showMessage("Standby");
            break;
    }
}

void setUIState(uint8_t state) {
    currentState = static_cast<UIState>(state);
}
