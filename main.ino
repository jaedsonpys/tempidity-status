#include "Arduino.h"

const int redLed = 19;
const int greenLed = 3;
const int blueLed = 4;

const int buzzerPin = 23;

void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);

    pinMode(buzzerPin, OUTPUT);
}

void loop() {

}