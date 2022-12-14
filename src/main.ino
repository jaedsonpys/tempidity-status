#include "Arduino.h"
#include <DHT.h>

const int redLed = 19;
const int greenLed = 15;
const int blueLed = 4;
const int dhtPin = 18;

const int buzzerPin = 23;
const int buzzerFreq = 1500;

// temperature control (in C°)
const int temperatureMin = 20;
const int temperatureMax = 35;

// humidity control (in %)
const int humidityMin = 40;
const int humidityMax = 80;

void lowAlert();
void mediumAlert();
void highAlert();

DHT dht(dhtPin, DHT11);

void setup() {
    Serial.begin(9600);

    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(blueLed, OUTPUT);

    pinMode(buzzerPin, OUTPUT);

    dht.begin();
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);

    bool temperatureCondition = temperature > temperatureMin && temperature < temperature;
    bool humidityCondition = humidity > humidityMin && humidity < humidityMax;

    if(temperatureCondition || humidityCondition) {
        lowAlert();
        delay(5000);
    } else {
        highAlert();
        delay(2500);
    }
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
    for(int i = 0; i < 4; i++) {
        analogWrite(redLed, 255);
        tone(buzzerPin, buzzerFreq);
        
        delay(100);

        noTone(buzzerPin);
        analogWrite(redLed, 0);
        delay(100);
    }
}