#include <Arduino.h>
#include "microswitch.h"
#include "config.h"

void setup() {
    Serial.begin(115200);
    initializeMicroSwitchPins();
    Serial.println("Microswitch Test Setup Complete.");
}

void loop() {
    testMicroSwitchPress(microswitch1Pin);
    testMicroSwitchPress(microswitch2Pin);
    testMicroSwitchPress(microswitch3Pin);
    delay(1000); // Add a delay to avoid overwhelming the serial output
}

void testMicroSwitchPress(int pin) {
    bool pressed = isMicroswitchPressed(pin);
    Serial.print("Microswitch on pin ");
    Serial.print(pin);
    if (pressed) {
        Serial.println(" is pressed.");
    } else {
        Serial.println(" is not pressed.");
    }
}