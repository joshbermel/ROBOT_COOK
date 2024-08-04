#include "microswitch.h"
#include "config.h"

// Setting all microswitch pins to be digital inputs which are active on Low (pullup)
void initializeMicroSwitchPins() {
    // pinMode(microswitch1Pin, INPUT_PULLUP);
}

// Checking to see if microswitch pin is active (low)
bool isMicroswitchPressed(int pin) {
    return digitalRead(pin) == LOW;
}