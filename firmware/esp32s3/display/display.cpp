
#include "display.h"
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>

#define MAX_OPTIONS 5

// Example display constructor (adjust to match your model)
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=*/ 5, /*DC=*/ 17, /*RST=*/ 16, /*BUSY=*/ 4));

void initDisplay() {
    display.init();
    display.setRotation(1);
    display.setFont(&FreeMonoBold9pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 30);
        display.print("Display Ready");
    } while (display.nextPage());
}

void showBootAnimation() {
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 30);
        display.print("Booting Orange Pi...");
    } while (display.nextPage());
}

void showMessage(const String &msg) {
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 30);
        display.print(msg);
    } while (display.nextPage());
}

void showMenu(String options[], int count) {
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        for (int i = 0; i < count && i < MAX_OPTIONS; i++) {
            display.setCursor(10, 30 + i * 20);
            display.print(options[i]);
        }
    } while (display.nextPage());
}
