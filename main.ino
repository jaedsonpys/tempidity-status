#include "Arduino.h"

const int redLed = 19;
const int greenLed = 15;
const int blueLed = 4;

const int buzzerPin = 23;
const int buzzerFreq = 1500;

void lowAlert();
void mediumAlert();
void highAlert();

void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);

    pinMode(buzzerPin, OUTPUT);
}

void loop() {

}

void lowAlert() {
    for(int i = 0; i < 1; i++) {
        analogWrite(greenLed, 255);        
        delay(500);
        analogWrite(greenLed, 0);
        delay(500);
    }
}

void mediumAlert() {
    for(int i = 0; i < 2; i++) {
        analogWrite(blueLed, 255);
        tone(buzzerPin, buzzerFreq);
        
        delay(500);

        noTone(buzzerPin);
        analogWrite(blueLed, 0);
        delay(500);
    }
}

void highAlert() {
    for(int i = 0; i < 3; i++) {
        analogWrite(redLed, 255);
        tone(buzzerPin, buzzerFreq);
        
        delay(200);

        noTone(buzzerPin);
        analogWrite(blueLed, 0);
        delay(200);
    }
}