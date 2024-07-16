#ifndef MICROSWITCH_H
#define MICROSWITCH_H

#include <Arduino.h>

void initializeMicroSwitchPins();
bool isMicroswitchPressed(int pin);

#endif // MICROSWITCH_H