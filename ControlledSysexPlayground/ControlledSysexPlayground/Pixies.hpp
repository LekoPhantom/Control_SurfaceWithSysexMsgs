#ifndef PIXIES_HPP
#define PIXIES_HPP

#include <Arduino.h>
#define Selectable FastLED_Selectable
#include <FastLED.h>
#include <Control_Surface.h>

#define LED_PIN 5  
#define NUM_LEDS 2 

CRGB leds[NUM_LEDS];

void initPixies() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(20);
}

// ✅ Explicitly use FastLED namespace
CRGB getFastLEDColor(uint8_t colorByte) {
    switch (colorByte) {
        case 0x01: return CRGB::Red;
        case 0x02: return CRGB::Green;
        case 0x03: return CRGB::Yellow;
        case 0x04: return CRGB::Blue;
        case 0x05: return CRGB::Purple;
        case 0x06: return CRGB::Teal;
        default: return CRGB::White;
    }
}

void updateLEDColor(uint8_t colorByte) {
    CRGB trackColor = getFastLEDColor(colorByte);
    leds[0] = trackColor;
    leds[1] = trackColor;
    FastLED.show();
}


uint8_t ledCounter = 0;
void  updatePixies() {
  static uint32_t lastUpdateTime = 0;
    if (millis() - lastUpdateTime > 5000) {  // ✅ Print every 5 seconds
        //trackManager.printTrackNames();
        //debugPrint(trackManager.getTrackColor(1));
        updateLEDColor(ledCounter);
        lastUpdateTime = millis();
        if (ledCounter > 5){
          ledCounter = 0;
        }
        ledCounter++;
    }
}
#endif