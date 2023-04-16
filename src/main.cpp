#include <Arduino.h>
// Setup Pins for RGB output
#define RED 3
#define GREEN 5
#define BLUE 6

void setup() {
    // Setup the pins for output
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    // Turn off the light
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

}

void setColor(int red, int green, int blue) {

}

void loop() {
// write your code here
}