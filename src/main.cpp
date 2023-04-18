#include <Arduino.h>
// Setup Pins for RGB output
#define RED 3
#define GREEN 5
#define BLUE 6

#define DELAY 10
#define DELAY_BETWEEN_LIGHTS 250
#define MAX_BRIGHT 64

/**
 * Fade to white or to black
 */
void fadeAll(bool fadeIn) {
    if (fadeIn) {
        for (int i = 0; i < MAX_BRIGHT; i++) {
            analogWrite(RED, i);
            analogWrite(BLUE, i);
            analogWrite(GREEN, i);
            delay(DELAY);
        }
    } else {
        for (int i = MAX_BRIGHT; i >= 0; i--) {
            analogWrite(RED, i);
            analogWrite(BLUE, i);
            analogWrite(GREEN, i);
            delay(DELAY);
        }
    }
}
/**
 * fades the color of the selected pin in or out
 */
void fadeColor(int colorPin, bool fadeIn) {
    if (fadeIn) {
        for (int i = 0; i < MAX_BRIGHT; i++) {
            analogWrite(colorPin, i);
            delay(DELAY);
        }
    } else {
        for (int i = MAX_BRIGHT; i >= 0; i--) {
            analogWrite(colorPin, i);
            delay(DELAY);
        }
    }
}

/**
 * Sets each pin to OUTPUT and turns them all off, then enables the default pin
 */
void setup() {
    // Setup the pins for output
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    // Turn off the light
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    // Setup RED to be lit to the correct brightness at startup
    fadeColor(RED, true);
}

void loop() {
    // red -> green
    fadeColor(RED, false);
    fadeColor(GREEN, true);
    delay(DELAY_BETWEEN_LIGHTS);

    // green -> blue
    fadeColor(GREEN, false);
    fadeColor(BLUE, true);
    delay(DELAY_BETWEEN_LIGHTS);

    // blue -> while
    fadeColor(BLUE, false);
    fadeAll(true);
    delay(DELAY_BETWEEN_LIGHTS);

    // white -> red
    fadeAll(false);
    fadeColor(RED, true);
    delay(DELAY_BETWEEN_LIGHTS);
}