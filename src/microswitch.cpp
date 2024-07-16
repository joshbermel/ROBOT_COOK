#include "microswitch.h"
#include "config.h"

void initializeMicroSwitchPins() {
    pinMode(microswitch1Pin, INPUT_PULLUP);
    pinMode(microswitch2Pin, INPUT_PULLUP);
    pinMode(microswitch3Pin, INPUT_PULLUP);
}

bool isMicroswitchPressed(int pin) {
    return digitalRead(pin) == LOW;
}